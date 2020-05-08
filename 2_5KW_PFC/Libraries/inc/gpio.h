/******************************************************************************
 * @file     gpio.h
 * @brief    GPIO driver header file.
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


#ifndef GPIO_H
#define GPIO_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1168.h"




/**
 *  @brief  GPIO Pinmux channel type definition
 */
typedef enum
{
  PINMUX_CHANNEL_0      = 0,                /*!< GPIO pin mux channel 0 define */
  PINMUX_CHANNEL_1      = 1,                /*!< GPIO pin mux channel 1 define */
  PINMUX_CHANNEL_2      = 2,                /*!< GPIO pin mux channel 2 define */
  PINMUX_CHANNEL_3      = 3,                /*!< GPIO pin mux channel 3 define */
  PINMUX_CHANNEL_4      = 4,                /*!< GPIO pin mux channel 4 define */
  PINMUX_CHANNEL_5      = 5,                /*!< GPIO pin mux channel 5 define */
  PINMUX_CHANNEL_6      = 6,                /*!< GPIO pin mux channel 6 define */
  PINMUX_CHANNEL_7      = 7,                /*!< GPIO pin mux channel 7 define */
} GPIO_PinMuxChannelEnum;




/**
 *  @brief  GPIO data direction type definition
 */
typedef enum
{
  GPIO_INPUT            = 0,                /*!< Set GPIO port data direction as input  */
  GPIO_OUTPUT           = 1,                /*!< Set GPIO port data direction as output */
} GPIO_DirEnum;




/**
 *  @brief  GPIO data Input/Output type definition
 */
typedef enum
{
  GPIO_LEVEL_LOW        = 0,                /*!< Set GPIO port data Input/Output value as LOW  */
  GPIO_LEVEL_HIGH       = 1,                /*!< Set GPIO port data Input/Output value as HIGH */
} GPIO_LevelEnum;




/**
 *  @brief  GPIO edge detection type definition
 */
typedef enum
{
  GPIO_INT_RISING_EDGE  = 0,                /*!< Rising edge detection                  */
  GPIO_INT_FALLING_EDGE = 1,                /*!< Falling edge detection                 */
  GPIO_INT_BOTH_EDGES   = 2,                /*!< Rising edge and Falling edge detection */
  GPIO_INT_IGNORE_EDGE  = 3,                /*!< Disable edge detection                 */
} GPIO_EdgeIntEnum;




/**
 *  @brief  GPIO output driving strength type definition
 */
typedef enum
{
  GPIO_OUT_STRENGTH_5MA  = 0,               /*!< Output strength is 5  mA               */
  GPIO_OUT_STRENGTH_10MA = 1,               /*!< Output strength is 10 mA               */
  GPIO_OUT_STRENGTH_15MA = 2,               /*!< Output strength is 15 mA               */
  GPIO_OUT_STRENGTH_20MA = 3,               /*!< Output strength is 20 mA               */
} GPIO_OutStrengthEnum;




/**
 *  @brief  GPIO0 pinmux function define
 */
#define GPIO0_GPIO0               PINMUX_CHANNEL_0
#define GPIO0_ADC0                PINMUX_CHANNEL_1
#define GPIO0_COMP0H              PINMUX_CHANNEL_6
#define GPIO0_ECAPO               PINMUX_CHANNEL_7




/**
 *  @brief  GPIO1 pinmux function define
 */
#define GPIO1_GPIO1               PINMUX_CHANNEL_0
#define GPIO1_ADC1                PINMUX_CHANNEL_1
#define GPIO1_COMP0L              PINMUX_CHANNEL_6
#define GPIO1_ECAPO               PINMUX_CHANNEL_7




/**
 *  @brief  GPIO2 pinmux function define
 */
#define GPIO2_GPIO2               PINMUX_CHANNEL_0
#define GPIO2_ADC2                PINMUX_CHANNEL_1
#define GPIO2_COMP1H              PINMUX_CHANNEL_6
#define GPIO2_ECAPO               PINMUX_CHANNEL_7




/**
 *  @brief  GPIO3 pinmux function define
 */
#define GPIO3_GPIO3               PINMUX_CHANNEL_0
#define GPIO3_ADC3                PINMUX_CHANNEL_1
#define GPIO3_COMP1L              PINMUX_CHANNEL_6
#define GPIO3_ECAPO               PINMUX_CHANNEL_7




