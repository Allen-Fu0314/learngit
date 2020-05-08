/******************************************************************************
 * @file     adc.h
 * @brief    ADC driver header file.
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


#ifndef ADC_H
#define ADC_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1168.h"




/**
 *  @brief  ADC default sampling and conversion time
 *          User can adjust with different application
 */
#define ADC_DEFAULT_SAMPLE_TIME_NS          150
#define ADC_DEFAULT_CONVERSION_TIME_NS      150




/**
 *  @brief  ADC full scale selection
 */
#define ADC_FULL_SCALE_3V65                 (0x1)
#define ADC_FULL_SCALE_3V3                  (0x2)
#define ADC_FULL_SCALE_SEL                  ADC_FULL_SCALE_3V65




/**
 *  @brief  ADC full scale voltage
 *
 *  @note   User should not change
 */
#if ADC_FULL_SCALE_SEL == ADC_FULL_SCALE_3V65
  #define ADC_FULLSCALE_VOLT                (3.657f)
#elif ADC_FULL_SCALE_SEL == ADC_FULL_SCALE_3V3
  #define ADC_FULLSCALE_VOLT                (3.3f)
#else
  #define ADC_FULLSCALE_VOLT                (3.657f)
#endif
#define ADC_FULLSCALE_mV                    ((int32_t)(ADC_FULLSCALE_VOLT * 1000.0f))




/**
 *  @brief  T-Sensor Temperature calculate coefficient
 *
 *  @note   User should not change
 */
#define TSENSOR_SLOPE             (4238.97f)      /*!< 4238970 oC/V   */
#define TSENSOR_OFFSET            (283.36f)       /*!< 283.36 oC       */




/**
 *  @brief  ADC interrupt type definition
 */
typedef enum
{
  ADC_INT_0             =  0,               /*!< ADC interrupt  0         */
  ADC_INT_1             =  1,               /*!< ADC interrupt  1         */
  ADC_INT_2             =  2,               /*!< ADC interrupt  2         */
  ADC_INT_3             =  3,               /*!< ADC interrupt  3         */
  ADC_INT_4             =  4,               /*!< ADC interrupt  4         */
  ADC_INT_5             =  5,               /*!< ADC interrupt  5         */
  ADC_INT_6             =  6,               /*!< ADC interrupt  6         */
  ADC_INT_7             =  7,               /*!< ADC interrupt  7         */
  ADC_INT_8             =  8,               /*!< ADC interrupt  8         */
  ADC_INT_9             =  9,               /*!< ADC interrupt  9         */
  ADC_INT_10            = 10,               /*!< ADC interrupt 10         */
  ADC_INT_11            = 11,               /*!< ADC interrupt 11         */
  ADC_INT_12            = 12,               /*!< ADC interrupt 12         */
  ADC_INT_13            = 13,               /*!< ADC interrupt 13         */
  ADC_INT_14            = 14,               /*!< ADC interrupt 14         */
  ADC_INT_15            = 15,               /*!< ADC interrupt 15         */
} ADC_IntEnum;




/**
 *  @brief  ADC SOC type definition
 */
typedef enum
{
  ADC_SOC_0             =  0,               /*!< ADC SOC  0               */
  ADC_SOC_1             =  1,               /*!< ADC SOC  1               */
  ADC_SOC_2             =  2,               /*!< ADC SOC  2               */
  ADC_SOC_3             =  3,               /*!< ADC SOC  3               */
  ADC_SOC_4             =  4,               /*!< ADC SOC  4               */
  ADC_SOC_5             =  5,               /*!< ADC SOC  5               */
  ADC_SOC_6             =  6,               /*!< ADC SOC  6               */
  ADC_SOC_7             =  7,               /*!< ADC SOC  7               */
  ADC_SOC_8             =  8,               /*!< ADC SOC  8               */
  ADC_SOC_9             =  9,               /*!< ADC SOC  9               */
  ADC_SOC_10            = 10,               /*!< ADC SOC 10               */
  ADC_SOC_11            = 11,               /*!< ADC SOC 11               */
  ADC_SOC_12            = 12,               /*!< ADC SOC 12               */
  ADC_SOC_13            = 13,               /*!< ADC SOC 13               */
  ADC_SOC_14            = 14,               /*!< ADC SOC 14               */
  ADC_SOC_15            = 15,               /*!< ADC SOC 15               */
} ADC_SocEnum;




/**
 *  @brief  ADC Input Pin Selection Table
 *          Encode logic for Non-GPIO pin: Sampler(4-bit) + Channel (4-bit)
 *          Sampler - \ref 8  SHA Positive    - \ref 9  SHA Negative
 *                  - \ref A  SHB Positive    - \ref B  SHB Negative
 *                  - \ref C  SHC Positive    - \ref D  SHC Negative
 */
