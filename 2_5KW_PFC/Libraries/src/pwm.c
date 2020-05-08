/******************************************************************************
 * @file     pwm.c
 * @brief    PWM firmware functions.
 * @version  V1.4.0
 * @date     18-July-2019
 *
 * @note
 * Copyright (C) 2019 Spintrol Limited. All rights reserved.
 *
 * @attention
 * THIS SOFTWARE JUST PROVIDES CUSTOMERS WITH CODING INFORMATION REGARDING 
 * THEIR PRODUCTS, WHICH AIMS AT SAVING TIME FOR THEM. SPINTROL SHALL NOT BE
 * LIABLE FOR THE USE OF THE SOFTWARE. SPINTROL DOES NOT GUARANTEE THE 
 * CORRECTNESS OF THIS SOFTWARE AND RESERVES THE RIGHT TO MODIFY THE SOFTWARE 
 * WITHOUT NOTIFICATION.
 *
 ******************************************************************************/

#include "pwm.h"




/******************************************************************************
 * @brief      Initializes PWM complementary pair channel/ PWMxA and PWMxB
 *
 * @param[in]  PWMx         :  Select the PWM module (PWM0~PWM5)
 * @param[in]  u32PWMFreqHz :  PWM output waveform frequency (Hz)
 * @param[in]  u32DeadTimeNs:  Dead time (ns)
 *
 * @return     none
 *
 ******************************************************************************/
void PWM_ComplementaryPairChannelInit(PWM_REGS* PWMx, uint32_t u32PWMFreqHz, uint32_t u32DeadTimeNs)
{
  uint32_t u32DeadTimeClk;
  uint32_t u32PWMPeriod;
  
  /* Enable PWM clock */
  CLOCK_EnableModule(PWM_MODULE);
  
  /*  PWM initial step */
  /*  Step 1: Set PWM frequency and dead time */
  u32PWMPeriod   = ((CLOCK_GetModuleClock(PWM_MODULE))/u32PWMFreqHz)/2;
  u32DeadTimeClk = ((u32DeadTimeNs*((CLOCK_GetModuleClock(PWM_MODULE))/100000))/10000);
  
  
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

  /*  Step 5: Set duty reload timing, Shadow mode and reload on period point */
  PWMx->CMPCTL.all |=   CMPCTL_ALL_CMPALOCK_UNLOCK 
                      | CMPCTL_ALL_CMPBLOCK_UNLOCK
                      | CMPCTL_ALL_CMPALOAD_LOAD_ON_ZERO
                      | CMPCTL_ALL_CMPBLOAD_LOAD_ON_ZERO;


  /* Step 6: Waveform generating with Dead-time */
  PWMx->DBCTL.all  = 0;
  PWMx->DBCTL.all |=   DBCTL_ALL_FEDSRC_FROM_A 
                     | DBCTL_ALL_REDSRC_FROM_A 
                     | DBCTL_ALL_OUTASRC_RISING_EDGE 
                     | DBCTL_ALL_OUTBSRC_FALLING_EDGE 
                     | DBCTL_ALL_REDPOL_ACTIVE_HIGH 
                     | DBCTL_ALL_FEDPOL_ACTIVE_LOW 
                     | DBCTL_ALL_HALFCYCLE_DISABLE 
                     | DBCTL_ALL_REDEN_ENABLE 
                     | DBCTL_ALL_FEDEN_ENABLE;
                     
  PWMx->DBFED.all = u32DeadTimeClk;       /* Dead time delay */
  PWMx->DBRED.all = u32DeadTimeClk;

  /*  Config PWM stop mode upon lockup/halted signal triggered by debug or other system events */
  PWMx->TBCTL.all |= TBCTL_ALL_DBGRUN_STOP_AFTER_CYCLE;   // Finish current cycle and stop upon lockup/halted signal
}




/******************************************************************************
 * @brief      Initializes PWM single channel
 *             Example : Enable PWM0A or PWM3B
 *             Note    : This function only intial PWM control logic but not Pin
 *
 * @param[in]  PWMx        :  Select the PWM module (PWM0~PWM5)
 * @param[in]  ePWM_CH     :  PWM channel selection (PWM_CHA or PWM_CHB)
 * @param[in]  u32PWMFreqHz:  PWM output waveform frequency (Hz)
 *  
 * @return     none
 *
 ******************************************************************************/
