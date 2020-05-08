/*******************************************************************************
* @file     clock.h
* @brief    CLOCK module header file.
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


#ifndef CLOCK_H
#define CLOCK_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1168.h"




/**  
 *  @brief Peripheral Clock Control Module
 */
typedef enum
{
  ADC_MODULE            = 0x40,             /*!< ADC  Clock Control Module   */
  PGA_MODULE            = 0x40,             /*!< PGA  Clock Control Module   */
  COMP_MODULE           = 0x44,             /*!< COMP Clock Control Module   */
  PWM_MODULE            = 0x44,             /*!< PWM  Clock Control Module   */
  ECAP_MODULE           = 0x48,             /*!< ECAP Clock Control Module   */
  TIMER0_MODULE         = 0x4C,             /*!< Timer0 Clock Control Module */
  TIMER1_MODULE         = 0x50,             /*!< Timer1 Clock Control Module */
  TIMER2_MODULE         = 0x54,             /*!< Timer2 Clock Control Module */
  SIO0_MODULE           = 0x58,             /*!< SIO0 Clock Control Module   */
  
  UART_MODULE           = 0x68,             /*!< UART Clock Control Module   */
  SSP_MODULE            = 0x6C,             /*!< SSP  Clock Control Module   */
  I2C_MODULE            = 0x70,             /*!< I2C  Clock Control Module   */
  WDT0_MODULE           = 0x74,             /*!< WDT0 Clock Control Module   */
  WDT1_MODULE           = 0x78,             /*!< WDT1 Clock Control Module   */
} CLOCK_ModuleEnum;




/**  
 *  @brief Pre-defined system HCLK value
 */
typedef enum
{
  CLOCK_HCLK_50MHZ      =  (0),             /*!< System clock frequency = 50MHz  */
  CLOCK_HCLK_100MHZ     =  (1),             /*!< System clock frequency = 100MHz */
  CLOCK_HCLK_150MHZ     =  (2),             /*!< System clock frequency = 150MHz */
  CLOCK_HCLK_200MHZ     =  (3)              /*!< System clock frequency = 200MHz */
} CLOCK_HCLKSelEnum;




/**  
 *  @brief Pre-defined system clock source
 */
typedef enum
{
  CLOCK_FROM_RCO32MHZ   =  (0UL),           /*!< PLL reference clock = RCO0(32MHz) */
  CLOCK_FROM_XTAL6MHZ   =  (6000000UL),     /*!< PLL reference clock = XO(6MHz)    */
  CLOCK_FROM_XTAL8MHZ   =  (8000000UL),     /*!< PLL reference clock = XO(8MHz)    */
  CLOCK_FROM_XTAL12MHZ  =  (12000000UL),    /*!< PLL reference clock = XO(12MHz)   */
  CLOCK_FROM_XTAL24MHZ  =  (24000000UL),    /*!< PLL reference clock = XO(24MHz)   */
  CLOCK_FROM_XTAL32MHZ  =  (32000000UL)     /*!< PLL reference clock = XO(32MHz)   */
} CLOCK_RefSelEnum;




/******************************************************************************
 * @brief      Get the pointer to access the clock control register of the selected module
 *
 * @param[in]  eModule:  The peripheral module defined by CLOCK_ModuleEnum
 *
 * @return     none
 * 
 ******************************************************************************/
#define CLOCK_MODULECTL(eModule)            ((__IO WDT0CLKCTL_REG*)(CLOCK_BASE + (eModule)))




/******************************************************************************
 * @brief      Calculate the counter value according to clock frequency and 
 *             desired time in us, ns or ms
 *
 * @param[in]  u32Ns/u32Us/u32Ms:  Nero second / Micro second / Milli second
 * @param[in]  u32ClkHz         :  Clock frequency(Hz)
 *
 * @return     Clock cycle count
 *
 * @example    If there is a module with 1MHz working frequency and there is a 
 *             counter inside sourced as same as this module.
 *             If we want this counter in 5 us, the following code can help to design
 *             Module.Counter = CLOCK_NsToCounter(5,1000000)
 * 
 ******************************************************************************/
#define CLOCK_NsToCounter(u32Ns,u32ClkHz)   (((u32Ns)*((u32ClkHz)/100000))/10000)
#define CLOCK_UsToCounter(u32Us,u32ClkHz)   (((u32Us)*((u32ClkHz)/1000))/1000)
#define CLOCK_MsToCounter(u32Ms,u32ClkHz)   ((u32Ms)*((u32ClkHz)/1000))




/******************************************************************************
 * @brief      Enable write access to the protected CLOCK registers
 *
 * @param[in]  none
 *
 * @return     none
 * 
 ******************************************************************************/
#define CLOCK_WALLOW()                      (CLOCK->CLKREGKEY.all = 0x1ACCE551)




/******************************************************************************
 * @brief      Disable write access to the protected CLOCK registers
 *
 * @param[in]  none
 *
 * @return     none
 * 
 ******************************************************************************/
#define CLOCK_WDIS()                        (CLOCK->CLKREGKEY.all = 0x0)




/**
 *  @brief  CLOCK Public Function Declaration
 */
void CLOCK_TrimPLL(void);

void CLOCK_Init(CLOCK_RefSelEnum u32CLKSrcSel, CLOCK_HCLKSelEnum u32HCLK);
void CLOCK_InitWithRCO(CLOCK_HCLKSelEnum u32HCLKSel);

ErrorStatus CLOCK_ConfigurePLL(uint8_t u8RefClkFromXO, uint32_t u32RefClkHz, uint32_t u32PLLClk);
ErrorStatus CLOCK_ConfigurePLLWithRCO(uint32_t u32PLLClk);

void CLOCK_EnableModule(CLOCK_ModuleEnum eModule);
void CLOCK_DisableModule(CLOCK_ModuleEnum eModule);

void CLOCK_SetModuleDiv(CLOCK_ModuleEnum eModule, uint32_t u32Div);
uint32_t CLOCK_GetModuleDiv(CLOCK_ModuleEnum eModule);
uint32_t CLOCK_GetModuleClock(CLOCK_ModuleEnum eModule);




#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* CLOCK_H */


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
