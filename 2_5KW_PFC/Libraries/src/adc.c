/******************************************************************************
 * @file     adc.c
 * @brief    ADC firmware functions.
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
 
#include "adc.h"
#include <stdio.h>




/******************************************************************************
 * @brief      ADC power up
 *
 * @param[in]  none
 *
 * @return     none
 *
 * @note       Need to call it before using ADC
 *
 ******************************************************************************/
void ADC_PowerUp(void)
{
  volatile uint32_t i;
  
  /* Enable ADC Module Clock */
  CLOCK_EnableModule(ADC_MODULE);
  
  /* Enable ADC Bandgap */
  ADC->ADCBGCTL.all |= ADCBGCTL_ALL_EN_ENABLE;
  
  /* Delay 200us */
#if DELAY_FOR_MEM != DELAY_FOR_FLASH
  i = ((SystemCoreClock / 1000000) * 200 / 4);
#else
  i = ((SystemCoreClock / 1000000) * 200 / (4 * SystemCoreClock / 32000000));
#endif
  while(i--);
  
  /* Enable ADC reference */
  ADC->ADCREFCTL.bit.EN = ADCREFCTL_BIT_EN_ENABLE;
  
  /* Delay 200us */
#if DELAY_FOR_MEM != DELAY_FOR_FLASH
  i = ((SystemCoreClock / 1000000) * 200 / 4);
#else
  i = ((SystemCoreClock / 1000000) * 200 / (4 * SystemCoreClock / 32000000));
#endif
  while(i--);
  
  /* Enable ADC */
  ADC->ADCCTL.bit.EN = ADCCTL_BIT_EN_ENABLE_ADC;
  
  /* Reset ADC logic state machine */
  ADC_Reset();
}




/******************************************************************************
 * @brief      Configure the sample & conversion window size (ns) for SOC
 *
 * @param[in]  eSOC           :  Select SOC to be used from ADC_SocEnum
 *             u32SampleTimeNs:  Sample window time, no less than 125 ns
 *             u32ConvTimeNs  :  Convert window time
 *
 * @return     none
 *
 ******************************************************************************/
void ADC_SetSampleAndConvertTime(ADC_SocEnum eSOC, uint32_t u32SampleTimeNs, uint32_t u32ConvTimeNs)
{
  uint32_t u32ADCModuleClk,u32SampleTimeCnt,u32ConvTimeCnt;
  
  /* Get ADC Clock Frequency */
  u32ADCModuleClk = CLOCK_GetModuleClock(ADC_MODULE);
  
  /* Calculate Sample and Convert window size */
  u32SampleTimeCnt = ((u32ADCModuleClk / 100000) * u32SampleTimeNs) / 10000;
  u32ConvTimeCnt   = ((u32ADCModuleClk / 100000) * u32ConvTimeNs) / 10000 + 1;
  
  /* Saturation handling */
  if(u32SampleTimeCnt >= 255) u32SampleTimeCnt = 255;
  if(u32ConvTimeCnt >= 127)   u32ConvTimeCnt   = 127;
  
  ADC->ADCSOCCTL[eSOC].bit.SAMPCNT = u32SampleTimeCnt;   /* SAMPCNT is 8-bit length */
  ADC->ADCSOCCTL[eSOC].bit.CONVCNT = u32ConvTimeCnt;     /* CONVCNT is 7-bit length */
}




/******************************************************************************
 * @brief      Configure the gain and offset of the specified SOC
 *
 * @param[in]  eSOC:  Select SOC to be used from ADC_SocEnum
 *
 * @return     none
 *
 * @note       For simultaneous mode, Only ADC_SOC_0, ADC_SOC_3, ADC_SOC_6, 
 *             ADC_SOC_9, ADC_SOC_12 is valid.
 *
 ******************************************************************************/