void PWM_SingleChannelInit(PWM_REGS* PWMx, PWM_ChannelEnum ePWM_CH, uint32_t u32PWMFreqHz)
{
  uint32_t u32PWMPeriod;
  
  /* Enable PWMx clock */
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
  if(ePWM_CH==PWM_CHA)
  {
    PWMx->AQCTLA.all  =  AQCTLA_ALL_ZRO_DO_NOTHING
                        |AQCTLA_ALL_CAU_SET_HIGH 
                        |AQCTLA_ALL_PRD_DO_NOTHING 
                        |AQCTLA_ALL_CAD_SET_LOW;
  }
  else
  {
    PWMx->AQCTLB.all  =  AQCTLA_ALL_ZRO_DO_NOTHING
                        |AQCTLA_ALL_CBU_SET_HIGH 
                        |AQCTLA_ALL_PRD_DO_NOTHING 
                        |AQCTLA_ALL_CBD_SET_LOW;
  }

  /*  Step 5: Set duty reload timing, shadow mode and reload on zero  */
  PWMx->CMPCTL.all |=  CMPCTL_ALL_CMPALOCK_UNLOCK 
                      |CMPCTL_ALL_CMPBLOCK_UNLOCK 
                      |CMPCTL_ALL_CMPALOAD_LOAD_ON_ZERO 
                      |CMPCTL_ALL_CMPBLOAD_LOAD_ON_ZERO;

    
  /*  Config PWM stop mode upon lockup/halted signal triggered by debug or other system events */
  PWMx->TBCTL.all |= (TBCTL_ALL_DBGRUN_STOP_AFTER_CYCLE );   // Finish current cycle and stop upon lockup/halted signal
}




/******************************************************************************
 * @brief      Configure TZ0 source from GPIO
 *             The selected pin will be automatically configured as GPIO input
 *
 * @param[in]  ePinNum  :  Select the GPIO pin number
 *                         Please goto GPIO_PinEnum for selection
 *             ePinLevel:  Select the GPIO pin level to trigger trip event
 *                         Please goto GPIO_LevelEnum for selection
 * @return     none
 *
 ******************************************************************************/
void PWM_SetTZ0FromGPIO(GPIO_PinEnum ePinNum, uint8_t ePinLevel)
{
  /* Set Pin as GPIO input */
  GPIO_SetPinAsGPIO(ePinNum);
  GPIO_SetPinDir(ePinNum, GPIO_INPUT);
  
  PWMCFG->TZ0SRCCTL.all = ePinNum | (ePinLevel << TZ0SRCCTL_ALL_POL_Pos);
}




/******************************************************************************
 * @brief      Configure TZ1 source from GPIO
 *             The selected pin will be automatically configured as GPIO input
 *
 * @param[in]  ePinNum  :  Select the GPIO pin number
 *                         Please goto GPIO_PinEnum for selection
 *             ePinLevel:  Select the GPIO pin level to trigger trip event
 *                         Please goto GPIO_LevelEnum for selection
 * @return     none
 *
 ******************************************************************************/
void PWM_SetTZ1FromGPIO(GPIO_PinEnum ePinNum, uint8_t ePinLevel)
{
  /* Set Pin as GPIO input */
  GPIO_SetPinAsGPIO(ePinNum);
  GPIO_SetPinDir(ePinNum, GPIO_INPUT);
  
  PWMCFG->TZ1SRCCTL.all = ePinNum | (ePinLevel << TZ1SRCCTL_ALL_POL_Pos);
}




/******************************************************************************
 * @brief      Configure TZ2 source from GPIO
 *             The selected pin will be automatically configured as GPIO input
 *
 * @param[in]  ePinNum  :  Select the GPIO pin number
 *                         Please goto GPIO_PinEnum for selection
 *             ePinLevel:  Select the GPIO pin level to trigger trip event
 *                         Please goto GPIO_LevelEnum for selection
 * @return     none
 *
 ******************************************************************************/
void PWM_SetTZ2FromGPIO(GPIO_PinEnum ePinNum, uint8_t ePinLevel)
{
  /* Set Pin as GPIO input */
  GPIO_SetPinAsGPIO(ePinNum);
  GPIO_SetPinDir(ePinNum, GPIO_INPUT);
  
  PWMCFG->TZ2SRCCTL.all = ePinNum | (ePinLevel << TZ2SRCCTL_ALL_POL_Pos);
}




