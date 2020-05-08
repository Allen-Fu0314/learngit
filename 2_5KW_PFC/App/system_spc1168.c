/******************************************************************************
 * @file     system_spc1168.c
 * @brief    CMSIS Device System Source File for SPC1168 Device Series
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

#include "spc1168.h"




/**
 *  @brief  Define clocks
 */
#define __SYSTEM_CLOCK            (32000000UL)  /* 32MHz */




/**
 *  @brief  System Core Clock Variable
 */
uint32_t SystemCoreClock = __SYSTEM_CLOCK;  /* System Core Clock Frequency      */




/**
 *  @brief  System Information Data Variable
 */
SysInfoStruct SysInfo;




/******************************************************************************
 * @brief      Updates the SystemCoreClock with current core Clock
 *             retrieved from cpu registers.
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
void SystemCoreClockUpdate (void)
{

  SystemCoreClock = __SYSTEM_CLOCK;

}




/******************************************************************************
 * @brief      Initialize the system
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
void SystemInit (void)
{
  #if (__FPU_USED == 1)
    SCB->CPACR |= ((3UL << 10*2) |                 /* set CP10 Full Access */
                   (3UL << 11*2)  );               /* set CP11 Full Access */
  #endif

#ifdef UNALIGNED_SUPPORT_DISABLE
  SCB->CCR |= SCB_CCR_UNALIGN_TRP_Msk;
#endif

  SystemCoreClock = __SYSTEM_CLOCK;

}


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