void ADC_SetGainAndOffset(ADC_SocEnum eSOC)
{
  switch(ADC->ADCSOCCTL[eSOC].bit.SHEN)
  {
    case ADCSOCCTL0_BIT_SHEN_SHA:   /* Sampler A */
      ADC->ADCGAIN[eSOC].all   = ADC->ADCGAINA.all;
      ADC->ADCOFFSET[eSOC].all = ADC->ADCOFFSETA.all;
      break;
      
    case ADCSOCCTL0_BIT_SHEN_SHB:   /* Sampler B */
      ADC->ADCGAIN[eSOC].all   = ADC->ADCGAINB.all;
      ADC->ADCOFFSET[eSOC].all = ADC->ADCOFFSETB.all;
      break;
    
    case ADCSOCCTL0_BIT_SHEN_SHC:   /* Sampler C */
      ADC->ADCGAIN[eSOC].all   = ADC->ADCGAINC.all;
      ADC->ADCOFFSET[eSOC].all = ADC->ADCOFFSETC.all;
      break;
    
    case ADCSOCCTL0_BIT_SHEN_SHA_AND_SHB: /* S/H A and B imultaneous mode */
      ADC->ADCGAIN[eSOC].all   = ADC->ADCGAINA.all;
      ADC->ADCOFFSET[eSOC].all = ADC->ADCOFFSETA.all;
      
      ADC->ADCGAIN[eSOC + 1].all   = ADC->ADCGAINB.all;
      ADC->ADCOFFSET[eSOC + 1].all = ADC->ADCOFFSETB.all;
      break;
    
    case ADCSOCCTL0_BIT_SHEN_SHB_AND_SHC: /* S/H B and C imultaneous mode */
      ADC->ADCGAIN[eSOC + 1].all   = ADC->ADCGAINB.all;
      ADC->ADCOFFSET[eSOC + 1].all = ADC->ADCOFFSETB.all;
      
      ADC->ADCGAIN[eSOC + 2].all   = ADC->ADCGAINC.all;
      ADC->ADCOFFSET[eSOC + 2].all = ADC->ADCOFFSETC.all;
      break;
    
    case ADCSOCCTL0_BIT_SHEN_SHA_AND_SHC: /* S/H A and C imultaneous mode */
      ADC->ADCGAIN[eSOC].all   = ADC->ADCGAINA.all;
      ADC->ADCOFFSET[eSOC].all = ADC->ADCOFFSETA.all;
      
      ADC->ADCGAIN[eSOC + 2].all   = ADC->ADCGAINC.all;
      ADC->ADCOFFSET[eSOC + 2].all = ADC->ADCOFFSETC.all;
      break;
    
    case ADCSOCCTL0_BIT_SHEN_SHA_AND_SHB_AND_SHC: /* S/H A and B and C imultaneous mode */
      ADC->ADCGAIN[eSOC].all   = ADC->ADCGAINA.all;
      ADC->ADCOFFSET[eSOC].all = ADC->ADCOFFSETA.all;
      
      ADC->ADCGAIN[eSOC + 1].all   = ADC->ADCGAINB.all;
      ADC->ADCOFFSET[eSOC + 1].all = ADC->ADCOFFSETB.all;
      
      ADC->ADCGAIN[eSOC + 2].all   = ADC->ADCGAINC.all;
      ADC->ADCOFFSET[eSOC + 2].all = ADC->ADCOFFSETC.all;
      break;
    
    default:
      break;
  }
}




/******************************************************************************
 * @brief      Select ADC trigger source (PWMxSOCA) according to PWM module
 *
 * @param[in]  PWMx:  PWM module
 *             - \ref PWM0
 *             - \ref PWM1
 *             ...
 *             - \ref PWM5
 *
 * @return     ADC_TriggerSourceEnum
 *
 ******************************************************************************/
ADC_TriggerSourceEnum ADC_TrigFromPWMxSOCA(PWM_REGS* PWMx)
{
  uint32_t u32PWMModuleNum;
  
  u32PWMModuleNum = (((uint32_t)PWMx) & 0x0F00UL) >> 8;
  
//  printf("PWM%d TrigSrc=%d\n",u32PWMModuleNum,(ADCTRIG_PWM0A + u32PWMModuleNum*3));
  
  return (ADC_TriggerSourceEnum)(ADCTRIG_PWM0SOCA + u32PWMModuleNum * 3);
}




/******************************************************************************
 * @brief      Select ADC trigger source (PWMxSOCB) according to PWM module
 *
 * @param[in]  PWMx:  PWM module
 *             - \ref PWM0
 *             - \ref PWM1
 *             ...
 *             - \ref PWM5
 *
 * @return     ADC_TriggerSourceEnum
 *
 ******************************************************************************/
ADC_TriggerSourceEnum ADC_TrigFromPWMxSOCB(PWM_REGS* PWMx)
{
  uint32_t u32PWMModuleNum;
  
  u32PWMModuleNum = (((uint32_t)PWMx) & 0x0F00UL) >> 8;
  
//  printf("PWM%d TrigSrc=%d\n",u32PWMModuleNum,(ADCTRIG_PWM0B + u32PWMModuleNum*3));
  
  return (ADC_TriggerSourceEnum)(ADCTRIG_PWM0SOCB + u32PWMModuleNum * 3);
}




/******************************************************************************
 * @brief      Select ADC trigger source (PWMxSOCC) according to PWM module
 *
 * @param[in]  PWMx:  PWM module
 *             - \ref PWM0
 *             - \ref PWM1
 *             ...
 *             - \ref PWM5
 *
 * @return     ADC_TriggerSourceEnum
 *
 ******************************************************************************/
ADC_TriggerSourceEnum ADC_TrigFromPWMxSOCC(PWM_REGS* PWMx)
{
  uint32_t u32PWMModuleNum;
  
  u32PWMModuleNum = (((uint32_t)PWMx) & 0x0F00UL) >> 8;
  
//  printf("PWM%d TrigSrc=%d\n",u32PWMModuleNum,(ADCTRIG_PWM0B + u32PWMModuleNum * 3));
  
  return (ADC_TriggerSourceEnum)(ADCTRIG_PWM0SOCC + u32PWMModuleNum * 3);
}




