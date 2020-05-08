/*******************************************************************************
* @file     power.h
* @brief    POWER driver header file.
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


#ifndef POWER_H
#define POWER_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1168.h"




/**
 *  @brief  BOD Interrupt events definitions
 */
typedef enum
{
  BOD_INT_VDD12_TOO_LOW0      = 0,      /*!< 1.2V Too-Low level 0 */
  BOD_INT_VDD12_TOO_LOW1      = 1,      /*!< 1.2V Too-Low level 1 */
  BOD_INT_VDD12_TOO_HIGH      = 2,      /*!< 1.2V Too-High        */
  BOD_INT_VDD33_TOO_LOW       = 3,      /*!< 3.3V Too-Low         */
  BOD_INT_VDD33_TOO_HIGH      = 4,      /*!< 3.3V Too-Low         */
} POWER_BODIntEnum;




/**
 *  @brief  BOD VDD33 Too-High Threshold definitions
 */
typedef enum
{
  BOD_VDD33H_3dot31_V      = 0,      /*!< 3.31V     */
  BOD_VDD33H_3dot42_V      = 1,      /*!< 3.42V     */
  BOD_VDD33H_3dot53_V      = 2,      /*!< 3.53V     */
  BOD_VDD33H_3dot66_V      = 3,      /*!< 3.66V     */
  BOD_VDD33H_3dot79_V      = 4,      /*!< 3.79V     */
  BOD_VDD33H_3dot93_V      = 5,      /*!< 3.93V     */
  BOD_VDD33H_4dot08_V      = 6,      /*!< 4.08V     */
  BOD_VDD33H_4dot24_V      = 7,      /*!< 4.24V     */
} POWER_VDD33HEnum;




/**
 *  @brief  BOD VDD33 Too-Low Threshold definitions
 */
typedef enum
{
  BOD_VDD33L_2dot58_V      = 0,      /*!< 2.58V     */
  BOD_VDD33L_2dot65_V      = 1,      /*!< 2.65V     */
  BOD_VDD33L_2dot72_V      = 2,      /*!< 2.72V     */
  BOD_VDD33L_2dot79_V      = 3,      /*!< 2.79V     */
  BOD_VDD33L_2dot86_V      = 4,      /*!< 2.86V     */
  BOD_VDD33L_2dot94_V      = 5,      /*!< 2.94V     */
  BOD_VDD33L_3dot03_V      = 6,      /*!< 3.03V     */
  BOD_VDD33L_3dot12_V      = 7,      /*!< 3.12V     */
} POWER_VDD33LEnum;




/**
 *  @brief  BOD VDD12 Too-High Threshold definitions
 */
typedef enum
{
  BOD_VDD12H_1dot31_V      = 0,      /*!< 1.31V     */
  BOD_VDD12H_1dot33_V      = 1,      /*!< 1.33V     */
  BOD_VDD12H_1dot36_V      = 2,      /*!< 1.36V     */
  BOD_VDD12H_1dot38_V      = 3,      /*!< 1.38V     */
  BOD_VDD12H_1dot41_V      = 4,      /*!< 1.41V     */
  BOD_VDD12H_1dot43_V      = 5,      /*!< 1.43V     */
  BOD_VDD12H_1dot46_V      = 6,      /*!< 1.46V     */
  BOD_VDD12H_1dot49_V      = 7,      /*!< 1.49V     */
} POWER_VDD12HEnum;




/**
 *  @brief  BOD VDD12 Too-Low Threshold definitions
 */
typedef enum
{
  BOD_VDD12L_0dot94_V      = 0,      /*!< 0.94V     */
  BOD_VDD12L_0dot97_V      = 1,      /*!< 0.97V     */
  BOD_VDD12L_0dot99_V      = 2,      /*!< 0.99V     */
  BOD_VDD12L_1dot02_V      = 3,      /*!< 1.02V     */
  BOD_VDD12L_1dot04_V      = 4,      /*!< 1.04V     */
  BOD_VDD12L_1dot07_V      = 5,      /*!< 1.07V     */
  BOD_VDD12L_1dot10_V      = 6,      /*!< 1.10V     */
  BOD_VDD12L_1dot14_V      = 7,      /*!< 1.14V     */
} POWER_VDD12LEnum;