typedef enum
{
  ADC0_GPIO0            =  0,               /*!< SHA/B/C positive terminal: GPIO0               */
  ADC1_GPIO1            =  1,               /*!< SHA/B/C negative terminal: GPIO1               */
                                            
  ADC2_GPIO2            =  2,               /*!< SHA positive terminal: GPIO2                   */
  ADC3_GPIO3            =  3,               /*!< SHA negative terminal: GPIO3                   */
                                            
  ADC4_GPIO4            =  4,               /*!< SHB positive terminal: GPIO4                   */
  ADC5_GPIO5            =  5,               /*!< SHB negative terminal: GPIO5                   */
                                            
  ADC6_GPIO6            =  6,               /*!< SHC positive terminal: GPIO6                   */
  ADC7_GPIO7            =  7,               /*!< SHC negative terminal: GPIO7                   */
                                            
  ADC8_GPIO8            =  8,               /*!< SHA/B/C positive terminal: GPIO8               */
  ADC9_GPIO9            =  9,               /*!< SHA/B/C negative terminal: GPIO9               */
                                            
  ADC10_GPIO10          = 10,               /*!< SHA positive terminal: GPIO10                  */
  ADC11_GPIO11          = 11,               /*!< SHA negative terminal: GPIO11                  */
                                            
  ADC12_GPIO12          = 12,               /*!< SHB positive terminal: GPIO12                  */
  ADC13_GPIO13          = 13,               /*!< SHB negative terminal: GPIO13                  */
                                            
  ADC14_GPIO14          = 14,               /*!< SHC positive terminal: GPIO14                  */
  ADC15_GPIO15          = 15,               /*!< SHC negative terminal: GPIO15                  */
  
  ADCx_PGA0P            = 0x81,             /*!< SHA positive terminal: Positive output of PGA0 */
  ADCx_PGA0N            = 0x91,             /*!< SHA negative terminal: Negative output of PGA0 */
  ADCx_PGA1P            = 0xA1,             /*!< SHB positive terminal: Positive output of PGA1 */
  ADCx_PGA1N            = 0xB1,             /*!< SHB negative terminal: Negative output of PGA1 */
  ADCx_PGA2P            = 0xC1,             /*!< SHC positive terminal: Positive output of PGA2 */
  ADCx_PGA2N            = 0xD1,             /*!< SHC negative terminal: Negative output of PGA2 */
  
  ADCx_TSENSOR_H        = 0xC3,             /*!< SHC positive terminal: T-sensor output 1       */
  ADCx_TSENSOR_L        = 0xD3,             /*!< SHC negative terminal: T-sensor output 0       */
  
  ADCx_VDDA             = 0x83,             /*!< SHA positive terminal: VDDA                    */
  ADCx_VDD12            = 0x93,             /*!< SHA negative terminal: VDD12                   */
  
  ADCx_ATEST            = 0xA3,             /*!< SHB positive terminal: ATEST                   */
  ADCx_DAC_BUF          = 0xB3,             /*!< SHB negative terminal: DAC BUF                 */
  
  ADCx_DAC0             = 0x82,             /*!< SHA both terminal: DAC0                        */
  ADCx_DAC1             = 0xA2,             /*!< SHB both terminal: DAC1                        */
  ADCx_DAC2             = 0xC2,             /*!< SHC both terminal: DAC2                        */
} ADC_PinSelEnum;




/**
 *  @brief  ADC Trigger Source Table
 */
typedef enum
{
  ADCTRIG_Software     =  0,                /*!< ADCTRIG0  - Software     */
  ADCTRIG_Timer0       =  1,                /*!< ADCTRIG1  - CPU Timer 0  */
  ADCTRIG_Timer1       =  2,                /*!< ADCTRIG1  - CPU Timer 1  */
  ADCTRIG_Timer2       =  3,                /*!< ADCTRIG1  - CPU Timer 2  */
  ADCTRIG_EXTSOC       =  4,                /*!< ADCTRIG4  - External SOC */
  ADCTRIG_PWM0SOCA     =  5,                /*!< ADCTRIG5  - PWM0SOCA     */
  ADCTRIG_PWM0SOCB     =  6,                /*!< ADCTRIG6  - PWM0SOCB     */
  ADCTRIG_PWM0SOCC     =  7,                /*!< ADCTRIG7  - PWM0SOCC     */
  
  ADCTRIG_PWM1SOCA     =  8,                /*!< ADCTRIG8  - PWM1SOCA     */
  ADCTRIG_PWM1SOCB     =  9,                /*!< ADCTRIG9  - PWM1SOCB     */
  ADCTRIG_PWM1SOCC     = 10,                /*!< ADCTRIG10 - PWM1SOCC     */
  
  ADCTRIG_PWM2SOCA     = 11,                /*!< ADCTRIG11 - PWM2SOCA     */
  ADCTRIG_PWM2SOCB     = 12,                /*!< ADCTRIG12 - PWM2SOCB     */
  ADCTRIG_PWM2SOCC     = 13,                /*!< ADCTRIG13 - PWM2SOCC     */
  
  ADCTRIG_PWM3SOCA     = 14,                /*!< ADCTRIG14 - PWM3SOCA     */
  ADCTRIG_PWM3SOCB     = 15,                /*!< ADCTRIG15 - PWM3SOCB     */
  ADCTRIG_PWM3SOCC     = 16,                /*!< ADCTRIG16 - PWM3SOCC     */
  
  ADCTRIG_PWM4SOCA     = 17,                /*!< ADCTRIG17 - PWM4SOCA     */
  ADCTRIG_PWM4SOCB     = 18,                /*!< ADCTRIG18 - PWM4SOCB     */
  ADCTRIG_PWM4SOCC     = 19,                /*!< ADCTRIG19 - PWM4SOCC     */
  
  ADCTRIG_PWM5SOCA     = 20,                /*!< ADCTRIG20 - PWM5SOCA     */
  ADCTRIG_PWM5SOCB     = 21,                /*!< ADCTRIG21 - PWM5SOCB     */
  ADCTRIG_PWM5SOCC     = 22,                /*!< ADCTRIG22 - PWM5SOCC     */
} ADC_TriggerSourceEnum;