/******************************************************************************
 * @brief      This function is only for single-ended use, that is 
 *             (1) The signal ternimal selected by u8PinSel
 *             (2) The other terminal is internal GND 
 *             (3) Default sampling time is ADC_DEFAULT_SAMPLE_TIME_NS(default 150ns) 
 *                 and conversion time is ADC_DEFAULT_CONVERSION_TIME_NS(default 150ns) 
 *                 Total time = 300ns = 3.33MHz SPS rate
 *             (4) This function will auto-set selected pin as analog pin
 *                 If user select pin outside the range of ADC pin, it will not effect.
 *
 * @param[in]  eSOC    :  Select SOC to be used (ADC_SOC_0 ~ ADC_SOC_15)
 * @param[in]  u8PinSel:  Select the ADC input pin
 *                        It can be GPIO pin number or Pin defined in adc.h
 *
 *                        GPIO_PinEnum  (Only support ADC pin GPIO0~GPIO15)
 *                        Please do NOT use GPIO16 ~ GPIO40!
 *
 *                        If user want to use internal signal like VDD12, please use this type
 *                        ADC_PinSelEnum

 * @param[in]  eTrigSrc:  Select the trigger source
 *                        Please goto ADC_TriggerSourceEnum for detail

 * @return     none
 *
 * @example    (1) Initial SOC1 to get ADC2(GPIO_2) signal with software trigger
 *                 ADC_EasyInit1(ADC_SOC_1,GPIO_2,ADCTRIG_Software);
 *                 or
 *                 ADC_EasyInit1(ADC_SOC_1,ADC2_GPIO2,ADCTRIG_Software);
 *
 *             (2) Initial SOC2 to get internal VDD12 signal with PWM trigger
 *                 ADC_EasyInit1(ADC_SOC_2,ADCx_VDD12,ADCTRIG_PWM0A);
 *
 *             (3) Initial SOC3 to get GPIO5(ADC5) signal with software trigger
 *                 <1> ADC_EasyInit1(ADC_SOC_3,GPIO_5,ADCTRIG_Software);
 *                 <2> Software trigger
 *                     ADC_SoftwareTrigger(ADC_SOC_3);
 *                 <3> Get value when data ready
 *                     ADC_GetTrimResult1(ADC_SOC_3); --> Take longer cpu cycle but accuracy (Recommend)
 *                     
 *                     ADC_GetRawResult(ADC_SOC_3); --> Raw data, user should determine polarity and calibration.
 *
 ******************************************************************************/
void ADC_EasyInit1(ADC_SocEnum eSOC, uint8_t u8PinSel, ADC_TriggerSourceEnum eTrigSrc)
{
  ADC_PowerUp();
  
  ADC_SelectPinSingleEnded(eSOC,u8PinSel,eTrigSrc);
  
  ADC_SetSampleAndConvertTime(eSOC,ADC_DEFAULT_SAMPLE_TIME_NS,ADC_DEFAULT_CONVERSION_TIME_NS);
  
  ADC_SetGainAndOffset(eSOC);
  
  ADC_EnableInt(eSOC);

  /* Only GPIO0(ADC0)~GPIO15(ADC15) can be configured as Analog Pin */
  if(u8PinSel < GPIO_16) GPIO_SetPinAsAnalog((GPIO_PinEnum)u8PinSel);
}




/******************************************************************************
 * @brief      This function is for differential mode, that is
 *             (1) Default sampling time is ADC_DEFAULT_SAMPLE_TIME_NS(default 150ns) 
 *                 and conversion time is ADC_DEFAULT_CONVERSION_TIME_NS(default 150ns) 
 *                 Total time = 300ns = 3.33MHz SPS rate
 *             (2) This function will auto-set selected pin as analog pin
 *                 If user select pin outside the range of ADC pin, it will not effect.
 *
 * @param[in]  eSOC     :  Select SOC to be used
 * @param[in]  u8PinSel_1:  Select the first terminal ADC pin
 *                          It can be GPIO pin number or Pin defined in adc.h
 *
 *                          GPIO_PinEnum  (Only support ADC pin GPIO0~GPIO15)
 *                          Please do NOT use GPIO16~GPIO40!
 *
 *                          If user want to use internal signal like VDD12, please use this type
 *                          ADC_PinSelEnum
 *
 * @param[in]  u8PinSel_2:  Select the second terminal ADC pin
 * @param[in]  eTrigSrc  :  Select the trigger source
 *                          Please goto ADC_TriggerSourceEnum for detail
 *
 * @return     none
 *
 * @details    Be sure to select pin as descripted as figure in datasheet
 *             SPC1168 do not support dedicated pins to differential mode
 *             Example : 
 *                Wrong  --> ADC_EasyInit2(ADC_SOC_5, ADC4_GPIO4, ADC3_GPIO3, ADCTRIG_Software);
 *                Correct -> ADC_EasyInit2(ADC_SOC_5, ADC2_GPIO2, ADC3_GPIO3, ADCTRIG_Software);
 *             Please #define SPC1168_DRIVER_DEBUG 1 when develop, there is an error message printf in
 *             ADC_SelectPinDifferetial() to help user debug.
 *
 * @example    Initial SOC3 to get differential signal between GPIO2(ADC2) and GPIO3(ADC3) signal 
 *             with software trigger
 *                 <1> ADC_EasyInit2(ADC_SOC_3,GPIO_2,GPIO_3,ADCTRIG_Software);
 *                 <2> Software trigger
 *                     ADC_SoftwareTrigger(ADC_SOC_3);
 *                 <3> Get value when data ready
 *                     ADC_GetTrimResult2(ADC_SOC_3); --> Take longer cpu cycle but accuracy (Recommend)
 *                     
 *                     ADC_GetRawResult(ADC_SOC_3);  --> Raw data, user should determine polarity and calibration.
 *
 * @note       ADC_EasyInit2(ADC_SOC_3,GPIO_2,GPIO_3,ADCTRIG_Software);
 *             and
 *             ADC_EasyInit2(ADC_SOC_3,GPIO_3,GPIO_2,ADCTRIG_Software);
 *             Are the same, the polarity of GPIO2(ADC2) and GPIO3(ADC3) is determined in 
 *             ADC hardware channel structure, please read the datasheet for details.
 *
 ******************************************************************************/
