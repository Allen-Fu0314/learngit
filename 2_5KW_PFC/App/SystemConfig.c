#include "SystemConfig.h"
#include "stdio.h"

volatile unsigned char cnt_2ms;
volatile unsigned char cnt_10ms;
volatile unsigned char cnt_100ms;
volatile unsigned short cnt_1ms;
volatile unsigned char cnt_20s;
volatile unsigned char fg_1ms;
volatile unsigned char fg_2ms;
volatile unsigned char fg_10ms;
volatile unsigned char fg_100ms;
volatile unsigned char fg_EndofConversion = 0;
extern PWMCALVAL pwmcalval;
extern FAULTSTATE FaultState;
extern SYSTEMFLAG SysFlag;
extern RMSCALVAL rmscalval;
extern PLL_VAL pll_val;


void Sys_Config()
{
	FLASH_WALLOW();
  FLASH_SetTiming(200000000);
  /* Disable flash write access after flash operation had done */
  FLASH_WDIS();

  CLOCK_InitWithRCO(CLOCK_HCLK_200MHZ);
	CLOCK_SetModuleDiv(TIMER1_MODULE, 10);

#if    DEBUG

#else
    
		WDT_Init(WDT1, 100);

	NVIC_EnableIRQ(WDT1_IRQn);
	WDT_EnableInt(WDT1);
	
#endif

	//TIMER_Init(TIMER0,AD_CurrentCount);   //1us for one isr 
	TIMER1_Init(100);//16666ns = 16.66us for one isr
	
	

  Delay_Init();
	
	  /*
   * Init the UART
   *
   * 1.Set the GPIO34/35 as UART FUNC
   *
   * 2.Enable the UART CLK
   *
   * 3.Set the rest para
   */
  GPIO_SetPinChannel(GPIO_34,GPIO34_UART_TXD);
  GPIO_SetPinChannel(GPIO_35,GPIO35_UART_RXD);
  CLOCK_EnableModule(UART_MODULE);
  UART_Init(UART,38400);
	GPIO_SetPinAsGPIO(GPIO_2);   //PFC OC FAULT  LOW is protected
	GPIO_SetPinDir(GPIO_2 , GPIO_INPUT);
	GPIO_SetPinAsGPIO(GPIO_8);   //PFC OV FAULT  LOW is protected
	GPIO_SetPinDir(GPIO_8 , GPIO_INPUT);
	GPIO_SetPinAsGPIO(GPIO_30);   //110V FLAG
	GPIO_SetPinDir(GPIO_30 , GPIO_OUTPUT);
    GPIO_SetPinAsGPIO(GPIO_19);   //110V FLAG
	GPIO_SetPinDir(GPIO_19 , GPIO_OUTPUT);

	printf("***********SYS Reboot************");
}

void TIMER1_IRQHandler(void)
{
       MeasureVoltage();
		//pll_chk_phase_lock();
	
        rmscalval.fg_rmscount++;
        if(rmscalval.fg_rmscount>=100)
		{
			rmscalval.fg_rms = 1;
            rmscalval.RMSVin = rmscalval.RMSBuff/100;
            rmscalval.RMSBuff = 0;
            rmscalval.fg_rmscount = 0;
		}else
		{
			rmscalval.RMSBuff+= rmscalval.VinAcs*rmscalval.VinAcs;
		}

    
if(SysFlag.fg_closeGvLoop)
		{
			pwmcalval.Vref = (pwmcalval.Vref>=pwmcalval.Vout_cmd)?pwmcalval.Vout_cmd:(pwmcalval.Vref+0.0005f);
		
		}
		pwmcalval.Vdiff = pwmcalval.Vref -pwmcalval.Vout;
		pwmcalval.Vloop = pwmcalval.Vloop_last +(pwmcalval.B0_V *pwmcalval.Vdiff)+(pwmcalval.B1_V *pwmcalval.Vdiff_last);
		pwmcalval.Vloop = (pwmcalval.Vloop > 3.1f) ? 3.1f :pwmcalval.Vloop;
		pwmcalval.Vloop = (pwmcalval.Vloop < -0.4f) ? -0.4f :pwmcalval.Vloop;

	
		pwmcalval.Vfilter=pwmcalval.Vfilter_last*1.9337f-0.9374007f*pwmcalval.Vfilter_last2+0.9411014f*pwmcalval.Vloop-1.8748013f*pwmcalval.Vloop_last+0.9374007f*pwmcalval.Vloop_last2;
	//pwmcalval.Vfilter=pwmcalval.Vfilter_last*1.6379308f-0.7077866f*pwmcalval.Vfilter_last2+0.7776423f*pwmcalval.Vloop-1.4155731f*pwmcalval.Vloop_last+0.7077866f*pwmcalval.Vloop_last2;
		pwmcalval.Vfilter = (pwmcalval.Vfilter > 3.1f) ? 3.1f :pwmcalval.Vfilter;
		pwmcalval.Vfilter = (pwmcalval.Vfilter < -0.4f) ? -0.4f :pwmcalval.Vfilter;	
	  pwmcalval.Vfilter_last2=pwmcalval.Vfilter_last;
		pwmcalval.Vfilter_last=pwmcalval.Vfilter;
		pwmcalval.Vdiff_last = pwmcalval.Vdiff;
		pwmcalval.Vloop_last2=pwmcalval.Vloop_last;
		pwmcalval.Vloop_last = pwmcalval.Vloop;
		
		

        
        if(++cnt_1ms >=10)
        {
            cnt_1ms =0;
            fg_1ms =1;
            if(++cnt_10ms>=10)
            {
                cnt_10ms = 0;
                fg_10ms =1;
            }
        }
     //   printf("SYS OK");
	TIMER_ClearInt(TIMER1);
        
}