/**
 *  @brief  ADC SOC S/H selection
 */
typedef enum
{
  SH_DISABLE            = 0,                /*!< Disable all S/Hs                       */
  SHA                   = 1,                /*!< Enable SHA                             */
  SHB                   = 2,                /*!< Enable SHB                             */
  SHC                   = 3,                /*!< Enable SHC                             */
  SHA_AND_SHB           = 4,                /*!< Enable SHA and SHB simultaneously      */
  SHB_AND_SHC           = 5,                /*!< Enable SHB and SHC simultaneously      */
  SHA_AND_SHC           = 6,                /*!< Enable SHA, SHB and SHC simultaneously */
  SHA_AND_SHB_SHC       = 7,
} ADC_SHSelEnum;




/**
 *  @brief  ADC PPU Unit definition
 */
typedef enum
{
  ADC_PPU_0             = 0,                /*!< ADC PPU 0         */
  ADC_PPU_1             = 1,                /*!< ADC PPU 1         */
  ADC_PPU_2             = 2,                /*!< ADC PPU 2         */
  ADC_PPU_3             = 3,                /*!< ADC PPU 3         */
  ADC_PPU_4             = 4,                /*!< ADC PPU 4         */
  ADC_PPU_5             = 5,                /*!< ADC PPU 5         */
} ADC_PPUEnum;




/**
 *  @brief  ADC PPU event definition
 */
typedef enum
{
  ADC_PPU_TOO_LOW       = 0,                /*!< ADC PPU Too-Low    */
  ADC_PPU_TOO_HIGH      = 1,                /*!< ADC PPU Too-High   */
  ADC_PPU_CROSS_ZERO    = 2,                /*!< ADC PPU Zero-cross */
} ADC_PPUEvtEnum;




/**
 *  @brief  ADC PPU Comparision Polarity definition
 */
typedef enum
{
  ADC_PPU_REF_MINUS_CODE          = 0,      /*!< ADCPPU result is the reference value minus the selected result */
  ADC_PPU_CODE_MINUS_REF          = 1,      /*!< ADCPPU result is the selected result minus the reference value */
} ADC_PPUPolEnum;




