/******************************************************************************
 * @file     clock.c
 * @brief    CLOCK firmware functions.
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


#include "clock.h"




/**
 *  @brief  RCO clock frequency
 */
#define __RCO_CLOCK               (32000000UL)




/**
 *  @brief  Oscillator frequency
 */
#define __XO_CLOCK                ( 8000000UL)




/******************************************************************************
 * @brief      PLL VCO frequency trimming
 *
 * @param[in]  none
 *
 * @return     none
 * 
 ******************************************************************************/
void CLOCK_TrimPLL(void)
{
  uint32_t u32VCOTrim;
  
  /* Enable PLL */
  CLOCK->PLLCTL0.bit.EN       = PLLCTL0_BIT_EN_ENABLE;
  /* Enable open-loop mode for VCO trimming */
  CLOCK->PLLCTL0.bit.OPENLOOP = PLLCTL0_BIT_OPENLOOP_OPEN_LOOP;
  /* Enable PLL frequency calibration */
  CLOCK->PLLCTL0.bit.FCALEN   = PLLCTL0_BIT_FCALEN_ENABLE;
  
  /* VCO frequency trimming */
  for(u32VCOTrim = 0; u32VCOTrim < 8; u32VCOTrim++)
  {
    /* Set VCO trim value */
    CLOCK->PLLCTL0.bit.VCOTRIM = u32VCOTrim;
    
    /* Enable PLL frequency calibration time window */
    CLOCK->PLLCTL0.bit.FCALWIN = PLLCTL0_BIT_FCALWIN_ENABLE;
    
    /* Wait VCOFREQ signal valid */
    while(CLOCK->CLKSTS.bit.VCOFREQVLD == CLKSTS_BIT_VCOFREQVLD_INVALID);
    /* If VCO frequency is too fast, finish calibration */
    if(CLOCK->CLKSTS.bit.VCOFREQ == CLKSTS_BIT_VCOFREQ_TOO_FAST) break;
    
    /* Disable PLL frequency calibration time window */
    CLOCK->PLLCTL0.bit.FCALWIN = PLLCTL0_BIT_FCALWIN_DISABLE;
  }
  
  /* Restore to default value */
  CLOCK->PLLCTL0.bit.FCALEN   = PLLCTL0_BIT_FCALEN_DISABLE;
  CLOCK->PLLCTL0.bit.OPENLOOP = PLLCTL0_BIT_OPENLOOP_CLOSE_LOOP;
  CLOCK->PLLCTL0.bit.EN       = PLLCTL0_BIT_EN_DISABLE;
}




/******************************************************************************
 * @brief      Configure chip clock system
 *
 * @param[in]  u32HCLKSel  :  HCLK frequency selection defined by CLOCK_HCLKSelEnum
 * @param[in]  u32CLKSrcSel:  Reference clock selection defined by CLOCK_RefSelEnum
 *
 * @return     none
 * 
 * @note       In this function:
 *             - Select PLL as system clock source
 *             - HCLK frequency equal to the system clock frequency
 *             - PCLK, SSPCLK and I2CCLK frequency is limited to less than 50MHz
 *             - Select PLL as periheral clock source
 *             - Peripheral clock freqency (except SSP and I2C) equal to system clock
 *
 * @example    (1)  CLOCK_Init(CLOCK_FROM_XTAL6MHZ,CLOCK_HCLK_25MHZ);
 *             (2)  CLOCK_Init(CLOCK_FROM_RCO24MHZ,CLOCK_HCLK_200MHZ);
 *
 ******************************************************************************/
                                  /* 50MHz    100MHz    150MHz    200MHz */
uint32_t gau32PLL_Array[4]      = {50000000,100000000,150000000,200000000};
uint8_t  gau8HCLK_DIV_Array[4]  = {       1,        1,        1,        1};
uint8_t  gau8PCLK_DIV_Array[4]  = {       1,        2,        3,        4};

