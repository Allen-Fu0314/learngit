/******************************************************************************
 * @file     wdt.h
 * @brief    Watchdog module header file.
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

#ifndef WDT_H
#define WDT_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1168.h"




/******************************************************************************
 * @brief      Start watchdog counter
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     none
 *
 ******************************************************************************/
#define WDT_Run(WDTx)                       ((WDTx)->WDTCTL.all |= WDTCTL_ALL_INTEN_ENABLE)




/******************************************************************************
 * @brief      Stop watchdog counter
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     none
 *
 ******************************************************************************/
#define WDT_Stop(WDTx)                      ((WDTx)->WDTCTL.bit.INTEN = WDTCTL_BIT_INTEN_DISABLE)




/******************************************************************************
 * @brief      Enable watchdog interrupt and the counter
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     none
 *
 ******************************************************************************/
#define WDT_EnableInt(WDTx)                 ((WDTx)->WDTCTL.all |= WDTCTL_ALL_INTEN_ENABLE)




/******************************************************************************
 * @brief      Disable watchdog interrupt and the counter
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     none
 *
 ******************************************************************************/
#define WDT_DisableInt(WDTx)                ((WDTx)->WDTCTL.bit.INTEN = WDTCTL_BIT_INTEN_DISABLE)




/******************************************************************************
 * @brief      Enable watchdog system reset request
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     none
 *
 ******************************************************************************/
#define WDT_EnableSystemReset(WDTx)         ((WDTx)->WDTCTL.all |= WDTCTL_ALL_RSTEN_ENABLE)




/******************************************************************************
 * @brief      Disable watchdog reset system request
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     none
 *
 ******************************************************************************/
#define WDT_DisableSystemReset(WDTx)        ((WDTx)->WDTCTL.bit.RSTEN = 0)




/******************************************************************************
 * @brief      Enable watchdog running when core halted
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     none
 *
******************************************************************************/
#define WDT_EnableRunWhenCoreHalt(WDTx)     ((WDTx)->WDTCTL.bit.HALTEDRUN = WDTCTL_BIT_HALTEDRUN_ENABLE)




/******************************************************************************
 * @brief      Disable watchdog running when core halted
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     none
 *
******************************************************************************/
#define WDT_DisableRunWhenCoreHalt(WDTx)    ((WDTx)->WDTCTL.bit.HALTEDRUN = WDTCTL_BIT_HALTEDRUN_DISABLE)




/******************************************************************************
 * @brief      Enable watchdog running when core lockup
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     none
 *
******************************************************************************/
#define WDT_EnableRunWhenCoreLockup(WDTx)   ((WDTx)->WDTCTL.bit.LOCKUPRUN = WDTCTL_BIT_LOCKUPRUN_ENABLE)




/******************************************************************************
 * @brief      Disable watchdog running when core lockup
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     none
 *
******************************************************************************/
#define WDT_DisableRunWhenCoreLockup(WDTx)  ((WDTx)->WDTCTL.bit.LOCKUPRUN = WDTCTL_BIT_LOCKUPRUN_DISABLE)




/******************************************************************************
 * @brief      Set watchdog load register value
 *             When the value is written to the register, the WDT count is 
 *             immediately restarted from the new value. The minimum valid value is 1.
 *
 * @param[in]  WDTx      :  Select the watchdog module
 * @param[in]  u32LoadVal:  Watchdog load register value
 *
 * @return     none
 *
 ******************************************************************************/
#define WDT_SetReloadValue(WDTx,u32LoadVal) ((WDTx)->WDTLOAD.all = (u32LoadVal))




/******************************************************************************
 * @brief      Get watchdog load register value
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     The load register value
 *
******************************************************************************/
#define WDT_GetReloadValue(WDTx)            ((WDTx)->WDTLOAD.all)




/******************************************************************************
 * @brief      Get watchdog current counter value
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     Current counter value
 *
******************************************************************************/
#define WDT_GetCounterValue(WDTx)           ((WDTx)->WDTCNT.all)




/******************************************************************************
 * @brief      Get watchdog lock status 
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     0 - Write access to all other registers is enabled (not locked)
 *             1 - Write access to all other registers is disabled (locked)
 *
 ******************************************************************************/
#define WDT_GetLockStatus(WDTx)             ((WDTx)->WDTREGKEY.all)




/******************************************************************************
 * @brief      Get watchdog raw interrupt status
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     0 - Interrupt not occurred
 *             1 - Interrupt occurred
 *
 ******************************************************************************/
#define WDT_GetRawIntFlag(WDTx)             ((WDTx)->WDTRAWIF.bit.RAWINT)




/******************************************************************************
 * @brief      Get watchdog interrupt status
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     0 - Interrupt not occurred
 *             1 - Interrupt occurred
 *
 ******************************************************************************/
#define WDT_GetIntFlag(WDTx)                ((WDTx)->WDTIF.bit.INT)




/******************************************************************************
 * @brief      Clear watchdog interrupt flag
 *             A write of any value to the WDTIC register clears the watchdog 
 *             interrupt, and reloads the counter from the value in WDTLOAD
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     none
 * 
 ******************************************************************************/
#define WDT_ClearInt(WDTx)                  ((WDTx)->WDTIC.all = 0x0)




/******************************************************************************
 * @brief      Feed dog
 *             A write of any value to the WDTIC register clears the watchdog 
 *             interrupt, and reloads the counter from the value in WDTLOAD
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     none
 * 
 ******************************************************************************/
#define WDT_FeedDog(WDTx)                   ((WDTx)->WDTIC.all = 0x0)




/******************************************************************************
 * @brief      Enable write access to the protected WDT registers
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     none
 * 
 ******************************************************************************/
#define WDT_WALLOW(WDTx)                    ((WDTx)->WDTREGKEY.all = 0x1ACCE551)




/******************************************************************************
 * @brief      Disable write access to the protected WDT registers
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     none
 * 
 ******************************************************************************/
#define WDT_WDIS(WDTx)                      ((WDTx)->WDTREGKEY.all = 0x0)




/**
 *  @brief Watchdog Public Function Declaration
 */
void WDT_Init(WDT_REGS* WDTx, uint32_t u32TimeMs);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* WDT_H */


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