/**
 *  @brief  GPIO4 pinmux function define
 */
#define GPIO4_GPIO4               PINMUX_CHANNEL_0
#define GPIO4_ADC4                PINMUX_CHANNEL_1
#define GPIO4_COMP2H              PINMUX_CHANNEL_6
#define GPIO4_ECAPO               PINMUX_CHANNEL_7




/**
 *  @brief  GPIO5 pinmux function define
 */
#define GPIO5_GPIO5               PINMUX_CHANNEL_0
#define GPIO5_ADC5                PINMUX_CHANNEL_1
#define GPIO5_COMP2L              PINMUX_CHANNEL_6
#define GPIO5_ECAPO               PINMUX_CHANNEL_7




/**
 *  @brief  GPIO6 pinmux function define
 */
#define GPIO6_GPIO6               PINMUX_CHANNEL_0
#define GPIO6_ADC6                PINMUX_CHANNEL_1
#define GPIO6_ECAPO               PINMUX_CHANNEL_7




/**
 *  @brief  GPIO7 pinmux function define
 */
#define GPIO7_GPIO7               PINMUX_CHANNEL_0
#define GPIO7_ADC7                PINMUX_CHANNEL_1
#define GPIO7_ECAPO               PINMUX_CHANNEL_7




/**
 *  @brief  GPIO8 pinmux function define
 */
#define GPIO8_GPIO8               PINMUX_CHANNEL_0
#define GPIO8_ADC8                PINMUX_CHANNEL_1
#define GPIO8_SPI_SCLK            PINMUX_CHANNEL_2
#define GPIO8_PWMSOC              PINMUX_CHANNEL_3
#define GPIO8_COMP3H              PINMUX_CHANNEL_6
#define GPIO8_ECAPO               PINMUX_CHANNEL_7




/**
 *  @brief  GPIO9 pinmux function define
 */
#define GPIO9_GPIO9               PINMUX_CHANNEL_0
#define GPIO9_ADC9                PINMUX_CHANNEL_1
#define GPIO9_SPI_SFRM            PINMUX_CHANNEL_2
#define GPIO9_COMP3L              PINMUX_CHANNEL_6
#define GPIO9_ECAPO               PINMUX_CHANNEL_7




/**
 *  @brief  GPIO10 pinmux function define
 */
#define GPIO10_GPIO10             PINMUX_CHANNEL_0
#define GPIO10_ADC10              PINMUX_CHANNEL_1
#define GPIO10_SPI_MOSI           PINMUX_CHANNEL_2
#define GPIO10_SPI_MISO           PINMUX_CHANNEL_3
#define GPIO10_COMP4H             PINMUX_CHANNEL_6
#define GPIO10_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO11 pinmux function define
 */
#define GPIO11_GPIO11             PINMUX_CHANNEL_0
#define GPIO11_ADC11              PINMUX_CHANNEL_1
#define GPIO11_SPI_MISO           PINMUX_CHANNEL_2
#define GPIO11_SPI_MOSI           PINMUX_CHANNEL_3
#define GPIO11_CLK_DCLK           PINMUX_CHANNEL_4
#define GPIO11_EPWRTZO            PINMUX_CHANNEL_5
#define GPIO11_COMP4L             PINMUX_CHANNEL_6
#define GPIO11_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO12 pinmux function define
 */
#define GPIO12_GPIO12             PINMUX_CHANNEL_0
#define GPIO12_ADC12              PINMUX_CHANNEL_1
#define GPIO12_I2C_SCL            PINMUX_CHANNEL_2
#define GPIO12_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO13 pinmux function define
 */
#define GPIO13_GPIO13             PINMUX_CHANNEL_0
#define GPIO13_ADC13              PINMUX_CHANNEL_1
#define GPIO13_I2C_SDA            PINMUX_CHANNEL_2
#define GPIO13_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO14 pinmux function define
 */
#define GPIO14_GPIO14             PINMUX_CHANNEL_0
#define GPIO14_ADC14              PINMUX_CHANNEL_1
#define GPIO14_UART_TXD           PINMUX_CHANNEL_2
#define GPIO14_UART_RXD           PINMUX_CHANNEL_3
#define GPIO14_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO15 pinmux function define
 */