void ADC_EasyInit2(ADC_SocEnum eSOC, uint8_t u8PinSel_1, uint8_t u8PinSel_2, ADC_TriggerSourceEnum eTrigSrc)
{
  ADC_PowerUp();
  
  ADC_SelectPinDifferetial(eSOC, (ADC_PinSelEnum)u8PinSel_1, (ADC_PinSelEnum)u8PinSel_2, eTrigSrc);
  
  ADC_SetSampleAndConvertTime(eSOC,ADC_DEFAULT_SAMPLE_TIME_NS,ADC_DEFAULT_CONVERSION_TIME_NS);
  
  ADC_SetGainAndOffset(eSOC);
  
  ADC_EnableInt(eSOC);

  /* Only GPIO0(ADC0)~GPIO15(ADC15) can be configured as Analog Pin */
  if(u8PinSel_1 < GPIO_16) GPIO_SetPinAsAnalog((GPIO_PinEnum)u8PinSel_1);
  if(u8PinSel_2 < GPIO_16) GPIO_SetPinAsAnalog((GPIO_PinEnum)u8PinSel_2);
}




/******************************************************************************
 * @brief      Get ADC Input Pin Code
 *             Encode logic for ADC Input pin: Sampler(4-bit) + Channel (4-bit)
 *             Sampler - \ref 8  SHA Positive    - \ref 9  SHA Negative
 *                     - \ref A  SHB Positive    - \ref B  SHB Negative
 *                     - \ref C  SHC Positive    - \ref D  SHC Negative
 *
 * @param[in]  u8PinSel :  Select the ADC input pin
 *                         It can be GPIO pin number or Pin defined in adc.h
 *                         GPIO_PinEnum (Only support ADC pin GPIO0~GPIO15)

 *                         Please do NOT use GPIO16~GPIO40!
 *
 *                         If user want to use internal signal like VDD12, please use this type
 *                         ADC_PinSelEnum
 *
 * @return     ADC Input Pin Code
 *
 ******************************************************************************/
uint8_t ADC_GetInputPinCode(uint8_t u8PinSel)
{
  uint8_t u8PinCode = 0;
  
  /* Set Pin code */
  switch(u8PinSel)
  {
    case GPIO_0:
      u8PinCode = 0x84;
      break;
    
    case GPIO_1:
      u8PinCode = 0x94;
      break;
    
    case GPIO_2:
      u8PinCode = 0x85;
      break;
    
    case GPIO_3:
      u8PinCode = 0x95;
      break;
    
    case GPIO_4:
      u8PinCode = 0xA5;
      break;
    
    case GPIO_5:
      u8PinCode = 0xB5;
      break;
    
    case GPIO_6:
      u8PinCode = 0xC5;
      break;
    
    case GPIO_7:
      u8PinCode = 0xD5;
      break;
    
    case GPIO_8:
      u8PinCode = 0x86;
      break;
    
    case GPIO_9:
      u8PinCode = 0x96;
      break;
    
    case GPIO_10:
      u8PinCode = 0x87;
      break;
    
    case GPIO_11:
      u8PinCode = 0x97;
      break;
    
    case GPIO_12:
      u8PinCode = 0xA7;
      break;
    
    case GPIO_13:
      u8PinCode = 0xB7;
      break;
    
    case GPIO_14:
      u8PinCode = 0xC7;
      break;
    
    case GPIO_15:
      u8PinCode = 0xD7;
      break;
    
    default:    /* Other ADC Input Pin */
      u8PinCode = u8PinSel;
      break;
  }
  
  return u8PinCode;
}




