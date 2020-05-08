/******************************************************************************
 * @file     comp.c
 * @brief    Comparator firmware functions.
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


#include "comp.h"




/******************************************************************************
 * @brief      Configure Comparator
 *
 * @param[in]  eCOMP              :  Select the comparator
 *                                   See COMP_ComparatorSelEnum for details
 * @param[in]  eCH                :  Select the comparator input channel
 *                                   See COMP_CHSelEnum for details
 * @param[in]  i32DACVoltageMV    :  DAC voltage range from 0(0 voltage) ~ 3300 (3300 mV = 3.3 V)
 * @param[in]  u32DeglicthWindowNs:  Filter sample window (nero second)
 *                                   If Filter Clock =10MHZ, its range from 0~31*(1/10MHz)= 3100 ns= 3.1 us
 *
 * @return     none
 *
 * @note       (1) All 3 COMP_x_LO share same DAC_LO(DAC3)
 *             (2) All 3 COMP_x_HI share same DAC_HI(DAC2)
 *             (3) This function do NOT saturate DAC value and deglitch(filter) value, please note it!
 *
 ******************************************************************************/
void COMP_Init(COMP_ComparatorSelEnum eCOMP, COMP_CHSelEnum eCH, int32_t i32DACVoltageMV, uint32_t u32DeglicthWindowNs)
{
  /* Enable Comparator clock */
  CLOCK_EnableModule(COMP_MODULE);
  
  /* Enable comparator */
  COMP_Enable(eCOMP);
  
  /* Set Input channe1 */
  COMP_SelectChannel(eCOMP, eCH);
  
  /* Set Reference channel - All COMP use channel 2 : DAC2 as Too-High reference and DAC3 as Too-Low reference */
  switch(eCOMP)
  {
    case COMP_0_LO:
    case COMP_0_HI:
      COMP->COMP0CTL.bit.REFSEL = 2;
      break;
    
    case COMP_1_LO:
    case COMP_1_HI:
      COMP->COMP1CTL.bit.REFSEL = 2;
      break;
    
    case COMP_2_LO:
    case COMP_2_HI:
      COMP->COMP2CTL.bit.REFSEL = 2;
      break;
    
    case COMP_3_LO:
    case COMP_3_HI:
      COMP->COMP3CTL.bit.REFSEL = 2;
      break;
    
    case COMP_4_LO:
    case COMP_4_HI:
      COMP->COMP4CTL.bit.REFSEL = 2;
      break;
  }
  
  /* Set comparator output = Filtered */
  COMP_SetOutputType(eCOMP, COMP_OUTPUT_FILTERED);
  
  /* Set Filter Div */
  COMP_SetFilterClockDiv(eCOMP, 4);
  
  /* Set Filter window - Threshld value = 0.6 * Window Size */
  COMP_SetFilterWindowTimeNs(eCOMP, u32DeglicthWindowNs , u32DeglicthWindowNs * 3 / 5);

  /* Enable DAC for comparison */
  COMP_EnableDAC(DAC2);
  COMP_EnableDAC(DAC3);
  
  /* Set DAC value */
  switch(eCOMP)
  {
    case COMP_0_HI:
    case COMP_1_HI:
    case COMP_2_HI:
    case COMP_3_HI:
    case COMP_4_HI:
      COMP_SetDACVoltage(DAC2, i32DACVoltageMV);
      break;
    
    case COMP_0_LO:
    case COMP_1_LO:
    case COMP_2_LO:
    case COMP_3_LO:
    case COMP_4_LO:
      COMP_SetDACVoltage(DAC3, i32DACVoltageMV);
      break;
  }
  
  /* Clear latched filter status */
  COMP_ClearAllFilterOutputStatus();
}




/******************************************************************************
 * @brief      Set Filter Window Size (clock cycles)
 *
 * @param[in]  eCOMP     : Select the comparator
 * @param[in]  eOutputSel: Select the comparator output
 *
 * @return     none
 *
 ******************************************************************************/
