/******************************************************************************
 * @file     pwm.h
 * @brief    PWM driver header file.
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


#ifndef PWM_H
#define PWM_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1168.h"




/**
 *  @brief  PWM Module Index for single selection
 */
typedef enum
{
  SEL_PWM0              = 0,                /*!< PWM0            */
  SEL_PWM1              = 1,                /*!< PWM1            */
  SEL_PWM2              = 2,                /*!< PWM2            */
  SEL_PWM3              = 3,                /*!< PWM3            */
  SEL_PWM4              = 4,                /*!< PWM4            */
  SEL_PWM5              = 5,                 /*!< PWM5            */
} PWM_SelEnum;




/**
 *  @brief  PWM Module Index for muitiple selection (Can be ORed)
 */
typedef enum
{
  INC_PWM0              = 0x01UL,           /*!< PWM0            */
  INC_PWM1              = 0x02UL,           /*!< PWM1            */
  INC_PWM2              = 0x04UL,           /*!< PWM2            */
  INC_PWM3              = 0x08UL,           /*!< PWM3            */
  INC_PWM4              = 0x10UL,           /*!< PWM4            */
  INC_PWM5              = 0x20UL,           /*!< PWM5            */
} PWM_IncEnum;




/**
 *  @brief  PWM channel A or B select type
 */
typedef enum
{
  PWM_CHA               = 0,                /*!< PWM Channel A define     */
  PWM_CHB               = 1                 /*!< PWM Channel B define     */
} PWM_ChannelEnum;




/**
 *  @brief  PWM event-trigger period selection
 */
typedef enum
{
  NO_EVENT              = ETPS_BIT_SOCAPRD_GEN_SOCA_DISABLE,          /*!< Disable event counter. No event pulse will be generated */
  ON_1ST_EVENT          = ETPS_BIT_SOCAPRD_GEN_SOCA_ON_1ST_EVENT,     /*!< Generate pulse on first event      */
  ON_2ND_EVENT          = ETPS_BIT_SOCAPRD_GEN_SOCA_ON_2ND_EVENT,     /*!< Generate pulse on second event     */
  ON_3RD_EVENT          = ETPS_BIT_SOCAPRD_GEN_SOCA_ON_3RD_EVENT,     /*!< Generate pulse on third event      */
  ON_4TH_EVENT          = ETPS_BIT_SOCAPRD_GEN_SOCA_ON_4TH_EVENT,     /*!< Generate pulse on fourth event     */
  ON_5TH_EVENT          = ETPS_BIT_SOCAPRD_GEN_SOCA_ON_5TH_EVENT,     /*!< Generate pulse on fifth event      */
  ON_6TH_EVENT          = ETPS_BIT_SOCAPRD_GEN_SOCA_ON_6TH_EVENT,     /*!< Generate pulse on sixth event      */
  ON_7TH_EVENT          = ETPS_BIT_SOCAPRD_GEN_SOCA_ON_7TH_EVENT,     /*!< Generate pulse on seventh event    */
  ON_8TH_EVENT          = ETPS_BIT_SOCAPRD_GEN_SOCA_ON_8TH_EVENT,     /*!< Generate pulse on eighth event     */
  ON_9TH_EVENT          = ETPS_BIT_SOCAPRD_GEN_SOCA_ON_9TH_EVENT,     /*!< Generate pulse on ninth event      */
  ON_10TH_EVENT         = ETPS_BIT_SOCAPRD_GEN_SOCA_ON_10TH_EVENT,    /*!< Generate pulse on tenth event      */
  ON_11TH_EVENT         = ETPS_BIT_SOCAPRD_GEN_SOCA_ON_11TH_EVENT,    /*!< Generate pulse on eleventh event   */
  ON_12TH_EVENT         = ETPS_BIT_SOCAPRD_GEN_SOCA_ON_12TH_EVENT,    /*!< Generate pulse on twelfth event    */
  ON_13TH_EVENT         = ETPS_BIT_SOCAPRD_GEN_SOCA_ON_13TH_EVENT,    /*!< Generate pulse on thirteenth event */
  ON_14TH_EVENT         = ETPS_BIT_SOCAPRD_GEN_SOCA_ON_14TH_EVENT,    /*!< Generate pulse on fourteenth event */
  ON_15TH_EVENT         = ETPS_BIT_SOCAPRD_GEN_SOCA_ON_15TH_EVENT     /*!< Generate pulse on fifteenth event  */
} PWM_EventPeriodEnum;




/**
 *  @brief  PWM SOC and INT event selection
 */
typedef enum
{
  EQU_ZERO                = ETCTL_BIT_SOCASEL_TBCNT_EQU_ZERO,         /*!< Event TBCNT=0                                */
  EQU_PERIOD              = ETCTL_BIT_SOCASEL_TBCNT_EQU_PERIOD,       /*!< Event TBCNT=TBPRD                            */
  EQU_ZERO_PERIOD         = ETCTL_BIT_SOCASEL_TBCNT_EQU_ZERO_PERIOD,  /*!< Event TBCNT=0 or TBCNT=TBPRD                 */
  EQU_CMPA_UP_COUNTING    = ETCTL_BIT_SOCASEL_TBCNT_EQU_CMPA_UP,      /*!< Event TBCNT=CMPA when TBCNT is counting up   */
  EQU_CMPA_DOWN_COUNTING  = ETCTL_BIT_SOCASEL_TBCNT_EQU_CMPA_DOWN,    /*!< Event TBCNT=CMPA when TBCNT is counting down */
  EQU_CMPB_UP_COUNTING    = ETCTL_BIT_SOCASEL_TBCNT_EQU_CMPB_UP,      /*!< Event TBCNT=CMPB when TBCNT is counting up   */
  EQU_CMPB_DOWN_COUNTING  = ETCTL_BIT_SOCASEL_TBCNT_EQU_CMPB_DOWN,    /*!< Event TBCNT=CMPB when TBCNT is counting down */
  EQU_CMPC_UP_COUNTING    = ETCTL_BIT_SOCASEL_TBCNT_EQU_CMPC_UP,      /*!< Event TBCNT=CMPC when TBCNT is counting up   */
  EQU_CMPC_DOWN_COUNTING  = ETCTL_BIT_SOCASEL_TBCNT_EQU_CMPC_DOWN,    /*!< Event TBCNT=CMPC when TBCNT is counting down */
  EQU_CMPD_UP_COUNTING    = ETCTL_BIT_SOCASEL_TBCNT_EQU_CMPD_UP,      /*!< Event TBCNT=CMPD when TBCNT is counting up   */
  EQU_CMPD_DOWN_COUNTING  = ETCTL_BIT_SOCASEL_TBCNT_EQU_CMPD_DOWN,    /*!< Event TBCNT=CMPD when TBCNT is counting down */
  DCAEVT0_SOC             = ETCTL_BIT_SOCASEL_DCAEVT0_SOC,            /*!< Event DCAEVT0.SOC                            */
  DCBEVT0_SOC             = ETCTL_BIT_SOCASEL_DCBEVT0_SOC             /*!< Event DCBEVT0.SOC                            */
} PWM_EventTimingEnum;




/**
 *  @brief  PWM output A and B action after trip event occurs
 */
typedef enum
{
  /* Action on PWM output when digital compare A/B event 1 occur and TBCNT is counting down */
  DCEVT1D_TRIP_AS_TRI_STATE       = TZACTL_ALL_DCAEVT1D_TRI_STATE,
  DCEVT1D_TRIP_AS_LOW             = TZACTL_ALL_DCAEVT1D_SET_HIGH,
  DCEVT1D_TRIP_AS_HIGH            = TZACTL_ALL_DCAEVT1D_SET_LOW,
  DCEVT1D_TRIP_AS_TOGGLE          = TZACTL_ALL_DCAEVT1D_TOGGLE,
  DCEVT1D_TRIP_DO_NOTHING         = TZACTL_ALL_DCAEVT1D_DO_NOTHING,
  
  /* Action on PWM output when digital compare A/B event 1 occur and TBCNT is counting up */
  DCEVT1U_TRIP_AS_TRI_STATE       = TZACTL_ALL_DCAEVT1U_TRI_STATE,
  DCEVT1U_TRIP_AS_LOW             = TZACTL_ALL_DCAEVT1U_SET_HIGH,
  DCEVT1U_TRIP_AS_HIGH            = TZACTL_ALL_DCAEVT1U_SET_LOW,
  DCEVT1U_TRIP_AS_TOGGLE          = TZACTL_ALL_DCAEVT1U_TOGGLE,
  DCEVT1U_TRIP_DO_NOTHING         = TZACTL_ALL_DCAEVT1U_DO_NOTHING,
  
  /* Action on PWM output when digital compare A/B event 0 occur and TBCNT is counting down */
  DCEVT0D_TRIP_AS_TRI_STATE       = TZACTL_ALL_DCAEVT0D_TRI_STATE,
  DCEVT0D_TRIP_AS_LOW             = TZACTL_ALL_DCAEVT0D_SET_HIGH,
  DCEVT0D_TRIP_AS_HIGH            = TZACTL_ALL_DCAEVT0D_SET_LOW,
  DCEVT0D_TRIP_AS_TOGGLE          = TZACTL_ALL_DCAEVT0D_TOGGLE,
  DCEVT0D_TRIP_DO_NOTHING         = TZACTL_ALL_DCAEVT0D_DO_NOTHING,
  
  /* Action on PWM output when digital compare A/B event 0 occur and TBCNT is counting up */
  DCEVT0U_TRIP_AS_TRI_STATE       = TZACTL_ALL_DCAEVT0U_TRI_STATE,
  DCEVT0U_TRIP_AS_LOW             = TZACTL_ALL_DCAEVT0U_SET_HIGH,
  DCEVT0U_TRIP_AS_HIGH            = TZACTL_ALL_DCAEVT0U_SET_LOW,
  DCEVT0U_TRIP_AS_TOGGLE          = TZACTL_ALL_DCAEVT0U_TOGGLE,
  DCEVT0U_TRIP_DO_NOTHING         = TZACTL_ALL_DCAEVT0U_DO_NOTHING,
  
  /* Action on PWM output when a trip event occur and TBCNT is counting down */
  TZD_TRIP_AS_TRI_STATE           = TZACTL_ALL_TZAD_TRI_STATE,
  TZD_TRIP_AS_LOW                 = TZACTL_ALL_TZAD_SET_HIGH,
  TZD_TRIP_AS_HIGH                = TZACTL_ALL_TZAD_SET_LOW,
  TZD_TRIP_AS_TOGGLE              = TZACTL_ALL_TZAD_TOGGLE,
  TZD_TRIP_DO_NOTHING             = TZACTL_ALL_TZAD_DO_NOTHING,
  
  /* Action on PWM output when a trip event occur and TBCNT is counting up */
  TZU_TRIP_AS_TRI_STATE           = TZACTL_ALL_TZAU_TRI_STATE,
  TZU_TRIP_AS_LOW                 = TZACTL_ALL_TZAU_SET_HIGH,
  TZU_TRIP_AS_HIGH                = TZACTL_ALL_TZAU_SET_LOW,
  TZU_TRIP_AS_TOGGLE              = TZACTL_ALL_TZAU_TOGGLE,
  TZU_TRIP_DO_NOTHING             = TZACTL_ALL_TZAU_DO_NOTHING
} PWM_TripActionEnum;




/**
 *  @brief  PWM Action-Qualifier output when event occurs
 */
