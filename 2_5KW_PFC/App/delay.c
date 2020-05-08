/******************************************************************************
 * @file     delay.c
 * @brief    Time-Delay firmware functions.
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

#include "delay.h"




/**
 *  @brief  Clock cycles per microseconds
 */
uint32_t u32DelayLoopPerUs;      /* (1) The number of loops in one us 
                                    (2) Used for time out when timer is used as delay */
uint32_t u32DelayClockPerUs;




/******************************************************************************
 * @brief      Initializes the time-delay module
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
void Delay_Init(void)
{
#if DELAY_FOR_MEM != DELAY_FOR_FLASH
  u32DelayLoopPerUs  = ((SysInfo.u32HCLK) / 1000000)>>2;  /* Each loop will cost 4 cycles */
#else
  u32DelayLoopPerUs  = ((SysInfo.u32HCLK) / 1000000)/(4 * SysInfo.u32HCLK / 32000000);
#endif
  
  /* Delay by timer */
  u32DelayClockPerUs = (SysInfo.u32HCLK) / 1000000;

#if DELAY_TYPE != DELAY_BY_CPU
  u32DelayLoopPerUs  = ((SysInfo.u32HCLK) / 1000000)<<2;
  TIMER_EnableInt(DELAY_TIMER);
#endif
}




/******************************************************************************
 * @brief      Delays the specified milliseconds
 *
 * @param[in]  u32Delay_Ms:  The milliseconds to delay, if the system clock = 24 MHz, 
 *                           the maximum time delay is 699 ms.
 *
 * @return     none
 *
 ******************************************************************************/
void Delay_Ms(uint32_t u32Delay_Ms)
{
  Delay_Us(u32Delay_Ms * 1000);
}




/******************************************************************************
 * @brief      Delays the specified microseconds
 *
 * @param[in]  u32Delay_Us:  The microseconds to delay
 *
 * @return     none
 *
 ******************************************************************************/
void Delay_Us(uint32_t u32Delay_Us)
{
#if  DELAY_TYPE == DELAY_BY_CPU
  /* Delay by CPU */
  u32Delay_Us=(u32Delay_Us*u32DelayLoopPerUs);                          /* There is 4 cycle during for in O0~O3  */
  while(u32Delay_Us){u32Delay_Us--;}
#else
  /* Delay by timer */
  volatile uint32_t u32Timeout;                                         /* Prevent optimization effect           */
                                                                        /* This timeout is suitable for O0~O3    */
  
  u32Timeout = u32DelayLoopPerUs;                                       /* About 1.25 us as timeout in O1~O3     */
                                                                        /* About 1.5  us as timeout in O0        */
  
  TIMER_Stop(DELAY_TIMER);                                              /* Stop timer                            */
  TIMER_SetReloadValue(DELAY_TIMER, u32Delay_Us * u32DelayClockPerUs);  /* Set timer reload value                */
  TIMER_ClearInt(DELAY_TIMER);                                          /* Clear timer interrupt flag            */
  TIMER_Run(DELAY_TIMER);                                               /* Timer run                             */
  while((!TIMER_GetIntFlag(DELAY_TIMER)))                               /* Wait until (1) Timer flag enable      */
  {                                                                     /*            (2) Timer out  occurs      */
    if((u32Timeout--)==0){ break;}
  }
#endif
}


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