/******************************************************************************
 * @brief      Enable ADC Interrupt
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define ADC_EnableInt0()                    (ADC->ADCIE.all |= ADCIE_ALL_INT0_ENABLE)
#define ADC_EnableInt1()                    (ADC->ADCIE.all |= ADCIE_ALL_INT1_ENABLE)
#define ADC_EnableInt2()                    (ADC->ADCIE.all |= ADCIE_ALL_INT2_ENABLE)
#define ADC_EnableInt3()                    (ADC->ADCIE.all |= ADCIE_ALL_INT3_ENABLE)
#define ADC_EnableInt4()                    (ADC->ADCIE.all |= ADCIE_ALL_INT4_ENABLE)
#define ADC_EnableInt5()                    (ADC->ADCIE.all |= ADCIE_ALL_INT5_ENABLE)
#define ADC_EnableInt6()                    (ADC->ADCIE.all |= ADCIE_ALL_INT6_ENABLE)
#define ADC_EnableInt7()                    (ADC->ADCIE.all |= ADCIE_ALL_INT7_ENABLE)
#define ADC_EnableInt8()                    (ADC->ADCIE.all |= ADCIE_ALL_INT8_ENABLE)
#define ADC_EnableInt9()                    (ADC->ADCIE.all |= ADCIE_ALL_INT9_ENABLE)
#define ADC_EnableInt10()                   (ADC->ADCIE.all |= ADCIE_ALL_INT10_ENABLE)
#define ADC_EnableInt11()                   (ADC->ADCIE.all |= ADCIE_ALL_INT11_ENABLE)
#define ADC_EnableInt12()                   (ADC->ADCIE.all |= ADCIE_ALL_INT12_ENABLE)
#define ADC_EnableInt13()                   (ADC->ADCIE.all |= ADCIE_ALL_INT13_ENABLE)
#define ADC_EnableInt14()                   (ADC->ADCIE.all |= ADCIE_ALL_INT14_ENABLE)
#define ADC_EnableInt15()                   (ADC->ADCIE.all |= ADCIE_ALL_INT15_ENABLE)




/******************************************************************************
 * @brief      Enable ADC Interrupt
 *
 * @param[in]  eSOC:  Select SOC to be used from ADC_SocEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define ADC_EnableInt(eSOC)                 (ADC->ADCIE.all |= ADCIE_ALL_INT0_Msk << (eSOC))




/******************************************************************************
 * @brief      Disable ADC Interrupt
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define ADC_DisableInt0()                   (ADC->ADCIE.bit.INT0  = ADCIE_BIT_INT0_DISABLE)
#define ADC_DisableInt1()                   (ADC->ADCIE.bit.INT1  = ADCIE_BIT_INT1_DISABLE)
#define ADC_DisableInt2()                   (ADC->ADCIE.bit.INT2  = ADCIE_BIT_INT2_DISABLE)
#define ADC_DisableInt3()                   (ADC->ADCIE.bit.INT3  = ADCIE_BIT_INT3_DISABLE)
#define ADC_DisableInt4()                   (ADC->ADCIE.bit.INT4  = ADCIE_BIT_INT4_DISABLE)
#define ADC_DisableInt5()                   (ADC->ADCIE.bit.INT5  = ADCIE_BIT_INT5_DISABLE)
#define ADC_DisableInt6()                   (ADC->ADCIE.bit.INT6  = ADCIE_BIT_INT6_DISABLE)
#define ADC_DisableInt7()                   (ADC->ADCIE.bit.INT7  = ADCIE_BIT_INT7_DISABLE)
#define ADC_DisableInt8()                   (ADC->ADCIE.bit.INT8  = ADCIE_BIT_INT8_DISABLE)
#define ADC_DisableInt9()                   (ADC->ADCIE.bit.INT9  = ADCIE_BIT_INT9_DISABLE)
#define ADC_DisableInt10()                  (ADC->ADCIE.bit.INT10 = ADCIE_BIT_INT10_DISABLE)
#define ADC_DisableInt11()                  (ADC->ADCIE.bit.INT11 = ADCIE_BIT_INT11_DISABLE)
#define ADC_DisableInt12()                  (ADC->ADCIE.bit.INT12 = ADCIE_BIT_INT12_DISABLE)
#define ADC_DisableInt13()                  (ADC->ADCIE.bit.INT13 = ADCIE_BIT_INT13_DISABLE)
#define ADC_DisableInt14()                  (ADC->ADCIE.bit.INT14 = ADCIE_BIT_INT14_DISABLE)
#define ADC_DisableInt15()                  (ADC->ADCIE.bit.INT15 = ADCIE_BIT_INT15_DISABLE)




/******************************************************************************
 * @brief      Disable ADC Interrupt
 *
 * @param[in]  eSOC:  Select SOC to be used from ADC_SocEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define ADC_DisableInt(eSOC)                (ADC->ADCIE.all &= (~(ADCIE_ALL_INT0_Msk << (eSOC))))




/******************************************************************************
 * @brief      Clear ADC Interrupt Flag
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define ADC_ClearInt0()                     (ADC->ADCIC.all = ADCIC_ALL_INT0_CLEAR)
#define ADC_ClearInt1()                     (ADC->ADCIC.all = ADCIC_ALL_INT1_CLEAR)
#define ADC_ClearInt2()                     (ADC->ADCIC.all = ADCIC_ALL_INT2_CLEAR)
#define ADC_ClearInt3()                     (ADC->ADCIC.all = ADCIC_ALL_INT3_CLEAR)
#define ADC_ClearInt4()                     (ADC->ADCIC.all = ADCIC_ALL_INT4_CLEAR)
#define ADC_ClearInt5()                     (ADC->ADCIC.all = ADCIC_ALL_INT5_CLEAR)
#define ADC_ClearInt6()                     (ADC->ADCIC.all = ADCIC_ALL_INT6_CLEAR)
#define ADC_ClearInt7()                     (ADC->ADCIC.all = ADCIC_ALL_INT7_CLEAR)
#define ADC_ClearInt8()                     (ADC->ADCIC.all = ADCIC_ALL_INT8_CLEAR)
#define ADC_ClearInt9()                     (ADC->ADCIC.all = ADCIC_ALL_INT9_CLEAR)
#define ADC_ClearInt10()                    (ADC->ADCIC.all = ADCIC_ALL_INT10_CLEAR)
#define ADC_ClearInt11()                    (ADC->ADCIC.all = ADCIC_ALL_INT11_CLEAR)
#define ADC_ClearInt12()                    (ADC->ADCIC.all = ADCIC_ALL_INT12_CLEAR)
#define ADC_ClearInt13()                    (ADC->ADCIC.all = ADCIC_ALL_INT13_CLEAR)
#define ADC_ClearInt14()                    (ADC->ADCIC.all = ADCIC_ALL_INT14_CLEAR)
#define ADC_ClearInt15()                    (ADC->ADCIC.all = ADCIC_ALL_INT15_CLEAR)




/******************************************************************************
 * @brief      Clear ADC Interrupt Flag
 *
 * @param[in]  eSOC:  Select SOC to be used from ADC_SocEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define ADC_ClearInt(eSOC)                  (ADC->ADCIC.all = (ADCIC_ALL_INT0_Msk << (eSOC)))




/******************************************************************************
 * @brief      Get ADC Interrupt Flag
 *
 * @param[in]  none
 *
 * @return     0 - Interrupt not occur
 *             1 - Interrupt occurred
 *
 ******************************************************************************/
