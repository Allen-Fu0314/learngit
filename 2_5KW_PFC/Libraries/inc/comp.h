/*******************************************************************************
* @file     comp.h
* @brief    Comparator driver header file.
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


#ifndef COMP_H
#define COMP_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1168.h"




/**
 *  @brief  Comparator selection
 */
typedef enum
{
  COMP_0_LO             = 0,                /*!< COMP0L   */
  COMP_0_HI             = 1,                /*!< COMP0H   */
  
  COMP_1_LO             = 2,                /*!< COMP1L   */
  COMP_1_HI             = 3,                /*!< COMP1H   */
  
  COMP_2_LO             = 4,                /*!< COMP2L   */
  COMP_2_HI             = 5,                /*!< COMP2H   */
  
  COMP_3_LO             = 6,                /*!< COMP3L   */
  COMP_3_HI             = 7,                /*!< COMP3H   */
  
  COMP_4_LO             = 8,                /*!< COMP4L   */
  COMP_4_HI             = 9,                /*!< COMP4H   */
} COMP_ComparatorSelEnum;




/**
 *  @brief  Comparator Channel Input selection
 */
typedef enum
{
  COMP0_FROM_PGA0N_OUT  = 0x00,             /*!< Negative output of PGA0 */
  COMP0_FROM_PGA0P_OUT  = 0x01,             /*!< Positive output of PGA0 */
  COMP0_FROM_ADC0       = 0x02,             /*!< ADC0 input from GPIO0   */
  COMP0_FROM_ADC8       = 0x03,             /*!< ADC8 input from GPIO8   */
  
  COMP1_FROM_PGA1N_OUT  = 0x10,             /*!< Negative output of PGA1 */
  COMP1_FROM_PGA1P_OUT  = 0x11,             /*!< Positive output of PGA1 */
  COMP1_FROM_ADC0       = 0x12,             /*!< ADC0 input from GPIO0   */
  COMP1_FROM_ADC8       = 0x13,             /*!< ADC8 input from GPIO8   */
  
  COMP2_FROM_PGA2N_OUT  = 0x20,             /*!< Negative output of PGA2 */
  COMP2_FROM_PGA2P_OUT  = 0x21,             /*!< Positive output of PGA2 */
  COMP2_FROM_ADC0       = 0x22,             /*!< ADC0 input from GPIO0   */
  COMP2_FROM_ADC8       = 0x23,             /*!< ADC8 input from GPIO8   */
  
  COMP3_FROM_ADC0       = 0x30,             /*!< ADC0 input from GPIO0   */
  COMP3_FROM_ADC4       = 0x31,             /*!< ADC4 input from GPIO4   */
  COMP3_FROM_ADC8       = 0x32,             /*!< ADC8 input from GPIO8   */
  COMP3_FROM_ADC12      = 0x33,             /*!< ADC12 input from GPIO12 */
  
  COMP4_FROM_ADC2       = 0x40,             /*!< ADC2 input from GPIO2   */
  COMP4_FROM_ADC6       = 0x41,             /*!< ADC6 input from GPIO6   */
  COMP4_FROM_ADC10      = 0x42,             /*!< ADC10 input from GPIO10 */
  COMP4_FROM_ADC14      = 0x43,             /*!< ADC14 input from GPIO14 */
} COMP_CHSelEnum;




/**
 *  @brief  Comparator Output selection
 */
typedef enum
{
  COMP_OUTPUT_ORIGINAL                        = 0,    /*!< Original output                                                    */
  COMP_OUTPUT_SYNC                            = 1,    /*!< Synchronous output with PWM clock                                  */
  COMP_OUTPUT_FILTERED                        = 2,    /*!< Digital filter output                                              */
  COMP_OUTPUT_LATCHED                         = 3,    /*!< Latched digital filter output                                      */
  COMP_OUTPUT_ORIGINAL_OR_LATCHED             = 4,    /*!< Original output or Latched digital filter output                   */
  COMP_OUTPUT_SYNC_OR_LATCHED                 = 5,    /*!< Synchronous output with PWM clock or Latched digital filter output */
  COMP_OUTPUT_FILTERED_OR_LATCHED             = 6,    /*!< Digital filter output or the latched one                           */
  COMP_OUTPUT_ORIGINAL_OR_FILTERED_OR_LATCHED = 7,    /*!< Original output or Synchronous output with PWM clock or Latched digital filter output */
} COMP_OutputSelEnum;




