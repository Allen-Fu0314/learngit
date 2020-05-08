
#include "ChargeFunction.h"
#include <math.h>
#include "arm_math.h"
#include "stdio.h"

enum PLLSTATUS pllstatus;
pwmSwState pwm_SwState;
PLL_VAL pll_val;
SOGI_VAL sogi_val;
CTRL_P1Z1 pll_cqr;
BDC_PWM bdc_pwm;	
RMSCALVAL rmscalval;
PLL_CONF pll_conf;
PWMCALVAL pwmcalval;
FAULTSTATE FaultState;


extern PROTECTVAL protectval;
extern ADCVALUE ADCvalue;
extern SYSTEMSTATE SysState;
extern SYSTEMFLAG SysFlag;
extern SYSTEM_DEBOUNCE Debounce;
FAULTVAL faultval;
uint8_t fg_PWMset = 0;
uint16_t I_ref[600];
uint16_t count;




void	pll_chk_phase_lock(void)
{
	if(pll_val.fg_locked	==	0)
	{
		if(sogi_val.q[0]	<	0.4f)
		{
			pll_conf.debounce_cnt++;
			if(pll_conf.debounce_cnt	>	pll_conf.debounce_time)
			{
				pll_conf.debounce_cnt	=	0;
				if(pll_val.wo	>	pll_conf.freq_max	||
					pll_val.wo <	pll_conf.freq_min)
				{
					
					return;
				}else
				{
					pll_val.fg_locked	=	1;
				}
			}
		}
	}
	
}



void	set_sogi_coff(float k, float freq,float dt)
{
	float	_x,_y,_tmp;
	float	x,y;

	x	=	(float)(2*0.8f*2*3.1415926f*dt);
	y	=	(float)(2*2*3.1415926f*3.141592f*dt*dt);

	_x	=	(float)(x*freq);
	_y	=	(float)(y*freq*freq);
	_tmp=	(float)(4+_x+_y);

	sogi_val.b0	=	(float)((_x/_tmp));
	sogi_val.a1	=	(float)(((2*_y-8)/_tmp));
	sogi_val.a2	=	(float)(((4-_x+_y)/_tmp));
	sogi_val.qb0=	(float)((0.8f*_y/_tmp));
}

void set_pwm(float freq, float scale)
{

	bdc_pwm.freq	=	freq;	//	60kHz
	bdc_pwm.prd	=	(uint16_t)(200000000/bdc_pwm.freq/2);
	bdc_pwm.prd_half	=	bdc_pwm.prd>>1;
	bdc_pwm.prd_quarter	=	bdc_pwm.prd_half>>1;
	bdc_pwm.scale	=	scale;
	bdc_pwm.min_duty	=	MIN_DUTY_PERCENT*((float)bdc_pwm.prd_half);
	bdc_pwm.max_duty	=	bdc_pwm.prd_half	-	bdc_pwm.min_duty;

	bdc_pwm.t_ctrl	=	(1/bdc_pwm.freq)*((float)bdc_pwm.scale);
	
}

void set_p1z1_coff(float g0, float b1, float max, float min,float dt)
{

	pll_cqr.b0	=	g0*1.1f;
	pll_cqr.b1	=	g0*b1*1.1f;
	pll_cqr.max	=	max;
	pll_cqr.min	=	min;
	pll_cqr.scale=	dt/bdc_pwm.t_ctrl-1;
	pll_cqr.avg_mul	=	1/(float)(pll_cqr.scale+1);
}

void	set_pll_conf(float	nor_freq)
{
	memset((uint16_t *)&pll_conf,0,sizeof(PLL_CONF));
	memset((uint16_t *)&pll_val,0,sizeof(PLL_VAL));



	pll_conf.debounce_time	=	100;
	pll_conf.freq_hyst_delaytime	=	100;
	pll_conf.freq_max	=	nor_freq*1.05f*PI_F_2;
	pll_conf.freq_min	=	nor_freq*0.95f*PI_F_2;
	pll_conf.freq_nor	=	nor_freq*PI_F_2;
	pll_conf.freq_var	=	0.5f*PI_F_2;
	pll_conf.freq_hyst_high	=	pll_conf.freq_nor	+	pll_conf.freq_var;
	pll_conf.freq_hyst_low	=	pll_conf.freq_nor	-	pll_conf.freq_var;
	
	pll_val.wo	=	pll_conf.freq_nor*PI_F_2;
}




