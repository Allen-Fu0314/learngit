/******************************************************************************
 * @file     gpio.c
 * @brief    GPIO firmware functions.
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


#include "gpio.h"




/******************************************************************************
 * @brief      Set all GPIO pin to default function
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
void GPIO_ResetAllPin(void)
{
  GPIO_PinEnum ePinNum;
  
  /* Set all pin as GPIO input */
  GPIO->GCDR[0].all = BYTE0_Msk | BYTE1_Msk | BYTE2_Msk |BYTE3_Msk;
  GPIO->GCDR[1].all = BYTE0_Msk | BYTE1_Msk | BYTE2_Msk |BYTE3_Msk;

  /* Set all pin channel as default */
  ePinNum = GPIO_40;
  while(ePinNum--)
  {
    if(ePinNum <= GPIO_15)
    {
      PINMUX_GPIO(ePinNum)->bit.MUXSEL = PINMUX_CHANNEL_1;
    }
    else
    {
      PINMUX_GPIO(ePinNum)->bit.MUXSEL = PINMUX_CHANNEL_0;
    }
  }
}




/******************************************************************************
 * @brief      Set the specified pin as GPIO function
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 ******************************************************************************/
void GPIO_SetPinAsGPIO(GPIO_PinEnum ePinNum)
{
  GPIO_SetPinChannel(ePinNum, PINMUX_CHANNEL_0);
}




/******************************************************************************
 * @brief      Set the specified pin as Analog function
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 ******************************************************************************/
void GPIO_SetPinAsAnalog(GPIO_PinEnum ePinNum)
{
  if(ePinNum <= GPIO_15)
  {
    PINMUX_GPIO(ePinNum)->bit.MUXSEL = PINMUX_CHANNEL_1;
  }
}




/******************************************************************************
 * @brief      Set GPIO pin direction
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 * @param[in]  eDir   :  Data transfer direction, should be GPIO_INPUT or GPIO_OUTPUT.
 *
 * @return     none
 *
 ******************************************************************************/
void GPIO_SetPinDir(GPIO_PinEnum ePinNum, GPIO_DirEnum eDir)
{
  /* Set GPIOx data direction */
  switch(eDir)
  {
    case GPIO_INPUT:
      GPIO->GCDR[__GPIO_PIN_PORT(ePinNum)].all = (0x01 << __GPIO_PIN_INDEX(ePinNum));
      break;

    case GPIO_OUTPUT:
      GPIO->GSDR[__GPIO_PIN_PORT(ePinNum)].all = (0x01 << __GPIO_PIN_INDEX(ePinNum));
      break;
  }
}




/******************************************************************************
 * @brief      Configure GPIO edge detection type
 *
 * @param[in]  ePinNum :  Select the GPIO pin, should be GPIO_PinEnum
 * @param[in]  eIntType:  Edge detection type, should be GPIO_EdgeIntEnum
 *                         - \ref GPIO_INT_RISING_EDGE  -> Rising edge
 *                         - \ref GPIO_INT_FALLING_EDGE -> Falling edge
 *                         - \ref GPIO_INT_BOTH_EDGES   -> Rising and Falling edge
 *                         - \ref GPIO_INT_IGNORE_EDGE  -> Disable edge detection
 *
 * @return     none
 *
 ******************************************************************************/
void GPIO_SetEdgeIntMode(GPIO_PinEnum ePinNum, GPIO_EdgeIntEnum eIntType)
{
  /* Enable/Disabe GPIO Rising/Falling interrupt function */
  switch(eIntType)
  {
    case GPIO_INT_RISING_EDGE:
      GPIO->GSRER[__GPIO_PIN_PORT(ePinNum)].all = (0x01 << __GPIO_PIN_INDEX(ePinNum));
      GPIO->GCFER[__GPIO_PIN_PORT(ePinNum)].all = (0x01 << __GPIO_PIN_INDEX(ePinNum));
      break;

    case GPIO_INT_FALLING_EDGE:
      GPIO->GCRER[__GPIO_PIN_PORT(ePinNum)].all = (0x01 << __GPIO_PIN_INDEX(ePinNum));
      GPIO->GSFER[__GPIO_PIN_PORT(ePinNum)].all = (0x01 << __GPIO_PIN_INDEX(ePinNum));
      break;

    case GPIO_INT_BOTH_EDGES:
      GPIO->GSRER[__GPIO_PIN_PORT(ePinNum)].all = (0x01 << __GPIO_PIN_INDEX(ePinNum));
      GPIO->GSFER[__GPIO_PIN_PORT(ePinNum)].all = (0x01 << __GPIO_PIN_INDEX(ePinNum));
      break;

    case GPIO_INT_IGNORE_EDGE:
      GPIO->GCRER[__GPIO_PIN_PORT(ePinNum)].all = (0x01 << __GPIO_PIN_INDEX(ePinNum));
      GPIO->GCFER[__GPIO_PIN_PORT(ePinNum)].all = (0x01 << __GPIO_PIN_INDEX(ePinNum));
      break;

    default:
      break;
  }
}


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