void CLOCK_Init(CLOCK_RefSelEnum u32CLKSrcSel,CLOCK_HCLKSelEnum u32HCLKSel)
{
  uint32_t u32PLLClock;
  uint32_t u32HCLKDiv;
  uint32_t u32PCLKDiv;

  u32PLLClock = gau32PLL_Array[u32HCLKSel];
  u32HCLKDiv  = gau8HCLK_DIV_Array[u32HCLKSel];
  u32PCLKDiv  = gau8PCLK_DIV_Array[u32HCLKSel];

  if(u32CLKSrcSel == 0UL)
  {
    /* Select RCO as reference */
    CLOCK_ConfigurePLL(0, 32000000, u32PLLClock);
  }
  else
  {
    CLOCK_ConfigurePLL(1, u32CLKSrcSel, u32PLLClock);
  }

  /* Update PCLK, UARTCLK, SSPCLK, I2CCLK and HCLK dividing ratio */
  CLOCK->PCLKCTL.bit.DIV    = (u32PCLKDiv - 1);
  CLOCK->UARTCLKCTL.bit.DIV = (u32PCLKDiv - 1);
  CLOCK->SSPCLKCTL.bit.DIV  = (u32PCLKDiv - 1);
  CLOCK->I2CCLKCTL.bit.DIV  = (u32PCLKDiv - 1);
  CLOCK->HCLKCTL.bit.DIV    = (u32HCLKDiv - 1);
  
  /* Update system information */
  SysInfo.u32HCLK = u32PLLClock / u32HCLKDiv;
  SysInfo.u32PCLK = u32PLLClock / u32PCLKDiv;
  SystemCoreClock = SysInfo.u32HCLK;

  /* Select PLL clock as system clock */
  CLOCK->SYSCLK0CTL.bit.SRC = SYSCLK0CTL_BIT_SRC_PLL;
  CLOCK->SYSCLK1CTL.bit.SRC = SYSCLK1CTL_BIT_SRC_PLL;
  
  /* Configure peripheral clock source */
  CLOCK->WDT0CLKCTL.bit.SRC = WDT0CLKCTL_BIT_SRC_PLL;
  CLOCK->WDT1CLKCTL.bit.SRC = WDT1CLKCTL_BIT_SRC_PLL;
  
  /* Configure peripheral clock dividing ratio */
  CLOCK->ADCCLKCTL.bit.DIV  = (u32HCLKDiv - 1);
  CLOCK->PWMCLKCTL.bit.DIV  = (u32HCLKDiv - 1);
  CLOCK->ECAPCLKCTL.bit.DIV = (u32HCLKDiv - 1);
  CLOCK->TMR0CLKCTL.bit.DIV = (u32HCLKDiv - 1);
  CLOCK->TMR1CLKCTL.bit.DIV = (u32HCLKDiv - 1);
  CLOCK->TMR2CLKCTL.bit.DIV = (u32HCLKDiv - 1);
  
  CLOCK->WDT0CLKCTL.bit.DIV = (u32HCLKDiv - 1);
  CLOCK->WDT1CLKCTL.bit.DIV = (u32HCLKDiv - 1);
}




/******************************************************************************
 * @brief      Configure chip clock system with RCO0 as reference
 *
 * @param[in]  u32HCLKSel:  HCLK frequency selection defined by CLOCK_HCLKSelEnum
 *
 * @return     none
 * 
 * @note       In this function:
 *             - Select PLL as system clock source
 *             - HCLK frequency equal to the system clock frequency
 *             - PCLK, SSPCLK and I2CCLK frequency is limited to less than 50MHz
 *             - Select PLL as periheral clock source
 *             - Peripheral clock freqency (except SSP and I2C) equal to system clock
 *
 * @example    (1)  CLOCK_InitWithRCO(CLOCK_HCLK_25MHZ);
 *             (2)  CLOCK_InitWithRCO(CLOCK_HCLK_200MHZ);
 *
 ******************************************************************************/