/**
 *  @brief  Comparator Hysteresis selection
 */
typedef enum
{
  COMP_HYST_0_MV        = 0,                /*!< Hysteresis 0  mV */
  COMP_HYST_12_MV       = 1,                /*!< Hysteresis 12 mV */
  COMP_HYST_24_MV       = 2,                /*!< Hysteresis 24 mV */
  COMP_HYST_36_MV       = 3,                /*!< Hysteresis 36 mV */
} COMP_HystSelEnum;




/**
 *  @brief  DAC Selection
 */
typedef enum
{
  DAC0                  = 0,                /*!< DAC0     */
  DAC1                  = 1,                /*!< DAC1     */
  DAC2                  = 2,                /*!< DAC2     */
  DAC3                  = 3,                /*!< DAC3     */
} COMP_DACSelEnum;




/******************************************************************************
 * @brief      Enable Comparator
 *
 * @param[in]  eComp:  Select the comparator
 *                     See COMP_ComparatorSelEnum for details
 *                     COMP_x_LO is for too low protection
 *                     COMP_x_HI is for too high protection
 *
 *                     COMP_x_LO = 1 when input value < Configure value
 *                     COMP_x_HI = 1 when input value > Configure value
 * @return     none
 *
 * @example    COMP_Enable(COMP_2_LO);
 *
 ******************************************************************************/
__STATIC_INLINE void COMP_Enable(COMP_ComparatorSelEnum eCOMP)
{
  switch(eCOMP)
  {
    case COMP_0_LO:
      COMP->COMP0CTL.bit.ENL = COMP0CTL_BIT_ENL_ENABLE;
      break;
    
    case COMP_0_HI:
      COMP->COMP0CTL.bit.ENH = COMP0CTL_BIT_ENH_ENABLE;
      break;
    
    case COMP_1_LO:
      COMP->COMP1CTL.bit.ENL = COMP1CTL_BIT_ENL_ENABLE;
      break;
    
    case COMP_1_HI:
      COMP->COMP1CTL.bit.ENH = COMP1CTL_BIT_ENH_ENABLE;
      break;
    
    case COMP_2_LO:
      COMP->COMP2CTL.bit.ENL = COMP2CTL_BIT_ENL_ENABLE;
      break;
    
    case COMP_2_HI:
      COMP->COMP2CTL.bit.ENH = COMP2CTL_BIT_ENH_ENABLE;
      break;
    
    case COMP_3_LO:
      COMP->COMP3CTL.bit.ENL = COMP3CTL_BIT_ENL_ENABLE;
      break;
    
    case COMP_3_HI:
      COMP->COMP3CTL.bit.ENH = COMP3CTL_BIT_ENH_ENABLE;
      break;
    
    case COMP_4_LO:
      COMP->COMP4CTL.bit.ENL = COMP4CTL_BIT_ENL_ENABLE;
      break;
    
    case COMP_4_HI:
      COMP->COMP4CTL.bit.ENH = COMP4CTL_BIT_ENH_ENABLE;
      break;
  }
}




/******************************************************************************
 * @brief      Disable Comparator
 *
 * @param[in]  eCOMP:  Select the comparator
 *                     See COMP_ComparatorSelEnum for details
 *                     COMP_x_LO is for too low protection
 *                     COMP_x_HI is for too high protection
 *
 *                     COMP_x_LO = 1 when input value < Configure value
 *                     COMP_x_HI = 1 when input value > Configure value
 *
 * @return     none
 *
 * @example    COMP_Disable(COMP_2_LO);
 *
 ******************************************************************************/
