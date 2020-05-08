/******************************************************************************
 * @file     ecap.h
 * @brief    eCAP driver header file.
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

#ifndef ECAP_H
#define ECAP_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1168.h"




/**
 *  @brief  ECAP interrupt type definition
 */
typedef enum
{
  ECAP_CEVT0                      =  0,               /*!< Capture event 0                        */
  ECAP_CEVT1                      =  1,               /*!< Capture event 1                        */
  ECAP_CEVT2                      =  2,               /*!< Capture event 2                        */
  ECAP_CEVT3                      =  3,               /*!< Capture event 3                        */
} ECAP_EvtEnum;




/**
 *  @brief  ECAP interrupt type definition
 */
typedef enum
{
  ECAP_INT_CEVT0                  =  0,               /*!< Capture event 0 interrupt                        */
  ECAP_INT_CEVT1                  =  1,               /*!< Capture event 1 interrupt                        */
  ECAP_INT_CEVT2                  =  2,               /*!< Capture event 2 interrupt                        */
  ECAP_INT_CEVT3                  =  3,               /*!< Capture event 3 interrupt                        */
  ECAP_INT_CNT_OVERFLOW           =  4,               /*!< Counter overflow interrupt                       */
  ECAP_INT_CNT_EQU_PRD            =  5,               /*!< Counter equal period interrupt (APWM mode only)  */
  ECAP_INT_CNT_EQU_CMP            =  6,               /*!< Counter equal Compare interrupt (APWM mode only) */
} ECAP_IntEnum;




