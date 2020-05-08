/******************************************************************************
 * @file     ecap.c
 * @brief    ECAP firmware functions.
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

#include "ecap.h"




/******************************************************************************
 * @brief      Initializes the ECAP module operating in capture mode
 *
 * @param[in]  ECAPx  :  Select the ECAP module
 * @param[in]  ePinNum:  Select the GPIO pin as capture input
 *
 * @return     none
 *
 ******************************************************************************/
void ECAP_CaptureModeInit(ECAP_REGS* ECAPx, GPIO_PinEnum ePinNum)
{
  /* Configure IO Pin for capture */
  ECAP_SetInputPin(ECAPx, ePinNum);
  
  /* Open ECAP clock */
  CLOCK_EnableModule(ECAP_MODULE);
  
  ECAPx->CAPCTL.all =   CAPCTL_ALL_APWMMODE_CAPTURE_MODE        /* Configure ECAP as Capture mode             */
                      | CAPCTL_ALL_CAPLDEN_ENABLE               /* Enable Cap Register loading on a capture event */
                      | CAPCTL_ALL_STOPWRAP_ON_CAPTURE_EVENT3   /* Stop/Wrap after Capture Event 3            */
                      | CAPCTL_ALL_ONESHOT_DISABLE              /* Operate in Continous mode                  */
                      | CAPCTL_ALL_CAP0POL_TRIG_ON_RISING_EDGE  /* Event 0 occurs on pulse rising edge        */
                      | CAPCTL_ALL_CAP1POL_TRIG_ON_FALLING_EDGE /* Event 1 occurs on pulse falling edge       */
                      | CAPCTL_ALL_CAP2POL_TRIG_ON_RISING_EDGE  /* Event 2 occurs on pulse rising edge        */
                      | CAPCTL_ALL_CAP3POL_TRIG_ON_FALLING_EDGE /* Event 3 occurs on pulse falling edge       */
                      | CAPCTL_ALL_CNTRST0_ENABLE               /* Reset capture counter when Event 0 occurs  */
                      | CAPCTL_ALL_CNTRST1_ENABLE               /* Reset capture counter when Event 1 occurs  */
                      | CAPCTL_ALL_CNTRST2_ENABLE               /* Reset capture counter when Event 2 occurs  */
                      | CAPCTL_ALL_CNTRST3_ENABLE               /* Reset capture counter when Event 3 occurs  */
                      | CAPCTL_ALL_TSCNTRUN_START_COUNTER;      /* Enable ECAP working                        */

  /* Enable Capture event interrupt */
  ECAPx->CAPIE.all |= CAPIE_ALL_CEVT0_ENABLE | 
                      CAPIE_ALL_CEVT1_ENABLE | 
                      CAPIE_ALL_CEVT2_ENABLE | 
                      CAPIE_ALL_CEVT3_ENABLE;

  /* If you do NOT want to lose any pulse information, please use interrupt type */
  // NVIC_EnableIRQ(ECAP_IRQn);
}




/******************************************************************************
 * @brief      Initializes the ECAP module operating in APWM mode
 *
 * @param[in]  ECAPx     :  Select the ECAP module
 * @param[in]  ePinNum   :  Select GPIO pin for output PWM
 * @param[in]  u32PwmFreq:  Define the frequency of PWM
 *                          This function will calculate period automaticlly
 *
 * @return     none
 *
 ******************************************************************************/
void ECAP_APWMModeInit(ECAP_REGS* ECAPx, GPIO_PinEnum ePinNum, uint32_t u32PwmFreq)
{
  /* Configure ECAP APWM output pin */
  GPIO_SetPinChannel(ePinNum, PINMUX_CHANNEL_7);
  
  /* Config ECAP operating mode */
  ECAPx->CAPCTL.bit.APWMMODE = CAPCTL_BIT_APWMMODE_APWM_MODE;
  
  /* Calculate Period Value based on system clock, ECAP clock and PWM frequency*/
  ECAPx->CAP0.all = CLOCK_GetModuleClock(ECAP_MODULE)/u32PwmFreq;
}




/******************************************************************************
 * @brief      Set the duty of PWM waveform
 *
 * @param[in]  u32PwmDuty:  Define the duty of PWM
 *                          PWM duty = u32PwmDuty/10000  (00.00% ~ 100.00%)
 *
 * @return     none
 *
 ******************************************************************************/
void ECAP_APWMSetDuty(ECAP_REGS* ECAPx, uint32_t u32PwmDuty)
{
  if(u32PwmDuty == 10000)
  {
    ECAPx->CAP1.all = ECAPx->CAP0.all;
  }
  else
  {
    ECAPx->CAP1.all = (ECAPx->CAP0.all / 10000) * u32PwmDuty;
  }
}




/******************************************************************************
 * @brief      Set ECAP input pin
 *
 * @param[in]  ePinNum:  Select the GPIO pin
 *                       See GPIO_PinEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
void ECAP_SetInputPin(ECAP_REGS* ECAPx, GPIO_PinEnum ePinNum)
{
  /* Set Pin as GPIO function */
  GPIO_SetPinAsGPIO(ePinNum);
  GPIO_SetPinDir(ePinNum, GPIO_INPUT);
  
  /* Select ECAP event source pin */
  ECAPx->CAPSRCCTL.bit.IOSEL = ePinNum;
}




/******************************************************************************
 * @brief      Set capture synchronization source input 
 *
 * @param[in]  ECAPx    :  Select the ECAP module
 * @param[in]  ePinNum  :  Select the GPIO pin
 *                         See GPIO_PinEnum for details
 * @param[in]  ePinLevel:  Select the GPIO pin level to generate Sync event
 *                         Please goto GPIO_LevelEnum for selection
 *
 * @return     none
 *
 ******************************************************************************/
void ECAP_SetSyncFromGPIO(ECAP_REGS* ECAPx, GPIO_PinEnum ePinNum, uint8_t ePinLevel)
{
  /* Set Pin as GPIO input */
  GPIO_SetPinAsGPIO(ePinNum);
  GPIO_SetPinDir(ePinNum, GPIO_INPUT);
  
  ECAPx->CAPSYNCICTL.all = ePinNum | (ePinLevel << CAPSYNCICTL_ALL_POL_Pos);
}


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