void CLOCK_InitWithRCO(CLOCK_HCLKSelEnum u32HCLKSel)
{
  uint32_t u32PLLClock;
  uint32_t u32HCLKDiv;
  uint32_t u32PCLKDiv;
  
  u32PLLClock = gau32PLL_Array[u32HCLKSel];
  u32HCLKDiv  = gau8HCLK_DIV_Array[u32HCLKSel];
  u32PCLKDiv  = gau8PCLK_DIV_Array[u32HCLKSel];

  /* Configure PLL clock */
  CLOCK_ConfigurePLLWithRCO(u32PLLClock);

  /* Update PCLK, UARTCLK, SSPCLK, I2CCLK and HCLK dividing ratio */
  CLOCK->PCLKCTL.bit.DIV   = (u32PCLKDiv - 1);
  CLOCK->UARTCLKCTL.bit.DIV = (u32PCLKDiv - 1);
  CLOCK->SSPCLKCTL.bit.DIV = (u32PCLKDiv - 1);
  CLOCK->I2CCLKCTL.bit.DIV = (u32PCLKDiv - 1);
  CLOCK->HCLKCTL.bit.DIV   = (u32HCLKDiv - 1);
  
  /* Update system information */
  SysInfo.u32HCLK = u32PLLClock / u32HCLKDiv;
  SysInfo.u32PCLK = u32PLLClock / u32PCLKDiv;
  SystemCoreClock = SysInfo.u32HCLK;

  /* Select PLL clock as system clock */
  CLOCK->SYSCLK0CTL.bit.SRC = SYSCLK0CTL_BIT_SRC_PLL;
  CLOCK->SYSCLK1CTL.bit.SRC = SYSCLK1CTL_BIT_SRC_PLL;
  
  /* Configure peripheral clock source */
  CLOCK->WDT0CLKCTL.bit.SRC = WDT0CLKCTL_BIT_SRC_PLL;
  CLOCK->WDT1CLKCTL.bit.SRC = WDT1CLKCTL_BIT_SRC_PLL;
  
  /* Configure peripheral clock dividing ratio */
  CLOCK->ADCCLKCTL.bit.DIV  = (u32HCLKDiv - 1);
  CLOCK->PWMCLKCTL.bit.DIV  = (u32HCLKDiv - 1);
  CLOCK->ECAPCLKCTL.bit.DIV = (u32HCLKDiv - 1);
  CLOCK->TMR0CLKCTL.bit.DIV = (u32HCLKDiv - 1);
  CLOCK->TMR1CLKCTL.bit.DIV = (u32HCLKDiv - 1);
  CLOCK->TMR2CLKCTL.bit.DIV = (u32HCLKDiv - 1);
  
  CLOCK->WDT0CLKCTL.bit.DIV = (u32HCLKDiv - 1);
  CLOCK->WDT1CLKCTL.bit.DIV = (u32HCLKDiv - 1);
}




/******************************************************************************
 * @brief      Configure PLL clock
 *
 * @param[in]  u8RefClkFromXO:  Reference clock selection
 *                               - \ref 1 -> clock source(reference) is from external crystal clock
 *                               - \ref 0 -> clock source(reference) is from internal RCO(32MHz)
 * @param[in]  u32RefClkHz   :  Reference clock frequency (Hz)
 * @param[in]  u32PLLClk     :  PLL output clock frequency (Hz)
 *
 * @return     SUCCESS or ERROR
 *
 ******************************************************************************/