/******************************************************************************
 * @brief      APWM Output is active high
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_APWMSetActiveHigh(ECAPx)       ((ECAPx)->CAPCTL.bit.APWMPOL = CAPCTL_BIT_APWMPOL_ACTIVE_HIGH)





/******************************************************************************
 * @brief      APWM Output is active low
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_APWMSetActiveLow(ECAPx)        ((ECAPx)->CAPCTL.bit.APWMPOL = CAPCTL_BIT_APWMPOL_ACTIVE_LOW)




/******************************************************************************
 * @brief      Counter Run
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_RunCounter(ECAPx)              ((ECAPx)->CAPCTL.bit.TSCNTRUN = CAPCTL_BIT_TSCNTRUN_START_COUNTER)




/******************************************************************************
 * @brief      Counter Stop
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_StopCounter(ECAPx)             ((ECAPx)->CAPCTL.bit.TSCNTRUN = CAPCTL_BIT_TSCNTRUN_STOP_COUNTER)




/******************************************************************************
 * @brief      Set ECAP synchronization reload value
 *             ECAP counter will equal CAPCNTPHS after synchronization event
 *
 * @param[in]  ECAPx :  Select the ECAP module
 * @param[in]  u32Val:  ECAP counter reload value
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_SetSyncReloadValue(ECAPx,u32Val)  ((ECAPx)->CAPCNTPHS.all = (u32Val))




/******************************************************************************
 * @brief      Enable phase synchronization
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_EnableSync(ECAPx)              ((ECAPx)->CAPCTL.all |= CAPCTL_ALL_PHSEN_ENABLE)




/******************************************************************************
 * @brief      Disable phase synchronization
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_DisableSync(ECAPx)             ((ECAPx)->CAPCTL.bit.PHSEN = CAPCTL_BIT_PHSEN_DISABLE)




/******************************************************************************
 * @brief      Software force counter synchronizing
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_ForceSync(ECAPx)               ((ECAPx)->CAPCTL.all |= CAPCTL_ALL_FRCSYNC_ENABLE)




/******************************************************************************
 * @brief      One-shot Re-Arming
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_OneshotReArm(ECAPx)            ((ECAPx)->CAPCTL.all |= CAPCTL_ALL_REARM_ENABLE)




/******************************************************************************
 * @brief      Operate in one-shot mode
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_EnableOneshotMode(ECAPx)       ((ECAPx)->CAPCTL.bit.ONESHOT = CAPCTL_BIT_ONESHOT_ENABLE)




/******************************************************************************
 * @brief      Operate in continuous mode
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_DisableOneshotMode(ECAPx)      ((ECAPx)->CAPCTL.bit.ONESHOT = CAPCTL_BIT_ONESHOT_DISABLE)




/******************************************************************************
 * @brief      Set event filter prescale
 *
 * @param[in]  ECAPx :  Select the ECAP module
 * @param[in]  u16Div:  Event filter prescale (1 ~ 256)
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_SetEventDiv(ECAPx,u16Div)      ((ECAPx)->CAPCTL.bit.EVTDIV = (u16Div - 1))




/******************************************************************************
 * @brief      Enable counter reset on capture event
 *
 * @param[in]  ECAPx  :  Select the ECAP module
 * @param[in]  eCapEvt:  Select the capture event
 *                       Please go to ECAP_EvtEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_EnableEventResetCounter(ECAPx,eCapEvt)   ((ECAPx)->CAPCTL.all |= (CAPCTL_ALL_CNTRST0_ENABLE << (eCapEvt << 1)))




/******************************************************************************
 * @brief      Disable counter reset on capture event
 *
 * @param[in]  ECAPx  :  Select the ECAP module
 * @param[in]  eCapEvt:  Select the capture event
 *                       Please go to ECAP_EvtEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_DisableEventResetCounter(ECAPx,eCapEvt)  ((ECAPx)->CAPCTL.all &= ~(CAPCTL_ALL_CNTRST0_ENABLE << (eCapEvt << 1)))




/******************************************************************************
 * @brief      Capture event triggered on rising edge
 *
 * @param[in]  ECAPx  :  Select the ECAP module
 * @param[in]  eCapEvt:  Select the capture event
 *                       Please go to ECAP_EvtEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_SetEventTriggeredOnRisingEdge(ECAPx,eCapEvt)   ((ECAPx)->CAPCTL.all |= (CAPCTL_ALL_CAP1POL_TRIG_ON_RISING_EDGE << (eCapEvt << 1)))




/******************************************************************************
 * @brief      Capture event triggered on falling edge
 *
 * @param[in]  ECAPx  :  Select the ECAP module
 * @param[in]  eCapEvt:  Select the capture event
 *                       Please go to ECAP_EvtEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_SetEventTriggeredOnFallingEdge(ECAPx,eCapEvt)  ((ECAPx)->CAPCTL.all &= ~(CAPCTL_ALL_CAP1POL_TRIG_ON_RISING_EDGE << (eCapEvt << 1)))




/******************************************************************************
 * @brief      Set Counter Value
 *
 * @param[in]  ECAPx    :  Select the ECAP module
 * @param[in]  u32CntVal:  Counter value
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_SetCounterValue(ECAPx,u32CntVal) ((ECAPx)->CAPTSCNT.all = (u32CntVal))




/******************************************************************************
 * @brief      Enable CEVT0 Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_EnableCEVT0Int(ECAPx)          ((ECAPx)->CAPIE.bit.CEVT0 = CAPIE_BIT_CEVT0_ENABLE)




/******************************************************************************
 * @brief      Disable CEVT0 Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_DisableCEVT0Int(ECAPx)         ((ECAPx)->CAPIE.bit.CEVT0 = CAPIE_BIT_CEVT0_DISABLE)




/******************************************************************************
 * @brief      Enable CEVT1 Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_EnableCEVT1Int(ECAPx)          ((ECAPx)->CAPIE.bit.CEVT1 = CAPIE_BIT_CEVT1_ENABLE)




/******************************************************************************
 * @brief      Disable CEVT1 Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_DisableCEVT1Int(ECAPx)         ((ECAPx)->CAPIE.bit.CEVT1 = CAPIE_BIT_CEVT1_DISABLE)




/******************************************************************************
 * @brief      Enable CEVT2 Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_EnableCEVT2Int(ECAPx)          ((ECAPx)->CAPIE.bit.CEVT2 = CAPIE_BIT_CEVT2_ENABLE)




/******************************************************************************
 * @brief      Disable CEVT2 Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_DisableCEVT2Int(ECAPx)         ((ECAPx)->CAPIE.bit.CEVT2 = CAPIE_BIT_CEVT2_DISABLE)




/******************************************************************************
 * @brief      Enable CEVT3 Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_EnableCEVT3Int(ECAPx)          ((ECAPx)->CAPIE.bit.CEVT3 = CAPIE_BIT_CEVT3_ENABLE)




/******************************************************************************
 * @brief      Disable CEVT3 Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_DisableCEVT3Int(ECAPx)         ((ECAPx)->CAPIE.bit.CEVT3 = CAPIE_BIT_CEVT3_DISABLE)




/******************************************************************************
 * @brief      Enable Counter Overflow Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_EnableCounterOverflowInt(ECAPx)  ((ECAPx)->CAPIE.bit.CNTOVF = CAPIE_BIT_CNTOVF_ENABLE)




/******************************************************************************
 * @brief      Disable Counter Overflow Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_DisableCounterOverflowInt(ECAPx) ((ECAPx)->CAPIE.bit.CNTOVF = CAPIE_BIT_CNTOVF_DISABLE)




/******************************************************************************
 * @brief      Enable Counter Equal Period value Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_EnableCounterEqualPRDInt(ECAPx)  ((ECAPx)->CAPIE.bit.PRD = CAPIE_BIT_PRD_ENABLE)




/******************************************************************************
 * @brief      Disable Count Equal Period value Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_DisableCounterEqualPRDInt(ECAPx) ((ECAPx)->CAPIE.bit.PRD = CAPIE_BIT_PRD_DISABLE)




/******************************************************************************
 * @brief      Enable Counter Equal Compare value Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_EnableCounterEqualCMPInt(ECAPx)  ((ECAPx)->CAPIE.bit.CMP = CAPIE_BIT_CMP_ENABLE)




/******************************************************************************
 * @brief      Disable Counter Equal Compare value Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_DisableCounterEqualCMPInt(ECAPx) ((ECAPx)->CAPIE.bit.CMP = CAPIE_BIT_CMP_DISABLE)




/******************************************************************************
 * @brief      Enable Event Interrupt
 *
 * @param[in]  ECAPx  :  Select the ECAP module
 * @param[in]  eIntEvt:  Select the interrupt event
 *                       Please go to ECAP_IntEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_EnableInt(ECAPx,eIntEvt)       ((ECAPx)->CAPIE.all |= (0x1UL << (eIntEvt)))




/******************************************************************************
 * @brief      Disable Event Interrupt
 *
 * @param[in]  ECAPx  :  Select the ECAP module
 * @param[in]  eIntEvt:  Select the interrupt event
 *                       Please go to ECAP_IntEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_DisableInt(ECAPx,eIntEvt)      ((ECAPx)->CAPIE.all &= ~(0x1UL << (eIntEvt)))




/******************************************************************************
 * @brief      Get CEVT0 Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     0 - Indicates no event occurred
 *             1 - Indicates the first event occurred at ECAPx pin
 *
 ******************************************************************************/
