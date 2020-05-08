/*******************************************************************************
* @file     pga.h
* @brief    PGA driver header file.
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


#ifndef PGA_H
#define PGA_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1168.h"




/**
 *  @brief  PGA selection
 */
typedef enum
{ 
  PGA0                  = 0,                /*!< PGA 0                */
  PGA1                  = 1,                /*!< PGA 1                */
  PGA2                  = 2                 /*!< PGA 2                */
} PGA_NumEnum;




/**
 *  @brief  Input channel selection for PGA "Positive"
 */
typedef enum
{ 
  PGA0_CH_P_VSSA        = 0x00,             /*!< GND                  */
  PGA0_CH_P_DAC1        = 0x01,             /*!< DAC1                 */
  PGA0_CH_P_DAC2        = 0x02,             /*!< DAC2                 */
  PGA0_CH_P_ADC0        = 0x03,             /*!< GPIO0                */
  PGA0_CH_P_ADC6        = 0x04,             /*!< GPIO6                */
  PGA0_CH_P_ADC8        = 0x05,             /*!< GPIO8                */
  PGA0_CH_P_ADC10       = 0x06,             /*!< GPIO10               */
  PGA0_CH_P_ADC4        = 0x07,             /*!< GPIO4                */
  
  PGA1_CH_P_VSSA        = 0x10,             /*!< GND                  */
  PGA1_CH_P_DAC1        = 0x11,             /*!< DAC1                 */
  PGA1_CH_P_ATEST       = 0x12,             /*!< ATEST                */
  PGA1_CH_P_ADC0        = 0x13,             /*!< GPIO0                */
  PGA1_CH_P_ADC2        = 0x14,             /*!< GPIO2                */
  PGA1_CH_P_ADC8        = 0x15,             /*!< GPIO8                */
  PGA1_CH_P_ADC10       = 0x16,             /*!< GPIO10               */
  PGA1_CH_P_ADC9        = 0x17,             /*!< GPIO9                */
  
  PGA2_CH_P_VSSA        = 0x20,             /*!< GND                  */
  PGA2_CH_P_DAC1        = 0x21,             /*!< DAC1                 */
  PGA2_CH_P_TSENSOR_H   = 0x22,             /*!< T-Sensor out 1       */
  PGA2_CH_P_ADC0        = 0x23,             /*!< GPIO0                */
  PGA2_CH_P_ADC4        = 0x24,             /*!< GPIO4                */
  PGA2_CH_P_ADC8        = 0x25,             /*!< GPIO8                */
  PGA2_CH_P_ADC12       = 0x26,             /*!< GPIO12               */
  PGA2_CH_P_ADC14       = 0x27              /*!< GPIO14               */
} PGA_CH_P;




/**
 *  @brief  Input channel selection for PGA "Negative"
 */
typedef enum
{ 
  PGA0_CH_N_VSSA        = 0x50,             /*!< GND                  */
  PGA0_CH_N_DAC1        = 0x51,             /*!< DAC1                 */
  PGA0_CH_N_DAC3        = 0x52,             /*!< DAC3                 */
  PGA0_CH_N_ADC1        = 0x53,             /*!< GPIO1                */
  PGA0_CH_N_ADC7        = 0x54,             /*!< GPIO7                */
  PGA0_CH_N_ADC9        = 0x55,             /*!< GPIO9                */
  PGA0_CH_N_ADC5        = 0x56,             /*!< GPIO5                */
  PGA0_CH_N_ADC3        = 0x57,             /*!< GPIO3                */
  
  PGA1_CH_N_VSSA        = 0x40,             /*!< GND                  */
  PGA1_CH_N_DAC1        = 0x41,             /*!< DAC1                 */
  PGA1_CH_N_VDD12       = 0x42,             /*!< VDD 1.2V             */
  PGA1_CH_N_ADC2        = 0x43,             /*!< GPIO2                */
  PGA1_CH_N_ADC3        = 0x44,             /*!< GPIO3                */
  PGA1_CH_N_ADC10       = 0x45,             /*!< GPIO10               */
  PGA1_CH_N_ADC11       = 0x46,             /*!< GPIO11               */
  PGA1_CH_N_ADC1        = 0x47,             /*!< GPIO1                */
  
  PGA2_CH_N_VSSA        = 0x30,             /*!< GND                  */
  PGA2_CH_N_DAC1        = 0x31,             /*!< DAC1                 */
  PGA2_CH_N_TSENSOR_L   = 0x32,             /*!< T-Sensor out 0       */
  PGA2_CH_N_ADC3        = 0x33,             /*!< GPIO3                */
  PGA2_CH_N_ADC5        = 0x34,             /*!< GPIO5                */
  PGA2_CH_N_ADC11       = 0x35,             /*!< GPIO11               */
  PGA2_CH_N_ADC13       = 0x36,             /*!< GPIO13               */
  PGA2_CH_N_ADC15       = 0x37              /*!< GPIO15               */
} PGA_CH_N;




/**
 *  @brief  PGA Gain
 */
typedef enum
{ 
  PGA_SCALE_2X          = 0,                /*!< 1x  for single-ended mode, 2x  for differential mode */
  PGA_SCALE_4X          = 1,                /*!< 2x  for single-ended mode, 4x  for differential mode */
  PGA_SCALE_8X          = 2,                /*!< 4x  for single-ended mode, 8x  for differential mode */
  PGA_SCALE_16X         = 3,                /*!< 8x  for single-ended mode, 16x for differential mode */
  PGA_SCALE_24X         = 4,                /*!< 12x for single-ended mode, 24x for differential mode */
  PGA_SCALE_32X         = 5,                /*!< 16x for single-ended mode, 32x for differential mode */
  PGA_SCALE_48X         = 6,                /*!< 24x for single-ended mode, 48x for differential mode */
  PGA_SCALE_64X         = 7                 /*!< 32x for single-ended mode, 64x for differential mode */
} PGA_SCALE;




/******************************************************************************
 * @brief      Enable write access to the protected PGA registers
 *
 * @param[in]  none
 *
 * @return     none
 * 
 ******************************************************************************/
#define PGA_WALLOW()                        (PGA->PGAREGKEY.all = 0x1ACCE551)




/******************************************************************************
 * @brief      Disable write access to the protected PGA registers
 *
 * @param[in]  none
 *
 * @return     none
 * 
 ******************************************************************************/
#define PGA_WDIS()                          (PGA->PGAREGKEY.all = 0x0)




/**
 *  @brief  PGA Public Function Declaration
 */
void PGA_DifferentialInit(PGA_NumEnum ePGA, PGA_CH_P ePChannel, PGA_CH_N eNChannel, PGA_SCALE eDiffGain);
void PGA_SelectPositiveChannelAsCommonInput(PGA_NumEnum ePGA);
void PGA_SelectNegativeChannelAsCommonInput(PGA_NumEnum ePGA);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* PGA_H */


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