__STATIC_INLINE void COMP_Disable(COMP_ComparatorSelEnum eCOMP)
{
  switch(eCOMP)
  {
    case COMP_0_LO:
      COMP->COMP0CTL.bit.ENL = COMP0CTL_BIT_ENL_DISABLE;
      break;
    
    case COMP_0_HI:
      COMP->COMP0CTL.bit.ENH = COMP0CTL_BIT_ENH_DISABLE;
      break;
    
    case COMP_1_LO:
      COMP->COMP1CTL.bit.ENL = COMP1CTL_BIT_ENL_DISABLE;
      break;
    
    case COMP_1_HI:
      COMP->COMP1CTL.bit.ENH = COMP1CTL_BIT_ENH_DISABLE;
      break;
    
    case COMP_2_LO:
      COMP->COMP2CTL.bit.ENL = COMP2CTL_BIT_ENL_DISABLE;
      break;
    
    case COMP_2_HI:
      COMP->COMP2CTL.bit.ENH = COMP2CTL_BIT_ENH_DISABLE;
      break;
    
    case COMP_3_LO:
      COMP->COMP3CTL.bit.ENL = COMP3CTL_BIT_ENL_DISABLE;
      break;
    
    case COMP_3_HI:
      COMP->COMP3CTL.bit.ENH = COMP3CTL_BIT_ENH_DISABLE;
      break;
    
    case COMP_4_LO:
      COMP->COMP4CTL.bit.ENL = COMP4CTL_BIT_ENL_DISABLE;
      break;
    
    case COMP_4_HI:
      COMP->COMP4CTL.bit.ENH = COMP4CTL_BIT_ENH_DISABLE;
      break;
  }
}