#define ADC_GetInt0Flag()                   (ADC->ADCIF.bit.INT0)
#define ADC_GetInt1Flag()                   (ADC->ADCIF.bit.INT1)
#define ADC_GetInt2Flag()                   (ADC->ADCIF.bit.INT2)
#define ADC_GetInt3Flag()                   (ADC->ADCIF.bit.INT3)
#define ADC_GetInt4Flag()                   (ADC->ADCIF.bit.INT4)
#define ADC_GetInt5Flag()                   (ADC->ADCIF.bit.INT5)
#define ADC_GetInt6Flag()                   (ADC->ADCIF.bit.INT6)
#define ADC_GetInt7Flag()                   (ADC->ADCIF.bit.INT7)
#define ADC_GetInt8Flag()                   (ADC->ADCIF.bit.INT8)
#define ADC_GetInt9Flag()                   (ADC->ADCIF.bit.INT9)
#define ADC_GetInt10Flag()                  (ADC->ADCIF.bit.INT10)
#define ADC_GetInt11Flag()                  (ADC->ADCIF.bit.INT11)
#define ADC_GetInt12Flag()                  (ADC->ADCIF.bit.INT12)
#define ADC_GetInt13Flag()                  (ADC->ADCIF.bit.INT13)
#define ADC_GetInt14Flag()                  (ADC->ADCIF.bit.INT14)
#define ADC_GetInt15Flag()                  (ADC->ADCIF.bit.INT15)




/******************************************************************************
 * @brief      Get ADC Interrupt Flag
 *
 * @param[in]  eSOC:  Select SOC to be used from ADC_SocEnum
 *
 * @return     0 - Interrupt not occur
 *             1 - Interrupt occurred
 *
 ******************************************************************************/
#define ADC_GetIntFlag(eSOC)                ((ADC->ADCIF.all & (ADCIF_ALL_INT0_Msk << (eSOC))) >> (eSOC))




/******************************************************************************
 * @brief      Clear ADC Interrupt Overflow Flag
 *
 * @param[in]  eSOC:  Select SOC to be used from ADC_SocEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define ADC_ClearOverflowInt(eSOC)          (ADC->ADCIOVFC.all = (ADCIOVFC_ALL_INT0_Msk << (eSOC)))




/******************************************************************************
 * @brief      Get ADC Interrupt Overflow Flag
 *
 * @param[in]  eSOC:  Select SOC to be used from ADC_SocEnum
 *
 * @return     0 - Interrupt overflow not occur
 *             1 - Interrupt overflow occurred
 *
 ******************************************************************************/
#define ADC_GetOverflowIntFlag(eSOC)        ((ADC->ADCIOVF.all & (ADCIOVF_ALL_INT0_Msk << (eSOC))) >> (eSOC))




/******************************************************************************
 * @brief      Enable ADC Interrupt Trigger SOC
 *
 * @param[in]  eSOC:  Select SOC to be used from ADC_SocEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define ADC_EnableIntTriggerSOC(eSOC)       (ADC->ADCINTSOCEN.all |= (ADCINTSOCEN_ALL_SOC0_Msk << (eSOC)))




/******************************************************************************
 * @brief      Disable ADC Interrupt Trigger SOC
 *
 * @param[in]  eSOC:  Select SOC to be used from ADC_SocEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define ADC_DisableIntTriggerSOC(eSOC)      (ADC->ADCINTSOCEN.all &= ~(ADCINTSOCEN_ALL_SOC0_Msk << (eSOC)))




/******************************************************************************
 * @brief      Select ADC Interrupt to Trigger SOC
 *
 * @param[in]  eSOC:  Select SOC to be used from ADC_SocEnum
 * @param[in]  eInt:  Select Interrupt number
 *                    Please go to ADC_IntEnum for datails
 *
 * @return     none
 *
 ******************************************************************************/
__STATIC_INLINE void ADC_SelectIntTriggerSOC(ADC_SocEnum eSOC, ADC_IntEnum eInt)
{
  if(eSOC < ADC_SOC_8)
  {
    ADC->ADCINTSOCSEL0.all &= ~(ADCINTSOCSEL0_ALL_SOC0_Msk << (eSOC * 4));
    ADC->ADCINTSOCSEL0.all |= (eInt << (eSOC * 4));
  }
  else
  {
    ADC->ADCINTSOCSEL1.all &= ~(ADCINTSOCSEL1_ALL_SOC8_Msk << ((eSOC - 8) * 4));
    ADC->ADCINTSOCSEL1.all |= (eInt << ((eSOC - 8) * 4));
  }
}