#define GPIO15_GPIO15             PINMUX_CHANNEL_0
#define GPIO15_ADC15              PINMUX_CHANNEL_1
#define GPIO15_UART_RXD           PINMUX_CHANNEL_2
#define GPIO15_UART_TXD           PINMUX_CHANNEL_3
#define GPIO15_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO16 pinmux function define
 */
#define GPIO16_GPIO16             PINMUX_CHANNEL_0
#define GPIO16_XIN                PINMUX_CHANNEL_1
#define GPIO16_UART_TXD           PINMUX_CHANNEL_2
#define GPIO16_UART_RXD           PINMUX_CHANNEL_3
#define GPIO16_PWM2A              PINMUX_CHANNEL_4
#define GPIO16_PWM5A              PINMUX_CHANNEL_5
#define GPIO16_SIO0_12            PINMUX_CHANNEL_6
#define GPIO16_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO17 pinmux function define
 */
#define GPIO17_GPIO17             PINMUX_CHANNEL_0
#define GPIO17_XIO                PINMUX_CHANNEL_1
#define GPIO17_UART_RXD           PINMUX_CHANNEL_2
#define GPIO17_UART_TXD           PINMUX_CHANNEL_3
#define GPIO17_PWM2B              PINMUX_CHANNEL_4
#define GPIO17_PWM5B              PINMUX_CHANNEL_5
#define GPIO17_SIO0_13            PINMUX_CHANNEL_6
#define GPIO17_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO18 pinmux function define
 */
#define GPIO18_GPIO18             PINMUX_CHANNEL_0
#define GPIO18_PWM3A              PINMUX_CHANNEL_1
#define GPIO18_COMP3H             PINMUX_CHANNEL_3
#define GPIO18_PWM0A              PINMUX_CHANNEL_4
#define GPIO18_SIO0_14            PINMUX_CHANNEL_6
#define GPIO18_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO19 pinmux function define
 */
#define GPIO19_GPIO19             PINMUX_CHANNEL_0
#define GPIO19_PWM4A              PINMUX_CHANNEL_1
#define GPIO19_PWM3B              PINMUX_CHANNEL_2
#define GPIO19_COMP3L             PINMUX_CHANNEL_3
#define GPIO19_PWM1A              PINMUX_CHANNEL_4
#define GPIO19_PWM0B              PINMUX_CHANNEL_5
#define GPIO19_SIO0_15            PINMUX_CHANNEL_6
#define GPIO19_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO20 pinmux function define
 */
#define GPIO20_GPIO20             PINMUX_CHANNEL_0
#define GPIO20_COMP4H             PINMUX_CHANNEL_3
#define GPIO20_PWM2A              PINMUX_CHANNEL_4
#define GPIO20_PWM1A              PINMUX_CHANNEL_5
#define GPIO20_SIO0_16            PINMUX_CHANNEL_6
#define GPIO20_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO21 pinmux function define
 */
#define GPIO21_GPIO21             PINMUX_CHANNEL_0
#define GPIO21_COMP4L             PINMUX_CHANNEL_3
#define GPIO21_PWM0B              PINMUX_CHANNEL_4
#define GPIO21_PWM1B              PINMUX_CHANNEL_5
#define GPIO21_SIO0_17            PINMUX_CHANNEL_6
#define GPIO21_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO22 pinmux function define
 */
#define GPIO22_GPIO22             PINMUX_CHANNEL_0
#define GPIO22_PWM1B              PINMUX_CHANNEL_4
#define GPIO22_PWM2A              PINMUX_CHANNEL_5
#define GPIO22_SIO0_0             PINMUX_CHANNEL_6
#define GPIO22_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO23 pinmux function define
 */
#define GPIO23_GPIO23             PINMUX_CHANNEL_0
#define GPIO23_PWM2B              PINMUX_CHANNEL_4
#define GPIO23_SIO0_1             PINMUX_CHANNEL_6
#define GPIO23_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO24 pinmux function define
 */
#define GPIO24_GPIO24             PINMUX_CHANNEL_0
#define GPIO24_COMP0H             PINMUX_CHANNEL_3
#define GPIO24_PWM3A              PINMUX_CHANNEL_4
#define GPIO24_SIO0_2             PINMUX_CHANNEL_6
#define GPIO24_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO25 pinmux function define
 */