void COMP_SetOutputType(COMP_ComparatorSelEnum eCOMP, COMP_OutputSelEnum eOutputSel)
{
  switch(eCOMP)
  {
    case COMP_0_LO:
      COMP->COMP0LCTL.bit.SEL4PWM = eOutputSel;
      break;
    
    case COMP_0_HI:
      COMP->COMP0HCTL.bit.SEL4PWM = eOutputSel;
      break;
    
    case COMP_1_LO:
      COMP->COMP1LCTL.bit.SEL4PWM = eOutputSel;
      break;
    
    case COMP_1_HI:
      COMP->COMP1HCTL.bit.SEL4PWM = eOutputSel;
      break;
    
    case COMP_2_LO:
      COMP->COMP2LCTL.bit.SEL4PWM = eOutputSel;
      break;
    
    case COMP_2_HI:
      COMP->COMP2HCTL.bit.SEL4PWM = eOutputSel;
      break;
    
    case COMP_3_LO:
      COMP->COMP3LCTL.bit.SEL4PWM = eOutputSel;
      break;
    
    case COMP_3_HI:
      COMP->COMP3HCTL.bit.SEL4PWM = eOutputSel;
      break;
    
    case COMP_4_LO:
      COMP->COMP4LCTL.bit.SEL4PWM = eOutputSel;
      break;
    
    case COMP_4_HI:
      COMP->COMP4HCTL.bit.SEL4PWM = eOutputSel;
      break;
  }
}




/******************************************************************************
 * @brief      Set Filter Window Size and Threshold
 *
 * @param[in]  eCOMP      : Select the comparator
 * @param[in]  u8Size     : Filter window size (1 ~ 32)
 * @param[in]  u8Threshold: Filter threshold value (1 ~ 32)
 *
 * @return     none
 *
 * @note       u8Threshold must bigger than u8Size/2
 *
 ******************************************************************************/
void COMP_SetFilterWindow(COMP_ComparatorSelEnum eCOMP, uint8_t u8Size, uint8_t u8Threshold)
{
  /* Invalid Window size */
  if((u8Size == 0) || (u8Size > 32))
  {
    return;
  }
  
  /* Invalid Window Threshold */
  if((u8Threshold == 0) || (u8Threshold > 32))
  {
    return;
  }
  
  /* Configure Filter Window */
  switch(eCOMP)
  {
    case COMP_0_LO:
      COMP->COMP0LCTL.bit.FLTWIN = u8Size - 1;
      COMP->COMP0LCTL.bit.FLTTH  = u8Threshold - 1;
      break;
    
    case COMP_0_HI:
      COMP->COMP0HCTL.bit.FLTWIN = u8Size - 1;
      COMP->COMP0HCTL.bit.FLTTH  = u8Threshold - 1;
      break;
    
    case COMP_1_LO:
      COMP->COMP1LCTL.bit.FLTWIN = u8Size - 1;
      COMP->COMP1LCTL.bit.FLTTH  = u8Threshold - 1;
      break;
    
    case COMP_1_HI:
      COMP->COMP1HCTL.bit.FLTWIN = u8Size - 1;
      COMP->COMP1HCTL.bit.FLTTH  = u8Threshold - 1;
      break;
    
    case COMP_2_LO:
      COMP->COMP2LCTL.bit.FLTWIN = u8Size - 1;
      COMP->COMP2LCTL.bit.FLTTH  = u8Threshold - 1;
      break;
    
    case COMP_2_HI:
      COMP->COMP2HCTL.bit.FLTWIN = u8Size - 1;
      COMP->COMP2HCTL.bit.FLTTH  = u8Threshold - 1;
      break;
    
    case COMP_3_LO:
      COMP->COMP3LCTL.bit.FLTWIN = u8Size - 1;
      COMP->COMP3LCTL.bit.FLTTH  = u8Threshold - 1;
      break;
    
    case COMP_3_HI:
      COMP->COMP3HCTL.bit.FLTWIN = u8Size - 1;
      COMP->COMP3HCTL.bit.FLTTH  = u8Threshold - 1;
      break;
    
    case COMP_4_LO:
      COMP->COMP4LCTL.bit.FLTWIN = u8Size - 1;
      COMP->COMP4LCTL.bit.FLTTH  = u8Threshold - 1;
      break;
    
    case COMP_4_HI:
      COMP->COMP4HCTL.bit.FLTWIN = u8Size - 1;
      COMP->COMP4HCTL.bit.FLTTH  = u8Threshold - 1;
      break;
  }
}



/******************************************************************************
 * @brief      Set Filter Window Size and Threshold (nero second)
 *
 * @param[in]  eCOMP             : Select the comparator
 * @param[in]  u32SizeTimeNS     : Window Size (Time in ns)
 * @param[in]  u32ThresholdTimeNS: Threshold (Time in ns)
 *
 * @return     none
 *
 ******************************************************************************/