void PWMcal(void)
{
    
//GPIO_TogglePin(GPIO_19);
		pwmcalval.Iref = (pwmcalval.Vfilter/rmscalval.RMSVin*pwmcalval.Vin);

        pwmcalval.Iadiff = (pwmcalval.Iref - pwmcalval.Ia);
        pwmcalval.Ibdiff = (pwmcalval.Iref - pwmcalval.Ib);

	
	pwmcalval.Dutya_NoVin = pwmcalval.Dutya_NoVinlast+(pwmcalval.B0_I *pwmcalval.Iadiff)+(pwmcalval.B1_I *pwmcalval.Iadiff_last)+(pwmcalval.B2_I *pwmcalval.Iadiff_last2);
	pwmcalval.Dutyb_NoVin = pwmcalval.Dutyb_NoVinlast+(pwmcalval.B0_I *pwmcalval.Ibdiff)+(pwmcalval.B1_I *pwmcalval.Ibdiff_last)+(pwmcalval.B2_I *pwmcalval.Ibdiff_last2);
  pwmcalval.Dutya_NoVin = (pwmcalval.Dutya_NoVin > 1) ? 1 : pwmcalval.Dutya_NoVin;
	pwmcalval.Dutya_NoVin = (pwmcalval.Dutya_NoVin < -1) ? -1 : pwmcalval.Dutya_NoVin;
  pwmcalval.Dutyb_NoVin = (pwmcalval.Dutyb_NoVin > 1) ? 1 : pwmcalval.Dutyb_NoVin;
	pwmcalval.Dutyb_NoVin = (pwmcalval.Dutyb_NoVin < -1) ? -1 : pwmcalval.Dutyb_NoVin;
  pwmcalval.Duty_a = pwmcalval.Dutya_NoVin;//-(FEEDFORWARD_VOLTAGE*pwmcalval.Vin);
  pwmcalval.Duty_b = pwmcalval.Dutyb_NoVin;//-(FEEDFORWARD_VOLTAGE*pwmcalval.Vin);
    
   
	pwmcalval.Duty_a = (pwmcalval.Duty_a > 0.95f) ? 0.95f :pwmcalval.Duty_a;
	pwmcalval.Duty_a = (pwmcalval.Duty_a < 0.005f) ? 0 : pwmcalval.Duty_a;
    
    
	pwmcalval.Duty_b = (pwmcalval.Duty_b > 0.95f) ? 0.95f :pwmcalval.Duty_b;
	pwmcalval.Duty_b = (pwmcalval.Duty_b < 0.005f) ? 0 : pwmcalval.Duty_b;

	

		pwmcalval.Iadiff_last2 = pwmcalval.Iadiff_last;
		pwmcalval.Iadiff_last = pwmcalval.Iadiff;
    pwmcalval.Dutya_NoVinlast2 = pwmcalval.Dutya_NoVinlast;
    pwmcalval.Dutya_NoVinlast = pwmcalval.Dutya_NoVin;
    pwmcalval.Ibdiff_last2 = pwmcalval.Ibdiff_last;
		pwmcalval.Ibdiff_last = pwmcalval.Ibdiff;
    pwmcalval.Dutyb_NoVinlast2 = pwmcalval.Dutyb_NoVinlast;
    pwmcalval.Dutyb_NoVinlast = pwmcalval.Dutyb_NoVin;
    
 
        SysFlag.fg_closeGvLoop = 1;
        SysFlag.fg_closeGiLoop = 1;

        PWM_ON;
        PFC2_Duty(1666*(1-pwmcalval.Duty_a));
        PFC2B_Duty(1666*(1-pwmcalval.Duty_b));
    
   

}




