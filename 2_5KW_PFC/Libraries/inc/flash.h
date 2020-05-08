/******************************************************************************
 * @file     flash.h
 * @brief    FLASH module header file.
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


#ifndef FLASH_H
#define FLASH_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1168.h"




/**
 *  @brief  FLASH Command Declaration
 */
#define FLASH_CMD_READ            0x01      /*!< Read a word data         */
#define FLASH_CMD_PROG_WORD       0x05      /*!< Program a word data      */
#define FLASH_CMD_ERASE_SECTOR    0x08      /*!< Erase Sector (512 Byte)  */
#define FLASH_CMD_ERASE_CHIP      0x0A      /*!< Erase Flash Chip         */




/**
 *  @brief  FLASH Constants
 */
#define FLASH_CHIP_SIZE           0x20000     /*!< Flash Size = 128KB              */
#define FLASH_SECTOR_SIZE         0x200       /*!< Flash Sector Size = 512B        */
#define FLASH_START_ADDR          0x10000000  /*!< Flash main memory start address */


#define OTP_START_ADDR            0x11000400  /*!< OTP Flash sector start address           */
#define CONFIG_START_ADDR         0x11000600  /*!< Configuration words sector start address */




/******************************************************************************
 * @brief      Enable XIP interface
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define FLASH_EnableXIP()         (FLASH->FLASHCTL.bit.XIPEN = FLASHCTL_BIT_XIPEN_ENABLE)




/******************************************************************************
 * @brief      Disable XIP interface
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define FLASH_DisableXIP()        (FLASH->FLASHCTL.bit.XIPEN = FLASHCTL_BIT_XIPEN_DISABLE)




/******************************************************************************
 * @brief      Enable write access to the protected FLASH registers
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define FLASH_WALLOW()            (FLASH->FLASHREGKEY.all = 0x1ACCE551)




/******************************************************************************
 * @brief      Disable write access to the protected FLASH registers
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
#define FLASH_WDIS()              (FLASH->FLASHREGKEY.all = 0x0)




/**
 *  @brief FLASH Public Function Declaration
 */
void FLASH_Read(uint32_t *pu32Buf, uint32_t u32Addr, uint32_t u32NumWords);
ErrorStatus FLASH_ProgramWord(uint32_t u32Data, uint32_t u32Addr);
ErrorStatus FLASH_Program(uint32_t *pu32Buf, uint32_t u32Addr, uint32_t u32NumWords);
void FLASH_EraseSector(uint32_t u32SectorAddr);
void FLASH_EraseChip(void);

void FLASH_WriteProtect(uint32_t u32StartAddr, uint32_t u32EndAddr);
ErrorStatus FLASH_SetTiming(uint32_t u32ClkFreq);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* FLASH_H */


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