ErrorStatus CLOCK_ConfigurePLL(uint8_t u8RefClkFromXO, uint32_t u32RefClkHz, uint32_t u32PLLClk)
{
  uint32_t u32TimeOut;
  uint32_t u32FVCOClk;
  uint32_t u32NOUT, u32NIN, u32NFB;

  
  u32TimeOut = 1000;
  
  /* Select RCO0 as system clock */
  CLOCK->RCO0CTL.all |= RCO0CTL_ALL_EN_ENABLE;
  while(CLOCK->CLKSTS.bit.RCO0RDY == CLKSTS_BIT_RCO0RDY_NOT_READY)
  {
    if((u32TimeOut--) == 0) return ERROR;
  }
  CLOCK->SYSCLK1CTL.bit.SRC = SYSCLK1CTL_BIT_SRC_RCO0;
  CLOCK->SYSCLK0CTL.bit.SRC = SYSCLK0CTL_BIT_SRC_RCO0;
  
  
  /* Enable XO */
  if(u8RefClkFromXO == 1)
  {
    CLOCK->XOCTL.bit.PRECNT = 0xFF;
    
    /* Use internal feedback resistor */
    CLOCK->XOCTL.bit.EXTRFB = XOCTL_BIT_EXTRFB_DISABLE;
    
    /* Select crystal frequency range */
    if(u32RefClkHz < 12000000)
    {
      CLOCK->XOCTL.bit.FREQSEL = 0;
    }
    else if(u32RefClkHz < 24000000)
    {
      CLOCK->XOCTL.bit.FREQSEL = 1;
    }
    else if(u32RefClkHz < 42000000)
    {
      CLOCK->XOCTL.bit.FREQSEL = 2;
    }
    else
    {
      CLOCK->XOCTL.bit.FREQSEL = 3;
    }
    
    /* Enable XO */
    CLOCK->XOCTL.bit.EN = XOCTL_BIT_EN_ENABLE;
    
    /* Wait XO ready */
    u32TimeOut = 100000;
    while(CLOCK->CLKSTS.bit.XORDY == CLKSTS_BIT_XORDY_NOT_READY)
    {
      if((u32TimeOut--) == 0) return ERROR;
    }
  }
  
  
  /* NIN number */
  if(u32RefClkHz <= 8000000)
  {
    u32NIN = 1;
  }
  else
  {
    u32NIN = u32RefClkHz / 8000000;
    
    if((u32RefClkHz % 8000000) != 0) u32NIN++;
  }

  /* NOUT number */
  u32FVCOClk = 600000000; /* Fvco = 600MHz */
  u32NOUT = (u32FVCOClk / u32PLLClk) - 1;
  
  /* NFB Number */
  u32NFB = ((u32PLLClk / 1000000) * (u32NOUT + 1) * u32NIN) * 65536 / (u32RefClkHz / 1000000);
  
  
  /* Set NIN, NOUT and NFB */
  CLOCK->PLLCTL1.bit.NIN  = u32NIN;
  CLOCK->PLLCTL1.bit.NOUT = u32NOUT;
  CLOCK->PLLCTL1.bit.NFB  = u32NFB;
  
  /* Set ICP */
  CLOCK->PLLCTL0.bit.ICP = (96 * u32NFB) / (14 - CLOCK->PLLCTL0.bit.VCOTRIM) / 65536 / 100;
  
  /* Select PLL reference clock */
  CLOCK->PLLCTL0.bit.RCLKSELXO = u8RefClkFromXO;

  /* Enable PLL and output */
  CLOCK->PLLCTL0.all |= (PLLCTL0_ALL_EN_ENABLE | PLLCTL0_ALL_OE_ENABLE);
  
  
  /* Wait PLL clock ready */
  u32TimeOut = 100000;
  while(CLOCK->CLKSTS.bit.PLLRDY == CLKSTS_BIT_PLLRDY_NOT_READY)
  {
    if((u32TimeOut--) == 0) return ERROR;
  }

  return SUCCESS;
}




/******************************************************************************
 * @brief      Configure PLL clock with reference from RCO0
 *
 * @param[in]  u32PLLClk:  PLL clock output frequency (Hz)
 *
 * @return     SUCCESS or ERROR
 *
 ******************************************************************************/
ErrorStatus CLOCK_ConfigurePLLWithRCO(uint32_t u32PLLClk)
{
  uint32_t u32TimeOut;
  uint32_t u32FVCOClk;
  uint32_t u32NOUT, u32NIN, u32NFB;

  
  u32TimeOut = 1000;
  
  /* Select RCO0 as system clock */
  CLOCK->RCO0CTL.all |= RCO0CTL_ALL_EN_ENABLE;
  while(CLOCK->CLKSTS.bit.RCO0RDY == CLKSTS_BIT_RCO0RDY_NOT_READY)
  {
    if((u32TimeOut--) == 0) return ERROR;
  }
  CLOCK->SYSCLK1CTL.bit.SRC = SYSCLK1CTL_BIT_SRC_RCO0;
  CLOCK->SYSCLK0CTL.bit.SRC = SYSCLK0CTL_BIT_SRC_RCO0;
  
  
  /* NIN number */
  u32NIN = 4;

  /* NOUT number */
  u32FVCOClk = 600000000; /* Fvco = 600MHz */
  u32NOUT = (u32FVCOClk / u32PLLClk) - 1;
  
  /* NFB Number */
  u32NFB = ((u32PLLClk / 1000000) * (u32NOUT + 1) * u32NIN) * 65536 / (__RCO_CLOCK / 1000000);
  
  
  /* Set NIN, NOUT and NFB */
  CLOCK->PLLCTL1.bit.NIN  = u32NIN;
  CLOCK->PLLCTL1.bit.NOUT = u32NOUT;
  CLOCK->PLLCTL1.bit.NFB  = u32NFB;
  
  /* Set ICP */
  CLOCK->PLLCTL0.bit.ICP = (96 * u32NFB) / (14 - CLOCK->PLLCTL0.bit.VCOTRIM) / 65536 / 100;
  
  /* Select RCO0 as reference clock */
  CLOCK->PLLCTL0.bit.RCLKSELXO = PLLCTL0_BIT_RCLKSELXO_RCO0;

  /* Enable PLL and output */
  CLOCK->PLLCTL0.all |= (PLLCTL0_ALL_EN_ENABLE | PLLCTL0_ALL_OE_ENABLE);
  
  
  /* Wait PLL clock ready */
  u32TimeOut = 100000;
  while(CLOCK->CLKSTS.bit.PLLRDY == CLKSTS_BIT_PLLRDY_NOT_READY)
  {
    if((u32TimeOut--) == 0) return ERROR;
  }
  
  return SUCCESS;
}




