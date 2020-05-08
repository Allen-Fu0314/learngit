/******************************************************************************
 * @file     wdt.c
 * @brief    Watchog firmware functions.
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

#include "wdt.h"




/******************************************************************************
 * @brief      Initialize the Watchdog Timer
 *
 * @param[in]  WDTx     :  Select the watchdog module
 * @param[in]  u32TimeMs:  Watchdog timeout in ms
 *
 * @return     none
 *
 ******************************************************************************/
void WDT_Init(WDT_REGS* WDTx, uint32_t u32TimeMs)
{
  uint32_t u32WdtClk;
  
  /* Check WDT lock status */
  if(WDT_GetLockStatus(WDTx) == 1)
  {
    /* Enable write access to all other registers */
    WDT_WALLOW(WDTx);
  }

  /* Enable and Get Watchdog module clock */
  if(WDTx == WDT0)
  {
    CLOCK_EnableModule(WDT0_MODULE);
    
    u32WdtClk = CLOCK_GetModuleClock(WDT0_MODULE);
  }
  else
  {
    CLOCK_EnableModule(WDT1_MODULE);
    
    u32WdtClk = CLOCK_GetModuleClock(WDT1_MODULE);
  }
  
  /* Watchdog load register value */
  WDTx->WDTLOAD.all = u32WdtClk / 1000 * u32TimeMs;

  /* Watchdog reset output enable */
  WDTx->WDTCTL.all |= WDTCTL_ALL_RSTEN_ENABLE;

  /* Watchdog counter and interrupt enable */
//  WDTx->WDTCTL.all |= WDTCTL_ALL_INTEN_ENABLE;
}


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