typedef enum
{
  /* Action on PWM output when T1 event occur and TBCNT is counting down */
  T1D_DO_NOTHING        = AQCTLA_ALL_T1D_DO_NOTHING,
  T1D_SET_LOW           = AQCTLA_ALL_T1D_SET_LOW,
  T1D_SET_HIGH          = AQCTLA_ALL_T1D_SET_HIGH,
  T1D_TOGGLE            = AQCTLA_ALL_T1D_TOGGLE,
  
  /* Action on PWM output when T1 event occur and TBCNT is counting up */
  T1U_DO_NOTHING        = AQCTLA_ALL_T1U_DO_NOTHING,
  T1U_SET_LOW           = AQCTLA_ALL_T1U_SET_LOW,
  T1U_SET_HIGH          = AQCTLA_ALL_T1U_SET_HIGH,
  T1U_TOGGLE            = AQCTLA_ALL_T1U_TOGGLE,
  
  /* Action on PWM output when T0 event occur and TBCNT is counting down */
  T0D_DO_NOTHING        = AQCTLA_ALL_T0D_DO_NOTHING,
  T0D_SET_LOW           = AQCTLA_ALL_T0D_SET_LOW,
  T0D_SET_HIGH          = AQCTLA_ALL_T0D_SET_HIGH,
  T0D_TOGGLE            = AQCTLA_ALL_T0D_TOGGLE,
  
  /* Action on PWM output when T1 event occur and TBCNT is counting up */
  T0U_DO_NOTHING        = AQCTLA_ALL_T0U_DO_NOTHING,
  T0U_SET_LOW           = AQCTLA_ALL_T0U_SET_LOW,
  T0U_SET_HIGH          = AQCTLA_ALL_T0U_SET_HIGH,
  T0U_TOGGLE            = AQCTLA_ALL_T0U_TOGGLE,
  
  /* Action on PWM output when TBCNT = CMPB and TBCNT is counting down */
  CBD_DO_NOTHING        = AQCTLA_ALL_CBD_DO_NOTHING,
  CBD_SET_LOW           = AQCTLA_ALL_CBD_SET_LOW,
  CBD_SET_HIGH          = AQCTLA_ALL_CBD_SET_HIGH,
  CBD_TOGGLE            = AQCTLA_ALL_CBD_TOGGLE,
  
  /* Action on PWM output when TBCNT = CMPB and TBCNT is counting up */
  CBU_DO_NOTHING        = AQCTLA_ALL_CBU_DO_NOTHING,
  CBU_SET_LOW           = AQCTLA_ALL_CBU_SET_LOW,
  CBU_SET_HIGH          = AQCTLA_ALL_CBU_SET_HIGH,
  CBU_TOGGLE            = AQCTLA_ALL_CBU_TOGGLE,
  
  /* Action on PWM output when TBCNT = CMPA and TBCNT is counting down */
  CAD_DO_NOTHING        = AQCTLA_ALL_CAD_DO_NOTHING,
  CAD_SET_LOW           = AQCTLA_ALL_CAD_SET_LOW,
  CAD_SET_HIGH          = AQCTLA_ALL_CAD_SET_HIGH,
  CAD_TOGGLE            = AQCTLA_ALL_CAD_TOGGLE,
  
  /* Action on PWM output when TBCNT = CMPA and TBCNT is counting up */
  CAU_DO_NOTHING        = AQCTLA_ALL_CAU_DO_NOTHING,
  CAU_SET_LOW           = AQCTLA_ALL_CAU_SET_LOW,
  CAU_SET_HIGH          = AQCTLA_ALL_CAU_SET_HIGH,
  CAU_TOGGLE            = AQCTLA_ALL_CAU_TOGGLE,
  
  /* Action on PWM output when TBCNT = TBPRD */
  PRD_DO_NOTHING        = AQCTLA_ALL_PRD_DO_NOTHING,
  PRD_SET_LOW           = AQCTLA_ALL_PRD_SET_LOW,
  PRD_SET_HIGH          = AQCTLA_ALL_PRD_SET_HIGH,
  PRD_TOGGLE            = AQCTLA_ALL_PRD_TOGGLE,
  
  /* Action on PWM output when TBCNT = Zero */
  ZRO_DO_NOTHING        = AQCTLA_ALL_ZRO_DO_NOTHING,
  ZRO_SET_LOW           = AQCTLA_ALL_ZRO_SET_LOW,
  ZRO_SET_HIGH          = AQCTLA_ALL_ZRO_SET_HIGH,
  ZRO_TOGGLE            = AQCTLA_ALL_ZRO_TOGGLE
} PWM_ActionQualifierEnum;




/**
 *  @brief  PWM CMPA/B/C/D and AQCTLA/B reload timing selection
 */
typedef enum
{
  ON_ZERO               = CMPCTL_BIT_CMPALOAD_LOAD_ON_ZERO,               /*!< Load on TBCNT=Zero                            */
  ON_PERIOD             = CMPCTL_BIT_CMPALOAD_LOAD_ON_PERIOD,             /*!< Load on TBCNT=TBPRD                           */
  ON_ZERO_PERIOD        = CMPCTL_BIT_CMPALOAD_LOAD_ON_ZERO_PERIOD,        /*!< Load on either TBCNT=Zero or TBCNT=TBPRD      */
  ON_SYNC               = CMPCTL_BIT_CMPALOAD_LOAD_ON_SYNC,               /*!< Load on SYNC event                            */
  ON_SYNC_ZERO          = CMPCTL_BIT_CMPALOAD_LOAD_ON_SYNC_ZERO,          /*!< Load on SYNC event or TBCNT=TBPRD             */
  ON_SYNC_ZERO_PERIOD   = CMPCTL_BIT_CMPALOAD_LOAD_ON_SYNC_ZERO_PERIOD,   /*!< Load on SYNC event, TBCNT=Zero or TBCNT=TBPRD */
  ON_IMMEDIATE          = CMPCTL_BIT_CMPALOAD_LOAD_IMMEDIATE              /*!< Load on immediately                           */
} PWM_LoadTimingEnum;




/**
 *  @brief  PWM T0 and T1 event selection
 */
typedef enum
{
  TxEVENT_DCAEVT0       = AQCTL_BIT_T0SEL_DCAEVT0,    /*!< DCAEVT0 event */
  TxEVENT_DCAEVT1       = AQCTL_BIT_T0SEL_DCAEVT1,    /*!< DCAEVT1 event */
  TxEVENT_DCBEVT0       = AQCTL_BIT_T0SEL_DCBEVT0,    /*!< DCBEVT0 event */
  TxEVENT_DCBEVT1       = AQCTL_BIT_T0SEL_DCBEVT1,    /*!< DCBEVT1 event */
  TxEVENT_TZ0           = AQCTL_BIT_T0SEL_TZ0,        /*!< TZ0 event     */
  TxEVENT_TZ1           = AQCTL_BIT_T0SEL_TZ1,        /*!< TZ1 event     */
  TxEVENT_TZ2           = AQCTL_BIT_T0SEL_TZ2,        /*!< TZ2 event     */
  TxEVENT_TZ3           = AQCTL_BIT_T0SEL_TZ3,        /*!< TZ3 event     */
  TxEVENT_TZ4           = AQCTL_BIT_T0SEL_TZ4,        /*!< TZ4 event     */
  TxEVENT_SYNCI         = AQCTL_BIT_T0SEL_SYNCI       /*!< SYNCI event   */
} PWM_TxEventEnum;




/**
 *  @brief  PWM clock count mode selection
 */
typedef enum
{
  COUNT_DOWN            = TBCTL_BIT_CNTMODE_COUNT_DOWN,     /*!< Down-count      */
  COUNT_UP              = TBCTL_BIT_CNTMODE_COUNT_UP,       /*!< Up-count        */
  COUNT_UP_DOWN         = TBCTL_BIT_CNTMODE_COUNT_UP_DOWN,  /*!< Up-down-count   */
  COUNT_STOP            = TBCTL_BIT_CNTMODE_COUNT_FREEZE    /*!< Stop and freeze */
} PWM_CounterModeEnum;




/**
 *  @brief  PWM clock divider binary part selection
 */
typedef enum
{
  PWM_CLKDIV0_1         = TBCTL_BIT_TBDIVBIN_1,             /*!< /1 (default on reset) */
  PWM_CLKDIV0_2         = TBCTL_BIT_TBDIVBIN_2,             /*!< /2                    */
  PWM_CLKDIV0_4         = TBCTL_BIT_TBDIVBIN_4,             /*!< /4                    */
  PWM_CLKDIV0_8         = TBCTL_BIT_TBDIVBIN_8,             /*!< /8                    */
  PWM_CLKDIV0_16        = TBCTL_BIT_TBDIVBIN_16,            /*!< /16                   */
  PWM_CLKDIV0_32        = TBCTL_BIT_TBDIVBIN_32,            /*!< /32                   */
  PWM_CLKDIV0_64        = TBCTL_BIT_TBDIVBIN_64,            /*!< /64                   */
  PWM_CLKDIV0_128       = TBCTL_BIT_TBDIVBIN_128            /*!< /128                  */
} PWM_ClockDiv0Enum;




/**
 *  @brief  PWM clock divider linear part selection
 */
typedef enum
{
  PWM_CLKDIV1_1         = TBCTL_BIT_TBDIVLIN_1,             /*!< /1 (default on reset) */
  PWM_CLKDIV1_2         = TBCTL_BIT_TBDIVLIN_2,             /*!< /2                    */
  PWM_CLKDIV1_3         = TBCTL_BIT_TBDIVLIN_3,             /*!< /3                    */
  PWM_CLKDIV1_4         = TBCTL_BIT_TBDIVLIN_4,             /*!< /4                    */
  PWM_CLKDIV1_5         = TBCTL_BIT_TBDIVLIN_5,             /*!< /5                    */
  PWM_CLKDIV1_6         = TBCTL_BIT_TBDIVLIN_6,             /*!< /6                    */
  PWM_CLKDIV1_7         = TBCTL_BIT_TBDIVLIN_7,             /*!< /7                    */
  PWM_CLKDIV1_8         = TBCTL_BIT_TBDIVLIN_8              /*!< /8                    */
} PWM_ClockDiv1Enum;




/**
 *  @brief  PWM trip-zone event selection
 */
typedef enum
{
  TRIP_EVENT_TZ0        = TZSEL_ALL_TZ0OST_ENABLE,          /*!< TZ0              */
  TRIP_EVENT_TZ1        = TZSEL_ALL_TZ1OST_ENABLE,          /*!< TZ1              */
  TRIP_EVENT_TZ2        = TZSEL_ALL_TZ2OST_ENABLE,          /*!< TZ2              */
  TRIP_EVENT_TZ3        = TZSEL_ALL_TZ3OST_ENABLE,          /*!< TZ3              */
  TRIP_EVENT_TZ4        = TZSEL_ALL_TZ4OST_ENABLE,          /*!< TZ4              */
  TRIP_EVENT_CLKERR     = TZSEL_ALL_CLKERROST_ENABLE,       /*!< CLKERR           */
  TRIP_EVENT_DCAEVT     = TZSEL_ALL_DCAEVT0_ONESHOT_ENABLE, /*!< DCAEVT0 for oneshot and DCAEVT1 for CBC */
  TRIP_EVENT_DCBEVT     = TZSEL_ALL_DCBEVT0_ONESHOT_ENABLE, /*!< DCBEVT0 for oneshot and DCBEVT1 for CBC */
  TRIP_EVENT_DEBUG      = TZSEL_ALL_DBGOST_ENABLE           /*!< DEBUG event       */
} PWM_TripEventEnum;




/**
 *  @brief  PWM Trip-zone output select
 */
typedef enum
{
  TRIP_OUTPUT_DISABLE         = TZSEL_ALL_OSTOUT_DISABLE,        /*!< Disable                             */
  TRIP_OUTPUT_ASYNC           = TZSEL_ALL_OSTOUT_ASYNC,          /*!< Async (Used only for debug purpose) */
  TRIP_OUTPUT_LATCH           = TZSEL_ALL_OSTOUT_LATCH,          /*!< Latch                               */
  TRIP_OUTPUT_ASYNC_OR_LATCH  = TZSEL_ALL_OSTOUT_ASYNC_OR_LATCH  /*!< Async or Latch                      */
} PWM_TripOutputEnum;




/**
 *  @brief  PWM DC trip event selection
 */
