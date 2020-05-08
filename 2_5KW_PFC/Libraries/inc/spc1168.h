/******************************************************************************
 * @file     spc1168.h
 * @brief    SPC1168 device header file.
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

#ifndef SPC1168_H
#define SPC1168_H

#ifdef __cplusplus
extern "C" {
#endif




/**
 *  @brief  Configuration of the Cortex-M4 Processor and Core Peripherals
 */
#define __CM4_REV                 0x0001    /*!< Core revision r0p1                              */
#define __MPU_PRESENT             0         /*!< MPU present or not                              */
#define __NVIC_PRIO_BITS          4         /*!< Number of Bits used for Priority Levels         */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used    */
#define __FPU_PRESENT             1         /*!< FPU present                                     */




/**
 *  @brief  SoC Interrupt Number Definition
 */
typedef enum IRQn
{
/* -------------------  Cortex-M4 Processor Exceptions Numbers  ------------------- */
  NonMaskableInt_IRQn           = -14,      /*!<  2 Non Maskable Interrupt          */
  HardFault_IRQn                = -13,      /*!<  3 HardFault Interrupt             */
  MemoryManagement_IRQn         = -12,      /*!<  4 Memory Management Interrupt     */
  BusFault_IRQn                 = -11,      /*!<  5 Bus Fault Interrupt             */
  UsageFault_IRQn               = -10,      /*!<  6 Usage Fault Interrupt           */
  SVCall_IRQn                   =  -5,      /*!< 11 SV Call Interrupt               */
  DebugMonitor_IRQn             =  -4,      /*!< 12 Debug Monitor Interrupt         */
  PendSV_IRQn                   =  -2,      /*!< 14 Pend SV Interrupt               */
  SysTick_IRQn                  =  -1,      /*!< 15 System Tick Interrupt           */

/******************  SoC Specific Interrupt Numbers *********************************/
  MEM_IRQn                      =   0,      /*!< Memory Error Interrupt             */
  POWER_IRQn                    =   1,      /*!< Power Error Interrupt              */
  CLOCK_IRQn                    =   2,      /*!< Clock Error Interrupt              */
  WDT1_IRQn                     =   3,      /*!< WDT1 Interrupt                     */
  GPIO_LEVEL_IRQn               =   4,      /*!< GPIO Level Triggered Interrupt     */
  GPIO_EDGE_IRQn                =   5,      /*!< GPIO Edge Triggered Interrupt      */
  SIO0A_IRQn                    =   6,      /*!< SIO0 Interrupt A                   */
  SIO0B_IRQn                    =   7,      /*!< SIO0 Interrupt B                   */
  UART_IRQn                     =  12,      /*!< UART Interrupt                     */
  SSP_IRQn                      =  13,      /*!< SSP Interrupt                      */
  I2C_IRQn                      =  14,      /*!< I2C Interrupt                      */
  ADC0_IRQn                     =  15,      /*!< ADC EOC0  Interrupt                */
  ADC1_IRQn                     =  16,      /*!< ADC EOC1  Interrupt                */
  ADC2_IRQn                     =  17,      /*!< ADC EOC2  Interrupt                */
  ADC3_IRQn                     =  18,      /*!< ADC EOC3  Interrupt                */
  ADC4_IRQn                     =  19,      /*!< ADC EOC4  Interrupt                */
  ADC5_IRQn                     =  20,      /*!< ADC EOC5  Interrupt                */
  ADC6_IRQn                     =  21,      /*!< ADC EOC6  Interrupt                */
  ADC7_IRQn                     =  22,      /*!< ADC EOC7  Interrupt                */
  ADC8_IRQn                     =  23,      /*!< ADC EOC8  Interrupt                */
  ADC9_IRQn                     =  24,      /*!< ADC EOC9  Interrupt                */
  ADC10_IRQn                    =  25,      /*!< ADC EOC10 Interrupt                */
  ADC11_IRQn                    =  26,      /*!< ADC EOC11 Interrupt                */
  ADC12_IRQn                    =  27,      /*!< ADC EOC12 Interrupt                */
  ADC13_IRQn                    =  28,      /*!< ADC EOC13 Interrupt                */
  ADC14_IRQn                    =  29,      /*!< ADC EOC14 Interrupt                */
  ADC15_IRQn                    =  30,      /*!< ADC EOC15 Interrupt                */
  ADCPPU0_IRQn                  =  31,      /*!< ADC PPU0 Interrupt                 */
  ADCPPU1_IRQn                  =  32,      /*!< ADC PPU1 Interrupt                 */
  ADCPPU2_IRQn                  =  33,      /*!< ADC PPU2 Interrupt                 */
  ADCPPU3_IRQn                  =  34,      /*!< ADC PPU3 Interrupt                 */
  ADCPPU4_IRQn                  =  35,      /*!< ADC PPU4 Interrupt                 */
  ADCPPU5_IRQn                  =  36,      /*!< ADC PPU5 Interrupt                 */
  PWM0_IRQn                     =  39,      /*!< PWM0 Interrupt                     */
  PWM1_IRQn                     =  40,      /*!< PWM1 Interrupt                     */
  PWM2_IRQn                     =  41,      /*!< PWM2 Interrupt                     */
  PWM3_IRQn                     =  42,      /*!< PWM3 Interrupt                     */
  PWM4_IRQn                     =  43,      /*!< PWM4 Interrupt                     */
  PWM5_IRQn                     =  44,      /*!< PWM5 Interrupt                     */
  PWM0TZ_IRQn                   =  47,      /*!< PWM0 Trip-Zone Interrupt           */
  PWM1TZ_IRQn                   =  48,      /*!< PWM1 Trip-Zone Interrupt           */
  PWM2TZ_IRQn                   =  49,      /*!< PWM2 Trip-Zone Interrupt           */
  PWM3TZ_IRQn                   =  50,      /*!< PWM3 Trip-Zone Interrupt           */
  PWM4TZ_IRQn                   =  51,      /*!< PWM4 Trip-Zone Interrupt           */
  PWM5TZ_IRQn                   =  52,      /*!< PWM5 Trip-Zone Interrupt           */
  ECAP_IRQn                     =  55,      /*!< ECAP Interrupt                     */
  TIMER0_IRQn                   =  56,      /*!< TIMER0 Interrupt                   */
  TIMER1_IRQn                   =  57,      /*!< TIMER1 Interrupt                   */
  TIMER2_IRQn                   =  58,      /*!< TIMER2 Interrupt                   */
  CRC_IRQn                      =  59,      /*!< CRC Interrupt                      */
  AES_IRQn                      =  60,      /*!< AES Interrupt                      */
} IRQn_Type;