/******************************************************************************
 * @brief      Configure ADC channel for single-ended
 *             It can auto configure SHA or SHB by the channel structure designed in ADC
 *             The other terminal is default as internal GND.
 *
 * @param[in]  eSOC    :  Select SOC to be used (ADC_SOC_0 ~ ADC_SOC_15)
 * @param[in]  u8PinSel:  Select the ADC input pin
 *                        It can be GPIO pin number or Pin defined in adc.h
 *                        GPIO_PinEnum  (Only support ADC pin GPIO0~GPIO15)

 *                        Please do NOT use GPIO16~GPIO40!
 *
 *                        If user want to use internal signal like VDD12, please use this type
 *                        ADC_PinSelEnum

 * @param[in]  eTrigSrc:  Select the trigger source
 *                        Please goto ADC_TriggerSourceEnum for detail
 *
 * @return     none
 *
 ******************************************************************************/
void ADC_SelectPinSingleEnded(ADC_SocEnum eSOC, uint8_t u8PinSel, ADC_TriggerSourceEnum eTrigSrc)
{
  /* Pin code */
  uint8_t  u8PinCode = 0;
  
  /* Sample/Hold Selection */
  uint32_t u32SHSel  = 0;
  
  /* Positive channel selection */
  uint32_t u32CHPSel = 0;
  
  /* Negative channel selection */
  uint32_t u32CHNSel = 0;
  
  
  /* Get ADC Input Pin code */
  u8PinCode = ADC_GetInputPinCode(u8PinSel);
  
  /* Configure S/H and Channel Selection */
  switch((u8PinCode & 0xF0) >> 4)
  {
    case 8:   /* SHA Positive */
      u32SHSel  = ADCSOCCTL0_BIT_SHEN_SHA;
      u32CHPSel = u8PinCode & 0x0F;
      u32CHNSel = 0;  /* GND */
      break;
    
    case 9:   /* SHA Negative */
      u32SHSel  = ADCSOCCTL0_BIT_SHEN_SHA;
      u32CHPSel = 0;  /* GND */
      u32CHNSel = u8PinCode & 0x0F;
      break;
    
    case 0xA:   /* SHB Positive */
      u32SHSel  = ADCSOCCTL0_BIT_SHEN_SHB;
      u32CHPSel = u8PinCode & 0x0F;
      u32CHNSel = 0;  /* GND */
      break;
    
    case 0xB:   /* SHB Negative */
      u32SHSel  = ADCSOCCTL0_BIT_SHEN_SHB;
      u32CHPSel = 0;  /* GND */
      u32CHNSel = u8PinCode & 0x0F;
      break;
    
    case 0xC:   /* SHC Positive */
      u32SHSel  = ADCSOCCTL0_BIT_SHEN_SHC;
      u32CHPSel = u8PinCode & 0x0F;
      u32CHNSel = 0;  /* GND */
      break;
    
    case 0xD:   /* SHC Negative */
      u32SHSel  = ADCSOCCTL0_BIT_SHEN_SHC;
      u32CHPSel = 0;  /* GND */
      u32CHNSel = u8PinCode & 0x0F;
      break;
    
    default:
      break;
  }
  
  /* Configure SOC */
  ADC->ADCSOCCTL[eSOC].all = (u32SHSel << ADCSOCCTL0_ALL_SHEN_Pos) | 
                              ((eTrigSrc) << ADCSOCCTL0_ALL_TRIGSEL_Pos) | 
                              (u32CHNSel << ADCSOCCTL0_ALL_CHSELN_Pos) | 
                              (u32CHPSel << ADCSOCCTL0_ALL_CHSELP_Pos);

#if SPC1168_DRIVER_DEBUG == 1
  if((u8PinSel >= GPIO_16) && (u8PinSel <= GPIO_40))
  {
    printf("Error in ADC_SelectPinSingleEnded\n");
    while(1){};
  }
#endif
}




/******************************************************************************
 * @brief      Configure ADC channel for differential mode
 *
 * @param[in]  eSOC      :  Select SOC to be used
 * @param[in]  u8PinSel_1:  Select the first terminal ADC pin 
 *                          It can be ADC_PinSelEnum or GPIO_PinEnum
 * @param[in]  u8PinSel_2:  Select the second terminal ADC pin 
 *                          It can be ADC_PinSelEnum or GPIO_PinEnum
 * @param[in]  eTrigSrc  :  Select the trigger source
 *                          Please goto ADC_TriggerSourceEnum for detail
 *
 * @return     none
 *
 * @details    Be sure to select pin as descripted as figure in datasheet
 *             SPC1168 do not support dedicated pins to differential mode
 *             Example : 
 *                Wrong  --> ADC_SelectPinDifferetial(ADC_SOC_5, ADC4_GPIO4, ADC3_GPIO3, ADCTRIG_Software);
 *                Correct -> ADC_SelectPinDifferetial(ADC_SOC_5, ADC2_GPIO2, ADC3_GPIO3, ADCTRIG_Software);
 *             Please 
 *                      #define SPC1168_DRIVER_DEBUG 1 
 *             when develop, there is an error message printf in ADC_SelectPinDifferetial() to help user debug.
 *
 ******************************************************************************/