/******************************************************************************
 * @brief      Configure TZ3 source from GPIO
 *             The selected pin will be automatically configured as GPIO input
 *
 * @param[in]  ePinNum  :  Select the GPIO pin number
 *                         Please goto GPIO_PinEnum for selection
 *             ePinLevel:  Select the GPIO pin level to trigger trip event
 *                         Please goto GPIO_LevelEnum for selection
 * @return     none
 *
 ******************************************************************************/
void PWM_SetTZ3FromGPIO(GPIO_PinEnum ePinNum, uint8_t ePinLevel)
{
  /* Set Pin as GPIO input */
  GPIO_SetPinAsGPIO(ePinNum);
  GPIO_SetPinDir(ePinNum, GPIO_INPUT);
  
  PWMCFG->TZ3SRCCTL.all = ePinNum | (ePinLevel << TZ3SRCCTL_ALL_POL_Pos);
}




/******************************************************************************
 * @brief      Configure TZ4 source from GPIO
 *             The selected pin will be automatically configured as GPIO input
 *
 * @param[in]  ePinNum  :  Select the GPIO pin number
 *                         Please goto GPIO_PinEnum for selection
 *             ePinLevel:  Select the GPIO pin level to trigger trip event
 *                         Please goto GPIO_LevelEnum for selection
 * @return     none
 *
 ******************************************************************************/
void PWM_SetTZ4FromGPIO(GPIO_PinEnum ePinNum, uint8_t ePinLevel)
{
  /* Set Pin as GPIO input */
  GPIO_SetPinAsGPIO(ePinNum);
  GPIO_SetPinDir(ePinNum, GPIO_INPUT);
  
  PWMCFG->TZ4SRCCTL.all = ePinNum | (ePinLevel << TZ4SRCCTL_ALL_POL_Pos);
}



/******************************************************************************
 * @brief      Configure PWM synchronization signal from GPIO
 *
 * @param[in]  ePinNum  :  Select the GPIO pin number
 *                         Please goto GPIO_PinEnum for selection
 *             ePinLevel:  Select the GPIO pin level to generate Sync event
 *                         Please goto GPIO_LevelEnum for selection
 * @return     none
 *
 ******************************************************************************/
void PWM_SetSyncFromGPIO(GPIO_PinEnum ePinNum, uint8_t ePinLevel)
{
  /* Set Pin as GPIO input */
  GPIO_SetPinAsGPIO(ePinNum);
  GPIO_SetPinDir(ePinNum, GPIO_INPUT);
  
  PWMCFG->GPIOSYNCCTL.all = ePinNum | (ePinLevel << GPIOSYNCCTL_ALL_POL_Pos);
}




/******************************************************************************
 * @brief      Calculate the counter phase value
 *
 * @param[in]  u32TBPRD   :  PWM counter period
 * @param[in]  eCntMode   :  Counter mode
 * @param[in]  ePHSDIR    :  Phase direction
 *                           Valid value is COUNT_UP (1) or COUNT_DOWN (0)
 * @param[in]  u32SyncVal :  Counter phase value
 * @param[in]  u32TBClkDiv:  TBCLK divider
 *
 * @return     Time-base Phase register value
 *
 ******************************************************************************/
uint32_t PWM_CalculateSyncReloadValue(uint32_t u32TBPRD, PWM_CounterModeEnum eCntMode, uint8_t ePHSDIR, uint32_t u32SyncVal, uint32_t u32TBClkDiv)
{
  uint32_t u32PHSVal = 0;
  
  
  if(u32TBClkDiv > 1)
  {
    u32PHSVal = u32SyncVal;
  }
  else
  {
    if(eCntMode == COUNT_UP)
    {
      u32PHSVal = (u32SyncVal + 1) % u32TBPRD;
    }
    else if(eCntMode == COUNT_DOWN)
    {
      u32PHSVal = (u32SyncVal + u32TBPRD - 1) % u32TBPRD;
    }
    else if(eCntMode == COUNT_UP_DOWN)
    {
      if(ePHSDIR == COUNT_UP)
      {
        u32PHSVal = (u32SyncVal == u32TBPRD)? (u32TBPRD - 1) : (u32SyncVal + 1);
      }
      else if(ePHSDIR == COUNT_DOWN)
      {
        u32PHSVal = (u32SyncVal == 0)? (1) : (u32SyncVal - 1);
      }
    }
  }
  
  return u32PHSVal;
}


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