/**
 *  @brief  GPIO Pin Definition
 */
typedef enum
{
  GPIO_0                          =  0,     /*!< GPIO0  pin define */
  GPIO_1                          =  1,     /*!< GPIO1  pin define */
  GPIO_2                          =  2,     /*!< GPIO2  pin define */
  GPIO_3                          =  3,     /*!< GPIO3  pin define */
  GPIO_4                          =  4,     /*!< GPIO4  pin define */
  GPIO_5                          =  5,     /*!< GPIO5  pin define */
  GPIO_6                          =  6,     /*!< GPIO6  pin define */
  GPIO_7                          =  7,     /*!< GPIO7  pin define */
  GPIO_8                          =  8,     /*!< GPIO8  pin define */
  GPIO_9                          =  9,     /*!< GPIO9  pin define */
  GPIO_10                         = 10,     /*!< GPIO10 pin define */
  GPIO_11                         = 11,     /*!< GPIO11 pin define */
  GPIO_12                         = 12,     /*!< GPIO12 pin define */
  GPIO_13                         = 13,     /*!< GPIO13 pin define */
  GPIO_14                         = 14,     /*!< GPIO14 pin define */
  GPIO_15                         = 15,     /*!< GPIO15 pin define */
  GPIO_16                         = 16,     /*!< GPIO16 pin define */
  GPIO_17                         = 17,     /*!< GPIO17 pin define */
  GPIO_18                         = 18,     /*!< GPIO18 pin define */
  GPIO_19                         = 19,     /*!< GPIO19 pin define */
  GPIO_20                         = 20,     /*!< GPIO20 pin define */
  GPIO_21                         = 21,     /*!< GPIO21 pin define */
  GPIO_22                         = 22,     /*!< GPIO22 pin define */
  GPIO_23                         = 23,     /*!< GPIO23 pin define */
  GPIO_24                         = 24,     /*!< GPIO24 pin define */
  GPIO_25                         = 25,     /*!< GPIO25 pin define */
  GPIO_26                         = 26,     /*!< GPIO26 pin define */
  GPIO_27                         = 27,     /*!< GPIO27 pin define */
  GPIO_28                         = 28,     /*!< GPIO28 pin define */
  GPIO_29                         = 29,     /*!< GPIO29 pin define */
  GPIO_30                         = 30,     /*!< GPIO30 pin define */
  GPIO_31                         = 31,     /*!< GPIO31 pin define */
  GPIO_32                         = 32,     /*!< GPIO32 pin define */
  GPIO_33                         = 33,     /*!< GPIO33 pin define */
  GPIO_34                         = 34,     /*!< GPIO34 pin define */
  GPIO_35                         = 35,     /*!< GPIO35 pin define */
  GPIO_36                         = 36,     /*!< GPIO36 pin define */
  GPIO_37                         = 37,     /*!< GPIO37 pin define */
  GPIO_38                         = 38,     /*!< GPIO38 pin define */
  GPIO_39                         = 39,     /*!< GPIO39 pin define */
  GPIO_40                         = 40,     /*!< GPIO40 pin define */
} GPIO_PinEnum;