void COMP_SetFilterWindowTimeNs(COMP_ComparatorSelEnum eCOMP, uint32_t u32SizeTimeNS, uint32_t u32ThresholdTimeNS)
{
  uint32_t u32TimeCnt1, u32TimeCnt2;
  uint32_t u32FilterClk;
  
  
  /* Comparator clock */
  u32FilterClk = CLOCK_GetModuleClock(COMP_MODULE);
  
  switch(eCOMP)
  {
    case COMP_0_LO:
      u32FilterClk /= (COMP->COMP0LCTL.bit.FLTDIV + 1);
      break;
    
    case COMP_0_HI:
      u32FilterClk /= (COMP->COMP0HCTL.bit.FLTDIV + 1);
      break;
    
    case COMP_1_LO:
      u32FilterClk /= (COMP->COMP1LCTL.bit.FLTDIV + 1);
      break;
    
    case COMP_1_HI:
      u32FilterClk /= (COMP->COMP1HCTL.bit.FLTDIV + 1);
      break;
    
    case COMP_2_LO:
      u32FilterClk /= (COMP->COMP2LCTL.bit.FLTDIV + 1);
      break;
    
    case COMP_2_HI:
      u32FilterClk /= (COMP->COMP2HCTL.bit.FLTDIV + 1);
      break;
    
    case COMP_3_LO:
      u32FilterClk /= (COMP->COMP3LCTL.bit.FLTDIV + 1);
      break;
    
    case COMP_3_HI:
      u32FilterClk /= (COMP->COMP3HCTL.bit.FLTDIV + 1);
      break;
    
    case COMP_4_LO:
      u32FilterClk /= (COMP->COMP4LCTL.bit.FLTDIV + 1);
      break;
    
    case COMP_4_HI:
      u32FilterClk /= (COMP->COMP4HCTL.bit.FLTDIV + 1);
      break;
  }
  
  /* Window size */
  u32TimeCnt1 = (((u32SizeTimeNS) * (u32FilterClk/100000)) / 10000);
  if(u32TimeCnt1 > 32) u32TimeCnt1 = 32;
  
  /* Threshold */
  u32TimeCnt2 = (((u32ThresholdTimeNS) * (u32FilterClk/100000)) / 10000);
  /* Threshold value must be bigger than WindowSize/2 */
  if((u32TimeCnt2 * 2) < u32TimeCnt1) u32TimeCnt2 = u32TimeCnt1 / 2 + 1;
  if(u32TimeCnt2 > 32) u32TimeCnt2 = 32;
  
  COMP_SetFilterWindow(eCOMP, u32TimeCnt1, u32TimeCnt2);
}




/******************************************************************************
 * @brief      Set Filter Clock Divider
 *
 * @param[in]  eCOMP    : Select the comparator
 *                        See COMP_ComparatorSelEnum for details
 * @param[in]  u16ClkDiv: Filter clock divider
 *
 * @return     none
 *
 ******************************************************************************/
void COMP_SetFilterClockDiv(COMP_ComparatorSelEnum eCOMP, uint16_t u16ClkDiv)
{
  if((u16ClkDiv == 0) || (u16ClkDiv > 1024)) return;
  
  switch(eCOMP)
  {
    case COMP_0_LO:
      COMP->COMP0LCTL.bit.FLTDIV = u16ClkDiv - 1;
      break;
    
    case COMP_0_HI:
      COMP->COMP0HCTL.bit.FLTDIV = u16ClkDiv - 1;
      break;
    
    case COMP_1_LO:
      COMP->COMP1LCTL.bit.FLTDIV = u16ClkDiv - 1;
      break;
    
    case COMP_1_HI:
      COMP->COMP1HCTL.bit.FLTDIV = u16ClkDiv - 1;
      break;
    
    case COMP_2_LO:
      COMP->COMP2LCTL.bit.FLTDIV = u16ClkDiv - 1;
      break;
    
    case COMP_2_HI:
      COMP->COMP2HCTL.bit.FLTDIV = u16ClkDiv - 1;
      break;
    
    case COMP_3_LO:
      COMP->COMP3LCTL.bit.FLTDIV = u16ClkDiv - 1;
      break;
    
    case COMP_3_HI:
      COMP->COMP3HCTL.bit.FLTDIV = u16ClkDiv - 1;
      break;
    
    case COMP_4_LO:
      COMP->COMP4LCTL.bit.FLTDIV = u16ClkDiv - 1;
      break;
    
    case COMP_4_HI:
      COMP->COMP4HCTL.bit.FLTDIV = u16ClkDiv - 1;
      break;
  }
}