/******************************************************************************
 * @brief      Reset Comparator Filter
 *
 * @param[in]  eCOMP:  Select the comparator
 *                     See COMP_ComparatorSelEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
__STATIC_INLINE void COMP_ResetFilter(COMP_ComparatorSelEnum eCOMP)
{
  switch(eCOMP)
  {
    case COMP_0_LO:
      COMP->COMP0LCTL.all |= COMP0LCTL_ALL_FLTRST_RESET;
      break;
    
    case COMP_0_HI:
      COMP->COMP0HCTL.all |= COMP0HCTL_ALL_FLTRST_RESET;
      break;
    
    case COMP_1_LO:
      COMP->COMP1LCTL.all |= COMP1LCTL_ALL_FLTRST_RESET;
      break;
    
    case COMP_1_HI:
      COMP->COMP1HCTL.all |= COMP1HCTL_ALL_FLTRST_RESET;
      break;
    
    case COMP_2_LO:
      COMP->COMP2LCTL.all |= COMP2LCTL_ALL_FLTRST_RESET;
      break;
    
    case COMP_2_HI:
      COMP->COMP2HCTL.all |= COMP2HCTL_ALL_FLTRST_RESET;
      break;
    
    case COMP_3_LO:
      COMP->COMP3LCTL.all |= COMP3LCTL_ALL_FLTRST_RESET;
      break;
    
    case COMP_3_HI:
      COMP->COMP3HCTL.all |= COMP3HCTL_ALL_FLTRST_RESET;
      break;
    
    case COMP_4_LO:
      COMP->COMP4LCTL.all |= COMP4LCTL_ALL_FLTRST_RESET;
      break;
    
    case COMP_4_HI:
      COMP->COMP4HCTL.all |= COMP4HCTL_ALL_FLTRST_RESET;
      break;
  }
}




/******************************************************************************
 * @brief      Enable comparator output invert
 *
 * @param[in]  eCOMP:  Select the comparator
 *                     See COMP_ComparatorSelEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
__STATIC_INLINE void COMP_EnableOutputInvert(COMP_ComparatorSelEnum eCOMP)
{
  switch(eCOMP)
  {
    case COMP_0_LO:
      COMP->COMP0LCTL.bit.POL4PWM = COMP0LCTL_BIT_POL4PWM_ACTIVE_LOW;
      break;
    
    case COMP_0_HI:
      COMP->COMP0HCTL.bit.POL4PWM = COMP0HCTL_BIT_POL4PWM_ACTIVE_LOW;
      break;
    
    case COMP_1_LO:
      COMP->COMP1LCTL.bit.POL4PWM = COMP1LCTL_BIT_POL4PWM_ACTIVE_LOW;
      break;
    
    case COMP_1_HI:
      COMP->COMP1HCTL.bit.POL4PWM = COMP1HCTL_BIT_POL4PWM_ACTIVE_LOW;
      break;
    
    case COMP_2_LO:
      COMP->COMP2LCTL.bit.POL4PWM = COMP2LCTL_BIT_POL4PWM_ACTIVE_LOW;
      break;
    
    case COMP_2_HI:
      COMP->COMP2HCTL.bit.POL4PWM = COMP2HCTL_BIT_POL4PWM_ACTIVE_LOW;
      break;
    
    case COMP_3_LO:
      COMP->COMP3LCTL.bit.POL4PWM = COMP3LCTL_BIT_POL4PWM_ACTIVE_LOW;
      break;
    
    case COMP_3_HI:
      COMP->COMP3HCTL.bit.POL4PWM = COMP3HCTL_BIT_POL4PWM_ACTIVE_LOW;
      break;
    
    case COMP_4_LO:
      COMP->COMP4LCTL.bit.POL4PWM = COMP4LCTL_BIT_POL4PWM_ACTIVE_LOW;
      break;
    
    case COMP_4_HI:
      COMP->COMP4HCTL.bit.POL4PWM = COMP4HCTL_BIT_POL4PWM_ACTIVE_LOW;
      break;
  }
}




/******************************************************************************
 * @brief      Disable comparator output invert
 *
 * @param[in]  eCOMP:  Select the comparator
 *                     See COMP_ComparatorSelEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
__STATIC_INLINE void COMP_DisableOutputInvert(COMP_ComparatorSelEnum eCOMP)
{
  switch(eCOMP)
  {
    case COMP_0_LO:
      COMP->COMP0LCTL.bit.POL4PWM = COMP0LCTL_BIT_POL4PWM_ACTIVE_HIGH;
      break;
    
    case COMP_0_HI:
      COMP->COMP0HCTL.bit.POL4PWM = COMP0HCTL_BIT_POL4PWM_ACTIVE_HIGH;
      break;
    
    case COMP_1_LO:
      COMP->COMP1LCTL.bit.POL4PWM = COMP1LCTL_BIT_POL4PWM_ACTIVE_HIGH;
      break;
    
    case COMP_1_HI:
      COMP->COMP1HCTL.bit.POL4PWM = COMP1HCTL_BIT_POL4PWM_ACTIVE_HIGH;
      break;
    
    case COMP_2_LO:
      COMP->COMP2LCTL.bit.POL4PWM = COMP2LCTL_BIT_POL4PWM_ACTIVE_HIGH;
      break;
    
    case COMP_2_HI:
      COMP->COMP2HCTL.bit.POL4PWM = COMP2HCTL_BIT_POL4PWM_ACTIVE_HIGH;
      break;
    
    case COMP_3_LO:
      COMP->COMP3LCTL.bit.POL4PWM = COMP3LCTL_BIT_POL4PWM_ACTIVE_HIGH;
      break;
    
    case COMP_3_HI:
      COMP->COMP3HCTL.bit.POL4PWM = COMP3HCTL_BIT_POL4PWM_ACTIVE_HIGH;
      break;
    
    case COMP_4_LO:
      COMP->COMP4LCTL.bit.POL4PWM = COMP4LCTL_BIT_POL4PWM_ACTIVE_HIGH;
      break;
    
    case COMP_4_HI:
      COMP->COMP4HCTL.bit.POL4PWM = COMP4HCTL_BIT_POL4PWM_ACTIVE_HIGH;
      break;
  }
}




/******************************************************************************
 * @brief      Enable latched filter output status cleared by PWMSYNC
 *
 * @param[in]  eCOMP:  Select the comparator
 *                     See COMP_ComparatorSelEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
__STATIC_INLINE void COMP_EnablePWMSyncClearFilterOutputStatus(COMP_ComparatorSelEnum eCOMP)
{
  switch(eCOMP)
  {
    case COMP_0_LO:
      COMP->COMP0LCTL.bit.SYNCCLREN = COMP0LCTL_BIT_SYNCCLREN_ENABLE;
      break;
    
    case COMP_0_HI:
      COMP->COMP0HCTL.bit.SYNCCLREN = COMP0HCTL_BIT_SYNCCLREN_ENABLE;
      break;
    
    case COMP_1_LO:
      COMP->COMP1LCTL.bit.SYNCCLREN = COMP1LCTL_BIT_SYNCCLREN_ENABLE;
      break;
    
    case COMP_1_HI:
      COMP->COMP1HCTL.bit.SYNCCLREN = COMP1HCTL_BIT_SYNCCLREN_ENABLE;
      break;
    
    case COMP_2_LO:
      COMP->COMP2LCTL.bit.SYNCCLREN = COMP2LCTL_BIT_SYNCCLREN_ENABLE;
      break;
    
    case COMP_2_HI:
      COMP->COMP2HCTL.bit.SYNCCLREN = COMP2HCTL_BIT_SYNCCLREN_ENABLE;
      break;
    
    case COMP_3_LO:
      COMP->COMP3LCTL.bit.SYNCCLREN = COMP3LCTL_BIT_SYNCCLREN_ENABLE;
      break;
    
    case COMP_3_HI:
      COMP->COMP3HCTL.bit.SYNCCLREN = COMP3HCTL_BIT_SYNCCLREN_ENABLE;
      break;
    
    case COMP_4_LO:
      COMP->COMP4LCTL.bit.SYNCCLREN = COMP4LCTL_BIT_SYNCCLREN_ENABLE;
      break;
    
    case COMP_4_HI:
      COMP->COMP4HCTL.bit.SYNCCLREN = COMP4HCTL_BIT_SYNCCLREN_ENABLE;
      break;
  }
}




/******************************************************************************
 * @brief      Disable latched filter output status cleared by PWMSYNC
 *
 * @param[in]  eCOMP:  Select the comparator
 *                     See COMP_ComparatorSelEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
__STATIC_INLINE void COMP_DisablePWMSyncClearFilterOutputStatus(COMP_ComparatorSelEnum eCOMP)
{
  switch(eCOMP)
  {
    case COMP_0_LO:
      COMP->COMP0LCTL.bit.SYNCCLREN = COMP0LCTL_BIT_SYNCCLREN_DISABLE;
      break;
    
    case COMP_0_HI:
      COMP->COMP0HCTL.bit.SYNCCLREN = COMP0HCTL_BIT_SYNCCLREN_DISABLE;
      break;
    
    case COMP_1_LO:
      COMP->COMP1LCTL.bit.SYNCCLREN = COMP1LCTL_BIT_SYNCCLREN_DISABLE;
      break;
    
    case COMP_1_HI:
      COMP->COMP1HCTL.bit.SYNCCLREN = COMP1HCTL_BIT_SYNCCLREN_DISABLE;
      break;
    
    case COMP_2_LO:
      COMP->COMP2LCTL.bit.SYNCCLREN = COMP2LCTL_BIT_SYNCCLREN_DISABLE;
      break;
    
    case COMP_2_HI:
      COMP->COMP2HCTL.bit.SYNCCLREN = COMP2HCTL_BIT_SYNCCLREN_DISABLE;
      break;
    
    case COMP_3_LO:
      COMP->COMP3LCTL.bit.SYNCCLREN = COMP3LCTL_BIT_SYNCCLREN_DISABLE;
      break;
    
    case COMP_3_HI:
      COMP->COMP3HCTL.bit.SYNCCLREN = COMP3HCTL_BIT_SYNCCLREN_DISABLE;
      break;
    
    case COMP_4_LO:
      COMP->COMP4LCTL.bit.SYNCCLREN = COMP4LCTL_BIT_SYNCCLREN_DISABLE;
      break;
    
    case COMP_4_HI:
      COMP->COMP4HCTL.bit.SYNCCLREN = COMP4HCTL_BIT_SYNCCLREN_DISABLE;
      break;
  }
}




/******************************************************************************
 * @brief      Select the synchronous output from PWM
 *
 * @param[in]  eCOMP    :  Select the comparator
 *                         See COMP_ComparatorSelEnum for details
 * @param[in]  ePWMIndex:  PWM module index
 *                         Please go to PWM_SelEnum for details
 *
 * @return     none
 *
 * @example    COMP_SetSyncEvent(COMP_0_LO, SEL_PWM0);
 *
 ******************************************************************************/