typedef enum
{
  DC_TRIP_TZ0           = DCALTRIPSEL_ALL_TZ0_ENABLE,           /*!< TZ0             */
  DC_TRIP_TZ1           = DCALTRIPSEL_ALL_TZ1_ENABLE,           /*!< TZ1             */
  DC_TRIP_TZ2           = DCALTRIPSEL_ALL_TZ2_ENABLE,           /*!< TZ2             */
  DC_TRIP_TZ3           = DCALTRIPSEL_ALL_TZ3_ENABLE,           /*!< TZ3             */
  DC_TRIP_TZ4           = DCALTRIPSEL_ALL_TZ4_ENABLE,           /*!< TZ4             */
  DC_TRIP_EPWRTZ0       = DCALTRIPSEL_ALL_EPWRTZ0_ENABLE,       /*!< EPWRTZ0         */
  DC_TRIP_EPWRTZ1       = DCALTRIPSEL_ALL_EPWRTZ1_ENABLE,       /*!< EPWRTZ1         */
  DC_TRIP_ADCPPU0TZ     = DCALTRIPSEL_ALL_ADCPPU0TZ_ENABLE,     /*!< ADCPPU0TZ       */
  DC_TRIP_ADCPPU1TZ     = DCALTRIPSEL_ALL_ADCPPU1TZ_ENABLE,     /*!< ADCPPU1TZ       */
  DC_TRIP_ADCPPU2TZ     = DCALTRIPSEL_ALL_ADCPPU2TZ_ENABLE,     /*!< ADCPPU2TZ       */
  DC_TRIP_ADCPPU3TZ     = DCALTRIPSEL_ALL_ADCPPU3TZ_ENABLE,     /*!< ADCPPU3TZ       */
  DC_TRIP_ADCPPU4TZ     = DCALTRIPSEL_ALL_ADCPPU4TZ_ENABLE,     /*!< ADCPPU4TZ       */
  DC_TRIP_ADCPPU5TZ     = DCALTRIPSEL_ALL_ADCPPU5TZ_ENABLE,     /*!< ADCPPU5TZ       */
  DC_TRIP_COMP0L        = DCALTRIPSEL_ALL_COMP0L_ENABLE,        /*!< COMP0L          */
  DC_TRIP_COMP0H        = DCALTRIPSEL_ALL_COMP0H_ENABLE,        /*!< COMP0H          */
  DC_TRIP_COMP1L        = DCALTRIPSEL_ALL_COMP1L_ENABLE,        /*!< COMP1L          */
  DC_TRIP_COMP1H        = DCALTRIPSEL_ALL_COMP1H_ENABLE,        /*!< COMP1H          */
  DC_TRIP_COMP2L        = DCALTRIPSEL_ALL_COMP2L_ENABLE,        /*!< COMP2L          */
  DC_TRIP_COMP2H        = DCALTRIPSEL_ALL_COMP2H_ENABLE,        /*!< COMP2H          */
  DC_TRIP_COMP3L        = DCALTRIPSEL_ALL_COMP3L_ENABLE,        /*!< COMP3L          */
  DC_TRIP_COMP3H        = DCALTRIPSEL_ALL_COMP3H_ENABLE,        /*!< COMP3H          */
  DC_TRIP_COMP4L        = DCALTRIPSEL_ALL_COMP4L_ENABLE,        /*!< COMP4L          */
  DC_TRIP_COMP4H        = DCALTRIPSEL_ALL_COMP4H_ENABLE         /*!< COMP4H          */
} PWM_DCTripEventEnum;




/**
 *  @brief  PWM Raw DCA/B event selection
 */
typedef enum
{
  DCEVT_DISABLE         = TZDCSEL_BIT_DCAEVT0_DISABLE,              /*!< Disable, do not generate event   */
  DCH_X_DCL_LOW         = TZDCSEL_BIT_DCAEVT0_DCAH_X_DCAL_LOW,      /*!< DCAH=dont'care,  DCAL=low        */
  DCH_X_DCL_HIGH        = TZDCSEL_BIT_DCAEVT0_DCAH_X_DCAL_HIGH,     /*!< DCAH=dont'care,  DCAL=high       */
  DCH_LOW_DCL_X         = TZDCSEL_BIT_DCAEVT0_DCAH_LOW_DCAL_X,      /*!< DCAH=low,        DCAL=dont'care  */
  DCH_HIGH_DCL_X        = TZDCSEL_BIT_DCAEVT0_DCAH_HIGH_DCAL_X,     /*!< DCAH=high,       DCAL=dont'care  */
  DCH_HIGH_DCL_LOW      = TZDCSEL_BIT_DCAEVT0_DCAH_HIGH_DCAL_LOW,   /*!< DCAH=high,       DCAL=low        */
  DCH_LOW_DCL_HIGH      = TZDCSEL_BIT_DCAEVT0_DCAH_LOW_DCAL_HIGH,   /*!< DCAH=low,        DCAL=high       */
  DCH_HIGH_DCL_HIGH     = TZDCSEL_BIT_DCAEVT0_DCAH_HIGH_DCAL_HIGH   /*!< DCAH=high,       DCAL=high       */
} PWM_RawDCEventEnum;




/**
 *  @brief  PWM final DCA/B event selection
 */
typedef enum
{
  DCEVT_RAW             = DCACTL_BIT_EVT0SRCSEL_DCAEVT0,      /*!< From Raw DC event      */
  DCEVT_FILTERED        = DCACTL_BIT_EVT0SRCSEL_DCEVTFILT,    /*!< From Filtered DC event */
} PWM_DCEventEnum;




/**
 *  @brief  PWM DC filter input select
 */
typedef enum
{
  DCF_FROM_RAW_DCAEVT0  = DCFCTL_BIT_SRCSEL_DCAEVT0,          /*!< From Raw DCAEVT0       */
  DCF_FROM_RAW_DCAEVT1  = DCFCTL_BIT_SRCSEL_DCAEVT1,          /*!< From Raw DCAEVT1       */
  DCF_FROM_RAW_DCBEVT0  = DCFCTL_BIT_SRCSEL_DCBEVT0,          /*!< From Raw DCBEVT0       */
  DCF_FROM_RAW_DCBEVT1  = DCFCTL_BIT_SRCSEL_DCBEVT1,          /*!< From Raw DCBEVT1       */
} PWM_DCFilterInputEnum;




/**
 *  @brief  PWM DC filter alignment select
 */
typedef enum
{
  DCF_ALIGN_ON_ZERO         = DCFCTL_BIT_PULSESEL_ALIGN_ON_ZERO,
  DCF_ALIGN_ON_PERIOD       = DCFCTL_BIT_PULSESEL_ALIGN_ON_PERIOD,
  DCF_ALIGN_ON_ZERO_PERIOD  = DCFCTL_BIT_PULSESEL_ALIGN_ON_ZERO_PERIOD
} PWM_DCFilterAlignEnum;




/**
 *  @brief  PWM Sync Event selection
 */
typedef enum
{
  SYNC_SYNCI_AND_FRCSYNC  = TBCTL_BIT_SYNCOSEL_SYNCI_AND_FRCSYNC,   /*!< SYNCI or TBCTL.bit.FRCSYNC   */
  SYNC_TBCNT_EQU_ZERO     = TBCTL_BIT_SYNCOSEL_TBCNT_EQU_ZERO,      /*!< TBCNT=0                      */
  SYNC_TBCNT_EQU_TBPRD    = TBCTL_BIT_SYNCOSEL_TBCNT_EQU_TBPRD,     /*!< TBCNT=TBPRD                  */
  SYNC_TBCNT_EQU_CMPA     = TBCTL_BIT_SYNCOSEL_TBCNT_EQU_CMPA,      /*!< TBCNT=CMPA                   */
  SYNC_TBCNT_EQU_CMPB     = TBCTL_BIT_SYNCOSEL_TBCNT_EQU_CMPB,      /*!< TBCNT=CMPB                   */
  SYNC_TBCNT_EQU_CMPC     = TBCTL_BIT_SYNCOSEL_TBCNT_EQU_CMPC,      /*!< TBCNT=CMPC                   */
  SYNC_TBCNT_EQU_CMPD     = TBCTL_BIT_SYNCOSEL_TBCNT_EQU_CMPD,      /*!< TBCNT=CMPD                   */
  SYNC_DISABLE            = TBCTL_BIT_SYNCOSEL_DISABLE              /*!< Disable                      */
} PWM_SyncEventEnum;




/******************************************************************************
 * @brief      Enable PWMx register link
 *
 * @param[in]  PWMx      :  Select the PWM module (PWM0~PWM5)
 * @param[in]  ePWMLinked:  Select the target PWM to be linked
 *                          Please goto PWM_SelEnum for the selection
 *
 * @return     none
 * 
 ******************************************************************************/
#define PWM_LinkTBPRD(PWMx,ePWMLinked)      ((PWMx)->PWMLINK.bit.TBPRD   = (ePWMLinked))
#define PWM_LinkCMPA(PWMx,ePWMLinked)       ((PWMx)->PWMLINK.bit.CMPA    = (ePWMLinked))
#define PWM_LinkCMPB(PWMx,ePWMLinked)       ((PWMx)->PWMLINK.bit.CMPB    = (ePWMLinked))
#define PWM_LinkCMPC(PWMx,ePWMLinked)       ((PWMx)->PWMLINK.bit.CMPC    = (ePWMLinked))
#define PWM_LinkCMPD(PWMx,ePWMLinked)       ((PWMx)->PWMLINK.bit.CMPD    = (ePWMLinked))
#define PWM_LinkDBRED(PWMx,ePWMLinked)      ((PWMx)->PWMLINK.bit.DBRED   = (ePWMLinked))
#define PWM_LinkDBFED(PWMx,ePWMLinked)      ((PWMx)->PWMLINK.bit.DBFED   = (ePWMLinked))
#define PWM_LinkGLDCTL1(PWMx,ePWMLinked)    ((PWMx)->PWMLINK.bit.GLDCTL1 = (ePWMLinked))




/******************************************************************************
 * @brief      Disable PWMx register link
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 * 
 ******************************************************************************/
#define PWM_UnlinkTBPRD(PWMx)               ((PWMx)->PWMLINK.bit.TBPRD   = 0xF)
#define PWM_UnlinkCMPA(PWMx)                ((PWMx)->PWMLINK.bit.CMPA    = 0xF)
#define PWM_UnlinkCMPB(PWMx)                ((PWMx)->PWMLINK.bit.CMPB    = 0xF)
#define PWM_UnlinkCMPC(PWMx)                ((PWMx)->PWMLINK.bit.CMPC    = 0xF)
#define PWM_UnlinkCMPD(PWMx)                ((PWMx)->PWMLINK.bit.CMPD    = 0xF)
#define PWM_UnlinkDBRED(PWMx)               ((PWMx)->PWMLINK.bit.DBRED   = 0xF)
#define PWM_UnlinkDBFED(PWMx)               ((PWMx)->PWMLINK.bit.DBFED   = 0xF)
#define PWM_UnlinkGLDCTL1(PWMx)             ((PWMx)->PWMLINK.bit.GLDCTL1 = 0xF)




/******************************************************************************
 * @brief      Configure PWMx Time-Base clock divider
 *
 * @param[in]  PWMx :  Select the PWM module (PWM0~PWM5)
 * @param[in]  eDiv0:  PWMx clock divider binary part
 *                     Please goto PWM_ClockDiv0Enum for selection
 * @param[in]  eDiv1:  PWMx clock divider lineary part
 *                     Please goto PWM_ClockDiv1Enum for selection
 *
 * @return     none
 *
 * @note       PWM Time-Base clock divider = 2^eDiv0 * eDiv1
 *
 * @example    PWM_SetClockDiv(PWM0, PWM_CLKDIV0_2,  PWM_CLKDIV1_1);
 *             PWM_SetClockDiv(PWM1, PWM_CLKDIV0_32, PWM_CLKDIV1_3);
 * 
 ******************************************************************************/