/**
 *  @brief  Flag Status Type Definition
 */
typedef enum {RESET = 0, SET = 1} FlagStatus, IntStatus;


/**
 *  @brief  Functional State Definition
 */
typedef enum {DISABLE = 0, ENABLE = 1} FunctionalState;


/**
 *  @brief  Status Type Definition
 */
typedef enum {ERROR = 0, SUCCESS = 1} ErrorStatus;


/**
 *  @brief  Boolean Type Definition
 */
typedef enum {FALSE = 0, TRUE = 1} BOOL;




#include "core_cm4.h"             /* Processor and core peripherals                       */
#include "system_spc1168.h"       /* System header file                                   */
#include <stdint.h>




/**
 *  @brief  SoC Peripheral Memory Map
 */
#define SYSTEM_BASE               ((uint32_t)0x40000000)      /*!< SYSTEM Base Address              */
#define POWER_BASE                ((uint32_t)0x40000100)      /*!< Power Base Address               */
#define CLOCK_BASE                ((uint32_t)0x40000200)      /*!< Clock Base Address               */
#define PINMUX_BASE               ((uint32_t)0x40000300)      /*!< PinMux Base Address              */
#define EPWR_BASE                 ((uint32_t)0x40000400)      /*!< EPWR Base Address                */
#define ENGR_BASE                 ((uint32_t)0x40000F00)      /*!< ENGR Base Address                */
#define WDT0_BASE                 ((uint32_t)0x40001000)      /*!< Watchdog Timer 0 Base Address    */
#define WDT1_BASE                 ((uint32_t)0x40002000)      /*!< Watchdog Timer 1 Base Address    */
#define GPIO_BASE                 ((uint32_t)0x40003000)      /*!< GPIO Base Address                */
#define UART_BASE                 ((uint32_t)0x40004000)      /*!< UART Base Address                */
#define SSP_BASE                  ((uint32_t)0x40005000)      /*!< SSP Base Address                 */
#define I2C_BASE                  ((uint32_t)0x40006000)      /*!< I2C Base Address                 */
#define TIMER0_BASE               ((uint32_t)0x40007000)      /*!< Timer0 Base Address              */
#define TIMER1_BASE               ((uint32_t)0x40007020)      /*!< Timer1 Base Address              */
#define TIMER2_BASE               ((uint32_t)0x40007040)      /*!< Timer2 Base Address              */
#define CRC_BASE                  ((uint32_t)0x40008000)      /*!< CRC Base Address                 */
#define AES_BASE                  ((uint32_t)0x40008400)      /*!< AES Base Address                 */
#define FLASH_BASE                ((uint32_t)0x40008800)      /*!< FLASH Base Address               */
#define ADC_BASE                  ((uint32_t)0x40008C00)      /*!< ADC Base Address                 */
#define PGA_BASE                  ((uint32_t)0x40008C00)      /*!< PGA Base Address                 */
#define COMP_BASE                 ((uint32_t)0x40008C00)      /*!< COMP Base Address                */
#define PWM0_BASE                 ((uint32_t)0x40009000)      /*!< PWM0 Base Address                */
#define PWM1_BASE                 ((uint32_t)0x40009100)      /*!< PWM1 Base Address                */
#define PWM2_BASE                 ((uint32_t)0x40009200)      /*!< PWM2 Base Address                */
#define PWM3_BASE                 ((uint32_t)0x40009300)      /*!< PWM3 Base Address                */
#define PWM4_BASE                 ((uint32_t)0x40009400)      /*!< PWM4 Base Address                */
#define PWM5_BASE                 ((uint32_t)0x40009500)      /*!< PWM5 Base Address                */
#define PWMCFG_BASE               ((uint32_t)0x40009F00)      /*!< PWMCFG Base Address              */
#define ECAP_BASE                 ((uint32_t)0x4000A000)      /*!< eCAP Base Address                */
#define SIO_BASE                  ((uint32_t)0x4000B000)      /*!< SIO Base Address                 */