void WDT1_IRQHandler(void)
{
	 fg_SysRestart =1;
	PWM_OFF;
	 WDT_ClearInt(WDT1);
	WDT_DisableInt(WDT1);
}


void PWM_Config()
{
	/********************PWM_PFC1 Config***********************/
	PWM_SetClockDiv(PWM0, PWM_CLKDIV0_1,  PWM_CLKDIV1_1);   //200m/2^0*1 = 200mhz
	PWM_SetClockDiv(PWM1, PWM_CLKDIV0_1,  PWM_CLKDIV1_1); 
	PWM_Init(PWM1,60000,1666);
  //  PWM_SingleChannelInit(PWM0 ,PWM_CHB ,60000 );
	PWM_SetTZ0FromGPIO(GPIO_8,GPIO_LEVEL_LOW);  //OVP
	PWM_SetTZ1FromGPIO(GPIO_2,GPIO_LEVEL_LOW);	//OCP
	PWM_SetOneShotTripEvent(PWM1,TRIP_EVENT_TZ0,TRIP_OUTPUT_ASYNC_OR_LATCH);
	PWM_SetOneShotTripEvent(PWM1,TRIP_EVENT_TZ1,TRIP_OUTPUT_ASYNC_OR_LATCH);
    
		//	PWM_SetOneShotTripEvent(PWM1,TRIP_EVENT_TZ0,TRIP_OUTPUT_ASYNC_OR_LATCH);
		
	PWM_SetCHBOutputWhenTrip(PWM1, TZU_TRIP_AS_LOW |
TZD_TRIP_AS_LOW |
DCEVT0U_TRIP_DO_NOTHING |
DCEVT0D_TRIP_DO_NOTHING |
DCEVT1U_TRIP_DO_NOTHING |
DCEVT1D_TRIP_DO_NOTHING);
		PWM_SetCHAOutputWhenTrip(PWM1, TZU_TRIP_AS_LOW |
TZD_TRIP_AS_LOW |
DCEVT0U_TRIP_DO_NOTHING |
DCEVT0D_TRIP_DO_NOTHING |
DCEVT1U_TRIP_DO_NOTHING |
DCEVT1D_TRIP_DO_NOTHING);

	PWM_SetTimeEventTiming(PWM1,EQU_PERIOD);
	PWM_SetTimeEventPeriod(PWM1,ON_1ST_EVENT);
	PWM_EnableTimeEventInt(PWM1);
			
	PWM_SetSOCATiming(PWM1,EQU_PERIOD); 
	PWM_SetSOCAPeriod(PWM1, ON_1ST_EVENT);
	PWM_EnableSOCA(PWM1);
	
	NVIC_SetPriorityGrouping(0x03); 
	NVIC_SetPriority(PWM1_IRQn, NVIC_EncodePriority(0x03,1, 2));
	NVIC_SetPriority(WDT1_IRQn, NVIC_EncodePriority(0x03, 3, 2));

	NVIC_SetPriority(TIMER1_IRQn, NVIC_EncodePriority(0x03, 4, 2));
	
	PWM_RunCounter(PWM1);	
	//PWM_RunCounter(PWM0);	
	
	//GPIO_SetPinChannel(GPIO_19,GPIO19_PWM0B);
	GPIO_SetPinChannel(GPIO_20,GPIO20_PWM1A);
	GPIO_SetPinChannel(GPIO_21,GPIO21_PWM1B);
	PWM_ForceCHALow(PWM1);
	PWM_ForceCHBLow(PWM1);
  //  PWM_ForceCHBLow(PWM0);
	

}