__STATIC_INLINE void PWM_SetClockDiv(PWM_REGS* PWMx, PWM_ClockDiv0Enum eDiv0, PWM_ClockDiv1Enum eDiv1)
{
  PWMx->TBCTL.bit.TBDIVBIN = (eDiv0);
  PWMx->TBCTL.bit.TBDIVLIN = (eDiv1);
}




/******************************************************************************
 * @brief      Get PWM Time-Base clock divider value
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     Actual PWM Time-Base clock divider value
 *
 ******************************************************************************/
#define PWM_GetClockDiv(PWMx)               ((0x1UL << ((PWMx)->TBCTL.bit.TBDIVBIN)) * ((PWMx)->TBCTL.bit.TBDIVLIN + 1))




/******************************************************************************
 * @brief      Get current PWM counter value
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     PWM current counter (16 bit)
 *
 ******************************************************************************/
#define PWM_GetCounterValue(PWMx)           ((PWMx)->TBCNT.all)




/******************************************************************************
 * @brief      Get PWM period value
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     PWM period (16 bit)
 *
 ******************************************************************************/
#define PWM_GetPeriod(PWMx)                 ((PWMx)->TBPRDA.all)
#define PWM_GetPRD(PWMx)                    ((PWMx)->TBPRDA.all)




/******************************************************************************
 * @brief      Set PWM period value
 *
 * @param[in]  PWMx  :  Select the PWM module (PWM0~PWM5)
 * @param[in]  u16Val:  PWM reload counter (16 bit)
 *
 * @return     none
 *
 * @detail     PWM carrier frequency will be devided by period value
 *             If PWM is up counting or down counting,
 *                PWM frequency = PWM clock/Period
 *             if PWM is up counting and down counting,
 *                PWM frequency = PWM clock/Period/2
 *             Thus user may design PWM frequency by Period and PWM clock frequency
 *
 ******************************************************************************/
#define PWM_SetPeriod(PWMx,u16Val)          ((PWMx)->TBPRD.all = (u16Val))
#define PWM_SetPRD(PWMx,u16Val)             ((PWMx)->TBPRD.all = (u16Val))




/******************************************************************************
 * @brief      Set PWM synchronization reload value
 *             PWM counter will equal TBPHS after synchronization event
 *
 * @param[in]  PWMx  :  Select the PWM module (PWM0~PWM5)
 * @param[in]  u16Val:  PWM reload value
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_SetSyncReloadValue(PWMx,u16Val) ((PWMx)->TBPHS.all = (u16Val))




/******************************************************************************
 * @brief      Enable PWM synchronization
 *             PWM counter will equal TBPHS upon synchronization event
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_EnableSync(PWMx)                ((PWMx)->TBCTL.bit.PHSEN = TBCTL_BIT_PHSEN_ENABLE)




/******************************************************************************
 * @brief      Disable PWM synchronization
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_DisableSync(PWMx)               ((PWMx)->TBCTL.bit.PHSEN = TBCTL_BIT_PHSEN_DISABLE)




/******************************************************************************
 * @brief      Select PWMSYNCO signal
 *
 * @param[in]  PWMx  :  Select the PWM module (PWM0~PWM5)
 * @param[in]  eSYNCO:  Select the PWM SYNC event
 *                      Please goto PWM_SyncEventEnum for the selection
 *
 * @return     none
 *
 * @example    PWM_SetSyncOutEvent(PWM0, SYNC_TBCNT_EQU_ZERO);
 *
 ******************************************************************************/
#define PWM_SetSyncOutEvent(PWMx,eSYNC)     ((PWMx)->TBCTL.bit.SYNCOSEL = (eSYNC))




/******************************************************************************
 * @brief      Select PWM counter direction after synchronization
 *             (Only valid in up-down-count mode)
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 * @param[in]  eDir:  Select the counter direction
 *                    Valid option is COUNT_UP(1) or COUNT_DOWN(0)
 *
 * @return     none
 *
 * @example    PWM_SetCounterDirAfterSync(PWM0, COUNT_UP);
 *             PWM_SetCounterDirAfterSync(PWM0, COUNT_DOWN);
 *
 ******************************************************************************/
#define PWM_SetCounterDirAfterSync(PWMx,eDir) ((PWMx)->TBCTL.bit.PHSDIR = (eDir))




/******************************************************************************
 * @brief      PWM counter will not increase when in MCU debug mode
 *             Note: Please remember to configure CBC trip when debug
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_StopCounterInDebug(PWMx)        ((PWMx)->TBCTL.bit.DBGRUN = TBCTL_BIT_DBGRUN_STOP_AFTER_CYCLE)




/******************************************************************************
 * @brief      Configure PWM counter counting mode (4 modes include stop)
 *
 * @param[in]  PWMx :  Select the PWM module (PWM0~PWM5)
 * @param[in]  eMode:  Specifies the clock counting mode
 *                     Please goto PWM_CounterModeEnum for selection
 *                      - \ref COUNT_UP
 *                      - \ref COUNT_DOWN
 *                      - \ref COUNT_UP_DOWN
 *                      - \ref COUNT_STOP
 *
 * @return     none
 *
 * @example    PWM_SetCounterMode(PWM0, COUNT_UP_DOWN);
 *             PWM_SetCounterMode(PWM1, COUNT_STOP);
 * 
 ******************************************************************************/
#define PWM_SetCounterMode(PWMx,eMode)      ((PWMx)->TBCTL.bit.CNTMODE = (eMode))




/******************************************************************************
 * @brief      Run PWM counter
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_RunCounter(PWMx)                ((PWMx)->TBCTL.all |= TBCTL_ALL_CNTRUN_COUNT_RUN)




/******************************************************************************
 * @brief      Stop PWM counter
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_StopCounter(PWMx)               ((PWMx)->TBCTL.bit.CNTRUN = TBCTL_BIT_CNTRUN_COUNT_STOP)




/******************************************************************************
 * @brief      Get the counting direction of PWM counter
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     0 - PWM counter is counting down
 *             1 - PWM counter is counting up
 *
 ******************************************************************************/
#define PWM_GetCountingDirection(PWMx)      ((PWMx)->TBSTS.bit.CNTDIR)




/******************************************************************************
 * @brief      Check if PWM counter is counting up
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     0 - PWM counter is counting down
 *             1 - PWM counter is counting up
 *
 ******************************************************************************/
#define PWM_IsCountingUp(PWMx)              ((((PWMx)->TBSTS.all & TBSTS_ALL_CNTDIR_Msk) == TBSTS_ALL_CNTDIR_COUNTING_UP)? (1):(0))




/******************************************************************************
 * @brief      Check if PWM counter is counting down
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     0 - PWM counter is counting up
 *             1 - PWM counter is counting down
 *
 ******************************************************************************/
#define PWM_IsCountingDown(PWMx)            ((((PWMx)->TBSTS.all & TBSTS_ALL_CNTDIR_Msk) == TBSTS_ALL_CNTDIR_COUNTING_DOWN)? (1):(0))




/******************************************************************************
 * @brief      Set PWMx CMPA value
 *
 * @param[in]  PWMx  :  Select the PWM module (PWM0~PWM5)
 * @param[in]  u16Val:  PWM comparator A value(16 bit)
 *                      It should be a value from 0~TBPRD
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_SetCMPA(PWMx,u16Val)            ((PWMx)->CMPA.all = (u16Val))




/******************************************************************************
 * @brief      Set PWMx CMPB value
 *
 * @param[in]  PWMx  :  Select the PWM module (PWM0~PWM5)
 * @param[in]  u16Val:  PWM comparator B value(16 bit)
 *                      It should be a value from 0~TBPRD
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_SetCMPB(PWMx,u16Val)            ((PWMx)->CMPB.all = (u16Val))




/******************************************************************************
 * @brief      Set PWMx CMPC value
 *
 * @param[in]  PWMx  :  Select the PWM module (PWM0~PWM5)
 * @param[in]  u16Val:  PWM comparator C value(16 bit)
 *                      It should be a value from 0~TBPRD
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_SetCMPC(PWMx,u16Val)            ((PWMx)->CMPC.all = (u16Val))




/******************************************************************************
 * @brief      Set PWMx CMPD value
 *
 * @param[in]  PWMx  :  Select the PWM module (PWM0~PWM5)
 * @param[in]  u16Val:  PWM comparator D value(16 bit)
 *                      It should be a value from 0~TBPRD
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_SetCMPD(PWMx,u16Val)            ((PWMx)->CMPD.all = (u16Val))




/******************************************************************************
 * @brief      Get PWMx CMPx value
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     CMPx active value (16 bit)
 *
 ******************************************************************************/
#define PWM_GetCMPA(PWMx)                   ((PWMx)->CMPAA.all)
#define PWM_GetCMPB(PWMx)                   ((PWMx)->CMPBA.all)
#define PWM_GetCMPC(PWMx)                   ((PWMx)->CMPCA.all)
#define PWM_GetCMPD(PWMx)                   ((PWMx)->CMPDA.all)




/******************************************************************************
 * @brief      Configure CMPA/CMPB/CMPC/CMPD load mode
 *
 * @param[in]  PWMx :  Select the PWM module (PWM0~PWM5)
 * @param[in]  eMode:  PWM Comparator value load mode
 *                     Please goto PWM_LoadTimingEnum for selection
 *
 * @return     none
 *
 * @example    PWM_SetCMPALoadTiming(PWM0, ON_ZERO);
 *             PWM_SetCMPBLoadTiming(PWM1, ON_ZERO_PERIOD);
 * 
 ******************************************************************************/
#define PWM_SetCMPALoadTiming(PWMx,eMode)   ((PWMx)->CMPCTL.bit.CMPALOAD = (eMode))
#define PWM_SetCMPBLoadTiming(PWMx,eMode)   ((PWMx)->CMPCTL.bit.CMPBLOAD = (eMode))
#define PWM_SetCMPCLoadTiming(PWMx,eMode)   ((PWMx)->CMPCTL.bit.CMPCLOAD = (eMode))
#define PWM_SetCMPDLoadTiming(PWMx,eMode)   ((PWMx)->CMPCTL.bit.CMPDLOAD = (eMode))




/******************************************************************************
 * @brief      UnLock CMPA/CMPB/CMPC/CMPD active value
 *             Active value in CMPx will be updated when loading event occurred
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_UnlockCMPA(PWMx)                ((PWMx)->CMPCTL.bit.CMPALOCK = CMPCTL_BIT_CMPALOCK_UNLOCK)
#define PWM_UnlockCMPB(PWMx)                ((PWMx)->CMPCTL.bit.CMPBLOCK = CMPCTL_BIT_CMPBLOCK_UNLOCK)
#define PWM_UnlockCMPC(PWMx)                ((PWMx)->CMPCTL.bit.CMPCLOCK = CMPCTL_BIT_CMPCLOCK_UNLOCK)
#define PWM_UnlockCMPD(PWMx)                ((PWMx)->CMPCTL.bit.CMPDLOCK = CMPCTL_BIT_CMPDLOCK_UNLOCK)




/******************************************************************************
 * @brief      Lock CMPA/CMPB/CMPC/CMPD active value
 *             Active value in CMPx will not change
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_LockCMPA(PWMx)                  ((PWMx)->CMPCTL.bit.CMPALOCK = CMPCTL_BIT_CMPALOCK_LOCK)
#define PWM_LockCMPB(PWMx)                  ((PWMx)->CMPCTL.bit.CMPBLOCK = CMPCTL_BIT_CMPBLOCK_LOCK)
#define PWM_LockCMPC(PWMx)                  ((PWMx)->CMPCTL.bit.CMPCLOCK = CMPCTL_BIT_CMPCLOCK_LOCK)
#define PWM_LockCMPD(PWMx)                  ((PWMx)->CMPCTL.bit.CMPDLOCK = CMPCTL_BIT_CMPDLOCK_LOCK)




/******************************************************************************
 * @brief      Configure AQCTLA/B load mode
 *
 * @param[in]  PWMx :  Select the PWM module (PWM0~PWM5)
 * @param[in]  eMode:  AQCTLA/B load mode
 *                     Please goto PWM_LoadTimingEnum for selection
 *
 * @return     none
 *
 * @example    PWM_SetAQCTLALoadTiming(PWM0, ON_ZERO);
 *             PWM_SetAQCTLBLoadTiming(PWM1, ON_ZERO_PERIOD);
 * 
 ******************************************************************************/