#include "spc1168_reg.h"          /*!< SPC1168 Register Structure Definition Header File  */
#include "spc1168_bitfield.h"     /*!< SPC1168 Register Bit Field Definition Header File  */




/**
 *  @brief  SPC1168 Peripheral Declaration
 */
#define SYSTEM          ((SYSTEM_REGS *) SYSTEM_BASE )        /*!< SYSTEM Declaration               */
#define POWER           ((POWER_REGS  *) POWER_BASE  )        /*!< Power Declaration                */
#define CLOCK           ((CLOCK_REGS  *) CLOCK_BASE  )        /*!< Clock Declaration                */
#define PINMUX          ((PINMUX_REGS *) PINMUX_BASE )        /*!< PinMux Declaration               */
#define EPWR            ((EPWR_REGS   *) EPWR_BASE   )        /*!< EPWR Declaration                 */
#define ENGR            ((ENGR_REGS   *) ENGR_BASE   )        /*!< ENGR Declaration                 */
#define WDT0            ((WDT_REGS    *) WDT0_BASE   )        /*!< Watchdog Timer 0 Declaration     */
#define WDT1            ((WDT_REGS    *) WDT1_BASE   )        /*!< Watchdog Timer 1 Declaration     */
#define GPIO            ((GPIO_REGS   *) GPIO_BASE   )        /*!< GPIO Declaration                 */
#define UART            ((UART_REGS   *) UART_BASE   )        /*!< UART Declaration                 */
#define SSP             ((SSP_REGS    *) SSP_BASE    )        /*!< SSP Declaration                  */
#define I2C             ((I2C_REGS    *) I2C_BASE    )        /*!< I2C Declaration                  */
#define TIMER0          ((TIMER_REGS  *) TIMER0_BASE )        /*!< Timer0 Declaration               */
#define TIMER1          ((TIMER_REGS  *) TIMER1_BASE )        /*!< Timer1 Declaration               */
#define TIMER2          ((TIMER_REGS  *) TIMER2_BASE )        /*!< Timer2 Declaration               */
#define CRC             ((CRC_REGS    *) CRC_BASE    )        /*!< CRC Declaration                  */
#define AES             ((AES_REGS    *) AES_BASE    )        /*!< AES Declaration                  */
#define FLASH           ((FLASH_REGS  *) FLASH_BASE  )        /*!< FLASH Declaration                */
#define ADC             ((ADC_REGS    *) ADC_BASE    )        /*!< ADC Declaration                  */
#define PGA             ((PGA_REGS    *) PGA_BASE    )        /*!< PGA Declaration                  */
#define COMP            ((COMP_REGS   *) COMP_BASE   )        /*!< COMP Declaration                 */
#define PWM0            ((PWM_REGS    *) PWM0_BASE   )        /*!< PWM0 Declaration                 */
#define PWM1            ((PWM_REGS    *) PWM1_BASE   )        /*!< PWM1 Declaration                 */
#define PWM2            ((PWM_REGS    *) PWM2_BASE   )        /*!< PWM2 Declaration                 */
#define PWM3            ((PWM_REGS    *) PWM3_BASE   )        /*!< PWM3 Declaration                 */
#define PWM4            ((PWM_REGS    *) PWM4_BASE   )        /*!< PWM4 Declaration                 */
#define PWM5            ((PWM_REGS    *) PWM5_BASE   )        /*!< PWM5 Declaration                 */
#define PWMCFG          ((PWMCFG_REGS *) PWMCFG_BASE )        /*!< PWM CFG Declaration              */
#define ECAP            ((ECAP_REGS   *) ECAP_BASE   )        /*!< eCAP Declaration                 */
#define SIO0            ((SIO_REGS    *) SIO_BASE    )        /*!< SIO Declaration                  */