/******************************************************************************
 * @brief      Set ADC SOC priority
 *
 * @param[in]  ePriority:  Select the Round Ring pointer
 *                         Please go to ADCSOCPRICTL_BIT_PRIORITY for details
 *
 * @return     none
 *
 ******************************************************************************/
#define ADC_SetSOCPriority(ePriority)       (ADC->ADCSOCPRICTL.bit.PRIORITY = (ePriority))




/******************************************************************************
 * @brief      Get ADC SOC priority
 *
 * @param[in]  none
 *
 * @return     SOC priority (0 ~ 15)
 *
 ******************************************************************************/
#define ADC_GetSOCPriority()                (ADC->ADCSOCPRICTL.bit.PRIORITY)




/******************************************************************************
 * @brief      Enable ADC module
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define ADC_Enable()                        (ADC->ADCCTL.all |= ADCCTL_ALL_EN_ENABLE_ADC)




/******************************************************************************
 * @brief      Disable ADC module 
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define ADC_Disable()                       (ADC->ADCCTL.bit.EN = ADCCTL_BIT_EN_DISABLE_ADC)




/******************************************************************************
 * @brief      Reset ADC module 
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define ADC_Reset()                         (ADC->ADCCTL.all |= ADCCTL_ALL_RST_RESET_ADC)




/******************************************************************************
 * @brief      Set average counts for the ADC result
 *
 * @param[in]  eSOC   :  Select SOC to be used
 * @param[in]  eAvgCnt:  Select average counts for ADC result
 *                       Please go to ADCSOCCTL0_BIT_AVGCNT ~ ADCSOCCTL15_BIT_AVGCNT for details
 *
 * @return     none
 *
*******************************************************************************/
#define ADC_SetAverageCnt(eSOC,eAvgCnt)     (ADC->ADCSOCCTL[(eSOC)].bit.AVGCNT = (eAvgCnt))




/******************************************************************************
 * @brief      Set Sampler/Hold for the selected SOC channel
 *
 * @param[in]  eSOC:  Select SOC to be used
 * @param[in]  eSH :  Select the S/H to be used
 *                    Please go to ADC_SHSelEnum for details
 *
 * @return     none
 *
*******************************************************************************/
#define ADC_SetSOCSH(eSOC,eSH)              (ADC->ADCSOCCTL[(eSOC)].bit.SHEN = (eSH))




/******************************************************************************
 * @brief      Select Trigger source for SOC
 *
 * @param[in]  eSOC          :  Select SOC to be used
 * @param[in]  eTriggerSource:  Select ADC Trigger Source, value from ADC_TriggerSourceEnum

 *
 * @return     none
 *
*******************************************************************************/
#define ADC_SelectTrigger(eSOC,eTriggerSource)  (ADC->ADCSOCCTL[(eSOC)].bit.TRIGSEL = (eTriggerSource))




/******************************************************************************
 * @brief      Software trigger SOC
 *
 * @param[in]  eSOC:  Select SOC to be used
 *
 * @return     none
 *
*******************************************************************************/
#define ADC_SoftwareTrigger(eSOC)           (ADC->ADCSOCFRC.all = (ADCSOCFRC_ALL_SOC0_Msk << (eSOC)))




/******************************************************************************
 * @brief      Get result value from ADC result register
 *
 * @param[in]  eSOC:  Select SOC to be used
 *
 * @return     ADC result in -8192 ~ 8191
 *
 ******************************************************************************/
#define ADC_GetResult(eSOC)                 ((int32_t)(ADC->ADCRESULT[(eSOC)].all))




/******************************************************************************
 * @brief      For Single End Mode Only (One terminal is GND)
 *             Get Trim result(code) from ADC result register
 *
 * @param[in]  eSOC:  Select SOC to be used
 *
 * @return     ADC result in 0~4091
 *             Note: User can choose ADC fullscale voltage in adc.h
 *             If full scale is 3.65V 
 *             Code            Real Voltage in ADC view
 *             0               0 V
 *             8191            3.65 V
 *
 *             If full scale is 3.3V 
 *             Code            Real Voltage in ADC view
 *             0               0 V
 *             8191            3.3 V
 *
 ******************************************************************************/
#if ADC_FULL_SCALE_SEL == ADC_FULL_SCALE_3V65
#define ADC_GetTrimResult1(eSOC)            (ABS((int32_t)ADC->ADCRESULT[(eSOC)].all))
#elif ADC_FULL_SCALE_SEL == ADC_FULL_SCALE_3V3
#define ADC_GetTrimResult1(eSOC)            (ABS((int32_t)ADC->ADCRESULT[(eSOC)].all))
#else
#define ADC_GetTrimResult1(eSOC)            (ABS((int32_t)ADC->ADCRESULT[(eSOC)].all))
#endif




/******************************************************************************
 * @brief      For Differential Mode 
 *             Get Trim result(code) from ADC result register
 *
 * @param[in]  eSOC:  Select SOC to be used
 *
 * @return     ADC result in -8192 ~ 8191
 *             Note: User can choose ADC fullscale voltage
 *             If full scale is 3.65V 
 *             Code            Real Voltage in ADC view
 *             -8192           -3.65 V
 *             0               0 V
 *             8191            3.65 V
 *
 *             If full scale is 3.3V 
 *             Code            Real Voltage in ADC view
 *             -8192           -3.3 V
 *             0               0 V
 *             8192            3.3 V
 *
 ******************************************************************************/