#define PWM_SetAQCTLALoadTiming(PWMx,eMode) ((PWMx)->AQCTL.bit.AQCTLALOAD = (eMode))
#define PWM_SetAQCTLBLoadTiming(PWMx,eMode) ((PWMx)->AQCTL.bit.AQCTLBLOAD = (eMode))




/******************************************************************************
 * @brief      UnLock AQCTLA/B active value
 *             Active value in CMPx will be updated when loading event occurred
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_UnlockAQCTLA(PWMx)              ((PWMx)->AQCTL.bit.AQCTLALOCK = AQCTL_BIT_AQCTLALOCK_UNLOCK)
#define PWM_UnlockAQCTLB(PWMx)              ((PWMx)->AQCTL.bit.AQCTLBLOCK = AQCTL_BIT_AQCTLBLOCK_UNLOCK)




/******************************************************************************
 * @brief      Lock AQCTLA/B active value
 *             Active value in AQCTLA/B will not change
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_LockAQCTLA(PWMx)                ((PWMx)->AQCTL.bit.AQCTLALOCK = AQCTL_BIT_AQCTLALOCK_LOCK)
#define PWM_LockAQCTLB(PWMx)                ((PWMx)->AQCTL.bit.AQCTLBLOCK = AQCTL_BIT_AQCTLBLOCK_LOCK)




/******************************************************************************
 * @brief      Configure PWMxA/B output waveform
 *
 * @param[in]  PWMx      :  Select the PWM module (PWM0~PWM5)
 * @param[in]  eActionSel:  Specifies the action after events
 *                          Please goto PWM_ActionQualifierEnum for selection
 *
 * @return     none
 *
 * @example    PWM_ActionQualifierCHA(PWM0, CAU_SET_HIGH|CAD_SET_LOW|
 *                                          CBD_DO_NOTHING|CBU_DO_NOTHING|
 *                                          PRD_DO_NOTHING|ZRO_SET_LOW);
 *             Wrong Confiquration!!
 *             PWM_ActionQualifierCHA(PWM1, CAU_SET_HIGH|CAU_SET_LOW|  --> Can NOT configure 2 actions for same event
 *                                          CBD_DO_NOTHING|CBU_DO_NOTHING|
 *                                          PRD_DO_NOTHING|ZRO_SET_LOW);
 * 
 ******************************************************************************/
#define PWM_ActionQualifierCHA(PWMx,eActionSel) ((PWMx)->AQCTLA.all = (eActionSel))
#define PWM_ActionQualifierCHB(PWMx,eActionSel) ((PWMx)->AQCTLB.all = (eActionSel))




/******************************************************************************
 * @brief      Configure T0/T1 event
 *
 * @param[in]  PWMx  :  Select the PWM module (PWM0~PWM5)
 * @param[in]  eEvent:  Specifies the event
 *                      Please goto PWM_TxEventEnum for selection
 *
 * @return     none
 *
 * @example    PWM_SetT0Event(PWM0, TxEVENT_DCAEVT0);
 *             PWM_SetT1Event(PWM0, TxEVENT_TZ0);
 * 
 ******************************************************************************/
#define PWM_SetT0Event(PWMx,eEvent)         ((PWMx)->AQCTL.bit.T0SEL = (eEvent))
#define PWM_SetT1Event(PWMx,eEvent)         ((PWMx)->AQCTL.bit.T1SEL = (eEvent))




/******************************************************************************
 * @brief      Continuous force PWMx output A/B low
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_ForceCHALow(PWMx)               ((PWMx)->AQCSFRC.bit.CSFA = AQCSFRC_BIT_CSFA_FORCE_CONTINUOUS_LOW)
#define PWM_ForceCHBLow(PWMx)               ((PWMx)->AQCSFRC.bit.CSFB = AQCSFRC_BIT_CSFB_FORCE_CONTINUOUS_LOW)
#define PWM_ForceCHAandCHBLow(PWMx)         ((PWMx)->AQCSFRC.all = AQCSFRC_ALL_CSFA_FORCE_CONTINUOUS_LOW | AQCSFRC_ALL_CSFB_FORCE_CONTINUOUS_LOW)




/******************************************************************************
 * @brief      Continuous force PWMx output A/B High
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_ForceCHAHigh(PWMx)              ((PWMx)->AQCSFRC.bit.CSFA = AQCSFRC_BIT_CSFA_FORCE_CONTINUOUS_HIGH)
#define PWM_ForceCHBHigh(PWMx)              ((PWMx)->AQCSFRC.bit.CSFB = AQCSFRC_BIT_CSFB_FORCE_CONTINUOUS_HIGH)
#define PWM_ForceCHAandCHBHigh(PWMx)        ((PWMx)->AQCSFRC.all = AQCSFRC_ALL_CSFA_FORCE_CONTINUOUS_HIGH | AQCSFRC_ALL_CSFB_FORCE_CONTINUOUS_HIGH)




/******************************************************************************
 * @brief      Disable/Release force PWMxA/B 
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_DisableForceCHA(PWMx)           ((PWMx)->AQCSFRC.bit.CSFA = AQCSFRC_BIT_CSFA_DISABLE)
#define PWM_DisableForceCHB(PWMx)           ((PWMx)->AQCSFRC.bit.CSFB = AQCSFRC_BIT_CSFB_DISABLE)
#define PWM_DisableForceCHAandCHB(PWMx)     ((PWMx)->AQCSFRC.all = AQCSFRC_ALL_CSFA_DISABLE | AQCSFRC_ALL_CSFB_DISABLE)




/******************************************************************************
 * @brief      Configure DBCTL/DBRED/DBFED load mode
 *
 * @param[in]  PWMx :  Select the PWM module (PWM0~PWM5)
 * @param[in]  eMode:  DBCTL/DBRED/DBFED load mode
 *                     Please goto PWM_LoadTimingEnum for selection
 *                     Only the following value is valid:
 *                      - \ref ON_ZERO
 *                      - \ref ON_PERIOD
 *                      - \ref ON_ZERO_PERIOD
 *                      - \ref ON_IMMEDIATE
 *
 * @return     none
 *
 * @example    PWM_SetDBREDLoadTiming(PWM0, ON_ZERO);
 *             PWM_SetDBFEDLoadTiming(PWM1, ON_ZERO_PERIOD);
 * 
 ******************************************************************************/
#define PWM_SetDBCTLLoadTiming(PWMx,eMode)  ((PWMx)->DBCTL.bit.DBCTLLOAD = (eMode & 0x03))
#define PWM_SetDBREDLoadTiming(PWMx,eMode)  ((PWMx)->DBCTL.bit.DBREDLOAD = (eMode & 0x03))
#define PWM_SetDBFEDLoadTiming(PWMx,eMode)  ((PWMx)->DBCTL.bit.DBFEDLOAD = (eMode & 0x03))




/******************************************************************************
 * @brief      UnLock DBCTL/DBRED/DBFED active value
 *             Active value in DBCTL[9:0]/DBRED/DBFED will be updated when loading event occurred
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_UnlockDBCTL(PWMx)               ((PWMx)->DBCTL.bit.DBCTLLOCK = DBCTL_BIT_DBCTLLOCK_UNLOCK)
#define PWM_UnlockDBRED(PWMx)               ((PWMx)->DBCTL.bit.DBREDLOCK = DBCTL_BIT_DBREDLOCK_UNLOCK)
#define PWM_UnlockDBFED(PWMx)               ((PWMx)->DBCTL.bit.DBFEDLOCK = DBCTL_BIT_DBFEDLOCK_UNLOCK)




/******************************************************************************
 * @brief      Lock DBCTL/DBRED/DBFED active value
 *             Active value in DBCTL[9:0]/DBRED/DBFED will not change
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_LockDBCTL(PWMx)                 ((PWMx)->DBCTL.bit.DBCTLLOCK = DBCTL_BIT_DBCTLLOCK_LOCK)
#define PWM_LockDBRED(PWMx)                 ((PWMx)->DBCTL.bit.DBREDLOCK = DBCTL_BIT_DBREDLOCK_LOCK)
#define PWM_LockDBFED(PWMx)                 ((PWMx)->DBCTL.bit.DBFEDLOCK = DBCTL_BIT_DBFEDLOCK_LOCK)




/******************************************************************************
 * @brief      Set PWM dead band rising edge delay
 *
 * @param[in]  PWMx    : Select the PWM module (PWM0~PWM5)
 * @param[in]  u32Delay: Rising edge delay, unit is PWM counter clock
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_SetDeadBandRisingDelay(PWMx,u16Delay)   ((PWMx)->DBRED.all = (u16Delay))




/******************************************************************************
 * @brief      Set PWM dead band falling edge delay
 *
 * @param[in]  PWMx    :  Select the PWM module (PWM0~PWM5)
 * @param[in]  u32Delay:  Falling edge delay, unit is PWM counter clock
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_SetDeadBandFallingDelay(PWMx,u16Delay)  ((PWMx)->DBFED.all = (u16Delay))




/******************************************************************************
 * @brief      Get PWM dead band effective rising edge delay
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     Active rising edge delay (16 bit), unit is PWM counter clock
 *
 ******************************************************************************/
#define PWM_GetDeadBandRisingDelay(PWMx)    ((PWMx)->DBREDA.all)




/******************************************************************************
 * @brief      Get PWM dead band effective falling edge delay
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     Active falling edge delay (16 bit), unit is PWM counter clock
 *
 ******************************************************************************/
#define PWM_GetDeadBandFallingDelay(PWMx)   ((PWMx)->DBFEDA.all)




/******************************************************************************
 * @brief      Enable Debug mode as an CBC trip event
 *             PWM output will be triped to configured state when in Debug mode
 *
 *             Please remember call PWM_SetCHAOutputWhenTrip() and 
 *             PWM_SetCHBOutputWhenTrip() to set the PWM output when trip
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_EnableTripWhenDebug(PWMx)       ((PWMx)->TZSEL.bit.DBGCBC = TZSEL_BIT_DBGCBC_ENABLE)




/******************************************************************************
 * @brief      One-shot trip event select
 *
 * @param[in]  PWMx  :  Select the PWM module (PWM0~PWM5)
 * @param[in]  eEvent:  Select the one-shot trip events
 *                      Please goto PWM_TripEventEnum for the selection
 * @param[in]  eType :  Select the one-shot trip signal type
 *                      Please goto PWM_TripOutputEnum for the selection
 *
 * @return     none
 *
 * @example    PWM_SetOneShotTripEvent(PWM0, TRIP_EVENT_TZ0, TRIP_OUTPUT_LATCH);
 *             PWM_SetOneShotTripEvent(PWM0, TRIP_EVENT_TZ0 | TRIP_EVENT_TZ1, TRIP_OUTPUT_LATCH);
 *
 ******************************************************************************/
#define PWM_SetOneShotTripEvent(PWMx,eEvent,eOutType) ((PWMx)->TZSEL.all = (eEvent) | (eOutType))




/******************************************************************************
 * @brief      CBC trip event select
 *
 * @param[in]  PWMx  :  Select the PWM module (PWM0~PWM5)
 * @param[in]  eEvent:  Select the CBC trip events
 *                      Please goto PWM_TripEventEnum for the selection
 * @param[in]  eType :  Select the CBC trip signal type
 *                      Please goto PWM_TripOutputEnum for the selection
 * @return     none
 *
 * @example    PWM_SetCBCTripEvent(PWM0, TRIP_EVENT_TZ0, TRIP_OUTPUT_LATCH);
 *             PWM_SetCBCTripEvent(PWM0, TRIP_EVENT_TZ0 | TRIP_EVENT_TZ1, TRIP_OUTPUT_LATCH);
 *
 ******************************************************************************/
