/******************************************************************************
 * @file     power.c
 * @brief    POWER firmware functions.
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

#include "power.h"




/******************************************************************************
 * @brief      VDD12H BOD Init
 *
 * @param[in]  eAssert  :  Select the threshold voltage to assert VDD12H when 3.3V supply is going high
 *                         Please go to POWER_VDD12HEnum for details
 * @param[in]  eDeassert:  Select the threshold voltage to deassert VDD12H when 3.3V supply is going low
 *                         Please go to POWER_VDD12HEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
void POWER_VDD12HBODInit(POWER_VDD12HEnum eAssert, POWER_VDD12HEnum eDeassert)
{
  /* Set VDD12H assert threshold */
  POWER->BOD12CTL.bit.ASVTHH = eAssert;
  
  /* Set VDD12H deassert threshold */
  POWER->BOD12CTL.bit.DEVTHH = eDeassert;
  
  /* Enable VDD12H BOD */
  POWER->BOD12CTL.bit.ENH = BOD12CTL_BIT_ENH_ENABLE;
}




/******************************************************************************
 * @brief      VDD12L0 BOD Init
 *
 * @param[in]  eAssert  :  Select the threshold voltage to assert VDD12L0 when 1.2V supply is going high
 *                         Please go to POWER_VDD12LEnum for details
 * @param[in]  eDeassert:  Select the threshold voltage to deassert VDD12L0 when 1.2V supply is going low
 *                         Please go to POWER_VDD12LEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
void POWER_VDD12L0BODInit(POWER_VDD12LEnum eAssert, POWER_VDD12LEnum eDeassert)
{
  /* Set VDD12L0 assert threshold */
  POWER->BOD12CTL.bit.ASVTHL0 = eAssert;
  
  /* Set VDD12L0 deassert threshold */
  POWER->BOD12CTL.bit.DEVTHL0 = eDeassert;
  
  /* Enable VDD12L0 BOD */
  POWER->BOD12CTL.bit.ENL0 = BOD12CTL_BIT_ENL0_ENABLE;
}




/******************************************************************************
 * @brief      VDD12L1 BOD Init
 *
 * @param[in]  eAssert  :  Select the threshold voltage to assert VDD12L1 when 1.2V supply is going high
 *                         Please go to POWER_VDD12LEnum for details
 * @param[in]  eDeassert:  Select the threshold voltage to deassert VDD12L1 when 1.2V supply is going low
 *                         Please go to POWER_VDD12LEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
void POWER_VDD12L1BODInit(POWER_VDD12LEnum eAssert, POWER_VDD12LEnum eDeassert)
{
  /* Set VDD12L1 assert threshold */
  POWER->BOD12CTL.bit.ASVTHL1 = eAssert;
  
  /* Set VDD12L1 deassert threshold */
  POWER->BOD12CTL.bit.DEVTHL1 = eDeassert;
  
  /* Enable VDD12L1 BOD */
  POWER->BOD12CTL.bit.ENL1 = BOD12CTL_BIT_ENL1_ENABLE;
}




/******************************************************************************
 * @brief      VDD33H BOD Init
 *
 * @param[in]  eAssert  :  Select the threshold voltage to assert VDD33H when 3.3V supply is going high
 *                         Please go to POWER_VDD33HEnum for details
 * @param[in]  eDeassert:  Select the threshold voltage to deassert VDD33H when 3.3V supply is going low
 *                         Please go to POWER_VDD33HEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
void POWER_VDD33HBODInit(POWER_VDD33HEnum eAssert, POWER_VDD33HEnum eDeassert)
{
  /* Set VDD33H assert threshold */
  POWER->BOD33CTL.bit.ASVTHH = eAssert;
  
  /* Set VDD33H deassert threshold */
  POWER->BOD33CTL.bit.DEVTHH = eDeassert;
  
  /* Enable VDD33H BOD */
  POWER->BOD33CTL.bit.ENH = BOD33CTL_BIT_ENH_ENABLE;
}




/******************************************************************************
 * @brief      VDD33L BOD Init
 *
 * @param[in]  eAssert  :  Select the threshold voltage to assert VDD33L when 3.3V supply is going high
 *                         Please go to POWER_VDD33LEnum for details
 * @param[in]  eDeassert:  Select the threshold voltage to deassert VDD33L when 3.3V supply is going low
 *                         Please go to POWER_VDD33LEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
void POWER_VDD33LBODInit(POWER_VDD33LEnum eAssert, POWER_VDD33LEnum eDeassert)
{
  /* Set VDD33L assert threshold */
  POWER->BOD33CTL.bit.ASVTHL = eAssert;
  
  /* Set VDD33L deassert threshold */
  POWER->BOD33CTL.bit.DEVTHL = eDeassert;
  
  
  /* Enable VDD33L BOD */
  POWER->BOD33CTL.bit.ENL = BOD33CTL_BIT_ENL_ENABLE;
}


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