#if ADC_FULL_SCALE_SEL == ADC_FULL_SCALE_3V65
#define ADC_GetTrimResult2(eSOC)            ((int32_t)ADC->ADCRESULT[(eSOC)].all)
#elif ADC_FULL_SCALE_SEL == ADC_FULL_SCALE_3V3
#define ADC_GetTrimResult2(eSOC)            ((int32_t)ADC->ADCRESULT[(eSOC)].all)
#else
#define ADC_GetTrimResult2(eSOC)            ((int32_t)ADC->ADCRESULT[(eSOC)].all)
#endif




/******************************************************************************
 * @brief      Get result value from ADC PPU result register
 *
 * @param[in]  ePPU:  Select PPU unit to be used
 *                    Please go to ADC_PPUEnum for details
 *
 * @return     ADC PPU result 
 *
 ******************************************************************************/
#define ADC_GetPPUResult(ePPU)              ((int32_t)(ADC->ADCPPURESULT[(ePPU)].all))



/******************************************************************************
 * @brief      Set SOC Delay Capture input signal
 *
 * @param[in]  ePPU:  Select PPU unit to be used
 *                    Please go to ADC_PPUEnum for details
 *             eSOC:  Select SOC to be used
 *                    Please go to ADC_SocEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
#define ADC_SetSOCDelayCapture(ePPU,eSOC)   (ADC->ADCPPUCTL[(ePPU)].bit.SOCSEL = eSOC)




/******************************************************************************
 * @brief      Get SOC Delay value
 *
 * @param[in]  ePPU:  Select PPU unit to be used
 *                    Please go to ADC_PPUEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
#define ADC_GetSOCDelay(ePPU)               (ADC->ADCPPUSOCDLY[(ePPU)].all)




/******************************************************************************
 * @brief      Enable ADC PPU unit
 *
 * @param[in]  ePPU   :  Select PPU unit to be used
 *                       Please go to ADC_PPUEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
#define ADC_EnablePPU(ePPU)                 (ADC->ADCPPUCTL[ePPU].all |= ADCPPUCTL0_ALL_EN_ENABLE)




/******************************************************************************
 * @brief      Disable ADC PPU unit
 *
 * @param[in]  ePPU   :  Select PPU unit to be used
 *                       Please go to ADC_PPUEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
#define ADC_DisablePPU(ePPU)                (ADC->ADCPPUCTL[ePPU].bit.EN = ADCPPUCTL0_BIT_EN_DISABLE)




/******************************************************************************
 * @brief      Enable ADC PPU Interrupt
 *
 * @param[in]  ePPU   :  Select PPU unit to be used
 *                       Please go to ADC_PPUEnum for details
 * @param[in]  ePPUEvt:  Select PPU interrupt event
 *                       Please go to ADC_PPUEvtEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
#define ADC_EnablePPUInt(ePPU,ePPUEvt)      (ADC->ADCPPUIE[ePPU].all |= (0x1UL << ePPUEvt))




/******************************************************************************
 * @brief      Disable ADC PPU Interrupt
 *
 * @param[in]  ePPU   :  Select PPU unit to be used
 *                       Please go to ADC_PPUEnum for details
 * @param[in]  ePPUEvt:  Select PPU interrupt event
 *                       Please go to ADC_PPUEvtEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
#define ADC_DisablePPUInt(ePPU,ePPUEvt)     (ADC->ADCPPUIE[ePPU].all &= ~(0x1UL << ePPUEvt))




/******************************************************************************
 * @brief      Enable ADC PPU Trip-zone Event
 *
 * @param[in]  ePPU   :  Select PPU unit to be used
 *                       Please go to ADC_PPUEnum for details
 * @param[in]  ePPUEvt:  Select PPU interrupt event
 *                       Please go to ADC_PPUEvtEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
#define ADC_EnablePPUTripEvent(ePPU,ePPUEvt)  (ADC->ADCPPUTZE[ePPU].all |= (0x1UL << ePPUEvt))




/******************************************************************************
 * @brief      Disable ADC PPU Trip-zone Event
 *
 * @param[in]  ePPU   :  Select PPU unit to be used
 *                       Please go to ADC_PPUEnum for details
 * @param[in]  ePPUEvt:  Select PPU interrupt event
 *                       Please go to ADC_PPUEvtEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
#define ADC_DisablePPUTripEvent(ePPU,ePPUEvt) (ADC->ADCPPUTZE[ePPU].all &= ~(0x1UL << ePPUEvt))




/******************************************************************************
 * @brief      Clear ADC PPU Interrupt Flag
 *
 * @param[in]  ePPU   :  Select PPU unit to be used
 *                       Please go to ADC_PPUEnum for details
 * @param[in]  ePPUEvt:  Select PPU interrupt event
 *                       Please go to ADC_PPUEvtEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
#define ADC_ClearPPUInt(ePPU,ePPUEvt)       (ADC->ADCPPUIC[ePPU].all = (0x1UL << ePPUEvt))
#define ADC_ClearPPUGlobalInt(ePPU)         (ADC->ADCPPUIC[ePPU].all = ADCPPUIC0_ALL_INT_CLEAR)




/******************************************************************************
 * @brief      Get ADC PPU Interrupt Flag
 *
 * @param[in]  ePPU   :  Select PPU unit to be used
 *                       Please go to ADC_PPUEnum for details
 * @param[in]  ePPUEvt:  Select PPU interrupt event
 *                       Please go to ADC_PPUEvtEnum for details
 *
 * @return     0 - PPU event interrupt not occur
 *             1 - PPU event interrupt has occurred
 *
 ******************************************************************************/