void ADC_SelectPinDifferetial(ADC_SocEnum eSOC, ADC_PinSelEnum u8PinSel_1, ADC_PinSelEnum u8PinSel_2,ADC_TriggerSourceEnum eTrigSrc)
{
  /* Pin code */
  uint8_t  u8PinCode1 = 0;
  uint8_t  u8PinCode2 = 0;
  
  /* Sample/Hold Selection */
  uint32_t u32SHSel  = 0;
  
  /* Positive channel selection */
  uint32_t u32CHPSel = 0;
  
  /* Negative channel selection */
  uint32_t u32CHNSel = 0;
  
  
  /* Get ADC Input Pin code */
  u8PinCode1 = ADC_GetInputPinCode(u8PinSel_1);
  u8PinCode2 = ADC_GetInputPinCode(u8PinSel_2);
  
  /* Configure S/H and Channel Selection */
  switch((u8PinCode1 & 0xF0) >> 4)
  {
    case 8:   /* SHA Positive */
      u32SHSel  = ADCSOCCTL0_BIT_SHEN_SHA;
      u32CHPSel = u8PinCode1 & 0x0F;
      u32CHNSel = u8PinCode2 & 0x0F;
      break;
    
    case 9:   /* SHA Negative */
      u32SHSel  = ADCSOCCTL0_BIT_SHEN_SHA;
      u32CHPSel = u8PinCode2 & 0x0F;
      u32CHNSel = u8PinCode1 & 0x0F;
      break;
    
    case 0xA:   /* SHB Positive */
      u32SHSel  = ADCSOCCTL0_BIT_SHEN_SHB;
      u32CHPSel = u8PinCode1 & 0x0F;
      u32CHNSel = u8PinCode2 & 0x0F;
      break;
    
    case 0xB:   /* SHB Negative */
      u32SHSel  = ADCSOCCTL0_BIT_SHEN_SHB;
      u32CHPSel = u8PinCode2 & 0x0F;
      u32CHNSel = u8PinCode1 & 0x0F;
      break;
    
    case 0xC:   /* SHC Positive */
      u32SHSel  = ADCSOCCTL0_BIT_SHEN_SHC;
      u32CHPSel = u8PinCode1 & 0x0F;
      u32CHNSel = u8PinCode2 & 0x0F;
      break;
    
    case 0xD:   /* SHC Negative */
      u32SHSel  = ADCSOCCTL0_BIT_SHEN_SHC;
      u32CHPSel = u8PinCode2 & 0x0F;
      u32CHNSel = u8PinCode1 & 0x0F;
      break;
    
    default:
      break;
  }
  
  /* Configure SOC */
  ADC->ADCSOCCTL[eSOC].all = (u32SHSel << ADCSOCCTL0_ALL_SHEN_Pos) | 
                              ((eTrigSrc) << ADCSOCCTL0_ALL_TRIGSEL_Pos) | 
                              (u32CHNSel << ADCSOCCTL0_ALL_CHSELN_Pos) | 
                              (u32CHPSel << ADCSOCCTL0_ALL_CHSELP_Pos);
  
  
#if SPC1168_DRIVER_DEBUG == 1
  if(ABS((u8PinCode1 & 0x0F) - (u8PinCode2 & 0x0F)) != 0x10)
  {
    printf("Error in ADC_SelectPinDifferetial\n");
    while(1){};
  }
  
  printf("CHA Enable = %d\n",ADC->ADCSOCCTL[eSOC].bit.SHEN);
  printf("CH SEL Negative  = %d\n",ADC->ADCSOCCTL[eSOC].bit.CHSELN);
  printf("CH SEL Positive  = %d\n",ADC->ADCSOCCTL[eSOC].bit.CHSELP);
#endif
}




/******************************************************************************
 * @brief      Configure ADC external SOC input
 *
 * @param[in]  ePinNum  :  Select the GPIO pin number
 *                         Please goto GPIO_PinEnum for selection
 *             ePinLevel:  Select the GPIO pin level to generate Sync event
 *                         Please goto GPIO_LevelEnum for selection
 * @return     none
 *
 ******************************************************************************/
void ADC_SetExternalSOC(GPIO_PinEnum ePinNum, uint8_t ePinLevel)
{
  /* Set Pin as GPIO input */
  GPIO_SetPinAsGPIO(ePinNum);
  GPIO_SetPinDir(ePinNum, GPIO_INPUT);
  
  ADC->ADCEXTSOCCTL.all = ePinNum | (ePinLevel << ADCEXTSOCCTL_ALL_POL_Pos);
}




/******************************************************************************
 * @brief      Init ADC PPU unit
 *
 * @param[in]  ePPU     :  Select the PPU unit
 *                         Please go to ADC_PPUEnum for details
 * @param[in]  u8DataSel:  Select the ADC result to compare with the reference (0 ~ 15)
 * @param[in]  i32Ref   :  Reference value (-8192 ~ 8191)
 * @param[in]  ePol     :  Select the polarity for PPU comparision
 *                         Please go to ADC_PPUPolEnum for details
 *
 * @return     none
 * 
 ******************************************************************************/