/******************************************************************************
 * @brief      Enable the clock of the selected peripheral module
 *
 * @param[in]  eModule:  The peripheral module defined by CLOCK_ModuleEnum
 *
 * @return     none
 *
 * @example    CLOCK_EnableModule(ADC_MODULE);
 *
 ******************************************************************************/
void CLOCK_EnableModule(CLOCK_ModuleEnum eModule)
{
  if(eModule == SSP_MODULE)
  {
    CLOCK->SSPCLKCTL.bit.EN = 1;
  }
  else
  {
    CLOCK_MODULECTL(eModule)->bit.EN = 1;
  }
}




/******************************************************************************
 * @brief      Disable the clock of the selected peripheral module
 *
 * @param[in]  eModule:  The peripheral module defined by CLOCK_ModuleEnum
 *
 * @return     none
 *
 * @example    CLOCK_DisableModule(ADC_MODULE);
 *
 ******************************************************************************/
void CLOCK_DisableModule(CLOCK_ModuleEnum eModule)
{
  if(eModule == SSP_MODULE)
  {
    CLOCK->SSPCLKCTL.bit.EN = 0;
  }
  else
  {
    CLOCK_MODULECTL(eModule)->bit.EN = 0;
  }
}




/******************************************************************************
 * @brief      Set the clock dividing ratio of the selected peripheral module
 *
 * @param[in]  eModule:  The peripheral module defined by CLOCK_ModuleEnum
 * @param[in]  u32Div :  Clock dividingw ratio value
 *
 * @return     none
 *
 * @example    CLOCK_SetModuleDiv(PWM_MODULE, 2);
 *             CLOCK_SetModuleDiv(ADC_MODULE, 4);
 *
 ******************************************************************************/
void CLOCK_SetModuleDiv(CLOCK_ModuleEnum eModule, uint32_t u32Div)
{
  if(eModule == SSP_MODULE)
  {
    CLOCK->SSPCLKCTL.bit.DIV = (u32Div - 1);
  }
  else
  {
    CLOCK_MODULECTL(eModule)->bit.DIV = (u32Div - 1);
  }
}




/******************************************************************************
 * @brief      Get the clock dividing ratio of the selected peripheral module
 *
 * @param[in]  eModule:  The peripheral module defined by CLOCK_ModuleEnum
 *
 * @return     Clock dividing ratio value range from 1~64
 * 
 ******************************************************************************/
uint32_t CLOCK_GetModuleDiv(CLOCK_ModuleEnum eModule)
{
  uint32_t u32Div;
  
  if(eModule == SSP_MODULE)
  {
    u32Div = CLOCK->SSPCLKCTL.bit.DIV;
  }
  else
  {
    u32Div = CLOCK_MODULECTL(eModule)->bit.DIV;
  }
  
  return (u32Div + 1);
}




/******************************************************************************
 * @brief      Get the clock frequency (Hz) of the selected peripheral module
 *
 * @param[in]  eModule:  The peripheral module defined by CLOCK_ModuleEnum
 *
 * @return     Clock frequency in Hz
 *
 * @note       This function can only excute correctly after CLOCK_Init()
 * 
 ******************************************************************************/
uint32_t CLOCK_GetModuleClock(CLOCK_ModuleEnum eModule)
{
  uint32_t u32Div, u32Clk;
  
  u32Div = CLOCK_GetModuleDiv(eModule);
  
  u32Clk = SystemCoreClock / u32Div;

  return u32Clk;
}


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