void TIMER1_Init(uint32_t u32TimerPeriodus)
{
  uint32_t u32TimerClk;
  
  /* Enable and Get Timer module clock */
 
    CLOCK_EnableModule(TIMER1_MODULE);
    
    u32TimerClk = CLOCK_GetModuleClock(TIMER1_MODULE);

  
  /* Set reload timer while timer reaches 0 */
  TIMER1->TMRRELOAD.all = TMRRELOAD_ALL_VAL_(CLOCK_UsToCounter(u32TimerPeriodus,u32TimerClk));
  
  /* Enable Timer interrupt */
  TIMER1->TMRIE.all |= TMRIE_ALL_INT_ENABLE;
  
  /* Enable Timer and select internal clock */
  TIMER1->TMRCTL.all = TMRCTL_ALL_EN_ENABLE | TMRCTL_ALL_EXTINMODE_DISABLE;
}

static void PWM_Init(PWM_REGS* PWMx, uint32_t u32PWMFreqHz, uint32_t DeadTime)
{
  uint32_t u32PWMPeriod;
  
  /* Enable PWM clock */
  CLOCK_EnableModule(PWM_MODULE);
  
  /*  PWM initial step */
  /*  Step 1: Set PWM frequency and dead time */
  u32PWMPeriod   = ((CLOCK_GetModuleClock(PWM_MODULE))/u32PWMFreqHz)/2;
  
  
  /*  Step 2: Enable EPWM clock and clock prescale*/
  PWMx->TBCTL.all = TBCTL_ALL_TBDIVBIN_1 | TBCTL_ALL_TBDIVLIN_1;


  /*  Step 3: PWM clock and counter synchronization configure  */
  /*  Step 3.1: Set PWM freq, counter type(count up-down as center alignment ) */
  PWMx->TBPRD.all   = u32PWMPeriod;                       /* PWM frequency setting */
  PWMx->TBCTL.all  |= TBCTL_ALL_CNTMODE_COUNT_UP_DOWN;    /* center alignment and PWM counter start to run */

  /*  Step 3.2: PWM module sync setting */
  PWMx->TBCTL.all  |=  TBCTL_ALL_SYNCOSEL_TBCNT_EQU_ZERO  /* Generate sync signal when TBCNT = Zero */
                     | TBCTL_ALL_PHSEN_ENABLE
                     | TBCTL_ALL_PHSDIR_COUNT_UP_AFTER_SYNC;
  
  PWMx->TBPHS.all = 1;

  /*  Step 4: Set PWM output waveform, central alignment and CMPA with duty are propotional  */
  PWMx->AQCTLA.all |=   AQCTLA_ALL_ZRO_DO_NOTHING 
                      | AQCTLA_ALL_PRD_DO_NOTHING
                      | AQCTLA_ALL_CAU_SET_HIGH
                      | AQCTLA_ALL_CAD_SET_LOW;
                      
  PWMx->AQCTLB.all |=   AQCTLB_ALL_ZRO_DO_NOTHING 
                      | AQCTLB_ALL_PRD_DO_NOTHING
                      | AQCTLB_ALL_CBU_SET_HIGH
                      | AQCTLB_ALL_CBD_SET_LOW;


  /*  Step 5: Set duty reload timing, Shadow mode and reload on period point */
  PWMx->CMPCTL.all |=   CMPCTL_ALL_CMPALOCK_UNLOCK 
                      | CMPCTL_ALL_CMPBLOCK_UNLOCK
                      | CMPCTL_ALL_CMPALOAD_LOAD_ON_ZERO
                      | CMPCTL_ALL_CMPBLOAD_LOAD_ON_ZERO;


  /* Step 6: Waveform generating with Dead-time */
  PWMx->DBCTL.all  = 0;
  PWMx->DBCTL.all |=   DBCTL_ALL_FEDSRC_FROM_A 
                     | DBCTL_ALL_REDSRC_FROM_B 
                     | DBCTL_ALL_OUTASRC_RISING_EDGE 
                     | DBCTL_ALL_OUTBSRC_FALLING_EDGE 
                     | DBCTL_ALL_REDPOL_ACTIVE_HIGH 
                     | DBCTL_ALL_FEDPOL_ACTIVE_HIGH 
                     | DBCTL_ALL_HALFCYCLE_DISABLE 
                     | DBCTL_ALL_DUALEDGE_ENABLE
                     | DBCTL_ALL_REDEN_DISABLE 
                     | DBCTL_ALL_FEDEN_ENABLE;
                     
  PWMx->DBFED.all = DeadTime;       /* Dead time delay */
  PWMx->DBRED.all = DeadTime;

  /*  Config PWM stop mode upon lockup/halted signal triggered by debug or other system events */
  PWMx->TBCTL.all |= TBCTL_ALL_DBGRUN_STOP_AFTER_CYCLE;   // Finish current cycle and stop upon lockup/halted signal
}