#define PWM_SetCBCTripEvent(PWMx,eEvent,eOutType)   ((PWMx)->TZSEL.all = (((eEvent) << TZSEL_ALL_CBCOUT_Pos) | (eOutType << TZSEL_ALL_CBCOUT_Pos)))




/******************************************************************************
 * @brief      Configure PWMxA/B output pin state after trip event happen
 *
 * @param[in]  PWMx   :  Select the PWM module (PWM0~PWM5)
 * @param[in]  eAction:  Specifies the action after trip
 *                       Please goto PWM_TripActionEnum for selection
 *
 * @return     none
 *
 * @note       Actions for all six scenarios should be explicitly specified 
 *
 * @example    PWM_SetCHAOutputWhenTrip(PWM0, TZU_TRIP_AS_LOW |
 *                                            TZD_TRIP_AS_LOW |
 *                                            DCEVT0U_TRIP_DO_NOTHING |
 *                                            DCEVT0D_TRIP_DO_NOTHING |
 *                                            DCEVT1U_TRIP_DO_NOTHING |
 *                                            DCEVT1D_TRIP_DO_NOTHING); 
 *                                            TZD_TRIP_AT_LOW | TZU_DO_NOTHING);
 *             Wrong Confiquration!!
 *             PWM_SetCHAOutputWhenTrip(PWM0, TZU_TRIP_AS_LOW | TZU_TRIP_AS_HIGH  <-- CANNOT configure 2 actions for the same event
 *                                            TZD_TRIP_AS_LOW |
 *                                            DCEVT0U_TRIP_DO_NOTHING |
 *                                            DCEVT0D_TRIP_DO_NOTHING |
 *                                            DCEVT1U_TRIP_DO_NOTHING |
 *                                            DCEVT1D_TRIP_DO_NOTHING); 
 *                                            TZD_TRIP_AT_LOW | TZU_DO_NOTHING);
 *
 ******************************************************************************/
#define PWM_SetCHAOutputWhenTrip(PWMx,eAction)  ((PWMx)->TZACTL.all = (eAction))
#define PWM_SetCHBOutputWhenTrip(PWMx,eAction)  ((PWMx)->TZBCTL.all = (eAction))




/******************************************************************************
 * @brief      Enable one shot interrupt
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_EnableOneShotTripInt(PWMx)      ((PWMx)->TZIE.bit.OST = TZIE_BIT_OST_ENABLE)




/******************************************************************************
 * @brief      Disable one shot interrupt
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_DisableOneShotTripInt(PWMx)     ((PWMx)->TZIE.bit.OST = TZIE_BIT_OST_DISABLE)




/******************************************************************************
 * @brief      Enable cycle by cycle interrupt
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_EnableCBCTripInt(PWMx)          ((PWMx)->TZIE.bit.CBC = TZIE_BIT_CBC_ENABLE)




/******************************************************************************
 * @brief      Disable cycle by cycle interrupt
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_DisableCBCTripInt(PWMx)         ((PWMx)->TZIE.bit.CBC = TZIE_BIT_CBC_DISABLE)




/******************************************************************************
 * @brief      Enable DCAEVT0 interrupt
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_EnableDCAEVT0TripInt(PWMx)      ((PWMx)->TZIE.bit.DCAEVT0 = TZIE_BIT_DCAEVT0_ENABLE)




/******************************************************************************
 * @brief      Disable DCAEVT0 interrupt
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_DisableDCAEVT0TripInt(PWMx)     ((PWMx)->TZIE.bit.DCAEVT0 = TZIE_BIT_DCAEVT0_DISABLE)




/******************************************************************************
 * @brief      Enable DCAEVT1 interrupt
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_EnableDCAEVT1TripInt(PWMx)      ((PWMx)->TZIE.bit.DCAEVT1 = TZIE_BIT_DCAEVT1_ENABLE)




/******************************************************************************
 * @brief      Disable DCAEVT1 interrupt
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_DisableDCAEVT1TripInt(PWMx)     ((PWMx)->TZIE.bit.DCAEVT1 = TZIE_BIT_DCAEVT1_DISABLE)




/******************************************************************************
 * @brief      Enable DCBEVT0 interrupt
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_EnableDCBEVT0TripInt(PWMx)      ((PWMx)->TZIE.bit.DCBEVT0 = TZIE_BIT_DCBEVT0_ENABLE)




/******************************************************************************
 * @brief      Disable DCBEVT0 interrupt
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_DisableDCBEVT0TripInt(PWMx)     ((PWMx)->TZIE.bit.DCBEVT0 = TZIE_BIT_DCBEVT0_DISABLE)




/******************************************************************************
 * @brief      Enable DCBEVT1 interrupt
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_EnableDCBEVT1TripInt(PWMx)      ((PWMx)->TZIE.bit.DCBEVT1 = TZIE_BIT_DCBEVT1_ENABLE)




/******************************************************************************
 * @brief      Disable DCBEVT1 interrupt
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_DisableDCBEVT1TripInt(PWMx)     ((PWMx)->TZIE.bit.DCBEVT1 = TZIE_BIT_DCBEVT1_DISABLE)




/******************************************************************************
 * @brief      Get one shot trip interrupt flag
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     0 - One shot interrupt does not occur
 *             1 - One shot interrupt occurred
 *
 ******************************************************************************/
#define PWM_GetOneShotTripIntFlag(PWMx)     ((PWMx)->TZIF.bit.OST)




/******************************************************************************
 * @brief      Get cycle by cycle trip interrupt flag
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     0 - Cycle by cycle interrupt does not occur
 *             1 - Cycle by cycle interrupt occured
 *
 ******************************************************************************/
#define PWM_GetCBCTripIntFlag(PWMx)         ((PWMx)->TZIF.bit.CBC)




/******************************************************************************
 * @brief      Get DCAEVT0 trip interrupt flag
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     0 - DCAEVT0 trip interrupt does not occur
 *             1 - DCAEVT0 trip interrupt occured
 *
 ******************************************************************************/
#define PWM_GetDCAEVT0TripIntFlag(PWMx)     ((PWMx)->TZIF.bit.DCAEVT0)




/******************************************************************************
 * @brief      Get DCAEVT1 trip interrupt flag
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     0 - DCAEVT1 trip interrupt does not occur
 *             1 - DCAEVT1 trip interrupt occured
 *
 ******************************************************************************/
#define PWM_GetDCAEVT1TripIntFlag(PWMx)     ((PWMx)->TZIF.bit.DCAEVT1)




/******************************************************************************
 * @brief      Get DCBEVT0 trip interrupt flag
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     0 - DCBEVT0 trip interrupt does not occur
 *             1 - DCBEVT0 trip interrupt occured
 *
 ******************************************************************************/
#define PWM_GetDCBEVT0TripIntFlag(PWMx)     ((PWMx)->TZIF.bit.DCBEVT0)




/******************************************************************************
 * @brief      Get DCBEVT1 trip interrupt flag
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     0 - DCBEVT1 trip interrupt does not occur
 *             1 - DCBEVT1 trip interrupt occured
 *
 ******************************************************************************/
#define PWM_GetDCBEVT1TripIntFlag(PWMx)     ((PWMx)->TZIF.bit.DCBEVT1)




/******************************************************************************
 * @brief      Get trip interrupt status
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     0 - No trip interrupt has been generated and issued to the CPU
 *             1 - A trip interrupt was generated and issued to the CPU
 *
 ******************************************************************************/
#define PWM_GetTripGlobalIntFlag(PWMx)      ((PWMx)->TZIF.bit.INT)




/******************************************************************************
 * @brief      Clear one shot trip interrupt flag
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_ClearOneShotTripInt(PWMx)       ((PWMx)->TZIC.all = TZIC_ALL_OST_CLEAR)




/******************************************************************************
 * @brief      Clear cycle by cycle trip interrupt flag
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_ClearCBCTripInt(PWMx)           ((PWMx)->TZIC.all = TZIC_ALL_CBC_CLEAR)




/******************************************************************************
 * @brief      Clear DCAEVT0 trip interrupt flag
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_ClearDCAEVT0TripInt(PWMx)       ((PWMx)->TZIC.all = TZIC_ALL_DCAEVT0_CLEAR)




/******************************************************************************
 * @brief      Clear DCAEVT1 trip interrupt flag
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_ClearDCAEVT1TripInt(PWMx)       ((PWMx)->TZIC.all = TZIC_ALL_DCAEVT1_CLEAR)




/******************************************************************************
 * @brief      Clear DCBEVT0 trip interrupt flag
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_ClearDCBEVT0TripInt(PWMx)       ((PWMx)->TZIC.all = TZIC_ALL_DCBEVT0_CLEAR)




/******************************************************************************
 * @brief      Clear DCBEVT1 trip interrupt flag
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_ClearDCBEVT1TripInt(PWMx)       ((PWMx)->TZIC.all = TZIC_ALL_DCBEVT1_CLEAR)




/******************************************************************************
 * @brief      Clear global trip interrupt flag
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_ClearTripGlobalInt(PWMx)        ((PWMx)->TZIC.all = TZIC_ALL_INT_CLEAR)




/******************************************************************************
 * @brief      Hardware clear cycle by cycle trip interrupt flag
 *
 * @param[in]  PWMx :  Select the PWM module (PWM0~PWM5)
 * @param[in]  eMode:  CBC trip status clear mode
 *                     Please go to TZIC_BIT_CBCCLRMODE for details
 *
 * @return     none
 *
 * @example    PWM_ClearCBCTripIntByHardware(PWM0, TZIC_BIT_CBCCLRMODE_CLEAR_ON_ZERO);
 *
 ******************************************************************************/
#define PWM_ClearCBCTripIntByHardware(PWMx,eMode) ((PWMx)->TZIC.bit.CBCCLRMODE = (eMode))




/******************************************************************************
 * @brief      Enable DCAH/DCAL/DCBH/DCBL trip events
 *
 * @param[in]  PWMx  :  Select the PWM module (PWM0~PWM5)
 * @param[in]  eEvent:  Select the DC trip events
 *                      Please goto PWM_DCTripEventEnum for selection
 *
 * @return     none
 *
 * @example    PWM_EnableDCAHTripEvent(PWM0, DC_TRIP_COMP0L);
 *             PWM_EnableDCAHTripEvent(PWM0, DC_TRIP_COMP0H | DC_TRIP_TZ0);
 *
 ******************************************************************************/
#define PWM_EnableDCAHTripEvent(PWMx,eEvent)  ((PWMx)->DCAHTRIPSEL.all |= (eEvent))
#define PWM_EnableDCALTripEvent(PWMx,eEvent)  ((PWMx)->DCALTRIPSEL.all |= (eEvent))
#define PWM_EnableDCBHTripEvent(PWMx,eEvent)  ((PWMx)->DCBHTRIPSEL.all |= (eEvent))
#define PWM_EnableDCBLTripEvent(PWMx,eEvent)  ((PWMx)->DCBLTRIPSEL.all |= (eEvent))




/******************************************************************************
 * @brief      Disable DCAH/DCAL/DCBH/DCBL trip events
 *
 * @param[in]  PWMx  :  Select the PWM module (PWM0~PWM5)
 * @param[in]  eEvent:  Select the DC trip events
 *                      Please goto PWM_DCTripEventEnum for selection
 *
 * @return     none
 *
 * @example    PWM_DisableDCAHTripEvent(PWM0, DC_TRIP_COMP0L);
 *             PWM_DisableDCAHTripEvent(PWM0, DC_TRIP_COMP0H | DC_TRIP_TZ0);
 *
 ******************************************************************************/