/******************************************************************************
 * @brief      Enable BOD interrupt event
 *
 * @param[in]  eBODInt:  Select the BOD event
 *                       Please go to POWER_BODIntEnum details
 *
 * @return     none
 *
 ******************************************************************************/
#define POWER_EnableBODInt(eBODInt)         (POWER->BODIE.all |= (0x1UL << (eBODInt)))




/******************************************************************************
 * @brief      Disable BOD interrupt event
 *
 * @param[in]  eBODInt:  Select the BOD event
 *                       Please go to POWER_BODIntEnum details
 *
 * @return     none
 *
 ******************************************************************************/
#define POWER_DisableBODInt(eBODInt)        (POWER->BODIE.all &= ~(0x1UL << (eBODInt)))




/******************************************************************************
 * @brief      Clear BOD interrupt flag
 *
 * @param[in]  eBODInt:  Select the BOD event
 *                       Please go to POWER_BODIntEnum details
 *
 * @return     none
 *
 ******************************************************************************/
#define POWER_ClearBODInt(eBODInt)          (POWER->BODIC.all = (0x1UL << (eBODInt)))




/******************************************************************************
 * @brief      Clear global BOD interrupt flag
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define POWER_ClearBODGlobalInt()           (POWER->BODIC.all = BODIC_ALL_BODINT_CLEAR)




/******************************************************************************
 * @brief      Get BOD interrupt flag
 *
 * @param[in]  eBODInt:  Select the BOD event
 *                       Please go to POWER_BODIntEnum details
 *
 * @return     0 - The specified BOD interrupt not occurred
 *             1 - The specified BOD interrupt occurred
 *
 ******************************************************************************/
#define POWER_GetBODIntFlag(eBODInt)        ((POWER->BODIF.all & (0x1UL << (eBODInt))) >> (eBODInt))




/******************************************************************************
 * @brief      Get BOD interrupt flag
 *
 * @param[in]  none
 *
 * @return     0 - BOD interrupt not occurred
 *             1 - BOD interrupt occurred
 *
 ******************************************************************************/
#define POWER_GetBODGlobalIntFlag()         (POWER->BODIF.bit.BODINT)




/******************************************************************************
 * @brief      Force system go into deep sleep mode
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define POWER_DeepSleepMode()               (POWER->DPSLPKEY.all = 0x51EE9)




/******************************************************************************
 * @brief      Enable write access to the protected POWER registers
 *
 * @param[in]  none
 *
 * @return     none
 * 
 ******************************************************************************/
#define POWER_WALLOW()                      (POWER->PWRREGKEY.all = 0x1ACCE551)




/******************************************************************************
 * @brief      Disable write access to the protected POWER registers
 *
 * @param[in]  none
 *
 * @return     none
 * 
 ******************************************************************************/
#define POWER_WDIS()                        (POWER->PWRREGKEY.all = 0x0)




/**
 *  @brief Power Public Function Declaration
 */
void POWER_VDD12HBODInit(POWER_VDD12HEnum eAssert, POWER_VDD12HEnum eDeassert);
void POWER_VDD12L0BODInit(POWER_VDD12LEnum eAssert, POWER_VDD12LEnum eDeassert);
void POWER_VDD12L1BODInit(POWER_VDD12LEnum eAssert, POWER_VDD12LEnum eDeassert);
void POWER_VDD33HBODInit(POWER_VDD33HEnum eAssert, POWER_VDD33HEnum eDeassert);
void POWER_VDD33LBODInit(POWER_VDD33LEnum eAssert, POWER_VDD33LEnum eDeassert);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* POWER_H */


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