__STATIC_INLINE void COMP_SetSyncEvent(COMP_ComparatorSelEnum eCOMP, uint8_t ePWMIndex)
{
  switch(eCOMP)
  {
    case COMP_0_LO:
    case COMP_0_HI:
      COMP->COMP0CTL.bit.SYNCSEL = ePWMIndex;
      break;
    
    case COMP_1_LO:
    case COMP_1_HI:
      COMP->COMP1CTL.bit.SYNCSEL = ePWMIndex;
      break;
    
    case COMP_2_LO:
    case COMP_2_HI:
      COMP->COMP2CTL.bit.SYNCSEL = ePWMIndex;
      break;
    
    case COMP_3_LO:
    case COMP_3_HI:
      COMP->COMP3CTL.bit.SYNCSEL = ePWMIndex;
      break;
    
    case COMP_4_LO:
    case COMP_4_HI:
      COMP->COMP4CTL.bit.SYNCSEL = ePWMIndex;
      break;
  }
}



/******************************************************************************
 * @brief      Clear the latched filter output status
 *
 * @param[in]  eCOMP:  Select the comparator
 *
 * @return     none
 *
 ******************************************************************************/
#define COMP_ClearFilterOutputStatus(eCOMP) ((COMP->COMPSTSCLR.all & (0x1UL<<(eCOMP)))>>(eCOMP))




