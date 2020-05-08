/******************************************************************************
 * @file     timer.h
 * @brief    TIMER module header file.
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


#ifndef TIMER_H
#define TIMER_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1168.h"




/******************************************************************************
 * @brief      Enable Hold counter value upon TMRCTL.EN from 1 to 0
 *
 * @param[in]  TIMERx:  Select the timer module
 *
 * @return     none
 *
 ******************************************************************************/
#define TIMER_EnableCounterHold(TIMERx)     ((TIMERx)->TMRCTL.bit.HOLD = TMRCTL_BIT_HOLD_ENABLE)




/******************************************************************************
 * @brief      Reset counter value to Zero upon TMRCTL.EN from 1 to 0
 *
 * @param[in]  TIMERx:  Select the timer module
 *
 * @return     none
 *
 ******************************************************************************/
#define TIMER_DisableCounterHold(TIMERx)    ((TIMERx)->TMRCTL.bit.HOLD = TMRCTL_BIT_HOLD_DISABLE)




/******************************************************************************
 * @brief      Enabel ADCSOC generation whenever TMRCNT counts down to 0
 *
 * @param[in]  TIMERx:  Select the timer module
 *
 * @return     none
 *
 ******************************************************************************/
#define TIMER_EnableADCSOC(TIMERx)          ((TIMERx)->TMRCTL.bit.ADCSOCEN = TMRCTL_BIT_ADCSOCEN_ENABLE)




/******************************************************************************
 * @brief      Do not generate ADCSOC
 *
 * @param[in]  TIMERx:  Select the timer module
 *
 * @return     none
 *
 ******************************************************************************/
#define TIMER_DisableADCSOC(TIMERx)         ((TIMERx)->TMRCTL.bit.ADCSOCEN = TMRCTL_BIT_ADCSOCEN_DISABLE)




/******************************************************************************
 * @brief      Enable generate PWMSYNC signal whenever TMRCNT counts down to 0
 *
 * @param[in]  TIMERx:  Select the timer module
 *
 * @return     none
 *
 ******************************************************************************/
#define TIMER_EnablePWMSync(TIMERx)         ((TIMERx)->TMRCTL.bit.PWMSYNCEN = TMRCTL_BIT_PWMSYNCEN_ENABLE)




/******************************************************************************
 * @brief      Do not generate PWMSYNC signal
 *
 * @param[in]  TIMERx:  Select the timer module
 *
 * @return     none
 *
 ******************************************************************************/
#define TIMER_DisablePWMSync(TIMERx)        ((TIMERx)->TMRCTL.bit.PWMSYNCEN = TMRCTL_BIT_PWMSYNCEN_DISABLE)




/******************************************************************************
 * @brief      Enable Timer
 *
 * @param[in]  TIMERx:  Select the timer module
 *
 * @return     none
 *
 ******************************************************************************/
#define TIMER_Run(TIMERx)                   ((TIMERx)->TMRCTL.all |= TMRCTL_ALL_EN_ENABLE)




/******************************************************************************
 * @brief      Disable Timer
 *
 * @param[in]  TIMERx:  Select the timer module
 *
 * @return     none
 *
 ******************************************************************************/
#define TIMER_Stop(TIMERx)                  ((TIMERx)->TMRCTL.all &= (~TMRCTL_ALL_EN_ENABLE))




/******************************************************************************
 * @brief      Set Timer Re-Load value
 *
 * @param[in]  TIMERxb       :  Select the timer module
 * @param[in]  u32ReloadValue:  Reload value
 *
 * @return     none
 *
 ******************************************************************************/
#define TIMER_SetReloadValue(TIMERx,u32ReloadValue)   ((TIMERx)->TMRRELOAD.all = (u32ReloadValue))




/******************************************************************************
 * @brief      Enable Timer interrupt
 *
 * @param[in]  TIMERx:  Select the timer module
 *
 * @return     none
 *
 ******************************************************************************/
#define TIMER_EnableInt(TIMERx)             ((TIMERx)->TMRIE.all |= TMRIE_ALL_INT_ENABLE)




/******************************************************************************
 * @brief      Disable Timer interrupt
 *
 * @param[in]  TIMERx:  Select the timer module
 *
 * @return     none
 *
 ******************************************************************************/
#define TIMER_DisableInt(TIMERx)             ((TIMERx)->TMRIE.bit.INT = TMRIE_BIT_INT_DISABLE)




/******************************************************************************
 * @brief      Clear Timer interrupt
 *
 * @param[in]  TIMERx:  Select the timer module
 *
 * @return     none
 *
 ******************************************************************************/
#define TIMER_ClearInt(TIMERx)              ((TIMERx)->TMRIC.all = TMRIC_ALL_INT_CLEAR)




/******************************************************************************
 * @brief      Get Timer interrupt flag
 *
 * @param[in]  TIMERx:  Select the timer module
 *
 * @return     0 - Timer interrupt not occurred
 *             1 - Timer interrupt occurred
 *
 ******************************************************************************/
#define TIMER_GetIntFlag(TIMERx)            ((TIMERx)->TMRIF.bit.INT)




/**
 *  @brief  TIMER Public Function Declaration
 */
void TIMER_Init(TIMER_REGS* TIMERx, uint32_t u32TimerPeriodMs);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* TIMER_H */


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