#define GPIO25_GPIO25             PINMUX_CHANNEL_0
#define GPIO25_COMP0L             PINMUX_CHANNEL_3
#define GPIO25_PWM4A              PINMUX_CHANNEL_4
#define GPIO25_PWM3B              PINMUX_CHANNEL_5
#define GPIO25_SIO0_3             PINMUX_CHANNEL_6
#define GPIO25_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO26 pinmux function define
 */
#define GPIO26_GPIO26             PINMUX_CHANNEL_0
#define GPIO26_PWM1H              PINMUX_CHANNEL_3
#define GPIO26_PWM5A              PINMUX_CHANNEL_4
#define GPIO26_PWM4A              PINMUX_CHANNEL_5
#define GPIO26_SIO0_4             PINMUX_CHANNEL_6
#define GPIO26_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO27 pinmux function define
 */
#define GPIO27_GPIO27             PINMUX_CHANNEL_0
#define GPIO27_COMP1L             PINMUX_CHANNEL_3
#define GPIO27_PWM3B              PINMUX_CHANNEL_4
#define GPIO27_PWM4B              PINMUX_CHANNEL_5
#define GPIO27_SIO0_5             PINMUX_CHANNEL_6
#define GPIO27_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO28 pinmux function define
 */
#define GPIO28_GPIO28             PINMUX_CHANNEL_0
#define GPIO28_COMP2H             PINMUX_CHANNEL_3
#define GPIO28_PWM4B              PINMUX_CHANNEL_4
#define GPIO28_PWM5A              PINMUX_CHANNEL_5
#define GPIO28_SIO0_6             PINMUX_CHANNEL_6
#define GPIO28_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO29 pinmux function define
 */
#define GPIO29_GPIO29             PINMUX_CHANNEL_0
#define GPIO29_COMP2L             PINMUX_CHANNEL_3
#define GPIO29_PWM5B              PINMUX_CHANNEL_4
#define GPIO29_SIO0_7             PINMUX_CHANNEL_6
#define GPIO29_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO30 pinmux function define
 */
#define GPIO30_GPIO30             PINMUX_CHANNEL_0
#define GPIO30_SPI_SCLK           PINMUX_CHANNEL_1
#define GPIO30_I2C_SCL            PINMUX_CHANNEL_2
#define GPIO30_COMP3H             PINMUX_CHANNEL_3
#define GPIO30_PWM3A              PINMUX_CHANNEL_4
#define GPIO30_PWM0A              PINMUX_CHANNEL_5
#define GPIO30_SIO0_8             PINMUX_CHANNEL_6
#define GPIO30_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO31 pinmux function define
 */
#define GPIO31_GPIO31             PINMUX_CHANNEL_0
#define GPIO31_SPI_SFRM           PINMUX_CHANNEL_1
#define GPIO31_I2C_SDA            PINMUX_CHANNEL_2
#define GPIO31_COMP3L             PINMUX_CHANNEL_3
#define GPIO31_PWM3B              PINMUX_CHANNEL_4
#define GPIO31_PWM0B              PINMUX_CHANNEL_5
#define GPIO31_SIO0_9             PINMUX_CHANNEL_6
#define GPIO31_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO32 pinmux function define
 */
#define GPIO32_GPIO32             PINMUX_CHANNEL_0
#define GPIO32_SPI_MOSI           PINMUX_CHANNEL_1
#define GPIO32_SPI_MISO           PINMUX_CHANNEL_2
#define GPIO32_COMP4H             PINMUX_CHANNEL_3
#define GPIO32_PWM4A              PINMUX_CHANNEL_4
#define GPIO32_EPWRTZ0O           PINMUX_CHANNEL_5
#define GPIO32_SIO0_10            PINMUX_CHANNEL_6
#define GPIO32_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO33 pinmux function define
 */
#define GPIO33_GPIO33             PINMUX_CHANNEL_0
#define GPIO33_SPI_MISO           PINMUX_CHANNEL_1
#define GPIO33_SPI_MOSI           PINMUX_CHANNEL_2
#define GPIO33_COMP4L             PINMUX_CHANNEL_3
#define GPIO33_PWM4B              PINMUX_CHANNEL_4
#define GPIO33_EPWRTZ1O           PINMUX_CHANNEL_5
#define GPIO33_SIO0_11            PINMUX_CHANNEL_6
#define GPIO33_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO34 pinmux function define
 */
