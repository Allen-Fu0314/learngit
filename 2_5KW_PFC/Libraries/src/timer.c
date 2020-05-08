/******************************************************************************
 * @file     timer.c
 * @brief    TIMER firmware functions.
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

#include "timer.h"




/******************************************************************************
 * @brief      Initialize the timer 
 *
 * @param[in]  TIMERx          :  Select the timer module
 * @param[in]  u32TimerPeriodMs:  Timer interrupt period (ms)
 *
 * @return     none
 *
 ******************************************************************************/
void TIMER_Init(TIMER_REGS* TIMERx, uint32_t u32TimerPeriodMs)
{
  uint32_t u32TimerClk;
  
  /* Enable and Get Timer module clock */
  if(TIMERx == TIMER0)
  {
    CLOCK_EnableModule(TIMER0_MODULE);
    
    u32TimerClk = CLOCK_GetModuleClock(TIMER0_MODULE);
  }
  else if(TIMERx == TIMER1)
  {
    CLOCK_EnableModule(TIMER1_MODULE);
    
    u32TimerClk = CLOCK_GetModuleClock(TIMER1_MODULE);
  }
  else
  {
    CLOCK_EnableModule(TIMER2_MODULE);
    
    u32TimerClk = CLOCK_GetModuleClock(TIMER2_MODULE);
  }
  
  /* Set reload timer while timer reaches 0 */
  TIMERx->TMRRELOAD.all = TMRRELOAD_ALL_VAL_(CLOCK_MsToCounter(u32TimerPeriodMs,u32TimerClk));
  
  /* Enable Timer interrupt */
  TIMERx->TMRIE.all |= TMRIE_ALL_INT_ENABLE;
  
  /* Enable Timer and select internal clock */
  TIMERx->TMRCTL.all = TMRCTL_ALL_EN_ENABLE | TMRCTL_ALL_EXTINMODE_DISABLE;
}


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
