/*******************************************************************************
* @file     system.h
* @brief    SYSTEM driver header file.
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


#ifndef SYSTEM_H
#define SYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1168.h"




/**
 *  @brief  Memory Error events definitions
 */
typedef enum
{
  MEM_ROM_1BIT_ERROR              = 0,      /*!< ROM access one-bit error   */
  MEM_ROM_2BIT_ERROR              = 1,      /*!< ROM access two-bit error   */
  MEM_FLASH_1BIT_ERROR            = 2,      /*!< FLASH access one-bit error */
  MEM_FLASH_2BIT_ERROR            = 3,      /*!< FLASH access two-bit error */
  MEM_IRAM_ERROR                  = 4,      /*!< IRAM parity error          */
  MEM_DRAM_ERROR                  = 5,      /*!< DRAM parity error          */
  MEM_SIO0_ERROR                  = 6,      /*!< SIO0 parity error          */
} SYSTEM_MemErrorEnum;




/**
 *  @brief  Reset events definitions
 */
typedef enum
{
  RESET_EVENT_ROM_ERROR           = 0,      /*!< Reset on 2-bit error during ROM access   */
  RESET_EVENT_FLASH_ERROR         = 1,      /*!< Reset on 2-bit error during Flash access */
  RESET_EVENT_IRAM_ERROR          = 2,      /*!< Reset on parity error during IRAM access */
  RESET_EVENT_DRAM_ERROR          = 3,      /*!< Reset on parity error during DRAM access */
  RESET_EVENT_SIO0_ERROR          = 4,      /*!< Reset on parity error during SIO access  */
  RESET_EVENT_VDD12_TOO_LOW0      = 5,      /*!< Reset on VDD12L0 event                   */
  RESET_EVENT_VDD12_TOO_LOW1      = 6,      /*!< Reset on VDD12L1 event                   */
  RESET_EVENT_VDD12_TOO_HIGH      = 7,      /*!< Reset on VDD12H event                    */
  RESET_EVENT_VDD33_TOO_LOW       = 8,      /*!< Reset on VDD33L event                    */
  RESET_EVENT_VDD33_TOO_HIGH      = 9,      /*!< Reset on VDD33H event                    */
  RESET_EVENT_PLL_UNLOCK          = 10,     /*!< Reset on PLL unlock event                */
  RESET_EVENT_CLK_DETECT_ERROR    = 11,     /*!< Reset on clock detect error event        */
} SYSTEM_ResetEvtEnum;




/******************************************************************************
 * @brief      Enable memory error interrupt
 *
 * @param[in]  eMemEvt:  Select the memory error event
 *                       Please go to SYSTEM_MemErrorEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
#define SYSTEM_EnableMemErrorInt(eMemEvt)   (SYSTEM->MEMIE.all |= (0x1UL << (eMemEvt)))




/******************************************************************************
 * @brief      Disable memory error interrupt
 *
 * @param[in]  eMemEvt:  Select the memory error event
 *                       Please go to SYSTEM_MemErrorEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
#define SYSTEM_DisableMemErrorInt(eMemEvt)  (SYSTEM->MEMIE.all &= ~(0x1UL << (eMemEvt)))




/******************************************************************************
 * @brief      Enable all memory error interrupts
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define SYSTEM_EnableAllMemErrorInt()       (SYSTEM->MEMIE.all = 0x7F)




/******************************************************************************
 * @brief      Disable all memory error interrupts
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define SYSTEM_DisableAllMemErrorInt()      (SYSTEM->MEMIE.all = 0x0)




/******************************************************************************
 * @brief      Clear memory error interrupt
 *
 * @param[in]  eMemEvt:  Select the memory error event
 *                       Please go to SYSTEM_MemErrorEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
#define SYSTEM_ClearMemErrorInt(eMemEvt)    (SYSTEM->MEMIC.all = (0x1UL << (eMemEvt)))




/******************************************************************************
 * @brief      Clear global memory error interrupt
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define SYSTEM_ClearMemErrorGlobalInt()     (SYSTEM->MEMIC.all = MEMIC_ALL_MEMINT_CLEAR)




/******************************************************************************
 * @brief      Get memory error interrupt flag
 *
 * @param[in]  eMemEvt:  Select the memory error event
 *                       Please go to SYSTEM_MemErrorEnum for details
 *
 * @return     0 - The specified memory error interrupt not occurred
 *             1 - The specified memory error interrupt occurred
 *
 ******************************************************************************/
#define SYSTEM_GetMemErrorIntFlag(eMemEvt)  ((SYSTEM->MEMIF.all & (0x1UL << (eMemEvt))) >> (eMemEvt))




/******************************************************************************
 * @brief      Get Memory error interrupt flag
 *
 * @param[in]  none
 *
 * @return     0 - Memory error interrupt not occurred
 *             1 - Memory error interrupt occurred
 *
 ******************************************************************************/