/**
 *  @brief  Define Data Type
 */
typedef volatile unsigned char  vu8;        /*!< Define 8-bit unsigned volatile data type           */
typedef volatile unsigned short vu16;       /*!< Define 16-bit unsigned volatile data type          */
typedef volatile unsigned int   vu32;       /*!< Define 32-bit unsigned volatile data type          */




/******************************************************************************
 * @brief      Get a 8-bit unsigned value from specified address
 *
 * @param[in]  addr: Address to get 8-bit data from
 *
 * @return     8-bit unsigned value stored in specified address
 *
 ******************************************************************************/
#define M8(addr)                  (*((vu8  *) (addr)))




/******************************************************************************
 * @brief      Get a 16-bit unsigned value from specified address
 *
 * @param[in]  addr: Address to get 16-bit data from
 *
 * @return     16-bit unsigned value stored in specified address
 *
 * @note       The input address must be 16-bit aligned
 *
 ******************************************************************************/
#define M16(addr)                 (*((vu16 *) (addr)))




/******************************************************************************
 * @brief      Get a 32-bit unsigned value from specified address
 *
 * @param[in]  addr: Address to get 32-bit data from
 *
 * @return     32-bit unsigned value stored in specified address
 *
 * @note       The input address must be 32-bit aligned
 *
 ******************************************************************************/
#define M32(addr)                 (*((vu32 *) (addr)))




/******************************************************************************
 * @brief      Set a 32-bit unsigned value to specified I/O port
 *
 * @param[in]  port : Port address to set 32-bit data
 * @param[in]  value: Value to write to I/O port
 *
 * @return     none
 *
 * @note       The output port must be 32-bit aligned
 *
 ******************************************************************************/
#define outpw(port,value)         *((volatile unsigned int *)(port)) = value




/******************************************************************************
 * @brief      Get a 32-bit unsigned value from specified I/O port
 *
 * @param[in]  port: Port address to get 32-bit data from
 *
 * @return     32-bit unsigned value stored in specified I/O port
 *
 * @note       The input port must be 32-bit aligned
 *
 ******************************************************************************/
#define inpw(port)                (*((volatile unsigned int *)(port)))




/******************************************************************************
 * @brief      Set a 16-bit unsigned value to specified I/O port
 *
 * @param[in]  port : Port address to set 16-bit data
 * @param[in]  value: Value to write to I/O port
 *
 * @return     none
 *
 * @note       The output port must be 16-bit aligned
 *
 ******************************************************************************/
#define outps(port,value)         *((volatile unsigned short *)(port)) = value




/******************************************************************************
 * @brief      Get a 16-bit unsigned value from specified I/O port
 *
 * @param[in]  port: Port address to get 16-bit data from
 *
 * @return     16-bit unsigned value stored in specified I/O port
 *
 * @note       The input port must be 16-bit aligned
 *
 ******************************************************************************/
#define inps(port)                (*((volatile unsigned short *)(port)))




/******************************************************************************
 * @brief      Set a 8-bit unsigned value to specified I/O port
 *
 * @param[in]  port : Port address to set 8-bit data
 * @param[in]  value: Value to write to I/O port
 *
 * @return     none
 *
 ******************************************************************************/