#define ADC_GetPPUIntFlag(ePPU,ePPUEvt)     ((ADC->ADCPPUIF[ePPU].all & (0x1UL << ePPUEvt)) >> (ePPUEvt))
#define ADC_GetPPUGlobalIntFlag(ePPU)       (ADC->ADCPPUIF[ePPU].bit.INT)




/******************************************************************************
 * @brief      Set ADC PPU Reference
 *
 * @param[in]  ePPU  :  Select PPU unit to be used
 *                      Please go to ADC_PPUEnum for details
 * @param[in]  i32Val:  Reference value (-8192 ~ 8191)
 *
 * @return     none
 *
 ******************************************************************************/
#define ADC_SetPPURef(ePPU,i32Val)          (ADC->ADCPPUREF[ePPU].all = (i32Val))




/******************************************************************************
 * @brief      Set ADC PPU Too-High Threshold
 *
 * @param[in]  ePPU  :  Select PPU unit to be used
 *                      Please go to ADC_PPUEnum for details
 * @param[in]  i32Val:  Too-High Threshold value (-16384 ~ 16383)
 *
 * @return     none
 *
 ******************************************************************************/
#define ADC_SetPPUTooHighThreshold(ePPU,i32Val) (ADC->ADCPPUTHH[ePPU].all = (i32Val))




/******************************************************************************
 * @brief      Set ADC PPU Too-Low Threshold
 *
 * @param[in]  ePPU  :  Select PPU unit to be used
 *                      Please go to ADC_PPUEnum for details
 * @param[in]  i32Val:  Too-Low Threshold value (-16384 ~ 16383)
 *
 * @return     none
 *
 ******************************************************************************/
#define ADC_SetPPUTooLowThreshold(ePPU,i32Val)  (ADC->ADCPPUTHL[ePPU].all = (i32Val))




/******************************************************************************
 * @brief      Enable write access to the protected ADC registers
 *
 * @param[in]  none
 *
 * @return     none
 * 
 ******************************************************************************/
#define ADC_WALLOW()                        (ADC->ADCREGKEY.all = 0x1ACCE551)




/******************************************************************************
 * @brief      Disable write access to the protected ADC registers
 *
 * @param[in]  none
 *
 * @return     none
 * 
 ******************************************************************************/
#define ADC_WDIS()                          (ADC->ADCREGKEY.all = 0x0)



/**
 *  @brief  ADC Public Function Declaration
 */
void ADC_PowerUp(void);

void ADC_SetGainAndOffset(ADC_SocEnum eSOC);
void ADC_SetSampleAndConvertTime(ADC_SocEnum eSOC, uint32_t u32SampleTimeNs, uint32_t u32ConvTimeNs);
void ADC_SelectPinSingleEnded(ADC_SocEnum eSOC, uint8_t u8PinSel, ADC_TriggerSourceEnum eTrigSrc);
void ADC_SelectPinDifferetial(ADC_SocEnum eSOC, ADC_PinSelEnum u8PinSel_1, ADC_PinSelEnum u8PinSel_2, ADC_TriggerSourceEnum eTrigSrc);

void ADC_EasyInit1(ADC_SocEnum eSOC, uint8_t u8PinSel, ADC_TriggerSourceEnum eTrigSrc);
void ADC_EasyInit2(ADC_SocEnum eSOC, uint8_t u8PinSel_1, uint8_t u8PinSel_2, ADC_TriggerSourceEnum eTrigSrc);

ADC_TriggerSourceEnum ADC_TrigFromPWMxSOCA(PWM_REGS* PWMx);
ADC_TriggerSourceEnum ADC_TrigFromPWMxSOCB(PWM_REGS* PWMx);
ADC_TriggerSourceEnum ADC_TrigFromPWMxSOCC(PWM_REGS* PWMx);

void ADC_SetExternalSOC(GPIO_PinEnum ePinNum, uint8_t ePinLevel);

void ADC_PPUInit(ADC_PPUEnum ePPU, uint8_t u8DataSel, int32_t i32Ref, ADC_PPUPolEnum ePol);

int32_t ADC_CalculateTemperature(ADC_SocEnum eSOC);
int32_t ADC_CalculatePreciseTemperature(ADC_SocEnum eSOC);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* ADC_H */

/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