void ChargeProtect(void)
{
	static uint8_t delay_Ifault;
	static uint8_t delay_Vfault;

/**********************SoftwareOVP*********************/
//if(protectval.VOUT >= OVP_FASTVALUE)
//		{
//			
//            FaultResetVal();
//                        printf("The OCP  == %d \n " , FaultState.oneFault.OverCurrent);    
//        printf("The faultVref is %3f\n" , faultval.Fault_Vref);
//        printf("The faultVout is %3f\n" , faultval.Fault_Vout);            
//		
//		}	
    
         if(fg_OverVoltage == 0)
	{
		if(protectval.VOUT >= OVP_FASTVALUE)
		{
			fg_OverVoltage = 1;           
		FaultResetVal();
            pwmcalval.Vref =1.5f;
		}
	}else
	{
		 if(protectval.VOUT <= OVP_RECOVERVALUE)
		{
			
					fg_OverVoltage = 0;
			
		}
	}

	
	  if(fg_OverVoltage450V == 0)
	{
		if(protectval.VOUT >= 450)
		{
			if(++delay_Vfault>=DEBOUNCE_OCP)
			{
				fg_OverVoltage450V = 1;
				PWM_ForceCHAandCHBLow(PWM1);
				SysState = sys_fault;
                        printf("The OVP  == %d \n " , FaultState.oneFault.OverVoltage);

                        printf("The HardwareOV  == %d \n " , FaultState.oneFault.HardwareOV);
			}
		
		}else
		{
			delay_Vfault = 0;
		}
	}else
	{
		 if(protectval.VOUT <= OVP_RECOVERVALUE)
		{
			
					fg_OverVoltage450V = 0;
			
		}
	}
	
/**********************SoftwareOCP*********************/	
	if(fg_OverCurrent == 0)
	{
//		if((protectval.IA>=OCP_FASTVALUE)||(protectval.IA<=-OCP_FASTVALUE))
//		{
//			fg_OverCurrent = 1;
//		}
		
		if((protectval.IA>=OCP_VALUE)||(protectval.IB>=OCP_VALUE))
		{
			if(++delay_Ifault>=DEBOUNCE_OCP)
			{
					fg_OverCurrent = 1;
				PWM_ForceCHAandCHBLow(PWM1);
				SysState = sys_fault;
			}
		}else
		{
			delay_Ifault = 0;
		}
	}
	
/**********************HardwareOVP*********************/	
	if(!fg_HardwareOV)
	{
		if(HardwareOVP_Testing ==0)
		{
			
				fg_HardwareOV = 1;
				PWM_ForceCHAandCHBLow(PWM1);
				SysState = sys_fault;
					
		}
		
	}
	
	/**********************HardwareOCP*********************/
		if(!fg_HardwareOC)
	{
		if(HardwareOCP_Testing ==0)
		{
			
				fg_HardwareOC = 1;
				PWM_ForceCHAandCHBLow(PWM1);
				SysState = sys_fault;
		}
		
	}
	
	if(PWM_GetOneShotTripIntFlag(PWM1))
	{
		fg_SoftwareTZ = 1;
						PWM_ForceCHAandCHBLow(PWM1);
				SysState = sys_fault;
	}else
	{
		fg_SoftwareTZ = 0;
		
	}
	/*
			if(fg_AllFault)
			{			
				PWM_ForceCHAandCHBLow(PWM1);
                ZC_OFF;
				//pwm_SwState.enum_pwmSwState =pwmSwState_defaultState;
				SysState = sys_fault;
			}	
	*/
}