#define outpb(port,value)         *((volatile unsigned char *)(port)) = value




/******************************************************************************
 * @brief      Get a 8-bit unsigned value from specified I/O port
 *
 * @param[in]  port : Port address to get 8-bit data from
 *
 * @return     8-bit unsigned value stored in specified I/O port
 *
 ******************************************************************************/
#define inpb(port)                (*((volatile unsigned char *)(port)))




/******************************************************************************
 * @brief      Set a 32-bit unsigned value to specified I/O port
 *
 * @param[in]  port : Port address to set 32-bit data
 * @param[in]  value: Value to write to I/O port
 *
 * @return     none
 *
 * @note       The output port must be 32-bit aligned
 *
 ******************************************************************************/
#define outp32(port,value)        *((volatile unsigned int *)(port)) = value




/******************************************************************************
 * @brief      Get a 32-bit unsigned value from specified I/O port
 *
 * @param[in]  port: Port address to get 32-bit data from
 *
 * @return     32-bit unsigned value stored in specified I/O port
 *
 * @note       The input port must be 32-bit aligned
 *
 ******************************************************************************/
#define inp32(port)               (*((volatile unsigned int *)(port)))




/******************************************************************************
 * @brief      Set a 16-bit unsigned value to specified I/O port
 *
 * @param[in]  port : Port address to set 16-bit data
 * @param[in]  value: Value to write to I/O port
 *
 * @return     none
 *
 * @note       The output port must be 16-bit aligned
 *
 ******************************************************************************/
#define outp16(port,value)        *((volatile unsigned short *)(port)) = value




/******************************************************************************
 * @brief      Get a 16-bit unsigned value from specified I/O port
 *
 * @param[in]  port: Port address to get 16-bit data from
 *
 * @return     16-bit unsigned value stored in specified I/O port
 *
 * @note       The input port must be 16-bit aligned
 *
 ******************************************************************************/
#define inp16(port)               (*((volatile unsigned short *)(port)))




/******************************************************************************
 * @brief      Set a 8-bit unsigned value to specified I/O port
 *
 * @param[in]  port : Port address to set 8-bit data
 * @param[in]  value: Value to write to I/O port
 *
 * @return     none
 *
 ******************************************************************************/
#define outp8(port,value)         *((volatile unsigned char *)(port)) = value




/******************************************************************************
 * @brief      Get a 8-bit unsigned value from specified I/O port
 *
 * @param[in]  port: Port address to get 8-bit data from
 *
 * @return     8-bit unsigned value stored in specified I/O port
 *
 ******************************************************************************/
#define inp8(port)                (*((volatile unsigned char *)(port)))




/**
 *  @brief  Null Type definition
 */
#ifndef NULL
#define NULL            (0)                 /*!< Null Pointer                                       */
#endif


/**
 *  @brief  Define one bit mask
 */
