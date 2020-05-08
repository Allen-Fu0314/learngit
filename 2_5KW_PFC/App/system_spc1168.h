/******************************************************************************
 * @file     system_spc1168.h
 * @brief    CMSIS Device System Header File for SPC1168 Device Series
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


#ifndef SYSTEM_ARMCM4_H
#define SYSTEM_ARMCM4_H

#ifdef __cplusplus
extern "C" {
#endif




/**
 *  @brief  System Clock Frequency (Core Clock)
 */
extern uint32_t SystemCoreClock;




/**
 *  @brief  System Information Structure Declaration
 */
typedef struct
{
  uint32_t u32HCLK;                         /*!< HCLK(CPU Core) Frequency */
  uint32_t u32PCLK;                         /*!< PCLK Frequency           */
  int32_t  i32SHOffset;
  int32_t  i32SHGain;
} SysInfoStruct;




/**
 *  @brief  System information data
 */
extern SysInfoStruct SysInfo;




/******************************************************************************
 * @brief      Initialize the system
 *             Setup the microcontroller system
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
extern void SystemInit(void);




/******************************************************************************
 * @brief      Updates the SystemCoreClock with current core Clock
 *             retrieved from cpu registers.
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
extern void SystemCoreClockUpdate(void);


#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_ARMCM4_H */


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