void ADC_PPUInit(ADC_PPUEnum ePPU, uint8_t u8DataSel, int32_t i32Ref, ADC_PPUPolEnum ePol)
{
  /* Enable PPU and Select ADC result */
  ADC->ADCPPUCTL[ePPU].all = ADCPPUCTL0_ALL_EN_ENABLE | ((u8DataSel) << ADCPPUCTL0_ALL_DATASEL_Pos);
  
  /* Polarity for comparision */
  ADC->ADCPPUCTL[ePPU].bit.POL = ePol;
  
  /* Set Reference */
  ADC->ADCPPUREF[ePPU].all = i32Ref;
}




/******************************************************************************
 * @brief      Calculate temperature
 *
 * @param[in]  eSOC:  Select SOC to be used
 *
 * @return     none
 *
 ******************************************************************************/
int32_t ADC_CalculateTemperature(ADC_SocEnum eSOC)
{
  volatile uint32_t i, j;
  uint32_t u32DivOld, u32DivNew;
  int32_t i32ADCCode;
  int32_t i32TempAvg;
  
  /* Power up ADC */
  ADC_PowerUp();
  
  /* Save Old divider */
  u32DivOld = CLOCK_GetModuleDiv(ADC_MODULE);
  
  /* Set new ADC Clock Divider - Set ADC Clock = 1MHZ */
  u32DivNew = CLOCK_GetModuleClock(ADC_MODULE) / 1000000;
  CLOCK->ADCCLKCTL.bit.DIV = (u32DivNew - 1);
  
  /* Select T-Sensor as ADC input */
  ADC_SelectPinDifferetial(eSOC, ADCx_TSENSOR_H, ADCx_TSENSOR_L, ADCTRIG_Software);
  
  /* Set Sample and Convert time */
  ADC_SetSampleAndConvertTime(eSOC,255000,4000);
  
  /* Set S/H gain and offset */
  ADC_SetGainAndOffset(eSOC);
  
  /* Set Average Count */
  ADC_SetAverageCnt(eSOC, ADCSOCCTL0_BIT_AVGCNT_AVG_32);
  
  /* Enable SOC interrupt */
  ADC_EnableInt(eSOC);
  
  /* Clear interrupt flag */
  ADC_ClearInt(eSOC);
  
  
  /* Enable T-Sensor */
  ADC->TSENSCTL.bit.EN = 1;
  ADC->TSENSCTL.bit.OUTINV = 0;
  ADC->TSENSCTL.bit.DEMSEL = 0;
  ADC->TSENSCTL.bit.SWAPBJT = 0;
  
  i32ADCCode = 0;
  
  /* Use ADC to measure T-Sensor by DEM */
  ADC->TSENSCTL.bit.SWAPBJT = 0;
  for(j = 0; j < 16; j++)
  {
    /* Alter internal bias current */
    ADC->TSENSCTL.bit.DEMSEL = j;
    
    /* Delay 1ms */
#if DELAY_FOR_MEM != DELAY_FOR_FLASH
    i = ((SystemCoreClock / 1000000) * 1000 / 4);
#else
    i = ((SystemCoreClock / 1000000) * 1000 / (4 * SystemCoreClock / 32000000));
#endif
    while(i--);
    
    /* Software trigger SOC */
    ADC_SoftwareTrigger(eSOC);
    
    /* Wait SOC Finished */
    while(ADC_GetIntFlag(eSOC) == 0);
    
    i32ADCCode += (int32_t)ADC->ADCRESULT[eSOC].all;
    
    /* Clear interrupt flag */
    ADC_ClearInt(eSOC);
  }
  
  
  /* Alter current between ADCx_TSENSOR_H and ADCx_TSENSOR_L */
  ADC->TSENSCTL.bit.SWAPBJT = 1;
  for(j = 0; j < 16; j++)
  {
    /* Alter internal bias current */
    ADC->TSENSCTL.bit.DEMSEL = j;
    
    /* Delay 1ms */
#if DELAY_FOR_MEM != DELAY_FOR_FLASH
    i = ((SystemCoreClock / 1000000) * 1000 / 4);
#else
    i = ((SystemCoreClock / 1000000) * 1000 / (4 * SystemCoreClock / 32000000));
#endif
    while(i--);
    
    /* Software trigger SOC */
    ADC_SoftwareTrigger(eSOC);
    
    /* Wait SOC Finished */
    while(ADC_GetIntFlag(eSOC) == 0);
    
    i32ADCCode -= (int32_t)ADC->ADCRESULT[eSOC].all;
    
    /* Clear interrupt flag */
    ADC_ClearInt(eSOC);
  }

  /* Average ADC code */
  i32ADCCode /= 32 ;

  /* Calculate temperature */
  i32TempAvg = TSENSOR_SLOPE * (i32ADCCode * (float)3.657f / 8192) - TSENSOR_OFFSET;
  
  /* Restore ADC Clock Divider */
  CLOCK->ADCCLKCTL.bit.DIV = u32DivOld - 1;
  
  /* Restore ADC SOC register */
  ADC->ADCSOCCTL[eSOC].all = 0;
  ADC_DisableInt(eSOC);
  ADC->TSENSCTL.all = 0;

  return i32TempAvg;
}