#define PWM_DisableDCAHTripEvent(PWMx,eEvent) ((PWMx)->DCAHTRIPSEL.all &= ~(eEvent))
#define PWM_DisableDCALTripEvent(PWMx,eEvent) ((PWMx)->DCALTRIPSEL.all &= ~(eEvent))
#define PWM_DisableDCBHTripEvent(PWMx,eEvent) ((PWMx)->DCBHTRIPSEL.all &= ~(eEvent))
#define PWM_DisableDCBLTripEvent(PWMx,eEvent) ((PWMx)->DCBLTRIPSEL.all &= ~(eEvent))




/******************************************************************************
 * @brief      Set raw DCAEVT0/DCAEVT1/DCBEVT0/DCBEVT1 event
 *
 * @param[in]  PWMx    :  Select the PWM module (PWM0~PWM5)
 * @param[in]  eEvent  :  Select the Raw DC event
 *                        Please goto PWM_RawDCEventEnum for the selection
 *
 * @return     none
 *
 * @example    PWM_SetRawDCAEVT0(PWM0, DCH_X_DCL_HIGH);
 *
 ******************************************************************************/
#define PWM_SetRawDCAEVT0(PWMx,eEvent)      ((PWMx)->TZDCSEL.bit.DCAEVT0 = (eEvent))
#define PWM_SetRawDCAEVT1(PWMx,eEvent)      ((PWMx)->TZDCSEL.bit.DCAEVT1 = (eEvent))
#define PWM_SetRawDCBEVT0(PWMx,eEvent)      ((PWMx)->TZDCSEL.bit.DCBEVT0 = (eEvent))
#define PWM_SetRawDCBEVT1(PWMx,eEvent)      ((PWMx)->TZDCSEL.bit.DCBEVT1 = (eEvent))




/******************************************************************************
 * @brief      Set final DCAEVT0/DCAEVT1/DCBEVT0/DCBEVT1 event
 *
 * @param[in]  PWMx    :  Select the PWM module (PWM0~PWM5)
 * @param[in]  eEvent  :  Select the final DC event
 *                        Please goto PWM_DCEventEnum for the selection
 *
 * @return     none
 *
 * @example    PWM_SetDCAEVT0(PWM0, DCEVT_FILTERED);
 *             PWM_SetDCBEVT0(PWM0, DCEVT_RAW);
 *
 ******************************************************************************/
#define PWM_SetDCAEVT0(PWMx,eEvent)         ((PWMx)->DCACTL.bit.EVT0SRCSEL = (eEvent))
#define PWM_SetDCAEVT1(PWMx,eEvent)         ((PWMx)->DCACTL.bit.EVT1SRCSEL = (eEvent))
#define PWM_SetDCBEVT0(PWMx,eEvent)         ((PWMx)->DCBCTL.bit.EVT0SRCSEL = (eEvent))
#define PWM_SetDCBEVT1(PWMx,eEvent)         ((PWMx)->DCBCTL.bit.EVT1SRCSEL = (eEvent))




/******************************************************************************
 * @brief      Enable/Disable DCAEVT0 trigger SYNC
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_EnableDCAEVT0TriggerSync(PWMx)  ((PWMx)->DCACTL.bit.EVT0SYNCE = DCACTL_BIT_EVT0SYNCE_ENABLE)
#define PWM_DisableDCAEVT0TriggerSync(PWMx) ((PWMx)->DCACTL.bit.EVT0SYNCE = DCACTL_BIT_EVT0SYNCE_DISABLE)




/******************************************************************************
 * @brief      Enable/Disable DCBEVT0 trigger SYNC
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_EnableDCBEVT0TriggerSync(PWMx)  ((PWMx)->DCBCTL.bit.EVT0SYNCE = DCBCTL_BIT_EVT0SYNCE_ENABLE)
#define PWM_DisableDCBEVT0TriggerSync(PWMx) ((PWMx)->DCBCTL.bit.EVT0SYNCE = DCBCTL_BIT_EVT0SYNCE_DISABLE)




/******************************************************************************
 * @brief      Enable/Disable DCAEVT0 trigger SOC
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_EnableDCAEVT0TriggerSOC(PWMx)   ((PWMx)->DCACTL.bit.EVT0SOCE = DCACTL_BIT_EVT0SOCE_ENABLE)
#define PWM_DisableDCAEVT0TriggerSOC(PWMx)  ((PWMx)->DCACTL.bit.EVT0SOCE = DCACTL_BIT_EVT0SOCE_DISABLE)




/******************************************************************************
 * @brief      Enable/Disable DCBEVT0 trigger SOC
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_EnableDCBEVT0TriggerSOC(PWMx)   ((PWMx)->DCBCTL.bit.EVT0SOCE = DCBCTL_BIT_EVT0SOCE_ENABLE)
#define PWM_DisableDCBEVT0TriggerSOC(PWMx)  ((PWMx)->DCBCTL.bit.EVT0SOCE = DCBCTL_BIT_EVT0SOCE_DISABLE)




/******************************************************************************
 * @brief      Configure DC filter
 *
 * @param[in]  PWMx  :  Select the PWM module (PWM0~PWM5)
 * @param[in]  eEvent:  Select the input event of the filter
 *                      Please goto PWM_DCFilterInputEnum for selection
 * @param[in]  eAlign:  Select the blank window alignment
 *                      Please goto PWM_DCFilterAlignEnum for selection
 *
 * @return     none
 *
 * @example    PWM_SetDCFilter(PWM0, DCF_FROM_RAW_DCAEVT0, DCF_ALIGN_ON_ZERO);
 *
 ******************************************************************************/
__STATIC_INLINE void PWM_SetDCFilter(PWM_REGS* PWMx, PWM_DCFilterInputEnum eEvent, PWM_DCFilterAlignEnum eAlign)
{
  PWMx->DCFCTL.bit.SRCSEL   = eEvent;
  PWMx->DCFCTL.bit.PULSESEL = eAlign;
}




/******************************************************************************
 * @brief      Enable DC filter blanking window from other PWM module
 *
 * @param[in]  PWMx :  Select the PWM module (PWM0~PWM5)
 * @param[in]  ePWMs:  Select other PWM module
 *                     Please go to PWM_IncEnum for details
 *
 * @return     none
 *
 * @example    PWM_EnableDCFilterFromOtherPWM(PWM0, INC_PWM1);
 *             PWM_EnableDCFilterFromOtherPWM(PWM0, INC_PWM1 | INC_PWM2);
 *
 ******************************************************************************/
#define PWM_EnableDCFilterFromOtherPWM(PWMx,ePWMs)  ((PWMx)->DCFCTL.all |= ((ePWMs) << DCFCTL_ALL_WIN0EN_Pos))




/******************************************************************************
 * @brief      Disable DC filter blanking window from other PWM module
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 * @param[in]  ePWMs:  Select other PWM module
 *                     Please go to PWM_IncEnum for details
 *
 * @return     none
 *
 * @example    PWM_DisableDCFilterFromOtherPWM(PWM0, INC_PWM1);
 *             PWM_DisableDCFilterFromOtherPWM(PWM0, INC_PWM1 | INC_PWM2);
 *
 ******************************************************************************/
#define PWM_DisableDCFilterFromOtherPWM(PWMx,ePWMs) ((PWMx)->DCFCTL.all &= ~((ePWMs) << DCFCTL_ALL_WIN0EN_Pos))




/******************************************************************************
 * @brief      Enable DC filter blanking window
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_EnableDCFilterBlank(PWMx)       ((PWMx)->DCFCTL.bit.BLANKEN = DCFCTL_BIT_BLANKEN_ENABLE)




/******************************************************************************
 * @brief      Disable DC filter blanking window
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_DisableDCFilterBlank(PWMx)      ((PWMx)->DCFCTL.bit.BLANKEN = DCFCTL_BIT_BLANKEN_DISABLE)




/******************************************************************************
 * @brief      Enable DC filter blanking window inversion
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_EnableDCFilterBlankInvert(PWMx)   ((PWMx)->DCFCTL.bit.BLANKINV = DCFCTL_BIT_BLANKINV_ENABLE)




/******************************************************************************
 * @brief      Disable DC filter blanking window inversion
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_DisableDCFilterBlankInvert(PWMx)  ((PWMx)->DCFCTL.bit.BLANKINV = DCFCTL_BIT_BLANKINV_DISABLE)




/******************************************************************************
 * @brief      Set DC Filter window size and offset
 *
 * @param[in]  PWMx     :  Select the PWM module (PWM0~PWM5)
 * @param[in]  u16Size  :  Size of the blank window (16 bit)
 *                         Unit: counter clock
 * @param[in]  u16Offset:  Offset of the blank window (16 bit)
 *                         Unit: counter clock
 *
 * @return     none
 *
 ******************************************************************************/
__STATIC_INLINE void PWM_SetDCFilterBlankWindow(PWM_REGS* PWMx, uint16_t u16Size, uint16_t u16Offset)
{
  PWMx->DCFWINDOW.all = u16Size;
  PWMx->DCFOFFSET.all = u16Offset;
}




/******************************************************************************
 * @brief      Enable SOCA as an ADC trigger signal
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_EnableSOCA(PWMx)                ((PWMx)->ETCTL.bit.SOCAEN = ETCTL_BIT_SOCAEN_ENABLE)




/******************************************************************************
 * @brief      Disable SOCA as an ADC trigger signal
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_DisableSOCA(PWMx)               ((PWMx)->ETCTL.bit.SOCAEN = ETCTL_BIT_SOCAEN_DISABLE)




/******************************************************************************
 * @brief      Configure PWMA SOC(SOCA) trigger pulse generate timing
 *
 * @param[in]  PWMx   :  Select the PWM module (PWM0~PWM5)
 * @param[in]  eTiming:  Specifies the event timing
 *                       Please goto PWM_EventTimingEnum for selection
 *
 * @return     none
 *
 * @details    This function is to confiqure the event period that ADC trigger 
 *             signal or PWM time event.
 * 
 ******************************************************************************/
#define PWM_SetSOCATiming(PWMx,eTiming)     ((PWMx)->ETCTL.bit.SOCASEL = (eTiming))




/******************************************************************************
 * @brief      Configure PWMA SOC(SOCA) trigger pulse generate period
 *
 * @param[in]  PWMx   :  Select the PWM module (PWM0~PWM5)
 * @param[in]  ePeriod:  Specifies the period
 *                       Please goto PWM_EventPeriodEnum for selection
 *
 * @return     none
 *
 * @details    This function is to confiqure the event period that ADC trigger 
 *             signal or PWM time event.
 * 
 ******************************************************************************/
#define PWM_SetSOCAPeriod(PWMx,ePeriod)     ((PWMx)->ETPS.bit.SOCAPRD  = (ePeriod))




/******************************************************************************
 * @brief      Enable SOCB as an ADC trigger signal
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_EnableSOCB(PWMx)                ((PWMx)->ETCTL.bit.SOCBEN = ETCTL_BIT_SOCBEN_ENABLE)




/******************************************************************************
 * @brief      Disble SOCB as an ADC trigger signal
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_DisableSOCB(PWMx)               ((PWMx)->ETCTL.bit.SOCBEN = ETCTL_BIT_SOCBEN_DISABLE)




/******************************************************************************
 * @brief      Configure PWMB SOC(SOCB) ADC trigger pulse generate timing
 *
 * @param[in]  PWMx   :  Select the PWM module (PWM0~PWM5)
 * @param[in]  eTiming:  Specifies the event timing
 *                       Please goto PWM_EventTimingEnum for selection
 *
 * @return     none
 * 
 * @details    This function is to confiqure the event period that ADC trigger 
 *             signal or PWM time event
 * 
 ******************************************************************************/
#define PWM_SetSOCBTiming(PWMx,eTiming)     ((PWMx)->ETCTL.bit.SOCBSEL = (eTiming))




/******************************************************************************
 * @brief      Configure PWMB SOC(SOCB) trigger pulse generate period
 *
 * @param[in]  PWMx   :  Select the PWM module (PWM0~PWM5)
 * @param[in]  ePeriod:  Specifies the period
 *                       Please goto PWM_EventPeriodEnum for selection
 *
 * @return     none
 *
 * @details    This function is to confiqure the event period that ADC trigger 
 *             signal or PWM time event.
 * 
 ******************************************************************************/