#define GPIO34_GPIO34             PINMUX_CHANNEL_0
#define GPIO34_UART_TXD           PINMUX_CHANNEL_1
#define GPIO34_UART_RXD           PINMUX_CHANNEL_2
#define GPIO34_I2C_SDA            PINMUX_CHANNEL_3
#define GPIO34_SPI_MOSI           PINMUX_CHANNEL_4
#define GPIO34_SPI_MISO           PINMUX_CHANNEL_5
#define GPIO34_SIO0_12            PINMUX_CHANNEL_6
#define GPIO34_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO35 pinmux function define
 */
#define GPIO35_GPIO35             PINMUX_CHANNEL_0
#define GPIO35_UART_RXD           PINMUX_CHANNEL_1
#define GPIO35_UART_TXD           PINMUX_CHANNEL_2
#define GPIO35_I2C_SCL            PINMUX_CHANNEL_3
#define GPIO35_SPI_MISO           PINMUX_CHANNEL_4
#define GPIO35_SPI_MOSI           PINMUX_CHANNEL_5
#define GPIO35_SIO0_13            PINMUX_CHANNEL_6
#define GPIO35_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO36 pinmux function define
 */
#define GPIO36_GPIO36             PINMUX_CHANNEL_0
#define GPIO36_TDO                PINMUX_CHANNEL_1
#define GPIO36_UART_RXD           PINMUX_CHANNEL_2
#define GPIO36_SPI_SCLK           PINMUX_CHANNEL_3
#define GPIO36_PWM5A              PINMUX_CHANNEL_4
#define GPIO36_PWM1A              PINMUX_CHANNEL_5
#define GPIO36_SIO0_14            PINMUX_CHANNEL_6
#define GPIO36_I2C_SDA            PINMUX_CHANNEL_7




/**
 *  @brief  GPIO37 pinmux function define
 */
#define GPIO37_GPIO37             PINMUX_CHANNEL_0
#define GPIO37_TDI                PINMUX_CHANNEL_1
#define GPIO37_UART_TXD           PINMUX_CHANNEL_2
#define GPIO37_SPI_SFRM           PINMUX_CHANNEL_3
#define GPIO37_PWM5B              PINMUX_CHANNEL_4
#define GPIO37_PWM1B              PINMUX_CHANNEL_5
#define GPIO37_SIO0_15            PINMUX_CHANNEL_6
#define GPIO37_I2C_SCL            PINMUX_CHANNEL_7




/**
 *  @brief  GPIO38 pinmux function define
 */
#define GPIO38_GPIO38             PINMUX_CHANNEL_0
#define GPIO38_TMS                PINMUX_CHANNEL_1
#define GPIO38_SWD                PINMUX_CHANNEL_1
#define GPIO38_I2C_SDA            PINMUX_CHANNEL_2
#define GPIO38_SPI_MOSI           PINMUX_CHANNEL_3
#define GPIO38_SPI_MISO           PINMUX_CHANNEL_4
#define GPIO38_PWM2A              PINMUX_CHANNEL_5
#define GPIO38_SIO0_16            PINMUX_CHANNEL_6
#define GPIO38_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO39 pinmux function define
 */
#define GPIO39_GPIO39             PINMUX_CHANNEL_0
#define GPIO39_TCK                PINMUX_CHANNEL_1
#define GPIO39_SWCK               PINMUX_CHANNEL_1
#define GPIO39_I2C_SCL            PINMUX_CHANNEL_2
#define GPIO39_SPI_MISO           PINMUX_CHANNEL_3
#define GPIO39_SPI_MOSI           PINMUX_CHANNEL_4
#define GPIO39_PWM2B              PINMUX_CHANNEL_5
#define GPIO39_SIO0_17            PINMUX_CHANNEL_6
#define GPIO39_ECAPO              PINMUX_CHANNEL_7




/**
 *  @brief  GPIO40 pinmux function define
 */
