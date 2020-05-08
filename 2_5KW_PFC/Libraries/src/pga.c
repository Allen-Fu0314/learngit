/******************************************************************************
 * @file     pga.c
 * @brief    PGA firmware functions.
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

#include "pga.h"




/******************************************************************************
 * @brief      Set Positive channel as commom mode signal
 *
 * @param[in]  ePGA:  Select the PGA module
 *                    See PGA_NumEnum for details
 *                     - \ref PGA0
 *                     - \ref PGA1
 *                     - \ref PGA2

 * @return     none
 *
 * @exmaple    If PGA is in differential mode, there should be two input signal
 *             One is common mode signal (VDD/2)
 *             One is signal signal(swaying among VDD/2)
 *             If PGA_DifferentialInit() is used, the common mode signal default comes into
 *             Negative channel, but SPC1168 supports common mode signal comes into
 *             Positive channel to make the flexibilty of PCB layout.
 *             Please note that even with such feature, the final signal polarity still 
 *             the same, thus
 *             Final signal = Gain * (PositiveCH - NegativeCH)
 *
 ******************************************************************************/
void PGA_SelectPositiveChannelAsCommonInput(PGA_NumEnum ePGA)
{
  switch(ePGA)
  {
    case PGA0:
      PGA->PGA0CTL.bit.CMSEL = PGA0CTL_BIT_CMSEL_POSITIVE_AS_COMMON;
      break;
    
    case PGA1:
      PGA->PGA1CTL.bit.CMSEL = PGA1CTL_BIT_CMSEL_POSITIVE_AS_COMMON;
      break;
    
    case PGA2:
      PGA->PGA2CTL.bit.CMSEL = PGA2CTL_BIT_CMSEL_POSITIVE_AS_COMMON;
      break;
  }
}




/******************************************************************************
 * @brief      Set Negative channel as commom mode signal 
 *
 * @param[in]  ePGA:  Select the PGA module
 *                    See PGA_NumEnum for details
 *                     - \ref PGA0
 *                     - \ref PGA1
 *                     - \ref PGA2

 * @return     none
 *
 * @exmaple    If PGA is in differential mode, there should be two input signal
 *             One is common mode signal (VDD/2)
 *             One is signal signal(swaying among VDD/2)
 *             If PGA_DifferentialInit() is used, the common mode signal default comes into
 *             Negative channel.
 *
 ******************************************************************************/
void PGA_SelectNegativeChannelAsCommonInput(PGA_NumEnum ePGA)
{
  switch(ePGA)
  {
    case PGA0:
      PGA->PGA0CTL.bit.CMSEL = PGA0CTL_BIT_CMSEL_NEGATIVE_AS_COMMON;
      break;
    
    case PGA1:
      PGA->PGA1CTL.bit.CMSEL = PGA1CTL_BIT_CMSEL_NEGATIVE_AS_COMMON;
      break;
    
    case PGA2:
      PGA->PGA2CTL.bit.CMSEL = PGA2CTL_BIT_CMSEL_NEGATIVE_AS_COMMON;
      break;
  }
}




/******************************************************************************
 * @brief      Set PGA in differetial ended mode
 *
 * @param[in]  ePGA       :  Select the PGA module from
 *                            PGA_NumEnum
 * @param[in]  ePositiveCH:  Select Positive Channel from 
 *                            PGA_CH_P
 * @param[in]  eNegativeCH:  Select Negative Channel from 
 *                            PGA_CH_N
 * @param[in]  eDiffGain  :  Select PGA amplitue scale from 
 *                            PGA_SCALE
 *
 * @return     none
 *
 * @exmaple    PGA_Init(PGA0,PGA0_CH_P_ADC0,PGA0_CH_N_ADC1,PGA_SCALE_8X)
 *             PGA_Init(PGA1,PGA1_CH_P_ADC10,PGA1_CH_N_ADC11,PGA_SCALE_8X)
 *             PGA_Init(PGA2,PGA2_CH_P_ADC12,PGA2_CH_N_ADC11,PGA_SCALE_8X)
 *
 ******************************************************************************/
void PGA_DifferentialInit(PGA_NumEnum ePGA, PGA_CH_P ePositiveCH, PGA_CH_N eNegativeCH, PGA_SCALE eDiffGain)
{
  /* Enable PGA(ADC) Module Clock */
  CLOCK_EnableModule(PGA_MODULE);
  
  /* Configure PGA */
  switch(ePGA)
  {
    case PGA0:
      PGA->PGA0CTL.all = (eDiffGain << PGA0CTL_ALL_GAINN_Pos) |  /* Negative path gain */
                         (eDiffGain << PGA0CTL_ALL_GAINP_Pos) |  /* Positive path gain */
                         ((eNegativeCH & 0xF) << PGA0CTL_ALL_INSELN_Pos) |  /* Negative input     */
                         ((ePositiveCH & 0xF) << PGA0CTL_ALL_INSELP_Pos) |  /* Positive input     */
                          PGA0CTL_ALL_CMSEL_NEGATIVE_AS_COMMON |  /* Select Negative as Common mode */
                          PGA0CTL_ALL_MODE_DIFF |                 /* Differential Mode */
                          PGA0CTL_ALL_EN_ENABLE;                  /* Enable PGA0 */
      break;
    
    case PGA1:
      PGA->PGA1CTL.all = (eDiffGain << PGA1CTL_ALL_GAINN_Pos) |  /* Negative path gain */
                         (eDiffGain << PGA1CTL_ALL_GAINP_Pos) |  /* Positive path gain */
                         ((eNegativeCH & 0xF) << PGA1CTL_ALL_INSELN_Pos) |  /* Negative input     */
                         ((ePositiveCH & 0xF) << PGA1CTL_ALL_INSELP_Pos) |  /* Positive input     */
                          PGA1CTL_ALL_CMSEL_NEGATIVE_AS_COMMON |  /* Select Negative as Common mode */
                          PGA1CTL_ALL_MODE_DIFF |                 /* Differential Mode */
                          PGA1CTL_ALL_EN_ENABLE;                  /* Enable PGA1 */
      break;
    
    case PGA2:
      PGA->PGA2CTL.all = (eDiffGain << PGA2CTL_ALL_GAINN_Pos) |  /* Negative path gain */
                         (eDiffGain << PGA2CTL_ALL_GAINP_Pos) |  /* Positive path gain */
                         ((eNegativeCH & 0xF) << PGA2CTL_ALL_INSELN_Pos) |  /* Negative input     */
                         ((ePositiveCH & 0xF) << PGA2CTL_ALL_INSELP_Pos) |  /* Positive input     */
                          PGA2CTL_ALL_CMSEL_NEGATIVE_AS_COMMON |  /* Select Negative as Common mode */
                          PGA2CTL_ALL_MODE_DIFF |                 /* Differential Mode */
                          PGA2CTL_ALL_EN_ENABLE;                  /* Enable PGA2 */
      break;
  }
}


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