#define BIT0            (0x00000001)        /*!< Bit  0 mask of an 32 bit integer                   */
#define BIT1            (0x00000002)        /*!< Bit  1 mask of an 32 bit integer                   */
#define BIT2            (0x00000004)        /*!< Bit  2 mask of an 32 bit integer                   */
#define BIT3            (0x00000008)        /*!< Bit  3 mask of an 32 bit integer                   */
#define BIT4            (0x00000010)        /*!< Bit  4 mask of an 32 bit integer                   */
#define BIT5            (0x00000020)        /*!< Bit  5 mask of an 32 bit integer                   */
#define BIT6            (0x00000040)        /*!< Bit  6 mask of an 32 bit integer                   */
#define BIT7            (0x00000080)        /*!< Bit  7 mask of an 32 bit integer                   */
#define BIT8            (0x00000100)        /*!< Bit  8 mask of an 32 bit integer                   */
#define BIT9            (0x00000200)        /*!< Bit  9 mask of an 32 bit integer                   */
#define BIT10           (0x00000400)        /*!< Bit 10 mask of an 32 bit integer                   */
#define BIT11           (0x00000800)        /*!< Bit 11 mask of an 32 bit integer                   */
#define BIT12           (0x00001000)        /*!< Bit 12 mask of an 32 bit integer                   */
#define BIT13           (0x00002000)        /*!< Bit 13 mask of an 32 bit integer                   */
#define BIT14           (0x00004000)        /*!< Bit 14 mask of an 32 bit integer                   */
#define BIT15           (0x00008000)        /*!< Bit 15 mask of an 32 bit integer                   */
#define BIT16           (0x00010000)        /*!< Bit 16 mask of an 32 bit integer                   */
#define BIT17           (0x00020000)        /*!< Bit 17 mask of an 32 bit integer                   */
#define BIT18           (0x00040000)        /*!< Bit 18 mask of an 32 bit integer                   */
#define BIT19           (0x00080000)        /*!< Bit 19 mask of an 32 bit integer                   */
#define BIT20           (0x00100000)        /*!< Bit 20 mask of an 32 bit integer                   */
#define BIT21           (0x00200000)        /*!< Bit 21 mask of an 32 bit integer                   */
#define BIT22           (0x00400000)        /*!< Bit 22 mask of an 32 bit integer                   */
#define BIT23           (0x00800000)        /*!< Bit 23 mask of an 32 bit integer                   */
#define BIT24           (0x01000000)        /*!< Bit 24 mask of an 32 bit integer                   */
#define BIT25           (0x02000000)        /*!< Bit 25 mask of an 32 bit integer                   */
#define BIT26           (0x04000000)        /*!< Bit 26 mask of an 32 bit integer                   */
#define BIT27           (0x08000000)        /*!< Bit 27 mask of an 32 bit integer                   */
#define BIT28           (0x10000000)        /*!< Bit 28 mask of an 32 bit integer                   */
#define BIT29           (0x20000000)        /*!< Bit 29 mask of an 32 bit integer                   */
#define BIT30           (0x40000000)        /*!< Bit 30 mask of an 32 bit integer                   */
#define BIT31           (0x80000000)        /*!< Bit 31 mask of an 32 bit integer                   */


/**
 *  @brief  Byte Mask Definitions
 */
#define BYTE0_Msk       (0x000000FF)        /*!< Mask to get bit 0~bit 7 from a 32 bit integer      */
#define BYTE1_Msk       (0x0000FF00)        /*!< Mask to get bit 8~bit15 from a 32 bit integer      */
#define BYTE2_Msk       (0x00FF0000)        /*!< Mask to get bit16~bit23 from a 32 bit integer      */
#define BYTE3_Msk       (0xFF000000)        /*!< Mask to get bit24~bit31 from a 32 bit integer      */




/******************************************************************************
 * @brief      Extract byte 0 from specified 32-bit unsigned value
 *
 * @param[in]  u32Param: 32-bit unsigned value
 *
 * @return     Byte 0 value
 *
 ******************************************************************************/
#define GET_BYTE0(u32Param)       ((u32Param & BYTE0_Msk)      )




/******************************************************************************
 * @brief      Extract byte 1 from specified 32-bit unsigned value
 *
 * @param[in]  u32Param: 32-bit unsigned value
 *
 * @return     Byte 1 value
 *
 ******************************************************************************/
#define GET_BYTE1(u32Param)       ((u32Param & BYTE1_Msk) >>  8)




/******************************************************************************
 * @brief      Extract byte 2 from specified 32-bit unsigned value
 *
 * @param[in]  u32Param: 32-bit unsigned value
 *
 * @return     Byte 2 value
 *
 ******************************************************************************/
#define GET_BYTE2(u32Param)       ((u32Param & BYTE2_Msk) >> 16)




/******************************************************************************
 * @brief      Extract byte 3 from specified 32-bit unsigned value
 *
 * @param[in]  u32Param: 32-bit unsigned value
 *
 * @return     Byte 3 value
 *
 ******************************************************************************/
#define GET_BYTE3(u32Param)       ((u32Param & BYTE3_Msk) >> 24)




/******************************************************************************
 * @brief      Calculate the absolute value of x
 *
 * @param[in]  x: Integer value
 *
 * @return     The absolute value of x
 *
 ******************************************************************************/
#define ABS(x)                    (((x)<0)? (-(x)):(x))