#define GPIO40_GPIO40             PINMUX_CHANNEL_0
#define GPIO40_SPI_SCLK           PINMUX_CHANNEL_1
#define GPIO40_UART_TXD           PINMUX_CHANNEL_2
#define GPIO40_CLK_DCLK           PINMUX_CHANNEL_3
#define GPIO40_EPWRTZ0O           PINMUX_CHANNEL_4
#define GPIO40_EPWRTZ1O           PINMUX_CHANNEL_5
#define GPIO40_SIO0_0             PINMUX_CHANNEL_6
#define GPIO40_ECAPO              PINMUX_CHANNEL_7




/******************************************************************************
 * @brief      Get GPIO pin port and index
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define __GPIO_PIN_PORT(ePinNum)            ((ePinNum) >> (5UL))
#define __GPIO_PIN_INDEX(ePinNum)           ((ePinNum) & (0x1FUL))




/******************************************************************************
 * @brief      GPIO Pin Configuration Register define
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define PINMUX_GPIO(ePinNum)                ((__IO GPIO0_REG*)(PINMUX_BASE + ((ePinNum) * 4)))




/******************************************************************************
 * @brief      Set GPIO pin channel
 *
 * @param[in]  ePinNum :  Select the GPIO pin, should be GPIO_PinEnum
 * @param[in]  eChannel:  GPIO pin channel, should be GPIO_PinMuxChannelEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define GPIO_SetPinChannel(ePinNum,eChannel)    (PINMUX_GPIO(ePinNum)->bit.MUXSEL = (eChannel & 0x07))




/******************************************************************************
 * @brief      Set GPIO output strength
 *
 * @param[in]  ePinNum  :  Select the GPIO pin, should be GPIO_PinEnum
 * @param[in]  eStrength:  GPIO output strength, should be GPIO_OutStrengthEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define GPIO_SetOutStrength(ePinNum,eStrength)  (PINMUX_GPIO(ePinNum)->bit.STRENGTH = (eStrength & 0x3))




/******************************************************************************
 * @brief      Enable GPIO pin pull-up
 *
 * @param[in]  ePinNum :  Select the GPIO pin, should be GPIO_PinEnum
 * @param[in]  eChannel:  GPIO pin channel, should be GPIO_PinMuxChannelEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define GPIO_EnablePullUp(ePinNum,eChannel)     (PINMUX_GPIO(ePinNum)->bit.PU |= (0x01 << eChannel))




/******************************************************************************
 * @brief      Disable GPIO pin pull-up
 *
 * @param[in]  ePinNum :  Select the GPIO pin, should be GPIO_PinEnum
 * @param[in]  eChannel:  GPIO pin channel, should be GPIO_PinMuxChannelEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define GPIO_DisablePullUp(ePinNum,eChannel)    (PINMUX_GPIO(ePinNum)->bit.PU &= (~(0x01 << eChannel)))




/******************************************************************************
 * @brief      Enable GPIO pin pull-down
 *
 * @param[in]  ePinNum :  Select the GPIO pin, should be GPIO_PinEnum
 * @param[in]  eChannel:  GPIO pin channel, should be GPIO_PinMuxChannelEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define GPIO_EnablePullDown(ePinNum,eChannel)     (PINMUX_GPIO(ePinNum)->bit.PD |= (0x01 << eChannel))




/******************************************************************************
 * @brief      Disable GPIO pin pull-down
 *
 * @param[in]  ePinNum :  Select the GPIO pin, should be GPIO_PinEnum
 * @param[in]  eChannel:  GPIO pin channel, should be GPIO_PinMuxChannelEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define GPIO_DisablePullDown(ePinNum,eChannel)    (PINMUX_GPIO(ePinNum)->bit.PD &= (~(0x01 << eChannel)))




/******************************************************************************
 * @brief      Enable GPIO pin deglitch filter
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define GPIO_EnableDeglitch(ePinNum)        (PINMUX_GPIO(ePinNum)->bit.DEGLITCH = 1)




/******************************************************************************
 * @brief      Disable GPIO pin deglitch filter
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define GPIO_DisableDeglitch(ePinNum)       (PINMUX_GPIO(ePinNum)->bit.DEGLITCH = 0)




/******************************************************************************
 * @brief      Set GPIO pin deglitch window size
 *
 * @param[in]  eWindow:  Deglitch clock divider
 *
 * @return     none
 *
 ******************************************************************************/
#define GPIO_SetDeglitchWindow(u32DIV)     (CLOCK->DGCLKCTL.all = (u32DIV))