#define ECAP_GetCEVT0IntFlag(ECAPx)         ((ECAPx)->CAPIF.bit.CEVT0)




/******************************************************************************
 * @brief      Get CEVT1 Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     0 - Indicates no event occurred
 *             1 - Indicates the second event occurred at ECAPx pin
 *
 ******************************************************************************/
#define ECAP_GetCEVT1IntFlag(ECAPx)         ((ECAPx)->CAPIF.bit.CEVT1)




/******************************************************************************
 * @brief      Get CEVT2 Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     0 - Indicates no event occurred
 *             1 - Indicates the third event occurred at ECAPx pin
 *
 ******************************************************************************/
#define ECAP_GetCEVT2IntFlag(ECAPx)         ((ECAPx)->CAPIF.bit.CEVT2)




/******************************************************************************
 * @brief      Get CEVT3 Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     0 - Indicates no event occurred
 *             1 - Indicates the fourth event occurred at ECAPx pin
 *
 ******************************************************************************/
#define ECAP_GetCEVT3IntFlag(ECAPx)         ((ECAPx)->CAPIF.bit.CEVT3)




/******************************************************************************
 * @brief      Get Counter Overflow Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     0 - Indicates no event occurred
 *             1 - Indicates the counter (TSCNT) has made the transition from FFFFFFFF to 00000000
 *
 ******************************************************************************/