/******************************************************************************
 * @brief      Convert bit band address and bit number into bit band alias address
 *
 * @param[in]  addr: Peripheral register address
 * @param[in]  addr: Register bit number
 *
 * @return     Bit band alias address
 *
 ******************************************************************************/
#define BITBAND(addr,bitnum)      ((addr & 0xF0000000) + 0x2000000 + ((addr & 0xFFFFF)<<5)+(bitnum<<2))




/******************************************************************************
 * @brief      Convert the address as a pointer and get its value
 *
 * @param[in]  addr: Memory address
 *
 * @return     Value in the memory address
 *
 ******************************************************************************/
#define MEM_ADDR(addr)            (*((volatile unsigned long *)(addr)))




/******************************************************************************
 * @brief      Get register bit value with bit-band feature
 *
 * @param[in]  addr  : Peripheral register address
 * @param[in]  bitnum: Register bit number
 *
 * @return     Bit value
 *
 ******************************************************************************/
#define REG_BIT(addr,bitnum)      MEM_ADDR(BITBAND(addr,bitnum))




/******************************************************************************
 * @brief      Set a single register bit
 *
 * @param[in]  REG: Peripheral register
 * @param[in]  POS: Register bit number
 *
 * @return     none
 *
 ******************************************************************************/
#define SET_BIT(REG, POS)         ((REG) |= ((0x1UL) << (POS)))




/******************************************************************************
 * @brief      Set register bits
 *
 * @param[in]  REG : Peripheral register
 * @param[in]  BITS: Register bits mask
 *
 * @return     none
 *
 ******************************************************************************/
#define SET_BITS(REG, BITS)       ((REG) |= (BITS))




/******************************************************************************
 * @brief      Clear a single register bit
 *
 * @param[in]  REG: Peripheral register
 * @param[in]  POS: Register bit number
 *
 * @return     none
 *
 ******************************************************************************/
#define CLEAR_BIT(REG, POS)       ((REG) &= ~((0x1UL) << (POS)))




/******************************************************************************
 * @brief      Clear register bits
 *
 * @param[in]  REG : Peripheral register
 * @param[in]  BITS: Register bits mask
 *
 * @return     none
 *
 ******************************************************************************/
#define CLEAR_BITS(REG, BITS)     ((REG) &= ~(BITS))




/******************************************************************************
 * @brief      Read a single register bit value
 *
 * @param[in]  REG: Peripheral register
 * @param[in]  POS: Register bit number
 *
 * @return     Register bit value
 *
 ******************************************************************************/
#define READ_BIT(REG, POS)        (((REG) >> (POS)) & 0x1UL)




/******************************************************************************
 * @brief      Clear register
 *
 * @param[in]  REG: Peripheral register
 *
 * @return     none
 *
 ******************************************************************************/
#define CLEAR_REG(REG)            ((REG) = (0x0))




/******************************************************************************
 * @brief      Write value to register
 *
 * @param[in]  REG: Peripheral register
 * @param[in]  VAL: Value to be written
 *
 * @return     none
 *
 ******************************************************************************/
#define WRITE_REG(REG, VAL)       ((REG) = (VAL))




/******************************************************************************
 * @brief      Read register value
 *
 * @param[in]  REG: Peripheral register
 *
 * @return     Register value
 *
 ******************************************************************************/
#define READ_REG(REG)             ((REG))




/******************************************************************************
 * @brief      Modify register bits value
 *
 * @param[in]  REG      : Peripheral register
 * @param[in]  CLEARMASK: Register bits value clear mask
 * @param[in]  SETMASK  : Register bits value set mask
 *
 * @return     none
 *
 ******************************************************************************/
#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))




/**
 *  @brief  SPC1168 Peripheral Header Files
 */
#include "clock.h"
#include "aes.h"
#include "crc.h"
#include "uart.h"
#include "wdt.h"
#include "timer.h"
#include "flash.h"
#include "ssp.h"
#include "i2c.h"
#include "gpio.h"
#include "ecap.h"
#include "power.h"
#include "system.h"
#include "pwm.h"
#include "adc.h"
#include "pga.h"
#include "comp.h"
#include "delay.h"


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* end of SPC1168_H */


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
