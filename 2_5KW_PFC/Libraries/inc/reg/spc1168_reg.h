/******************************************************************************
 * @file     spc1168_reg.h
 * @brief    SPC1168 register structure definition.
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

#ifndef SPC1168_REG_H
#define SPC1168_REG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "core_cm4.h"




/********************************************************************************
*
* Module Name     SYSTEM
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the Chip ID Register 0 (CID0), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  CID0_BIT_VAL           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CID0_REG;



/**
 *  @brief  Union type to access the Chip ID Register 1 (CID1), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  CID1_BIT_VAL           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CID1_REG;



/**
 *  @brief  Union type to access the Unique ID Register 0 (UID0), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  UID0_BIT_VAL           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UID0_REG;



/**
 *  @brief  Union type to access the Unique ID Register 1 (UID1), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  UID1_BIT_VAL           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UID1_REG;



/**
 *  @brief  Union type to access the Random Number Register 0 (RND0), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  RND0_BIT_VAL           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} RND0_REG;



/**
 *  @brief  Union type to access the Random Number Register 1 (RND1), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  RND1_BIT_VAL           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} RND1_REG;



/**
 *  @brief  Union type to access the Revision Information Register 0 (REV0), offset 0x18.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  REV0_BIT_VAL           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} REV0_REG;



/**
 *  @brief  Union type to access the Revision Information Register 1 (REV1), offset 0x1C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  REV1_BIT_VAL           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} REV1_REG;



/**
 *  @brief  Union type to access the Memory Error Interrupt Flag Register (MEMIF), offset 0x20.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t ROM1ERR       : 1;  /*!< bit:      0  MEMIF_BIT_ROM1ERR      */
        uint32_t ROM2ERR       : 1;  /*!< bit:      1  MEMIF_BIT_ROM2ERR      */
        uint32_t FLASH1ERR     : 1;  /*!< bit:      2  MEMIF_BIT_FLASH1ERR    */
        uint32_t FLASH2ERR     : 1;  /*!< bit:      3  MEMIF_BIT_FLASH2ERR    */
        uint32_t IRAMERR       : 1;  /*!< bit:      4  MEMIF_BIT_IRAMERR      */
        uint32_t DRAMERR       : 1;  /*!< bit:      5  MEMIF_BIT_DRAMERR      */
        uint32_t SIOERR        : 1;  /*!< bit:      6  MEMIF_BIT_SIOERR       */
        uint32_t MEMINT        : 1;  /*!< bit:      7  MEMIF_BIT_MEMINT       */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} MEMIF_REG;



/**
 *  @brief  Union type to access the Memory Error Interrupt Clear Register (MEMIC), offset 0x24.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t ROM1ERR       : 1;  /*!< bit:      0  MEMIC_BIT_ROM1ERR      */
        uint32_t ROM2ERR       : 1;  /*!< bit:      1  MEMIC_BIT_ROM2ERR      */
        uint32_t FLASH1ERR     : 1;  /*!< bit:      2  MEMIC_BIT_FLASH1ERR    */
        uint32_t FLASH2ERR     : 1;  /*!< bit:      3  MEMIC_BIT_FLASH2ERR    */
        uint32_t IRAMERR       : 1;  /*!< bit:      4  MEMIC_BIT_IRAMERR      */
        uint32_t DRAMERR       : 1;  /*!< bit:      5  MEMIC_BIT_DRAMERR      */
        uint32_t SIOERR        : 1;  /*!< bit:      6  MEMIC_BIT_SIOERR       */
        uint32_t MEMINT        : 1;  /*!< bit:      7  MEMIC_BIT_MEMINT       */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} MEMIC_REG;



/**
 *  @brief  Union type to access the Memory Error Interrupt Enable Register (MEMIE), offset 0x28.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t ROM1ERR       : 1;  /*!< bit:      0  MEMIE_BIT_ROM1ERR      */
        uint32_t ROM2ERR       : 1;  /*!< bit:      1  MEMIE_BIT_ROM2ERR      */
        uint32_t FLASH1ERR     : 1;  /*!< bit:      2  MEMIE_BIT_FLASH1ERR    */
        uint32_t FLASH2ERR     : 1;  /*!< bit:      3  MEMIE_BIT_FLASH2ERR    */
        uint32_t IRAMERR       : 1;  /*!< bit:      4  MEMIE_BIT_IRAMERR      */
        uint32_t DRAMERR       : 1;  /*!< bit:      5  MEMIE_BIT_DRAMERR      */
        uint32_t SIOERR        : 1;  /*!< bit:      6  MEMIE_BIT_SIOERR       */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} MEMIE_REG;



/**
 *  @brief  Union type to access the Memory ECC Enable Register (MEMECCEN), offset 0x2C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t ROMECC        : 1;  /*!< bit:      0  MEMECCEN_BIT_ROMECC    */
        uint32_t FLASHECC      : 1;  /*!< bit:      1  MEMECCEN_BIT_FLASHECC  */
        uint32_t RESERVED_31_2 :30;  /*!< bit: 31.. 2                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} MEMECCEN_REG;



/**
 *  @brief  Union type to access the Memory Lock Status Register (MEMLOCKSTS), offset 0x30.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t FLASH0        : 1;  /*!< bit:      0  MEMLOCKSTS_BIT_FLASH0  */
        uint32_t FLASH1        : 1;  /*!< bit:      1  MEMLOCKSTS_BIT_FLASH1  */
        uint32_t FLASH2        : 1;  /*!< bit:      2  MEMLOCKSTS_BIT_FLASH2  */
        uint32_t FLASH3        : 1;  /*!< bit:      3  MEMLOCKSTS_BIT_FLASH3  */
        uint32_t USER0INFO     : 1;  /*!< bit:      4  MEMLOCKSTS_BIT_USER0INFO*/
        uint32_t USER1INFO     : 1;  /*!< bit:      5  MEMLOCKSTS_BIT_USER1INFO*/
        uint32_t USER2INFO     : 1;  /*!< bit:      6  MEMLOCKSTS_BIT_USER2INFO*/
        uint32_t USER3INFO     : 1;  /*!< bit:      7  MEMLOCKSTS_BIT_USER3INFO*/
        uint32_t FLASHOTP      : 1;  /*!< bit:      8  MEMLOCKSTS_BIT_FLASHOTP*/
        uint32_t RAM0          : 1;  /*!< bit:      9  MEMLOCKSTS_BIT_RAM0    */
        uint32_t RAM1          : 1;  /*!< bit:     10  MEMLOCKSTS_BIT_RAM1    */
        uint32_t RAM2          : 1;  /*!< bit:     11  MEMLOCKSTS_BIT_RAM2    */
        uint32_t RAM3          : 1;  /*!< bit:     12  MEMLOCKSTS_BIT_RAM3    */
        uint32_t RESERVED_31_13:19;  /*!< bit: 31..13                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} MEMLOCKSTS_REG;



/**
 *  @brief  Union type to access the Reset Event Status Register (RSTEVTSTS), offset 0x34.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t ROMERR        : 1;  /*!< bit:      0  RSTEVTSTS_BIT_ROMERR   */
        uint32_t FLASHERR      : 1;  /*!< bit:      1  RSTEVTSTS_BIT_FLASHERR */
        uint32_t IRAMERR       : 1;  /*!< bit:      2  RSTEVTSTS_BIT_IRAMERR  */
        uint32_t DRAMERR       : 1;  /*!< bit:      3  RSTEVTSTS_BIT_DRAMERR  */
        uint32_t SIOERR        : 1;  /*!< bit:      4  RSTEVTSTS_BIT_SIOERR   */
        uint32_t VDD12L0       : 1;  /*!< bit:      5  RSTEVTSTS_BIT_VDD12L0  */
        uint32_t VDD12L1       : 1;  /*!< bit:      6  RSTEVTSTS_BIT_VDD12L1  */
        uint32_t VDD12H        : 1;  /*!< bit:      7  RSTEVTSTS_BIT_VDD12H   */
        uint32_t VDD33L        : 1;  /*!< bit:      8  RSTEVTSTS_BIT_VDD33L   */
        uint32_t VDD33H        : 1;  /*!< bit:      9  RSTEVTSTS_BIT_VDD33H   */
        uint32_t PLLUNLOCK     : 1;  /*!< bit:     10  RSTEVTSTS_BIT_PLLUNLOCK*/
        uint32_t CLKDETERR     : 1;  /*!< bit:     11  RSTEVTSTS_BIT_CLKDETERR*/
        uint32_t WDT0RST       : 1;  /*!< bit:     12  RSTEVTSTS_BIT_WDT0RST  */
        uint32_t WDT1RST       : 1;  /*!< bit:     13  RSTEVTSTS_BIT_WDT1RST  */
        uint32_t SYSRESET      : 1;  /*!< bit:     14  RSTEVTSTS_BIT_SYSRESET */
        uint32_t RESERVED_31_15:17;  /*!< bit: 31..15                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} RSTEVTSTS_REG;



/**
 *  @brief  Union type to access the Reset Event Status Clear Register (RSTEVTCLR), offset 0x38.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t ROMERR        : 1;  /*!< bit:      0  RSTEVTCLR_BIT_ROMERR   */
        uint32_t FLASHERR      : 1;  /*!< bit:      1  RSTEVTCLR_BIT_FLASHERR */
        uint32_t IRAMERR       : 1;  /*!< bit:      2  RSTEVTCLR_BIT_IRAMERR  */
        uint32_t DRAMERR       : 1;  /*!< bit:      3  RSTEVTCLR_BIT_DRAMERR  */
        uint32_t SIOERR        : 1;  /*!< bit:      4  RSTEVTCLR_BIT_SIOERR   */
        uint32_t VDD12L0       : 1;  /*!< bit:      5  RSTEVTCLR_BIT_VDD12L0  */
        uint32_t VDD12L1       : 1;  /*!< bit:      6  RSTEVTCLR_BIT_VDD12L1  */
        uint32_t VDD12H        : 1;  /*!< bit:      7  RSTEVTCLR_BIT_VDD12H   */
        uint32_t VDD33L        : 1;  /*!< bit:      8  RSTEVTCLR_BIT_VDD33L   */
        uint32_t VDD33H        : 1;  /*!< bit:      9  RSTEVTCLR_BIT_VDD33H   */
        uint32_t PLLUNLOCK     : 1;  /*!< bit:     10  RSTEVTCLR_BIT_PLLUNLOCK*/
        uint32_t CLKDETERR     : 1;  /*!< bit:     11  RSTEVTCLR_BIT_CLKDETERR*/
        uint32_t WDT0RST       : 1;  /*!< bit:     12  RSTEVTCLR_BIT_WDT0RST  */
        uint32_t WDT1RST       : 1;  /*!< bit:     13  RSTEVTCLR_BIT_WDT1RST  */
        uint32_t SYSRESET      : 1;  /*!< bit:     14  RSTEVTCLR_BIT_SYSRESET */
        uint32_t RESERVED_31_15:17;  /*!< bit: 31..15                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} RSTEVTCLR_REG;



/**
 *  @brief  Union type to access the Reset Event Enable Register (RSTEVTEN), offset 0x3C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t ROMERR        : 1;  /*!< bit:      0  RSTEVTEN_BIT_ROMERR    */
        uint32_t FLASHERR      : 1;  /*!< bit:      1  RSTEVTEN_BIT_FLASHERR  */
        uint32_t IRAMERR       : 1;  /*!< bit:      2  RSTEVTEN_BIT_IRAMERR   */
        uint32_t DRAMERR       : 1;  /*!< bit:      3  RSTEVTEN_BIT_DRAMERR   */
        uint32_t SIOERR        : 1;  /*!< bit:      4  RSTEVTEN_BIT_SIOERR    */
        uint32_t VDD12L0       : 1;  /*!< bit:      5  RSTEVTEN_BIT_VDD12L0   */
        uint32_t VDD12L1       : 1;  /*!< bit:      6  RSTEVTEN_BIT_VDD12L1   */
        uint32_t VDD12H        : 1;  /*!< bit:      7  RSTEVTEN_BIT_VDD12H    */
        uint32_t VDD33L        : 1;  /*!< bit:      8  RSTEVTEN_BIT_VDD33L    */
        uint32_t VDD33H        : 1;  /*!< bit:      9  RSTEVTEN_BIT_VDD33H    */
        uint32_t PLLUNLOCK     : 1;  /*!< bit:     10  RSTEVTEN_BIT_PLLUNLOCK */
        uint32_t CLKDETERR     : 1;  /*!< bit:     11  RSTEVTEN_BIT_CLKDETERR */
        uint32_t RESERVED_31_12:20;  /*!< bit: 31..12                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} RSTEVTEN_REG;



/**
 *  @brief  Union type to access the System Information Register (SYSINFO), offset 0x40.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t FLASHSIZE     : 2;  /*!< bit:  1.. 0  SYSINFO_BIT_FLASHSIZE  */
        uint32_t RAMSIZE       : 2;  /*!< bit:  3.. 2  SYSINFO_BIT_RAMSIZE    */
        uint32_t CLKOPT        : 3;  /*!< bit:  6.. 4  SYSINFO_BIT_CLKOPT     */
        uint32_t ADCBIT        : 2;  /*!< bit:  8.. 7  SYSINFO_BIT_ADCBIT     */
        uint32_t RESERVED_31_9 :23;  /*!< bit: 31.. 9                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SYSINFO_REG;



/**
 *  @brief  Union type to access the System Register Write-Allow Key Register (SYSREGKEY), offset 0x44.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t KEY           :32;  /*!< bit: 31.. 0  SYSREGKEY_BIT_KEY      */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SYSREGKEY_REG;



/**
  *  @brief  Structure type to access the SYSTEM Controller (SYSTEM).
  */
typedef struct
{
    __IO CID0_REG           CID0                ; /*!< Offset: 0x00000000 (RW  )  Chip ID Register 0                        */
    __IO CID1_REG           CID1                ; /*!< Offset: 0x00000004 (RW  )  Chip ID Register 1                        */
    __IO UID0_REG           UID0                ; /*!< Offset: 0x00000008 (RW  )  Unique ID Register 0                      */
    __IO UID1_REG           UID1                ; /*!< Offset: 0x0000000C (RW  )  Unique ID Register 1                      */
    __IO RND0_REG           RND0                ; /*!< Offset: 0x00000010 (RW  )  Random Number Register 0                  */
    __IO RND1_REG           RND1                ; /*!< Offset: 0x00000014 (RW  )  Random Number Register 1                  */
    __I  REV0_REG           REV0                ; /*!< Offset: 0x00000018 (RO  )  Revision Information Register 0           */
    __I  REV1_REG           REV1                ; /*!< Offset: 0x0000001C (RO  )  Revision Information Register 1           */
    __I  MEMIF_REG          MEMIF               ; /*!< Offset: 0x00000020 (RO  )  Memory Error Interrupt Flag Register      */
    __O  MEMIC_REG          MEMIC               ; /*!< Offset: 0x00000024 (WO  )  Memory Error Interrupt Clear Register     */
    __IO MEMIE_REG          MEMIE               ; /*!< Offset: 0x00000028 (RW  )  Memory Error Interrupt Enable Register    */
    __IO MEMECCEN_REG       MEMECCEN            ; /*!< Offset: 0x0000002C (RW  )  Memory ECC Enable Register                */
    __I  MEMLOCKSTS_REG     MEMLOCKSTS          ; /*!< Offset: 0x00000030 (RO  )  Memory Lock Status Register               */
    __I  RSTEVTSTS_REG      RSTEVTSTS           ; /*!< Offset: 0x00000034 (RO  )  Reset Event Status Register               */
    __O  RSTEVTCLR_REG      RSTEVTCLR           ; /*!< Offset: 0x00000038 (WO  )  Reset Event Status Clear Register         */
    __IO RSTEVTEN_REG       RSTEVTEN            ; /*!< Offset: 0x0000003C (RW  )  Reset Event Enable Register               */
    __I  SYSINFO_REG        SYSINFO             ; /*!< Offset: 0x00000040 (RO  )  System Information Register               */
    __IO SYSREGKEY_REG      SYSREGKEY           ; /*!< Offset: 0x00000044 (RW  )  System Register Write-Allow Key Register  */
} SYSTEM_REGS;



/********************************************************************************
*
* Module Name     POWER
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the Power Status Register (PWRSTS), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t FLASHREGRDY   : 1;  /*!< bit:      0  PWRSTS_BIT_FLASHREGRDY */
        uint32_t RESERVED_1_1  : 1;  /*!< bit:      1                         */
        uint32_t RESERVED_2_2  : 1;  /*!< bit:      2                         */
        uint32_t RESERVED_3_3  : 1;  /*!< bit:      3                         */
        uint32_t RESERVED_4_4  : 1;  /*!< bit:      4                         */
        uint32_t RESERVED_5_5  : 1;  /*!< bit:      5                         */
        uint32_t RESERVED_31_6 :26;  /*!< bit: 31.. 6                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PWRSTS_REG;



/**
 *  @brief  Union type to access the LDO Control Register (LDOCTL), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VREFTRIM      : 4;  /*!< bit:  3.. 0  LDOCTL_BIT_VREFTRIM    */
        uint32_t RESERVED_31_4 :28;  /*!< bit: 31.. 4                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} LDOCTL_REG;



/**
 *  @brief  Union type to access the Low Power POR Control Register (PORCTL), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t XRSTFILT      : 2;  /*!< bit:  1.. 0  PORCTL_BIT_XRSTFILT    */
        uint32_t RESERVED_2_2  : 1;  /*!< bit:      2                         */
        uint32_t RESERVED_31_3 :29;  /*!< bit: 31.. 3                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PORCTL_REG;



/**
 *  @brief  Union type to access the BOD Interrupt Flag Register (BODIF), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VDD12L0       : 1;  /*!< bit:      0  BODIF_BIT_VDD12L0      */
        uint32_t VDD12L1       : 1;  /*!< bit:      1  BODIF_BIT_VDD12L1      */
        uint32_t VDD12H        : 1;  /*!< bit:      2  BODIF_BIT_VDD12H       */
        uint32_t VDD33L        : 1;  /*!< bit:      3  BODIF_BIT_VDD33L       */
        uint32_t VDD33H        : 1;  /*!< bit:      4  BODIF_BIT_VDD33H       */
        uint32_t BODINT        : 1;  /*!< bit:      5  BODIF_BIT_BODINT       */
        uint32_t RESERVED_31_6 :26;  /*!< bit: 31.. 6                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} BODIF_REG;



/**
 *  @brief  Union type to access the BOD Interrupt Clear Register (BODIC), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VDD12L0       : 1;  /*!< bit:      0  BODIC_BIT_VDD12L0      */
        uint32_t VDD12L1       : 1;  /*!< bit:      1  BODIC_BIT_VDD12L1      */
        uint32_t VDD12H        : 1;  /*!< bit:      2  BODIC_BIT_VDD12H       */
        uint32_t VDD33L        : 1;  /*!< bit:      3  BODIC_BIT_VDD33L       */
        uint32_t VDD33H        : 1;  /*!< bit:      4  BODIC_BIT_VDD33H       */
        uint32_t BODINT        : 1;  /*!< bit:      5  BODIC_BIT_BODINT       */
        uint32_t RESERVED_31_6 :26;  /*!< bit: 31.. 6                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} BODIC_REG;



/**
 *  @brief  Union type to access the BOD Interrupt Enable Register (BODIE), offset 0x18.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VDD12L0       : 1;  /*!< bit:      0  BODIE_BIT_VDD12L0      */
        uint32_t VDD12L1       : 1;  /*!< bit:      1  BODIE_BIT_VDD12L1      */
        uint32_t VDD12H        : 1;  /*!< bit:      2  BODIE_BIT_VDD12H       */
        uint32_t VDD33L        : 1;  /*!< bit:      3  BODIE_BIT_VDD33L       */
        uint32_t VDD33H        : 1;  /*!< bit:      4  BODIE_BIT_VDD33H       */
        uint32_t RESERVED_31_5 :27;  /*!< bit: 31.. 5                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} BODIE_REG;



/**
 *  @brief  Union type to access the BOD Control Register (BODCTL), offset 0x1C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VREFTRIM      : 4;  /*!< bit:  3.. 0  BODCTL_BIT_VREFTRIM    */
        uint32_t RESERVED_31_4 :28;  /*!< bit: 31.. 4                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} BODCTL_REG;



/**
 *  @brief  Union type to access the 3.3V BOD Control Register (BOD33CTL), offset 0x20.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t ENL           : 1;  /*!< bit:      0  BOD33CTL_BIT_ENL       */
        uint32_t ASVTHL        : 3;  /*!< bit:  3.. 1  BOD33CTL_BIT_ASVTHL    */
        uint32_t DEVTHL        : 3;  /*!< bit:  6.. 4  BOD33CTL_BIT_DEVTHL    */
        uint32_t RESERVED_7_7  : 1;  /*!< bit:      7                         */
        uint32_t ENH           : 1;  /*!< bit:      8  BOD33CTL_BIT_ENH       */
        uint32_t ASVTHH        : 3;  /*!< bit: 11.. 9  BOD33CTL_BIT_ASVTHH    */
        uint32_t DEVTHH        : 3;  /*!< bit: 14..12  BOD33CTL_BIT_DEVTHH    */
        uint32_t RESERVED_31_15:17;  /*!< bit: 31..15                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} BOD33CTL_REG;



/**
 *  @brief  Union type to access the 1.2V BOD Control Register (BOD12CTL), offset 0x24.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t ENL0          : 1;  /*!< bit:      0  BOD12CTL_BIT_ENL0      */
        uint32_t ASVTHL0       : 3;  /*!< bit:  3.. 1  BOD12CTL_BIT_ASVTHL0   */
        uint32_t DEVTHL0       : 3;  /*!< bit:  6.. 4  BOD12CTL_BIT_DEVTHL0   */
        uint32_t RESERVED_7_7  : 1;  /*!< bit:      7                         */
        uint32_t ENL1          : 1;  /*!< bit:      8  BOD12CTL_BIT_ENL1      */
        uint32_t ASVTHL1       : 3;  /*!< bit: 11.. 9  BOD12CTL_BIT_ASVTHL1   */
        uint32_t DEVTHL1       : 3;  /*!< bit: 14..12  BOD12CTL_BIT_DEVTHL1   */
        uint32_t RESERVED_15_15: 1;  /*!< bit:     15                         */
        uint32_t ENH           : 1;  /*!< bit:     16  BOD12CTL_BIT_ENH       */
        uint32_t ASVTHH        : 3;  /*!< bit: 19..17  BOD12CTL_BIT_ASVTHH    */
        uint32_t DEVTHH        : 3;  /*!< bit: 22..20  BOD12CTL_BIT_DEVTHH    */
        uint32_t RESERVED_31_23: 9;  /*!< bit: 31..23                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} BOD12CTL_REG;



/**
 *  @brief  Union type to access the Deep Sleep Enable Key Register (DPSLPKEY), offset 0x28.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t KEY           :32;  /*!< bit: 31.. 0  DPSLPKEY_BIT_KEY       */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DPSLPKEY_REG;



/**
 *  @brief  Union type to access the Power Register Write-Allow Key Register (PWRREGKEY), offset 0x2C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t KEY           :32;  /*!< bit: 31.. 0  PWRREGKEY_BIT_KEY      */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PWRREGKEY_REG;



/**
  *  @brief  Structure type to access the POWER Controller (POWER).
  */
typedef struct
{
    __I  PWRSTS_REG          PWRSTS               ; /*!< Offset: 0x00000000 (RO  )  Power Status Register                    */
    __IO LDOCTL_REG          LDOCTL               ; /*!< Offset: 0x00000004 (RW  )  LDO Control Register                     */
         uint32_t            RESERVED0            ; 
    __IO PORCTL_REG          PORCTL               ; /*!< Offset: 0x0000000C (RW  )  Low Power POR Control Register           */
    __I  BODIF_REG           BODIF                ; /*!< Offset: 0x00000010 (RO  )  BOD Interrupt Flag Register              */
    __O  BODIC_REG           BODIC                ; /*!< Offset: 0x00000014 (WO  )  BOD Interrupt Clear Register             */
    __IO BODIE_REG           BODIE                ; /*!< Offset: 0x00000018 (RW  )  BOD Interrupt Enable Register            */
    __IO BODCTL_REG          BODCTL               ; /*!< Offset: 0x0000001C (RW  )  BOD Control Register                     */
    __IO BOD33CTL_REG        BOD33CTL             ; /*!< Offset: 0x00000020 (RW  )  3.3V BOD Control Register                */
    __IO BOD12CTL_REG        BOD12CTL             ; /*!< Offset: 0x00000024 (RW  )  1.2V BOD Control Register                */
    __IO DPSLPKEY_REG        DPSLPKEY             ; /*!< Offset: 0x00000028 (RW  )  Deep Sleep Enable Key Register           */
    __IO PWRREGKEY_REG       PWRREGKEY            ; /*!< Offset: 0x0000002C (RW  )  Power Register Write-Allow Key Register  */
} POWER_REGS;



/********************************************************************************
*
* Module Name     CLOCK
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the Clock Status Register (CLKSTS), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t RCO0RDY       : 1;  /*!< bit:      0  CLKSTS_BIT_RCO0RDY     */
        uint32_t RCO1RDY       : 1;  /*!< bit:      1  CLKSTS_BIT_RCO1RDY     */
        uint32_t XORDY         : 1;  /*!< bit:      2  CLKSTS_BIT_XORDY       */
        uint32_t PLLRDY        : 1;  /*!< bit:      3  CLKSTS_BIT_PLLRDY      */
        uint32_t VCOFREQ       : 1;  /*!< bit:      4  CLKSTS_BIT_VCOFREQ     */
        uint32_t VCOFREQVLD    : 1;  /*!< bit:      5  CLKSTS_BIT_VCOFREQVLD  */
        uint32_t PLLFAST       : 1;  /*!< bit:      6  CLKSTS_BIT_PLLFAST     */
        uint32_t PLLSLOW       : 1;  /*!< bit:      7  CLKSTS_BIT_PLLSLOW     */
        uint32_t CLKDETERR     : 1;  /*!< bit:      8  CLKSTS_BIT_CLKDETERR   */
        uint32_t RESERVED_31_9 :23;  /*!< bit: 31.. 9                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CLKSTS_REG;



/**
 *  @brief  Union type to access the RCO0 Control Register (RCO0CTL), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t EN            : 1;  /*!< bit:      0  RCO0CTL_BIT_EN         */
        uint32_t LFMODE        : 1;  /*!< bit:      1  RCO0CTL_BIT_LFMODE     */
        uint32_t FREQTRIM      : 9;  /*!< bit: 10.. 2  RCO0CTL_BIT_FREQTRIM   */
        uint32_t RESERVED_31_11:21;  /*!< bit: 31..11                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} RCO0CTL_REG;



/**
 *  @brief  Union type to access the Crystal Oscillator Control Register (XOCTL), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t EN            : 1;  /*!< bit:      0  XOCTL_BIT_EN           */
        uint32_t FASTEN        : 1;  /*!< bit:      1  XOCTL_BIT_FASTEN       */
        uint32_t FREQSEL       : 2;  /*!< bit:  3.. 2  XOCTL_BIT_FREQSEL      */
        uint32_t PRECNT        : 8;  /*!< bit: 11.. 4  XOCTL_BIT_PRECNT       */
        uint32_t EXTRFB        : 1;  /*!< bit:     12  XOCTL_BIT_EXTRFB       */
        uint32_t FEEDXOUT      : 1;  /*!< bit:     13  XOCTL_BIT_FEEDXOUT     */
        uint32_t RESERVED_31_14:18;  /*!< bit: 31..14                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} XOCTL_REG;



/**
 *  @brief  Union type to access the PLL Control Register 0 (PLLCTL0), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t EN            : 1;  /*!< bit:      0  PLLCTL0_BIT_EN         */
        uint32_t OE            : 1;  /*!< bit:      1  PLLCTL0_BIT_OE         */
        uint32_t FCALEN        : 1;  /*!< bit:      2  PLLCTL0_BIT_FCALEN     */
        uint32_t FCALWIN       : 1;  /*!< bit:      3  PLLCTL0_BIT_FCALWIN    */
        uint32_t VCOTRIM       : 3;  /*!< bit:  6.. 4  PLLCTL0_BIT_VCOTRIM    */
        uint32_t RCLKSELXO     : 1;  /*!< bit:      7  PLLCTL0_BIT_RCLKSELXO  */
        uint32_t OPENLOOP      : 1;  /*!< bit:      8  PLLCTL0_BIT_OPENLOOP   */
        uint32_t ICP           : 5;  /*!< bit: 13.. 9  PLLCTL0_BIT_ICP        */
        uint32_t RESERVED_31_14:18;  /*!< bit: 31..14                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PLLCTL0_REG;



/**
 *  @brief  Union type to access the PLL Control Register 1 (PLLCTL1), offset 0x18.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t NFB           :24;  /*!< bit: 23.. 0  PLLCTL1_BIT_NFB        */
        uint32_t NIN           : 3;  /*!< bit: 26..24  PLLCTL1_BIT_NIN        */
        uint32_t NOUT          : 4;  /*!< bit: 30..27  PLLCTL1_BIT_NOUT       */
        uint32_t RESERVED_31_31: 1;  /*!< bit:     31                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PLLCTL1_REG;



/**
 *  @brief  Union type to access the Clock Detection Control Register (CLKDETCTL), offset 0x1C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t RCLKSEL       : 2;  /*!< bit:  1.. 0  CLKDETCTL_BIT_RCLKSEL  */
        uint32_t RCLKDIV       : 3;  /*!< bit:  4.. 2  CLKDETCTL_BIT_RCLKDIV  */
        uint32_t DCLKSEL       : 2;  /*!< bit:  6.. 5  CLKDETCTL_BIT_DCLKSEL  */
        uint32_t DCLKDIV       : 3;  /*!< bit:  9.. 7  CLKDETCTL_BIT_DCLKDIV  */
        uint32_t EN            : 1;  /*!< bit:     10  CLKDETCTL_BIT_EN       */
        uint32_t RESERVED_31_11:21;  /*!< bit: 31..11                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CLKDETCTL_REG;



/**
 *  @brief  Union type to access the Clock Detection Counter Threshold Register (CLKDETCTH), offset 0x20.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t LO            :16;  /*!< bit: 15.. 0  CLKDETCTH_BIT_LO       */
        uint32_t HI            :16;  /*!< bit: 31..16  CLKDETCTH_BIT_HI       */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CLKDETCTH_REG;



/**
 *  @brief  Union type to access the Clock Detection Counter Register (CLKDETCNT), offset 0x24.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  CLKDETCNT_BIT_VAL      */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CLKDETCNT_REG;



/**
 *  @brief  Union type to access the Clock Interrupt Flag Register (CLKIF), offset 0x28.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t PLLUNLOCK     : 1;  /*!< bit:      0  CLKIF_BIT_PLLUNLOCK    */
        uint32_t CLKDETERR     : 1;  /*!< bit:      1  CLKIF_BIT_CLKDETERR    */
        uint32_t CLKINT        : 1;  /*!< bit:      2  CLKIF_BIT_CLKINT       */
        uint32_t RESERVED_31_3 :29;  /*!< bit: 31.. 3                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CLKIF_REG;



/**
 *  @brief  Union type to access the Clock Interrupt Clear Register (CLKIC), offset 0x2C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t PLLUNLOCK     : 1;  /*!< bit:      0  CLKIC_BIT_PLLUNLOCK    */
        uint32_t CLKDETERR     : 1;  /*!< bit:      1  CLKIC_BIT_CLKDETERR    */
        uint32_t CLKINT        : 1;  /*!< bit:      2  CLKIC_BIT_CLKINT       */
        uint32_t RESERVED_31_3 :29;  /*!< bit: 31.. 3                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CLKIC_REG;



/**
 *  @brief  Union type to access the Clock Interrupt Enable Register (CLKIE), offset 0x30.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t PLLUNLOCK     : 1;  /*!< bit:      0  CLKIE_BIT_PLLUNLOCK    */
        uint32_t CLKDETERR     : 1;  /*!< bit:      1  CLKIE_BIT_CLKDETERR    */
        uint32_t RESERVED_31_2 :30;  /*!< bit: 31.. 2                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CLKIE_REG;



/**
 *  @brief  Union type to access the Clock Trip-zone Event Enable Register (CLKTZE), offset 0x34.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t PLLUNLOCK     : 1;  /*!< bit:      0  CLKTZE_BIT_PLLUNLOCK   */
        uint32_t CLKDETERR     : 1;  /*!< bit:      1  CLKTZE_BIT_CLKDETERR   */
        uint32_t RESERVED_31_2 :30;  /*!< bit: 31.. 2                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CLKTZE_REG;



/**
 *  @brief  Union type to access the SYSCLK0 Control Register (SYSCLK0CTL), offset 0x38.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t RESERVED_8_0  : 9;  /*!< bit:  8.. 0                         */
        uint32_t SRC           : 2;  /*!< bit: 10.. 9  SYSCLK0CTL_BIT_SRC     */
        uint32_t RESERVED_31_11:21;  /*!< bit: 31..11                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SYSCLK0CTL_REG;



/**
 *  @brief  Union type to access the HCLK Control Register (HCLKCTL), offset 0x3C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 8;  /*!< bit:  7.. 0  HCLKCTL_BIT_DIV        */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} HCLKCTL_REG;



/**
 *  @brief  Union type to access the ADC Clock Control Register (ADCCLKCTL), offset 0x40.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 8;  /*!< bit:  7.. 0  ADCCLKCTL_BIT_DIV      */
        uint32_t EN            : 1;  /*!< bit:      8  ADCCLKCTL_BIT_EN       */
        uint32_t RESERVED_31_9 :23;  /*!< bit: 31.. 9                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} ADCCLKCTL_REG;



/**
 *  @brief  Union type to access the PWM Clock Control Register (PWMCLKCTL), offset 0x44.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 8;  /*!< bit:  7.. 0  PWMCLKCTL_BIT_DIV      */
        uint32_t EN            : 1;  /*!< bit:      8  PWMCLKCTL_BIT_EN       */
        uint32_t RESERVED_31_9 :23;  /*!< bit: 31.. 9                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PWMCLKCTL_REG;



/**
 *  @brief  Union type to access the ECAP Clock Control Register (ECAPCLKCTL), offset 0x48.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 8;  /*!< bit:  7.. 0  ECAPCLKCTL_BIT_DIV     */
        uint32_t EN            : 1;  /*!< bit:      8  ECAPCLKCTL_BIT_EN      */
        uint32_t RESERVED_31_9 :23;  /*!< bit: 31.. 9                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} ECAPCLKCTL_REG;



/**
 *  @brief  Union type to access the Timer 0 Clock Control Register (TMR0CLKCTL), offset 0x4C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 8;  /*!< bit:  7.. 0  TMR0CLKCTL_BIT_DIV     */
        uint32_t EN            : 1;  /*!< bit:      8  TMR0CLKCTL_BIT_EN      */
        uint32_t RESERVED_31_9 :23;  /*!< bit: 31.. 9                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TMR0CLKCTL_REG;



/**
 *  @brief  Union type to access the Timer 1 Clock Control Register (TMR1CLKCTL), offset 0x50.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 8;  /*!< bit:  7.. 0  TMR1CLKCTL_BIT_DIV     */
        uint32_t EN            : 1;  /*!< bit:      8  TMR1CLKCTL_BIT_EN      */
        uint32_t RESERVED_31_9 :23;  /*!< bit: 31.. 9                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TMR1CLKCTL_REG;



/**
 *  @brief  Union type to access the Timer 2 Clock Control Register (TMR2CLKCTL), offset 0x54.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 8;  /*!< bit:  7.. 0  TMR2CLKCTL_BIT_DIV     */
        uint32_t EN            : 1;  /*!< bit:      8  TMR2CLKCTL_BIT_EN      */
        uint32_t RESERVED_31_9 :23;  /*!< bit: 31.. 9                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TMR2CLKCTL_REG;



/**
 *  @brief  Union type to access the SIO Clock Control Register (SIOCLKCTL), offset 0x58.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 8;  /*!< bit:  7.. 0  SIOCLKCTL_BIT_DIV      */
        uint32_t EN            : 1;  /*!< bit:      8  SIOCLKCTL_BIT_EN       */
        uint32_t RESERVED_31_9 :23;  /*!< bit: 31.. 9                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SIOCLKCTL_REG;



/**
 *  @brief  Union type to access the SYSCLK1 Control Register (SYSCLK1CTL), offset 0x5C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t RESERVED_8_0  : 9;  /*!< bit:  8.. 0                         */
        uint32_t SRC           : 2;  /*!< bit: 10.. 9  SYSCLK1CTL_BIT_SRC     */
        uint32_t RESERVED_31_11:21;  /*!< bit: 31..11                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SYSCLK1CTL_REG;



/**
 *  @brief  Union type to access the PCLK Control Register (PCLKCTL), offset 0x60.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 8;  /*!< bit:  7.. 0  PCLKCTL_BIT_DIV        */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PCLKCTL_REG;



/**
 *  @brief  Union type to access the Deglitch Clock Control Register (DGCLKCTL), offset 0x64.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 8;  /*!< bit:  7.. 0  DGCLKCTL_BIT_DIV       */
        uint32_t PDIV          : 3;  /*!< bit: 10.. 8  DGCLKCTL_BIT_PDIV      */
        uint32_t RESERVED_31_11:21;  /*!< bit: 31..11                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DGCLKCTL_REG;



/**
 *  @brief  Union type to access the UART Clock Control Register (UARTCLKCTL), offset 0x68.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 8;  /*!< bit:  7.. 0  UARTCLKCTL_BIT_DIV     */
        uint32_t EN            : 1;  /*!< bit:      8  UARTCLKCTL_BIT_EN      */
        uint32_t RESERVED_31_9 :23;  /*!< bit: 31.. 9                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTCLKCTL_REG;



/**
 *  @brief  Union type to access the SSP Clock Control Register (SSPCLKCTL), offset 0x6C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           :16;  /*!< bit: 15.. 0  SSPCLKCTL_BIT_DIV      */
        uint32_t EN            : 1;  /*!< bit:     16  SSPCLKCTL_BIT_EN       */
        uint32_t RESERVED_31_17:15;  /*!< bit: 31..17                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SSPCLKCTL_REG;



/**
 *  @brief  Union type to access the I2C Clock Control Register (I2CCLKCTL), offset 0x70.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 8;  /*!< bit:  7.. 0  I2CCLKCTL_BIT_DIV      */
        uint32_t EN            : 1;  /*!< bit:      8  I2CCLKCTL_BIT_EN       */
        uint32_t RESERVED_31_9 :23;  /*!< bit: 31.. 9                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} I2CCLKCTL_REG;



/**
 *  @brief  Union type to access the WDT0 Clock Control Register (WDT0CLKCTL), offset 0x74.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 8;  /*!< bit:  7.. 0  WDT0CLKCTL_BIT_DIV     */
        uint32_t EN            : 1;  /*!< bit:      8  WDT0CLKCTL_BIT_EN      */
        uint32_t SRC           : 2;  /*!< bit: 10.. 9  WDT0CLKCTL_BIT_SRC     */
        uint32_t RESERVED_31_11:21;  /*!< bit: 31..11                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} WDT0CLKCTL_REG;



/**
 *  @brief  Union type to access the WDT1 Clock Control Register (WDT1CLKCTL), offset 0x78.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 8;  /*!< bit:  7.. 0  WDT1CLKCTL_BIT_DIV     */
        uint32_t EN            : 1;  /*!< bit:      8  WDT1CLKCTL_BIT_EN      */
        uint32_t SRC           : 2;  /*!< bit: 10.. 9  WDT1CLKCTL_BIT_SRC     */
        uint32_t RESERVED_31_11:21;  /*!< bit: 31..11                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} WDT1CLKCTL_REG;



/**
 *  @brief  Union type to access the Clock Register Write-Allow Key Register (CLKREGKEY), offset 0x7C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t KEY           :32;  /*!< bit: 31.. 0  CLKREGKEY_BIT_KEY      */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CLKREGKEY_REG;



/**
  *  @brief  Structure type to access the CLOCK Controller (CLOCK).
  */
typedef struct
{
    __I  CLKSTS_REG         CLKSTS              ; /*!< Offset: 0x00000000 (RO  )  Clock Status Register                       */
         uint32_t           RESERVED0           ; 
    __IO RCO0CTL_REG        RCO0CTL             ; /*!< Offset: 0x00000008 (RW  )  RCO0 Control Register                       */
         uint32_t           RESERVED1           ; 
    __IO XOCTL_REG          XOCTL               ; /*!< Offset: 0x00000010 (RW  )  Crystal Oscillator Control Register         */
    __IO PLLCTL0_REG        PLLCTL0             ; /*!< Offset: 0x00000014 (RW  )  PLL Control Register 0                      */
    __IO PLLCTL1_REG        PLLCTL1             ; /*!< Offset: 0x00000018 (RW  )  PLL Control Register 1                      */
    __IO CLKDETCTL_REG      CLKDETCTL           ; /*!< Offset: 0x0000001C (RW  )  Clock Detection Control Register            */
    __IO CLKDETCTH_REG      CLKDETCTH           ; /*!< Offset: 0x00000020 (RW  )  Clock Detection Counter Threshold Register  */
    __I  CLKDETCNT_REG      CLKDETCNT           ; /*!< Offset: 0x00000024 (RO  )  Clock Detection Counter Register            */
    __I  CLKIF_REG          CLKIF               ; /*!< Offset: 0x00000028 (RO  )  Clock Interrupt Flag Register               */
    __O  CLKIC_REG          CLKIC               ; /*!< Offset: 0x0000002C (WO  )  Clock Interrupt Clear Register              */
    __IO CLKIE_REG          CLKIE               ; /*!< Offset: 0x00000030 (RW  )  Clock Interrupt Enable Register             */
    __IO CLKTZE_REG         CLKTZE              ; /*!< Offset: 0x00000034 (RW  )  Clock Trip-zone Event Enable Register       */
    __IO SYSCLK0CTL_REG     SYSCLK0CTL          ; /*!< Offset: 0x00000038 (RW  )  SYSCLK0 Control Register                    */
    __IO HCLKCTL_REG        HCLKCTL             ; /*!< Offset: 0x0000003C (RW  )  HCLK Control Register                       */
    __IO ADCCLKCTL_REG      ADCCLKCTL           ; /*!< Offset: 0x00000040 (RW  )  ADC Clock Control Register                  */
    __IO PWMCLKCTL_REG      PWMCLKCTL           ; /*!< Offset: 0x00000044 (RW  )  PWM Clock Control Register                  */
    __IO ECAPCLKCTL_REG     ECAPCLKCTL          ; /*!< Offset: 0x00000048 (RW  )  ECAP Clock Control Register                 */
    __IO TMR0CLKCTL_REG     TMR0CLKCTL          ; /*!< Offset: 0x0000004C (RW  )  Timer 0 Clock Control Register              */
    __IO TMR1CLKCTL_REG     TMR1CLKCTL          ; /*!< Offset: 0x00000050 (RW  )  Timer 1 Clock Control Register              */
    __IO TMR2CLKCTL_REG     TMR2CLKCTL          ; /*!< Offset: 0x00000054 (RW  )  Timer 2 Clock Control Register              */
    __IO SIOCLKCTL_REG      SIOCLKCTL           ; /*!< Offset: 0x00000058 (RW  )  SIO Clock Control Register                  */
    __IO SYSCLK1CTL_REG     SYSCLK1CTL          ; /*!< Offset: 0x0000005C (RW  )  SYSCLK1 Control Register                    */
    __IO PCLKCTL_REG        PCLKCTL             ; /*!< Offset: 0x00000060 (RW  )  PCLK Control Register                       */
    __IO DGCLKCTL_REG       DGCLKCTL            ; /*!< Offset: 0x00000064 (RW  )  Deglitch Clock Control Register             */
    __IO UARTCLKCTL_REG     UARTCLKCTL          ; /*!< Offset: 0x00000068 (RW  )  UART Clock Control Register                 */
    __IO SSPCLKCTL_REG      SSPCLKCTL           ; /*!< Offset: 0x0000006C (RW  )  SSP Clock Control Register                  */
    __IO I2CCLKCTL_REG      I2CCLKCTL           ; /*!< Offset: 0x00000070 (RW  )  I2C Clock Control Register                  */
    __IO WDT0CLKCTL_REG     WDT0CLKCTL          ; /*!< Offset: 0x00000074 (RW  )  WDT0 Clock Control Register                 */
    __IO WDT1CLKCTL_REG     WDT1CLKCTL          ; /*!< Offset: 0x00000078 (RW  )  WDT1 Clock Control Register                 */
    __IO CLKREGKEY_REG      CLKREGKEY           ; /*!< Offset: 0x0000007C (RW  )  Clock Register Write-Allow Key Register     */
} CLOCK_REGS;



/********************************************************************************
*
* Module Name     PINMUX
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the GPIO0 Pin Control Register (GPIO0), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO0_BIT_MUXSEL       */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO0_BIT_IE           */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO0_BIT_SMT          */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO0_BIT_DEGLITCH     */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO0_BIT_STRENGTH     */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO0_BIT_CHDFLTVAL    */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO0_BIT_PD           */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO0_BIT_PU           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO0_REG;



/**
 *  @brief  Union type to access the GPIO1 Pin Control Register (GPIO1), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO1_BIT_MUXSEL       */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO1_BIT_IE           */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO1_BIT_SMT          */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO1_BIT_DEGLITCH     */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO1_BIT_STRENGTH     */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO1_BIT_CHDFLTVAL    */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO1_BIT_PD           */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO1_BIT_PU           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO1_REG;



/**
 *  @brief  Union type to access the GPIO2 Pin Control Register (GPIO2), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO2_BIT_MUXSEL       */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO2_BIT_IE           */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO2_BIT_SMT          */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO2_BIT_DEGLITCH     */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO2_BIT_STRENGTH     */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO2_BIT_CHDFLTVAL    */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO2_BIT_PD           */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO2_BIT_PU           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO2_REG;



/**
 *  @brief  Union type to access the GPIO3 Pin Control Register (GPIO3), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO3_BIT_MUXSEL       */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO3_BIT_IE           */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO3_BIT_SMT          */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO3_BIT_DEGLITCH     */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO3_BIT_STRENGTH     */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO3_BIT_CHDFLTVAL    */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO3_BIT_PD           */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO3_BIT_PU           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO3_REG;



/**
 *  @brief  Union type to access the GPIO4 Pin Control Register (GPIO4), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO4_BIT_MUXSEL       */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO4_BIT_IE           */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO4_BIT_SMT          */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO4_BIT_DEGLITCH     */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO4_BIT_STRENGTH     */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO4_BIT_CHDFLTVAL    */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO4_BIT_PD           */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO4_BIT_PU           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO4_REG;



/**
 *  @brief  Union type to access the GPIO5 Pin Control Register (GPIO5), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO5_BIT_MUXSEL       */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO5_BIT_IE           */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO5_BIT_SMT          */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO5_BIT_DEGLITCH     */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO5_BIT_STRENGTH     */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO5_BIT_CHDFLTVAL    */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO5_BIT_PD           */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO5_BIT_PU           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO5_REG;



/**
 *  @brief  Union type to access the GPIO6 Pin Control Register (GPIO6), offset 0x18.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO6_BIT_MUXSEL       */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO6_BIT_IE           */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO6_BIT_SMT          */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO6_BIT_DEGLITCH     */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO6_BIT_STRENGTH     */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO6_BIT_CHDFLTVAL    */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO6_BIT_PD           */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO6_BIT_PU           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO6_REG;



/**
 *  @brief  Union type to access the GPIO7 Pin Control Register (GPIO7), offset 0x1C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO7_BIT_MUXSEL       */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO7_BIT_IE           */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO7_BIT_SMT          */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO7_BIT_DEGLITCH     */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO7_BIT_STRENGTH     */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO7_BIT_CHDFLTVAL    */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO7_BIT_PD           */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO7_BIT_PU           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO7_REG;



/**
 *  @brief  Union type to access the GPIO8 Pin Control Register (GPIO8), offset 0x20.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO8_BIT_MUXSEL       */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO8_BIT_IE           */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO8_BIT_SMT          */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO8_BIT_DEGLITCH     */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO8_BIT_STRENGTH     */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO8_BIT_CHDFLTVAL    */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO8_BIT_PD           */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO8_BIT_PU           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO8_REG;



/**
 *  @brief  Union type to access the GPIO9 Pin Control Register (GPIO9), offset 0x24.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO9_BIT_MUXSEL       */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO9_BIT_IE           */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO9_BIT_SMT          */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO9_BIT_DEGLITCH     */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO9_BIT_STRENGTH     */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO9_BIT_CHDFLTVAL    */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO9_BIT_PD           */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO9_BIT_PU           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO9_REG;



/**
 *  @brief  Union type to access the GPIO10 Pin Control Register (GPIO10), offset 0x28.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO10_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO10_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO10_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO10_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO10_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO10_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO10_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO10_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO10_REG;



/**
 *  @brief  Union type to access the GPIO11 Pin Control Register (GPIO11), offset 0x2C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO11_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO11_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO11_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO11_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO11_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO11_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO11_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO11_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO11_REG;



/**
 *  @brief  Union type to access the GPIO12 Pin Control Register (GPIO12), offset 0x30.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO12_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO12_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO12_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO12_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO12_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO12_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO12_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO12_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO12_REG;



/**
 *  @brief  Union type to access the GPIO13 Pin Control Register (GPIO13), offset 0x34.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO13_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO13_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO13_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO13_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO13_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO13_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO13_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO13_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO13_REG;



/**
 *  @brief  Union type to access the GPIO14 Pin Control Register (GPIO14), offset 0x38.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO14_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO14_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO14_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO14_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO14_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO14_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO14_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO14_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO14_REG;



/**
 *  @brief  Union type to access the GPIO15 Pin Control Register (GPIO15), offset 0x3C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO15_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO15_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO15_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO15_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO15_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO15_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO15_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO15_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO15_REG;



/**
 *  @brief  Union type to access the GPIO16 Pin Control Register (GPIO16), offset 0x40.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO16_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO16_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO16_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO16_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO16_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO16_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO16_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO16_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO16_REG;



/**
 *  @brief  Union type to access the GPIO17 Pin Control Register (GPIO17), offset 0x44.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO17_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO17_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO17_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO17_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO17_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO17_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO17_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO17_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO17_REG;



/**
 *  @brief  Union type to access the GPIO18 Pin Control Register (GPIO18), offset 0x48.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO18_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO18_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO18_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO18_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO18_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO18_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO18_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO18_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO18_REG;



/**
 *  @brief  Union type to access the GPIO19 Pin Control Register (GPIO19), offset 0x4C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO19_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO19_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO19_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO19_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO19_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO19_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO19_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO19_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO19_REG;



/**
 *  @brief  Union type to access the GPIO20 Pin Control Register (GPIO20), offset 0x50.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO20_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO20_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO20_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO20_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO20_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO20_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO20_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO20_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO20_REG;



/**
 *  @brief  Union type to access the GPIO21 Pin Control Register (GPIO21), offset 0x54.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO21_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO21_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO21_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO21_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO21_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO21_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO21_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO21_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO21_REG;



/**
 *  @brief  Union type to access the GPIO22 Pin Control Register (GPIO22), offset 0x58.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO22_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO22_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO22_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO22_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO22_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO22_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO22_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO22_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO22_REG;



/**
 *  @brief  Union type to access the GPIO23 Pin Control Register (GPIO23), offset 0x5C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO23_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO23_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO23_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO23_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO23_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO23_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO23_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO23_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO23_REG;



/**
 *  @brief  Union type to access the GPIO24 Pin Control Register (GPIO24), offset 0x60.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO24_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO24_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO24_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO24_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO24_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO24_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO24_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO24_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO24_REG;



/**
 *  @brief  Union type to access the GPIO25 Pin Control Register (GPIO25), offset 0x64.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO25_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO25_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO25_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO25_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO25_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO25_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO25_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO25_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO25_REG;



/**
 *  @brief  Union type to access the GPIO26 Pin Control Register (GPIO26), offset 0x68.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO26_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO26_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO26_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO26_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO26_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO26_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO26_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO26_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO26_REG;



/**
 *  @brief  Union type to access the GPIO27 Pin Control Register (GPIO27), offset 0x6C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO27_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO27_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO27_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO27_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO27_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO27_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO27_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO27_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO27_REG;



/**
 *  @brief  Union type to access the GPIO28 Pin Control Register (GPIO28), offset 0x70.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO28_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO28_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO28_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO28_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO28_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO28_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO28_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO28_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO28_REG;



/**
 *  @brief  Union type to access the GPIO29 Pin Control Register (GPIO29), offset 0x74.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO29_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO29_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO29_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO29_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO29_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO29_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO29_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO29_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO29_REG;



/**
 *  @brief  Union type to access the GPIO30 Pin Control Register (GPIO30), offset 0x78.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO30_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO30_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO30_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO30_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO30_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO30_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO30_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO30_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO30_REG;



/**
 *  @brief  Union type to access the GPIO31 Pin Control Register (GPIO31), offset 0x7C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO31_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO31_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO31_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO31_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO31_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO31_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO31_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO31_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO31_REG;



/**
 *  @brief  Union type to access the GPIO32 Pin Control Register (GPIO32), offset 0x80.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO32_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO32_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO32_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO32_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO32_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO32_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO32_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO32_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO32_REG;



/**
 *  @brief  Union type to access the GPIO33 Pin Control Register (GPIO33), offset 0x84.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO33_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO33_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO33_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO33_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO33_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO33_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO33_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO33_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO33_REG;



/**
 *  @brief  Union type to access the GPIO34 Pin Control Register (GPIO34), offset 0x88.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO34_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO34_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO34_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO34_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO34_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO34_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO34_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO34_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO34_REG;



/**
 *  @brief  Union type to access the GPIO35 Pin Control Register (GPIO35), offset 0x8C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO35_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO35_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO35_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO35_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO35_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO35_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO35_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO35_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO35_REG;



/**
 *  @brief  Union type to access the GPIO36 Pin Control Register (GPIO36), offset 0x90.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO36_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO36_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO36_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO36_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO36_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO36_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO36_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO36_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO36_REG;



/**
 *  @brief  Union type to access the GPIO37 Pin Control Register (GPIO37), offset 0x94.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO37_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO37_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO37_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO37_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO37_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO37_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO37_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO37_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO37_REG;



/**
 *  @brief  Union type to access the GPIO38 Pin Control Register (GPIO38), offset 0x98.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO38_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO38_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO38_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO38_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO38_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO38_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO38_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO38_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO38_REG;



/**
 *  @brief  Union type to access the GPIO39 Pin Control Register (GPIO39), offset 0x9C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO39_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO39_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO39_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO39_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO39_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO39_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO39_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO39_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO39_REG;



/**
 *  @brief  Union type to access the GPIO40 Pin Control Register (GPIO40), offset 0xA0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO40_BIT_MUXSEL      */
        uint32_t IE            : 1;  /*!< bit:      3  GPIO40_BIT_IE          */
        uint32_t SMT           : 1;  /*!< bit:      4  GPIO40_BIT_SMT         */
        uint32_t DEGLITCH      : 1;  /*!< bit:      5  GPIO40_BIT_DEGLITCH    */
        uint32_t STRENGTH      : 2;  /*!< bit:  7.. 6  GPIO40_BIT_STRENGTH    */
        uint32_t CHDFLTVAL     : 8;  /*!< bit: 15.. 8  GPIO40_BIT_CHDFLTVAL   */
        uint32_t PD            : 8;  /*!< bit: 23..16  GPIO40_BIT_PD          */
        uint32_t PU            : 8;  /*!< bit: 31..24  GPIO40_BIT_PU          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO40_REG;



/**
 *  @brief  Union type to access the PINMUX  Register Write-Allow Key Register (PINMUXREGKEY), offset 0xA4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t KEY           :32;  /*!< bit: 31.. 0  PINMUXREGKEY_BIT_KEY   */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PINMUXREGKEY_REG;



/**
  *  @brief  Structure type to access the PINMUX Controller (PINMUX).
  */
typedef struct
{
    __IO GPIO0_REG            GPIO0                 ; /*!< Offset: 0x00000000 (RW  )  GPIO0 Pin Control Register                 */
    __IO GPIO1_REG            GPIO1                 ; /*!< Offset: 0x00000004 (RW  )  GPIO1 Pin Control Register                 */
    __IO GPIO2_REG            GPIO2                 ; /*!< Offset: 0x00000008 (RW  )  GPIO2 Pin Control Register                 */
    __IO GPIO3_REG            GPIO3                 ; /*!< Offset: 0x0000000C (RW  )  GPIO3 Pin Control Register                 */
    __IO GPIO4_REG            GPIO4                 ; /*!< Offset: 0x00000010 (RW  )  GPIO4 Pin Control Register                 */
    __IO GPIO5_REG            GPIO5                 ; /*!< Offset: 0x00000014 (RW  )  GPIO5 Pin Control Register                 */
    __IO GPIO6_REG            GPIO6                 ; /*!< Offset: 0x00000018 (RW  )  GPIO6 Pin Control Register                 */
    __IO GPIO7_REG            GPIO7                 ; /*!< Offset: 0x0000001C (RW  )  GPIO7 Pin Control Register                 */
    __IO GPIO8_REG            GPIO8                 ; /*!< Offset: 0x00000020 (RW  )  GPIO8 Pin Control Register                 */
    __IO GPIO9_REG            GPIO9                 ; /*!< Offset: 0x00000024 (RW  )  GPIO9 Pin Control Register                 */
    __IO GPIO10_REG           GPIO10                ; /*!< Offset: 0x00000028 (RW  )  GPIO10 Pin Control Register                */
    __IO GPIO11_REG           GPIO11                ; /*!< Offset: 0x0000002C (RW  )  GPIO11 Pin Control Register                */
    __IO GPIO12_REG           GPIO12                ; /*!< Offset: 0x00000030 (RW  )  GPIO12 Pin Control Register                */
    __IO GPIO13_REG           GPIO13                ; /*!< Offset: 0x00000034 (RW  )  GPIO13 Pin Control Register                */
    __IO GPIO14_REG           GPIO14                ; /*!< Offset: 0x00000038 (RW  )  GPIO14 Pin Control Register                */
    __IO GPIO15_REG           GPIO15                ; /*!< Offset: 0x0000003C (RW  )  GPIO15 Pin Control Register                */
    __IO GPIO16_REG           GPIO16                ; /*!< Offset: 0x00000040 (RW  )  GPIO16 Pin Control Register                */
    __IO GPIO17_REG           GPIO17                ; /*!< Offset: 0x00000044 (RW  )  GPIO17 Pin Control Register                */
    __IO GPIO18_REG           GPIO18                ; /*!< Offset: 0x00000048 (RW  )  GPIO18 Pin Control Register                */
    __IO GPIO19_REG           GPIO19                ; /*!< Offset: 0x0000004C (RW  )  GPIO19 Pin Control Register                */
    __IO GPIO20_REG           GPIO20                ; /*!< Offset: 0x00000050 (RW  )  GPIO20 Pin Control Register                */
    __IO GPIO21_REG           GPIO21                ; /*!< Offset: 0x00000054 (RW  )  GPIO21 Pin Control Register                */
    __IO GPIO22_REG           GPIO22                ; /*!< Offset: 0x00000058 (RW  )  GPIO22 Pin Control Register                */
    __IO GPIO23_REG           GPIO23                ; /*!< Offset: 0x0000005C (RW  )  GPIO23 Pin Control Register                */
    __IO GPIO24_REG           GPIO24                ; /*!< Offset: 0x00000060 (RW  )  GPIO24 Pin Control Register                */
    __IO GPIO25_REG           GPIO25                ; /*!< Offset: 0x00000064 (RW  )  GPIO25 Pin Control Register                */
    __IO GPIO26_REG           GPIO26                ; /*!< Offset: 0x00000068 (RW  )  GPIO26 Pin Control Register                */
    __IO GPIO27_REG           GPIO27                ; /*!< Offset: 0x0000006C (RW  )  GPIO27 Pin Control Register                */
    __IO GPIO28_REG           GPIO28                ; /*!< Offset: 0x00000070 (RW  )  GPIO28 Pin Control Register                */
    __IO GPIO29_REG           GPIO29                ; /*!< Offset: 0x00000074 (RW  )  GPIO29 Pin Control Register                */
    __IO GPIO30_REG           GPIO30                ; /*!< Offset: 0x00000078 (RW  )  GPIO30 Pin Control Register                */
    __IO GPIO31_REG           GPIO31                ; /*!< Offset: 0x0000007C (RW  )  GPIO31 Pin Control Register                */
    __IO GPIO32_REG           GPIO32                ; /*!< Offset: 0x00000080 (RW  )  GPIO32 Pin Control Register                */
    __IO GPIO33_REG           GPIO33                ; /*!< Offset: 0x00000084 (RW  )  GPIO33 Pin Control Register                */
    __IO GPIO34_REG           GPIO34                ; /*!< Offset: 0x00000088 (RW  )  GPIO34 Pin Control Register                */
    __IO GPIO35_REG           GPIO35                ; /*!< Offset: 0x0000008C (RW  )  GPIO35 Pin Control Register                */
    __IO GPIO36_REG           GPIO36                ; /*!< Offset: 0x00000090 (RW  )  GPIO36 Pin Control Register                */
    __IO GPIO37_REG           GPIO37                ; /*!< Offset: 0x00000094 (RW  )  GPIO37 Pin Control Register                */
    __IO GPIO38_REG           GPIO38                ; /*!< Offset: 0x00000098 (RW  )  GPIO38 Pin Control Register                */
    __IO GPIO39_REG           GPIO39                ; /*!< Offset: 0x0000009C (RW  )  GPIO39 Pin Control Register                */
    __IO GPIO40_REG           GPIO40                ; /*!< Offset: 0x000000A0 (RW  )  GPIO40 Pin Control Register                */
    __IO PINMUXREGKEY_REG     PINMUXREGKEY          ; /*!< Offset: 0x000000A4 (RW  )  PINMUX  Register Write-Allow Key Register  */
} PINMUX_REGS;



/********************************************************************************
*
* Module Name     EPWR
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the ePower Module Filtered Trip-Zone Event Register (EPWRTZFLT), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label        */
        uint32_t EPWRTZ0       : 1;  /*!< bit:      0  EPWRTZFLT_BIT_EPWRTZ0   */
        uint32_t EPWRTZ1       : 1;  /*!< bit:      1  EPWRTZFLT_BIT_EPWRTZ1   */
        uint32_t RESERVED_31_2 :30;  /*!< bit: 31.. 2                          */
    } bit;                           /*!< Structure used for bit  access       */
    uint32_t all;                    /*!< Type      used for word access       */
} EPWRTZFLT_REG;



/**
 *  @brief  Union type to access the ePower Module Latched Trip-Zone Status Register (EPWRTZSTS), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label        */
        uint32_t EPWRTZ0       : 1;  /*!< bit:      0  EPWRTZSTS_BIT_EPWRTZ0   */
        uint32_t EPWRTZ1       : 1;  /*!< bit:      1  EPWRTZSTS_BIT_EPWRTZ1   */
        uint32_t RESERVED_31_2 :30;  /*!< bit: 31.. 2                          */
    } bit;                           /*!< Structure used for bit  access       */
    uint32_t all;                    /*!< Type      used for word access       */
} EPWRTZSTS_REG;



/**
 *  @brief  Union type to access the ePower Module Latched Trip-Zone Status Clear Register (EPWRTZCLR), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label        */
        uint32_t EPWRTZ0       : 1;  /*!< bit:      0  EPWRTZCLR_BIT_EPWRTZ0   */
        uint32_t EPWRTZ1       : 1;  /*!< bit:      1  EPWRTZCLR_BIT_EPWRTZ1   */
        uint32_t RESERVED_31_2 :30;  /*!< bit: 31.. 2                          */
    } bit;                           /*!< Structure used for bit  access       */
    uint32_t all;                    /*!< Type      used for word access       */
} EPWRTZCLR_REG;



/**
 *  @brief  Union type to access the ePower Module Trip-Zone Event 0 Control Register (EPWRTZ0CTL), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label        */
        uint32_t SEL4PWM       : 3;  /*!< bit:  2.. 0  EPWRTZ0CTL_BIT_SEL4PWM  */
        uint32_t POL4PWM       : 1;  /*!< bit:      3  EPWRTZ0CTL_BIT_POL4PWM  */
        uint32_t SEL4GPIO      : 3;  /*!< bit:  6.. 4  EPWRTZ0CTL_BIT_SEL4GPIO */
        uint32_t POL4GPIO      : 1;  /*!< bit:      7  EPWRTZ0CTL_BIT_POL4GPIO */
        uint32_t IE            : 1;  /*!< bit:      8  EPWRTZ0CTL_BIT_IE       */
        uint32_t INPOL         : 1;  /*!< bit:      9  EPWRTZ0CTL_BIT_INPOL    */
        uint32_t SYNCCLREN     : 1;  /*!< bit:     10  EPWRTZ0CTL_BIT_SYNCCLREN*/
        uint32_t FLTDIV        :10;  /*!< bit: 20..11  EPWRTZ0CTL_BIT_FLTDIV   */
        uint32_t FLTWIN        : 5;  /*!< bit: 25..21  EPWRTZ0CTL_BIT_FLTWIN   */
        uint32_t FLTTH         : 5;  /*!< bit: 30..26  EPWRTZ0CTL_BIT_FLTTH    */
        uint32_t FLTRST        : 1;  /*!< bit:     31  EPWRTZ0CTL_BIT_FLTRST   */
    } bit;                           /*!< Structure used for bit  access       */
    uint32_t all;                    /*!< Type      used for word access       */
} EPWRTZ0CTL_REG;



/**
 *  @brief  Union type to access the ePower Module Trip-Zone Event 1 Control Register (EPWRTZ1CTL), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label        */
        uint32_t SEL4PWM       : 3;  /*!< bit:  2.. 0  EPWRTZ1CTL_BIT_SEL4PWM  */
        uint32_t POL4PWM       : 1;  /*!< bit:      3  EPWRTZ1CTL_BIT_POL4PWM  */
        uint32_t SEL4GPIO      : 3;  /*!< bit:  6.. 4  EPWRTZ1CTL_BIT_SEL4GPIO */
        uint32_t POL4GPIO      : 1;  /*!< bit:      7  EPWRTZ1CTL_BIT_POL4GPIO */
        uint32_t IE            : 1;  /*!< bit:      8  EPWRTZ1CTL_BIT_IE       */
        uint32_t INPOL         : 1;  /*!< bit:      9  EPWRTZ1CTL_BIT_INPOL    */
        uint32_t SYNCCLREN     : 1;  /*!< bit:     10  EPWRTZ1CTL_BIT_SYNCCLREN*/
        uint32_t FLTDIV        :10;  /*!< bit: 20..11  EPWRTZ1CTL_BIT_FLTDIV   */
        uint32_t FLTWIN        : 5;  /*!< bit: 25..21  EPWRTZ1CTL_BIT_FLTWIN   */
        uint32_t FLTTH         : 5;  /*!< bit: 30..26  EPWRTZ1CTL_BIT_FLTTH    */
        uint32_t FLTRST        : 1;  /*!< bit:     31  EPWRTZ1CTL_BIT_FLTRST   */
    } bit;                           /*!< Structure used for bit  access       */
    uint32_t all;                    /*!< Type      used for word access       */
} EPWRTZ1CTL_REG;



/**
 *  @brief  Union type to access the ePower Module Control Register (EPWRCTL), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label        */
        uint32_t EN            : 1;  /*!< bit:      0  EPWRCTL_BIT_EN          */
        uint32_t ENSPI         : 1;  /*!< bit:      1  EPWRCTL_BIT_ENSPI       */
        uint32_t SPIDIR        : 1;  /*!< bit:      2  EPWRCTL_BIT_SPIDIR      */
        uint32_t SYNCSEL0      : 3;  /*!< bit:  5.. 3  EPWRCTL_BIT_SYNCSEL0    */
        uint32_t SYNCSEL1      : 3;  /*!< bit:  8.. 6  EPWRCTL_BIT_SYNCSEL1    */
        uint32_t TZSEL4GPIO11  : 1;  /*!< bit:      9  EPWRCTL_BIT_TZSEL4GPIO11*/
        uint32_t RESERVED_31_10:22;  /*!< bit: 31..10                          */
    } bit;                           /*!< Structure used for bit  access       */
    uint32_t all;                    /*!< Type      used for word access       */
} EPWRCTL_REG;



/**
 *  @brief  Union type to access the ePower Module Register Write-Allow Key Register (EPWRREGKEY), offset 0x18.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label        */
        uint32_t KEY           :32;  /*!< bit: 31.. 0  EPWRREGKEY_BIT_KEY      */
    } bit;                           /*!< Structure used for bit  access       */
    uint32_t all;                    /*!< Type      used for word access       */
} EPWRREGKEY_REG;



/**
  *  @brief  Structure type to access the EPWR Controller (EPWR).
  */
typedef struct
{
    __I  EPWRTZFLT_REG      EPWRTZFLT           ; /*!< Offset: 0x00000000 (RO  )  ePower Module Filtered Trip-Zone Event Register        */
    __I  EPWRTZSTS_REG      EPWRTZSTS           ; /*!< Offset: 0x00000004 (RO  )  ePower Module Latched Trip-Zone Status Register        */
    __O  EPWRTZCLR_REG      EPWRTZCLR           ; /*!< Offset: 0x00000008 (WO  )  ePower Module Latched Trip-Zone Status Clear Register  */
    __IO EPWRTZ0CTL_REG     EPWRTZ0CTL          ; /*!< Offset: 0x0000000C (RW  )  ePower Module Trip-Zone Event 0 Control Register       */
    __IO EPWRTZ1CTL_REG     EPWRTZ1CTL          ; /*!< Offset: 0x00000010 (RW  )  ePower Module Trip-Zone Event 1 Control Register       */
    __IO EPWRCTL_REG        EPWRCTL             ; /*!< Offset: 0x00000014 (RW  )  ePower Module Control Register                         */
    __IO EPWRREGKEY_REG     EPWRREGKEY          ; /*!< Offset: 0x00000018 (RW  )  ePower Module Register Write-Allow Key Register        */
} EPWR_REGS;



/********************************************************************************
*
* Module Name     ENGR
*
*
********************************************************************************/



/**
  *  @brief  Structure type to access the ENGR Controller (ENGR).
  */
typedef struct
{
         uint32_t           RESERVED0           ; 
         uint32_t           RESERVED1           ; 
         uint32_t           RESERVED2           ; 
         uint32_t           RESERVED3           ; 
         uint32_t           RESERVED4           ; 
         uint32_t           RESERVED5           ; 
         uint32_t           RESERVED6           ; 
         uint32_t           RESERVED7           ; 
         uint32_t           RESERVED8           ; 
         uint32_t           RESERVED9           ; 
         uint32_t           RESERVED10          ; 
         uint32_t           RESERVED11          ; 
         uint32_t           RESERVED12          ; 
         uint32_t           RESERVED13          ; 
         uint32_t           RESERVED14          ; 
         uint32_t           RESERVED15          ; 
         uint32_t           RESERVED16          ; 
         uint32_t           RESERVED17          ; 
         uint32_t           RESERVED18          ; 
         uint32_t           RESERVED19          ; 
         uint32_t           RESERVED20          ; 
} ENGR_REGS;



/********************************************************************************
*
* Module Name     WDT
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the Watchdog Timer Load Register (WDTLOAD), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  WDTLOAD_BIT_VAL        */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} WDTLOAD_REG;



/**
 *  @brief  Union type to access the Watchdog Timer Current Value Register (WDTCNT), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  WDTCNT_BIT_VAL         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} WDTCNT_REG;



/**
 *  @brief  Union type to access the Watchdog Timer Control Register (WDTCTL), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t INTEN         : 1;  /*!< bit:      0  WDTCTL_BIT_INTEN       */
        uint32_t RSTEN         : 1;  /*!< bit:      1  WDTCTL_BIT_RSTEN       */
        uint32_t HALTEDRUN     : 1;  /*!< bit:      2  WDTCTL_BIT_HALTEDRUN   */
        uint32_t LOCKUPRUN     : 1;  /*!< bit:      3  WDTCTL_BIT_LOCKUPRUN   */
        uint32_t RESERVED_31_4 :28;  /*!< bit: 31.. 4                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} WDTCTL_REG;



/**
 *  @brief  Union type to access the Watchdog Timer Clear Interrupt Register  (WDTIC), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  WDTIC_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} WDTIC_REG;



/**
 *  @brief  Union type to access the Watchdog Timer Raw Interrupt Status Register (WDTRAWIF), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t RAWINT        : 1;  /*!< bit:      0  WDTRAWIF_BIT_RAWINT    */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} WDTRAWIF_REG;



/**
 *  @brief  Union type to access the Watchdog Timer Interrupt Status Register (WDTIF), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t INT           : 1;  /*!< bit:      0  WDTIF_BIT_INT          */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} WDTIF_REG;



/**
 *  @brief  Union type to access the Watchdog Timer Lock Register (WDTREGKEY), offset 0x18.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t LCKSTS        : 1;  /*!< bit:      0  WDTREGKEY_BIT_LCKSTS   */
        uint32_t LCKCTL        :31;  /*!< bit: 31.. 1  WDTREGKEY_BIT_LCKCTL   */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} WDTREGKEY_REG;



/**
  *  @brief  Structure type to access the WDT Controller (WDT).
  */
typedef struct
{
    __IO WDTLOAD_REG       WDTLOAD            ; /*!< Offset: 0x00000000 (RW  )  Watchdog Timer Load Register                  */
    __I  WDTCNT_REG        WDTCNT             ; /*!< Offset: 0x00000004 (RO  )  Watchdog Timer Current Value Register         */
    __IO WDTCTL_REG        WDTCTL             ; /*!< Offset: 0x00000008 (RW  )  Watchdog Timer Control Register               */
    __O  WDTIC_REG         WDTIC              ; /*!< Offset: 0x0000000C (WO  )  Watchdog Timer Clear Interrupt Register       */
    __I  WDTRAWIF_REG      WDTRAWIF           ; /*!< Offset: 0x00000010 (RO  )  Watchdog Timer Raw Interrupt Status Register  */
    __I  WDTIF_REG         WDTIF              ; /*!< Offset: 0x00000014 (RO  )  Watchdog Timer Interrupt Status Register      */
    __IO WDTREGKEY_REG     WDTREGKEY          ; /*!< Offset: 0x00000018 (RW  )  Watchdog Timer Lock Register                  */
} WDT_REGS;



/********************************************************************************
*
* Module Name     GPIO
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the GPIO Pin Level Register 0 (GPLR0), offset 0x0.
            Union type to access the GPIO Pin Level Register 1 (GPLR1), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GPLR0_BIT_VAL          
                                                       GPLR1_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPLRx_REG;



/**
 *  @brief  Union type to access the GPIO Pin Direction Register 0 (GPDR0), offset 0xC.
            Union type to access the GPIO Pin Direction Register 1 (GPDR1), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GPDR0_BIT_VAL          
                                                       GPDR1_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPDRx_REG;



/**
 *  @brief  Union type to access the GPIO Pin Output Set Register 0 (GSLR0), offset 0x18.
            Union type to access the GPIO Pin Output Set Register 1 (GSLR1), offset 0x1C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GSLR0_BIT_VAL          
                                                       GSLR1_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GSLRx_REG;



/**
 *  @brief  Union type to access the GPIO Pin Output Clear Register 0 (GCLR0), offset 0x24.
            Union type to access the GPIO Pin Output Clear Register 1 (GCLR1), offset 0x28.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GCLR0_BIT_VAL          
                                                       GCLR1_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GCLRx_REG;



/**
 *  @brief  Union type to access the GPIO Rising Edge Detect Enable Register 0 (GRER0), offset 0x30.
            Union type to access the GPIO Rising Edge Detect Enable Register 1 (GRER1), offset 0x34.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GRER0_BIT_VAL          
                                                       GRER1_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GRERx_REG;



/**
 *  @brief  Union type to access the GPIO Falling Edge Detect Enable Register 0 (GFER0), offset 0x3C.
            Union type to access the GPIO Falling Edge Detect Enable Register 1 (GFER1), offset 0x40.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GFER0_BIT_VAL          
                                                       GFER1_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GFERx_REG;



/**
 *  @brief  Union type to access the GPIO Edge Detect Status Register 0 (GEDR0), offset 0x48.
            Union type to access the GPIO Edge Detect Status Register 1 (GEDR1), offset 0x4C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GEDR0_BIT_VAL          
                                                       GEDR1_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GEDRx_REG;



/**
 *  @brief  Union type to access the GPIO Pin Bitwise Set Direction Register 0 (GSDR0), offset 0x54.
            Union type to access the GPIO Pin Bitwise Set Direction Register 1 (GSDR1), offset 0x58.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GSDR0_BIT_VAL          
                                                       GSDR1_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GSDRx_REG;



/**
 *  @brief  Union type to access the GPIO Pin Bitwise Clear Direction Register 0 (GCDR0), offset 0x60.
            Union type to access the GPIO Pin Bitwise Clear Direction Register 1 (GCDR1), offset 0x64.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GCDR0_BIT_VAL          
                                                       GCDR1_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GCDRx_REG;



/**
 *  @brief  Union type to access the GPIO Bitwise Set Rising Edge Detect Enable Register 0 (GSRER0), offset 0x6C.
            Union type to access the GPIO Bitwise Set Rising Edge Detect Enable Register 1 (GSRER1), offset 0x70.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GSRER0_BIT_VAL         
                                                       GSRER1_BIT_VAL         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GSRERx_REG;



/**
 *  @brief  Union type to access the GPIO Bitwise Clear Rising Edge Detect Enable Register 0 (GCRER0), offset 0x78.
            Union type to access the GPIO Bitwise Clear Rising Edge Detect Enable Register 1 (GCRER1), offset 0x7C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GCRER0_BIT_VAL         
                                                       GCRER1_BIT_VAL         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GCRERx_REG;



/**
 *  @brief  Union type to access the GPIO Bitwise Set Falling Edge Detect Enable Register 0 (GSFER0), offset 0x84.
            Union type to access the GPIO Bitwise Set Falling Edge Detect Enable Register 1 (GSFER1), offset 0x88.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GSFER0_BIT_VAL         
                                                       GSFER1_BIT_VAL         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GSFERx_REG;



/**
 *  @brief  Union type to access the GPIO Bitwise Clear Falling Edge Detect Enable Register 0 (GCFER0), offset 0x90.
            Union type to access the GPIO Bitwise Clear Falling Edge Detect Enable Register 1 (GCFER1), offset 0x94.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GCFER0_BIT_VAL         
                                                       GCFER1_BIT_VAL         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GCFERx_REG;



/**
 *  @brief  Union type to access the GPIO Edge-Triggered Interrupt Enable Register 0 (GEIE0), offset 0x9C.
            Union type to access the GPIO Edge-Triggered Interrupt Enable Register 1 (GEIE1), offset 0xA0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GEIE0_BIT_VAL          
                                                       GEIE1_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GEIEx_REG;



/**
 *  @brief  Union type to access the GPIO Level-Triggered Interrupt Flag Register 0 (GLIF0), offset 0xA8.
            Union type to access the GPIO Level-Triggered Interrupt Flag Register 1 (GLIF1), offset 0xAC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GLIF0_BIT_VAL          
                                                       GLIF1_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GLIFx_REG;



/**
 *  @brief  Union type to access the GPIO Level-Triggered Interrupt Enable Register 0 (GLIE0), offset 0xB4.
            Union type to access the GPIO Level-Triggered Interrupt Enable Register 1 (GLIE1), offset 0xB8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GLIE0_BIT_VAL          
                                                       GLIE1_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GLIEx_REG;



/**
 *  @brief  Union type to access the GPIO Level-Triggered Interrupt Clear Register 0 (GLIC0), offset 0xC0.
            Union type to access the GPIO Level-Triggered Interrupt Clear Register 1 (GLIC1), offset 0xC4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GLIC0_BIT_VAL          
                                                       GLIC1_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GLICx_REG;



/**
 *  @brief  Union type to access the GPIO Level-Triggered Interrupt Force Register 0 (GLIFRC0), offset 0xCC.
            Union type to access the GPIO Level-Triggered Interrupt Force Register 1 (GLIFRC1), offset 0xD0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GLIFRC0_BIT_VAL        
                                                       GLIFRC1_BIT_VAL        */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GLIFRCx_REG;



/**
 *  @brief  Union type to access the GPIO Level-Triggered Interrupt Polarity Register 0 (GLIPOL0), offset 0xD8.
            Union type to access the GPIO Level-Triggered Interrupt Polarity Register 1 (GLIPOL1), offset 0xDC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GLIPOL0_BIT_VAL        
                                                       GLIPOL1_BIT_VAL        */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GLIPOLx_REG;



/**
 *  @brief  Union type to access the GPIO Interrupt Flag Register (GIF), offset 0xE4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t EDGE          : 1;  /*!< bit:      0  GIF_BIT_EDGE           */
        uint32_t LEVEL         : 1;  /*!< bit:      1  GIF_BIT_LEVEL          */
        uint32_t RESERVED_31_2 :30;  /*!< bit: 31.. 2                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GIF_REG;



/**
 *  @brief  Union type to access the GPIO Interrupt Flag Clear Register (GIC), offset 0xE8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t EDGE          : 1;  /*!< bit:      0  GIC_BIT_EDGE           */
        uint32_t LEVEL         : 1;  /*!< bit:      1  GIC_BIT_LEVEL          */
        uint32_t RESERVED_31_2 :30;  /*!< bit: 31.. 2                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GIC_REG;



/**
 *  @brief  Union type to access the GPIO Register Write-Allow Key Register (GPIOREGKEY), offset 0xEC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t KEY           :32;  /*!< bit: 31.. 0  GPIOREGKEY_BIT_KEY     */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIOREGKEY_REG;



/**
  *  @brief  Structure type to access the GPIO Controller (GPIO).
  */
typedef struct
{
    __IO GPLRx_REG          GPLR[2]             ; /*!< Offset: 0x00000000 (RW  )  GPIO Pin Level Register 0                                 */
         uint32_t           RESERVED0           ; 
    __IO GPDRx_REG          GPDR[2]             ; /*!< Offset: 0x0000000C (RW  )  GPIO Pin Direction Register 0                             */
         uint32_t           RESERVED1           ; 
    __O  GSLRx_REG          GSLR[2]             ; /*!< Offset: 0x00000018 (WO  )  GPIO Pin Output Set Register 0                            */
         uint32_t           RESERVED2           ; 
    __O  GCLRx_REG          GCLR[2]             ; /*!< Offset: 0x00000024 (WO  )  GPIO Pin Output Clear Register 0                          */
         uint32_t           RESERVED3           ; 
    __IO GRERx_REG          GRER[2]             ; /*!< Offset: 0x00000030 (RW  )  GPIO Rising Edge Detect Enable Register 0                 */
         uint32_t           RESERVED4           ; 
    __IO GFERx_REG          GFER[2]             ; /*!< Offset: 0x0000003C (RW  )  GPIO Falling Edge Detect Enable Register 0                */
         uint32_t           RESERVED5           ; 
    __O  GEDRx_REG          GEDR[2]             ; /*!< Offset: 0x00000048 (WO  )  GPIO Edge Detect Status Register 0                        */
         uint32_t           RESERVED6           ; 
    __O  GSDRx_REG          GSDR[2]             ; /*!< Offset: 0x00000054 (WO  )  GPIO Pin Bitwise Set Direction Register 0                 */
         uint32_t           RESERVED7           ; 
    __O  GCDRx_REG          GCDR[2]             ; /*!< Offset: 0x00000060 (WO  )  GPIO Pin Bitwise Clear Direction Register 0               */
         uint32_t           RESERVED8           ; 
    __O  GSRERx_REG         GSRER[2]            ; /*!< Offset: 0x0000006C (WO  )  GPIO Bitwise Set Rising Edge Detect Enable Register 0     */
         uint32_t           RESERVED9           ; 
    __O  GCRERx_REG         GCRER[2]            ; /*!< Offset: 0x00000078 (WO  )  GPIO Bitwise Clear Rising Edge Detect Enable Register 0   */
         uint32_t           RESERVED10          ; 
    __O  GSFERx_REG         GSFER[2]            ; /*!< Offset: 0x00000084 (WO  )  GPIO Bitwise Set Falling Edge Detect Enable Register 0    */
         uint32_t           RESERVED11          ; 
    __O  GCFERx_REG         GCFER[2]            ; /*!< Offset: 0x00000090 (WO  )  GPIO Bitwise Clear Falling Edge Detect Enable Register 0  */
         uint32_t           RESERVED12          ; 
    __IO GEIEx_REG          GEIE[2]             ; /*!< Offset: 0x0000009C (RW  )  GPIO Edge-Triggered Interrupt Enable Register 0           */
         uint32_t           RESERVED13          ; 
    __I  GLIFx_REG          GLIF[2]             ; /*!< Offset: 0x000000A8 (RO  )  GPIO Level-Triggered Interrupt Flag Register 0            */
         uint32_t           RESERVED14          ; 
    __IO GLIEx_REG          GLIE[2]             ; /*!< Offset: 0x000000B4 (RW  )  GPIO Level-Triggered Interrupt Enable Register 0          */
         uint32_t           RESERVED15          ; 
    __O  GLICx_REG          GLIC[2]             ; /*!< Offset: 0x000000C0 (WO  )  GPIO Level-Triggered Interrupt Clear Register 0           */
         uint32_t           RESERVED16          ; 
    __O  GLIFRCx_REG        GLIFRC[2]           ; /*!< Offset: 0x000000CC (WO  )  GPIO Level-Triggered Interrupt Force Register 0           */
         uint32_t           RESERVED17          ; 
    __IO GLIPOLx_REG        GLIPOL[2]           ; /*!< Offset: 0x000000D8 (RW  )  GPIO Level-Triggered Interrupt Polarity Register 0        */
         uint32_t           RESERVED18          ; 
    __I  GIF_REG            GIF                 ; /*!< Offset: 0x000000E4 (RO  )  GPIO Interrupt Flag Register                              */
    __O  GIC_REG            GIC                 ; /*!< Offset: 0x000000E8 (WO  )  GPIO Interrupt Flag Clear Register                        */
    __IO GPIOREGKEY_REG     GPIOREGKEY          ; /*!< Offset: 0x000000EC (RW  )  GPIO Register Write-Allow Key Register                    */
} GPIO_REGS;



/********************************************************************************
*
* Module Name     UART
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the UART Receive Buffer Register (UARTRBR), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  UARTRBR_BIT_VAL        */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTRBR_REG;



/**
 *  @brief  Union type to access the UART Transmit Holding Register (UARTTHR), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  UARTTHR_BIT_VAL        */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTTHR_REG;



/**
 *  @brief  Union type to access the UART Divisor Latch Low Byte Register (UARTDLL), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           : 8;  /*!< bit:  7.. 0  UARTDLL_BIT_VAL        */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTDLL_REG;



/**
 *  @brief  Union type to access the UART Divisor Latch High Byte Register (UARTDLH), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           : 8;  /*!< bit:  7.. 0  UARTDLH_BIT_VAL        */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTDLH_REG;



/**
 *  @brief  Union type to access the UART Interrupt Enable Register (UARTIER), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t RAVIE         : 1;  /*!< bit:      0  UARTIER_BIT_RAVIE      */
        uint32_t TIE           : 1;  /*!< bit:      1  UARTIER_BIT_TIE        */
        uint32_t RLSE          : 1;  /*!< bit:      2  UARTIER_BIT_RLSE       */
        uint32_t RESERVED_3_3  : 1;  /*!< bit:      3                         */
        uint32_t RTOIE         : 1;  /*!< bit:      4  UARTIER_BIT_RTOIE      */
        uint32_t NRZME         : 1;  /*!< bit:      5  UARTIER_BIT_NRZME      */
        uint32_t UUE           : 1;  /*!< bit:      6  UARTIER_BIT_UUE        */
        uint32_t RESERVED_7_7  : 1;  /*!< bit:      7                         */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTIER_REG;



/**
 *  @brief  Union type to access the UART Interrupt Identification Register (UARTIIR), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t NIP           : 1;  /*!< bit:      0  UARTIIR_BIT_NIP        */
        uint32_t IID           : 2;  /*!< bit:  2.. 1  UARTIIR_BIT_IID        */
        uint32_t TOD           : 1;  /*!< bit:      3  UARTIIR_BIT_TOD        */
        uint32_t ABL           : 1;  /*!< bit:      4  UARTIIR_BIT_ABL        */
        uint32_t RESERVED_5_5  : 1;  /*!< bit:      5                         */
        uint32_t FIFOSTS       : 2;  /*!< bit:  7.. 6  UARTIIR_BIT_FIFOSTS    */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTIIR_REG;



/**
 *  @brief  Union type to access the UART FIFO Control Register (UARTFCR), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t TRFIFOE       : 1;  /*!< bit:      0  UARTFCR_BIT_TRFIFOE    */
        uint32_t CLRRF         : 1;  /*!< bit:      1  UARTFCR_BIT_CLRRF      */
        uint32_t CLRTF         : 1;  /*!< bit:      2  UARTFCR_BIT_CLRTF      */
        uint32_t TXTH          : 1;  /*!< bit:      3  UARTFCR_BIT_TXTH       */
        uint32_t RESERVED_4_4  : 1;  /*!< bit:      4                         */
        uint32_t BUS32         : 1;  /*!< bit:      5  UARTFCR_BIT_BUS32      */
        uint32_t RXTH          : 2;  /*!< bit:  7.. 6  UARTFCR_BIT_RXTH       */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTFCR_REG;



/**
 *  @brief  Union type to access the UART Line Control Register (UARTLCR), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t WLS           : 2;  /*!< bit:  1.. 0  UARTLCR_BIT_WLS        */
        uint32_t STB           : 1;  /*!< bit:      2  UARTLCR_BIT_STB        */
        uint32_t PEN           : 1;  /*!< bit:      3  UARTLCR_BIT_PEN        */
        uint32_t EPS           : 1;  /*!< bit:      4  UARTLCR_BIT_EPS        */
        uint32_t STKYP         : 1;  /*!< bit:      5  UARTLCR_BIT_STKYP      */
        uint32_t SB            : 1;  /*!< bit:      6  UARTLCR_BIT_SB         */
        uint32_t DLAB          : 1;  /*!< bit:      7  UARTLCR_BIT_DLAB       */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTLCR_REG;



/**
 *  @brief  Union type to access the UART Modem Control Register (UARTMCR), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t RESERVED_0_0  : 1;  /*!< bit:      0                         */
        uint32_t RESERVED_1_1  : 1;  /*!< bit:      1                         */
        uint32_t RESERVED_2_2  : 1;  /*!< bit:      2                         */
        uint32_t GIE           : 1;  /*!< bit:      3  UARTMCR_BIT_GIE        */
        uint32_t RESERVED_4_4  : 1;  /*!< bit:      4                         */
        uint32_t RESERVED_5_5  : 1;  /*!< bit:      5                         */
        uint32_t RESERVED_31_6 :26;  /*!< bit: 31.. 6                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTMCR_REG;



/**
 *  @brief  Union type to access the UART Line Status Register (UARTLSR), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DR            : 1;  /*!< bit:      0  UARTLSR_BIT_DR         */
        uint32_t OE            : 1;  /*!< bit:      1  UARTLSR_BIT_OE         */
        uint32_t PE            : 1;  /*!< bit:      2  UARTLSR_BIT_PE         */
        uint32_t FE            : 1;  /*!< bit:      3  UARTLSR_BIT_FE         */
        uint32_t BI            : 1;  /*!< bit:      4  UARTLSR_BIT_BI         */
        uint32_t TDRQ          : 1;  /*!< bit:      5  UARTLSR_BIT_TDRQ       */
        uint32_t TXDONE        : 1;  /*!< bit:      6  UARTLSR_BIT_TXDONE     */
        uint32_t FIFOERR       : 1;  /*!< bit:      7  UARTLSR_BIT_FIFOERR    */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTLSR_REG;



/**
 *  @brief  Union type to access the UART Infrared Selection Register (UARTISR), offset 0x20.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t XMITIR        : 1;  /*!< bit:      0  UARTISR_BIT_XMITIR     */
        uint32_t RCVEIR        : 1;  /*!< bit:      1  UARTISR_BIT_RCVEIR     */
        uint32_t RESERVED_2_2  : 1;  /*!< bit:      2                         */
        uint32_t TXPL          : 1;  /*!< bit:      3  UARTISR_BIT_TXPL       */
        uint32_t RXPL          : 1;  /*!< bit:      4  UARTISR_BIT_RXPL       */
        uint32_t RESERVED_31_5 :27;  /*!< bit: 31.. 5                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTISR_REG;



/**
 *  @brief  Union type to access the UART Receive FIFO Occupancy Register (UARTFOR), offset 0x24.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t BYTECNT       : 6;  /*!< bit:  5.. 0  UARTFOR_BIT_BYTECNT    */
        uint32_t RESERVED_31_6 :26;  /*!< bit: 31.. 6                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTFOR_REG;



/**
 *  @brief  Union type to access the UART Auto-Baud Control Register (UARTABR), offset 0x28.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t ABE           : 1;  /*!< bit:      0  UARTABR_BIT_ABE        */
        uint32_t ABLIE         : 1;  /*!< bit:      1  UARTABR_BIT_ABLIE      */
        uint32_t ABUP          : 1;  /*!< bit:      2  UARTABR_BIT_ABUP       */
        uint32_t RESERVED_31_3 :29;  /*!< bit: 31.. 3                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTABR_REG;



/**
 *  @brief  Union type to access the UART Auto-Baud Count Register (UARTACR), offset 0x2C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t CNTVAL        :16;  /*!< bit: 15.. 0  UARTACR_BIT_CNTVAL     */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTACR_REG;



/**
  *  @brief  Structure type to access the UART Controller (UART).
  */
typedef struct
{
    union
    {
        __I  UARTRBR_REG     UARTRBR      ; /*!< Offset: 0x00000000 (RO  )  UART Receive Buffer Register            */
        __O  UARTTHR_REG     UARTTHR      ; /*!< Offset: 0x00000000 (WO  )  UART Transmit Holding Register          */
        __IO UARTDLL_REG     UARTDLL      ; /*!< Offset: 0x00000000 (RW  )  UART Divisor Latch Low Byte Register    */
    } UARTRBR_UARTTHR_UARTDLL;
    union
    {
        __IO UARTDLH_REG     UARTDLH      ; /*!< Offset: 0x00000004 (RW  )  UART Divisor Latch High Byte Register   */
        __IO UARTIER_REG     UARTIER      ; /*!< Offset: 0x00000004 (RW  )  UART Interrupt Enable Register          */
    } UARTDLH_UARTIER;
    union
    {
        __I  UARTIIR_REG     UARTIIR      ; /*!< Offset: 0x00000008 (RO  )  UART Interrupt Identification Register  */
        __O  UARTFCR_REG     UARTFCR      ; /*!< Offset: 0x00000008 (WO  )  UART FIFO Control Register              */
    } UARTIIR_UARTFCR;
    __IO UARTLCR_REG     UARTLCR          ; /*!< Offset: 0x0000000C (RW  )  UART Line Control Register              */
    __IO UARTMCR_REG     UARTMCR          ; /*!< Offset: 0x00000010 (RW  )  UART Modem Control Register             */
    __I  UARTLSR_REG     UARTLSR          ; /*!< Offset: 0x00000014 (RO  )  UART Line Status Register               */
         uint32_t        RESERVED0        ; 
         uint32_t        RESERVED1        ; 
    __IO UARTISR_REG     UARTISR          ; /*!< Offset: 0x00000020 (RW  )  UART Infrared Selection Register        */
    __I  UARTFOR_REG     UARTFOR          ; /*!< Offset: 0x00000024 (RO  )  UART Receive FIFO Occupancy Register    */
    __IO UARTABR_REG     UARTABR          ; /*!< Offset: 0x00000028 (RW  )  UART Auto-Baud Control Register         */
    __I  UARTACR_REG     UARTACR          ; /*!< Offset: 0x0000002C (RO  )  UART Auto-Baud Count Register           */
} UART_REGS;



/********************************************************************************
*
* Module Name     SSP
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the SSP Control Register 0 (SSPCTL0), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t SIZESEL       : 4;  /*!< bit:  3.. 0  SSPCTL0_BIT_SIZESEL    */
        uint32_t FRMSEL        : 2;  /*!< bit:  5.. 4  SSPCTL0_BIT_FRMSEL     */
        uint32_t RESERVED_6_6  : 1;  /*!< bit:      6                         */
        uint32_t EN            : 1;  /*!< bit:      7  SSPCTL0_BIT_EN         */
        uint32_t RESERVED_19_8 :12;  /*!< bit: 19.. 8                         */
        uint32_t ESIZESEL      : 1;  /*!< bit:     20  SSPCTL0_BIT_ESIZESEL   */
        uint32_t RESERVED_21_21: 1;  /*!< bit:     21                         */
        uint32_t RFINTMSK      : 1;  /*!< bit:     22  SSPCTL0_BIT_RFINTMSK   */
        uint32_t TFINTMSK      : 1;  /*!< bit:     23  SSPCTL0_BIT_TFINTMSK   */
        uint32_t RESERVED_26_24: 3;  /*!< bit: 26..24                         */
        uint32_t RESERVED_28_27: 2;  /*!< bit: 28..27                         */
        uint32_t FPACKEN       : 1;  /*!< bit:     29  SSPCTL0_BIT_FPACKEN    */
        uint32_t RESERVED_30_30: 1;  /*!< bit:     30                         */
        uint32_t RESERVED_31_31: 1;  /*!< bit:     31                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SSPCTL0_REG;



/**
 *  @brief  Union type to access the SSP Control Register 1 (SSPCTL1), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t RFIE          : 1;  /*!< bit:      0  SSPCTL1_BIT_RFIE       */
        uint32_t TFIE          : 1;  /*!< bit:      1  SSPCTL1_BIT_TFIE       */
        uint32_t RESERVED_2_2  : 1;  /*!< bit:      2                         */
        uint32_t CLKPOL        : 1;  /*!< bit:      3  SSPCTL1_BIT_CLKPOL     */
        uint32_t CLKPHS        : 1;  /*!< bit:      4  SSPCTL1_BIT_CLKPHS     */
        uint32_t RESERVED_5_5  : 1;  /*!< bit:      5                         */
        uint32_t TFTH          : 4;  /*!< bit:  9.. 6  SSPCTL1_BIT_TFTH       */
        uint32_t RFTH          : 4;  /*!< bit: 13..10  SSPCTL1_BIT_RFTH       */
        uint32_t RESERVED_14_14: 1;  /*!< bit:     14                         */
        uint32_t RESERVED_15_15: 1;  /*!< bit:     15                         */
        uint32_t FRMINV        : 1;  /*!< bit:     16  SSPCTL1_BIT_FRMINV     */
        uint32_t RESERVED_18_17: 2;  /*!< bit: 18..17                         */
        uint32_t RXTOIE        : 1;  /*!< bit:     19  SSPCTL1_BIT_RXTOIE     */
        uint32_t RESERVED_20_20: 1;  /*!< bit:     20                         */
        uint32_t RESERVED_21_21: 1;  /*!< bit:     21                         */
        uint32_t TRAIL         : 1;  /*!< bit:     22  SSPCTL1_BIT_TRAIL      */
        uint32_t RXONLY        : 1;  /*!< bit:     23  SSPCTL1_BIT_RXONLY     */
        uint32_t FRMDIR        : 1;  /*!< bit:     24  SSPCTL1_BIT_FRMDIR     */
        uint32_t CLKDIR        : 1;  /*!< bit:     25  SSPCTL1_BIT_CLKDIR     */
        uint32_t RESERVED_27_26: 2;  /*!< bit: 27..26                         */
        uint32_t SLVCLKSEL     : 1;  /*!< bit:     28  SSPCTL1_BIT_SLVCLKSEL  */
        uint32_t RESERVED_29_29: 1;  /*!< bit:     29                         */
        uint32_t TXTRIEN       : 1;  /*!< bit:     30  SSPCTL1_BIT_TXTRIEN    */
        uint32_t TXTRITIME     : 1;  /*!< bit:     31  SSPCTL1_BIT_TXTRITIME  */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SSPCTL1_REG;



/**
 *  @brief  Union type to access the SSP Status Register (SSPSTS), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t RESERVED_1_0  : 2;  /*!< bit:  1.. 0                         */
        uint32_t TNF           : 1;  /*!< bit:      2  SSPSTS_BIT_TNF         */
        uint32_t RNE           : 1;  /*!< bit:      3  SSPSTS_BIT_RNE         */
        uint32_t BUSY          : 1;  /*!< bit:      4  SSPSTS_BIT_BUSY        */
        uint32_t TFS           : 1;  /*!< bit:      5  SSPSTS_BIT_TFS         */
        uint32_t RFS           : 1;  /*!< bit:      6  SSPSTS_BIT_RFS         */
        uint32_t RFOVF         : 1;  /*!< bit:      7  SSPSTS_BIT_RFOVF       */
        uint32_t TFLVL         : 4;  /*!< bit: 11.. 8  SSPSTS_BIT_TFLVL       */
        uint32_t RFLVL         : 4;  /*!< bit: 15..12  SSPSTS_BIT_RFLVL       */
        uint32_t RESERVED_18_16: 3;  /*!< bit: 18..16                         */
        uint32_t RXTO          : 1;  /*!< bit:     19  SSPSTS_BIT_RXTO        */
        uint32_t RESERVED_20_20: 1;  /*!< bit:     20                         */
        uint32_t TFUDF         : 1;  /*!< bit:     21  SSPSTS_BIT_TFUDF       */
        uint32_t SLVCLKSTS     : 1;  /*!< bit:     22  SSPSTS_BIT_SLVCLKSTS   */
        uint32_t RESERVED_23_23: 1;  /*!< bit:     23                         */
        uint32_t RESERVED_29_24: 6;  /*!< bit: 29..24                         */
        uint32_t TFODDSTS      : 1;  /*!< bit:     30  SSPSTS_BIT_TFODDSTS    */
        uint32_t RFODDSTS      : 1;  /*!< bit:     31  SSPSTS_BIT_RFODDSTS    */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SSPSTS_REG;



/**
 *  @brief  Union type to access the SSP Interrupt Force Register (SSPFRC), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t RESERVED_4_0  : 5;  /*!< bit:  4.. 0                         */
        uint32_t TFREQ         : 1;  /*!< bit:      5  SSPFRC_BIT_TFREQ       */
        uint32_t RFREQ         : 1;  /*!< bit:      6  SSPFRC_BIT_RFREQ       */
        uint32_t RFOVF         : 1;  /*!< bit:      7  SSPFRC_BIT_RFOVF       */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SSPFRC_REG;



/**
 *  @brief  Union type to access the SSP Data Register (SSPDATA), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  SSPDATA_BIT_VAL        */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SSPDATA_REG;



/**
 *  @brief  Union type to access the SSP Time Out Register (SSPTO), offset 0x28.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :24;  /*!< bit: 23.. 0  SSPTO_BIT_VAL          */
        uint32_t RESERVED_31_24: 8;  /*!< bit: 31..24                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SSPTO_REG;



/**
  *  @brief  Structure type to access the SSP Controller (SSP).
  */
typedef struct
{
    __IO SSPCTL0_REG         SSPCTL0              ; /*!< Offset: 0x00000000 (RW  )  SSP Control Register 0                                        */
    __IO SSPCTL1_REG         SSPCTL1              ; /*!< Offset: 0x00000004 (RW  )  SSP Control Register 1                                        */
    __IO SSPSTS_REG          SSPSTS               ; /*!< Offset: 0x00000008 (RW  )  SSP Status Register                                           */
    __IO SSPFRC_REG          SSPFRC               ; /*!< Offset: 0x0000000C (RW  )  SSP Interrupt Force Register                                  */
    __IO SSPDATA_REG         SSPDATA              ; /*!< Offset: 0x00000010 (RW  )  SSP Data Register                                             */
         uint32_t            RESERVED0[5]         ; 
    __IO SSPTO_REG           SSPTO                ; /*!< Offset: 0x00000028 (RW  )  SSP Time Out Register                                         */
         uint32_t            RESERVED1            ; 
         uint32_t            RESERVED2            ; 
         uint32_t            RESERVED3            ; 
         uint32_t            RESERVED4            ; 
} SSP_REGS;



/********************************************************************************
*
* Module Name     I2C
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the I2C Control Register (I2CCTL), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t MASTER        : 1;  /*!< bit:      0  I2CCTL_BIT_MASTER             */
        uint32_t SPEED         : 2;  /*!< bit:  2.. 1  I2CCTL_BIT_SPEED              */
        uint32_t SLVADDR10B    : 1;  /*!< bit:      3  I2CCTL_BIT_SLVADDR10B         */
        uint32_t ADDRSTS       : 1;  /*!< bit:      4  I2CCTL_BIT_ADDRSTS            */
        uint32_t RESTARTEN     : 1;  /*!< bit:      5  I2CCTL_BIT_RESTARTEN          */
        uint32_t SLVDIS        : 1;  /*!< bit:      6  I2CCTL_BIT_SLVDIS             */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CCTL_REG;



/**
 *  @brief  Union type to access the I2C Master Address Register (I2CMASTERADDR), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t TARADDR       :10;  /*!< bit:  9.. 0  I2CMASTERADDR_BIT_TARADDR     */
        uint32_t GCORSTART     : 1;  /*!< bit:     10  I2CMASTERADDR_BIT_GCORSTART   */
        uint32_t SPECIAL       : 1;  /*!< bit:     11  I2CMASTERADDR_BIT_SPECIAL     */
        uint32_t MASTERADDR10B : 1;  /*!< bit:     12  I2CMASTERADDR_BIT_MASTERADDR10B*/
        uint32_t RESERVED_31_13:19;  /*!< bit: 31..13                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CMASTERADDR_REG;



/**
 *  @brief  Union type to access the I2C Slave Address Register (I2CSLVADDR), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           :10;  /*!< bit:  9.. 0  I2CSLVADDR_BIT_VAL            */
        uint32_t RESERVED_31_10:22;  /*!< bit: 31..10                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CSLVADDR_REG;



/**
 *  @brief  Union type to access the I2C High Speed Master Mode Code Address Register (I2CHSMADDR), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           : 3;  /*!< bit:  2.. 0  I2CHSMADDR_BIT_VAL            */
        uint32_t RESERVED_31_3 :29;  /*!< bit: 31.. 3                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CHSMADDR_REG;



/**
 *  @brief  Union type to access the I2C Data Buffer and Command Register (I2CDATACMD), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t DATA          : 8;  /*!< bit:  7.. 0  I2CDATACMD_BIT_DATA           */
        uint32_t CMD           : 1;  /*!< bit:      8  I2CDATACMD_BIT_CMD            */
        uint32_t RESERVED_31_9 :23;  /*!< bit: 31.. 9                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CDATACMD_REG;



/**
 *  @brief  Union type to access the Standard Speed I2C Clock SCL High Count Register (I2CSSHCNT), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  I2CSSHCNT_BIT_VAL             */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CSSHCNT_REG;



/**
 *  @brief  Union type to access the Standard Speed I2C Clock SCL Low Count Register (I2CSSLCNT), offset 0x18.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  I2CSSLCNT_BIT_VAL             */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CSSLCNT_REG;



/**
 *  @brief  Union type to access the Fast Speed I2C Clock SCL High Count Register (I2CFSHCNT), offset 0x1C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  I2CFSHCNT_BIT_VAL             */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CFSHCNT_REG;



/**
 *  @brief  Union type to access the Fast Speed I2C Clock SCL Low Count Register (I2CFSLCNT), offset 0x20.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  I2CFSLCNT_BIT_VAL             */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CFSLCNT_REG;



/**
 *  @brief  Union type to access the High Speed I2C Clock SCL High Count Register (I2CHSHCNT), offset 0x24.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  I2CHSHCNT_BIT_VAL             */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CHSHCNT_REG;



/**
 *  @brief  Union type to access the High Speed I2C Clock SCL Low Count Register (I2CHSLCNT), offset 0x28.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  I2CHSLCNT_BIT_VAL             */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CHSLCNT_REG;



/**
 *  @brief  Union type to access the I2C Interrupt Flag Register (I2CIF), offset 0x2C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t RXUDF         : 1;  /*!< bit:      0  I2CIF_BIT_RXUDF               */
        uint32_t RXOVF         : 1;  /*!< bit:      1  I2CIF_BIT_RXOVF               */
        uint32_t RXDAV         : 1;  /*!< bit:      2  I2CIF_BIT_RXDAV               */
        uint32_t TXOVF         : 1;  /*!< bit:      3  I2CIF_BIT_TXOVF               */
        uint32_t TXDREQ        : 1;  /*!< bit:      4  I2CIF_BIT_TXDREQ              */
        uint32_t RDREQ         : 1;  /*!< bit:      5  I2CIF_BIT_RDREQ               */
        uint32_t TXABRT        : 1;  /*!< bit:      6  I2CIF_BIT_TXABRT              */
        uint32_t RXDONE        : 1;  /*!< bit:      7  I2CIF_BIT_RXDONE              */
        uint32_t ACT           : 1;  /*!< bit:      8  I2CIF_BIT_ACT                 */
        uint32_t STOPDET       : 1;  /*!< bit:      9  I2CIF_BIT_STOPDET             */
        uint32_t STARTDET      : 1;  /*!< bit:     10  I2CIF_BIT_STARTDET            */
        uint32_t GENCALL       : 1;  /*!< bit:     11  I2CIF_BIT_GENCALL             */
        uint32_t RESERVED_31_12:20;  /*!< bit: 31..12                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CIF_REG;



/**
 *  @brief  Union type to access the I2C Interrupt Enable Register (I2CIE), offset 0x30.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t RXUDF         : 1;  /*!< bit:      0  I2CIE_BIT_RXUDF               */
        uint32_t RXOVF         : 1;  /*!< bit:      1  I2CIE_BIT_RXOVF               */
        uint32_t RXDAV         : 1;  /*!< bit:      2  I2CIE_BIT_RXDAV               */
        uint32_t TXOVF         : 1;  /*!< bit:      3  I2CIE_BIT_TXOVF               */
        uint32_t TXDREQ        : 1;  /*!< bit:      4  I2CIE_BIT_TXDREQ              */
        uint32_t RDREQ         : 1;  /*!< bit:      5  I2CIE_BIT_RDREQ               */
        uint32_t TXABRT        : 1;  /*!< bit:      6  I2CIE_BIT_TXABRT              */
        uint32_t RXDONE        : 1;  /*!< bit:      7  I2CIE_BIT_RXDONE              */
        uint32_t ACT           : 1;  /*!< bit:      8  I2CIE_BIT_ACT                 */
        uint32_t STOPDET       : 1;  /*!< bit:      9  I2CIE_BIT_STOPDET             */
        uint32_t STARTDET      : 1;  /*!< bit:     10  I2CIE_BIT_STARTDET            */
        uint32_t GENCALL       : 1;  /*!< bit:     11  I2CIE_BIT_GENCALL             */
        uint32_t RESERVED_31_12:20;  /*!< bit: 31..12                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CIE_REG;



/**
 *  @brief  Union type to access the I2C Raw Interrupt Flag Register (I2CRAWIF), offset 0x34.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t RXUDF         : 1;  /*!< bit:      0  I2CRAWIF_BIT_RXUDF            */
        uint32_t RXOVF         : 1;  /*!< bit:      1  I2CRAWIF_BIT_RXOVF            */
        uint32_t RXDAV         : 1;  /*!< bit:      2  I2CRAWIF_BIT_RXDAV            */
        uint32_t TXOVF         : 1;  /*!< bit:      3  I2CRAWIF_BIT_TXOVF            */
        uint32_t TXDREQ        : 1;  /*!< bit:      4  I2CRAWIF_BIT_TXDREQ           */
        uint32_t RDREQ         : 1;  /*!< bit:      5  I2CRAWIF_BIT_RDREQ            */
        uint32_t TXABRT        : 1;  /*!< bit:      6  I2CRAWIF_BIT_TXABRT           */
        uint32_t RXDONE        : 1;  /*!< bit:      7  I2CRAWIF_BIT_RXDONE           */
        uint32_t ACT           : 1;  /*!< bit:      8  I2CRAWIF_BIT_ACT              */
        uint32_t STOPDET       : 1;  /*!< bit:      9  I2CRAWIF_BIT_STOPDET          */
        uint32_t STARTDET      : 1;  /*!< bit:     10  I2CRAWIF_BIT_STARTDET         */
        uint32_t GENCALL       : 1;  /*!< bit:     11  I2CRAWIF_BIT_GENCALL          */
        uint32_t RESERVED_31_12:20;  /*!< bit: 31..12                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CRAWIF_REG;



/**
 *  @brief  Union type to access the I2C Receive FIFO Threshold Register (I2CRXTH), offset 0x38.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           : 4;  /*!< bit:  3.. 0  I2CRXTH_BIT_VAL               */
        uint32_t KEY           : 4;  /*!< bit:  7.. 4  I2CRXTH_BIT_KEY               */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CRXTH_REG;



/**
 *  @brief  Union type to access the I2C Transmit FIFO Threshold Register (I2CTXTH), offset 0x3C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           : 4;  /*!< bit:  3.. 0  I2CTXTH_BIT_VAL               */
        uint32_t KEY           : 4;  /*!< bit:  7.. 4  I2CTXTH_BIT_KEY               */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CTXTH_REG;



/**
 *  @brief  Union type to access the Clear Combined and Individual Interrupt Register (I2CINTCLR), offset 0x40.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t CLR           : 1;  /*!< bit:      0  I2CINTCLR_BIT_CLR             */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CINTCLR_REG;



/**
 *  @brief  Union type to access the Clear RXUDF Interrupt Register (I2CRXUDFCLR), offset 0x44.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t CLR           : 1;  /*!< bit:      0  I2CRXUDFCLR_BIT_CLR           */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CRXUDFCLR_REG;



/**
 *  @brief  Union type to access the Clear RXOVF Interrupt Register (I2CRXOVFCLR), offset 0x48.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t CLR           : 1;  /*!< bit:      0  I2CRXOVFCLR_BIT_CLR           */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CRXOVFCLR_REG;



/**
 *  @brief  Union type to access the Clear TXOVF Interrupt Register (I2CTXOVFCLR), offset 0x4C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t CLR           : 1;  /*!< bit:      0  I2CTXOVFCLR_BIT_CLR           */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CTXOVFCLR_REG;



/**
 *  @brief  Union type to access the Clear RDREQ Interrupt Register (I2CRDREQCLR), offset 0x50.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t CLR           : 1;  /*!< bit:      0  I2CRDREQCLR_BIT_CLR           */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CRDREQCLR_REG;



/**
 *  @brief  Union type to access the Clear TXABRT Interrupt Register (I2CTXABRTCLR), offset 0x54.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t CLR           : 1;  /*!< bit:      0  I2CTXABRTCLR_BIT_CLR          */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CTXABRTCLR_REG;



/**
 *  @brief  Union type to access the Clear RXDONE Interrupt Register (I2CRXDONECLR), offset 0x58.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t CLR           : 1;  /*!< bit:      0  I2CRXDONECLR_BIT_CLR          */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CRXDONECLR_REG;



/**
 *  @brief  Union type to access the Clear ACT Interrupt Register (I2CACTCLR), offset 0x5C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t CLR           : 1;  /*!< bit:      0  I2CACTCLR_BIT_CLR             */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CACTCLR_REG;



/**
 *  @brief  Union type to access the Clear STOPDET Interrupt Register (I2CSTOPDETCLR), offset 0x60.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t CLR           : 1;  /*!< bit:      0  I2CSTOPDETCLR_BIT_CLR         */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CSTOPDETCLR_REG;



/**
 *  @brief  Union type to access the Clear STARTDET Interrupt Register (I2CSTARTDETCLR), offset 0x64.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t CLR           : 1;  /*!< bit:      0  I2CSTARTDETCLR_BIT_CLR        */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CSTARTDETCLR_REG;



/**
 *  @brief  Union type to access the Clear GENCALL Interrupt Register (I2CGENCALLCLR), offset 0x68.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t CLR           : 1;  /*!< bit:      0  I2CGENCALLCLR_BIT_CLR         */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CGENCALLCLR_REG;



/**
 *  @brief  Union type to access the I2C Enable Register (I2CENABLE), offset 0x6C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t EN            : 1;  /*!< bit:      0  I2CENABLE_BIT_EN              */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CENABLE_REG;



/**
 *  @brief  Union type to access the I2C Status Register (I2CSTS), offset 0x70.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t ACT           : 1;  /*!< bit:      0  I2CSTS_BIT_ACT                */
        uint32_t TFNF          : 1;  /*!< bit:      1  I2CSTS_BIT_TFNF               */
        uint32_t TFE           : 1;  /*!< bit:      2  I2CSTS_BIT_TFE                */
        uint32_t RFNE          : 1;  /*!< bit:      3  I2CSTS_BIT_RFNE               */
        uint32_t RFF           : 1;  /*!< bit:      4  I2CSTS_BIT_RFF                */
        uint32_t MACT          : 1;  /*!< bit:      5  I2CSTS_BIT_MACT               */
        uint32_t SACT          : 1;  /*!< bit:      6  I2CSTS_BIT_SACT               */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CSTS_REG;



/**
 *  @brief  Union type to access the I2C Transmit FIFO Level Register (I2CTFLVL), offset 0x74.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           : 5;  /*!< bit:  4.. 0  I2CTFLVL_BIT_VAL              */
        uint32_t RESERVED_31_5 :27;  /*!< bit: 31.. 5                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CTFLVL_REG;



/**
 *  @brief  Union type to access the I2C Receive FIFO Level Register (I2CRFLVL), offset 0x78.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           : 5;  /*!< bit:  4.. 0  I2CRFLVL_BIT_VAL              */
        uint32_t RESERVED_31_5 :27;  /*!< bit: 31.. 5                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CRFLVL_REG;



/**
 *  @brief  Union type to access the I2C SDA Hold-Time Register (I2CSDAHOLD), offset 0x7C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  I2CSDAHOLD_BIT_VAL            */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CSDAHOLD_REG;



/**
 *  @brief  Union type to access the I2C Transmit Abort Source Register (I2CTXABRTSRC), offset 0x80.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t ADDR7BNACK    : 1;  /*!< bit:      0  I2CTXABRTSRC_BIT_ADDR7BNACK   */
        uint32_t ADDR10B1NACK  : 1;  /*!< bit:      1  I2CTXABRTSRC_BIT_ADDR10B1NACK */
        uint32_t ADDR10B2NACK  : 1;  /*!< bit:      2  I2CTXABRTSRC_BIT_ADDR10B2NACK */
        uint32_t TXDATANACK    : 1;  /*!< bit:      3  I2CTXABRTSRC_BIT_TXDATANACK   */
        uint32_t GCNACK        : 1;  /*!< bit:      4  I2CTXABRTSRC_BIT_GCNACK       */
        uint32_t GCREAD        : 1;  /*!< bit:      5  I2CTXABRTSRC_BIT_GCREAD       */
        uint32_t HSACKDET      : 1;  /*!< bit:      6  I2CTXABRTSRC_BIT_HSACKDET     */
        uint32_t STARTACKDET   : 1;  /*!< bit:      7  I2CTXABRTSRC_BIT_STARTACKDET  */
        uint32_t HSNORESTART   : 1;  /*!< bit:      8  I2CTXABRTSRC_BIT_HSNORESTART  */
        uint32_t STARTNORESTART: 1;  /*!< bit:      9  I2CTXABRTSRC_BIT_STARTNORESTART*/
        uint32_t RD10BNORESTART: 1;  /*!< bit:     10  I2CTXABRTSRC_BIT_RD10BNORESTART*/
        uint32_t MASTERDIS     : 1;  /*!< bit:     11  I2CTXABRTSRC_BIT_MASTERDIS    */
        uint32_t MARBLOST      : 1;  /*!< bit:     12  I2CTXABRTSRC_BIT_MARBLOST     */
        uint32_t SLVFLUSHTF    : 1;  /*!< bit:     13  I2CTXABRTSRC_BIT_SLVFLUSHTF   */
        uint32_t SARBLOST      : 1;  /*!< bit:     14  I2CTXABRTSRC_BIT_SARBLOST     */
        uint32_t SLVRDINTX     : 1;  /*!< bit:     15  I2CTXABRTSRC_BIT_SLVRDINTX    */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CTXABRTSRC_REG;



/**
 *  @brief  Union type to access the I2C SDA Setup Register (I2CSDASETUP), offset 0x94.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           : 8;  /*!< bit:  7.. 0  I2CSDASETUP_BIT_VAL           */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CSDASETUP_REG;



/**
 *  @brief  Union type to access the I2C ACK General Call Register (I2CACKGC), offset 0x98.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t ACKGC         : 1;  /*!< bit:      0  I2CACKGC_BIT_ACKGC            */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CACKGC_REG;



/**
 *  @brief  Union type to access the I2C Enable Status Register (I2CENSTS), offset 0x9C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t EN            : 1;  /*!< bit:      0  I2CENSTS_BIT_EN               */
        uint32_t SLVDISONBUSY  : 1;  /*!< bit:      1  I2CENSTS_BIT_SLVDISONBUSY     */
        uint32_t SLVRDLOST     : 1;  /*!< bit:      2  I2CENSTS_BIT_SLVRDLOST        */
        uint32_t RESERVED_31_3 :29;  /*!< bit: 31.. 3                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CENSTS_REG;



/**
 *  @brief  Union type to access the Fast Speed I2C Spike Suppresion Limit Register (I2CFSSPKLEN), offset 0xA0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           : 8;  /*!< bit:  7.. 0  I2CFSSPKLEN_BIT_VAL           */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CFSSPKLEN_REG;



/**
 *  @brief  Union type to access the High Speed I2C Spike Suppresion Limit Register (I2CHSSPKLEN), offset 0xA4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           : 8;  /*!< bit:  7.. 0  I2CHSSPKLEN_BIT_VAL           */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CHSSPKLEN_REG;



/**
  *  @brief  Structure type to access the I2C Controller (I2C).
  */
typedef struct
{
    __IO I2CCTL_REG             I2CCTL                  ; /*!< Offset: 0x00000000 (RW  )  I2C Control Register                              */
    __IO I2CMASTERADDR_REG      I2CMASTERADDR           ; /*!< Offset: 0x00000004 (RW  )  I2C Master Address Register                       */
    __IO I2CSLVADDR_REG         I2CSLVADDR              ; /*!< Offset: 0x00000008 (RW  )  I2C Slave Address Register                        */
    __IO I2CHSMADDR_REG         I2CHSMADDR              ; /*!< Offset: 0x0000000C (RW  )  I2C High Speed Master Mode Code Address Register  */
    __IO I2CDATACMD_REG         I2CDATACMD              ; /*!< Offset: 0x00000010 (RW  )  I2C Data Buffer and Command Register              */
    __IO I2CSSHCNT_REG          I2CSSHCNT               ; /*!< Offset: 0x00000014 (RW  )  Standard Speed I2C Clock SCL High Count Register  */
    __IO I2CSSLCNT_REG          I2CSSLCNT               ; /*!< Offset: 0x00000018 (RW  )  Standard Speed I2C Clock SCL Low Count Register   */
    __IO I2CFSHCNT_REG          I2CFSHCNT               ; /*!< Offset: 0x0000001C (RW  )  Fast Speed I2C Clock SCL High Count Register      */
    __IO I2CFSLCNT_REG          I2CFSLCNT               ; /*!< Offset: 0x00000020 (RW  )  Fast Speed I2C Clock SCL Low Count Register       */
    __IO I2CHSHCNT_REG          I2CHSHCNT               ; /*!< Offset: 0x00000024 (RW  )  High Speed I2C Clock SCL High Count Register      */
    __IO I2CHSLCNT_REG          I2CHSLCNT               ; /*!< Offset: 0x00000028 (RW  )  High Speed I2C Clock SCL Low Count Register       */
    __I  I2CIF_REG              I2CIF                   ; /*!< Offset: 0x0000002C (RO  )  I2C Interrupt Flag Register                       */
    __IO I2CIE_REG              I2CIE                   ; /*!< Offset: 0x00000030 (RW  )  I2C Interrupt Enable Register                     */
    __I  I2CRAWIF_REG           I2CRAWIF                ; /*!< Offset: 0x00000034 (RO  )  I2C Raw Interrupt Flag Register                   */
    __IO I2CRXTH_REG            I2CRXTH                 ; /*!< Offset: 0x00000038 (RW  )  I2C Receive FIFO Threshold Register               */
    __IO I2CTXTH_REG            I2CTXTH                 ; /*!< Offset: 0x0000003C (RW  )  I2C Transmit FIFO Threshold Register              */
    __I  I2CINTCLR_REG          I2CINTCLR               ; /*!< Offset: 0x00000040 (RO  )  Clear Combined and Individual Interrupt Register  */
    __I  I2CRXUDFCLR_REG        I2CRXUDFCLR             ; /*!< Offset: 0x00000044 (RO  )  Clear RXUDF Interrupt Register                    */
    __I  I2CRXOVFCLR_REG        I2CRXOVFCLR             ; /*!< Offset: 0x00000048 (RO  )  Clear RXOVF Interrupt Register                    */
    __I  I2CTXOVFCLR_REG        I2CTXOVFCLR             ; /*!< Offset: 0x0000004C (RO  )  Clear TXOVF Interrupt Register                    */
    __I  I2CRDREQCLR_REG        I2CRDREQCLR             ; /*!< Offset: 0x00000050 (RO  )  Clear RDREQ Interrupt Register                    */
    __I  I2CTXABRTCLR_REG       I2CTXABRTCLR            ; /*!< Offset: 0x00000054 (RO  )  Clear TXABRT Interrupt Register                   */
    __I  I2CRXDONECLR_REG       I2CRXDONECLR            ; /*!< Offset: 0x00000058 (RO  )  Clear RXDONE Interrupt Register                   */
    __I  I2CACTCLR_REG          I2CACTCLR               ; /*!< Offset: 0x0000005C (RO  )  Clear ACT Interrupt Register                      */
    __I  I2CSTOPDETCLR_REG      I2CSTOPDETCLR           ; /*!< Offset: 0x00000060 (RO  )  Clear STOPDET Interrupt Register                  */
    __I  I2CSTARTDETCLR_REG     I2CSTARTDETCLR          ; /*!< Offset: 0x00000064 (RO  )  Clear STARTDET Interrupt Register                 */
    __I  I2CGENCALLCLR_REG      I2CGENCALLCLR           ; /*!< Offset: 0x00000068 (RO  )  Clear GENCALL Interrupt Register                  */
    __IO I2CENABLE_REG          I2CENABLE               ; /*!< Offset: 0x0000006C (RW  )  I2C Enable Register                               */
    __I  I2CSTS_REG             I2CSTS                  ; /*!< Offset: 0x00000070 (RO  )  I2C Status Register                               */
    __I  I2CTFLVL_REG           I2CTFLVL                ; /*!< Offset: 0x00000074 (RO  )  I2C Transmit FIFO Level Register                  */
    __I  I2CRFLVL_REG           I2CRFLVL                ; /*!< Offset: 0x00000078 (RO  )  I2C Receive FIFO Level Register                   */
    __IO I2CSDAHOLD_REG         I2CSDAHOLD              ; /*!< Offset: 0x0000007C (RW  )  I2C SDA Hold-Time Register                        */
    __I  I2CTXABRTSRC_REG       I2CTXABRTSRC            ; /*!< Offset: 0x00000080 (RO  )  I2C Transmit Abort Source Register                */
         uint32_t               RESERVED0               ; 
         uint32_t               RESERVED1               ; 
         uint32_t               RESERVED2               ; 
         uint32_t               RESERVED3               ; 
    __IO I2CSDASETUP_REG        I2CSDASETUP             ; /*!< Offset: 0x00000094 (RW  )  I2C SDA Setup Register                            */
    __IO I2CACKGC_REG           I2CACKGC                ; /*!< Offset: 0x00000098 (RW  )  I2C ACK General Call Register                     */
    __I  I2CENSTS_REG           I2CENSTS                ; /*!< Offset: 0x0000009C (RO  )  I2C Enable Status Register                        */
    __IO I2CFSSPKLEN_REG        I2CFSSPKLEN             ; /*!< Offset: 0x000000A0 (RW  )  Fast Speed I2C Spike Suppresion Limit Register    */
    __IO I2CHSSPKLEN_REG        I2CHSSPKLEN             ; /*!< Offset: 0x000000A4 (RW  )  High Speed I2C Spike Suppresion Limit Register    */
} I2C_REGS;



/********************************************************************************
*
* Module Name     TIMER
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the Timer Control Register (TMRCTL), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t EN            : 1;  /*!< bit:      0  TMRCTL_BIT_EN          */
        uint32_t HOLD          : 1;  /*!< bit:      1  TMRCTL_BIT_HOLD        */
        uint32_t ADCSOCEN      : 1;  /*!< bit:      2  TMRCTL_BIT_ADCSOCEN    */
        uint32_t PWMSYNCEN     : 1;  /*!< bit:      3  TMRCTL_BIT_PWMSYNCEN   */
        uint32_t EXTINMODE     : 2;  /*!< bit:  5.. 4  TMRCTL_BIT_EXTINMODE   */
        uint32_t EXTPOL        : 1;  /*!< bit:      6  TMRCTL_BIT_EXTPOL      */
        uint32_t EXTSEL        : 6;  /*!< bit: 12.. 7  TMRCTL_BIT_EXTSEL      */
        uint32_t RESERVED_31_13:19;  /*!< bit: 31..13                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TMRCTL_REG;



/**
 *  @brief  Union type to access the Timer Counter Value Register (TMRCNT), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  TMRCNT_BIT_VAL         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TMRCNT_REG;



/**
 *  @brief  Union type to access the Timer Reload Value Register (TMRRELOAD), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  TMRRELOAD_BIT_VAL      */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TMRRELOAD_REG;



/**
 *  @brief  Union type to access the Timer Interrupt Flag Register (TMRIF), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t INT           : 1;  /*!< bit:      0  TMRIF_BIT_INT          */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TMRIF_REG;



/**
 *  @brief  Union type to access the Timer Raw Interrupt Flag Register (TMRRAWIF), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t INT           : 1;  /*!< bit:      0  TMRRAWIF_BIT_INT       */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TMRRAWIF_REG;



/**
 *  @brief  Union type to access the Timer Interrupt Enable Register (TMRIE), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t INT           : 1;  /*!< bit:      0  TMRIE_BIT_INT          */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TMRIE_REG;



/**
 *  @brief  Union type to access the Timer Interrupt Force Register (TMRIFRC), offset 0x18.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t INT           : 1;  /*!< bit:      0  TMRIFRC_BIT_INT        */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TMRIFRC_REG;



/**
 *  @brief  Union type to access the Timer Interrupt Clear Register (TMRIC), offset 0x1C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t INT           : 1;  /*!< bit:      0  TMRIC_BIT_INT          */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TMRIC_REG;



/**
  *  @brief  Structure type to access the TIMER Controller (TIMER).
  */
typedef struct
{
    __IO TMRCTL_REG        TMRCTL             ; /*!< Offset: 0x00000000 (RW  )  Timer Control Register             */
    __IO TMRCNT_REG        TMRCNT             ; /*!< Offset: 0x00000004 (RW  )  Timer Counter Value Register       */
    __IO TMRRELOAD_REG     TMRRELOAD          ; /*!< Offset: 0x00000008 (RW  )  Timer Reload Value Register        */
    __I  TMRIF_REG         TMRIF              ; /*!< Offset: 0x0000000C (RO  )  Timer Interrupt Flag Register      */
    __I  TMRRAWIF_REG      TMRRAWIF           ; /*!< Offset: 0x00000010 (RO  )  Timer Raw Interrupt Flag Register  */
    __IO TMRIE_REG         TMRIE              ; /*!< Offset: 0x00000014 (RW  )  Timer Interrupt Enable Register    */
    __O  TMRIFRC_REG       TMRIFRC            ; /*!< Offset: 0x00000018 (WO  )  Timer Interrupt Force Register     */
    __O  TMRIC_REG         TMRIC              ; /*!< Offset: 0x0000001C (WO  )  Timer Interrupt Clear Register     */
} TIMER_REGS;



/********************************************************************************
*
* Module Name     CRC
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the CRC Interrupt Flag Register (CRCIF), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DONE          : 1;  /*!< bit:      0  CRCIF_BIT_DONE         */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CRCIF_REG;



/**
 *  @brief  Union type to access the CRC Raw Interrupt Flag Register (CRCRAWIF), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DONE          : 1;  /*!< bit:      0  CRCRAWIF_BIT_DONE      */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CRCRAWIF_REG;



/**
 *  @brief  Union type to access the CRC Interrupt Clear Register (CRCIC), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DONE          : 1;  /*!< bit:      0  CRCIC_BIT_DONE         */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CRCIC_REG;



/**
 *  @brief  Union type to access the CRC Interrupt Enable Register (CRCIE), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DONE          : 1;  /*!< bit:      0  CRCIE_BIT_DONE         */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CRCIE_REG;



/**
 *  @brief  Union type to access the CRC Control Register (CRCCTL), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t EN            : 1;  /*!< bit:      0  CRCCTL_BIT_EN          */
        uint32_t MODE          : 3;  /*!< bit:  3.. 1  CRCCTL_BIT_MODE        */
        uint32_t RESERVED_4_4  : 1;  /*!< bit:      4                         */
        uint32_t RESERVED_31_5 :27;  /*!< bit: 31.. 5                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CRCCTL_REG;



/**
 *  @brief  Union type to access the CRC Stream Length Register (CRCSTRLEN), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  CRCSTRLEN_BIT_VAL      */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CRCSTRLEN_REG;



/**
 *  @brief  Union type to access the CRC Stream Input Register (CRCSTRIN), offset 0x18.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  CRCSTRIN_BIT_VAL       */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CRCSTRIN_REG;



/**
 *  @brief  Union type to access the CRC Result Register (CRCRESULT), offset 0x1C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  CRCRESULT_BIT_VAL      */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CRCRESULT_REG;



/**
  *  @brief  Structure type to access the CRC Controller (CRC).
  */
typedef struct
{
    __I  CRCIF_REG         CRCIF              ; /*!< Offset: 0x00000000 (RO  )  CRC Interrupt Flag Register      */
    __I  CRCRAWIF_REG      CRCRAWIF           ; /*!< Offset: 0x00000004 (RO  )  CRC Raw Interrupt Flag Register  */
    __O  CRCIC_REG         CRCIC              ; /*!< Offset: 0x00000008 (WO  )  CRC Interrupt Clear Register     */
    __IO CRCIE_REG         CRCIE              ; /*!< Offset: 0x0000000C (RW  )  CRC Interrupt Enable Register    */
    __IO CRCCTL_REG        CRCCTL             ; /*!< Offset: 0x00000010 (RW  )  CRC Control Register             */
    __IO CRCSTRLEN_REG     CRCSTRLEN          ; /*!< Offset: 0x00000014 (RW  )  CRC Stream Length Register       */
    __IO CRCSTRIN_REG      CRCSTRIN           ; /*!< Offset: 0x00000018 (RW  )  CRC Stream Input Register        */
    __I  CRCRESULT_REG     CRCRESULT          ; /*!< Offset: 0x0000001C (RO  )  CRC Result Register              */
} CRC_REGS;



/********************************************************************************
*
* Module Name     AES
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the AES Control Register 0 (AESCTL0), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t START         : 1;  /*!< bit:      0  AESCTL0_BIT_START      */
        uint32_t RESERVED_1_1  : 1;  /*!< bit:      1                         */
        uint32_t IFIFOCLR      : 1;  /*!< bit:      2  AESCTL0_BIT_IFIFOCLR   */
        uint32_t OFIFOCLR      : 1;  /*!< bit:      3  AESCTL0_BIT_OFIFOCLR   */
        uint32_t OUTMSG        : 1;  /*!< bit:      4  AESCTL0_BIT_OUTMSG     */
        uint32_t OUTHDR        : 1;  /*!< bit:      5  AESCTL0_BIT_OUTHDR     */
        uint32_t RESERVED_7_6  : 2;  /*!< bit:  7.. 6                         */
        uint32_t RESERVED_8_8  : 1;  /*!< bit:      8                         */
        uint32_t RESERVED_9_9  : 1;  /*!< bit:      9                         */
        uint32_t KEYSIZE       : 2;  /*!< bit: 11..10  AESCTL0_BIT_KEYSIZE    */
        uint32_t MICLEN        : 2;  /*!< bit: 13..12  AESCTL0_BIT_MICLEN     */
        uint32_t OUTMIC        : 1;  /*!< bit:     14  AESCTL0_BIT_OUTMIC     */
        uint32_t DECRYPTEN     : 1;  /*!< bit:     15  AESCTL0_BIT_DECRYPTEN  */
        uint32_t MODE          : 3;  /*!< bit: 18..16  AESCTL0_BIT_MODE       */
        uint32_t CTRMOD        : 7;  /*!< bit: 25..19  AESCTL0_BIT_CTRMOD     */
        uint32_t RESERVED_31_26: 6;  /*!< bit: 31..26                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESCTL0_REG;



/**
 *  @brief  Union type to access the AES Status Register (AESSTS), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DONE          : 1;  /*!< bit:      0  AESSTS_BIT_DONE        */
        uint32_t RESERVED_3_1  : 3;  /*!< bit:  3.. 1                         */
        uint32_t IFIFOFULL     : 1;  /*!< bit:      4  AESSTS_BIT_IFIFOFULL   */
        uint32_t RESERVED_5_5  : 1;  /*!< bit:      5                         */
        uint32_t OFIFORDY      : 1;  /*!< bit:      6  AESSTS_BIT_OFIFORDY    */
        uint32_t OFIFOEMPTY    : 1;  /*!< bit:      7  AESSTS_BIT_OFIFOEMPTY  */
        uint32_t RESERVED_10_8 : 3;  /*!< bit: 10.. 8                         */
        uint32_t ERRCODE       : 3;  /*!< bit: 13..11  AESSTS_BIT_ERRCODE     */
        uint32_t IFIFODEPTH    : 3;  /*!< bit: 16..14  AESSTS_BIT_IFIFODEPTH  */
        uint32_t OFIFODEPTH    : 3;  /*!< bit: 19..17  AESSTS_BIT_OFIFODEPTH  */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESSTS_REG;



/**
 *  @brief  Union type to access the AES Associate String Length Register (AESASTRLEN), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  AESASTRLEN_BIT_VAL     */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESASTRLEN_REG;



/**
 *  @brief  Union type to access the AES Message String Length Register (AESMSTRLEN), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  AESMSTRLEN_BIT_VAL     */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESMSTRLEN_REG;



/**
 *  @brief  Union type to access the AES Input Message Word Register (AESSTRIN), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  AESSTRIN_BIT_VAL       */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESSTRIN_REG;



/**
 *  @brief  Union type to access the AES Initial Vector Register 0 (AESIV0), offset 0x18.
            Union type to access the AES Initial Vector Register 1 (AESIV1), offset 0x1C.
            Union type to access the AES Initial Vector Register 2 (AESIV2), offset 0x20.
            Union type to access the AES Initial Vector Register 3 (AESIV3), offset 0x24.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  AESIV0_BIT_VAL         
                                                       AESIV1_BIT_VAL         
                                                       AESIV2_BIT_VAL         
                                                       AESIV3_BIT_VAL         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESIVx_REG;



/**
 *  @brief  Union type to access the AES Key Register 0 (AESKEY0), offset 0x28.
            Union type to access the AES Key Register 1 (AESKEY1), offset 0x2C.
            Union type to access the AES Key Register 2 (AESKEY2), offset 0x30.
            ...
            Union type to access the AES Key Register 6 (AESKEY6), offset 0x40.
            Union type to access the AES Key Register 7 (AESKEY7), offset 0x44.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  AESKEY0_BIT_VAL        
                                                       AESKEY1_BIT_VAL        
                                                       AESKEY2_BIT_VAL        
                                                       ...                    
                                                       AESKEY6_BIT_VAL        
                                                       AESKEY7_BIT_VAL        */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESKEYx_REG;



/**
 *  @brief  Union type to access the AES Output Message Word Register (AESSTROUT), offset 0x48.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  AESSTROUT_BIT_VAL      */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESSTROUT_REG;



/**
 *  @brief  Union type to access the AES Output Vector Register 0 (AESOV0), offset 0x4C.
            Union type to access the AES Output Vector Register 1 (AESOV1), offset 0x50.
            Union type to access the AES Output Vector Register 2 (AESOV2), offset 0x54.
            Union type to access the AES Output Vector Register 3 (AESOV3), offset 0x58.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  AESOV0_BIT_VAL         
                                                       AESOV1_BIT_VAL         
                                                       AESOV2_BIT_VAL         
                                                       AESOV3_BIT_VAL         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESOVx_REG;



/**
 *  @brief  Union type to access the AES Interrupt Status Register (AESIF), offset 0x5C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DONE          : 1;  /*!< bit:      0  AESIF_BIT_DONE         */
        uint32_t IFIFOFULL     : 1;  /*!< bit:      1  AESIF_BIT_IFIFOFULL    */
        uint32_t OFIFOEMPTY    : 1;  /*!< bit:      2  AESIF_BIT_OFIFOEMPTY   */
        uint32_t RESERVED_31_3 :29;  /*!< bit: 31.. 3                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESIF_REG;



/**
 *  @brief  Union type to access the AES Interrupt Enable Register (AESIE), offset 0x60.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DONE          : 1;  /*!< bit:      0  AESIE_BIT_DONE         */
        uint32_t IFIFOFULL     : 1;  /*!< bit:      1  AESIE_BIT_IFIFOFULL    */
        uint32_t OFIFOEMPTY    : 1;  /*!< bit:      2  AESIE_BIT_OFIFOEMPTY   */
        uint32_t RESERVED_31_3 :29;  /*!< bit: 31.. 3                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESIE_REG;



/**
 *  @brief  Union type to access the AES Interrupt RAW status Register (AESRAWIF), offset 0x64.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DONE          : 1;  /*!< bit:      0  AESRAWIF_BIT_DONE      */
        uint32_t IFIFOFULL     : 1;  /*!< bit:      1  AESRAWIF_BIT_IFIFOFULL */
        uint32_t OFIFOEMPTY    : 1;  /*!< bit:      2  AESRAWIF_BIT_OFIFOEMPTY*/
        uint32_t RESERVED_31_3 :29;  /*!< bit: 31.. 3                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESRAWIF_REG;



/**
 *  @brief  Union type to access the AES Interrupt Clear Register (AESIC), offset 0x68.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DONE          : 1;  /*!< bit:      0  AESIC_BIT_DONE         */
        uint32_t IFIFOFULL     : 1;  /*!< bit:      1  AESIC_BIT_IFIFOFULL    */
        uint32_t OFIFOEMPTY    : 1;  /*!< bit:      2  AESIC_BIT_OFIFOEMPTY   */
        uint32_t RESERVED_31_3 :29;  /*!< bit: 31.. 3                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESIC_REG;



/**
  *  @brief  Structure type to access the AES Controller (AES).
  */
typedef struct
{
    __IO AESCTL0_REG        AESCTL0             ; /*!< Offset: 0x00000000 (RW  )  AES Control Register 0                */
         uint32_t           RESERVED0           ; 
    __I  AESSTS_REG         AESSTS              ; /*!< Offset: 0x00000008 (RO  )  AES Status Register                   */
    __IO AESASTRLEN_REG     AESASTRLEN          ; /*!< Offset: 0x0000000C (RW  )  AES Associate String Length Register  */
    __IO AESMSTRLEN_REG     AESMSTRLEN          ; /*!< Offset: 0x00000010 (RW  )  AES Message String Length Register    */
    __O  AESSTRIN_REG       AESSTRIN            ; /*!< Offset: 0x00000014 (WO  )  AES Input Message Word Register       */
    __IO AESIVx_REG         AESIV[4]            ; /*!< Offset: 0x00000018 (RW  )  AES Initial Vector Register 0         */
    __IO AESKEYx_REG        AESKEY[8]           ; /*!< Offset: 0x00000028 (RW  )  AES Key Register 0                    */
    __I  AESSTROUT_REG      AESSTROUT           ; /*!< Offset: 0x00000048 (RO  )  AES Output Message Word Register      */
    __I  AESOVx_REG         AESOV[4]            ; /*!< Offset: 0x0000004C (RO  )  AES Output Vector Register 0          */
    __I  AESIF_REG          AESIF               ; /*!< Offset: 0x0000005C (RO  )  AES Interrupt Status Register         */
    __IO AESIE_REG          AESIE               ; /*!< Offset: 0x00000060 (RW  )  AES Interrupt Enable Register         */
    __I  AESRAWIF_REG       AESRAWIF            ; /*!< Offset: 0x00000064 (RO  )  AES Interrupt RAW status Register     */
    __O  AESIC_REG          AESIC               ; /*!< Offset: 0x00000068 (WO  )  AES Interrupt Clear Register          */
} AES_REGS;



/********************************************************************************
*
* Module Name     FLASH
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the Flash Control Register (FLASHCTL), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t COMMAND       : 4;  /*!< bit:  3.. 0  FLASHCTL_BIT_COMMAND   */
        uint32_t DATAACCEPT    : 1;  /*!< bit:      4  FLASHCTL_BIT_DATAACCEPT*/
        uint32_t EXECUTION     : 1;  /*!< bit:      5  FLASHCTL_BIT_EXECUTION */
        uint32_t XIPEN         : 1;  /*!< bit:      6  FLASHCTL_BIT_XIPEN     */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} FLASHCTL_REG;



/**
 *  @brief  Union type to access the Flash Address Register (FLASHADDR), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  FLASHADDR_BIT_VAL      */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} FLASHADDR_REG;



/**
 *  @brief  Union type to access the Flash Data Input Register (FLASHDIN), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t FLASHDIN      :32;  /*!< bit: 31.. 0  FLASHDIN_BIT_FLASHDIN  */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} FLASHDIN_REG;



/**
 *  @brief  Union type to access the Flash Data Output Register (FLASHDOUT), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t FLASHDOUT     :32;  /*!< bit: 31.. 0  FLASHDOUT_BIT_FLASHDOUT*/
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} FLASHDOUT_REG;



/**
 *  @brief  Union type to access the Flash Timing Register 0 (FLASHTIMING0), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t TAEPH         : 6;  /*!< bit:  5.. 0  FLASHTIMING0_BIT_TAEPH */
        uint32_t TAA           : 6;  /*!< bit: 11.. 6  FLASHTIMING0_BIT_TAA   */
        uint32_t TAS           : 6;  /*!< bit: 17..12  FLASHTIMING0_BIT_TAS   */
        uint32_t TNVSSEC       : 6;  /*!< bit: 23..18  FLASHTIMING0_BIT_TNVSSEC*/
        uint32_t TNVSCHIP      : 6;  /*!< bit: 29..24  FLASHTIMING0_BIT_TNVSCHIP*/
        uint32_t RESERVED_31_30: 2;  /*!< bit: 31..30                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} FLASHTIMING0_REG;



/**
 *  @brief  Union type to access the Flash Timing Register 1 (FLASHTIMING1), offset 0x18.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t TSSE          : 6;  /*!< bit:  5.. 0  FLASHTIMING1_BIT_TSSE  */
        uint32_t TSBE          : 6;  /*!< bit: 11.. 6  FLASHTIMING1_BIT_TSBE  */
        uint32_t TUS           : 9;  /*!< bit: 20..12  FLASHTIMING1_BIT_TUS   */
        uint32_t TMS           :11;  /*!< bit: 31..21  FLASHTIMING1_BIT_TMS   */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} FLASHTIMING1_REG;



/**
 *  @brief  Union type to access the Flash Timing Register 2 (FLASHTIMING2), offset 0x1C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t TSCE          : 6;  /*!< bit:  5.. 0  FLASHTIMING2_BIT_TSCE  */
        uint32_t TPGS          : 6;  /*!< bit: 11.. 6  FLASHTIMING2_BIT_TPGS  */
        uint32_t TPROG         : 6;  /*!< bit: 17..12  FLASHTIMING2_BIT_TPROG */
        uint32_t TPGH          : 6;  /*!< bit: 23..18  FLASHTIMING2_BIT_TPGH  */
        uint32_t TRCVPROG      : 6;  /*!< bit: 29..24  FLASHTIMING2_BIT_TRCVPROG*/
        uint32_t RESERVED_31_30: 2;  /*!< bit: 31..30                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} FLASHTIMING2_REG;



/**
 *  @brief  Union type to access the Flash Timing Register 3 (FLASHTIMING3), offset 0x20.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t TPREPROG      : 6;  /*!< bit:  5.. 0  FLASHTIMING3_BIT_TPREPROG*/
        uint32_t TAPS          : 6;  /*!< bit: 11.. 6  FLASHTIMING3_BIT_TAPS  */
        uint32_t TAAR          : 6;  /*!< bit: 17..12  FLASHTIMING3_BIT_TAAR  */
        uint32_t TCFS          : 6;  /*!< bit: 23..18  FLASHTIMING3_BIT_TCFS  */
        uint32_t TCONFEN       : 6;  /*!< bit: 29..24  FLASHTIMING3_BIT_TCONFEN*/
        uint32_t RESERVED_31_30: 2;  /*!< bit: 31..30                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} FLASHTIMING3_REG;



/**
 *  @brief  Union type to access the Flash Timing Register 4 (FLASHTIMING4), offset 0x24.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t TDS           : 6;  /*!< bit:  5.. 0  FLASHTIMING4_BIT_TDS   */
        uint32_t TRW           : 6;  /*!< bit: 11.. 6  FLASHTIMING4_BIT_TRW   */
        uint32_t TCFH          : 6;  /*!< bit: 17..12  FLASHTIMING4_BIT_TCFH  */
        uint32_t TCFL          : 6;  /*!< bit: 23..18  FLASHTIMING4_BIT_TCFL  */
        uint32_t TRCVERASE     : 7;  /*!< bit: 30..24  FLASHTIMING4_BIT_TRCVERASE*/
        uint32_t RESERVED_31_31: 1;  /*!< bit:     31                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} FLASHTIMING4_REG;



/**
 *  @brief  Union type to access the Flash Timing Register 5 (FLASHTIMING5), offset 0x28.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t TAAVR         : 6;  /*!< bit:  5.. 0  FLASHTIMING5_BIT_TAAVR */
        uint32_t TRSRECALL     : 6;  /*!< bit: 11.. 6  FLASHTIMING5_BIT_TRSRECALL*/
        uint32_t TRSVREAD      : 6;  /*!< bit: 17..12  FLASHTIMING5_BIT_TRSVREAD*/
        uint32_t RESERVED_31_18:14;  /*!< bit: 31..18                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} FLASHTIMING5_REG;



/**
 *  @brief  Union type to access the Flash Write Protect Register 0 (FLASHWP0), offset 0x2C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t UNIT0         : 1;  /*!< bit:      0  FLASHWP0_BIT_UNIT0     */
        uint32_t UNIT1         : 1;  /*!< bit:      1  FLASHWP0_BIT_UNIT1     */
        uint32_t UNIT2         : 1;  /*!< bit:      2  FLASHWP0_BIT_UNIT2     */
        uint32_t UNIT3         : 1;  /*!< bit:      3  FLASHWP0_BIT_UNIT3     */
        uint32_t UNIT4         : 1;  /*!< bit:      4  FLASHWP0_BIT_UNIT4     */
        uint32_t UNIT5         : 1;  /*!< bit:      5  FLASHWP0_BIT_UNIT5     */
        uint32_t UNIT6         : 1;  /*!< bit:      6  FLASHWP0_BIT_UNIT6     */
        uint32_t UNIT7         : 1;  /*!< bit:      7  FLASHWP0_BIT_UNIT7     */
        uint32_t UNIT8         : 1;  /*!< bit:      8  FLASHWP0_BIT_UNIT8     */
        uint32_t UNIT9         : 1;  /*!< bit:      9  FLASHWP0_BIT_UNIT9     */
        uint32_t UNIT10        : 1;  /*!< bit:     10  FLASHWP0_BIT_UNIT10    */
        uint32_t UNIT11        : 1;  /*!< bit:     11  FLASHWP0_BIT_UNIT11    */
        uint32_t UNIT12        : 1;  /*!< bit:     12  FLASHWP0_BIT_UNIT12    */
        uint32_t UNIT13        : 1;  /*!< bit:     13  FLASHWP0_BIT_UNIT13    */
        uint32_t UNIT14        : 1;  /*!< bit:     14  FLASHWP0_BIT_UNIT14    */
        uint32_t UNIT15        : 1;  /*!< bit:     15  FLASHWP0_BIT_UNIT15    */
        uint32_t UNIT16        : 1;  /*!< bit:     16  FLASHWP0_BIT_UNIT16    */
        uint32_t UNIT17        : 1;  /*!< bit:     17  FLASHWP0_BIT_UNIT17    */
        uint32_t UNIT18        : 1;  /*!< bit:     18  FLASHWP0_BIT_UNIT18    */
        uint32_t UNIT19        : 1;  /*!< bit:     19  FLASHWP0_BIT_UNIT19    */
        uint32_t UNIT20        : 1;  /*!< bit:     20  FLASHWP0_BIT_UNIT20    */
        uint32_t UNIT21        : 1;  /*!< bit:     21  FLASHWP0_BIT_UNIT21    */
        uint32_t UNIT22        : 1;  /*!< bit:     22  FLASHWP0_BIT_UNIT22    */
        uint32_t UNIT23        : 1;  /*!< bit:     23  FLASHWP0_BIT_UNIT23    */
        uint32_t UNIT24        : 1;  /*!< bit:     24  FLASHWP0_BIT_UNIT24    */
        uint32_t UNIT25        : 1;  /*!< bit:     25  FLASHWP0_BIT_UNIT25    */
        uint32_t UNIT26        : 1;  /*!< bit:     26  FLASHWP0_BIT_UNIT26    */
        uint32_t UNIT27        : 1;  /*!< bit:     27  FLASHWP0_BIT_UNIT27    */
        uint32_t UNIT28        : 1;  /*!< bit:     28  FLASHWP0_BIT_UNIT28    */
        uint32_t UNIT29        : 1;  /*!< bit:     29  FLASHWP0_BIT_UNIT29    */
        uint32_t UNIT30        : 1;  /*!< bit:     30  FLASHWP0_BIT_UNIT30    */
        uint32_t UNIT31        : 1;  /*!< bit:     31  FLASHWP0_BIT_UNIT31    */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} FLASHWP0_REG;



/**
 *  @brief  Union type to access the Flash Write Protect Register 1 (FLASHWP1), offset 0x30.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t UNIT32        : 1;  /*!< bit:      0  FLASHWP1_BIT_UNIT32    */
        uint32_t UNIT33        : 1;  /*!< bit:      1  FLASHWP1_BIT_UNIT33    */
        uint32_t UNIT34        : 1;  /*!< bit:      2  FLASHWP1_BIT_UNIT34    */
        uint32_t UNIT35        : 1;  /*!< bit:      3  FLASHWP1_BIT_UNIT35    */
        uint32_t UNIT36        : 1;  /*!< bit:      4  FLASHWP1_BIT_UNIT36    */
        uint32_t UNIT37        : 1;  /*!< bit:      5  FLASHWP1_BIT_UNIT37    */
        uint32_t UNIT38        : 1;  /*!< bit:      6  FLASHWP1_BIT_UNIT38    */
        uint32_t UNIT39        : 1;  /*!< bit:      7  FLASHWP1_BIT_UNIT39    */
        uint32_t UNIT40        : 1;  /*!< bit:      8  FLASHWP1_BIT_UNIT40    */
        uint32_t UNIT41        : 1;  /*!< bit:      9  FLASHWP1_BIT_UNIT41    */
        uint32_t UNIT42        : 1;  /*!< bit:     10  FLASHWP1_BIT_UNIT42    */
        uint32_t UNIT43        : 1;  /*!< bit:     11  FLASHWP1_BIT_UNIT43    */
        uint32_t UNIT44        : 1;  /*!< bit:     12  FLASHWP1_BIT_UNIT44    */
        uint32_t UNIT45        : 1;  /*!< bit:     13  FLASHWP1_BIT_UNIT45    */
        uint32_t UNIT46        : 1;  /*!< bit:     14  FLASHWP1_BIT_UNIT46    */
        uint32_t UNIT47        : 1;  /*!< bit:     15  FLASHWP1_BIT_UNIT47    */
        uint32_t UNIT48        : 1;  /*!< bit:     16  FLASHWP1_BIT_UNIT48    */
        uint32_t UNIT49        : 1;  /*!< bit:     17  FLASHWP1_BIT_UNIT49    */
        uint32_t UNIT50        : 1;  /*!< bit:     18  FLASHWP1_BIT_UNIT50    */
        uint32_t UNIT51        : 1;  /*!< bit:     19  FLASHWP1_BIT_UNIT51    */
        uint32_t UNIT52        : 1;  /*!< bit:     20  FLASHWP1_BIT_UNIT52    */
        uint32_t UNIT53        : 1;  /*!< bit:     21  FLASHWP1_BIT_UNIT53    */
        uint32_t UNIT54        : 1;  /*!< bit:     22  FLASHWP1_BIT_UNIT54    */
        uint32_t UNIT55        : 1;  /*!< bit:     23  FLASHWP1_BIT_UNIT55    */
        uint32_t UNIT56        : 1;  /*!< bit:     24  FLASHWP1_BIT_UNIT56    */
        uint32_t UNIT57        : 1;  /*!< bit:     25  FLASHWP1_BIT_UNIT57    */
        uint32_t UNIT58        : 1;  /*!< bit:     26  FLASHWP1_BIT_UNIT58    */
        uint32_t UNIT59        : 1;  /*!< bit:     27  FLASHWP1_BIT_UNIT59    */
        uint32_t UNIT60        : 1;  /*!< bit:     28  FLASHWP1_BIT_UNIT60    */
        uint32_t UNIT61        : 1;  /*!< bit:     29  FLASHWP1_BIT_UNIT61    */
        uint32_t UNIT62        : 1;  /*!< bit:     30  FLASHWP1_BIT_UNIT62    */
        uint32_t UNIT63        : 1;  /*!< bit:     31  FLASHWP1_BIT_UNIT63    */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} FLASHWP1_REG;



/**
 *  @brief  Union type to access the Flash Write Protect Register 2 (FLASHWP2), offset 0x34.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t UNIT64        : 1;  /*!< bit:      0  FLASHWP2_BIT_UNIT64    */
        uint32_t UNIT65        : 1;  /*!< bit:      1  FLASHWP2_BIT_UNIT65    */
        uint32_t UNIT66        : 1;  /*!< bit:      2  FLASHWP2_BIT_UNIT66    */
        uint32_t UNIT67        : 1;  /*!< bit:      3  FLASHWP2_BIT_UNIT67    */
        uint32_t UNIT68        : 1;  /*!< bit:      4  FLASHWP2_BIT_UNIT68    */
        uint32_t UNIT69        : 1;  /*!< bit:      5  FLASHWP2_BIT_UNIT69    */
        uint32_t UNIT70        : 1;  /*!< bit:      6  FLASHWP2_BIT_UNIT70    */
        uint32_t UNIT71        : 1;  /*!< bit:      7  FLASHWP2_BIT_UNIT71    */
        uint32_t UNIT72        : 1;  /*!< bit:      8  FLASHWP2_BIT_UNIT72    */
        uint32_t UNIT73        : 1;  /*!< bit:      9  FLASHWP2_BIT_UNIT73    */
        uint32_t UNIT74        : 1;  /*!< bit:     10  FLASHWP2_BIT_UNIT74    */
        uint32_t UNIT75        : 1;  /*!< bit:     11  FLASHWP2_BIT_UNIT75    */
        uint32_t UNIT76        : 1;  /*!< bit:     12  FLASHWP2_BIT_UNIT76    */
        uint32_t UNIT77        : 1;  /*!< bit:     13  FLASHWP2_BIT_UNIT77    */
        uint32_t UNIT78        : 1;  /*!< bit:     14  FLASHWP2_BIT_UNIT78    */
        uint32_t UNIT79        : 1;  /*!< bit:     15  FLASHWP2_BIT_UNIT79    */
        uint32_t UNIT80        : 1;  /*!< bit:     16  FLASHWP2_BIT_UNIT80    */
        uint32_t UNIT81        : 1;  /*!< bit:     17  FLASHWP2_BIT_UNIT81    */
        uint32_t UNIT82        : 1;  /*!< bit:     18  FLASHWP2_BIT_UNIT82    */
        uint32_t UNIT83        : 1;  /*!< bit:     19  FLASHWP2_BIT_UNIT83    */
        uint32_t UNIT84        : 1;  /*!< bit:     20  FLASHWP2_BIT_UNIT84    */
        uint32_t UNIT85        : 1;  /*!< bit:     21  FLASHWP2_BIT_UNIT85    */
        uint32_t UNIT86        : 1;  /*!< bit:     22  FLASHWP2_BIT_UNIT86    */
        uint32_t UNIT87        : 1;  /*!< bit:     23  FLASHWP2_BIT_UNIT87    */
        uint32_t UNIT88        : 1;  /*!< bit:     24  FLASHWP2_BIT_UNIT88    */
        uint32_t UNIT89        : 1;  /*!< bit:     25  FLASHWP2_BIT_UNIT89    */
        uint32_t UNIT90        : 1;  /*!< bit:     26  FLASHWP2_BIT_UNIT90    */
        uint32_t UNIT91        : 1;  /*!< bit:     27  FLASHWP2_BIT_UNIT91    */
        uint32_t UNIT92        : 1;  /*!< bit:     28  FLASHWP2_BIT_UNIT92    */
        uint32_t UNIT93        : 1;  /*!< bit:     29  FLASHWP2_BIT_UNIT93    */
        uint32_t UNIT94        : 1;  /*!< bit:     30  FLASHWP2_BIT_UNIT94    */
        uint32_t UNIT95        : 1;  /*!< bit:     31  FLASHWP2_BIT_UNIT95    */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} FLASHWP2_REG;



/**
 *  @brief  Union type to access the Flash Write Protect Register 3 (FLASHWP3), offset 0x38.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t UNIT96        : 1;  /*!< bit:      0  FLASHWP3_BIT_UNIT96    */
        uint32_t UNIT97        : 1;  /*!< bit:      1  FLASHWP3_BIT_UNIT97    */
        uint32_t UNIT98        : 1;  /*!< bit:      2  FLASHWP3_BIT_UNIT98    */
        uint32_t UNIT99        : 1;  /*!< bit:      3  FLASHWP3_BIT_UNIT99    */
        uint32_t UNIT100       : 1;  /*!< bit:      4  FLASHWP3_BIT_UNIT100   */
        uint32_t UNIT101       : 1;  /*!< bit:      5  FLASHWP3_BIT_UNIT101   */
        uint32_t UNIT102       : 1;  /*!< bit:      6  FLASHWP3_BIT_UNIT102   */
        uint32_t UNIT103       : 1;  /*!< bit:      7  FLASHWP3_BIT_UNIT103   */
        uint32_t UNIT104       : 1;  /*!< bit:      8  FLASHWP3_BIT_UNIT104   */
        uint32_t UNIT105       : 1;  /*!< bit:      9  FLASHWP3_BIT_UNIT105   */
        uint32_t UNIT106       : 1;  /*!< bit:     10  FLASHWP3_BIT_UNIT106   */
        uint32_t UNIT107       : 1;  /*!< bit:     11  FLASHWP3_BIT_UNIT107   */
        uint32_t UNIT108       : 1;  /*!< bit:     12  FLASHWP3_BIT_UNIT108   */
        uint32_t UNIT109       : 1;  /*!< bit:     13  FLASHWP3_BIT_UNIT109   */
        uint32_t UNIT110       : 1;  /*!< bit:     14  FLASHWP3_BIT_UNIT110   */
        uint32_t UNIT111       : 1;  /*!< bit:     15  FLASHWP3_BIT_UNIT111   */
        uint32_t UNIT112       : 1;  /*!< bit:     16  FLASHWP3_BIT_UNIT112   */
        uint32_t UNIT113       : 1;  /*!< bit:     17  FLASHWP3_BIT_UNIT113   */
        uint32_t UNIT114       : 1;  /*!< bit:     18  FLASHWP3_BIT_UNIT114   */
        uint32_t UNIT115       : 1;  /*!< bit:     19  FLASHWP3_BIT_UNIT115   */
        uint32_t UNIT116       : 1;  /*!< bit:     20  FLASHWP3_BIT_UNIT116   */
        uint32_t UNIT117       : 1;  /*!< bit:     21  FLASHWP3_BIT_UNIT117   */
        uint32_t UNIT118       : 1;  /*!< bit:     22  FLASHWP3_BIT_UNIT118   */
        uint32_t UNIT119       : 1;  /*!< bit:     23  FLASHWP3_BIT_UNIT119   */
        uint32_t UNIT120       : 1;  /*!< bit:     24  FLASHWP3_BIT_UNIT120   */
        uint32_t UNIT121       : 1;  /*!< bit:     25  FLASHWP3_BIT_UNIT121   */
        uint32_t UNIT122       : 1;  /*!< bit:     26  FLASHWP3_BIT_UNIT122   */
        uint32_t UNIT123       : 1;  /*!< bit:     27  FLASHWP3_BIT_UNIT123   */
        uint32_t UNIT124       : 1;  /*!< bit:     28  FLASHWP3_BIT_UNIT124   */
        uint32_t UNIT125       : 1;  /*!< bit:     29  FLASHWP3_BIT_UNIT125   */
        uint32_t UNIT126       : 1;  /*!< bit:     30  FLASHWP3_BIT_UNIT126   */
        uint32_t UNIT127       : 1;  /*!< bit:     31  FLASHWP3_BIT_UNIT127   */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} FLASHWP3_REG;



/**
 *  @brief  Union type to access the Flash Register Write-Allow Key Register (FLASHREGKEY), offset 0x3C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t KEY           :32;  /*!< bit: 31.. 0  FLASHREGKEY_BIT_KEY    */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} FLASHREGKEY_REG;



/**
  *  @brief  Structure type to access the FLASH Controller (FLASH).
  */
typedef struct
{
    __IO FLASHCTL_REG         FLASHCTL              ; /*!< Offset: 0x00000000 (RW  )  Flash Control Register                   */
    __IO FLASHADDR_REG        FLASHADDR             ; /*!< Offset: 0x00000004 (RW  )  Flash Address Register                   */
    __IO FLASHDIN_REG         FLASHDIN              ; /*!< Offset: 0x00000008 (RW  )  Flash Data Input Register                */
    __I  FLASHDOUT_REG        FLASHDOUT             ; /*!< Offset: 0x0000000C (RO  )  Flash Data Output Register               */
         uint32_t             RESERVED0             ; 
    __IO FLASHTIMING0_REG     FLASHTIMING0          ; /*!< Offset: 0x00000014 (RW  )  Flash Timing Register 0                  */
    __IO FLASHTIMING1_REG     FLASHTIMING1          ; /*!< Offset: 0x00000018 (RW  )  Flash Timing Register 1                  */
    __IO FLASHTIMING2_REG     FLASHTIMING2          ; /*!< Offset: 0x0000001C (RW  )  Flash Timing Register 2                  */
    __IO FLASHTIMING3_REG     FLASHTIMING3          ; /*!< Offset: 0x00000020 (RW  )  Flash Timing Register 3                  */
    __IO FLASHTIMING4_REG     FLASHTIMING4          ; /*!< Offset: 0x00000024 (RW  )  Flash Timing Register 4                  */
    __IO FLASHTIMING5_REG     FLASHTIMING5          ; /*!< Offset: 0x00000028 (RW  )  Flash Timing Register 5                  */
    __IO FLASHWP0_REG         FLASHWP0              ; /*!< Offset: 0x0000002C (RW  )  Flash Write Protect Register 0           */
    __IO FLASHWP1_REG         FLASHWP1              ; /*!< Offset: 0x00000030 (RW  )  Flash Write Protect Register 1           */
    __IO FLASHWP2_REG         FLASHWP2              ; /*!< Offset: 0x00000034 (RW  )  Flash Write Protect Register 2           */
    __IO FLASHWP3_REG         FLASHWP3              ; /*!< Offset: 0x00000038 (RW  )  Flash Write Protect Register 3           */
    __IO FLASHREGKEY_REG      FLASHREGKEY           ; /*!< Offset: 0x0000003C (RW  )  Flash Register Write-Allow Key Register  */
} FLASH_REGS;



/********************************************************************************
*
* Module Name     PGA
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the PGA0 Control Register (PGA0CTL), offset 0x2C0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t EN            : 1;  /*!< bit:      0  PGA0CTL_BIT_EN         */
        uint32_t MODE          : 2;  /*!< bit:  2.. 1  PGA0CTL_BIT_MODE       */
        uint32_t CMSEL         : 1;  /*!< bit:      3  PGA0CTL_BIT_CMSEL      */
        uint32_t INSELP        : 3;  /*!< bit:  6.. 4  PGA0CTL_BIT_INSELP     */
        uint32_t INSELN        : 3;  /*!< bit:  9.. 7  PGA0CTL_BIT_INSELN     */
        uint32_t GAINP         : 3;  /*!< bit: 12..10  PGA0CTL_BIT_GAINP      */
        uint32_t GAINN         : 3;  /*!< bit: 15..13  PGA0CTL_BIT_GAINN      */
        uint32_t BYPP          : 1;  /*!< bit:     16  PGA0CTL_BIT_BYPP       */
        uint32_t BYPN          : 1;  /*!< bit:     17  PGA0CTL_BIT_BYPN       */
        uint32_t RESERVED_31_18:14;  /*!< bit: 31..18                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PGA0CTL_REG;



/**
 *  @brief  Union type to access the PGA1 Control Register (PGA1CTL), offset 0x2C4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t EN            : 1;  /*!< bit:      0  PGA1CTL_BIT_EN         */
        uint32_t MODE          : 2;  /*!< bit:  2.. 1  PGA1CTL_BIT_MODE       */
        uint32_t CMSEL         : 1;  /*!< bit:      3  PGA1CTL_BIT_CMSEL      */
        uint32_t INSELP        : 3;  /*!< bit:  6.. 4  PGA1CTL_BIT_INSELP     */
        uint32_t INSELN        : 3;  /*!< bit:  9.. 7  PGA1CTL_BIT_INSELN     */
        uint32_t GAINP         : 3;  /*!< bit: 12..10  PGA1CTL_BIT_GAINP      */
        uint32_t GAINN         : 3;  /*!< bit: 15..13  PGA1CTL_BIT_GAINN      */
        uint32_t BYPP          : 1;  /*!< bit:     16  PGA1CTL_BIT_BYPP       */
        uint32_t BYPN          : 1;  /*!< bit:     17  PGA1CTL_BIT_BYPN       */
        uint32_t RESERVED_31_18:14;  /*!< bit: 31..18                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PGA1CTL_REG;



/**
 *  @brief  Union type to access the PGA2 Control Register (PGA2CTL), offset 0x2C8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t EN            : 1;  /*!< bit:      0  PGA2CTL_BIT_EN         */
        uint32_t MODE          : 2;  /*!< bit:  2.. 1  PGA2CTL_BIT_MODE       */
        uint32_t CMSEL         : 1;  /*!< bit:      3  PGA2CTL_BIT_CMSEL      */
        uint32_t INSELP        : 3;  /*!< bit:  6.. 4  PGA2CTL_BIT_INSELP     */
        uint32_t INSELN        : 3;  /*!< bit:  9.. 7  PGA2CTL_BIT_INSELN     */
        uint32_t GAINP         : 3;  /*!< bit: 12..10  PGA2CTL_BIT_GAINP      */
        uint32_t GAINN         : 3;  /*!< bit: 15..13  PGA2CTL_BIT_GAINN      */
        uint32_t BYPP          : 1;  /*!< bit:     16  PGA2CTL_BIT_BYPP       */
        uint32_t BYPN          : 1;  /*!< bit:     17  PGA2CTL_BIT_BYPN       */
        uint32_t RESERVED_31_18:14;  /*!< bit: 31..18                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PGA2CTL_REG;



/**
 *  @brief  Union type to access the PGA Register Write-Allow Key Register (PGAREGKEY), offset 0x2E0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t KEY           :32;  /*!< bit: 31.. 0  PGAREGKEY_BIT_KEY      */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PGAREGKEY_REG;



/**
  *  @brief  Structure type to access the PGA Controller (PGA).
  */
typedef struct
{
         uint32_t          RESERVED0[176]     ; 
    __IO PGA0CTL_REG       PGA0CTL            ; /*!< Offset: 0x000002C0 (RW  )  PGA0 Control Register                  */
    __IO PGA1CTL_REG       PGA1CTL            ; /*!< Offset: 0x000002C4 (RW  )  PGA1 Control Register                  */
    __IO PGA2CTL_REG       PGA2CTL            ; /*!< Offset: 0x000002C8 (RW  )  PGA2 Control Register                  */
         uint32_t          RESERVED1[5]       ; 
    __IO PGAREGKEY_REG     PGAREGKEY          ; /*!< Offset: 0x000002E0 (RW  )  PGA Register Write-Allow Key Register  */
} PGA_REGS;



/********************************************************************************
*
* Module Name     COMP
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the Comparator Filter Output Register (COMPFLTOUT), offset 0x2F0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t COMP0L        : 1;  /*!< bit:      0  COMPFLTOUT_BIT_COMP0L  */
        uint32_t COMP0H        : 1;  /*!< bit:      1  COMPFLTOUT_BIT_COMP0H  */
        uint32_t COMP1L        : 1;  /*!< bit:      2  COMPFLTOUT_BIT_COMP1L  */
        uint32_t COMP1H        : 1;  /*!< bit:      3  COMPFLTOUT_BIT_COMP1H  */
        uint32_t COMP2L        : 1;  /*!< bit:      4  COMPFLTOUT_BIT_COMP2L  */
        uint32_t COMP2H        : 1;  /*!< bit:      5  COMPFLTOUT_BIT_COMP2H  */
        uint32_t COMP3L        : 1;  /*!< bit:      6  COMPFLTOUT_BIT_COMP3L  */
        uint32_t COMP3H        : 1;  /*!< bit:      7  COMPFLTOUT_BIT_COMP3H  */
        uint32_t COMP4L        : 1;  /*!< bit:      8  COMPFLTOUT_BIT_COMP4L  */
        uint32_t COMP4H        : 1;  /*!< bit:      9  COMPFLTOUT_BIT_COMP4H  */
        uint32_t RESERVED_31_10:22;  /*!< bit: 31..10                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} COMPFLTOUT_REG;



/**
 *  @brief  Union type to access the Comparator Status Register (COMPSTS), offset 0x2F4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t COMP0L        : 1;  /*!< bit:      0  COMPSTS_BIT_COMP0L     */
        uint32_t COMP0H        : 1;  /*!< bit:      1  COMPSTS_BIT_COMP0H     */
        uint32_t COMP1L        : 1;  /*!< bit:      2  COMPSTS_BIT_COMP1L     */
        uint32_t COMP1H        : 1;  /*!< bit:      3  COMPSTS_BIT_COMP1H     */
        uint32_t COMP2L        : 1;  /*!< bit:      4  COMPSTS_BIT_COMP2L     */
        uint32_t COMP2H        : 1;  /*!< bit:      5  COMPSTS_BIT_COMP2H     */
        uint32_t COMP3L        : 1;  /*!< bit:      6  COMPSTS_BIT_COMP3L     */
        uint32_t COMP3H        : 1;  /*!< bit:      7  COMPSTS_BIT_COMP3H     */
        uint32_t COMP4L        : 1;  /*!< bit:      8  COMPSTS_BIT_COMP4L     */
        uint32_t COMP4H        : 1;  /*!< bit:      9  COMPSTS_BIT_COMP4H     */
        uint32_t RESERVED_31_10:22;  /*!< bit: 31..10                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} COMPSTS_REG;



/**
 *  @brief  Union type to access the Comparator Status Clear Register (COMPSTSCLR), offset 0x2F8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t COMP0L        : 1;  /*!< bit:      0  COMPSTSCLR_BIT_COMP0L  */
        uint32_t COMP0H        : 1;  /*!< bit:      1  COMPSTSCLR_BIT_COMP0H  */
        uint32_t COMP1L        : 1;  /*!< bit:      2  COMPSTSCLR_BIT_COMP1L  */
        uint32_t COMP1H        : 1;  /*!< bit:      3  COMPSTSCLR_BIT_COMP1H  */
        uint32_t COMP2L        : 1;  /*!< bit:      4  COMPSTSCLR_BIT_COMP2L  */
        uint32_t COMP2H        : 1;  /*!< bit:      5  COMPSTSCLR_BIT_COMP2H  */
        uint32_t COMP3L        : 1;  /*!< bit:      6  COMPSTSCLR_BIT_COMP3L  */
        uint32_t COMP3H        : 1;  /*!< bit:      7  COMPSTSCLR_BIT_COMP3H  */
        uint32_t COMP4L        : 1;  /*!< bit:      8  COMPSTSCLR_BIT_COMP4L  */
        uint32_t COMP4H        : 1;  /*!< bit:      9  COMPSTSCLR_BIT_COMP4H  */
        uint32_t RESERVED_31_10:22;  /*!< bit: 31..10                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} COMPSTSCLR_REG;



/**
 *  @brief  Union type to access the Comparator 0 Control Register (COMP0CTL), offset 0x2FC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t ENL           : 1;  /*!< bit:      0  COMP0CTL_BIT_ENL       */
        uint32_t ENH           : 1;  /*!< bit:      1  COMP0CTL_BIT_ENH       */
        uint32_t PHCMPEN       : 1;  /*!< bit:      2  COMP0CTL_BIT_PHCMPEN   */
        uint32_t HYSTSEL       : 2;  /*!< bit:  4.. 3  COMP0CTL_BIT_HYSTSEL   */
        uint32_t INSEL         : 2;  /*!< bit:  6.. 5  COMP0CTL_BIT_INSEL     */
        uint32_t REFSEL        : 2;  /*!< bit:  8.. 7  COMP0CTL_BIT_REFSEL    */
        uint32_t SYNCSEL       : 3;  /*!< bit: 11.. 9  COMP0CTL_BIT_SYNCSEL   */
        uint32_t RESERVED_31_12:20;  /*!< bit: 31..12                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} COMP0CTL_REG;



/**
 *  @brief  Union type to access the COMP0L Control Register (COMP0LCTL), offset 0x300.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t SEL4PWM       : 3;  /*!< bit:  2.. 0  COMP0LCTL_BIT_SEL4PWM  */
        uint32_t POL4PWM       : 1;  /*!< bit:      3  COMP0LCTL_BIT_POL4PWM  */
        uint32_t SEL4GPIO      : 3;  /*!< bit:  6.. 4  COMP0LCTL_BIT_SEL4GPIO */
        uint32_t POL4GPIO      : 1;  /*!< bit:      7  COMP0LCTL_BIT_POL4GPIO */
        uint32_t SYNCCLREN     : 1;  /*!< bit:      8  COMP0LCTL_BIT_SYNCCLREN*/
        uint32_t FLTDIV        :10;  /*!< bit: 18.. 9  COMP0LCTL_BIT_FLTDIV   */
        uint32_t FLTWIN        : 5;  /*!< bit: 23..19  COMP0LCTL_BIT_FLTWIN   */
        uint32_t FLTTH         : 5;  /*!< bit: 28..24  COMP0LCTL_BIT_FLTTH    */
        uint32_t FLTRST        : 1;  /*!< bit:     29  COMP0LCTL_BIT_FLTRST   */
        uint32_t RESERVED_31_30: 2;  /*!< bit: 31..30                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} COMP0LCTL_REG;



/**
 *  @brief  Union type to access the COMP0H Control Register (COMP0HCTL), offset 0x304.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t SEL4PWM       : 3;  /*!< bit:  2.. 0  COMP0HCTL_BIT_SEL4PWM  */
        uint32_t POL4PWM       : 1;  /*!< bit:      3  COMP0HCTL_BIT_POL4PWM  */
        uint32_t SEL4GPIO      : 3;  /*!< bit:  6.. 4  COMP0HCTL_BIT_SEL4GPIO */
        uint32_t POL4GPIO      : 1;  /*!< bit:      7  COMP0HCTL_BIT_POL4GPIO */
        uint32_t SYNCCLREN     : 1;  /*!< bit:      8  COMP0HCTL_BIT_SYNCCLREN*/
        uint32_t FLTDIV        :10;  /*!< bit: 18.. 9  COMP0HCTL_BIT_FLTDIV   */
        uint32_t FLTWIN        : 5;  /*!< bit: 23..19  COMP0HCTL_BIT_FLTWIN   */
        uint32_t FLTTH         : 5;  /*!< bit: 28..24  COMP0HCTL_BIT_FLTTH    */
        uint32_t FLTRST        : 1;  /*!< bit:     29  COMP0HCTL_BIT_FLTRST   */
        uint32_t RESERVED_31_30: 2;  /*!< bit: 31..30                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} COMP0HCTL_REG;



/**
 *  @brief  Union type to access the Comparator 1 Control Register (COMP1CTL), offset 0x308.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t ENL           : 1;  /*!< bit:      0  COMP1CTL_BIT_ENL       */
        uint32_t ENH           : 1;  /*!< bit:      1  COMP1CTL_BIT_ENH       */
        uint32_t PHCMPEN       : 1;  /*!< bit:      2  COMP1CTL_BIT_PHCMPEN   */
        uint32_t HYSTSEL       : 2;  /*!< bit:  4.. 3  COMP1CTL_BIT_HYSTSEL   */
        uint32_t INSEL         : 2;  /*!< bit:  6.. 5  COMP1CTL_BIT_INSEL     */
        uint32_t REFSEL        : 2;  /*!< bit:  8.. 7  COMP1CTL_BIT_REFSEL    */
        uint32_t SYNCSEL       : 3;  /*!< bit: 11.. 9  COMP1CTL_BIT_SYNCSEL   */
        uint32_t RESERVED_31_12:20;  /*!< bit: 31..12                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} COMP1CTL_REG;



/**
 *  @brief  Union type to access the COMP1L Control Register (COMP1LCTL), offset 0x30C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t SEL4PWM       : 3;  /*!< bit:  2.. 0  COMP1LCTL_BIT_SEL4PWM  */
        uint32_t POL4PWM       : 1;  /*!< bit:      3  COMP1LCTL_BIT_POL4PWM  */
        uint32_t SEL4GPIO      : 3;  /*!< bit:  6.. 4  COMP1LCTL_BIT_SEL4GPIO */
        uint32_t POL4GPIO      : 1;  /*!< bit:      7  COMP1LCTL_BIT_POL4GPIO */
        uint32_t SYNCCLREN     : 1;  /*!< bit:      8  COMP1LCTL_BIT_SYNCCLREN*/
        uint32_t FLTDIV        :10;  /*!< bit: 18.. 9  COMP1LCTL_BIT_FLTDIV   */
        uint32_t FLTWIN        : 5;  /*!< bit: 23..19  COMP1LCTL_BIT_FLTWIN   */
        uint32_t FLTTH         : 5;  /*!< bit: 28..24  COMP1LCTL_BIT_FLTTH    */
        uint32_t FLTRST        : 1;  /*!< bit:     29  COMP1LCTL_BIT_FLTRST   */
        uint32_t RESERVED_31_30: 2;  /*!< bit: 31..30                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} COMP1LCTL_REG;



/**
 *  @brief  Union type to access the COMP1H Control Register (COMP1HCTL), offset 0x310.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t SEL4PWM       : 3;  /*!< bit:  2.. 0  COMP1HCTL_BIT_SEL4PWM  */
        uint32_t POL4PWM       : 1;  /*!< bit:      3  COMP1HCTL_BIT_POL4PWM  */
        uint32_t SEL4GPIO      : 3;  /*!< bit:  6.. 4  COMP1HCTL_BIT_SEL4GPIO */
        uint32_t POL4GPIO      : 1;  /*!< bit:      7  COMP1HCTL_BIT_POL4GPIO */
        uint32_t SYNCCLREN     : 1;  /*!< bit:      8  COMP1HCTL_BIT_SYNCCLREN*/
        uint32_t FLTDIV        :10;  /*!< bit: 18.. 9  COMP1HCTL_BIT_FLTDIV   */
        uint32_t FLTWIN        : 5;  /*!< bit: 23..19  COMP1HCTL_BIT_FLTWIN   */
        uint32_t FLTTH         : 5;  /*!< bit: 28..24  COMP1HCTL_BIT_FLTTH    */
        uint32_t FLTRST        : 1;  /*!< bit:     29  COMP1HCTL_BIT_FLTRST   */
        uint32_t RESERVED_31_30: 2;  /*!< bit: 31..30                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} COMP1HCTL_REG;



/**
 *  @brief  Union type to access the Comparator 2 Control Register (COMP2CTL), offset 0x314.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t ENL           : 1;  /*!< bit:      0  COMP2CTL_BIT_ENL       */
        uint32_t ENH           : 1;  /*!< bit:      1  COMP2CTL_BIT_ENH       */
        uint32_t PHCMPEN       : 1;  /*!< bit:      2  COMP2CTL_BIT_PHCMPEN   */
        uint32_t HYSTSEL       : 2;  /*!< bit:  4.. 3  COMP2CTL_BIT_HYSTSEL   */
        uint32_t INSEL         : 2;  /*!< bit:  6.. 5  COMP2CTL_BIT_INSEL     */
        uint32_t REFSEL        : 2;  /*!< bit:  8.. 7  COMP2CTL_BIT_REFSEL    */
        uint32_t SYNCSEL       : 3;  /*!< bit: 11.. 9  COMP2CTL_BIT_SYNCSEL   */
        uint32_t RESERVED_31_12:20;  /*!< bit: 31..12                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} COMP2CTL_REG;



/**
 *  @brief  Union type to access the COMP2L Control Register (COMP2LCTL), offset 0x318.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t SEL4PWM       : 3;  /*!< bit:  2.. 0  COMP2LCTL_BIT_SEL4PWM  */
        uint32_t POL4PWM       : 1;  /*!< bit:      3  COMP2LCTL_BIT_POL4PWM  */
        uint32_t SEL4GPIO      : 3;  /*!< bit:  6.. 4  COMP2LCTL_BIT_SEL4GPIO */
        uint32_t POL4GPIO      : 1;  /*!< bit:      7  COMP2LCTL_BIT_POL4GPIO */
        uint32_t SYNCCLREN     : 1;  /*!< bit:      8  COMP2LCTL_BIT_SYNCCLREN*/
        uint32_t FLTDIV        :10;  /*!< bit: 18.. 9  COMP2LCTL_BIT_FLTDIV   */
        uint32_t FLTWIN        : 5;  /*!< bit: 23..19  COMP2LCTL_BIT_FLTWIN   */
        uint32_t FLTTH         : 5;  /*!< bit: 28..24  COMP2LCTL_BIT_FLTTH    */
        uint32_t FLTRST        : 1;  /*!< bit:     29  COMP2LCTL_BIT_FLTRST   */
        uint32_t RESERVED_31_30: 2;  /*!< bit: 31..30                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} COMP2LCTL_REG;



/**
 *  @brief  Union type to access the COMP2H Control Register (COMP2HCTL), offset 0x31C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t SEL4PWM       : 3;  /*!< bit:  2.. 0  COMP2HCTL_BIT_SEL4PWM  */
        uint32_t POL4PWM       : 1;  /*!< bit:      3  COMP2HCTL_BIT_POL4PWM  */
        uint32_t SEL4GPIO      : 3;  /*!< bit:  6.. 4  COMP2HCTL_BIT_SEL4GPIO */
        uint32_t POL4GPIO      : 1;  /*!< bit:      7  COMP2HCTL_BIT_POL4GPIO */
        uint32_t SYNCCLREN     : 1;  /*!< bit:      8  COMP2HCTL_BIT_SYNCCLREN*/
        uint32_t FLTDIV        :10;  /*!< bit: 18.. 9  COMP2HCTL_BIT_FLTDIV   */
        uint32_t FLTWIN        : 5;  /*!< bit: 23..19  COMP2HCTL_BIT_FLTWIN   */
        uint32_t FLTTH         : 5;  /*!< bit: 28..24  COMP2HCTL_BIT_FLTTH    */
        uint32_t FLTRST        : 1;  /*!< bit:     29  COMP2HCTL_BIT_FLTRST   */
        uint32_t RESERVED_31_30: 2;  /*!< bit: 31..30                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} COMP2HCTL_REG;



/**
 *  @brief  Union type to access the Comparator 3 Control Register (COMP3CTL), offset 0x320.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t ENL           : 1;  /*!< bit:      0  COMP3CTL_BIT_ENL       */
        uint32_t ENH           : 1;  /*!< bit:      1  COMP3CTL_BIT_ENH       */
        uint32_t PHCMPEN       : 1;  /*!< bit:      2  COMP3CTL_BIT_PHCMPEN   */
        uint32_t HYSTSEL       : 2;  /*!< bit:  4.. 3  COMP3CTL_BIT_HYSTSEL   */
        uint32_t INSEL         : 2;  /*!< bit:  6.. 5  COMP3CTL_BIT_INSEL     */
        uint32_t REFSEL        : 2;  /*!< bit:  8.. 7  COMP3CTL_BIT_REFSEL    */
        uint32_t SYNCSEL       : 3;  /*!< bit: 11.. 9  COMP3CTL_BIT_SYNCSEL   */
        uint32_t RESERVED_31_12:20;  /*!< bit: 31..12                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} COMP3CTL_REG;



/**
 *  @brief  Union type to access the COMP3L Control Register (COMP3LCTL), offset 0x324.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t SEL4PWM       : 3;  /*!< bit:  2.. 0  COMP3LCTL_BIT_SEL4PWM  */
        uint32_t POL4PWM       : 1;  /*!< bit:      3  COMP3LCTL_BIT_POL4PWM  */
        uint32_t SEL4GPIO      : 3;  /*!< bit:  6.. 4  COMP3LCTL_BIT_SEL4GPIO */
        uint32_t POL4GPIO      : 1;  /*!< bit:      7  COMP3LCTL_BIT_POL4GPIO */
        uint32_t SYNCCLREN     : 1;  /*!< bit:      8  COMP3LCTL_BIT_SYNCCLREN*/
        uint32_t FLTDIV        :10;  /*!< bit: 18.. 9  COMP3LCTL_BIT_FLTDIV   */
        uint32_t FLTWIN        : 5;  /*!< bit: 23..19  COMP3LCTL_BIT_FLTWIN   */
        uint32_t FLTTH         : 5;  /*!< bit: 28..24  COMP3LCTL_BIT_FLTTH    */
        uint32_t FLTRST        : 1;  /*!< bit:     29  COMP3LCTL_BIT_FLTRST   */
        uint32_t RESERVED_31_30: 2;  /*!< bit: 31..30                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} COMP3LCTL_REG;



/**
 *  @brief  Union type to access the COMP3H Control Register (COMP3HCTL), offset 0x328.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t SEL4PWM       : 3;  /*!< bit:  2.. 0  COMP3HCTL_BIT_SEL4PWM  */
        uint32_t POL4PWM       : 1;  /*!< bit:      3  COMP3HCTL_BIT_POL4PWM  */
        uint32_t SEL4GPIO      : 3;  /*!< bit:  6.. 4  COMP3HCTL_BIT_SEL4GPIO */
        uint32_t POL4GPIO      : 1;  /*!< bit:      7  COMP3HCTL_BIT_POL4GPIO */
        uint32_t SYNCCLREN     : 1;  /*!< bit:      8  COMP3HCTL_BIT_SYNCCLREN*/
        uint32_t FLTDIV        :10;  /*!< bit: 18.. 9  COMP3HCTL_BIT_FLTDIV   */
        uint32_t FLTWIN        : 5;  /*!< bit: 23..19  COMP3HCTL_BIT_FLTWIN   */
        uint32_t FLTTH         : 5;  /*!< bit: 28..24  COMP3HCTL_BIT_FLTTH    */
        uint32_t FLTRST        : 1;  /*!< bit:     29  COMP3HCTL_BIT_FLTRST   */
        uint32_t RESERVED_31_30: 2;  /*!< bit: 31..30                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} COMP3HCTL_REG;



/**
 *  @brief  Union type to access the Comparator 4 Control Register (COMP4CTL), offset 0x32C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t ENL           : 1;  /*!< bit:      0  COMP4CTL_BIT_ENL       */
        uint32_t ENH           : 1;  /*!< bit:      1  COMP4CTL_BIT_ENH       */
        uint32_t PHCMPEN       : 1;  /*!< bit:      2  COMP4CTL_BIT_PHCMPEN   */
        uint32_t HYSTSEL       : 2;  /*!< bit:  4.. 3  COMP4CTL_BIT_HYSTSEL   */
        uint32_t INSEL         : 2;  /*!< bit:  6.. 5  COMP4CTL_BIT_INSEL     */
        uint32_t REFSEL        : 2;  /*!< bit:  8.. 7  COMP4CTL_BIT_REFSEL    */
        uint32_t SYNCSEL       : 3;  /*!< bit: 11.. 9  COMP4CTL_BIT_SYNCSEL   */
        uint32_t RESERVED_31_12:20;  /*!< bit: 31..12                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} COMP4CTL_REG;



/**
 *  @brief  Union type to access the COMP4L Control Register (COMP4LCTL), offset 0x330.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t SEL4PWM       : 3;  /*!< bit:  2.. 0  COMP4LCTL_BIT_SEL4PWM  */
        uint32_t POL4PWM       : 1;  /*!< bit:      3  COMP4LCTL_BIT_POL4PWM  */
        uint32_t SEL4GPIO      : 3;  /*!< bit:  6.. 4  COMP4LCTL_BIT_SEL4GPIO */
        uint32_t POL4GPIO      : 1;  /*!< bit:      7  COMP4LCTL_BIT_POL4GPIO */
        uint32_t SYNCCLREN     : 1;  /*!< bit:      8  COMP4LCTL_BIT_SYNCCLREN*/
        uint32_t FLTDIV        :10;  /*!< bit: 18.. 9  COMP4LCTL_BIT_FLTDIV   */
        uint32_t FLTWIN        : 5;  /*!< bit: 23..19  COMP4LCTL_BIT_FLTWIN   */
        uint32_t FLTTH         : 5;  /*!< bit: 28..24  COMP4LCTL_BIT_FLTTH    */
        uint32_t FLTRST        : 1;  /*!< bit:     29  COMP4LCTL_BIT_FLTRST   */
        uint32_t RESERVED_31_30: 2;  /*!< bit: 31..30                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} COMP4LCTL_REG;



/**
 *  @brief  Union type to access the COMP4H Control Register (COMP4HCTL), offset 0x334.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t SEL4PWM       : 3;  /*!< bit:  2.. 0  COMP4HCTL_BIT_SEL4PWM  */
        uint32_t POL4PWM       : 1;  /*!< bit:      3  COMP4HCTL_BIT_POL4PWM  */
        uint32_t SEL4GPIO      : 3;  /*!< bit:  6.. 4  COMP4HCTL_BIT_SEL4GPIO */
        uint32_t POL4GPIO      : 1;  /*!< bit:      7  COMP4HCTL_BIT_POL4GPIO */
        uint32_t SYNCCLREN     : 1;  /*!< bit:      8  COMP4HCTL_BIT_SYNCCLREN*/
        uint32_t FLTDIV        :10;  /*!< bit: 18.. 9  COMP4HCTL_BIT_FLTDIV   */
        uint32_t FLTWIN        : 5;  /*!< bit: 23..19  COMP4HCTL_BIT_FLTWIN   */
        uint32_t FLTTH         : 5;  /*!< bit: 28..24  COMP4HCTL_BIT_FLTTH    */
        uint32_t FLTRST        : 1;  /*!< bit:     29  COMP4HCTL_BIT_FLTRST   */
        uint32_t RESERVED_31_30: 2;  /*!< bit: 31..30                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} COMP4HCTL_REG;



/**
 *  @brief  Union type to access the DAC0 Control Register (DAC0CTL), offset 0x35C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t EN            : 1;  /*!< bit:      0  DAC0CTL_BIT_EN         */
        uint32_t CODELOAD      : 1;  /*!< bit:      1  DAC0CTL_BIT_CODELOAD   */
        uint32_t SYNCSEL       : 3;  /*!< bit:  4.. 2  DAC0CTL_BIT_SYNCSEL    */
        uint32_t RAMPEN        : 1;  /*!< bit:      5  DAC0CTL_BIT_RAMPEN     */
        uint32_t RAMPLOAD      : 1;  /*!< bit:      6  DAC0CTL_BIT_RAMPLOAD   */
        uint32_t COMPHSEL      : 3;  /*!< bit:  9.. 7  DAC0CTL_BIT_COMPHSEL   */
        uint32_t DBGRUN        : 2;  /*!< bit: 11..10  DAC0CTL_BIT_DBGRUN     */
        uint32_t RESERVED_31_12:20;  /*!< bit: 31..12                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DAC0CTL_REG;



/**
 *  @brief  Union type to access the DAC0 Code Register (DAC0CODE), offset 0x360.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :10;  /*!< bit:  9.. 0  DAC0CODE_BIT_VAL       */
        uint32_t RESERVED_31_10:22;  /*!< bit: 31..10                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DAC0CODE_REG;



/**
 *  @brief  Union type to access the DAC0 Active Code Register (DAC0CODEA), offset 0x364.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :10;  /*!< bit:  9.. 0  DAC0CODEA_BIT_VAL      */
        uint32_t RESERVED_31_10:22;  /*!< bit: 31..10                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DAC0CODEA_REG;



/**
 *  @brief  Union type to access the RAMP0 Delay Shadow Register (RAMP0DLY), offset 0x368.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  RAMP0DLY_BIT_VAL       */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} RAMP0DLY_REG;



/**
 *  @brief  Union type to access the RAMP0 Delay Active Register (RAMP0DLYA), offset 0x36C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  RAMP0DLYA_BIT_VAL      */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} RAMP0DLYA_REG;



/**
 *  @brief  Union type to access the RAMP0 Decrement Shadow Register (RAMP0DEC), offset 0x370.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  RAMP0DEC_BIT_VAL       */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} RAMP0DEC_REG;



/**
 *  @brief  Union type to access the RAMP0 Decrement Active Register (RAMP0DECA), offset 0x374.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  RAMP0DECA_BIT_VAL      */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} RAMP0DECA_REG;



/**
 *  @brief  Union type to access the RAMP0 Maximum Value Shadow Register (RAMP0MAX), offset 0x378.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  RAMP0MAX_BIT_VAL       */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} RAMP0MAX_REG;



/**
 *  @brief  Union type to access the RAMP0 Maximum Value Active Register (RAMP0MAXA), offset 0x37C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  RAMP0MAXA_BIT_VAL      */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} RAMP0MAXA_REG;



/**
 *  @brief  Union type to access the RAMP0 Count Register (RAMP0CNT), offset 0x380.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  RAMP0CNT_BIT_VAL       */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} RAMP0CNT_REG;



/**
 *  @brief  Union type to access the DAC1 Control Register (DAC1CTL), offset 0x384.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t EN            : 1;  /*!< bit:      0  DAC1CTL_BIT_EN         */
        uint32_t CODELOAD      : 1;  /*!< bit:      1  DAC1CTL_BIT_CODELOAD   */
        uint32_t SYNCSEL       : 3;  /*!< bit:  4.. 2  DAC1CTL_BIT_SYNCSEL    */
        uint32_t RAMPEN        : 1;  /*!< bit:      5  DAC1CTL_BIT_RAMPEN     */
        uint32_t RAMPLOAD      : 1;  /*!< bit:      6  DAC1CTL_BIT_RAMPLOAD   */
        uint32_t COMPHSEL      : 3;  /*!< bit:  9.. 7  DAC1CTL_BIT_COMPHSEL   */
        uint32_t DBGRUN        : 2;  /*!< bit: 11..10  DAC1CTL_BIT_DBGRUN     */
        uint32_t RESERVED_31_12:20;  /*!< bit: 31..12                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DAC1CTL_REG;



/**
 *  @brief  Union type to access the DAC1 Code Register (DAC1CODE), offset 0x388.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :10;  /*!< bit:  9.. 0  DAC1CODE_BIT_VAL       */
        uint32_t RESERVED_31_10:22;  /*!< bit: 31..10                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DAC1CODE_REG;



/**
 *  @brief  Union type to access the DAC1 Active Code Register (DAC1CODEA), offset 0x38C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :10;  /*!< bit:  9.. 0  DAC1CODEA_BIT_VAL      */
        uint32_t RESERVED_31_10:22;  /*!< bit: 31..10                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DAC1CODEA_REG;



/**
 *  @brief  Union type to access the RAMP1 Delay Shadow Register (RAMP1DLY), offset 0x390.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  RAMP1DLY_BIT_VAL       */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} RAMP1DLY_REG;



/**
 *  @brief  Union type to access the RAMP1 Delay Active Register (RAMP1DLYA), offset 0x394.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  RAMP1DLYA_BIT_VAL      */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} RAMP1DLYA_REG;



/**
 *  @brief  Union type to access the RAMP1 Decrement Shadow Register (RAMP1DEC), offset 0x398.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  RAMP1DEC_BIT_VAL       */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} RAMP1DEC_REG;



/**
 *  @brief  Union type to access the RAMP1 Decrement Active Register (RAMP1DECA), offset 0x39C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  RAMP1DECA_BIT_VAL      */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} RAMP1DECA_REG;



/**
 *  @brief  Union type to access the RAMP1 Maximum Value Shadow Register (RAMP1MAX), offset 0x3A0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  RAMP1MAX_BIT_VAL       */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} RAMP1MAX_REG;



/**
 *  @brief  Union type to access the RAMP1 Maximum Value Active Register (RAMP1MAXA), offset 0x3A4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  RAMP1MAXA_BIT_VAL      */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} RAMP1MAXA_REG;



/**
 *  @brief  Union type to access the RAMP1 Count Register (RAMP1CNT), offset 0x3A8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  RAMP1CNT_BIT_VAL       */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} RAMP1CNT_REG;



/**
 *  @brief  Union type to access the DAC2 Control Register (DAC2CTL), offset 0x3AC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t EN            : 1;  /*!< bit:      0  DAC2CTL_BIT_EN         */
        uint32_t CODELOAD      : 1;  /*!< bit:      1  DAC2CTL_BIT_CODELOAD   */
        uint32_t SYNCSEL       : 3;  /*!< bit:  4.. 2  DAC2CTL_BIT_SYNCSEL    */
        uint32_t RESERVED_31_5 :27;  /*!< bit: 31.. 5                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DAC2CTL_REG;



/**
 *  @brief  Union type to access the DAC2 Code Register (DAC2CODE), offset 0x3B0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :10;  /*!< bit:  9.. 0  DAC2CODE_BIT_VAL       */
        uint32_t RESERVED_31_10:22;  /*!< bit: 31..10                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DAC2CODE_REG;



/**
 *  @brief  Union type to access the DAC2 Active Code Register (DAC2CODEA), offset 0x3B4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :10;  /*!< bit:  9.. 0  DAC2CODEA_BIT_VAL      */
        uint32_t RESERVED_31_10:22;  /*!< bit: 31..10                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DAC2CODEA_REG;



/**
 *  @brief  Union type to access the DAC3 Control Register (DAC3CTL), offset 0x3B8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t EN            : 1;  /*!< bit:      0  DAC3CTL_BIT_EN         */
        uint32_t CODELOAD      : 1;  /*!< bit:      1  DAC3CTL_BIT_CODELOAD   */
        uint32_t SYNCSEL       : 3;  /*!< bit:  4.. 2  DAC3CTL_BIT_SYNCSEL    */
        uint32_t RESERVED_31_5 :27;  /*!< bit: 31.. 5                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DAC3CTL_REG;



/**
 *  @brief  Union type to access the DAC3 Code Register (DAC3CODE), offset 0x3BC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :10;  /*!< bit:  9.. 0  DAC3CODE_BIT_VAL       */
        uint32_t RESERVED_31_10:22;  /*!< bit: 31..10                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DAC3CODE_REG;



/**
 *  @brief  Union type to access the DAC3 Active Code Register (DAC3CODEA), offset 0x3C0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :10;  /*!< bit:  9.. 0  DAC3CODEA_BIT_VAL      */
        uint32_t RESERVED_31_10:22;  /*!< bit: 31..10                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DAC3CODEA_REG;



/**
 *  @brief  Union type to access the DAC Buffer Control Register (DACBUFCTL), offset 0x3F4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t EN            : 1;  /*!< bit:      0  DACBUFCTL_BIT_EN       */
        uint32_t INSEL         : 2;  /*!< bit:  2.. 1  DACBUFCTL_BIT_INSEL    */
        uint32_t OE10          : 1;  /*!< bit:      3  DACBUFCTL_BIT_OE10     */
        uint32_t OE13          : 1;  /*!< bit:      4  DACBUFCTL_BIT_OE13     */
        uint32_t RESERVED_31_5 :27;  /*!< bit: 31.. 5                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DACBUFCTL_REG;



/**
 *  @brief  Union type to access the COMP Register Write-Allow Key Register (COMPREGKEY), offset 0x3FC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t KEY           :32;  /*!< bit: 31.. 0  COMPREGKEY_BIT_KEY     */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} COMPREGKEY_REG;



/**
  *  @brief  Structure type to access the COMP Controller (COMP).
  */
typedef struct
{
         uint32_t           RESERVED0[188]      ; 
    __I  COMPFLTOUT_REG     COMPFLTOUT          ; /*!< Offset: 0x000002F0 (RO  )  Comparator Filter Output Register       */
    __I  COMPSTS_REG        COMPSTS             ; /*!< Offset: 0x000002F4 (RO  )  Comparator Status Register              */
    __O  COMPSTSCLR_REG     COMPSTSCLR          ; /*!< Offset: 0x000002F8 (WO  )  Comparator Status Clear Register        */
    __IO COMP0CTL_REG       COMP0CTL            ; /*!< Offset: 0x000002FC (RW  )  Comparator 0 Control Register           */
    __IO COMP0LCTL_REG      COMP0LCTL           ; /*!< Offset: 0x00000300 (RW  )  COMP0L Control Register                 */
    __IO COMP0HCTL_REG      COMP0HCTL           ; /*!< Offset: 0x00000304 (RW  )  COMP0H Control Register                 */
    __IO COMP1CTL_REG       COMP1CTL            ; /*!< Offset: 0x00000308 (RW  )  Comparator 1 Control Register           */
    __IO COMP1LCTL_REG      COMP1LCTL           ; /*!< Offset: 0x0000030C (RW  )  COMP1L Control Register                 */
    __IO COMP1HCTL_REG      COMP1HCTL           ; /*!< Offset: 0x00000310 (RW  )  COMP1H Control Register                 */
    __IO COMP2CTL_REG       COMP2CTL            ; /*!< Offset: 0x00000314 (RW  )  Comparator 2 Control Register           */
    __IO COMP2LCTL_REG      COMP2LCTL           ; /*!< Offset: 0x00000318 (RW  )  COMP2L Control Register                 */
    __IO COMP2HCTL_REG      COMP2HCTL           ; /*!< Offset: 0x0000031C (RW  )  COMP2H Control Register                 */
    __IO COMP3CTL_REG       COMP3CTL            ; /*!< Offset: 0x00000320 (RW  )  Comparator 3 Control Register           */
    __IO COMP3LCTL_REG      COMP3LCTL           ; /*!< Offset: 0x00000324 (RW  )  COMP3L Control Register                 */
    __IO COMP3HCTL_REG      COMP3HCTL           ; /*!< Offset: 0x00000328 (RW  )  COMP3H Control Register                 */
    __IO COMP4CTL_REG       COMP4CTL            ; /*!< Offset: 0x0000032C (RW  )  Comparator 4 Control Register           */
    __IO COMP4LCTL_REG      COMP4LCTL           ; /*!< Offset: 0x00000330 (RW  )  COMP4L Control Register                 */
    __IO COMP4HCTL_REG      COMP4HCTL           ; /*!< Offset: 0x00000334 (RW  )  COMP4H Control Register                 */
         uint32_t           RESERVED1[9]        ; 
    __IO DAC0CTL_REG        DAC0CTL             ; /*!< Offset: 0x0000035C (RW  )  DAC0 Control Register                   */
    __IO DAC0CODE_REG       DAC0CODE            ; /*!< Offset: 0x00000360 (RW  )  DAC0 Code Register                      */
    __I  DAC0CODEA_REG      DAC0CODEA           ; /*!< Offset: 0x00000364 (RO  )  DAC0 Active Code Register               */
    __IO RAMP0DLY_REG       RAMP0DLY            ; /*!< Offset: 0x00000368 (RW  )  RAMP0 Delay Shadow Register             */
    __I  RAMP0DLYA_REG      RAMP0DLYA           ; /*!< Offset: 0x0000036C (RO  )  RAMP0 Delay Active Register             */
    __IO RAMP0DEC_REG       RAMP0DEC            ; /*!< Offset: 0x00000370 (RW  )  RAMP0 Decrement Shadow Register         */
    __I  RAMP0DECA_REG      RAMP0DECA           ; /*!< Offset: 0x00000374 (RO  )  RAMP0 Decrement Active Register         */
    __IO RAMP0MAX_REG       RAMP0MAX            ; /*!< Offset: 0x00000378 (RW  )  RAMP0 Maximum Value Shadow Register     */
    __I  RAMP0MAXA_REG      RAMP0MAXA           ; /*!< Offset: 0x0000037C (RO  )  RAMP0 Maximum Value Active Register     */
    __I  RAMP0CNT_REG       RAMP0CNT            ; /*!< Offset: 0x00000380 (RO  )  RAMP0 Count Register                    */
    __IO DAC1CTL_REG        DAC1CTL             ; /*!< Offset: 0x00000384 (RW  )  DAC1 Control Register                   */
    __IO DAC1CODE_REG       DAC1CODE            ; /*!< Offset: 0x00000388 (RW  )  DAC1 Code Register                      */
    __I  DAC1CODEA_REG      DAC1CODEA           ; /*!< Offset: 0x0000038C (RO  )  DAC1 Active Code Register               */
    __IO RAMP1DLY_REG       RAMP1DLY            ; /*!< Offset: 0x00000390 (RW  )  RAMP1 Delay Shadow Register             */
    __I  RAMP1DLYA_REG      RAMP1DLYA           ; /*!< Offset: 0x00000394 (RO  )  RAMP1 Delay Active Register             */
    __IO RAMP1DEC_REG       RAMP1DEC            ; /*!< Offset: 0x00000398 (RW  )  RAMP1 Decrement Shadow Register         */
    __I  RAMP1DECA_REG      RAMP1DECA           ; /*!< Offset: 0x0000039C (RO  )  RAMP1 Decrement Active Register         */
    __IO RAMP1MAX_REG       RAMP1MAX            ; /*!< Offset: 0x000003A0 (RW  )  RAMP1 Maximum Value Shadow Register     */
    __I  RAMP1MAXA_REG      RAMP1MAXA           ; /*!< Offset: 0x000003A4 (RO  )  RAMP1 Maximum Value Active Register     */
    __I  RAMP1CNT_REG       RAMP1CNT            ; /*!< Offset: 0x000003A8 (RO  )  RAMP1 Count Register                    */
    __IO DAC2CTL_REG        DAC2CTL             ; /*!< Offset: 0x000003AC (RW  )  DAC2 Control Register                   */
    __IO DAC2CODE_REG       DAC2CODE            ; /*!< Offset: 0x000003B0 (RW  )  DAC2 Code Register                      */
    __I  DAC2CODEA_REG      DAC2CODEA           ; /*!< Offset: 0x000003B4 (RO  )  DAC2 Active Code Register               */
    __IO DAC3CTL_REG        DAC3CTL             ; /*!< Offset: 0x000003B8 (RW  )  DAC3 Control Register                   */
    __IO DAC3CODE_REG       DAC3CODE            ; /*!< Offset: 0x000003BC (RW  )  DAC3 Code Register                      */
    __I  DAC3CODEA_REG      DAC3CODEA           ; /*!< Offset: 0x000003C0 (RO  )  DAC3 Active Code Register               */
         uint32_t           RESERVED2[12]       ; 
    __IO DACBUFCTL_REG      DACBUFCTL           ; /*!< Offset: 0x000003F4 (RW  )  DAC Buffer Control Register             */
         uint32_t           RESERVED3           ; 
    __IO COMPREGKEY_REG     COMPREGKEY          ; /*!< Offset: 0x000003FC (RW  )  COMP Register Write-Allow Key Register  */
} COMP_REGS;



/********************************************************************************
*
* Module Name     ADC
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the ADC Interrupt Flag Register (ADCIF), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t INT0          : 1;  /*!< bit:      0  ADCIF_BIT_INT0           */
        uint32_t INT1          : 1;  /*!< bit:      1  ADCIF_BIT_INT1           */
        uint32_t INT2          : 1;  /*!< bit:      2  ADCIF_BIT_INT2           */
        uint32_t INT3          : 1;  /*!< bit:      3  ADCIF_BIT_INT3           */
        uint32_t INT4          : 1;  /*!< bit:      4  ADCIF_BIT_INT4           */
        uint32_t INT5          : 1;  /*!< bit:      5  ADCIF_BIT_INT5           */
        uint32_t INT6          : 1;  /*!< bit:      6  ADCIF_BIT_INT6           */
        uint32_t INT7          : 1;  /*!< bit:      7  ADCIF_BIT_INT7           */
        uint32_t INT8          : 1;  /*!< bit:      8  ADCIF_BIT_INT8           */
        uint32_t INT9          : 1;  /*!< bit:      9  ADCIF_BIT_INT9           */
        uint32_t INT10         : 1;  /*!< bit:     10  ADCIF_BIT_INT10          */
        uint32_t INT11         : 1;  /*!< bit:     11  ADCIF_BIT_INT11          */
        uint32_t INT12         : 1;  /*!< bit:     12  ADCIF_BIT_INT12          */
        uint32_t INT13         : 1;  /*!< bit:     13  ADCIF_BIT_INT13          */
        uint32_t INT14         : 1;  /*!< bit:     14  ADCIF_BIT_INT14          */
        uint32_t INT15         : 1;  /*!< bit:     15  ADCIF_BIT_INT15          */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCIF_REG;



/**
 *  @brief  Union type to access the ADC Interrupt Flag Clear Register (ADCIC), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t INT0          : 1;  /*!< bit:      0  ADCIC_BIT_INT0           */
        uint32_t INT1          : 1;  /*!< bit:      1  ADCIC_BIT_INT1           */
        uint32_t INT2          : 1;  /*!< bit:      2  ADCIC_BIT_INT2           */
        uint32_t INT3          : 1;  /*!< bit:      3  ADCIC_BIT_INT3           */
        uint32_t INT4          : 1;  /*!< bit:      4  ADCIC_BIT_INT4           */
        uint32_t INT5          : 1;  /*!< bit:      5  ADCIC_BIT_INT5           */
        uint32_t INT6          : 1;  /*!< bit:      6  ADCIC_BIT_INT6           */
        uint32_t INT7          : 1;  /*!< bit:      7  ADCIC_BIT_INT7           */
        uint32_t INT8          : 1;  /*!< bit:      8  ADCIC_BIT_INT8           */
        uint32_t INT9          : 1;  /*!< bit:      9  ADCIC_BIT_INT9           */
        uint32_t INT10         : 1;  /*!< bit:     10  ADCIC_BIT_INT10          */
        uint32_t INT11         : 1;  /*!< bit:     11  ADCIC_BIT_INT11          */
        uint32_t INT12         : 1;  /*!< bit:     12  ADCIC_BIT_INT12          */
        uint32_t INT13         : 1;  /*!< bit:     13  ADCIC_BIT_INT13          */
        uint32_t INT14         : 1;  /*!< bit:     14  ADCIC_BIT_INT14          */
        uint32_t INT15         : 1;  /*!< bit:     15  ADCIC_BIT_INT15          */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCIC_REG;



/**
 *  @brief  Union type to access the ADC Interrupt Overflow Flag Register (ADCIOVF), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t INT0          : 1;  /*!< bit:      0  ADCIOVF_BIT_INT0         */
        uint32_t INT1          : 1;  /*!< bit:      1  ADCIOVF_BIT_INT1         */
        uint32_t INT2          : 1;  /*!< bit:      2  ADCIOVF_BIT_INT2         */
        uint32_t INT3          : 1;  /*!< bit:      3  ADCIOVF_BIT_INT3         */
        uint32_t INT4          : 1;  /*!< bit:      4  ADCIOVF_BIT_INT4         */
        uint32_t INT5          : 1;  /*!< bit:      5  ADCIOVF_BIT_INT5         */
        uint32_t INT6          : 1;  /*!< bit:      6  ADCIOVF_BIT_INT6         */
        uint32_t INT7          : 1;  /*!< bit:      7  ADCIOVF_BIT_INT7         */
        uint32_t INT8          : 1;  /*!< bit:      8  ADCIOVF_BIT_INT8         */
        uint32_t INT9          : 1;  /*!< bit:      9  ADCIOVF_BIT_INT9         */
        uint32_t INT10         : 1;  /*!< bit:     10  ADCIOVF_BIT_INT10        */
        uint32_t INT11         : 1;  /*!< bit:     11  ADCIOVF_BIT_INT11        */
        uint32_t INT12         : 1;  /*!< bit:     12  ADCIOVF_BIT_INT12        */
        uint32_t INT13         : 1;  /*!< bit:     13  ADCIOVF_BIT_INT13        */
        uint32_t INT14         : 1;  /*!< bit:     14  ADCIOVF_BIT_INT14        */
        uint32_t INT15         : 1;  /*!< bit:     15  ADCIOVF_BIT_INT15        */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCIOVF_REG;



/**
 *  @brief  Union type to access the ADC Interrupt Overflow Flag Clear Register (ADCIOVFC), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t INT0          : 1;  /*!< bit:      0  ADCIOVFC_BIT_INT0        */
        uint32_t INT1          : 1;  /*!< bit:      1  ADCIOVFC_BIT_INT1        */
        uint32_t INT2          : 1;  /*!< bit:      2  ADCIOVFC_BIT_INT2        */
        uint32_t INT3          : 1;  /*!< bit:      3  ADCIOVFC_BIT_INT3        */
        uint32_t INT4          : 1;  /*!< bit:      4  ADCIOVFC_BIT_INT4        */
        uint32_t INT5          : 1;  /*!< bit:      5  ADCIOVFC_BIT_INT5        */
        uint32_t INT6          : 1;  /*!< bit:      6  ADCIOVFC_BIT_INT6        */
        uint32_t INT7          : 1;  /*!< bit:      7  ADCIOVFC_BIT_INT7        */
        uint32_t INT8          : 1;  /*!< bit:      8  ADCIOVFC_BIT_INT8        */
        uint32_t INT9          : 1;  /*!< bit:      9  ADCIOVFC_BIT_INT9        */
        uint32_t INT10         : 1;  /*!< bit:     10  ADCIOVFC_BIT_INT10       */
        uint32_t INT11         : 1;  /*!< bit:     11  ADCIOVFC_BIT_INT11       */
        uint32_t INT12         : 1;  /*!< bit:     12  ADCIOVFC_BIT_INT12       */
        uint32_t INT13         : 1;  /*!< bit:     13  ADCIOVFC_BIT_INT13       */
        uint32_t INT14         : 1;  /*!< bit:     14  ADCIOVFC_BIT_INT14       */
        uint32_t INT15         : 1;  /*!< bit:     15  ADCIOVFC_BIT_INT15       */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCIOVFC_REG;



/**
 *  @brief  Union type to access the ADC Interrupt Enable Register (ADCIE), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t INT0          : 1;  /*!< bit:      0  ADCIE_BIT_INT0           */
        uint32_t INT1          : 1;  /*!< bit:      1  ADCIE_BIT_INT1           */
        uint32_t INT2          : 1;  /*!< bit:      2  ADCIE_BIT_INT2           */
        uint32_t INT3          : 1;  /*!< bit:      3  ADCIE_BIT_INT3           */
        uint32_t INT4          : 1;  /*!< bit:      4  ADCIE_BIT_INT4           */
        uint32_t INT5          : 1;  /*!< bit:      5  ADCIE_BIT_INT5           */
        uint32_t INT6          : 1;  /*!< bit:      6  ADCIE_BIT_INT6           */
        uint32_t INT7          : 1;  /*!< bit:      7  ADCIE_BIT_INT7           */
        uint32_t INT8          : 1;  /*!< bit:      8  ADCIE_BIT_INT8           */
        uint32_t INT9          : 1;  /*!< bit:      9  ADCIE_BIT_INT9           */
        uint32_t INT10         : 1;  /*!< bit:     10  ADCIE_BIT_INT10          */
        uint32_t INT11         : 1;  /*!< bit:     11  ADCIE_BIT_INT11          */
        uint32_t INT12         : 1;  /*!< bit:     12  ADCIE_BIT_INT12          */
        uint32_t INT13         : 1;  /*!< bit:     13  ADCIE_BIT_INT13          */
        uint32_t INT14         : 1;  /*!< bit:     14  ADCIE_BIT_INT14          */
        uint32_t INT15         : 1;  /*!< bit:     15  ADCIE_BIT_INT15          */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCIE_REG;



/**
 *  @brief  Union type to access the ADC Start of Conversion Priority Control Register (ADCSOCPRICTL), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t PRIORITY      : 4;  /*!< bit:  3.. 0  ADCSOCPRICTL_BIT_PRIORITY*/
        uint32_t RESERVED_7_4  : 4;  /*!< bit:  7.. 4                           */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCSOCPRICTL_REG;



/**
 *  @brief  Union type to access the ADC SOC Flag Register (ADCSOCFLG), offset 0x18.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t SOC0          : 1;  /*!< bit:      0  ADCSOCFLG_BIT_SOC0       */
        uint32_t SOC1          : 1;  /*!< bit:      1  ADCSOCFLG_BIT_SOC1       */
        uint32_t SOC2          : 1;  /*!< bit:      2  ADCSOCFLG_BIT_SOC2       */
        uint32_t SOC3          : 1;  /*!< bit:      3  ADCSOCFLG_BIT_SOC3       */
        uint32_t SOC4          : 1;  /*!< bit:      4  ADCSOCFLG_BIT_SOC4       */
        uint32_t SOC5          : 1;  /*!< bit:      5  ADCSOCFLG_BIT_SOC5       */
        uint32_t SOC6          : 1;  /*!< bit:      6  ADCSOCFLG_BIT_SOC6       */
        uint32_t SOC7          : 1;  /*!< bit:      7  ADCSOCFLG_BIT_SOC7       */
        uint32_t SOC8          : 1;  /*!< bit:      8  ADCSOCFLG_BIT_SOC8       */
        uint32_t SOC9          : 1;  /*!< bit:      9  ADCSOCFLG_BIT_SOC9       */
        uint32_t SOC10         : 1;  /*!< bit:     10  ADCSOCFLG_BIT_SOC10      */
        uint32_t SOC11         : 1;  /*!< bit:     11  ADCSOCFLG_BIT_SOC11      */
        uint32_t SOC12         : 1;  /*!< bit:     12  ADCSOCFLG_BIT_SOC12      */
        uint32_t SOC13         : 1;  /*!< bit:     13  ADCSOCFLG_BIT_SOC13      */
        uint32_t SOC14         : 1;  /*!< bit:     14  ADCSOCFLG_BIT_SOC14      */
        uint32_t SOC15         : 1;  /*!< bit:     15  ADCSOCFLG_BIT_SOC15      */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCSOCFLG_REG;



/**
 *  @brief  Union type to access the ADC SOC Force Register (ADCSOCFRC), offset 0x1C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t SOC0          : 1;  /*!< bit:      0  ADCSOCFRC_BIT_SOC0       */
        uint32_t SOC1          : 1;  /*!< bit:      1  ADCSOCFRC_BIT_SOC1       */
        uint32_t SOC2          : 1;  /*!< bit:      2  ADCSOCFRC_BIT_SOC2       */
        uint32_t SOC3          : 1;  /*!< bit:      3  ADCSOCFRC_BIT_SOC3       */
        uint32_t SOC4          : 1;  /*!< bit:      4  ADCSOCFRC_BIT_SOC4       */
        uint32_t SOC5          : 1;  /*!< bit:      5  ADCSOCFRC_BIT_SOC5       */
        uint32_t SOC6          : 1;  /*!< bit:      6  ADCSOCFRC_BIT_SOC6       */
        uint32_t SOC7          : 1;  /*!< bit:      7  ADCSOCFRC_BIT_SOC7       */
        uint32_t SOC8          : 1;  /*!< bit:      8  ADCSOCFRC_BIT_SOC8       */
        uint32_t SOC9          : 1;  /*!< bit:      9  ADCSOCFRC_BIT_SOC9       */
        uint32_t SOC10         : 1;  /*!< bit:     10  ADCSOCFRC_BIT_SOC10      */
        uint32_t SOC11         : 1;  /*!< bit:     11  ADCSOCFRC_BIT_SOC11      */
        uint32_t SOC12         : 1;  /*!< bit:     12  ADCSOCFRC_BIT_SOC12      */
        uint32_t SOC13         : 1;  /*!< bit:     13  ADCSOCFRC_BIT_SOC13      */
        uint32_t SOC14         : 1;  /*!< bit:     14  ADCSOCFRC_BIT_SOC14      */
        uint32_t SOC15         : 1;  /*!< bit:     15  ADCSOCFRC_BIT_SOC15      */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCSOCFRC_REG;



/**
 *  @brief  Union type to access the ADC SOC Overflow Register (ADCSOCOVF), offset 0x20.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t SOC0          : 1;  /*!< bit:      0  ADCSOCOVF_BIT_SOC0       */
        uint32_t SOC1          : 1;  /*!< bit:      1  ADCSOCOVF_BIT_SOC1       */
        uint32_t SOC2          : 1;  /*!< bit:      2  ADCSOCOVF_BIT_SOC2       */
        uint32_t SOC3          : 1;  /*!< bit:      3  ADCSOCOVF_BIT_SOC3       */
        uint32_t SOC4          : 1;  /*!< bit:      4  ADCSOCOVF_BIT_SOC4       */
        uint32_t SOC5          : 1;  /*!< bit:      5  ADCSOCOVF_BIT_SOC5       */
        uint32_t SOC6          : 1;  /*!< bit:      6  ADCSOCOVF_BIT_SOC6       */
        uint32_t SOC7          : 1;  /*!< bit:      7  ADCSOCOVF_BIT_SOC7       */
        uint32_t SOC8          : 1;  /*!< bit:      8  ADCSOCOVF_BIT_SOC8       */
        uint32_t SOC9          : 1;  /*!< bit:      9  ADCSOCOVF_BIT_SOC9       */
        uint32_t SOC10         : 1;  /*!< bit:     10  ADCSOCOVF_BIT_SOC10      */
        uint32_t SOC11         : 1;  /*!< bit:     11  ADCSOCOVF_BIT_SOC11      */
        uint32_t SOC12         : 1;  /*!< bit:     12  ADCSOCOVF_BIT_SOC12      */
        uint32_t SOC13         : 1;  /*!< bit:     13  ADCSOCOVF_BIT_SOC13      */
        uint32_t SOC14         : 1;  /*!< bit:     14  ADCSOCOVF_BIT_SOC14      */
        uint32_t SOC15         : 1;  /*!< bit:     15  ADCSOCOVF_BIT_SOC15      */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCSOCOVF_REG;



/**
 *  @brief  Union type to access the ADC SOC Overflow Clear Register (ADCSOCOVFC), offset 0x24.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t SOC0          : 1;  /*!< bit:      0  ADCSOCOVFC_BIT_SOC0      */
        uint32_t SOC1          : 1;  /*!< bit:      1  ADCSOCOVFC_BIT_SOC1      */
        uint32_t SOC2          : 1;  /*!< bit:      2  ADCSOCOVFC_BIT_SOC2      */
        uint32_t SOC3          : 1;  /*!< bit:      3  ADCSOCOVFC_BIT_SOC3      */
        uint32_t SOC4          : 1;  /*!< bit:      4  ADCSOCOVFC_BIT_SOC4      */
        uint32_t SOC5          : 1;  /*!< bit:      5  ADCSOCOVFC_BIT_SOC5      */
        uint32_t SOC6          : 1;  /*!< bit:      6  ADCSOCOVFC_BIT_SOC6      */
        uint32_t SOC7          : 1;  /*!< bit:      7  ADCSOCOVFC_BIT_SOC7      */
        uint32_t SOC8          : 1;  /*!< bit:      8  ADCSOCOVFC_BIT_SOC8      */
        uint32_t SOC9          : 1;  /*!< bit:      9  ADCSOCOVFC_BIT_SOC9      */
        uint32_t SOC10         : 1;  /*!< bit:     10  ADCSOCOVFC_BIT_SOC10     */
        uint32_t SOC11         : 1;  /*!< bit:     11  ADCSOCOVFC_BIT_SOC11     */
        uint32_t SOC12         : 1;  /*!< bit:     12  ADCSOCOVFC_BIT_SOC12     */
        uint32_t SOC13         : 1;  /*!< bit:     13  ADCSOCOVFC_BIT_SOC13     */
        uint32_t SOC14         : 1;  /*!< bit:     14  ADCSOCOVFC_BIT_SOC14     */
        uint32_t SOC15         : 1;  /*!< bit:     15  ADCSOCOVFC_BIT_SOC15     */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCSOCOVFC_REG;



/**
 *  @brief  Union type to access the ADC Interrupt Trigger SOC Enable Register (ADCINTSOCEN), offset 0x28.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t SOC0          : 1;  /*!< bit:      0  ADCINTSOCEN_BIT_SOC0     */
        uint32_t SOC1          : 1;  /*!< bit:      1  ADCINTSOCEN_BIT_SOC1     */
        uint32_t SOC2          : 1;  /*!< bit:      2  ADCINTSOCEN_BIT_SOC2     */
        uint32_t SOC3          : 1;  /*!< bit:      3  ADCINTSOCEN_BIT_SOC3     */
        uint32_t SOC4          : 1;  /*!< bit:      4  ADCINTSOCEN_BIT_SOC4     */
        uint32_t SOC5          : 1;  /*!< bit:      5  ADCINTSOCEN_BIT_SOC5     */
        uint32_t SOC6          : 1;  /*!< bit:      6  ADCINTSOCEN_BIT_SOC6     */
        uint32_t SOC7          : 1;  /*!< bit:      7  ADCINTSOCEN_BIT_SOC7     */
        uint32_t SOC8          : 1;  /*!< bit:      8  ADCINTSOCEN_BIT_SOC8     */
        uint32_t SOC9          : 1;  /*!< bit:      9  ADCINTSOCEN_BIT_SOC9     */
        uint32_t SOC10         : 1;  /*!< bit:     10  ADCINTSOCEN_BIT_SOC10    */
        uint32_t SOC11         : 1;  /*!< bit:     11  ADCINTSOCEN_BIT_SOC11    */
        uint32_t SOC12         : 1;  /*!< bit:     12  ADCINTSOCEN_BIT_SOC12    */
        uint32_t SOC13         : 1;  /*!< bit:     13  ADCINTSOCEN_BIT_SOC13    */
        uint32_t SOC14         : 1;  /*!< bit:     14  ADCINTSOCEN_BIT_SOC14    */
        uint32_t SOC15         : 1;  /*!< bit:     15  ADCINTSOCEN_BIT_SOC15    */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCINTSOCEN_REG;



/**
 *  @brief  Union type to access the ADC Interrupt Trigger SOC Select Register 0 (ADCINTSOCSEL0), offset 0x2C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t SOC0          : 4;  /*!< bit:  3.. 0  ADCINTSOCSEL0_BIT_SOC0   */
        uint32_t SOC1          : 4;  /*!< bit:  7.. 4  ADCINTSOCSEL0_BIT_SOC1   */
        uint32_t SOC2          : 4;  /*!< bit: 11.. 8  ADCINTSOCSEL0_BIT_SOC2   */
        uint32_t SOC3          : 4;  /*!< bit: 15..12  ADCINTSOCSEL0_BIT_SOC3   */
        uint32_t SOC4          : 4;  /*!< bit: 19..16  ADCINTSOCSEL0_BIT_SOC4   */
        uint32_t SOC5          : 4;  /*!< bit: 23..20  ADCINTSOCSEL0_BIT_SOC5   */
        uint32_t SOC6          : 4;  /*!< bit: 27..24  ADCINTSOCSEL0_BIT_SOC6   */
        uint32_t SOC7          : 4;  /*!< bit: 31..28  ADCINTSOCSEL0_BIT_SOC7   */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCINTSOCSEL0_REG;



/**
 *  @brief  Union type to access the ADC Interrupt Trigger SOC Select Register 1 (ADCINTSOCSEL1), offset 0x30.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t SOC8          : 4;  /*!< bit:  3.. 0  ADCINTSOCSEL1_BIT_SOC8   */
        uint32_t SOC9          : 4;  /*!< bit:  7.. 4  ADCINTSOCSEL1_BIT_SOC9   */
        uint32_t SOC10         : 4;  /*!< bit: 11.. 8  ADCINTSOCSEL1_BIT_SOC10  */
        uint32_t SOC11         : 4;  /*!< bit: 15..12  ADCINTSOCSEL1_BIT_SOC11  */
        uint32_t SOC12         : 4;  /*!< bit: 19..16  ADCINTSOCSEL1_BIT_SOC12  */
        uint32_t SOC13         : 4;  /*!< bit: 23..20  ADCINTSOCSEL1_BIT_SOC13  */
        uint32_t SOC14         : 4;  /*!< bit: 27..24  ADCINTSOCSEL1_BIT_SOC14  */
        uint32_t SOC15         : 4;  /*!< bit: 31..28  ADCINTSOCSEL1_BIT_SOC15  */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCINTSOCSEL1_REG;



/**
 *  @brief  Union type to access the ADC External SOC Input Control Register (ADCEXTSOCCTL), offset 0x34.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t IOSEL         : 6;  /*!< bit:  5.. 0  ADCEXTSOCCTL_BIT_IOSEL   */
        uint32_t POL           : 1;  /*!< bit:      6  ADCEXTSOCCTL_BIT_POL     */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCEXTSOCCTL_REG;



/**
 *  @brief  Union type to access the ADC SOC0 Control Register (ADCSOCCTL0), offset 0x38.
            Union type to access the ADC SOC1 Control Register (ADCSOCCTL1), offset 0x3C.
            Union type to access the ADC SOC2 Control Register (ADCSOCCTL2), offset 0x40.
            ...
            Union type to access the ADC SOC14 Control Register (ADCSOCCTL14), offset 0x70.
            Union type to access the ADC SOC15 Control Register (ADCSOCCTL15), offset 0x74.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t SAMPCNT       : 8;  /*!< bit:  7.. 0  ADCSOCCTL0_BIT_SAMPCNT   
                                                       ADCSOCCTL1_BIT_SAMPCNT   
                                                       ADCSOCCTL2_BIT_SAMPCNT   
                                                       ...                      
                                                       ADCSOCCTL14_BIT_SAMPCNT  
                                                       ADCSOCCTL15_BIT_SAMPCNT  */
        uint32_t CONVCNT       : 7;  /*!< bit: 14.. 8  ADCSOCCTL0_BIT_CONVCNT   
                                                       ADCSOCCTL1_BIT_CONVCNT   
                                                       ADCSOCCTL2_BIT_CONVCNT   
                                                       ...                      
                                                       ADCSOCCTL14_BIT_CONVCNT  
                                                       ADCSOCCTL15_BIT_CONVCNT  */
        uint32_t AVGCNT        : 3;  /*!< bit: 17..15  ADCSOCCTL0_BIT_AVGCNT    
                                                       ADCSOCCTL1_BIT_AVGCNT    
                                                       ADCSOCCTL2_BIT_AVGCNT    
                                                       ...                      
                                                       ADCSOCCTL14_BIT_AVGCNT   
                                                       ADCSOCCTL15_BIT_AVGCNT   */
        uint32_t CHSELP        : 3;  /*!< bit: 20..18  ADCSOCCTL0_BIT_CHSELP    
                                                       ADCSOCCTL1_BIT_CHSELP    
                                                       ADCSOCCTL2_BIT_CHSELP    
                                                       ...                      
                                                       ADCSOCCTL14_BIT_CHSELP   
                                                       ADCSOCCTL15_BIT_CHSELP   */
        uint32_t CHSELN        : 3;  /*!< bit: 23..21  ADCSOCCTL0_BIT_CHSELN    
                                                       ADCSOCCTL1_BIT_CHSELN    
                                                       ADCSOCCTL2_BIT_CHSELN    
                                                       ...                      
                                                       ADCSOCCTL14_BIT_CHSELN   
                                                       ADCSOCCTL15_BIT_CHSELN   */
        uint32_t TRIGSEL       : 5;  /*!< bit: 28..24  ADCSOCCTL0_BIT_TRIGSEL   
                                                       ADCSOCCTL1_BIT_TRIGSEL   
                                                       ADCSOCCTL2_BIT_TRIGSEL   
                                                       ...                      
                                                       ADCSOCCTL14_BIT_TRIGSEL  
                                                       ADCSOCCTL15_BIT_TRIGSEL  */
        uint32_t SHEN          : 3;  /*!< bit: 31..29  ADCSOCCTL0_BIT_SHEN      
                                                       ADCSOCCTL1_BIT_SHEN      
                                                       ADCSOCCTL2_BIT_SHEN      
                                                       ...                      
                                                       ADCSOCCTL14_BIT_SHEN     
                                                       ADCSOCCTL15_BIT_SHEN     */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCSOCCTLx_REG;



/**
 *  @brief  Union type to access the ADC Offset Trim Register 0 (ADCOFFSET0), offset 0x78.
            Union type to access the ADC Offset Trim Register 1 (ADCOFFSET1), offset 0x7C.
            Union type to access the ADC Offset Trim Register 2 (ADCOFFSET2), offset 0x80.
            ...
            Union type to access the ADC Offset Trim Register 14 (ADCOFFSET14), offset 0xB0.
            Union type to access the ADC Offset Trim Register 15 (ADCOFFSET15), offset 0xB4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        int32_t  VAL           :32;  /*!< bit: 31.. 0  ADCOFFSET0_BIT_VAL       
                                                       ADCOFFSET1_BIT_VAL       
                                                       ADCOFFSET2_BIT_VAL       
                                                       ...                      
                                                       ADCOFFSET14_BIT_VAL      
                                                       ADCOFFSET15_BIT_VAL      */
    } bit;                           /*!< Structure used for bit  access        */
    int32_t  all;                    /*!< Type      used for word access        */
} ADCOFFSETx_REG;



/**
 *  @brief  Union type to access the ADC Gain Trim Register 0 (ADCGAIN0), offset 0xB8.
            Union type to access the ADC Gain Trim Register 1 (ADCGAIN1), offset 0xBC.
            Union type to access the ADC Gain Trim Register 2 (ADCGAIN2), offset 0xC0.
            ...
            Union type to access the ADC Gain Trim Register 14 (ADCGAIN14), offset 0xF0.
            Union type to access the ADC Gain Trim Register 15 (ADCGAIN15), offset 0xF4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  ADCGAIN0_BIT_VAL         
                                                       ADCGAIN1_BIT_VAL         
                                                       ADCGAIN2_BIT_VAL         
                                                       ...                      
                                                       ADCGAIN14_BIT_VAL        
                                                       ADCGAIN15_BIT_VAL        */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCGAINx_REG;



/**
 *  @brief  Union type to access the ADC SHA Offset Trim Register (ADCOFFSETA), offset 0xF8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        int32_t  VAL           :32;  /*!< bit: 31.. 0  ADCOFFSETA_BIT_VAL       */
    } bit;                           /*!< Structure used for bit  access        */
    int32_t  all;                    /*!< Type      used for word access        */
} ADCOFFSETA_REG;



/**
 *  @brief  Union type to access the ADC SHB Offset Trim Register (ADCOFFSETB), offset 0xFC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        int32_t  VAL           :32;  /*!< bit: 31.. 0  ADCOFFSETB_BIT_VAL       */
    } bit;                           /*!< Structure used for bit  access        */
    int32_t  all;                    /*!< Type      used for word access        */
} ADCOFFSETB_REG;



/**
 *  @brief  Union type to access the ADC SHC Offset Trim Register (ADCOFFSETC), offset 0x100.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        int32_t  VAL           :32;  /*!< bit: 31.. 0  ADCOFFSETC_BIT_VAL       */
    } bit;                           /*!< Structure used for bit  access        */
    int32_t  all;                    /*!< Type      used for word access        */
} ADCOFFSETC_REG;



/**
 *  @brief  Union type to access the ADC SHA Gain Trim Register (ADCGAINA), offset 0x104.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  ADCGAINA_BIT_VAL         */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCGAINA_REG;



/**
 *  @brief  Union type to access the ADC SHB Gain Trim Register (ADCGAINB), offset 0x108.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  ADCGAINB_BIT_VAL         */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCGAINB_REG;



/**
 *  @brief  Union type to access the ADC SHC Gain Trim Register (ADCGAINC), offset 0x10C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  ADCGAINC_BIT_VAL         */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCGAINC_REG;



/**
 *  @brief  Union type to access the ADC Status Register (ADCSTS), offset 0x110.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t CODEARDY      : 1;  /*!< bit:      0  ADCSTS_BIT_CODEARDY      */
        uint32_t CODEBRDY      : 1;  /*!< bit:      1  ADCSTS_BIT_CODEBRDY      */
        uint32_t CODECRDY      : 1;  /*!< bit:      2  ADCSTS_BIT_CODECRDY      */
        uint32_t RESERVED_31_3 :29;  /*!< bit: 31.. 3                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCSTS_REG;



/**
 *  @brief  Union type to access the ADC Status Clear Register (ADCSTSCLR), offset 0x114.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t CODEARDY      : 1;  /*!< bit:      0  ADCSTSCLR_BIT_CODEARDY   */
        uint32_t CODEBRDY      : 1;  /*!< bit:      1  ADCSTSCLR_BIT_CODEBRDY   */
        uint32_t CODECRDY      : 1;  /*!< bit:      2  ADCSTSCLR_BIT_CODECRDY   */
        uint32_t RESERVED_31_3 :29;  /*!< bit: 31.. 3                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCSTSCLR_REG;



/**
 *  @brief  Union type to access the ADC Control Register (ADCCTL), offset 0x118.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t EN            : 1;  /*!< bit:      0  ADCCTL_BIT_EN            */
        uint32_t RST           : 1;  /*!< bit:      1  ADCCTL_BIT_RST           */
        uint32_t SYNCEN        : 1;  /*!< bit:      2  ADCCTL_BIT_SYNCEN        */
        uint32_t SYNCEDGE      : 1;  /*!< bit:      3  ADCCTL_BIT_SYNCEDGE      */
        uint32_t TIEAP         : 2;  /*!< bit:  5.. 4  ADCCTL_BIT_TIEAP         */
        uint32_t TIEAN         : 2;  /*!< bit:  7.. 6  ADCCTL_BIT_TIEAN         */
        uint32_t TIEBP         : 2;  /*!< bit:  9.. 8  ADCCTL_BIT_TIEBP         */
        uint32_t TIEBN         : 2;  /*!< bit: 11..10  ADCCTL_BIT_TIEBN         */
        uint32_t TIECP         : 2;  /*!< bit: 13..12  ADCCTL_BIT_TIECP         */
        uint32_t TIECN         : 2;  /*!< bit: 15..14  ADCCTL_BIT_TIECN         */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCCTL_REG;



/**
 *  @brief  Union type to access the ADC Bandgap Control Register (ADCBGCTL), offset 0x11C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t EN            : 1;  /*!< bit:      0  ADCBGCTL_BIT_EN          */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCBGCTL_REG;



/**
 *  @brief  Union type to access the ADC Reference Control Register (ADCREFCTL), offset 0x120.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t EN            : 1;  /*!< bit:      0  ADCREFCTL_BIT_EN         */
        uint32_t EXTREF        : 1;  /*!< bit:      1  ADCREFCTL_BIT_EXTREF     */
        uint32_t VREFTRIM      : 5;  /*!< bit:  6.. 2  ADCREFCTL_BIT_VREFTRIM   */
        uint32_t VDIGTRIM      : 2;  /*!< bit:  8.. 7  ADCREFCTL_BIT_VDIGTRIM   */
        uint32_t VANATRIM      : 2;  /*!< bit: 10.. 9  ADCREFCTL_BIT_VANATRIM   */
        uint32_t VDDTRIM       : 4;  /*!< bit: 14..11  ADCREFCTL_BIT_VDDTRIM    */
        uint32_t RESERVED_31_15:17;  /*!< bit: 31..15                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCREFCTL_REG;



/**
 *  @brief  Union type to access the ADC SHA Raw Code Register (ADCRAWCODEA), offset 0x124.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  ADCRAWCODEA_BIT_VAL      */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCRAWCODEA_REG;



/**
 *  @brief  Union type to access the ADC SHB Raw Code Register (ADCRAWCODEB), offset 0x128.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  ADCRAWCODEB_BIT_VAL      */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCRAWCODEB_REG;



/**
 *  @brief  Union type to access the ADC SHC Raw Code Register (ADCRAWCODEC), offset 0x12C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  ADCRAWCODEC_BIT_VAL      */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCRAWCODEC_REG;



/**
 *  @brief  Union type to access the ADC Result Register 0 (ADCRESULT0), offset 0x130.
            Union type to access the ADC Result Register 1 (ADCRESULT1), offset 0x134.
            Union type to access the ADC Result Register 2 (ADCRESULT2), offset 0x138.
            ...
            Union type to access the ADC Result Register 14 (ADCRESULT14), offset 0x168.
            Union type to access the ADC Result Register 15 (ADCRESULT15), offset 0x16C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        int32_t  VAL           :32;  /*!< bit: 31.. 0  ADCRESULT0_BIT_VAL       
                                                       ADCRESULT1_BIT_VAL       
                                                       ADCRESULT2_BIT_VAL       
                                                       ...                      
                                                       ADCRESULT14_BIT_VAL      
                                                       ADCRESULT15_BIT_VAL      */
    } bit;                           /*!< Structure used for bit  access        */
    int32_t  all;                    /*!< Type      used for word access        */
} ADCRESULTx_REG;



/**
 *  @brief  Union type to access the ADCPPU0 Comparison Result Register (ADCPPURESULT0), offset 0x170.
            Union type to access the ADCPPU1 Comparison Result Register (ADCPPURESULT1), offset 0x174.
            Union type to access the ADCPPU2 Comparison Result Register (ADCPPURESULT2), offset 0x178.
            ...
            Union type to access the ADCPPU4 Comparison Result Register (ADCPPURESULT4), offset 0x180.
            Union type to access the ADCPPU5 Comparison Result Register (ADCPPURESULT5), offset 0x184.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        int32_t  VAL           :32;  /*!< bit: 31.. 0  ADCPPURESULT0_BIT_VAL    
                                                       ADCPPURESULT1_BIT_VAL    
                                                       ADCPPURESULT2_BIT_VAL    
                                                       ...                      
                                                       ADCPPURESULT4_BIT_VAL    
                                                       ADCPPURESULT5_BIT_VAL    */
    } bit;                           /*!< Structure used for bit  access        */
    int32_t  all;                    /*!< Type      used for word access        */
} ADCPPURESULTx_REG;



/**
 *  @brief  Union type to access the ADCPPU0 SOC Delay Register (ADCPPUSOCDLY0), offset 0x190.
            Union type to access the ADCPPU1 SOC Delay Register (ADCPPUSOCDLY1), offset 0x194.
            Union type to access the ADCPPU2 SOC Delay Register (ADCPPUSOCDLY2), offset 0x198.
            ...
            Union type to access the ADCPPU4 SOC Delay Register (ADCPPUSOCDLY4), offset 0x1A0.
            Union type to access the ADCPPU5 SOC Delay Register (ADCPPUSOCDLY5), offset 0x1A4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  ADCPPUSOCDLY0_BIT_VAL    
                                                       ADCPPUSOCDLY1_BIT_VAL    
                                                       ADCPPUSOCDLY2_BIT_VAL    
                                                       ...                      
                                                       ADCPPUSOCDLY4_BIT_VAL    
                                                       ADCPPUSOCDLY5_BIT_VAL    */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCPPUSOCDLYx_REG;



/**
 *  @brief  Union type to access the ADCPPU0 Interrupt Flag Register (ADCPPUIF0), offset 0x1B0.
            Union type to access the ADCPPU1 Interrupt Flag Register (ADCPPUIF1), offset 0x1B4.
            Union type to access the ADCPPU2 Interrupt Flag Register (ADCPPUIF2), offset 0x1B8.
            ...
            Union type to access the ADCPPU4 Interrupt Flag Register (ADCPPUIF4), offset 0x1C0.
            Union type to access the ADCPPU5 Interrupt Flag Register (ADCPPUIF5), offset 0x1C4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t TZLO          : 1;  /*!< bit:      0  ADCPPUIF0_BIT_TZLO       
                                                       ADCPPUIF1_BIT_TZLO       
                                                       ADCPPUIF2_BIT_TZLO       
                                                       ...                      
                                                       ADCPPUIF4_BIT_TZLO       
                                                       ADCPPUIF5_BIT_TZLO       */
        uint32_t TZHI          : 1;  /*!< bit:      1  ADCPPUIF0_BIT_TZHI       
                                                       ADCPPUIF1_BIT_TZHI       
                                                       ADCPPUIF2_BIT_TZHI       
                                                       ...                      
                                                       ADCPPUIF4_BIT_TZHI       
                                                       ADCPPUIF5_BIT_TZHI       */
        uint32_t XZRO          : 1;  /*!< bit:      2  ADCPPUIF0_BIT_XZRO       
                                                       ADCPPUIF1_BIT_XZRO       
                                                       ADCPPUIF2_BIT_XZRO       
                                                       ...                      
                                                       ADCPPUIF4_BIT_XZRO       
                                                       ADCPPUIF5_BIT_XZRO       */
        uint32_t INT           : 1;  /*!< bit:      3  ADCPPUIF0_BIT_INT        
                                                       ADCPPUIF1_BIT_INT        
                                                       ADCPPUIF2_BIT_INT        
                                                       ...                      
                                                       ADCPPUIF4_BIT_INT        
                                                       ADCPPUIF5_BIT_INT        */
        uint32_t RESERVED_31_4 :28;  /*!< bit: 31.. 4                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCPPUIFx_REG;



/**
 *  @brief  Union type to access the ADCPPU0 Interrupt Clear Register (ADCPPUIC0), offset 0x1D0.
            Union type to access the ADCPPU1 Interrupt Clear Register (ADCPPUIC1), offset 0x1D4.
            Union type to access the ADCPPU2 Interrupt Clear Register (ADCPPUIC2), offset 0x1D8.
            ...
            Union type to access the ADCPPU4 Interrupt Clear Register (ADCPPUIC4), offset 0x1E0.
            Union type to access the ADCPPU5 Interrupt Clear Register (ADCPPUIC5), offset 0x1E4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t TZLO          : 1;  /*!< bit:      0  ADCPPUIC0_BIT_TZLO       
                                                       ADCPPUIC1_BIT_TZLO       
                                                       ADCPPUIC2_BIT_TZLO       
                                                       ...                      
                                                       ADCPPUIC4_BIT_TZLO       
                                                       ADCPPUIC5_BIT_TZLO       */
        uint32_t TZHI          : 1;  /*!< bit:      1  ADCPPUIC0_BIT_TZHI       
                                                       ADCPPUIC1_BIT_TZHI       
                                                       ADCPPUIC2_BIT_TZHI       
                                                       ...                      
                                                       ADCPPUIC4_BIT_TZHI       
                                                       ADCPPUIC5_BIT_TZHI       */
        uint32_t XZRO          : 1;  /*!< bit:      2  ADCPPUIC0_BIT_XZRO       
                                                       ADCPPUIC1_BIT_XZRO       
                                                       ADCPPUIC2_BIT_XZRO       
                                                       ...                      
                                                       ADCPPUIC4_BIT_XZRO       
                                                       ADCPPUIC5_BIT_XZRO       */
        uint32_t INT           : 1;  /*!< bit:      3  ADCPPUIC0_BIT_INT        
                                                       ADCPPUIC1_BIT_INT        
                                                       ADCPPUIC2_BIT_INT        
                                                       ...                      
                                                       ADCPPUIC4_BIT_INT        
                                                       ADCPPUIC5_BIT_INT        */
        uint32_t RESERVED_31_4 :28;  /*!< bit: 31.. 4                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCPPUICx_REG;



/**
 *  @brief  Union type to access the ADCPPU0 Interrupt Enable Register (ADCPPUIE0), offset 0x1F0.
            Union type to access the ADCPPU1 Interrupt Enable Register (ADCPPUIE1), offset 0x1F4.
            Union type to access the ADCPPU2 Interrupt Enable Register (ADCPPUIE2), offset 0x1F8.
            ...
            Union type to access the ADCPPU4 Interrupt Enable Register (ADCPPUIE4), offset 0x200.
            Union type to access the ADCPPU5 Interrupt Enable Register (ADCPPUIE5), offset 0x204.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t TZLO          : 1;  /*!< bit:      0  ADCPPUIE0_BIT_TZLO       
                                                       ADCPPUIE1_BIT_TZLO       
                                                       ADCPPUIE2_BIT_TZLO       
                                                       ...                      
                                                       ADCPPUIE4_BIT_TZLO       
                                                       ADCPPUIE5_BIT_TZLO       */
        uint32_t TZHI          : 1;  /*!< bit:      1  ADCPPUIE0_BIT_TZHI       
                                                       ADCPPUIE1_BIT_TZHI       
                                                       ADCPPUIE2_BIT_TZHI       
                                                       ...                      
                                                       ADCPPUIE4_BIT_TZHI       
                                                       ADCPPUIE5_BIT_TZHI       */
        uint32_t XZRO          : 1;  /*!< bit:      2  ADCPPUIE0_BIT_XZRO       
                                                       ADCPPUIE1_BIT_XZRO       
                                                       ADCPPUIE2_BIT_XZRO       
                                                       ...                      
                                                       ADCPPUIE4_BIT_XZRO       
                                                       ADCPPUIE5_BIT_XZRO       */
        uint32_t RESERVED_31_3 :29;  /*!< bit: 31.. 3                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCPPUIEx_REG;



/**
 *  @brief  Union type to access the ADCPPU0 Trip-Zone Event Enable Register (ADCPPUTZE0), offset 0x210.
            Union type to access the ADCPPU1 Trip-Zone Event Enable Register (ADCPPUTZE1), offset 0x214.
            Union type to access the ADCPPU2 Trip-Zone Event Enable Register (ADCPPUTZE2), offset 0x218.
            ...
            Union type to access the ADCPPU4 Trip-Zone Event Enable Register (ADCPPUTZE4), offset 0x220.
            Union type to access the ADCPPU5 Trip-Zone Event Enable Register (ADCPPUTZE5), offset 0x224.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t TZLO          : 1;  /*!< bit:      0  ADCPPUTZE0_BIT_TZLO      
                                                       ADCPPUTZE1_BIT_TZLO      
                                                       ADCPPUTZE2_BIT_TZLO      
                                                       ...                      
                                                       ADCPPUTZE4_BIT_TZLO      
                                                       ADCPPUTZE5_BIT_TZLO      */
        uint32_t TZHI          : 1;  /*!< bit:      1  ADCPPUTZE0_BIT_TZHI      
                                                       ADCPPUTZE1_BIT_TZHI      
                                                       ADCPPUTZE2_BIT_TZHI      
                                                       ...                      
                                                       ADCPPUTZE4_BIT_TZHI      
                                                       ADCPPUTZE5_BIT_TZHI      */
        uint32_t XZRO          : 1;  /*!< bit:      2  ADCPPUTZE0_BIT_XZRO      
                                                       ADCPPUTZE1_BIT_XZRO      
                                                       ADCPPUTZE2_BIT_XZRO      
                                                       ...                      
                                                       ADCPPUTZE4_BIT_XZRO      
                                                       ADCPPUTZE5_BIT_XZRO      */
        uint32_t RESERVED_31_3 :29;  /*!< bit: 31.. 3                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCPPUTZEx_REG;



/**
 *  @brief  Union type to access the ADCPPU0 Control Register (ADCPPUCTL0), offset 0x230.
            Union type to access the ADCPPU1 Control Register (ADCPPUCTL1), offset 0x234.
            Union type to access the ADCPPU2 Control Register (ADCPPUCTL2), offset 0x238.
            ...
            Union type to access the ADCPPU4 Control Register (ADCPPUCTL4), offset 0x240.
            Union type to access the ADCPPU5 Control Register (ADCPPUCTL5), offset 0x244.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t EN            : 1;  /*!< bit:      0  ADCPPUCTL0_BIT_EN        
                                                       ADCPPUCTL1_BIT_EN        
                                                       ADCPPUCTL2_BIT_EN        
                                                       ...                      
                                                       ADCPPUCTL4_BIT_EN        
                                                       ADCPPUCTL5_BIT_EN        */
        uint32_t CBCEN         : 1;  /*!< bit:      1  ADCPPUCTL0_BIT_CBCEN     
                                                       ADCPPUCTL1_BIT_CBCEN     
                                                       ADCPPUCTL2_BIT_CBCEN     
                                                       ...                      
                                                       ADCPPUCTL4_BIT_CBCEN     
                                                       ADCPPUCTL5_BIT_CBCEN     */
        uint32_t SOCSEL        : 4;  /*!< bit:  5.. 2  ADCPPUCTL0_BIT_SOCSEL    
                                                       ADCPPUCTL1_BIT_SOCSEL    
                                                       ADCPPUCTL2_BIT_SOCSEL    
                                                       ...                      
                                                       ADCPPUCTL4_BIT_SOCSEL    
                                                       ADCPPUCTL5_BIT_SOCSEL    */
        uint32_t DATASEL       : 4;  /*!< bit:  9.. 6  ADCPPUCTL0_BIT_DATASEL   
                                                       ADCPPUCTL1_BIT_DATASEL   
                                                       ADCPPUCTL2_BIT_DATASEL   
                                                       ...                      
                                                       ADCPPUCTL4_BIT_DATASEL   
                                                       ADCPPUCTL5_BIT_DATASEL   */
        uint32_t POL           : 1;  /*!< bit:     10  ADCPPUCTL0_BIT_POL       
                                                       ADCPPUCTL1_BIT_POL       
                                                       ADCPPUCTL2_BIT_POL       
                                                       ...                      
                                                       ADCPPUCTL4_BIT_POL       
                                                       ADCPPUCTL5_BIT_POL       */
        uint32_t RESERVED_31_11:21;  /*!< bit: 31..11                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCPPUCTLx_REG;



/**
 *  @brief  Union type to access the ADCPPU0 Reference Register (ADCPPUREF0), offset 0x250.
            Union type to access the ADCPPU1 Reference Register (ADCPPUREF1), offset 0x254.
            Union type to access the ADCPPU2 Reference Register (ADCPPUREF2), offset 0x258.
            ...
            Union type to access the ADCPPU4 Reference Register (ADCPPUREF4), offset 0x260.
            Union type to access the ADCPPU5 Reference Register (ADCPPUREF5), offset 0x264.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        int32_t  VAL           :32;  /*!< bit: 31.. 0  ADCPPUREF0_BIT_VAL       
                                                       ADCPPUREF1_BIT_VAL       
                                                       ADCPPUREF2_BIT_VAL       
                                                       ...                      
                                                       ADCPPUREF4_BIT_VAL       
                                                       ADCPPUREF5_BIT_VAL       */
    } bit;                           /*!< Structure used for bit  access        */
    int32_t  all;                    /*!< Type      used for word access        */
} ADCPPUREFx_REG;



/**
 *  @brief  Union type to access the ADCPPU0 Trip-Zone High-Side Threshold Register (ADCPPUTHH0), offset 0x270.
            Union type to access the ADCPPU1 Trip-Zone High-Side Threshold Register (ADCPPUTHH1), offset 0x274.
            Union type to access the ADCPPU2 Trip-Zone High-Side Threshold Register (ADCPPUTHH2), offset 0x278.
            ...
            Union type to access the ADCPPU4 Trip-Zone High-Side Threshold Register (ADCPPUTHH4), offset 0x280.
            Union type to access the ADCPPU5 Trip-Zone High-Side Threshold Register (ADCPPUTHH5), offset 0x284.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        int32_t  VAL           :32;  /*!< bit: 31.. 0  ADCPPUTHH0_BIT_VAL       
                                                       ADCPPUTHH1_BIT_VAL       
                                                       ADCPPUTHH2_BIT_VAL       
                                                       ...                      
                                                       ADCPPUTHH4_BIT_VAL       
                                                       ADCPPUTHH5_BIT_VAL       */
    } bit;                           /*!< Structure used for bit  access        */
    int32_t  all;                    /*!< Type      used for word access        */
} ADCPPUTHHx_REG;



/**
 *  @brief  Union type to access the ADCPPU0 Trip-Zone Low-Side Threshold Register (ADCPPUTHL0), offset 0x290.
            Union type to access the ADCPPU1 Trip-Zone Low-Side Threshold Register (ADCPPUTHL1), offset 0x294.
            Union type to access the ADCPPU2 Trip-Zone Low-Side Threshold Register (ADCPPUTHL2), offset 0x298.
            ...
            Union type to access the ADCPPU4 Trip-Zone Low-Side Threshold Register (ADCPPUTHL4), offset 0x2A0.
            Union type to access the ADCPPU5 Trip-Zone Low-Side Threshold Register (ADCPPUTHL5), offset 0x2A4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        int32_t  VAL           :32;  /*!< bit: 31.. 0  ADCPPUTHL0_BIT_VAL       
                                                       ADCPPUTHL1_BIT_VAL       
                                                       ADCPPUTHL2_BIT_VAL       
                                                       ...                      
                                                       ADCPPUTHL4_BIT_VAL       
                                                       ADCPPUTHL5_BIT_VAL       */
    } bit;                           /*!< Structure used for bit  access        */
    int32_t  all;                    /*!< Type      used for word access        */
} ADCPPUTHLx_REG;



/**
 *  @brief  Union type to access the Temperature Sensor Control Register (TSENSCTL), offset 0x2B0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t EN            : 1;  /*!< bit:      0  TSENSCTL_BIT_EN          */
        uint32_t OUTINV        : 1;  /*!< bit:      1  TSENSCTL_BIT_OUTINV      */
        uint32_t SWAPBJT       : 1;  /*!< bit:      2  TSENSCTL_BIT_SWAPBJT     */
        uint32_t DEMSEL        : 4;  /*!< bit:  6.. 3  TSENSCTL_BIT_DEMSEL      */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} TSENSCTL_REG;



/**
 *  @brief  Union type to access the ADC Register Write-Allow Key Register (ADCREGKEY), offset 0x2B4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t KEY           :32;  /*!< bit: 31.. 0  ADCREGKEY_BIT_KEY        */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ADCREGKEY_REG;



/**
  *  @brief  Structure type to access the ADC Controller (ADC).
  */
typedef struct
{
    __I  ADCIF_REG               ADCIF                    ; /*!< Offset: 0x00000000 (RO  )  ADC Interrupt Flag Register                        */
    __O  ADCIC_REG               ADCIC                    ; /*!< Offset: 0x00000004 (WO  )  ADC Interrupt Flag Clear Register                  */
    __I  ADCIOVF_REG             ADCIOVF                  ; /*!< Offset: 0x00000008 (RO  )  ADC Interrupt Overflow Flag Register               */
    __O  ADCIOVFC_REG            ADCIOVFC                 ; /*!< Offset: 0x0000000C (WO  )  ADC Interrupt Overflow Flag Clear Register         */
    __IO ADCIE_REG               ADCIE                    ; /*!< Offset: 0x00000010 (RW  )  ADC Interrupt Enable Register                      */
    __IO ADCSOCPRICTL_REG        ADCSOCPRICTL             ; /*!< Offset: 0x00000014 (RW  )  ADC Start of Conversion Priority Control Register  */
    __I  ADCSOCFLG_REG           ADCSOCFLG                ; /*!< Offset: 0x00000018 (RO  )  ADC SOC Flag Register                              */
    __O  ADCSOCFRC_REG           ADCSOCFRC                ; /*!< Offset: 0x0000001C (WO  )  ADC SOC Force Register                             */
    __I  ADCSOCOVF_REG           ADCSOCOVF                ; /*!< Offset: 0x00000020 (RO  )  ADC SOC Overflow Register                          */
    __O  ADCSOCOVFC_REG          ADCSOCOVFC               ; /*!< Offset: 0x00000024 (WO  )  ADC SOC Overflow Clear Register                    */
    __IO ADCINTSOCEN_REG         ADCINTSOCEN              ; /*!< Offset: 0x00000028 (RW  )  ADC Interrupt Trigger SOC Enable Register          */
    __IO ADCINTSOCSEL0_REG       ADCINTSOCSEL0            ; /*!< Offset: 0x0000002C (RW  )  ADC Interrupt Trigger SOC Select Register 0        */
    __IO ADCINTSOCSEL1_REG       ADCINTSOCSEL1            ; /*!< Offset: 0x00000030 (RW  )  ADC Interrupt Trigger SOC Select Register 1        */
    __IO ADCEXTSOCCTL_REG        ADCEXTSOCCTL             ; /*!< Offset: 0x00000034 (RW  )  ADC External SOC Input Control Register            */
    __IO ADCSOCCTLx_REG          ADCSOCCTL[16]            ; /*!< Offset: 0x00000038 (RW  )  ADC SOC0 Control Register                          */
    __IO ADCOFFSETx_REG          ADCOFFSET[16]            ; /*!< Offset: 0x00000078 (RW  )  ADC Offset Trim Register 0                         */
    __IO ADCGAINx_REG            ADCGAIN[16]              ; /*!< Offset: 0x000000B8 (RW  )  ADC Gain Trim Register 0                           */
    __IO ADCOFFSETA_REG          ADCOFFSETA               ; /*!< Offset: 0x000000F8 (RW  )  ADC SHA Offset Trim Register                       */
    __IO ADCOFFSETB_REG          ADCOFFSETB               ; /*!< Offset: 0x000000FC (RW  )  ADC SHB Offset Trim Register                       */
    __IO ADCOFFSETC_REG          ADCOFFSETC               ; /*!< Offset: 0x00000100 (RW  )  ADC SHC Offset Trim Register                       */
    __IO ADCGAINA_REG            ADCGAINA                 ; /*!< Offset: 0x00000104 (RW  )  ADC SHA Gain Trim Register                         */
    __IO ADCGAINB_REG            ADCGAINB                 ; /*!< Offset: 0x00000108 (RW  )  ADC SHB Gain Trim Register                         */
    __IO ADCGAINC_REG            ADCGAINC                 ; /*!< Offset: 0x0000010C (RW  )  ADC SHC Gain Trim Register                         */
    __I  ADCSTS_REG              ADCSTS                   ; /*!< Offset: 0x00000110 (RO  )  ADC Status Register                                */
    __O  ADCSTSCLR_REG           ADCSTSCLR                ; /*!< Offset: 0x00000114 (WO  )  ADC Status Clear Register                          */
    __IO ADCCTL_REG              ADCCTL                   ; /*!< Offset: 0x00000118 (RW  )  ADC Control Register                               */
    __IO ADCBGCTL_REG            ADCBGCTL                 ; /*!< Offset: 0x0000011C (RW  )  ADC Bandgap Control Register                       */
    __IO ADCREFCTL_REG           ADCREFCTL                ; /*!< Offset: 0x00000120 (RW  )  ADC Reference Control Register                     */
    __I  ADCRAWCODEA_REG         ADCRAWCODEA              ; /*!< Offset: 0x00000124 (RO  )  ADC SHA Raw Code Register                          */
    __I  ADCRAWCODEB_REG         ADCRAWCODEB              ; /*!< Offset: 0x00000128 (RO  )  ADC SHB Raw Code Register                          */
    __I  ADCRAWCODEC_REG         ADCRAWCODEC              ; /*!< Offset: 0x0000012C (RO  )  ADC SHC Raw Code Register                          */
    __I  ADCRESULTx_REG          ADCRESULT[16]            ; /*!< Offset: 0x00000130 (RO  )  ADC Result Register 0                              */
    __I  ADCPPURESULTx_REG       ADCPPURESULT[6]          ; /*!< Offset: 0x00000170 (RO  )  ADCPPU0 Comparison Result Register                 */
         uint32_t                RESERVED0[2]             ; 
    __I  ADCPPUSOCDLYx_REG       ADCPPUSOCDLY[6]          ; /*!< Offset: 0x00000190 (RO  )  ADCPPU0 SOC Delay Register                         */
         uint32_t                RESERVED1[2]             ; 
    __I  ADCPPUIFx_REG           ADCPPUIF[6]              ; /*!< Offset: 0x000001B0 (RO  )  ADCPPU0 Interrupt Flag Register                    */
         uint32_t                RESERVED2[2]             ; 
    __O  ADCPPUICx_REG           ADCPPUIC[6]              ; /*!< Offset: 0x000001D0 (WO  )  ADCPPU0 Interrupt Clear Register                   */
         uint32_t                RESERVED3[2]             ; 
    __IO ADCPPUIEx_REG           ADCPPUIE[6]              ; /*!< Offset: 0x000001F0 (RW  )  ADCPPU0 Interrupt Enable Register                  */
         uint32_t                RESERVED4[2]             ; 
    __IO ADCPPUTZEx_REG          ADCPPUTZE[6]             ; /*!< Offset: 0x00000210 (RW  )  ADCPPU0 Trip-Zone Event Enable Register            */
         uint32_t                RESERVED5[2]             ; 
    __IO ADCPPUCTLx_REG          ADCPPUCTL[6]             ; /*!< Offset: 0x00000230 (RW  )  ADCPPU0 Control Register                           */
         uint32_t                RESERVED6[2]             ; 
    __IO ADCPPUREFx_REG          ADCPPUREF[6]             ; /*!< Offset: 0x00000250 (RW  )  ADCPPU0 Reference Register                         */
         uint32_t                RESERVED7[2]             ; 
    __IO ADCPPUTHHx_REG          ADCPPUTHH[6]             ; /*!< Offset: 0x00000270 (RW  )  ADCPPU0 Trip-Zone High-Side Threshold Register     */
         uint32_t                RESERVED8[2]             ; 
    __IO ADCPPUTHLx_REG          ADCPPUTHL[6]             ; /*!< Offset: 0x00000290 (RW  )  ADCPPU0 Trip-Zone Low-Side Threshold Register      */
         uint32_t                RESERVED9[2]             ; 
    __IO TSENSCTL_REG            TSENSCTL                 ; /*!< Offset: 0x000002B0 (RW  )  Temperature Sensor Control Register                */
    __IO ADCREGKEY_REG           ADCREGKEY                ; /*!< Offset: 0x000002B4 (RW  )  ADC Register Write-Allow Key Register              */
} ADC_REGS;



/********************************************************************************
*
* Module Name     PWM
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the Shadow Status Register (SHADOWSTS), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t TBPRD         : 1;  /*!< bit:      0  SHADOWSTS_BIT_TBPRD      */
        uint32_t CMPA          : 1;  /*!< bit:      1  SHADOWSTS_BIT_CMPA       */
        uint32_t CMPB          : 1;  /*!< bit:      2  SHADOWSTS_BIT_CMPB       */
        uint32_t CMPC          : 1;  /*!< bit:      3  SHADOWSTS_BIT_CMPC       */
        uint32_t CMPD          : 1;  /*!< bit:      4  SHADOWSTS_BIT_CMPD       */
        uint32_t AQCTLA        : 1;  /*!< bit:      5  SHADOWSTS_BIT_AQCTLA     */
        uint32_t AQCTLB        : 1;  /*!< bit:      6  SHADOWSTS_BIT_AQCTLB     */
        uint32_t AQCSFRC       : 1;  /*!< bit:      7  SHADOWSTS_BIT_AQCSFRC    */
        uint32_t DBCTL         : 1;  /*!< bit:      8  SHADOWSTS_BIT_DBCTL      */
        uint32_t DBRED         : 1;  /*!< bit:      9  SHADOWSTS_BIT_DBRED      */
        uint32_t DBFED         : 1;  /*!< bit:     10  SHADOWSTS_BIT_DBFED      */
        uint32_t RESERVED_31_11:21;  /*!< bit: 31..11                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} SHADOWSTS_REG;



/**
 *  @brief  Union type to access the Global Shadow to Active Load Control Register 0 (GLDCTL0), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t GLDEN         : 1;  /*!< bit:      0  GLDCTL0_BIT_GLDEN        */
        uint32_t GLDLOAD       : 3;  /*!< bit:  3.. 1  GLDCTL0_BIT_GLDLOAD      */
        uint32_t GLDPRD        : 4;  /*!< bit:  7.. 4  GLDCTL0_BIT_GLDPRD       */
        uint32_t GLDCNT        : 4;  /*!< bit: 11.. 8  GLDCTL0_BIT_GLDCNT       */
        uint32_t OSTMODE       : 1;  /*!< bit:     12  GLDCTL0_BIT_OSTMODE      */
        uint32_t RESERVED_31_13:19;  /*!< bit: 31..13                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} GLDCTL0_REG;



/**
 *  @brief  Union type to access the Global Shadow to Active Load Control Register 1 (GLDCTL1), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t OSTLOAD       : 1;  /*!< bit:      0  GLDCTL1_BIT_OSTLOAD      */
        uint32_t FRCLOAD       : 1;  /*!< bit:      1  GLDCTL1_BIT_FRCLOAD      */
        uint32_t RESERVED_31_2 :30;  /*!< bit: 31.. 2                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} GLDCTL1_REG;



/**
 *  @brief  Union type to access the Global Shadow to Active Load Select Register (GLDSEL), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t TBPRD         : 1;  /*!< bit:      0  GLDSEL_BIT_TBPRD         */
        uint32_t CMPA          : 1;  /*!< bit:      1  GLDSEL_BIT_CMPA          */
        uint32_t CMPB          : 1;  /*!< bit:      2  GLDSEL_BIT_CMPB          */
        uint32_t CMPC          : 1;  /*!< bit:      3  GLDSEL_BIT_CMPC          */
        uint32_t CMPD          : 1;  /*!< bit:      4  GLDSEL_BIT_CMPD          */
        uint32_t AQCTLA        : 1;  /*!< bit:      5  GLDSEL_BIT_AQCTLA        */
        uint32_t AQCTLB        : 1;  /*!< bit:      6  GLDSEL_BIT_AQCTLB        */
        uint32_t AQCSFRC       : 1;  /*!< bit:      7  GLDSEL_BIT_AQCSFRC       */
        uint32_t DBCTL         : 1;  /*!< bit:      8  GLDSEL_BIT_DBCTL         */
        uint32_t DBRED         : 1;  /*!< bit:      9  GLDSEL_BIT_DBRED         */
        uint32_t DBFED         : 1;  /*!< bit:     10  GLDSEL_BIT_DBFED         */
        uint32_t RESERVED_31_11:21;  /*!< bit: 31..11                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} GLDSEL_REG;



/**
 *  @brief  Union type to access the PWM Link Control Register (PWMLINK), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t TBPRD         : 4;  /*!< bit:  3.. 0  PWMLINK_BIT_TBPRD        */
        uint32_t CMPA          : 4;  /*!< bit:  7.. 4  PWMLINK_BIT_CMPA         */
        uint32_t CMPB          : 4;  /*!< bit: 11.. 8  PWMLINK_BIT_CMPB         */
        uint32_t CMPC          : 4;  /*!< bit: 15..12  PWMLINK_BIT_CMPC         */
        uint32_t CMPD          : 4;  /*!< bit: 19..16  PWMLINK_BIT_CMPD         */
        uint32_t DBRED         : 4;  /*!< bit: 23..20  PWMLINK_BIT_DBRED        */
        uint32_t DBFED         : 4;  /*!< bit: 27..24  PWMLINK_BIT_DBFED        */
        uint32_t GLDCTL1       : 4;  /*!< bit: 31..28  PWMLINK_BIT_GLDCTL1      */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} PWMLINK_REG;



/**
 *  @brief  Union type to access the Time-Base Control Register (TBCTL), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t CNTRUN        : 1;  /*!< bit:      0  TBCTL_BIT_CNTRUN         */
        uint32_t CNTMODE       : 2;  /*!< bit:  2.. 1  TBCTL_BIT_CNTMODE        */
        uint32_t PHSEN         : 1;  /*!< bit:      3  TBCTL_BIT_PHSEN          */
        uint32_t PHSDIR        : 1;  /*!< bit:      4  TBCTL_BIT_PHSDIR         */
        uint32_t TBPRDLOAD     : 2;  /*!< bit:  6.. 5  TBCTL_BIT_TBPRDLOAD      */
        uint32_t TBPRDLOCK     : 1;  /*!< bit:      7  TBCTL_BIT_TBPRDLOCK      */
        uint32_t SYNCOSEL      : 3;  /*!< bit: 10.. 8  TBCTL_BIT_SYNCOSEL       */
        uint32_t FRCSYNC       : 1;  /*!< bit:     11  TBCTL_BIT_FRCSYNC        */
        uint32_t TBDIVLIN      : 3;  /*!< bit: 14..12  TBCTL_BIT_TBDIVLIN       */
        uint32_t TBDIVBIN      : 3;  /*!< bit: 17..15  TBCTL_BIT_TBDIVBIN       */
        uint32_t DBGRUN        : 2;  /*!< bit: 19..18  TBCTL_BIT_DBGRUN         */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} TBCTL_REG;



/**
 *  @brief  Union type to access the Time-Base Period Register (TBPRD), offset 0x18.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  TBPRD_BIT_VAL            */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} TBPRD_REG;



/**
 *  @brief  Union type to access the Time-Base Period Active Register (TBPRDA), offset 0x1C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  TBPRDA_BIT_VAL           */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} TBPRDA_REG;



/**
 *  @brief  Union type to access the Time-Base Phase Register (TBPHS), offset 0x20.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  TBPHS_BIT_VAL            */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} TBPHS_REG;



/**
 *  @brief  Union type to access the Time-Base Counter Register (TBCNT), offset 0x24.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  TBCNT_BIT_VAL            */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} TBCNT_REG;



/**
 *  @brief  Union type to access the Time-Base Status Register (TBSTS), offset 0x28.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t SYNCI         : 1;  /*!< bit:      0  TBSTS_BIT_SYNCI          */
        uint32_t CNTMAX        : 1;  /*!< bit:      1  TBSTS_BIT_CNTMAX         */
        uint32_t CNTZRO        : 1;  /*!< bit:      2  TBSTS_BIT_CNTZRO         */
        uint32_t CNTPRD        : 1;  /*!< bit:      3  TBSTS_BIT_CNTPRD         */
        uint32_t CNTCMPA       : 1;  /*!< bit:      4  TBSTS_BIT_CNTCMPA        */
        uint32_t CNTCMPB       : 1;  /*!< bit:      5  TBSTS_BIT_CNTCMPB        */
        uint32_t CNTCMPC       : 1;  /*!< bit:      6  TBSTS_BIT_CNTCMPC        */
        uint32_t CNTCMPD       : 1;  /*!< bit:      7  TBSTS_BIT_CNTCMPD        */
        uint32_t CNTDIR        : 1;  /*!< bit:      8  TBSTS_BIT_CNTDIR         */
        uint32_t RESERVED_31_9 :23;  /*!< bit: 31.. 9                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} TBSTS_REG;



/**
 *  @brief  Union type to access the Time-Base Status Clear Register (TBSTSCLR), offset 0x2C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t SYNCI         : 1;  /*!< bit:      0  TBSTSCLR_BIT_SYNCI       */
        uint32_t CNTMAX        : 1;  /*!< bit:      1  TBSTSCLR_BIT_CNTMAX      */
        uint32_t CNTZRO        : 1;  /*!< bit:      2  TBSTSCLR_BIT_CNTZRO      */
        uint32_t CNTPRD        : 1;  /*!< bit:      3  TBSTSCLR_BIT_CNTPRD      */
        uint32_t CNTCMPA       : 1;  /*!< bit:      4  TBSTSCLR_BIT_CNTCMPA     */
        uint32_t CNTCMPB       : 1;  /*!< bit:      5  TBSTSCLR_BIT_CNTCMPB     */
        uint32_t CNTCMPC       : 1;  /*!< bit:      6  TBSTSCLR_BIT_CNTCMPC     */
        uint32_t CNTCMPD       : 1;  /*!< bit:      7  TBSTSCLR_BIT_CNTCMPD     */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} TBSTSCLR_REG;



/**
 *  @brief  Union type to access the Counter-Compare Control Register (CMPCTL), offset 0x30.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t CMPALOAD      : 3;  /*!< bit:  2.. 0  CMPCTL_BIT_CMPALOAD      */
        uint32_t CMPALOCK      : 1;  /*!< bit:      3  CMPCTL_BIT_CMPALOCK      */
        uint32_t CMPBLOAD      : 3;  /*!< bit:  6.. 4  CMPCTL_BIT_CMPBLOAD      */
        uint32_t CMPBLOCK      : 1;  /*!< bit:      7  CMPCTL_BIT_CMPBLOCK      */
        uint32_t CMPCLOAD      : 3;  /*!< bit: 10.. 8  CMPCTL_BIT_CMPCLOAD      */
        uint32_t CMPCLOCK      : 1;  /*!< bit:     11  CMPCTL_BIT_CMPCLOCK      */
        uint32_t CMPDLOAD      : 3;  /*!< bit: 14..12  CMPCTL_BIT_CMPDLOAD      */
        uint32_t CMPDLOCK      : 1;  /*!< bit:     15  CMPCTL_BIT_CMPDLOCK      */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} CMPCTL_REG;



/**
 *  @brief  Union type to access the Counter-Compare A Threshold Register (CMPA), offset 0x34.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  CMPA_BIT_VAL             */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} CMPA_REG;



/**
 *  @brief  Union type to access the Counter-Compare A Threshold Active Register (CMPAA), offset 0x38.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  CMPAA_BIT_VAL            */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} CMPAA_REG;



/**
 *  @brief  Union type to access the Counter-Compare B Threshold Register (CMPB), offset 0x3C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  CMPB_BIT_VAL             */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} CMPB_REG;



/**
 *  @brief  Union type to access the Counter-Compare B Threshold Active Register (CMPBA), offset 0x40.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  CMPBA_BIT_VAL            */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} CMPBA_REG;



/**
 *  @brief  Union type to access the Counter-Compare C Threshold Register (CMPC), offset 0x44.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  CMPC_BIT_VAL             */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} CMPC_REG;



/**
 *  @brief  Union type to access the Counter-Compare C Threshold Active Register (CMPCA), offset 0x48.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  CMPCA_BIT_VAL            */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} CMPCA_REG;



/**
 *  @brief  Union type to access the Counter-Compare D Threshold Register (CMPD), offset 0x4C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  CMPD_BIT_VAL             */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} CMPD_REG;



/**
 *  @brief  Union type to access the Counter-Compare D Threshold Active Register (CMPDA), offset 0x50.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  CMPDA_BIT_VAL            */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} CMPDA_REG;



/**
 *  @brief  Union type to access the Action-Qualifier Control Register (AQCTL), offset 0x54.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t AQCTLALOAD    : 3;  /*!< bit:  2.. 0  AQCTL_BIT_AQCTLALOAD     */
        uint32_t AQCTLALOCK    : 1;  /*!< bit:      3  AQCTL_BIT_AQCTLALOCK     */
        uint32_t AQCTLBLOAD    : 3;  /*!< bit:  6.. 4  AQCTL_BIT_AQCTLBLOAD     */
        uint32_t AQCTLBLOCK    : 1;  /*!< bit:      7  AQCTL_BIT_AQCTLBLOCK     */
        uint32_t T0SEL         : 4;  /*!< bit: 11.. 8  AQCTL_BIT_T0SEL          */
        uint32_t T1SEL         : 4;  /*!< bit: 15..12  AQCTL_BIT_T1SEL          */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} AQCTL_REG;



/**
 *  @brief  Union type to access the Action-Qualifier Output A Control Register (AQCTLA), offset 0x58.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t ZRO           : 2;  /*!< bit:  1.. 0  AQCTLA_BIT_ZRO           */
        uint32_t PRD           : 2;  /*!< bit:  3.. 2  AQCTLA_BIT_PRD           */
        uint32_t CAU           : 2;  /*!< bit:  5.. 4  AQCTLA_BIT_CAU           */
        uint32_t CAD           : 2;  /*!< bit:  7.. 6  AQCTLA_BIT_CAD           */
        uint32_t CBU           : 2;  /*!< bit:  9.. 8  AQCTLA_BIT_CBU           */
        uint32_t CBD           : 2;  /*!< bit: 11..10  AQCTLA_BIT_CBD           */
        uint32_t T0U           : 2;  /*!< bit: 13..12  AQCTLA_BIT_T0U           */
        uint32_t T0D           : 2;  /*!< bit: 15..14  AQCTLA_BIT_T0D           */
        uint32_t T1U           : 2;  /*!< bit: 17..16  AQCTLA_BIT_T1U           */
        uint32_t T1D           : 2;  /*!< bit: 19..18  AQCTLA_BIT_T1D           */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} AQCTLA_REG;



/**
 *  @brief  Union type to access the Action-Qualifier Output A Control Active Register (AQCTLAA), offset 0x5C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t ZRO           : 2;  /*!< bit:  1.. 0  AQCTLAA_BIT_ZRO          */
        uint32_t PRD           : 2;  /*!< bit:  3.. 2  AQCTLAA_BIT_PRD          */
        uint32_t CAU           : 2;  /*!< bit:  5.. 4  AQCTLAA_BIT_CAU          */
        uint32_t CAD           : 2;  /*!< bit:  7.. 6  AQCTLAA_BIT_CAD          */
        uint32_t CBU           : 2;  /*!< bit:  9.. 8  AQCTLAA_BIT_CBU          */
        uint32_t CBD           : 2;  /*!< bit: 11..10  AQCTLAA_BIT_CBD          */
        uint32_t T0U           : 2;  /*!< bit: 13..12  AQCTLAA_BIT_T0U          */
        uint32_t T0D           : 2;  /*!< bit: 15..14  AQCTLAA_BIT_T0D          */
        uint32_t T1U           : 2;  /*!< bit: 17..16  AQCTLAA_BIT_T1U          */
        uint32_t T1D           : 2;  /*!< bit: 19..18  AQCTLAA_BIT_T1D          */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} AQCTLAA_REG;



/**
 *  @brief  Union type to access the Action-Qualifier Output B Control Register (AQCTLB), offset 0x60.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t ZRO           : 2;  /*!< bit:  1.. 0  AQCTLB_BIT_ZRO           */
        uint32_t PRD           : 2;  /*!< bit:  3.. 2  AQCTLB_BIT_PRD           */
        uint32_t CAU           : 2;  /*!< bit:  5.. 4  AQCTLB_BIT_CAU           */
        uint32_t CAD           : 2;  /*!< bit:  7.. 6  AQCTLB_BIT_CAD           */
        uint32_t CBU           : 2;  /*!< bit:  9.. 8  AQCTLB_BIT_CBU           */
        uint32_t CBD           : 2;  /*!< bit: 11..10  AQCTLB_BIT_CBD           */
        uint32_t T0U           : 2;  /*!< bit: 13..12  AQCTLB_BIT_T0U           */
        uint32_t T0D           : 2;  /*!< bit: 15..14  AQCTLB_BIT_T0D           */
        uint32_t T1U           : 2;  /*!< bit: 17..16  AQCTLB_BIT_T1U           */
        uint32_t T1D           : 2;  /*!< bit: 19..18  AQCTLB_BIT_T1D           */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} AQCTLB_REG;



/**
 *  @brief  Union type to access the Action-Qualifier Output B Control Active Register (AQCTLBA), offset 0x64.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t ZRO           : 2;  /*!< bit:  1.. 0  AQCTLBA_BIT_ZRO          */
        uint32_t PRD           : 2;  /*!< bit:  3.. 2  AQCTLBA_BIT_PRD          */
        uint32_t CAU           : 2;  /*!< bit:  5.. 4  AQCTLBA_BIT_CAU          */
        uint32_t CAD           : 2;  /*!< bit:  7.. 6  AQCTLBA_BIT_CAD          */
        uint32_t CBU           : 2;  /*!< bit:  9.. 8  AQCTLBA_BIT_CBU          */
        uint32_t CBD           : 2;  /*!< bit: 11..10  AQCTLBA_BIT_CBD          */
        uint32_t T0U           : 2;  /*!< bit: 13..12  AQCTLBA_BIT_T0U          */
        uint32_t T0D           : 2;  /*!< bit: 15..14  AQCTLBA_BIT_T0D          */
        uint32_t T1U           : 2;  /*!< bit: 17..16  AQCTLBA_BIT_T1U          */
        uint32_t T1D           : 2;  /*!< bit: 19..18  AQCTLBA_BIT_T1D          */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} AQCTLBA_REG;



/**
 *  @brief  Union type to access the Action-Qualifier Software Force Register (AQSFRC), offset 0x68.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t ACTSFA        : 2;  /*!< bit:  1.. 0  AQSFRC_BIT_ACTSFA        */
        uint32_t OTSFA         : 1;  /*!< bit:      2  AQSFRC_BIT_OTSFA         */
        uint32_t ACTSFB        : 2;  /*!< bit:  4.. 3  AQSFRC_BIT_ACTSFB        */
        uint32_t OTSFB         : 1;  /*!< bit:      5  AQSFRC_BIT_OTSFB         */
        uint32_t CSFLOAD       : 2;  /*!< bit:  7.. 6  AQSFRC_BIT_CSFLOAD       */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} AQSFRC_REG;



/**
 *  @brief  Union type to access the Action-Qualifier Continuous Software Force Register (AQCSFRC), offset 0x6C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t CSFA          : 2;  /*!< bit:  1.. 0  AQCSFRC_BIT_CSFA         */
        uint32_t CSFB          : 2;  /*!< bit:  3.. 2  AQCSFRC_BIT_CSFB         */
        uint32_t RESERVED_31_4 :28;  /*!< bit: 31.. 4                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} AQCSFRC_REG;



/**
 *  @brief  Union type to access the Action-Qualifier Continuous Software Force Active Register (AQCSFRCA), offset 0x70.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t CSFA          : 2;  /*!< bit:  1.. 0  AQCSFRCA_BIT_CSFA        */
        uint32_t CSFB          : 2;  /*!< bit:  3.. 2  AQCSFRCA_BIT_CSFB        */
        uint32_t RESERVED_31_4 :28;  /*!< bit: 31.. 4                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} AQCSFRCA_REG;



/**
 *  @brief  Union type to access the Dead-Band Generator Control Register (DBCTL), offset 0x74.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t REDEN         : 1;  /*!< bit:      0  DBCTL_BIT_REDEN          */
        uint32_t FEDEN         : 1;  /*!< bit:      1  DBCTL_BIT_FEDEN          */
        uint32_t REDSRC        : 1;  /*!< bit:      2  DBCTL_BIT_REDSRC         */
        uint32_t FEDSRC        : 1;  /*!< bit:      3  DBCTL_BIT_FEDSRC         */
        uint32_t REDPOL        : 1;  /*!< bit:      4  DBCTL_BIT_REDPOL         */
        uint32_t FEDPOL        : 1;  /*!< bit:      5  DBCTL_BIT_FEDPOL         */
        uint32_t OUTASRC       : 1;  /*!< bit:      6  DBCTL_BIT_OUTASRC        */
        uint32_t OUTBSRC       : 1;  /*!< bit:      7  DBCTL_BIT_OUTBSRC        */
        uint32_t DUALEDGE      : 1;  /*!< bit:      8  DBCTL_BIT_DUALEDGE       */
        uint32_t HALFCYCLE     : 1;  /*!< bit:      9  DBCTL_BIT_HALFCYCLE      */
        uint32_t DBCTLLOAD     : 2;  /*!< bit: 11..10  DBCTL_BIT_DBCTLLOAD      */
        uint32_t DBCTLLOCK     : 1;  /*!< bit:     12  DBCTL_BIT_DBCTLLOCK      */
        uint32_t DBREDLOAD     : 2;  /*!< bit: 14..13  DBCTL_BIT_DBREDLOAD      */
        uint32_t DBREDLOCK     : 1;  /*!< bit:     15  DBCTL_BIT_DBREDLOCK      */
        uint32_t DBFEDLOAD     : 2;  /*!< bit: 17..16  DBCTL_BIT_DBFEDLOAD      */
        uint32_t DBFEDLOCK     : 1;  /*!< bit:     18  DBCTL_BIT_DBFEDLOCK      */
        uint32_t RESERVED_31_19:13;  /*!< bit: 31..19                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} DBCTL_REG;



/**
 *  @brief  Union type to access the Dead-Band Generator Control Active Register (DBCTLA), offset 0x78.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t REDEN         : 1;  /*!< bit:      0  DBCTLA_BIT_REDEN         */
        uint32_t FEDEN         : 1;  /*!< bit:      1  DBCTLA_BIT_FEDEN         */
        uint32_t REDSRC        : 1;  /*!< bit:      2  DBCTLA_BIT_REDSRC        */
        uint32_t FEDSRC        : 1;  /*!< bit:      3  DBCTLA_BIT_FEDSRC        */
        uint32_t REDPOL        : 1;  /*!< bit:      4  DBCTLA_BIT_REDPOL        */
        uint32_t FEDPOL        : 1;  /*!< bit:      5  DBCTLA_BIT_FEDPOL        */
        uint32_t OUTASRC       : 1;  /*!< bit:      6  DBCTLA_BIT_OUTASRC       */
        uint32_t OUTBSRC       : 1;  /*!< bit:      7  DBCTLA_BIT_OUTBSRC       */
        uint32_t DUALEDGE      : 1;  /*!< bit:      8  DBCTLA_BIT_DUALEDGE      */
        uint32_t HALFCYCLE     : 1;  /*!< bit:      9  DBCTLA_BIT_HALFCYCLE     */
        uint32_t RESERVED_31_10:22;  /*!< bit: 31..10                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} DBCTLA_REG;



/**
 *  @brief  Union type to access the Dead-Band Generator Rising Edge Delay Register (DBRED), offset 0x7C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  DBRED_BIT_VAL            */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} DBRED_REG;



/**
 *  @brief  Union type to access the Dead-Band Generator Rising Edge Delay Active Register (DBREDA), offset 0x80.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  DBREDA_BIT_VAL           */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} DBREDA_REG;



/**
 *  @brief  Union type to access the Dead-Band Generator Falling Edge Delay Register (DBFED), offset 0x84.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  DBFED_BIT_VAL            */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} DBFED_REG;



/**
 *  @brief  Union type to access the Dead-Band Generator Falling Edge Delay Active Register (DBFEDA), offset 0x88.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  DBFEDA_BIT_VAL           */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} DBFEDA_REG;



/**
 *  @brief  Union type to access the Trip-Zone Event Select Register (TZSEL), offset 0x8C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t OSTOUT        : 2;  /*!< bit:  1.. 0  TZSEL_BIT_OSTOUT         */
        uint32_t TZ0OST        : 1;  /*!< bit:      2  TZSEL_BIT_TZ0OST         */
        uint32_t TZ1OST        : 1;  /*!< bit:      3  TZSEL_BIT_TZ1OST         */
        uint32_t TZ2OST        : 1;  /*!< bit:      4  TZSEL_BIT_TZ2OST         */
        uint32_t TZ3OST        : 1;  /*!< bit:      5  TZSEL_BIT_TZ3OST         */
        uint32_t TZ4OST        : 1;  /*!< bit:      6  TZSEL_BIT_TZ4OST         */
        uint32_t CLKERROST     : 1;  /*!< bit:      7  TZSEL_BIT_CLKERROST      */
        uint32_t DCAEVT0       : 1;  /*!< bit:      8  TZSEL_BIT_DCAEVT0        */
        uint32_t DCBEVT0       : 1;  /*!< bit:      9  TZSEL_BIT_DCBEVT0        */
        uint32_t DBGOST        : 1;  /*!< bit:     10  TZSEL_BIT_DBGOST         */
        uint32_t RESERVED_15_11: 5;  /*!< bit: 15..11                           */
        uint32_t CBCOUT        : 2;  /*!< bit: 17..16  TZSEL_BIT_CBCOUT         */
        uint32_t TZ0CBC        : 1;  /*!< bit:     18  TZSEL_BIT_TZ0CBC         */
        uint32_t TZ1CBC        : 1;  /*!< bit:     19  TZSEL_BIT_TZ1CBC         */
        uint32_t TZ2CBC        : 1;  /*!< bit:     20  TZSEL_BIT_TZ2CBC         */
        uint32_t TZ3CBC        : 1;  /*!< bit:     21  TZSEL_BIT_TZ3CBC         */
        uint32_t TZ4CBC        : 1;  /*!< bit:     22  TZSEL_BIT_TZ4CBC         */
        uint32_t CLKERRCBC     : 1;  /*!< bit:     23  TZSEL_BIT_CLKERRCBC      */
        uint32_t DCAEVT1       : 1;  /*!< bit:     24  TZSEL_BIT_DCAEVT1        */
        uint32_t DCBEVT1       : 1;  /*!< bit:     25  TZSEL_BIT_DCBEVT1        */
        uint32_t DBGCBC        : 1;  /*!< bit:     26  TZSEL_BIT_DBGCBC         */
        uint32_t RESERVED_31_27: 5;  /*!< bit: 31..27                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} TZSEL_REG;



/**
 *  @brief  Union type to access the Trip-Zone Status Register (TZSTS), offset 0x90.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t TZ0OST        : 1;  /*!< bit:      0  TZSTS_BIT_TZ0OST         */
        uint32_t TZ1OST        : 1;  /*!< bit:      1  TZSTS_BIT_TZ1OST         */
        uint32_t TZ2OST        : 1;  /*!< bit:      2  TZSTS_BIT_TZ2OST         */
        uint32_t TZ3OST        : 1;  /*!< bit:      3  TZSTS_BIT_TZ3OST         */
        uint32_t TZ4OST        : 1;  /*!< bit:      4  TZSTS_BIT_TZ4OST         */
        uint32_t CLKERROST     : 1;  /*!< bit:      5  TZSTS_BIT_CLKERROST      */
        uint32_t DCAEVT0       : 1;  /*!< bit:      6  TZSTS_BIT_DCAEVT0        */
        uint32_t DCBEVT0       : 1;  /*!< bit:      7  TZSTS_BIT_DCBEVT0        */
        uint32_t DBGOST        : 1;  /*!< bit:      8  TZSTS_BIT_DBGOST         */
        uint32_t TZ0CBC        : 1;  /*!< bit:      9  TZSTS_BIT_TZ0CBC         */
        uint32_t TZ1CBC        : 1;  /*!< bit:     10  TZSTS_BIT_TZ1CBC         */
        uint32_t TZ2CBC        : 1;  /*!< bit:     11  TZSTS_BIT_TZ2CBC         */
        uint32_t TZ3CBC        : 1;  /*!< bit:     12  TZSTS_BIT_TZ3CBC         */
        uint32_t TZ4CBC        : 1;  /*!< bit:     13  TZSTS_BIT_TZ4CBC         */
        uint32_t CLKERRCBC     : 1;  /*!< bit:     14  TZSTS_BIT_CLKERRCBC      */
        uint32_t DCAEVT1       : 1;  /*!< bit:     15  TZSTS_BIT_DCAEVT1        */
        uint32_t DCBEVT1       : 1;  /*!< bit:     16  TZSTS_BIT_DCBEVT1        */
        uint32_t DBGCBC        : 1;  /*!< bit:     17  TZSTS_BIT_DBGCBC         */
        uint32_t RESERVED_31_18:14;  /*!< bit: 31..18                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} TZSTS_REG;



/**
 *  @brief  Union type to access the Trip-Zone Status Clear Register (TZSTSCLR), offset 0x94.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t TZ0OST        : 1;  /*!< bit:      0  TZSTSCLR_BIT_TZ0OST      */
        uint32_t TZ1OST        : 1;  /*!< bit:      1  TZSTSCLR_BIT_TZ1OST      */
        uint32_t TZ2OST        : 1;  /*!< bit:      2  TZSTSCLR_BIT_TZ2OST      */
        uint32_t TZ3OST        : 1;  /*!< bit:      3  TZSTSCLR_BIT_TZ3OST      */
        uint32_t TZ4OST        : 1;  /*!< bit:      4  TZSTSCLR_BIT_TZ4OST      */
        uint32_t CLKERROST     : 1;  /*!< bit:      5  TZSTSCLR_BIT_CLKERROST   */
        uint32_t DCAEVT0       : 1;  /*!< bit:      6  TZSTSCLR_BIT_DCAEVT0     */
        uint32_t DCBEVT0       : 1;  /*!< bit:      7  TZSTSCLR_BIT_DCBEVT0     */
        uint32_t DBGOST        : 1;  /*!< bit:      8  TZSTSCLR_BIT_DBGOST      */
        uint32_t TZ0CBC        : 1;  /*!< bit:      9  TZSTSCLR_BIT_TZ0CBC      */
        uint32_t TZ1CBC        : 1;  /*!< bit:     10  TZSTSCLR_BIT_TZ1CBC      */
        uint32_t TZ2CBC        : 1;  /*!< bit:     11  TZSTSCLR_BIT_TZ2CBC      */
        uint32_t TZ3CBC        : 1;  /*!< bit:     12  TZSTSCLR_BIT_TZ3CBC      */
        uint32_t TZ4CBC        : 1;  /*!< bit:     13  TZSTSCLR_BIT_TZ4CBC      */
        uint32_t CLKERRCBC     : 1;  /*!< bit:     14  TZSTSCLR_BIT_CLKERRCBC   */
        uint32_t DCAEVT1       : 1;  /*!< bit:     15  TZSTSCLR_BIT_DCAEVT1     */
        uint32_t DCBEVT1       : 1;  /*!< bit:     16  TZSTSCLR_BIT_DCBEVT1     */
        uint32_t DBGCBC        : 1;  /*!< bit:     17  TZSTSCLR_BIT_DBGCBC      */
        uint32_t RESERVED_31_18:14;  /*!< bit: 31..18                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} TZSTSCLR_REG;



/**
 *  @brief  Union type to access the Trip-Zone Digital Compare Event Select Register (TZDCSEL), offset 0x98.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t DCAEVT0       : 3;  /*!< bit:  2.. 0  TZDCSEL_BIT_DCAEVT0      */
        uint32_t DCAEVT1       : 3;  /*!< bit:  5.. 3  TZDCSEL_BIT_DCAEVT1      */
        uint32_t DCBEVT0       : 3;  /*!< bit:  8.. 6  TZDCSEL_BIT_DCBEVT0      */
        uint32_t DCBEVT1       : 3;  /*!< bit: 11.. 9  TZDCSEL_BIT_DCBEVT1      */
        uint32_t RESERVED_31_12:20;  /*!< bit: 31..12                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} TZDCSEL_REG;



/**
 *  @brief  Union type to access the Trip-Zone Output A Control Register (TZACTL), offset 0x9C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t TZAU          : 3;  /*!< bit:  2.. 0  TZACTL_BIT_TZAU          */
        uint32_t TZAD          : 3;  /*!< bit:  5.. 3  TZACTL_BIT_TZAD          */
        uint32_t DCAEVT0U      : 3;  /*!< bit:  8.. 6  TZACTL_BIT_DCAEVT0U      */
        uint32_t DCAEVT0D      : 3;  /*!< bit: 11.. 9  TZACTL_BIT_DCAEVT0D      */
        uint32_t DCAEVT1U      : 3;  /*!< bit: 14..12  TZACTL_BIT_DCAEVT1U      */
        uint32_t DCAEVT1D      : 3;  /*!< bit: 17..15  TZACTL_BIT_DCAEVT1D      */
        uint32_t RESERVED_31_18:14;  /*!< bit: 31..18                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} TZACTL_REG;



/**
 *  @brief  Union type to access the Trip-Zone Ouput B Control Register (TZBCTL), offset 0xA0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t TZBU          : 3;  /*!< bit:  2.. 0  TZBCTL_BIT_TZBU          */
        uint32_t TZBD          : 3;  /*!< bit:  5.. 3  TZBCTL_BIT_TZBD          */
        uint32_t DCBEVT0U      : 3;  /*!< bit:  8.. 6  TZBCTL_BIT_DCBEVT0U      */
        uint32_t DCBEVT0D      : 3;  /*!< bit: 11.. 9  TZBCTL_BIT_DCBEVT0D      */
        uint32_t DCBEVT1U      : 3;  /*!< bit: 14..12  TZBCTL_BIT_DCBEVT1U      */
        uint32_t DCBEVT1D      : 3;  /*!< bit: 17..15  TZBCTL_BIT_DCBEVT1D      */
        uint32_t RESERVED_31_18:14;  /*!< bit: 31..18                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} TZBCTL_REG;



/**
 *  @brief  Union type to access the Trip-Zone Flag Register (TZIF), offset 0xA4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t OST           : 1;  /*!< bit:      0  TZIF_BIT_OST             */
        uint32_t CBC           : 1;  /*!< bit:      1  TZIF_BIT_CBC             */
        uint32_t DCAEVT0       : 1;  /*!< bit:      2  TZIF_BIT_DCAEVT0         */
        uint32_t DCAEVT1       : 1;  /*!< bit:      3  TZIF_BIT_DCAEVT1         */
        uint32_t DCBEVT0       : 1;  /*!< bit:      4  TZIF_BIT_DCBEVT0         */
        uint32_t DCBEVT1       : 1;  /*!< bit:      5  TZIF_BIT_DCBEVT1         */
        uint32_t INT           : 1;  /*!< bit:      6  TZIF_BIT_INT             */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} TZIF_REG;



/**
 *  @brief  Union type to access the Trip-Zone Clear Register (TZIC), offset 0xA8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t OST           : 1;  /*!< bit:      0  TZIC_BIT_OST             */
        uint32_t CBC           : 1;  /*!< bit:      1  TZIC_BIT_CBC             */
        uint32_t DCAEVT0       : 1;  /*!< bit:      2  TZIC_BIT_DCAEVT0         */
        uint32_t DCAEVT1       : 1;  /*!< bit:      3  TZIC_BIT_DCAEVT1         */
        uint32_t DCBEVT0       : 1;  /*!< bit:      4  TZIC_BIT_DCBEVT0         */
        uint32_t DCBEVT1       : 1;  /*!< bit:      5  TZIC_BIT_DCBEVT1         */
        uint32_t INT           : 1;  /*!< bit:      6  TZIC_BIT_INT             */
        uint32_t CBCCLRMODE    : 2;  /*!< bit:  8.. 7  TZIC_BIT_CBCCLRMODE      */
        uint32_t RESERVED_31_9 :23;  /*!< bit: 31.. 9                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} TZIC_REG;



/**
 *  @brief  Union type to access the Trip-Zone Interrupt Enable Register (TZIE), offset 0xAC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t OST           : 1;  /*!< bit:      0  TZIE_BIT_OST             */
        uint32_t CBC           : 1;  /*!< bit:      1  TZIE_BIT_CBC             */
        uint32_t DCAEVT0       : 1;  /*!< bit:      2  TZIE_BIT_DCAEVT0         */
        uint32_t DCAEVT1       : 1;  /*!< bit:      3  TZIE_BIT_DCAEVT1         */
        uint32_t DCBEVT0       : 1;  /*!< bit:      4  TZIE_BIT_DCBEVT0         */
        uint32_t DCBEVT1       : 1;  /*!< bit:      5  TZIE_BIT_DCBEVT1         */
        uint32_t RESERVED_31_6 :26;  /*!< bit: 31.. 6                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} TZIE_REG;



/**
 *  @brief  Union type to access the Trip-Zone Force Register (TZFRC), offset 0xB0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t OST           : 1;  /*!< bit:      0  TZFRC_BIT_OST            */
        uint32_t CBC           : 1;  /*!< bit:      1  TZFRC_BIT_CBC            */
        uint32_t DCAEVT0       : 1;  /*!< bit:      2  TZFRC_BIT_DCAEVT0        */
        uint32_t DCAEVT1       : 1;  /*!< bit:      3  TZFRC_BIT_DCAEVT1        */
        uint32_t DCBEVT0       : 1;  /*!< bit:      4  TZFRC_BIT_DCBEVT0        */
        uint32_t DCBEVT1       : 1;  /*!< bit:      5  TZFRC_BIT_DCBEVT1        */
        uint32_t RESERVED_31_6 :26;  /*!< bit: 31.. 6                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} TZFRC_REG;



/**
 *  @brief  Union type to access the Digital Compare AL Trip Select Register (DCALTRIPSEL), offset 0xB4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t TZ0           : 1;  /*!< bit:      0  DCALTRIPSEL_BIT_TZ0      */
        uint32_t TZ1           : 1;  /*!< bit:      1  DCALTRIPSEL_BIT_TZ1      */
        uint32_t TZ2           : 1;  /*!< bit:      2  DCALTRIPSEL_BIT_TZ2      */
        uint32_t TZ3           : 1;  /*!< bit:      3  DCALTRIPSEL_BIT_TZ3      */
        uint32_t TZ4           : 1;  /*!< bit:      4  DCALTRIPSEL_BIT_TZ4      */
        uint32_t EPWRTZ0       : 1;  /*!< bit:      5  DCALTRIPSEL_BIT_EPWRTZ0  */
        uint32_t EPWRTZ1       : 1;  /*!< bit:      6  DCALTRIPSEL_BIT_EPWRTZ1  */
        uint32_t RESERVED_7_7  : 1;  /*!< bit:      7                           */
        uint32_t ADCPPU0TZ     : 1;  /*!< bit:      8  DCALTRIPSEL_BIT_ADCPPU0TZ*/
        uint32_t ADCPPU1TZ     : 1;  /*!< bit:      9  DCALTRIPSEL_BIT_ADCPPU1TZ*/
        uint32_t ADCPPU2TZ     : 1;  /*!< bit:     10  DCALTRIPSEL_BIT_ADCPPU2TZ*/
        uint32_t ADCPPU3TZ     : 1;  /*!< bit:     11  DCALTRIPSEL_BIT_ADCPPU3TZ*/
        uint32_t ADCPPU4TZ     : 1;  /*!< bit:     12  DCALTRIPSEL_BIT_ADCPPU4TZ*/
        uint32_t ADCPPU5TZ     : 1;  /*!< bit:     13  DCALTRIPSEL_BIT_ADCPPU5TZ*/
        uint32_t RESERVED_15_14: 2;  /*!< bit: 15..14                           */
        uint32_t COMP0L        : 1;  /*!< bit:     16  DCALTRIPSEL_BIT_COMP0L   */
        uint32_t COMP0H        : 1;  /*!< bit:     17  DCALTRIPSEL_BIT_COMP0H   */
        uint32_t COMP1L        : 1;  /*!< bit:     18  DCALTRIPSEL_BIT_COMP1L   */
        uint32_t COMP1H        : 1;  /*!< bit:     19  DCALTRIPSEL_BIT_COMP1H   */
        uint32_t COMP2L        : 1;  /*!< bit:     20  DCALTRIPSEL_BIT_COMP2L   */
        uint32_t COMP2H        : 1;  /*!< bit:     21  DCALTRIPSEL_BIT_COMP2H   */
        uint32_t COMP3L        : 1;  /*!< bit:     22  DCALTRIPSEL_BIT_COMP3L   */
        uint32_t COMP3H        : 1;  /*!< bit:     23  DCALTRIPSEL_BIT_COMP3H   */
        uint32_t COMP4L        : 1;  /*!< bit:     24  DCALTRIPSEL_BIT_COMP4L   */
        uint32_t COMP4H        : 1;  /*!< bit:     25  DCALTRIPSEL_BIT_COMP4H   */
        uint32_t RESERVED_31_26: 6;  /*!< bit: 31..26                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} DCALTRIPSEL_REG;



/**
 *  @brief  Union type to access the Digital Compare AH Trip Select Register (DCAHTRIPSEL), offset 0xB8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t TZ0           : 1;  /*!< bit:      0  DCAHTRIPSEL_BIT_TZ0      */
        uint32_t TZ1           : 1;  /*!< bit:      1  DCAHTRIPSEL_BIT_TZ1      */
        uint32_t TZ2           : 1;  /*!< bit:      2  DCAHTRIPSEL_BIT_TZ2      */
        uint32_t TZ3           : 1;  /*!< bit:      3  DCAHTRIPSEL_BIT_TZ3      */
        uint32_t TZ4           : 1;  /*!< bit:      4  DCAHTRIPSEL_BIT_TZ4      */
        uint32_t EPWRTZ0       : 1;  /*!< bit:      5  DCAHTRIPSEL_BIT_EPWRTZ0  */
        uint32_t EPWRTZ1       : 1;  /*!< bit:      6  DCAHTRIPSEL_BIT_EPWRTZ1  */
        uint32_t RESERVED_7_7  : 1;  /*!< bit:      7                           */
        uint32_t ADCPPU0TZ     : 1;  /*!< bit:      8  DCAHTRIPSEL_BIT_ADCPPU0TZ*/
        uint32_t ADCPPU1TZ     : 1;  /*!< bit:      9  DCAHTRIPSEL_BIT_ADCPPU1TZ*/
        uint32_t ADCPPU2TZ     : 1;  /*!< bit:     10  DCAHTRIPSEL_BIT_ADCPPU2TZ*/
        uint32_t ADCPPU3TZ     : 1;  /*!< bit:     11  DCAHTRIPSEL_BIT_ADCPPU3TZ*/
        uint32_t ADCPPU4TZ     : 1;  /*!< bit:     12  DCAHTRIPSEL_BIT_ADCPPU4TZ*/
        uint32_t ADCPPU5TZ     : 1;  /*!< bit:     13  DCAHTRIPSEL_BIT_ADCPPU5TZ*/
        uint32_t RESERVED_15_14: 2;  /*!< bit: 15..14                           */
        uint32_t COMP0L        : 1;  /*!< bit:     16  DCAHTRIPSEL_BIT_COMP0L   */
        uint32_t COMP0H        : 1;  /*!< bit:     17  DCAHTRIPSEL_BIT_COMP0H   */
        uint32_t COMP1L        : 1;  /*!< bit:     18  DCAHTRIPSEL_BIT_COMP1L   */
        uint32_t COMP1H        : 1;  /*!< bit:     19  DCAHTRIPSEL_BIT_COMP1H   */
        uint32_t COMP2L        : 1;  /*!< bit:     20  DCAHTRIPSEL_BIT_COMP2L   */
        uint32_t COMP2H        : 1;  /*!< bit:     21  DCAHTRIPSEL_BIT_COMP2H   */
        uint32_t COMP3L        : 1;  /*!< bit:     22  DCAHTRIPSEL_BIT_COMP3L   */
        uint32_t COMP3H        : 1;  /*!< bit:     23  DCAHTRIPSEL_BIT_COMP3H   */
        uint32_t COMP4L        : 1;  /*!< bit:     24  DCAHTRIPSEL_BIT_COMP4L   */
        uint32_t COMP4H        : 1;  /*!< bit:     25  DCAHTRIPSEL_BIT_COMP4H   */
        uint32_t RESERVED_31_26: 6;  /*!< bit: 31..26                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} DCAHTRIPSEL_REG;



/**
 *  @brief  Union type to access the Digital Compare BL Trip Select Register (DCBLTRIPSEL), offset 0xBC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t TZ0           : 1;  /*!< bit:      0  DCBLTRIPSEL_BIT_TZ0      */
        uint32_t TZ1           : 1;  /*!< bit:      1  DCBLTRIPSEL_BIT_TZ1      */
        uint32_t TZ2           : 1;  /*!< bit:      2  DCBLTRIPSEL_BIT_TZ2      */
        uint32_t TZ3           : 1;  /*!< bit:      3  DCBLTRIPSEL_BIT_TZ3      */
        uint32_t TZ4           : 1;  /*!< bit:      4  DCBLTRIPSEL_BIT_TZ4      */
        uint32_t EPWRTZ0       : 1;  /*!< bit:      5  DCBLTRIPSEL_BIT_EPWRTZ0  */
        uint32_t EPWRTZ1       : 1;  /*!< bit:      6  DCBLTRIPSEL_BIT_EPWRTZ1  */
        uint32_t RESERVED_7_7  : 1;  /*!< bit:      7                           */
        uint32_t ADCPPU0TZ     : 1;  /*!< bit:      8  DCBLTRIPSEL_BIT_ADCPPU0TZ*/
        uint32_t ADCPPU1TZ     : 1;  /*!< bit:      9  DCBLTRIPSEL_BIT_ADCPPU1TZ*/
        uint32_t ADCPPU2TZ     : 1;  /*!< bit:     10  DCBLTRIPSEL_BIT_ADCPPU2TZ*/
        uint32_t ADCPPU3TZ     : 1;  /*!< bit:     11  DCBLTRIPSEL_BIT_ADCPPU3TZ*/
        uint32_t ADCPPU4TZ     : 1;  /*!< bit:     12  DCBLTRIPSEL_BIT_ADCPPU4TZ*/
        uint32_t ADCPPU5TZ     : 1;  /*!< bit:     13  DCBLTRIPSEL_BIT_ADCPPU5TZ*/
        uint32_t RESERVED_15_14: 2;  /*!< bit: 15..14                           */
        uint32_t COMP0L        : 1;  /*!< bit:     16  DCBLTRIPSEL_BIT_COMP0L   */
        uint32_t COMP0H        : 1;  /*!< bit:     17  DCBLTRIPSEL_BIT_COMP0H   */
        uint32_t COMP1L        : 1;  /*!< bit:     18  DCBLTRIPSEL_BIT_COMP1L   */
        uint32_t COMP1H        : 1;  /*!< bit:     19  DCBLTRIPSEL_BIT_COMP1H   */
        uint32_t COMP2L        : 1;  /*!< bit:     20  DCBLTRIPSEL_BIT_COMP2L   */
        uint32_t COMP2H        : 1;  /*!< bit:     21  DCBLTRIPSEL_BIT_COMP2H   */
        uint32_t COMP3L        : 1;  /*!< bit:     22  DCBLTRIPSEL_BIT_COMP3L   */
        uint32_t COMP3H        : 1;  /*!< bit:     23  DCBLTRIPSEL_BIT_COMP3H   */
        uint32_t COMP4L        : 1;  /*!< bit:     24  DCBLTRIPSEL_BIT_COMP4L   */
        uint32_t COMP4H        : 1;  /*!< bit:     25  DCBLTRIPSEL_BIT_COMP4H   */
        uint32_t RESERVED_31_26: 6;  /*!< bit: 31..26                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} DCBLTRIPSEL_REG;



/**
 *  @brief  Union type to access the Digital Compare BH Trip Select Register (DCBHTRIPSEL), offset 0xC0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t TZ0           : 1;  /*!< bit:      0  DCBHTRIPSEL_BIT_TZ0      */
        uint32_t TZ1           : 1;  /*!< bit:      1  DCBHTRIPSEL_BIT_TZ1      */
        uint32_t TZ2           : 1;  /*!< bit:      2  DCBHTRIPSEL_BIT_TZ2      */
        uint32_t TZ3           : 1;  /*!< bit:      3  DCBHTRIPSEL_BIT_TZ3      */
        uint32_t TZ4           : 1;  /*!< bit:      4  DCBHTRIPSEL_BIT_TZ4      */
        uint32_t EPWRTZ0       : 1;  /*!< bit:      5  DCBHTRIPSEL_BIT_EPWRTZ0  */
        uint32_t EPWRTZ1       : 1;  /*!< bit:      6  DCBHTRIPSEL_BIT_EPWRTZ1  */
        uint32_t RESERVED_7_7  : 1;  /*!< bit:      7                           */
        uint32_t ADCPPU0TZ     : 1;  /*!< bit:      8  DCBHTRIPSEL_BIT_ADCPPU0TZ*/
        uint32_t ADCPPU1TZ     : 1;  /*!< bit:      9  DCBHTRIPSEL_BIT_ADCPPU1TZ*/
        uint32_t ADCPPU2TZ     : 1;  /*!< bit:     10  DCBHTRIPSEL_BIT_ADCPPU2TZ*/
        uint32_t ADCPPU3TZ     : 1;  /*!< bit:     11  DCBHTRIPSEL_BIT_ADCPPU3TZ*/
        uint32_t ADCPPU4TZ     : 1;  /*!< bit:     12  DCBHTRIPSEL_BIT_ADCPPU4TZ*/
        uint32_t ADCPPU5TZ     : 1;  /*!< bit:     13  DCBHTRIPSEL_BIT_ADCPPU5TZ*/
        uint32_t RESERVED_15_14: 2;  /*!< bit: 15..14                           */
        uint32_t COMP0L        : 1;  /*!< bit:     16  DCBHTRIPSEL_BIT_COMP0L   */
        uint32_t COMP0H        : 1;  /*!< bit:     17  DCBHTRIPSEL_BIT_COMP0H   */
        uint32_t COMP1L        : 1;  /*!< bit:     18  DCBHTRIPSEL_BIT_COMP1L   */
        uint32_t COMP1H        : 1;  /*!< bit:     19  DCBHTRIPSEL_BIT_COMP1H   */
        uint32_t COMP2L        : 1;  /*!< bit:     20  DCBHTRIPSEL_BIT_COMP2L   */
        uint32_t COMP2H        : 1;  /*!< bit:     21  DCBHTRIPSEL_BIT_COMP2H   */
        uint32_t COMP3L        : 1;  /*!< bit:     22  DCBHTRIPSEL_BIT_COMP3L   */
        uint32_t COMP3H        : 1;  /*!< bit:     23  DCBHTRIPSEL_BIT_COMP3H   */
        uint32_t COMP4L        : 1;  /*!< bit:     24  DCBHTRIPSEL_BIT_COMP4L   */
        uint32_t COMP4H        : 1;  /*!< bit:     25  DCBHTRIPSEL_BIT_COMP4H   */
        uint32_t RESERVED_31_26: 6;  /*!< bit: 31..26                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} DCBHTRIPSEL_REG;



/**
 *  @brief  Union type to access the Digital Compare A Control Register (DCACTL), offset 0xC4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t EVT0SRCSEL    : 1;  /*!< bit:      0  DCACTL_BIT_EVT0SRCSEL    */
        uint32_t EVT0SRCASYNC  : 1;  /*!< bit:      1  DCACTL_BIT_EVT0SRCASYNC  */
        uint32_t EVT0SOCE      : 1;  /*!< bit:      2  DCACTL_BIT_EVT0SOCE      */
        uint32_t EVT0SYNCE     : 1;  /*!< bit:      3  DCACTL_BIT_EVT0SYNCE     */
        uint32_t EVT1SRCSEL    : 1;  /*!< bit:      4  DCACTL_BIT_EVT1SRCSEL    */
        uint32_t EVT1SRCASYNC  : 1;  /*!< bit:      5  DCACTL_BIT_EVT1SRCASYNC  */
        uint32_t RESERVED_31_6 :26;  /*!< bit: 31.. 6                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} DCACTL_REG;



/**
 *  @brief  Union type to access the Digital Compare B Control Register (DCBCTL), offset 0xC8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t EVT0SRCSEL    : 1;  /*!< bit:      0  DCBCTL_BIT_EVT0SRCSEL    */
        uint32_t EVT0SRCASYNC  : 1;  /*!< bit:      1  DCBCTL_BIT_EVT0SRCASYNC  */
        uint32_t EVT0SOCE      : 1;  /*!< bit:      2  DCBCTL_BIT_EVT0SOCE      */
        uint32_t EVT0SYNCE     : 1;  /*!< bit:      3  DCBCTL_BIT_EVT0SYNCE     */
        uint32_t EVT1SRCSEL    : 1;  /*!< bit:      4  DCBCTL_BIT_EVT1SRCSEL    */
        uint32_t EVT1SRCASYNC  : 1;  /*!< bit:      5  DCBCTL_BIT_EVT1SRCASYNC  */
        uint32_t RESERVED_31_6 :26;  /*!< bit: 31.. 6                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} DCBCTL_REG;



/**
 *  @brief  Union type to access the Digital Compare Filter Register (DCFCTL), offset 0xCC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t SRCSEL        : 2;  /*!< bit:  1.. 0  DCFCTL_BIT_SRCSEL        */
        uint32_t BLANKEN       : 1;  /*!< bit:      2  DCFCTL_BIT_BLANKEN       */
        uint32_t BLANKINV      : 1;  /*!< bit:      3  DCFCTL_BIT_BLANKINV      */
        uint32_t PULSESEL      : 2;  /*!< bit:  5.. 4  DCFCTL_BIT_PULSESEL      */
        uint32_t WIN0EN        : 1;  /*!< bit:      6  DCFCTL_BIT_WIN0EN        */
        uint32_t WIN1EN        : 1;  /*!< bit:      7  DCFCTL_BIT_WIN1EN        */
        uint32_t WIN2EN        : 1;  /*!< bit:      8  DCFCTL_BIT_WIN2EN        */
        uint32_t WIN3EN        : 1;  /*!< bit:      9  DCFCTL_BIT_WIN3EN        */
        uint32_t WIN4EN        : 1;  /*!< bit:     10  DCFCTL_BIT_WIN4EN        */
        uint32_t WIN5EN        : 1;  /*!< bit:     11  DCFCTL_BIT_WIN5EN        */
        uint32_t RESERVED_31_12:20;  /*!< bit: 31..12                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} DCFCTL_REG;



/**
 *  @brief  Union type to access the Digital Compare Filter Offset Register (DCFOFFSET), offset 0xD0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  DCFOFFSET_BIT_VAL        */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} DCFOFFSET_REG;



/**
 *  @brief  Union type to access the Digital Compare Filter Offset Counter Register (DCFOFFSETCNT), offset 0xD4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  DCFOFFSETCNT_BIT_VAL     */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} DCFOFFSETCNT_REG;



/**
 *  @brief  Union type to access the Digital Compare Filter Window Register (DCFWINDOW), offset 0xD8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  DCFWINDOW_BIT_VAL        */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} DCFWINDOW_REG;



/**
 *  @brief  Union type to access the Digital Compare Filter Window Counter Register (DCFWINDOWCNT), offset 0xDC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  DCFWINDOWCNT_BIT_VAL     */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} DCFWINDOWCNT_REG;



/**
 *  @brief  Union type to access the Digital Compare Capture Control Register (DCCAPCTL), offset 0xE0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t CAPEN         : 1;  /*!< bit:      0  DCCAPCTL_BIT_CAPEN       */
        uint32_t DIRECT        : 1;  /*!< bit:      1  DCCAPCTL_BIT_DIRECT      */
        uint32_t CAPCLR        : 1;  /*!< bit:      2  DCCAPCTL_BIT_CAPCLR      */
        uint32_t CAPSTS        : 1;  /*!< bit:      3  DCCAPCTL_BIT_CAPSTS      */
        uint32_t RESERVED_31_4 :28;  /*!< bit: 31.. 4                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} DCCAPCTL_REG;



/**
 *  @brief  Union type to access the Digital Compare Counter Capture Register (DCCAP), offset 0xE4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  DCCAP_BIT_VAL            */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} DCCAP_REG;



/**
 *  @brief  Union type to access the Event-Trigger Control Register (ETCTL), offset 0xE8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t INTSEL        : 4;  /*!< bit:  3.. 0  ETCTL_BIT_INTSEL         */
        uint32_t INTEN         : 1;  /*!< bit:      4  ETCTL_BIT_INTEN          */
        uint32_t SOCASEL       : 4;  /*!< bit:  8.. 5  ETCTL_BIT_SOCASEL        */
        uint32_t SOCAEN        : 1;  /*!< bit:      9  ETCTL_BIT_SOCAEN         */
        uint32_t SOCBSEL       : 4;  /*!< bit: 13..10  ETCTL_BIT_SOCBSEL        */
        uint32_t SOCBEN        : 1;  /*!< bit:     14  ETCTL_BIT_SOCBEN         */
        uint32_t SOCCSEL       : 4;  /*!< bit: 18..15  ETCTL_BIT_SOCCSEL        */
        uint32_t SOCCEN        : 1;  /*!< bit:     19  ETCTL_BIT_SOCCEN         */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ETCTL_REG;



/**
 *  @brief  Union type to access the Event-Trigger Prescale Register (ETPS), offset 0xEC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t INTPRD        : 4;  /*!< bit:  3.. 0  ETPS_BIT_INTPRD          */
        uint32_t INTCNT        : 4;  /*!< bit:  7.. 4  ETPS_BIT_INTCNT          */
        uint32_t SOCAPRD       : 4;  /*!< bit: 11.. 8  ETPS_BIT_SOCAPRD         */
        uint32_t SOCACNT       : 4;  /*!< bit: 15..12  ETPS_BIT_SOCACNT         */
        uint32_t SOCBPRD       : 4;  /*!< bit: 19..16  ETPS_BIT_SOCBPRD         */
        uint32_t SOCBCNT       : 4;  /*!< bit: 23..20  ETPS_BIT_SOCBCNT         */
        uint32_t SOCCPRD       : 4;  /*!< bit: 27..24  ETPS_BIT_SOCCPRD         */
        uint32_t SOCCCNT       : 4;  /*!< bit: 31..28  ETPS_BIT_SOCCCNT         */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ETPS_REG;



/**
 *  @brief  Union type to access the Event-Trigger Flag Register (ETFLG), offset 0xF0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t INT           : 1;  /*!< bit:      0  ETFLG_BIT_INT            */
        uint32_t SOCA          : 1;  /*!< bit:      1  ETFLG_BIT_SOCA           */
        uint32_t SOCB          : 1;  /*!< bit:      2  ETFLG_BIT_SOCB           */
        uint32_t SOCC          : 1;  /*!< bit:      3  ETFLG_BIT_SOCC           */
        uint32_t RESERVED_31_4 :28;  /*!< bit: 31.. 4                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ETFLG_REG;



/**
 *  @brief  Union type to access the Event-Trigger Clear Register (ETCLR), offset 0xF4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t INT           : 1;  /*!< bit:      0  ETCLR_BIT_INT            */
        uint32_t SOCA          : 1;  /*!< bit:      1  ETCLR_BIT_SOCA           */
        uint32_t SOCB          : 1;  /*!< bit:      2  ETCLR_BIT_SOCB           */
        uint32_t SOCC          : 1;  /*!< bit:      3  ETCLR_BIT_SOCC           */
        uint32_t RESERVED_31_4 :28;  /*!< bit: 31.. 4                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ETCLR_REG;



/**
 *  @brief  Union type to access the Event-Trigger Force Register (ETFRC), offset 0xF8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t INT           : 1;  /*!< bit:      0  ETFRC_BIT_INT            */
        uint32_t SOCA          : 1;  /*!< bit:      1  ETFRC_BIT_SOCA           */
        uint32_t SOCB          : 1;  /*!< bit:      2  ETFRC_BIT_SOCB           */
        uint32_t SOCC          : 1;  /*!< bit:      3  ETFRC_BIT_SOCC           */
        uint32_t RESERVED_31_4 :28;  /*!< bit: 31.. 4                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} ETFRC_REG;



/**
 *  @brief  Union type to access the PWM Register Write-Allow Key Register (PWMREGKEY), offset 0xFC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t KEY           :32;  /*!< bit: 31.. 0  PWMREGKEY_BIT_KEY        */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} PWMREGKEY_REG;



/**
  *  @brief  Structure type to access the PWM Controller (PWM).
  */
typedef struct
{
    __I  SHADOWSTS_REG        SHADOWSTS             ; /*!< Offset: 0x00000000 (RO  )  Shadow Status Register                                      */
    __IO GLDCTL0_REG          GLDCTL0               ; /*!< Offset: 0x00000004 (RW  )  Global Shadow to Active Load Control Register 0             */
    __O  GLDCTL1_REG          GLDCTL1               ; /*!< Offset: 0x00000008 (WO  )  Global Shadow to Active Load Control Register 1             */
    __IO GLDSEL_REG           GLDSEL                ; /*!< Offset: 0x0000000C (RW  )  Global Shadow to Active Load Select Register                */
    __IO PWMLINK_REG          PWMLINK               ; /*!< Offset: 0x00000010 (RW  )  PWM Link Control Register                                   */
    __IO TBCTL_REG            TBCTL                 ; /*!< Offset: 0x00000014 (RW  )  Time-Base Control Register                                  */
    __IO TBPRD_REG            TBPRD                 ; /*!< Offset: 0x00000018 (RW  )  Time-Base Period Register                                   */
    __I  TBPRDA_REG           TBPRDA                ; /*!< Offset: 0x0000001C (RO  )  Time-Base Period Active Register                            */
    __IO TBPHS_REG            TBPHS                 ; /*!< Offset: 0x00000020 (RW  )  Time-Base Phase Register                                    */
    __IO TBCNT_REG            TBCNT                 ; /*!< Offset: 0x00000024 (RW  )  Time-Base Counter Register                                  */
    __I  TBSTS_REG            TBSTS                 ; /*!< Offset: 0x00000028 (RO  )  Time-Base Status Register                                   */
    __O  TBSTSCLR_REG         TBSTSCLR              ; /*!< Offset: 0x0000002C (WO  )  Time-Base Status Clear Register                             */
    __IO CMPCTL_REG           CMPCTL                ; /*!< Offset: 0x00000030 (RW  )  Counter-Compare Control Register                            */
    __IO CMPA_REG             CMPA                  ; /*!< Offset: 0x00000034 (RW  )  Counter-Compare A Threshold Register                        */
    __I  CMPAA_REG            CMPAA                 ; /*!< Offset: 0x00000038 (RO  )  Counter-Compare A Threshold Active Register                 */
    __IO CMPB_REG             CMPB                  ; /*!< Offset: 0x0000003C (RW  )  Counter-Compare B Threshold Register                        */
    __I  CMPBA_REG            CMPBA                 ; /*!< Offset: 0x00000040 (RO  )  Counter-Compare B Threshold Active Register                 */
    __IO CMPC_REG             CMPC                  ; /*!< Offset: 0x00000044 (RW  )  Counter-Compare C Threshold Register                        */
    __I  CMPCA_REG            CMPCA                 ; /*!< Offset: 0x00000048 (RO  )  Counter-Compare C Threshold Active Register                 */
    __IO CMPD_REG             CMPD                  ; /*!< Offset: 0x0000004C (RW  )  Counter-Compare D Threshold Register                        */
    __I  CMPDA_REG            CMPDA                 ; /*!< Offset: 0x00000050 (RO  )  Counter-Compare D Threshold Active Register                 */
    __IO AQCTL_REG            AQCTL                 ; /*!< Offset: 0x00000054 (RW  )  Action-Qualifier Control Register                           */
    __IO AQCTLA_REG           AQCTLA                ; /*!< Offset: 0x00000058 (RW  )  Action-Qualifier Output A Control Register                  */
    __I  AQCTLAA_REG          AQCTLAA               ; /*!< Offset: 0x0000005C (RO  )  Action-Qualifier Output A Control Active Register           */
    __IO AQCTLB_REG           AQCTLB                ; /*!< Offset: 0x00000060 (RW  )  Action-Qualifier Output B Control Register                  */
    __I  AQCTLBA_REG          AQCTLBA               ; /*!< Offset: 0x00000064 (RO  )  Action-Qualifier Output B Control Active Register           */
    __IO AQSFRC_REG           AQSFRC                ; /*!< Offset: 0x00000068 (RW  )  Action-Qualifier Software Force Register                    */
    __IO AQCSFRC_REG          AQCSFRC               ; /*!< Offset: 0x0000006C (RW  )  Action-Qualifier Continuous Software Force Register         */
    __I  AQCSFRCA_REG         AQCSFRCA              ; /*!< Offset: 0x00000070 (RO  )  Action-Qualifier Continuous Software Force Active Register  */
    __IO DBCTL_REG            DBCTL                 ; /*!< Offset: 0x00000074 (RW  )  Dead-Band Generator Control Register                        */
    __I  DBCTLA_REG           DBCTLA                ; /*!< Offset: 0x00000078 (RO  )  Dead-Band Generator Control Active Register                 */
    __IO DBRED_REG            DBRED                 ; /*!< Offset: 0x0000007C (RW  )  Dead-Band Generator Rising Edge Delay Register              */
    __I  DBREDA_REG           DBREDA                ; /*!< Offset: 0x00000080 (RO  )  Dead-Band Generator Rising Edge Delay Active Register       */
    __IO DBFED_REG            DBFED                 ; /*!< Offset: 0x00000084 (RW  )  Dead-Band Generator Falling Edge Delay Register             */
    __I  DBFEDA_REG           DBFEDA                ; /*!< Offset: 0x00000088 (RO  )  Dead-Band Generator Falling Edge Delay Active Register      */
    __IO TZSEL_REG            TZSEL                 ; /*!< Offset: 0x0000008C (RW  )  Trip-Zone Event Select Register                             */
    __I  TZSTS_REG            TZSTS                 ; /*!< Offset: 0x00000090 (RO  )  Trip-Zone Status Register                                   */
    __O  TZSTSCLR_REG         TZSTSCLR              ; /*!< Offset: 0x00000094 (WO  )  Trip-Zone Status Clear Register                             */
    __IO TZDCSEL_REG          TZDCSEL               ; /*!< Offset: 0x00000098 (RW  )  Trip-Zone Digital Compare Event Select Register             */
    __IO TZACTL_REG           TZACTL                ; /*!< Offset: 0x0000009C (RW  )  Trip-Zone Output A Control Register                         */
    __IO TZBCTL_REG           TZBCTL                ; /*!< Offset: 0x000000A0 (RW  )  Trip-Zone Ouput B Control Register                          */
    __I  TZIF_REG             TZIF                  ; /*!< Offset: 0x000000A4 (RO  )  Trip-Zone Flag Register                                     */
    __IO TZIC_REG             TZIC                  ; /*!< Offset: 0x000000A8 (RW  )  Trip-Zone Clear Register                                    */
    __IO TZIE_REG             TZIE                  ; /*!< Offset: 0x000000AC (RW  )  Trip-Zone Interrupt Enable Register                         */
    __O  TZFRC_REG            TZFRC                 ; /*!< Offset: 0x000000B0 (WO  )  Trip-Zone Force Register                                    */
    __IO DCALTRIPSEL_REG      DCALTRIPSEL           ; /*!< Offset: 0x000000B4 (RW  )  Digital Compare AL Trip Select Register                     */
    __IO DCAHTRIPSEL_REG      DCAHTRIPSEL           ; /*!< Offset: 0x000000B8 (RW  )  Digital Compare AH Trip Select Register                     */
    __IO DCBLTRIPSEL_REG      DCBLTRIPSEL           ; /*!< Offset: 0x000000BC (RW  )  Digital Compare BL Trip Select Register                     */
    __IO DCBHTRIPSEL_REG      DCBHTRIPSEL           ; /*!< Offset: 0x000000C0 (RW  )  Digital Compare BH Trip Select Register                     */
    __IO DCACTL_REG           DCACTL                ; /*!< Offset: 0x000000C4 (RW  )  Digital Compare A Control Register                          */
    __IO DCBCTL_REG           DCBCTL                ; /*!< Offset: 0x000000C8 (RW  )  Digital Compare B Control Register                          */
    __IO DCFCTL_REG           DCFCTL                ; /*!< Offset: 0x000000CC (RW  )  Digital Compare Filter Register                             */
    __IO DCFOFFSET_REG        DCFOFFSET             ; /*!< Offset: 0x000000D0 (RW  )  Digital Compare Filter Offset Register                      */
    __I  DCFOFFSETCNT_REG     DCFOFFSETCNT          ; /*!< Offset: 0x000000D4 (RO  )  Digital Compare Filter Offset Counter Register              */
    __IO DCFWINDOW_REG        DCFWINDOW             ; /*!< Offset: 0x000000D8 (RW  )  Digital Compare Filter Window Register                      */
    __I  DCFWINDOWCNT_REG     DCFWINDOWCNT          ; /*!< Offset: 0x000000DC (RO  )  Digital Compare Filter Window Counter Register              */
    __IO DCCAPCTL_REG         DCCAPCTL              ; /*!< Offset: 0x000000E0 (RW  )  Digital Compare Capture Control Register                    */
    __I  DCCAP_REG            DCCAP                 ; /*!< Offset: 0x000000E4 (RO  )  Digital Compare Counter Capture Register                    */
    __IO ETCTL_REG            ETCTL                 ; /*!< Offset: 0x000000E8 (RW  )  Event-Trigger Control Register                              */
    __IO ETPS_REG             ETPS                  ; /*!< Offset: 0x000000EC (RW  )  Event-Trigger Prescale Register                             */
    __I  ETFLG_REG            ETFLG                 ; /*!< Offset: 0x000000F0 (RO  )  Event-Trigger Flag Register                                 */
    __O  ETCLR_REG            ETCLR                 ; /*!< Offset: 0x000000F4 (WO  )  Event-Trigger Clear Register                                */
    __O  ETFRC_REG            ETFRC                 ; /*!< Offset: 0x000000F8 (WO  )  Event-Trigger Force Register                                */
    __IO PWMREGKEY_REG        PWMREGKEY             ; /*!< Offset: 0x000000FC (RW  )  PWM Register Write-Allow Key Register                       */
} PWM_REGS;



/********************************************************************************
*
* Module Name     PWMCFG
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the TZ0 Source Control Register (TZ0SRCCTL), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t IOSEL         : 6;  /*!< bit:  5.. 0  TZ0SRCCTL_BIT_IOSEL    */
        uint32_t POL           : 1;  /*!< bit:      6  TZ0SRCCTL_BIT_POL      */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TZ0SRCCTL_REG;



/**
 *  @brief  Union type to access the TZ1 Source Control Register (TZ1SRCCTL), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t IOSEL         : 6;  /*!< bit:  5.. 0  TZ1SRCCTL_BIT_IOSEL    */
        uint32_t POL           : 1;  /*!< bit:      6  TZ1SRCCTL_BIT_POL      */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TZ1SRCCTL_REG;



/**
 *  @brief  Union type to access the TZ2 Source Control Register (TZ2SRCCTL), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t IOSEL         : 6;  /*!< bit:  5.. 0  TZ2SRCCTL_BIT_IOSEL    */
        uint32_t POL           : 1;  /*!< bit:      6  TZ2SRCCTL_BIT_POL      */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TZ2SRCCTL_REG;



/**
 *  @brief  Union type to access the TZ3 Source Control Register (TZ3SRCCTL), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t IOSEL         : 6;  /*!< bit:  5.. 0  TZ3SRCCTL_BIT_IOSEL    */
        uint32_t POL           : 1;  /*!< bit:      6  TZ3SRCCTL_BIT_POL      */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TZ3SRCCTL_REG;



/**
 *  @brief  Union type to access the TZ4 Source Control Register (TZ4SRCCTL), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t IOSEL         : 6;  /*!< bit:  5.. 0  TZ4SRCCTL_BIT_IOSEL    */
        uint32_t POL           : 1;  /*!< bit:      6  TZ4SRCCTL_BIT_POL      */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TZ4SRCCTL_REG;



/**
 *  @brief  Union type to access the Global PWM Force Synchronization Register (FRCSYNC), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t PWM0SYNC      : 1;  /*!< bit:      0  FRCSYNC_BIT_PWM0SYNC   */
        uint32_t PWM1SYNC      : 1;  /*!< bit:      1  FRCSYNC_BIT_PWM1SYNC   */
        uint32_t PWM2SYNC      : 1;  /*!< bit:      2  FRCSYNC_BIT_PWM2SYNC   */
        uint32_t PWM3SYNC      : 1;  /*!< bit:      3  FRCSYNC_BIT_PWM3SYNC   */
        uint32_t PWM4SYNC      : 1;  /*!< bit:      4  FRCSYNC_BIT_PWM4SYNC   */
        uint32_t PWM5SYNC      : 1;  /*!< bit:      5  FRCSYNC_BIT_PWM5SYNC   */
        uint32_t RESERVED_30_6 :25;  /*!< bit: 30.. 6                         */
        uint32_t PWMCLK        : 1;  /*!< bit:     31  FRCSYNC_BIT_PWMCLK     */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} FRCSYNC_REG;



/**
 *  @brief  Union type to access the GPIO PWMSYNCI Control Register (GPIOSYNCCTL), offset 0x18.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t IOSEL         : 6;  /*!< bit:  5.. 0  GPIOSYNCCTL_BIT_IOSEL  */
        uint32_t POL           : 1;  /*!< bit:      6  GPIOSYNCCTL_BIT_POL    */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIOSYNCCTL_REG;



/**
 *  @brief  Union type to access the GPIO Force PWMSYNCI Enable Register (GPIOSYNCEN), offset 0x1C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t PWM0SYNC      : 1;  /*!< bit:      0  GPIOSYNCEN_BIT_PWM0SYNC*/
        uint32_t PWM1SYNC      : 1;  /*!< bit:      1  GPIOSYNCEN_BIT_PWM1SYNC*/
        uint32_t PWM2SYNC      : 1;  /*!< bit:      2  GPIOSYNCEN_BIT_PWM2SYNC*/
        uint32_t PWM3SYNC      : 1;  /*!< bit:      3  GPIOSYNCEN_BIT_PWM3SYNC*/
        uint32_t PWM4SYNC      : 1;  /*!< bit:      4  GPIOSYNCEN_BIT_PWM4SYNC*/
        uint32_t PWM5SYNC      : 1;  /*!< bit:      5  GPIOSYNCEN_BIT_PWM5SYNC*/
        uint32_t RESERVED_31_6 :26;  /*!< bit: 31.. 6                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIOSYNCEN_REG;



/**
 *  @brief  Union type to access the Timer 0 Force PWMSYNCI Enable Register (TMR0SYNCEN), offset 0x20.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t PWM0SYNC      : 1;  /*!< bit:      0  TMR0SYNCEN_BIT_PWM0SYNC*/
        uint32_t PWM1SYNC      : 1;  /*!< bit:      1  TMR0SYNCEN_BIT_PWM1SYNC*/
        uint32_t PWM2SYNC      : 1;  /*!< bit:      2  TMR0SYNCEN_BIT_PWM2SYNC*/
        uint32_t PWM3SYNC      : 1;  /*!< bit:      3  TMR0SYNCEN_BIT_PWM3SYNC*/
        uint32_t PWM4SYNC      : 1;  /*!< bit:      4  TMR0SYNCEN_BIT_PWM4SYNC*/
        uint32_t PWM5SYNC      : 1;  /*!< bit:      5  TMR0SYNCEN_BIT_PWM5SYNC*/
        uint32_t RESERVED_31_6 :26;  /*!< bit: 31.. 6                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TMR0SYNCEN_REG;



/**
 *  @brief  Union type to access the Timer 1 Force PWMSYNCI Enable Register (TMR1SYNCEN), offset 0x24.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t PWM0SYNC      : 1;  /*!< bit:      0  TMR1SYNCEN_BIT_PWM0SYNC*/
        uint32_t PWM1SYNC      : 1;  /*!< bit:      1  TMR1SYNCEN_BIT_PWM1SYNC*/
        uint32_t PWM2SYNC      : 1;  /*!< bit:      2  TMR1SYNCEN_BIT_PWM2SYNC*/
        uint32_t PWM3SYNC      : 1;  /*!< bit:      3  TMR1SYNCEN_BIT_PWM3SYNC*/
        uint32_t PWM4SYNC      : 1;  /*!< bit:      4  TMR1SYNCEN_BIT_PWM4SYNC*/
        uint32_t PWM5SYNC      : 1;  /*!< bit:      5  TMR1SYNCEN_BIT_PWM5SYNC*/
        uint32_t RESERVED_31_6 :26;  /*!< bit: 31.. 6                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TMR1SYNCEN_REG;



/**
 *  @brief  Union type to access the Timer 2 Force PWMSYNCI Enable Register (TMR2SYNCEN), offset 0x28.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t PWM0SYNC      : 1;  /*!< bit:      0  TMR2SYNCEN_BIT_PWM0SYNC*/
        uint32_t PWM1SYNC      : 1;  /*!< bit:      1  TMR2SYNCEN_BIT_PWM1SYNC*/
        uint32_t PWM2SYNC      : 1;  /*!< bit:      2  TMR2SYNCEN_BIT_PWM2SYNC*/
        uint32_t PWM3SYNC      : 1;  /*!< bit:      3  TMR2SYNCEN_BIT_PWM3SYNC*/
        uint32_t PWM4SYNC      : 1;  /*!< bit:      4  TMR2SYNCEN_BIT_PWM4SYNC*/
        uint32_t PWM5SYNC      : 1;  /*!< bit:      5  TMR2SYNCEN_BIT_PWM5SYNC*/
        uint32_t RESERVED_31_6 :26;  /*!< bit: 31.. 6                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TMR2SYNCEN_REG;



/**
 *  @brief  Union type to access the PWMSYNCO Control Register (SYNCOCTL), offset 0x2C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DURATION      : 2;  /*!< bit:  1.. 0  SYNCOCTL_BIT_DURATION  */
        uint32_t POL           : 1;  /*!< bit:      2  SYNCOCTL_BIT_POL       */
        uint32_t SRCSEL        : 3;  /*!< bit:  5.. 3  SYNCOCTL_BIT_SRCSEL    */
        uint32_t RESERVED_31_6 :26;  /*!< bit: 31.. 6                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SYNCOCTL_REG;



/**
 *  @brief  Union type to access the PWMSOCA Output Control Register (SOCAOCTL), offset 0x30.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DURATION      : 2;  /*!< bit:  1.. 0  SOCAOCTL_BIT_DURATION  */
        uint32_t POL           : 1;  /*!< bit:      2  SOCAOCTL_BIT_POL       */
        uint32_t SOCA0EN       : 1;  /*!< bit:      3  SOCAOCTL_BIT_SOCA0EN   */
        uint32_t SOCA1EN       : 1;  /*!< bit:      4  SOCAOCTL_BIT_SOCA1EN   */
        uint32_t SOCA2EN       : 1;  /*!< bit:      5  SOCAOCTL_BIT_SOCA2EN   */
        uint32_t SOCA3EN       : 1;  /*!< bit:      6  SOCAOCTL_BIT_SOCA3EN   */
        uint32_t SOCA4EN       : 1;  /*!< bit:      7  SOCAOCTL_BIT_SOCA4EN   */
        uint32_t SOCA5EN       : 1;  /*!< bit:      8  SOCAOCTL_BIT_SOCA5EN   */
        uint32_t RESERVED_31_9 :23;  /*!< bit: 31.. 9                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SOCAOCTL_REG;



/**
 *  @brief  Union type to access the PWMSOCB Output Control Register (SOCBOCTL), offset 0x34.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DURATION      : 2;  /*!< bit:  1.. 0  SOCBOCTL_BIT_DURATION  */
        uint32_t POL           : 1;  /*!< bit:      2  SOCBOCTL_BIT_POL       */
        uint32_t SOCB0EN       : 1;  /*!< bit:      3  SOCBOCTL_BIT_SOCB0EN   */
        uint32_t SOCB1EN       : 1;  /*!< bit:      4  SOCBOCTL_BIT_SOCB1EN   */
        uint32_t SOCB2EN       : 1;  /*!< bit:      5  SOCBOCTL_BIT_SOCB2EN   */
        uint32_t SOCB3EN       : 1;  /*!< bit:      6  SOCBOCTL_BIT_SOCB3EN   */
        uint32_t SOCB4EN       : 1;  /*!< bit:      7  SOCBOCTL_BIT_SOCB4EN   */
        uint32_t SOCB5EN       : 1;  /*!< bit:      8  SOCBOCTL_BIT_SOCB5EN   */
        uint32_t RESERVED_31_9 :23;  /*!< bit: 31.. 9                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SOCBOCTL_REG;



/**
 *  @brief  Union type to access the PWMSOCC Output Control Register (SOCCOCTL), offset 0x38.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DURATION      : 2;  /*!< bit:  1.. 0  SOCCOCTL_BIT_DURATION  */
        uint32_t POL           : 1;  /*!< bit:      2  SOCCOCTL_BIT_POL       */
        uint32_t SOCC0EN       : 1;  /*!< bit:      3  SOCCOCTL_BIT_SOCC0EN   */
        uint32_t SOCC1EN       : 1;  /*!< bit:      4  SOCCOCTL_BIT_SOCC1EN   */
        uint32_t SOCC2EN       : 1;  /*!< bit:      5  SOCCOCTL_BIT_SOCC2EN   */
        uint32_t SOCC3EN       : 1;  /*!< bit:      6  SOCCOCTL_BIT_SOCC3EN   */
        uint32_t SOCC4EN       : 1;  /*!< bit:      7  SOCCOCTL_BIT_SOCC4EN   */
        uint32_t SOCC5EN       : 1;  /*!< bit:      8  SOCCOCTL_BIT_SOCC5EN   */
        uint32_t RESERVED_31_9 :23;  /*!< bit: 31.. 9                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SOCCOCTL_REG;



/**
 *  @brief  Union type to access the PWMCFG Register Write-Allow Key Register (PWMCFGREGKEY), offset 0x3C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t KEY           :32;  /*!< bit: 31.. 0  PWMCFGREGKEY_BIT_KEY   */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PWMCFGREGKEY_REG;



/**
  *  @brief  Structure type to access the PWMCFG Controller (PWMCFG).
  */
typedef struct
{
    __IO TZ0SRCCTL_REG        TZ0SRCCTL             ; /*!< Offset: 0x00000000 (RW  )  TZ0 Source Control Register                */
    __IO TZ1SRCCTL_REG        TZ1SRCCTL             ; /*!< Offset: 0x00000004 (RW  )  TZ1 Source Control Register                */
    __IO TZ2SRCCTL_REG        TZ2SRCCTL             ; /*!< Offset: 0x00000008 (RW  )  TZ2 Source Control Register                */
    __IO TZ3SRCCTL_REG        TZ3SRCCTL             ; /*!< Offset: 0x0000000C (RW  )  TZ3 Source Control Register                */
    __IO TZ4SRCCTL_REG        TZ4SRCCTL             ; /*!< Offset: 0x00000010 (RW  )  TZ4 Source Control Register                */
    __O  FRCSYNC_REG          FRCSYNC               ; /*!< Offset: 0x00000014 (WO  )  Global PWM Force Synchronization Register  */
    __IO GPIOSYNCCTL_REG      GPIOSYNCCTL           ; /*!< Offset: 0x00000018 (RW  )  GPIO PWMSYNCI Control Register             */
    __IO GPIOSYNCEN_REG       GPIOSYNCEN            ; /*!< Offset: 0x0000001C (RW  )  GPIO Force PWMSYNCI Enable Register        */
    __IO TMR0SYNCEN_REG       TMR0SYNCEN            ; /*!< Offset: 0x00000020 (RW  )  Timer 0 Force PWMSYNCI Enable Register     */
    __IO TMR1SYNCEN_REG       TMR1SYNCEN            ; /*!< Offset: 0x00000024 (RW  )  Timer 1 Force PWMSYNCI Enable Register     */
    __IO TMR2SYNCEN_REG       TMR2SYNCEN            ; /*!< Offset: 0x00000028 (RW  )  Timer 2 Force PWMSYNCI Enable Register     */
    __IO SYNCOCTL_REG         SYNCOCTL              ; /*!< Offset: 0x0000002C (RW  )  PWMSYNCO Control Register                  */
    __IO SOCAOCTL_REG         SOCAOCTL              ; /*!< Offset: 0x00000030 (RW  )  PWMSOCA Output Control Register            */
    __IO SOCBOCTL_REG         SOCBOCTL              ; /*!< Offset: 0x00000034 (RW  )  PWMSOCB Output Control Register            */
    __IO SOCCOCTL_REG         SOCCOCTL              ; /*!< Offset: 0x00000038 (RW  )  PWMSOCC Output Control Register            */
    __IO PWMCFGREGKEY_REG     PWMCFGREGKEY          ; /*!< Offset: 0x0000003C (RW  )  PWMCFG Register Write-Allow Key Register   */
} PWMCFG_REGS;



/********************************************************************************
*
* Module Name     ECAP
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the Capture Source Input Control Register (CAPSRCCTL), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t IOSEL         : 6;  /*!< bit:  5.. 0  CAPSRCCTL_BIT_IOSEL    */
        uint32_t POL           : 1;  /*!< bit:      6  CAPSRCCTL_BIT_POL      */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CAPSRCCTL_REG;



/**
 *  @brief  Union type to access the Capture Synchronization Source Input Control Register (CAPSYNCICTL), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t IOSEL         : 6;  /*!< bit:  5.. 0  CAPSYNCICTL_BIT_IOSEL  */
        uint32_t POL           : 1;  /*!< bit:      6  CAPSYNCICTL_BIT_POL    */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CAPSYNCICTL_REG;



/**
 *  @brief  Union type to access the Time-Stamp Counter Register (CAPTSCNT), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  CAPTSCNT_BIT_VAL       */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CAPTSCNT_REG;



/**
 *  @brief  Union type to access the Counter Phase Offset Value Register (CAPCNTPHS), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  CAPCNTPHS_BIT_VAL      */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CAPCNTPHS_REG;



/**
 *  @brief  Union type to access the Capture Register 0 (CAP0), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  CAP0_BIT_VAL           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CAP0_REG;



/**
 *  @brief  Union type to access the Capture Register 1 (CAP1), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  CAP1_BIT_VAL           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CAP1_REG;



/**
 *  @brief  Union type to access the Capture Register 2 (CAP2), offset 0x18.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  CAP2_BIT_VAL           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CAP2_REG;



/**
 *  @brief  Union type to access the Capture Register 3 (CAP3), offset 0x1C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  CAP3_BIT_VAL           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CAP3_REG;



/**
 *  @brief  Union type to access the Capture Control Register (CAPCTL), offset 0x20.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t CAP0POL       : 1;  /*!< bit:      0  CAPCTL_BIT_CAP0POL     */
        uint32_t CNTRST0       : 1;  /*!< bit:      1  CAPCTL_BIT_CNTRST0     */
        uint32_t CAP1POL       : 1;  /*!< bit:      2  CAPCTL_BIT_CAP1POL     */
        uint32_t CNTRST1       : 1;  /*!< bit:      3  CAPCTL_BIT_CNTRST1     */
        uint32_t CAP2POL       : 1;  /*!< bit:      4  CAPCTL_BIT_CAP2POL     */
        uint32_t CNTRST2       : 1;  /*!< bit:      5  CAPCTL_BIT_CNTRST2     */
        uint32_t CAP3POL       : 1;  /*!< bit:      6  CAPCTL_BIT_CAP3POL     */
        uint32_t CNTRST3       : 1;  /*!< bit:      7  CAPCTL_BIT_CNTRST3     */
        uint32_t CAPLDEN       : 1;  /*!< bit:      8  CAPCTL_BIT_CAPLDEN     */
        uint32_t EVTDIV        : 8;  /*!< bit: 16.. 9  CAPCTL_BIT_EVTDIV      */
        uint32_t ONESHOT       : 1;  /*!< bit:     17  CAPCTL_BIT_ONESHOT     */
        uint32_t STOPWRAP      : 2;  /*!< bit: 19..18  CAPCTL_BIT_STOPWRAP    */
        uint32_t REARM         : 1;  /*!< bit:     20  CAPCTL_BIT_REARM       */
        uint32_t TSCNTRUN      : 1;  /*!< bit:     21  CAPCTL_BIT_TSCNTRUN    */
        uint32_t PHSEN         : 1;  /*!< bit:     22  CAPCTL_BIT_PHSEN       */
        uint32_t SYNCOSEL      : 2;  /*!< bit: 24..23  CAPCTL_BIT_SYNCOSEL    */
        uint32_t FRCSYNC       : 1;  /*!< bit:     25  CAPCTL_BIT_FRCSYNC     */
        uint32_t APWMMODE      : 1;  /*!< bit:     26  CAPCTL_BIT_APWMMODE    */
        uint32_t APWMPOL       : 1;  /*!< bit:     27  CAPCTL_BIT_APWMPOL     */
        uint32_t DBGRUN        : 2;  /*!< bit: 29..28  CAPCTL_BIT_DBGRUN      */
        uint32_t RESERVED_31_30: 2;  /*!< bit: 31..30                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CAPCTL_REG;



/**
 *  @brief  Union type to access the Capture Interrupt Flag Register (CAPIF), offset 0x24.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t CEVT0         : 1;  /*!< bit:      0  CAPIF_BIT_CEVT0        */
        uint32_t CEVT1         : 1;  /*!< bit:      1  CAPIF_BIT_CEVT1        */
        uint32_t CEVT2         : 1;  /*!< bit:      2  CAPIF_BIT_CEVT2        */
        uint32_t CEVT3         : 1;  /*!< bit:      3  CAPIF_BIT_CEVT3        */
        uint32_t CNTOVF        : 1;  /*!< bit:      4  CAPIF_BIT_CNTOVF       */
        uint32_t PRD           : 1;  /*!< bit:      5  CAPIF_BIT_PRD          */
        uint32_t CMP           : 1;  /*!< bit:      6  CAPIF_BIT_CMP          */
        uint32_t INT           : 1;  /*!< bit:      7  CAPIF_BIT_INT          */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CAPIF_REG;



/**
 *  @brief  Union type to access the Capture Interrupt Enable Register (CAPIE), offset 0x28.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t CEVT0         : 1;  /*!< bit:      0  CAPIE_BIT_CEVT0        */
        uint32_t CEVT1         : 1;  /*!< bit:      1  CAPIE_BIT_CEVT1        */
        uint32_t CEVT2         : 1;  /*!< bit:      2  CAPIE_BIT_CEVT2        */
        uint32_t CEVT3         : 1;  /*!< bit:      3  CAPIE_BIT_CEVT3        */
        uint32_t CNTOVF        : 1;  /*!< bit:      4  CAPIE_BIT_CNTOVF       */
        uint32_t PRD           : 1;  /*!< bit:      5  CAPIE_BIT_PRD          */
        uint32_t CMP           : 1;  /*!< bit:      6  CAPIE_BIT_CMP          */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CAPIE_REG;



/**
 *  @brief  Union type to access the Capture Interrupt Clear Register (CAPIC), offset 0x2C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t CEVT0         : 1;  /*!< bit:      0  CAPIC_BIT_CEVT0        */
        uint32_t CEVT1         : 1;  /*!< bit:      1  CAPIC_BIT_CEVT1        */
        uint32_t CEVT2         : 1;  /*!< bit:      2  CAPIC_BIT_CEVT2        */
        uint32_t CEVT3         : 1;  /*!< bit:      3  CAPIC_BIT_CEVT3        */
        uint32_t CNTOVF        : 1;  /*!< bit:      4  CAPIC_BIT_CNTOVF       */
        uint32_t PRD           : 1;  /*!< bit:      5  CAPIC_BIT_PRD          */
        uint32_t CMP           : 1;  /*!< bit:      6  CAPIC_BIT_CMP          */
        uint32_t INT           : 1;  /*!< bit:      7  CAPIC_BIT_INT          */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CAPIC_REG;



/**
 *  @brief  Union type to access the Capture Interrupt Force Register (CAPIFRC), offset 0x30.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t CEVT0         : 1;  /*!< bit:      0  CAPIFRC_BIT_CEVT0      */
        uint32_t CEVT1         : 1;  /*!< bit:      1  CAPIFRC_BIT_CEVT1      */
        uint32_t CEVT2         : 1;  /*!< bit:      2  CAPIFRC_BIT_CEVT2      */
        uint32_t CEVT3         : 1;  /*!< bit:      3  CAPIFRC_BIT_CEVT3      */
        uint32_t CNTOVF        : 1;  /*!< bit:      4  CAPIFRC_BIT_CNTOVF     */
        uint32_t PRD           : 1;  /*!< bit:      5  CAPIFRC_BIT_PRD        */
        uint32_t CMP           : 1;  /*!< bit:      6  CAPIFRC_BIT_CMP        */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CAPIFRC_REG;



/**
 *  @brief  Union type to access the Capture Register Write-Allow Key Register (CAPREGKEY), offset 0x34.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t KEY           :32;  /*!< bit: 31.. 0  CAPREGKEY_BIT_KEY      */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CAPREGKEY_REG;



/**
  *  @brief  Structure type to access the ECAP Controller (ECAP).
  */
typedef struct
{
    __IO CAPSRCCTL_REG       CAPSRCCTL            ; /*!< Offset: 0x00000000 (RW  )  Capture Source Input Control Register                  */
    __IO CAPSYNCICTL_REG     CAPSYNCICTL          ; /*!< Offset: 0x00000004 (RW  )  Capture Synchronization Source Input Control Register  */
    __IO CAPTSCNT_REG        CAPTSCNT             ; /*!< Offset: 0x00000008 (RW  )  Time-Stamp Counter Register                            */
    __IO CAPCNTPHS_REG       CAPCNTPHS            ; /*!< Offset: 0x0000000C (RW  )  Counter Phase Offset Value Register                    */
    __IO CAP0_REG            CAP0                 ; /*!< Offset: 0x00000010 (RW  )  Capture Register 0                                     */
    __IO CAP1_REG            CAP1                 ; /*!< Offset: 0x00000014 (RW  )  Capture Register 1                                     */
    __IO CAP2_REG            CAP2                 ; /*!< Offset: 0x00000018 (RW  )  Capture Register 2                                     */
    __IO CAP3_REG            CAP3                 ; /*!< Offset: 0x0000001C (RW  )  Capture Register 3                                     */
    __IO CAPCTL_REG          CAPCTL               ; /*!< Offset: 0x00000020 (RW  )  Capture Control Register                               */
    __I  CAPIF_REG           CAPIF                ; /*!< Offset: 0x00000024 (RO  )  Capture Interrupt Flag Register                        */
    __IO CAPIE_REG           CAPIE                ; /*!< Offset: 0x00000028 (RW  )  Capture Interrupt Enable Register                      */
    __O  CAPIC_REG           CAPIC                ; /*!< Offset: 0x0000002C (WO  )  Capture Interrupt Clear Register                       */
    __O  CAPIFRC_REG         CAPIFRC              ; /*!< Offset: 0x00000030 (WO  )  Capture Interrupt Force Register                       */
    __IO CAPREGKEY_REG       CAPREGKEY            ; /*!< Offset: 0x00000034 (RW  )  Capture Register Write-Allow Key Register              */
} ECAP_REGS;



/********************************************************************************
*
* Module Name     SIO
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the  (SIOM0), offset 0x0.
            Union type to access the  (SIOM1), offset 0x4.
            Union type to access the  (SIOM2), offset 0x8.
            ...
            Union type to access the  (SIOM30), offset 0x78.
            Union type to access the  (SIOM31), offset 0x7C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  SIOM0_BIT_VAL          
                                                       SIOM1_BIT_VAL          
                                                       SIOM2_BIT_VAL          
                                                       ...                    
                                                       SIOM30_BIT_VAL         
                                                       SIOM31_BIT_VAL         */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SIOMx_REG;



/**
 *  @brief  Union type to access the  (SIOSADDR), offset 0x80.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :10;  /*!< bit:  9.. 0  SIOSADDR_BIT_VAL       */
        uint32_t RESERVED_31_10:22;  /*!< bit: 31..10                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SIOSADDR_REG;



/**
 *  @brief  Union type to access the  (SIOSDATA), offset 0x84.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  SIOSDATA_BIT_VAL       */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SIOSDATA_REG;



/**
 *  @brief  Union type to access the  (SIOPLDPARA), offset 0x88.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  SIOPLDPARA_BIT_VAL     */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SIOPLDPARA_REG;



/**
 *  @brief  Union type to access the  (SIOSD0), offset 0xA0.
            Union type to access the  (SIOSD1), offset 0xA4.
            Union type to access the  (SIOSD2), offset 0xA8.
            ...
            Union type to access the  (SIOSD6), offset 0xB8.
            Union type to access the  (SIOSD7), offset 0xBC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  SIOSD0_BIT_VAL         
                                                       SIOSD1_BIT_VAL         
                                                       SIOSD2_BIT_VAL         
                                                       ...                    
                                                       SIOSD6_BIT_VAL         
                                                       SIOSD7_BIT_VAL         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SIOSDx_REG;



/**
 *  @brief  Union type to access the  (BSM000), offset 0x800.
            Union type to access the  (BSM001), offset 0x804.
            Union type to access the  (BSM002), offset 0x808.
            ...
            Union type to access the  (BSM510), offset 0xFF8.
            Union type to access the  (BSM511), offset 0xFFC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :24;  /*!< bit: 23.. 0  BSM000_BIT_VAL         
                                                       BSM001_BIT_VAL         
                                                       BSM002_BIT_VAL         
                                                       ...                    
                                                       BSM510_BIT_VAL         
                                                       BSM511_BIT_VAL         */
        uint32_t RESERVED_31_24: 8;  /*!< bit: 31..24                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} BSMx_REG;



/**
  *  @brief  Structure type to access the SIO Controller (SIO).
  */
typedef struct
{
    __IO SIOMx_REG          SIOM[32]            ; /*!< Offset: 0x00000000 (RW  )    */
    __IO SIOSADDR_REG       SIOSADDR            ; /*!< Offset: 0x00000080 (RW  )    */
    __IO SIOSDATA_REG       SIOSDATA            ; /*!< Offset: 0x00000084 (RW  )    */
    __IO SIOPLDPARA_REG     SIOPLDPARA          ; /*!< Offset: 0x00000088 (RW  )    */
         uint32_t           RESERVED0[5]        ; 
    __IO SIOSDx_REG         SIOSD[8]            ; /*!< Offset: 0x000000A0 (RW  )    */
         uint32_t           RESERVED1[464]      ; 
    __IO BSMx_REG           BSM[512]            ; /*!< Offset: 0x00000800 (RW  )    */
} SIO_REGS;




#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* SPC1168_REG_H */


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