/******************************************************************************
 * @brief      Clear all latched filter output status flag
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define COMP_ClearAllFilterOutputStatus()   (COMP->COMPSTSCLR.all = 0x3FF)




/******************************************************************************
 * @brief      Get the latched filter output status
 *
 * @param[in]  eCOMP:  Select the comparator
 *
 * @return     0 or 1
 *
 ******************************************************************************/
#define COMP_GetFilterOutputStatus(eCOMP)   ((COMP->COMPSTS.all & (0x1UL<<(eCOMP)))>>(eCOMP))




/******************************************************************************
 * @brief      Get the filter output status
 *
 * @param[in]  eCOMP:  Select the comparator
 *
 * @return     0 or 1
 *
 ******************************************************************************/
#define COMP_GetRawFilterOutputStatus(eCOMP)  ((COMP->COMPFLTOUT.all & (0x1UL<<(eCOMP)))>>(eCOMP))




/******************************************************************************
 * @brief      Enable DAC
 *
 * @param[in]  eDACSel:  Select the DAC
 *
 * @return     none
 *
 ******************************************************************************/
__STATIC_INLINE void COMP_EnableDAC(COMP_DACSelEnum eDACSel)
{
  switch(eDACSel)
  {
    case DAC0:
      COMP->DAC0CTL.bit.EN = DAC0CTL_BIT_EN_ENABLE;
      break;
    
    case DAC1:
      COMP->DAC1CTL.bit.EN = DAC1CTL_BIT_EN_ENABLE;
      break;
    
    case DAC2:
      COMP->DAC2CTL.bit.EN = DAC2CTL_BIT_EN_ENABLE;
      break;
    
    case DAC3:
      COMP->DAC3CTL.bit.EN = DAC3CTL_BIT_EN_ENABLE;
      break;
  }
}




/******************************************************************************
 * @brief      Disable DAC
 *
 * @param[in]  eDACSel:  Select the DAC
 *
 * @return     none
 *
 ******************************************************************************/
__STATIC_INLINE void COMP_DisableDAC(COMP_DACSelEnum eDACSel)
{
  switch(eDACSel)
  {
    case DAC0:
      COMP->DAC0CTL.bit.EN = DAC0CTL_BIT_EN_DISABLE;
      break;
    
    case DAC1:
      COMP->DAC1CTL.bit.EN = DAC1CTL_BIT_EN_DISABLE;
      break;
    
    case DAC2:
      COMP->DAC2CTL.bit.EN = DAC2CTL_BIT_EN_DISABLE;
      break;
    
    case DAC3:
      COMP->DAC3CTL.bit.EN = DAC3CTL_BIT_EN_DISABLE;
      break;
  }
}




/******************************************************************************
 * @brief      Set DAC value
 *
 * @param[in]  eDACSel:  Select the DAC
 * @param[in]  u32Code:  Range from 0(0 Voltage) ~ 1023 (3.3 Voltage)
 *
 * @return     none
 *
 ******************************************************************************/
__STATIC_INLINE void COMP_SetDACValue10Bit(COMP_DACSelEnum eDACSel, uint32_t u32Code)
{
  switch(eDACSel)
  {
    case DAC0:
      COMP->DAC0CODE.all = u32Code;
      break;
    
    case DAC1:
      COMP->DAC1CODE.all = u32Code;
      break;
    
    case DAC2:
      COMP->DAC2CODE.all = u32Code;
      break;
    
    case DAC3:
      COMP->DAC3CODE.all = u32Code;
      break;
  }
}




/******************************************************************************
 * @brief      Set DAC value in milli voltage
 *
 * @param[in]  eDACSel   :  Select the DAC
 * @param[in]  i32ValueMV:  Range from 0(0 voltage) ~ 3300 (3300 mV = 3.3 V)
 *
 * @return     none
 *
 ******************************************************************************/
__STATIC_INLINE void COMP_SetDACVoltage(COMP_DACSelEnum eDACSel, int32_t i32ValueMV)
{
  int32_t i32Val;
  i32Val = (i32ValueMV * 1024) / 3300;
  
  if(i32Val > 1023) i32Val = 1023;
  if(i32Val < 0)    i32Val = 0;
  
  COMP_SetDACValue10Bit(eDACSel, i32Val);
}