#define ECAP_GetCounterOverflowIntFlag(ECAPx) ((ECAPx)->CAPIF.bit.CNTOVF)




/******************************************************************************
 * @brief      Get Counter Equal Period value Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     0 - Indicates no event occurred
 *             1 - Indicates the counter (TSCNT) reached the period register value (APRD) and was reset
 *
 * @note       This flag is only active in APWM mode
 *
 ******************************************************************************/
#define ECAP_GetCounterEqualPRDIntFlag(ECAPx) ((ECAPx)->CAPIF.bit.PRD)




/******************************************************************************
 * @brief      Get Counter Equal Compare value Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     0 - Indicates no event occurred
 *             1 - Indicates the counter (TSCNT) reached the compare register value (ACMP)
 *
 * @note       This flag is only active in APWM mode
 *
 ******************************************************************************/
#define ECAP_GetCounterEqualCMPIntFlag(ECAPx) ((ECAPx)->CAPIF.bit.CMP)




/******************************************************************************
 * @brief      Get Global Interrupt flag
 *
 * @param[in]  ECAPx:  Select the ECAP module.
 *
 * @return     0 - Indicates no interrupt generated
 *             1 - Indicates that an interrupt was generated
 *
 ******************************************************************************/
#define ECAP_GetGlobalIntFlag(ECAPx)        ((ECAPx)->CAPIF.bit.INT)




/******************************************************************************
 * @brief      Is Interrupt Pending
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     0 - No interrupt pending
 *             1 - Interrupt pending
 *
 ******************************************************************************/
#define ECAP_IsGlobalIntPending(ECAPx)      ((ECAPx)->CAPIF.bit.INT)




/******************************************************************************
 * @brief      Get Event Interrupt Flag
 *
 * @param[in]  ECAPx  :  Select the ECAP module
 * @param[in]  eIntEvt:  Select the interrupt event
 *                       Please go to ECAP_IntEnum for details
 *
 * @return     0 - Indicates the specified interrupt not generated
 *             1 - Indicates that the specified interrupt was generated
 *
 ******************************************************************************/
#define ECAP_GetIntFlag(ECAPx,eIntEvt)      (((ECAPx)->CAPIF.all & (0x1UL << (eIntEvt))) >> (eIntEvt))