void PWM1_IRQHandler(void)
{
    
				pwmcalval.Vin =(float)ADCvalue.Vrms*0.000446465f;
        rmscalval.VinAcs =(float)ADCvalue.Vrms*0.000446465f;
        pwmcalval.Ia =(float)ADCvalue.Ia*0.000446465f;
        pwmcalval.Ib = (float)ADCvalue.Ib*0.000446465f;

		

 //ChargeProtect(); 
		


    
    
	if(SysState == sys_normal)
	{
		PWMcal();
        faultval.Fault_RMS = rmscalval.RMSVin;
        faultval.Fault_Ia = pwmcalval.Ia;
        faultval.Fault_Ib = pwmcalval.Ib;
        faultval.Fault_Dutya = pwmcalval.Dutya_NoVin;
        faultval.Fault_Dutyb = pwmcalval.Dutyb_NoVin;
        faultval.Fault_Vout = pwmcalval.Vout;
        faultval.Fault_Vref = pwmcalval.Vref ;
        faultval.Fault_Iref = pwmcalval.Iref;
      
//        I_ref[count] = pwmcalval.Ia*10000;
//        count++;
//        if(count>=599)
//        {
//            count = 0;
//        }
        
	}else
	{

		PWM_OFF;
     //   ZC_OFF;
	}
    
	PWM_ClearTimeEventInt(PWM1);
	
}


void Parameter_Loading()
{
  pwmcalval.Vref =1;
	pwmcalval.Vout_cmd = 2.7f;
	pwmcalval.Vout_cmd_95 = pwmcalval.Vout_cmd*0.95f;
	pwmcalval.Vout_cmd_110 = pwmcalval.Vout_cmd*1.1f;
	pwmcalval.Vout_80 = pwmcalval.Vout_cmd*0.8f;
	pwmcalval.B0_V =3.3208981f; //1.3543216f;//0.5230025f;//1.310795f;       
	pwmcalval.B1_V =-3.2973517f;//-1.3459093f;//-0.5222471f;//-1.30609f;
	pwmcalval.B0_I =0.2032968f;//0.4065937f;//0.3204501;//0.1778723;
	pwmcalval.B1_I =-0.2679121f;//-0.5358243f;//-0.4809178;//-0.29569;
	pwmcalval.B2_I =0.0882662f;//0.1765323f;//0.1804352;//0.122889;
	pwmcalval.pwmperiod = PWM_GetPeriod(PWM1);
	pwmcalval.Duty_max	=		pwmcalval.pwmperiod*0.95;
	pwmcalval.Duty_min	=		pwmcalval.pwmperiod*0.005;
	rmscalval.RMSProtectMin = (float)(80/141.9)*(80/141.9); 
	rmscalval.RMSProtectMax = (float)(380/141.9)*(380/141.9);
  rmscalval.RMS110V = (float)(180/141.9)*(180/141.9);
  rmscalval.OverRmsValue =rmscalval.RMSProtectMax*1.2f;
  rmscalval.UnderRMSValue =rmscalval.RMSProtectMin*0.8f;
	rmscalval.OverRMSRecoverValue = rmscalval.RMSProtectMax*0.9f;
	rmscalval.UnderRMSRecoverValue = rmscalval.RMSProtectMin*1.1f;
	protectval.VoutProtect = pwmcalval.Vout_cmd*141.9f*0.7f;

    TIMER_Run(TIMER1);
    NVIC_EnableIRQ(PWM1_IRQn);
    NVIC_EnableIRQ(TIMER1_IRQn);
}

void ResetVal()
{
	memset(&pwmcalval , 0 , sizeof(PWMCALVAL));
	memset(&SysFlag , 0 , sizeof(SYSTEMFLAG));
	memset(&rmscalval , 0 , sizeof(RMSCALVAL));
	
	Parameter_Loading();
		fg_PWMset = 0;
    rmscalval.RMSVin = 0;
    

	//pwm_SwState.enum_pwmSwState =pwmSwState_defaultState;

}

void FaultResetVal()
{
		memset(&pwmcalval , 0 , sizeof(PWMCALVAL));
		memset(&SysFlag , 0 , sizeof(SYSTEMFLAG));
	
		Parameter_Loading();
}


