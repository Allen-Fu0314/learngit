/******************************************************************************
 * @file     system.c
 * @brief    SYSTEM firmware functions.
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

#include "system.h"




/******************************************************************************
 * @brief      Get Chip Unique ID
 *
 * @param[in]  none
 *
 * @return     none
 * 
 ******************************************************************************/
uint64_t SYSTEM_GetUID(void)
{
  uint64_t u64ID;
  
  u64ID = SYSTEM->UID1.all;
  u64ID <<= 32;
  u64ID |= SYSTEM->UID0.all;
  
  return u64ID;
}




/******************************************************************************
 * @brief      Get Chip Random number
 *
 * @param[in]  none
 *
 * @return     none
 * 
 ******************************************************************************/
uint64_t SYSTEM_GetRandomNum(void)
{
  uint64_t u64RandNum;
  
  u64RandNum = SYSTEM->RND1.all;
  u64RandNum <<= 32;
  u64RandNum |= SYSTEM->RND0.all;
  
  return u64RandNum;
}


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