/******************************************************************************
 * @brief      Force CEVT0 Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_ForceCEVT0Int(ECAPx)           ((ECAPx)->CAPIFRC.all = CAPIFRC_ALL_CEVT0_FORCE)




/******************************************************************************
 * @brief      Force CEVT1 Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_ForceCEVT1Int(ECAPx)           ((ECAPx)->CAPIFRC.all = CAPIFRC_ALL_CEVT1_FORCE)




/******************************************************************************
 * @brief      Force CEVT2 Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_ForceCEVT2Int(ECAPx)           ((ECAPx)->CAPIFRC.all = CAPIFRC_ALL_CEVT2_FORCE)




/******************************************************************************
 * @brief      Force CEVT3 Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_ForceCEVT3Int(ECAPx)           ((ECAPx)->CAPIFRC.all = CAPIFRC_ALL_CEVT3_FORCE)




/******************************************************************************
 * @brief      Force Counter Overflow Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_ForceCounterOverflowInt(ECAPx) ((ECAPx)->CAPIFRC.all = CAPIFRC_ALL_CNTOVF_FORCE)




/******************************************************************************
 * @brief      Force Counter Equal Period value Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_ForceCounterEqualPRDInt(ECAPx) ((ECAPx)->CAPIFRC.all = CAPIFRC_ALL_PRD_FORCE)




/******************************************************************************
 * @brief      Force Counter Equal Compare value Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_ForceCounterEqualCMPInt(ECAPx) ((ECAPx)->CAPIFRC.all = CAPIFRC_ALL_CMP_FORCE)




/******************************************************************************
 * @brief      Force Event Interrupt
 *
 * @param[in]  ECAPx  :  Select the ECAP module
 * @param[in]  eIntEvt:  Select the interrupt event
 *                       Please go to ECAP_IntEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_ForceInt(ECAPx,eIntEvt)        ((ECAPx)->CAPIFRC.all = (0x1UL << (eIntEvt)))




/******************************************************************************
 * @brief      Clear CEVT0 Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_ClearCEVT0Int(ECAPx)           ((ECAPx)->CAPIC.all = CAPIC_ALL_CEVT0_CLEAR)




/******************************************************************************
 * @brief      Clear CEVT1 Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_ClearCEVT1Int(ECAPx)           ((ECAPx)->CAPIC.all = CAPIC_ALL_CEVT1_CLEAR)




/******************************************************************************
 * @brief      Clear CEVT2 Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_ClearCEVT2Int(ECAPx)           ((ECAPx)->CAPIC.all = CAPIC_ALL_CEVT2_CLEAR)




/******************************************************************************
 * @brief      Clear CEVT3 Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_ClearCEVT3Int(ECAPx)           ((ECAPx)->CAPIC.all = CAPIC_ALL_CEVT3_CLEAR)




/******************************************************************************
 * @brief      Clear Counter Overflow Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_ClearCounterOverflowInt(ECAPx) ((ECAPx)->CAPIC.all = CAPIC_ALL_CNTOVF_CLEAR)




/******************************************************************************
 * @brief      Clear Counter Equal Period value Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_ClearCounterEqualPRDInt(ECAPx) ((ECAPx)->CAPIC.all = CAPIC_ALL_PRD_CLEAR)




/******************************************************************************
 * @brief      Clear Counter Equal Compare value Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_ClearCounterEqualCMPInt(ECAPx) ((ECAPx)->CAPIC.all = CAPIC_ALL_CMP_CLEAR)




/******************************************************************************
 * @brief      Clear Global Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_ClearGlobalInt(ECAPx)          ((ECAPx)->CAPIC.all = CAPIC_ALL_INT_CLEAR)




/******************************************************************************
 * @brief      Clear Event Interrupt
 *
 * @param[in]  ECAPx  :  Select the ECAP module
 * @param[in]  eIntEvt:  Select the interrupt event
 *                       Please go to ECAP_IntEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
#define ECAP_ClearInt(ECAPx,eIntEvt)        ((ECAPx)->CAPIC.all = (0x1UL << (eIntEvt)))




/******************************************************************************
 * @brief      Enable write access to the protected CLOCK registers
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 * 
 ******************************************************************************/
#define ECAP_WALLOW(ECAPx)                  ((ECAPx)->CAPREGKEY.all = 0x1ACCE551)




/******************************************************************************
 * @brief      Disable write access to the protected CLOCK registers
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 * 
 ******************************************************************************/
#define ECAP_WDIS(ECAPx)                    ((ECAPx)->CAPREGKEY.all = 0x0)




/**
 *  @brief ECAP Public Function Declaration
 */
void ECAP_CaptureModeInit(ECAP_REGS* ECAPx, GPIO_PinEnum ePinNum);

void ECAP_APWMModeInit(ECAP_REGS* ECAPx, GPIO_PinEnum ePinNum, uint32_t u32PwmFreq);
void ECAP_APWMSetDuty(ECAP_REGS* ECAPx, uint32_t u32PwmDuty);

void ECAP_SetInputPin(ECAP_REGS* ECAPx, GPIO_PinEnum ePinNum);

void ECAP_SetSyncFromGPIO(ECAP_REGS* ECAPx, GPIO_PinEnum ePinNum, uint8_t ePinLevel);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* ECAP_H */


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