#define PWM_SetSOCBPeriod(PWMx,ePeriod)     ((PWMx)->ETPS.bit.SOCBPRD  = (ePeriod))




/******************************************************************************
 * @brief      Enable SOCC as an ADC trigger signal
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_EnableSOCC(PWMx)                ((PWMx)->ETCTL.bit.SOCCEN = ETCTL_BIT_SOCCEN_ENABLE)




/******************************************************************************
 * @brief      Disble SOCC as an ADC trigger signal
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_DisableSOCC(PWMx)               ((PWMx)->ETCTL.bit.SOCCEN = ETCTL_BIT_SOCCEN_DISABLE)




/******************************************************************************
 * @brief      Configure PWMB SOC(SOCC) ADC trigger pulse generate timing
 *
 * @param[in]  PWMx   :  Select the PWM module (PWM0~PWM5)
 * @param[in]  eTiming:  Specifies the event timing
 *                       Please goto PWM_EventTimingEnum for selection
 *
 * @return     none
 * 
 * @details    This function is to confiqure the event period that ADC trigger 
 *             signal or PWM time event
 * 
 ******************************************************************************/
#define PWM_SetSOCCTiming(PWMx,eTiming)     ((PWMx)->ETCTL.bit.SOCCSEL = (eTiming))




/******************************************************************************
 * @brief      Configure PWMB SOC(SOCC) trigger pulse generate period
 *
 * @param[in]  PWMx   :  Select the PWM module (PWM0~PWM5)
 * @param[in]  ePeriod:  Specifies the period
 *                       Please goto PWM_EventPeriodEnum for selection
 *
 * @return     none
 *
 * @details    This function is to confiqure the event period that ADC trigger 
 *             signal or PWM time event.
 * 
 ******************************************************************************/
#define PWM_SetSOCCPeriod(PWMx,ePeriod)     ((PWMx)->ETPS.bit.SOCCPRD  = (ePeriod))




/******************************************************************************
 * @brief      Enable Time event interrupt
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_EnableTimeEventInt(PWMx)        ((PWMx)->ETCTL.bit.INTEN  = ETCTL_BIT_INTEN_ENABLE)




/******************************************************************************
 * @brief      Disable Time event interrupt
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_DisableTimeEventInt(PWMx)       ((PWMx)->ETCTL.bit.INTEN  = ETCTL_BIT_INTEN_DISABLE)




/******************************************************************************
 * @brief      Configure PWM time event generate timing
 *
 * @param[in]  PWMx   :  Select the PWM module (PWM0~PWM5)
 * @param[in]  eTiming:  Specifies the event timing
 *                       Please goto PWM_EventTimingEnum for selection
 *
 * @return     none
 *
 * @details    This function is to confiqure the event period that ADC trigger 
 *             signal or PWM time event.
 * 
 ******************************************************************************/
#define PWM_SetTimeEventTiming(PWMx,eTiming)  ((PWMx)->ETCTL.bit.INTSEL = (eTiming))




/******************************************************************************
 * @brief      Configure PWM time event generate period
 *
 * @param[in]  PWMx   :  Select the PWM module (PWM0~PWM5)
 * @param[in]  ePeriod:  Specifies the period
 *                       Please goto PWM_EventPeriodEnum for selection
 * 
 * @return     none
 * 
 * @details    This function is to confiqure the event period that ADC trigger 
 *             signal or PWM time event.
 * 
 ******************************************************************************/
#define PWM_SetTimeEventPeriod(PWMx,ePeriod)  ((PWMx)->ETPS.bit.INTPRD = (ePeriod))




/******************************************************************************
 * @brief      Clear time event interrupt flag
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_ClearTimeEventInt(PWMx)         ((PWMx)->ETCLR.all = ETCLR_ALL_INT_CLEAR)




/******************************************************************************
 * @brief      Get time event status flag
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     0 - PWM interrupt not occur
 *             1 - PWM interrupt has occurred
 *
 ******************************************************************************/
#define PWM_GetTimeEventIntFlag(PWMx)       ((PWMx)->ETFLG.bit.INT)




/******************************************************************************
 * @brief      Clear SOCx event flag
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_ClearSOCAEvent(PWMx)            ((PWMx)->ETCLR.all = ETCLR_ALL_SOCA_CLEAR)
#define PWM_ClearSOCBEvent(PWMx)            ((PWMx)->ETCLR.all = ETCLR_ALL_SOCB_CLEAR)
#define PWM_ClearSOCCEvent(PWMx)            ((PWMx)->ETCLR.all = ETCLR_ALL_SOCC_CLEAR)




/******************************************************************************
 * @brief      Get SOCx event flag
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM5)
 *
 * @return     0 - SOCx event not occur
 *             1 - A SOCx event has occurred
 *
 ******************************************************************************/
#define PWM_GetSOCAEventFlag(PWMx)          ((PWMx)->ETFLG.bit.SOCA)
#define PWM_GetSOCBEventFlag(PWMx)          ((PWMx)->ETFLG.bit.SOCB)
#define PWM_GetSOCCEventFlag(PWMx)          ((PWMx)->ETFLG.bit.SOCC)




/******************************************************************************
 * @brief      Software force clock synchronization for all PWM modules
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define PWM_ForceClockSync()                (PWMCFG->FRCSYNC.all = FRCSYNC_ALL_PWMCLK_FORCE)




/******************************************************************************
 * @brief      Software force PWM synchronization
 *
 * @param[in]  ePWMs:  Select the PWM module to be synchronized
 *                     Please goto PWM_IncEnum for the selection
 *
 * @return     none
 *
 * @example    PWM_ForceSync(INC_PWM0);  // For PWM0 Sync
 *             PWM_ForceSync(INC_PWM0 | INC_PWM1);  // For PWM0 and PWM1 Sync
 *
 ******************************************************************************/
#define PWM_ForceSync(ePWMs)                (PWMCFG->FRCSYNC.all = (ePWMs))




/******************************************************************************
 * @brief      Enable PWM synchronization by GPIO
 *
 * @param[in]  ePWMs:  Select the PWM module to be synchronized
 *                     Please goto PWM_IncEnum for the selection
 *
 * @return     none
 *
 * @example    PWM_EnableSyncFromGPIO(INC_PWM0);  // Enable PWM0 Sync by GPIO
 *             PWM_EnableSyncFromGPIO(INC_PWM0 | INC_PWM1);  // Enable PWM0 and PWM1 Sync by GPIO
 *
 ******************************************************************************/
#define PWM_EnableSyncFromGPIO(ePWMs)       (PWMCFG->GPIOSYNCEN.all |= (ePWMs))




/******************************************************************************
 * @brief      Disable PWM synchronization by GPIO
 *
 * @param[in]  ePWMs:  Select the PWM module to be un-synchronized
 *                     Please goto PWM_IncEnum for the selection
 *
 * @return     none
 *
 * @example    PWM_DisableSyncFromGPIO(INC_PWM0);  // Disable PWM0 Sync by GPIO
 *             PWM_DisableSyncFromGPIO(INC_PWM0 | INC_PWM1);  // Disable PWM0 and PWM1 Sync by GPIO
 *
 ******************************************************************************/
#define PWM_DisableSyncFromGPIO(ePWMs)      (PWMCFG->GPIOSYNCEN.all &= ~(ePWMs))




/******************************************************************************
 * @brief      Enable PWM synchronization by Timer
 *
 * @param[in]  ePWMs:  Select the PWM module to be synchronized
 *                     Please goto PWM_IncEnum for the selection
 *
 * @return     none
 *
 * @example    PWM_EnableSyncFromTIMER0(INC_PWM0);  // Enable PWM0 Sync by Timer0
 *             PWM_EnableSyncFromTIMER0(INC_PWM0 | INC_PWM1);  // Enable PWM0 and PWM1 Sync by Timer0
 *
 ******************************************************************************/
#define PWM_EnableSyncFromTIMER0(ePWMs)     (PWMCFG->TMR0SYNCEN.all |= (ePWMs))
#define PWM_EnableSyncFromTIMER1(ePWMs)     (PWMCFG->TMR1SYNCEN.all |= (ePWMs))
#define PWM_EnableSyncFromTIMER2(ePWMs)     (PWMCFG->TMR2SYNCEN.all |= (ePWMs))




/******************************************************************************
 * @brief      Disable PWM synchronization by Timer
 *
 * @param[in]  ePWMs:  Select the PWM module to be un-synchronized
 *                     Please goto PWM_IncEnum for the selection
 *
 * @return     none
 *
 * @example    PWM_DisableSyncFromTIMER0(INC_PWM0);  // Disable PWM0 Sync by Timer0
 *             PWM_DisableSyncFromTIMER0(INC_PWM0 | INC_PWM1);  // Disable PWM0 and PWM1 Sync by Timer0
 *
 ******************************************************************************/
#define PWM_DisableSyncFromTIMER0(ePWMs)    (PWMCFG->TMR0SYNCEN.all &= ~(ePWMs))
#define PWM_DisableSyncFromTIMER1(ePWMs)    (PWMCFG->TMR1SYNCEN.all &= ~(ePWMs))
#define PWM_DisableSyncFromTIMER2(ePWMs)    (PWMCFG->TMR2SYNCEN.all &= ~(ePWMs))




/******************************************************************************
 * @brief      Enable write access to the protected PWM registers
 *
 * @param[in]  PWMx:  Select the PWM module
 *
 * @return     none
 * 
 ******************************************************************************/
#define PWM_WALLOW(PWMx)                    ((PWMx)->PWMREGKEY.all = 0x1ACCE551)




/******************************************************************************
 * @brief      Disable write access to the protected PWM registers
 *
 * @param[in]  PWMx:  Select the ECAP module
 *
 * @return     none
 * 
 ******************************************************************************/
#define PWM_WDIS(PWMx)                      ((PWMx)->PWMREGKEY.all = 0x0)




/******************************************************************************
 * @brief      Enable write access to the protected PWMCFG registers
 *
 * @param[in]  none
 *
 * @return     none
 * 
 ******************************************************************************/
#define PWMCFG_WALLOW()                     (PWMCFG->PWMCFGREGKEY.all = 0x1ACCE551)




/******************************************************************************
 * @brief      Disable write access to the protected PWMCFG registers
 *
 * @param[in]  PWMx:  Select the ECAP module
 *
 * @return     none
 * 
 ******************************************************************************/
#define PWMCFG_WDIS()                       (PWMCFG->PWMCFGREGKEY.all = 0x0)




/**
 *  @brief  PWM Public Function Declaration
 */
void PWM_ComplementaryPairChannelInit(PWM_REGS* PWMx, uint32_t u32PWMFreqHz, uint32_t u32DeadTimeNs);
void PWM_SingleChannelInit(PWM_REGS* PWMx, PWM_ChannelEnum ePWM_CH, uint32_t u32PWMFreqHz);

void PWM_SetTZ0FromGPIO(GPIO_PinEnum ePinNum, uint8_t ePinLevel);
void PWM_SetTZ1FromGPIO(GPIO_PinEnum ePinNum, uint8_t ePinLevel);
void PWM_SetTZ2FromGPIO(GPIO_PinEnum ePinNum, uint8_t ePinLevel);
void PWM_SetTZ3FromGPIO(GPIO_PinEnum ePinNum, uint8_t ePinLevel);
void PWM_SetTZ4FromGPIO(GPIO_PinEnum ePinNum, uint8_t ePinLevel);

void PWM_SetSyncFromGPIO(GPIO_PinEnum ePinNum, uint8_t ePinLevel);

uint32_t PWM_CalculateSyncReloadValue(uint32_t u32TBPRD, PWM_CounterModeEnum eCntMode, uint8_t ePHSDIR, uint32_t u32SyncVal, uint32_t u32TBClkDiv);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* PWM_H */


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