/******************************************************************************
 * @brief      Calculate temperature more precise
 *
 * @param[in]  eSOC:  Select SOC to be used
 *
 * @return     none
 *
 ******************************************************************************/
int32_t ADC_CalculatePreciseTemperature(ADC_SocEnum eSOC)
{
  volatile uint32_t i, j;
  uint32_t u32DivOld, u32DivNew;
  int32_t i32ADCCode;
  int32_t i32TempAvg;
  
  /* Power up ADC */
  ADC_PowerUp();
  
  /* Save Old divider */
  u32DivOld = CLOCK_GetModuleDiv(ADC_MODULE);
  
  /* Set new ADC Clock Divider - Set ADC Clock = 1MHZ */
  u32DivNew = CLOCK_GetModuleClock(ADC_MODULE) / 1000000;
  CLOCK->ADCCLKCTL.bit.DIV = (u32DivNew - 1);
  
  
  /* Init PGA2 */
  PGA_DifferentialInit(PGA2, PGA2_CH_P_TSENSOR_H, PGA2_CH_N_TSENSOR_L, PGA_SCALE_8X);
  PGA_SelectPositiveChannelAsCommonInput(PGA2);
  
  
  /* Select T-Sensor as ADC input */
  ADC_SelectPinDifferetial(eSOC, ADCx_PGA2P, ADCx_PGA2N, ADCTRIG_Software);
  
  /* Set Sample and Convert time */
  ADC_SetSampleAndConvertTime(eSOC,255000,4000);
  
  /* Set S/H gain and offset */
  ADC_SetGainAndOffset(eSOC);
  
  /* Set Average Count */
  ADC_SetAverageCnt(eSOC, ADCSOCCTL0_BIT_AVGCNT_AVG_32);
  
  /* Enable SOC interrupt */
  ADC_EnableInt(eSOC);
  
  /* Clear interrupt flag */
  ADC_ClearInt(eSOC);
  
  
  /* Enable T-Sensor */
  ADC->TSENSCTL.bit.EN = 1;
  ADC->TSENSCTL.bit.OUTINV = 0;
  ADC->TSENSCTL.bit.DEMSEL = 0;
  ADC->TSENSCTL.bit.SWAPBJT = 0;
  
  i32ADCCode = 0;
  
  /* Use ADC to measure T-Sensor by DEM */
  ADC->TSENSCTL.bit.SWAPBJT = 0;
  for(j = 0; j < 16; j++)
  {
    /* Alter internal bias current */
    ADC->TSENSCTL.bit.DEMSEL = j;
    
    /* Delay 1ms */
#if DELAY_FOR_MEM != DELAY_FOR_FLASH
    i = ((SystemCoreClock / 1000000) * 1000 / 4);
#else
    i = ((SystemCoreClock / 1000000) * 1000 / (4 * SystemCoreClock / 32000000));
#endif
    while(i--);
    
    /* Software trigger SOC */
    ADC_SoftwareTrigger(eSOC);
    
    /* Wait SOC Finished */
    while(ADC_GetIntFlag(eSOC) == 0);
    
    i32ADCCode += (int32_t)ADC->ADCRESULT[eSOC].all;
    
    /* Clear interrupt flag */
    ADC_ClearInt(eSOC);
  }
  
  
  /* Alter current between ADCx_TSENSOR_H and ADCx_TSENSOR_L */
  ADC->TSENSCTL.bit.SWAPBJT = 1;
  for(j = 0; j < 16; j++)
  {
    /* Alter internal bias current */
    ADC->TSENSCTL.bit.DEMSEL = j;
    
    /* Delay 1ms */
#if DELAY_FOR_MEM != DELAY_FOR_FLASH
    i = ((SystemCoreClock / 1000000) * 1000 / 4);
#else
    i = ((SystemCoreClock / 1000000) * 1000 / (4 * SystemCoreClock / 32000000));
#endif
    while(i--);
    
    /* Software trigger SOC */
    ADC_SoftwareTrigger(eSOC);
    
    /* Wait SOC Finished */
    while(ADC_GetIntFlag(eSOC) == 0);
    
    i32ADCCode -= (int32_t)ADC->ADCRESULT[eSOC].all;
    
    /* Clear interrupt flag */
    ADC_ClearInt(eSOC);
  }

  /* Average ADC code */
  i32ADCCode /= 32 ;

  /* Calculate temperature */
  i32TempAvg = TSENSOR_SLOPE * (i32ADCCode * (float)3.657f / 8192 / 8) - TSENSOR_OFFSET;
  
  /* Restore ADC Clock Divider */
  CLOCK->ADCCLKCTL.bit.DIV = u32DivOld - 1;
  
  /* Restore ADC SOC register */
  ADC->ADCSOCCTL[eSOC].all = 0;
  ADC_DisableInt(eSOC);
  ADC->TSENSCTL.all = 0;
  
  /* Restore PGA register */
  PGA->PGA2CTL.all = 0;
  
  return i32TempAvg;
}


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