/******************************************************************************
 * @brief      Set GPIO pin output
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 * @param[in]  eBitVal:  Value to be written to GPIO pin, should be GPIO_LevelEnum
 *                        - \ref GPIO_LEVEL_LOW
 *                        - \ref GPIO_LEVEL_HIGH
 *
 * @return     none
 *
 ******************************************************************************/
#define __GPIO_OUTPUT_REG_ADDR(ePinNum,bitVal)  ((uint32_t)(GPIO_BASE + 0x24UL + (__GPIO_PIN_PORT(ePinNum) << 2) - (bitVal * 12)))
#define GPIO_WritePin(ePinNum,bitVal)           (*(volatile uint32_t*)(__GPIO_OUTPUT_REG_ADDR(ePinNum,bitVal)) = (0x01UL << __GPIO_PIN_INDEX(ePinNum)))




/******************************************************************************
 * @brief      Read GPIO pin level
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     Value read from GPIO pin
 *             - \ref 0 : GPIO level is LOW
 *             - \ref 1 : GPIO level is HIGH
 *
 ******************************************************************************/
#define __GPIO_GPLR_ADDR(ePinNum)           ((uint32_t)(GPIO_BASE + (__GPIO_PIN_PORT(ePinNum) << 2)))
#define GPIO_ReadPin(ePinNum)               ((GPIO->GPLR[__GPIO_PIN_PORT(ePinNum)].all & (0x01 << __GPIO_PIN_INDEX(ePinNum)))? (1UL) : (0UL))
#define GPIO_ReadPinBitBand(ePinNum)        REG_BIT(__GPIO_GPLR_ADDR(ePinNum), __GPIO_PIN_INDEX(ePinNum))




/******************************************************************************
 * @brief      Toggle GPIO pin output value
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define GPIO_TogglePin(ePinNum)             (GPIO->GPLR[__GPIO_PIN_PORT(ePinNum)].all ^= (0x01UL << __GPIO_PIN_INDEX(ePinNum)))




/******************************************************************************
 * @brief      Enable GPIO edge detect
 *
 * @param[in]  pinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define GPIO_EnableEdgeInt(ePinNum)         (GPIO->GEIE[__GPIO_PIN_PORT(ePinNum)].all |= (0x01 << __GPIO_PIN_INDEX(ePinNum)))




/******************************************************************************
 * @brief      Disable GPIO edge detect
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define GPIO_DisableEdgeInt(ePinNum)        (GPIO->GEIE[__GPIO_PIN_PORT(ePinNum)].all &= (~(0x01 << __GPIO_PIN_INDEX(ePinNum))))




/******************************************************************************
 * @brief      Get GPIO edge detect status
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     0 - No detected rising or falling edge
 *             1 - Edge was detected on the selected pin
 *
 ******************************************************************************/
#define GPIO_GetEdgeIntStatus(ePinNum)      ((GPIO->GEDR[__GPIO_PIN_PORT(ePinNum)].all & (0x01 << __GPIO_PIN_INDEX(ePinNum)))? (1UL) : (0UL))




/******************************************************************************
 * @brief      Clear GPIO edge detect status
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define GPIO_ClearEdgeInt(ePinNum)          (GPIO->GEDR[__GPIO_PIN_PORT(ePinNum)].all = (0x01 << __GPIO_PIN_INDEX(ePinNum)))




/******************************************************************************
 * @brief      Enable GPIO level triggered interrupt
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define GPIO_EnableLevelInt(ePinNum)        (GPIO->GLIE[__GPIO_PIN_PORT(ePinNum)].all |= (0x01 << __GPIO_PIN_INDEX(ePinNum)))




/******************************************************************************
 * @brief      Disable GPIO level triggered interrupt
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define GPIO_DisableLevelInt(ePinNum)       (GPIO->GLIE[__GPIO_PIN_PORT(ePinNum)].all &= (~(0x01 << __GPIO_PIN_INDEX(ePinNum))))




/******************************************************************************
 * @brief      Clear GPIO level triggered interrupt
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define GPIO_ClearLevelInt(ePinNum)         (GPIO->GLIC[__GPIO_PIN_PORT(ePinNum)].all = (0x01 << __GPIO_PIN_INDEX(ePinNum)))




/******************************************************************************
 * @brief      Force level triggered interrupt
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define GPIO_ForceLevelInt(ePinNum)         (GPIO->GLIFRC[__GPIO_PIN_PORT(ePinNum)].all = (0x01 << __GPIO_PIN_INDEX(ePinNum)))




/******************************************************************************
 * @brief      Interrupt triggered when GPIO level is high
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define GPIO_SetLevelIntActiveHigh(ePinNum) (GPIO->GLIPOL[__GPIO_PIN_PORT(ePinNum)].all |= (0x01 << __GPIO_PIN_INDEX(ePinNum)))




/******************************************************************************
 * @brief      Interrupt triggered when GPIO level is low
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 ******************************************************************************/
#define GPIO_SetLevelIntActiveLow(ePinNum)  (GPIO->GLIPOL[__GPIO_PIN_PORT(ePinNum)].all &= (~(0x01 << __GPIO_PIN_INDEX(ePinNum))))