/******************************************************************************
 * @brief      Set comparator hysteresis
 *
 * @param[in]  eCOMP   : Select the comparator
 *                       See COMP_ComparatorSelEnum for details
 * @param[in]  eHystSel: Select the hysteresis
 *                       See COMP_HystSelEnum for details
 *
 * @return     none
 *
 * @example    COMP_SetHysteresis(COMP_0_HI, COMP_HYST_12_MV);
 *
 ******************************************************************************/
void COMP_SetHysteresis(COMP_ComparatorSelEnum eCOMP, COMP_HystSelEnum eHystSel)
{
  switch(eCOMP)
  {
    case COMP_0_LO:
    case COMP_0_HI:
      COMP->COMP0CTL.bit.HYSTSEL = eHystSel;
      break;
    
    case COMP_1_LO:
    case COMP_1_HI:
      COMP->COMP1CTL.bit.HYSTSEL = eHystSel;
      break;
    
    case COMP_2_LO:
    case COMP_2_HI:
      COMP->COMP2CTL.bit.HYSTSEL = eHystSel;
      break;
    
    case COMP_3_LO:
    case COMP_3_HI:
      COMP->COMP3CTL.bit.HYSTSEL = eHystSel;
      break;
    
    case COMP_4_LO:
    case COMP_4_HI:
      COMP->COMP4CTL.bit.HYSTSEL = eHystSel;
      break;
  }
}




/******************************************************************************
 * @brief      Select the comparator input channel
 *
 * @param[in]  eCOMP:  Select the comparator
 *                     See COMP_ComparatorSelEnum for details
 * @param[in]  eCH  :  Select the comparator input channel
 *                     See COMP_CHSelEnum for details
 *
 * @return     none
 *
 * @example    COMP_SetChannel(COMP_0_HI,COMP0_FROM_PGA0N_OUT)
 *             The above means COMP_0_HI comparator input channel is from PGA0 negative output
 *
 ******************************************************************************/
void COMP_SelectChannel(COMP_ComparatorSelEnum eCOMP, COMP_CHSelEnum eCH)
{
  switch(eCOMP)
  {
    case COMP_0_LO:
    case COMP_0_HI:
      COMP->COMP0CTL.bit.INSEL = eCH & 0x0F;
      break;
    
    case COMP_1_LO:
    case COMP_1_HI:
      COMP->COMP1CTL.bit.INSEL = eCH & 0x0F;
      break;
    
    case COMP_2_LO:
    case COMP_2_HI:
      COMP->COMP2CTL.bit.INSEL = eCH & 0x0F;
      break;
    
    case COMP_3_LO:
    case COMP_3_HI:
      COMP->COMP3CTL.bit.INSEL = eCH & 0x0F;
      break;
    
    case COMP_4_LO:
    case COMP_4_HI:
      COMP->COMP4CTL.bit.INSEL = eCH & 0x0F;
      break;
  }
}




/******************************************************************************
 * @brief      Init DAC Buffer
 *
 * @param[in]  eDACSel : Select the DAC module
 *                       See COMP_DACSelEnum for details
 * @param[in]  bIsOut10: Output to GPIO10
 *                       TRUE or FALSE
 * @param[in]  bIsOut13: Output to GPIO13
 *                       TRUE or FALSE
 *
 * @return     none
 *
 ******************************************************************************/
void COMP_DACBufferInit(COMP_DACSelEnum eDACSel, BOOL bIsOut10, BOOL bIsOut13)
{
  COMP->DACBUFCTL.all = 0;
  
  /* Enable DAC Buffer */
  COMP->DACBUFCTL.bit.EN = DACBUFCTL_BIT_EN_ENABLE;
  
  /* Select DAC Buffer Input */
  COMP->DACBUFCTL.bit.INSEL = eDACSel;
  
  if(bIsOut10) COMP->DACBUFCTL.bit.OE10 = DACBUFCTL_BIT_OE10_ENABLE;
  if(bIsOut13) COMP->DACBUFCTL.bit.OE13 = DACBUFCTL_BIT_OE13_ENABLE;
}


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