/******************************************************************************
 * @brief      Select the PWM synchronous output signal for DAC
 *
 * @param[in]  eDACSel  :  Select the DAC
 *                         See COMP_DACSelEnum for details
 * @param[in]  ePWMIndex:  PWM module index
 *                         Please go to PWM_SelEnum for details
 *
 * @return     none
 *
 * @example    COMP_SetDACSyncEvent(DAC0, SEL_PWM0);
 *
 ******************************************************************************/
__STATIC_INLINE void COMP_SetDACSyncEvent(COMP_DACSelEnum eDACSel, uint8_t ePWMIndex)
{
  switch(eDACSel)
  {
    case DAC0:
      COMP->DAC0CTL.bit.SYNCSEL = ePWMIndex;
      break;
    
    case DAC1:
      COMP->DAC1CTL.bit.SYNCSEL = ePWMIndex;
      break;
    
    case DAC2:
      COMP->DAC2CTL.bit.SYNCSEL = ePWMIndex;
      break;
    
    case DAC3:
      COMP->DAC3CTL.bit.SYNCSEL = ePWMIndex;
      break;
  }
}




/******************************************************************************
 * @brief      Set DAC Code Load Mode
 *
 * @param[in]  eDACSel  :  Select the DAC
 * @param[in]  eLoadMode:  DAC code load mode
 *                         Please go to DAC0CTL_BIT_CODELOAD ~ DAC3CTL_BIT_CODELOAD for details
 *
 * @return     none
 *
 ******************************************************************************/
__STATIC_INLINE void COMP_SetDACCodeLoadTiming(COMP_DACSelEnum eDACSel, uint8_t eLoadMode)
{
  switch(eDACSel)
  {
    case DAC0:
      COMP->DAC0CTL.bit.CODELOAD = eLoadMode;
      break;
    
    case DAC1:
      COMP->DAC1CTL.bit.CODELOAD = eLoadMode;
      break;
    
    case DAC2:
      COMP->DAC2CTL.bit.CODELOAD = eLoadMode;
      break;
    
    case DAC3:
      COMP->DAC3CTL.bit.CODELOAD = eLoadMode;
      break;
  }
}




/******************************************************************************
 * @brief      Enable DAC Buffer
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define COMP_EnableDACBuffer()              (COMP->DACBUFCTL.bit.EN = DACBUFCTL_BIT_EN_ENABLE)




/******************************************************************************
 * @brief      Disable DAC Buffer
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define COMP_DisableDACBuffer()             (COMP->DACBUFCTL.bit.EN = DACBUFCTL_BIT_EN_DISABLE)




/******************************************************************************
 * @brief      Enable write access to the protected COMP registers
 *
 * @param[in]  none
 *
 * @return     none
 * 
 ******************************************************************************/
#define COMP_WALLOW()                       (COMP->COMPREGKEY.all = 0x1ACCE551)




/******************************************************************************
 * @brief      Disable write access to the protected PGA registers
 *
 * @param[in]  none
 *
 * @return     none
 * 
 ******************************************************************************/
#define COMP_WDIS()                         (COMP->COMPREGKEY.all = 0x0)




/**
 *  @brief  Comparator Public Function Declaration
 */
void COMP_Init(COMP_ComparatorSelEnum eCOMP, COMP_CHSelEnum eCH, int32_t i32DACVoltageMV, uint32_t u32DeglicthTimeNs);

void COMP_SelectChannel(COMP_ComparatorSelEnum eCOMP, COMP_CHSelEnum eCH);
void COMP_SetOutputType(COMP_ComparatorSelEnum eCOMP, COMP_OutputSelEnum eOutputSel);

void COMP_SetFilterWindow(COMP_ComparatorSelEnum eCOMP, uint8_t u8Size, uint8_t u8Threshold);
void COMP_SetFilterWindowTimeNs(COMP_ComparatorSelEnum eCOMP, uint32_t u32SizeTimeNS, uint32_t u32ThresholdTimeNS);
void COMP_SetFilterClockDiv(COMP_ComparatorSelEnum eCOMP, uint16_t u16ClkDiv);

void COMP_SetHysteresis(COMP_ComparatorSelEnum eCOMP, COMP_HystSelEnum eHystSel);

void COMP_DACBufferInit(COMP_DACSelEnum eDACSel, BOOL bIsOut10, BOOL bIsOut13);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* COMP_H */


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