#define SYSTEM_GetMemErrorGlobalIntFlag()   (SYSTEM->MEMIF.bit.MEMINT)




/******************************************************************************
 * @brief      Enable reset event
 *
 * @param[in]  eRSTEvt:  Reset event
 *                       Please go to SYSTEM_ResetEvtEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
#define SYSTEM_EnableResetEvent(eRSTEvt)    (SYSTEM->RSTEVTEN.all |= (0x1UL << (eRSTEvt)))




/******************************************************************************
 * @brief      Disable reset event
 *
 * @param[in]  eRSTEvt:  Reset event
 *                       Please go to SYSTEM_ResetEvtEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
#define SYSTEM_DisableResetEvent(eRSTEvt)   (SYSTEM->RSTEVTEN.all &= ~(0x1UL << (eRSTEvt)))




/******************************************************************************
 * @brief      Enable all reset events
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define SYSTEM_EnableAllResetEvent()        (SYSTEM->RSTEVTEN.all = 0xFFF)




/******************************************************************************
 * @brief      Disable all reset events
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define SYSTEM_DisableAllResetEvent()       (SYSTEM->RSTEVTEN.all = 0x0)




/******************************************************************************
 * @brief      Clear reset event status
 *
 * @param[in]  eRSTEvt:  Reset event
 *                       Please go to SYSTEM_ResetEvtEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
#define SYSTEM_ClearResetEventStatus(eRSTEvt) (SYSTEM->RSTEVTCLR.all = (0x1UL << (eRSTEvt)))




/******************************************************************************
 * @brief      Clear WDT0 reset event status
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define SYSTEM_ClearWDT0ResetStatus()       (SYSTEM->RSTEVTCLR.all = RSTEVTCLR_ALL_WDT0RST_CLEAR)




/******************************************************************************
 * @brief      Clear WDT1 reset event status
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define SYSTEM_ClearWDT1ResetStatus()       (SYSTEM->RSTEVTCLR.all = RSTEVTCLR_ALL_WDT1RST_CLEAR)




/******************************************************************************
 * @brief      Clear system reset status
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define SYSTEM_ClearSystemResetStatus()     (SYSTEM->RSTEVTCLR.all = RSTEVTCLR_ALL_SYSRESET_CLEAR)




/******************************************************************************
 * @brief      Get reset event status
 *
 * @param[in]  eRSTEvt:  Reset event
 *                       Please go to SYSTEM_ResetEvtEnum for details
 *
 * @return     0 - The specified reset event not occur
 *             1 - The specified reset event has occurred
 *
 ******************************************************************************/
#define SYSTEM_GetResetEventStatus(eRSTEvt) ((SYSTEM->RSTEVTSTS.all & (0x1UL << (eRSTEvt))) >> (eRSTEvt))




/******************************************************************************
 * @brief      Get WDT0 reset event status
 *
 * @param[in]  none
 *
 * @return     0 - Reset not triggered by WDT0 reset event
 *             1 - Reset triggered by WDT0 reset event
 *
 ******************************************************************************/
#define SYSTEM_GetWDT0ResetStatus()         (SYSTEM->RSTEVTSTS.bit.WDT0RST)




/******************************************************************************
 * @brief      Get WDT1 reset event status
 *
 * @param[in]  none
 *
 * @return     0 - Reset not triggered by WDT1 reset event
 *             1 - Reset triggered by WDT1 reset event
 *
 ******************************************************************************/
#define SYSTEM_GetWDT1ResetStatus()         (SYSTEM->RSTEVTSTS.bit.WDT1RST)




/******************************************************************************
 * @brief      Get System reset event status
 *
 * @param[in]  none
 *
 * @return     0 - Reset not triggered by System reset event
 *             1 - Reset triggered by System reset event
 *
 ******************************************************************************/
#define SYSTEM_GetSystemResetStatus()       (SYSTEM->RSTEVTSTS.bit.SYSRESET)




/******************************************************************************
 * @brief      Enable write access to the protected SYSTEM registers
 *
 * @param[in]  none
 *
 * @return     none
 * 
 ******************************************************************************/
#define SYSTEM_WALLOW()                     (SYSTEM->SYSREGKEY.all = 0x1ACCE551)




/******************************************************************************
 * @brief      Disable write access to the protected SYSTEM registers
 *
 * @param[in]  none
 *
 * @return     none
 * 
 ******************************************************************************/
#define SYSTEM_WDIS()                       (SYSTEM->SYSREGKEY.all = 0x0)




/**
 *  @brief System Public Function Declaration
 */
uint64_t SYSTEM_GetUID(void);
uint64_t SYSTEM_GetRandomNum(void);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* SYSTEM_H */


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