/******************************************************************************
 * @brief      Get level triggered interrupt polarity
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     0 - Interrupt triggered when GPIO level is HIGH
 *             1 - Interrupt triggered when GPIO level is LOW
 *
 ******************************************************************************/
#define GPIO_GetLevelIntPol(ePinNum)        ((GPIO->GLIPOL[__GPIO_PIN_PORT(ePinNum)].all & (0x01 << __GPIO_PIN_INDEX(ePinNum)))? (1) : (0))




/******************************************************************************
 * @brief      Get level triggered interrupt status
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     0 - No level interrupt was detected
 *             1 - A level interrupt was detected
 *
 ******************************************************************************/
#define GPIO_GetLevelIntStatus(ePinNum)     ((GPIO->GLIF[__GPIO_PIN_PORT(ePinNum)].all & (0x01 << __GPIO_PIN_INDEX(ePinNum)))? (1UL) : (0UL))




/******************************************************************************
 * @brief      Get GPIO edge-triggered interrupt flag
 *
 * @param[in]  none
 *
 * @return     0 - No edge-triggered interrupt occurred
 *             1 - Edge-triggered interrupt occurred
 *
 ******************************************************************************/
#define GPIO_GetGlobalEdgeIntStatus()       (GPIO->GIF.bit.EDGE)




/******************************************************************************
 * @brief      Get GPIO level-triggered interrupt flag
 *
 * @param[in]  none
 *
 * @return     0 - No detected rising or falling edge
 *             1 - Edge was detected
 *
 ******************************************************************************/
#define GPIO_GetGlobalLevelIntStatus()      (GPIO->GIF.bit.LEVEL)




/******************************************************************************
 * @brief      Clear GPIO edge-triggered interrupt flag
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define GPIO_ClearGlobalEdgeInt()           (GPIO->GIC.all = GIC_ALL_EDGE_CLEAR)




/******************************************************************************
 * @brief      Clear GPIO level-triggered interrupt flag
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define GPIO_ClearGlobalLevelInt()          (GPIO->GIC.all = GIC_ALL_LEVEL_CLEAR)




/******************************************************************************
 * @brief      Enable write access to the protected GPIO registers
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define GPIO_WALLOW()                      (GPIO->GPIOREGKEY.all = 0x1ACCE551)




/******************************************************************************
 * @brief      Disable write access to the protected GPIO registers
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define GPIO_WDIS()                        (GPIO->GPIOREGKEY.all = 0x0)




/******************************************************************************
 * @brief      Enable write access to the protected PINMUX registers
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define PINMUX_WALLOW()                      (PINMUX->PINMUXREGKEY.all = 0x1ACCE551)




/******************************************************************************
 * @brief      Disable write access to the protected PINMUX registers
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define PINMUX_WDIS()                        (PINMUX->PINMUXREGKEY.all = 0x0)




/**
 *  @brief GPIO Public Function Declaration
 */
void GPIO_ResetAllPin(void);
void GPIO_SetPinAsGPIO(GPIO_PinEnum ePinNum);
void GPIO_SetPinAsAnalog(GPIO_PinEnum ePinNum);

void GPIO_SetPinDir(GPIO_PinEnum ePinNum, GPIO_DirEnum eDir);

void GPIO_SetEdgeIntMode(GPIO_PinEnum ePinNum, GPIO_EdgeIntEnum eIntType);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* GPIO_H */


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
