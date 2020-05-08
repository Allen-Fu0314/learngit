/*******************************************************************************
* @file     aes.h
* @brief    AES module header file.
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


#ifndef AES_H
#define AES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "spc1168.h"




/**
 *  @brief  AES running mode type definition
 */
typedef enum
{
  AES_MODE_ECB          = AESCTL0_BIT_MODE_ECB,         /*!< AES running mode: ECB          */
  AES_MODE_CBC          = AESCTL0_BIT_MODE_CBC,         /*!< AES running mode: CBC          */
  AES_MODE_CTR          = AESCTL0_BIT_MODE_CTR,         /*!< AES running mode: CTR          */
  AES_MODE_CCM          = AESCTL0_BIT_MODE_CCM,         /*!< AES running mode: CCM          */
  AES_MODE_MMO          = AESCTL0_BIT_MODE_MMO,         /*!< AES running mode: MMO          */
  AES_MODE_BYPASS       = AESCTL0_BIT_MODE_BYPASS,      /*!< AES running mode: Bypass       */
} AES_ModeEnum;




/**
 *  @brief  AES key size type definition
 */
typedef enum
{
  AES_KEYSIZE_16BYTE    = AESCTL0_BIT_KEYSIZE_16BYTE,   /*!< AES key size select: 16 bytes  */
  AES_KEYSIZE_32BYTE    = AESCTL0_BIT_KEYSIZE_32BYTE,   /*!< AES key size select: 32 bytes  */
  AES_KEYSIZE_24BYTE    = AESCTL0_BIT_KEYSIZE_24BYTE,   /*!< AES key size select: 24 bytes  */
} AES_KeySizeEnum;




/**
 *  @brief  AES MIC size type definition
 */
typedef enum
{
  AES_MICLEN_0BYTE      = AESCTL0_BIT_MICLEN_0BYTE,     /*!< AES MIC length: 0 bytes        */
  AES_MICLEN_4BYTE      = AESCTL0_BIT_MICLEN_4BYTE,     /*!< AES MIC length: 4 bytes        */
  AES_MICLEN_8BYTE      = AESCTL0_BIT_MICLEN_8BYTE,     /*!< AES MIC length: 8 bytes        */
  AES_MICLEN_16BYTE     = AESCTL0_BIT_MICLEN_16BYTE,    /*!< AES MIC length: 16 bytes       */
} AES_MicLenEnum;




/******************************************************************************
 * @brief      Start AES
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 ******************************************************************************/
#define AES_Start(AESx)                     ((AESx)->AESCTL0.all |= AESCTL0_ALL_START_AES_START)




/******************************************************************************
 * @brief      Set AES running mode
 *
 * @param[in]  AESx :  Select the AES module
 * @param[in]  eMode:  AES running mode
 *                     Please go to AES_ModeEnum for details
 *
 * @return     none
 *
 ******************************************************************************/
#define AES_SetRunningMode(AESx,eMode)      ((AESx)->AESCTL0.bit.MODE = eMode)




/******************************************************************************
 * @brief      Set the counter modular of CTR mode
 *
 * @param[in]  AESx :  Select the AES module
 * @param[in]  u8Mod:  The counter modular value
 *                     - \ref [7'h0-7'hF]: modular = 2^128
 *                     - \ref Others     : modular = 2^u8Mod
 *
 * @return     none
 *
 ******************************************************************************/
#define AES_SetCTRModular(AESx,u8Mod)       ((AESx)->AESCTL0.bit.CTRMOD = (u8Mod))




/******************************************************************************
 * @brief      AES Encrypt mode
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 ******************************************************************************/
#define AES_EncryptMode(AESx)               ((AESx)->AESCTL0.bit.DECRYPTEN = AESCTL0_BIT_DECRYPTEN_ENCRYPT)




/******************************************************************************
 * @brief      AES Decrypt mode
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 ******************************************************************************/
#define AES_DecryptMode(AESx)               ((AESx)->AESCTL0.bit.DECRYPTEN = AESCTL0_BIT_DECRYPTEN_DECRYPT)




/******************************************************************************
 * @brief      Append MIC at the end of output stream in CCM encryption mode or MMO mode
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 ******************************************************************************/
#define AES_EnableMICOutput(AESx)           ((AESx)->AESCTL0.bit.OUTMIC = AESCTL0_BIT_OUTMIC_ENABLE)




/******************************************************************************
 * @brief      Not Append MIC at the end of output stream in CCM encryption mode or MMO mode
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 ******************************************************************************/
#define AES_DisableMICOutput(AESx)          ((AESx)->AESCTL0.bit.OUTMIC = AESCTL0_BIT_OUTMIC_DISABLE)




/******************************************************************************
 * @brief      Ouptput stream to output FIFO
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 ******************************************************************************/
#define AES_EnableStreamOutput(AESx)        ((AESx)->AESCTL0.bit.OUTMSG = AESCTL0_BIT_OUTMSG_ENABLE)




/******************************************************************************
 * @brief      Block stream to output FIFO
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 ******************************************************************************/
#define AES_DisableStreamOutput(AESx)       ((AESx)->AESCTL0.bit.OUTMSG = AESCTL0_BIT_OUTMSG_DISABLE)




/******************************************************************************
 * @brief      Feed data in AES input stream
 *
 * @param[in]  AESx   :  Select the AES module
 * @param[in]  u32Data:  Data to be fed into input stream
 *
 * @return     none
 *
 ******************************************************************************/
#define AES_FeedData(AESx,u32Data)          ((AESx)->AESSTRIN.all = (u32Data))




/******************************************************************************
 * @brief      Read AES output data
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     Stream output data
 *
 ******************************************************************************/
#define AES_ReadData(AESx)                  ((AESx)->AESSTROUT.all)




/******************************************************************************
 * @brief      Clear input FIFO
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 ******************************************************************************/
#define AES_ClearInputFIFO(AESx)            ((AESx)->AESCTL0.all |= AESCTL0_ALL_IFIFOCLR_CLEAR)




/******************************************************************************
 * @brief      Clear output FIFO
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 ******************************************************************************/
#define AES_ClearOutputFIFO(AESx)           ((AESx)->AESCTL0.all |= AESCTL0_ALL_OFIFOCLR_CLEAR)




/******************************************************************************
 * @brief      Enable AES operation done interrupt
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 ******************************************************************************/
#define AES_EnableOperateDoneInt(AESx)      ((AESx)->AESIE.bit.DONE = AESIE_BIT_DONE_ENABLE)




/******************************************************************************
 * @brief      Disable AES operation done interrupt
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 ******************************************************************************/
#define AES_DisableOperateDoneInt(AESx)     ((AESx)->AESIE.bit.DONE = AESIE_BIT_DONE_DISABLE)




/******************************************************************************
 * @brief      Enable AES input FIFO full interrupt
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 ******************************************************************************/
#define AES_EnableInputFullInt(AESx)        ((AESx)->AESIE.bit.IFIFOFULL = AESIE_BIT_IFIFOFULL_ENABLE)




/******************************************************************************
 * @brief      Disable AES input FIFO full interrupt
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 ******************************************************************************/
#define AES_DisableInputFullInt(AESx)       ((AESx)->AESIE.bit.IFIFOFULL = AESIE_BIT_IFIFOFULL_DISABLE)




/******************************************************************************
 * @brief      Enable AES output FIFO empty interrupt
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 ******************************************************************************/
#define AES_EnableOutputEmptyInt(AESx)      ((AESx)->AESIE.bit.OFIFOEMPTY = AESIE_BIT_OFIFOEMPTY_ENABLE)




/******************************************************************************
 * @brief      Disable AES output FIFO empty interrupt
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 ******************************************************************************/
#define AES_DisableOutputEmptyInt(AESx)     ((AESx)->AESIE.bit.OFIFOEMPTY = AESIE_BIT_OFIFOEMPTY_DISABLE)




/******************************************************************************
 * @brief      Clear AES operation done interrupt status and raw status
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 ******************************************************************************/
#define AES_ClearOperateDoneInt(AESx)       ((AESx)->AESIC.all = AESIC_ALL_DONE_CLEAR)




/******************************************************************************
 * @brief      Clear AES input FIFO full interrupt status and raw status
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 ******************************************************************************/
#define AES_ClearInputFullInt(AESx)         ((AESx)->AESIC.all = AESIC_ALL_IFIFOFULL_CLEAR)




/******************************************************************************
 * @brief      Clear AES output FIFO empty interrupt staus and raw status
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 ******************************************************************************/
#define AES_ClearOutputEmptyInt(AESx)       ((AESx)->AESIC.all = AESIC_ALL_OFIFOEMPTY_CLEAR)




/******************************************************************************
 * @brief      Get AES operation done interrupt flag
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     0 - AES operation done interrupt not occurred
 *             1 - AES operation done interrupt occurred
 *
 ******************************************************************************/
#define AES_GetOperateDoneIntFlag(AESx)     ((AESx)->AESIF.bit.DONE)




/******************************************************************************
 * @brief      Get AES input FIFO full interrupt flag
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     0 - AES input FIFO full interrupt not occurred
 *             1 - AES input FIFO full interrupt occurred
 *
 ******************************************************************************/
#define AES_GetInputFullIntFlag(AESx)       ((AESx)->AESIF.bit.IFIFOFULL)




/******************************************************************************
 * @brief      Get AES output FIFO empty interrupt flag
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     0 - AES output FIFO empty interrupt not occurred
 *             1 - AES output FIFO empty interrupt occurred
 *
 ******************************************************************************/
#define AES_GetOutputEmptyIntFlag(AESx)     ((AESx)->AESIF.bit.OFIFOEMPTY)




/******************************************************************************
 * @brief      Get AES operation done interrupt raw flag
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     0 - AES operation done interrupt not occurred
 *             1 - AES operation done interrupt occurred
 *
 ******************************************************************************/
#define AES_GetOperateDoneIntRawFlag(AESx)  ((AESx)->AESRAWIF.bit.DONE)




/******************************************************************************
 * @brief      Get AES input FIFO full interrupt raw flag
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     0 - AES input FIFO full interrupt not occurred
 *             1 - AES input FIFO full interrupt occurred
 *
 ******************************************************************************/
#define AES_GetInputFullIntRawFlag(AESx)    ((AESx)->AESRAWIF.bit.IFIFOFULL)




/******************************************************************************
 * @brief      Get AES output FIFO empty interrupt raw flag
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     0 - AES output FIFO empty interrupt not occurred
 *             1 - AES output FIFO empty interrupt occurred
 *
 ******************************************************************************/
#define AES_GetOutputEmptyIntRawFlag(AESx)  ((AESx)->AESRAWIF.bit.OFIFOEMPTY)




/******************************************************************************
 * @brief      Is AES operation done
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     0 - AES operation has not done yet
 *             1 - AES operation done
 *
 ******************************************************************************/
#define AES_IsOperateDone(AESx)             ((AESx)->AESSTS.bit.DONE)




/******************************************************************************
 * @brief      Is AES input FIFO full
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     0 - Input FIFO is not full
 *             1 - Input FIFO is full
 *
 ******************************************************************************/
#define AES_IsInputFull(AESx)               ((AESx)->AESSTS.bit.IFIFOFULL)




/******************************************************************************
 * @brief      Is AES output FIFO ready to read
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     0 - Output FIFO is not ready to read
 *             1 - Output FIFO is ready to read
 *
 ******************************************************************************/
#define AES_IsOutputReady(AESx)             ((AESx)->AESSTS.bit.OFIFORDY)




/******************************************************************************
 * @brief      Is AES output FIFO empty
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     0 - Output FIFO is not empty
 *             1 - Output FIFO is empty
 *
 ******************************************************************************/
#define AES_IsOutputEmpty(AESx)             ((AESx)->AESSTS.bit.OFIFOEMPTY)




/******************************************************************************
 * @brief      Is AES operation error
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     0 - No operation error
 *             1 - Operation error occurred
 *
 ******************************************************************************/
#define AES_IsOperateError(AESx)            (((AESx)->AESSTS.bit.ERRCODE)? (1) : (0))




/**
 *  @brief  AES Public Function Declaration
 */
void AES_CBCModeInit(AES_REGS* AESx, uint32_t au32IV[], uint32_t au32Key[], AES_KeySizeEnum eKeySize, uint32_t u32MstrLen);
void AES_CCMModeInit(AES_REGS* AESx, uint32_t au32IV[], uint32_t au32Key[], AES_KeySizeEnum eKeySize, uint32_t u32MstrLen, uint32_t u32AstrLen);

ErrorStatus AES_EncryptData(AES_REGS* AESx, uint32_t u32DataIn[], uint32_t u32DataOut[], uint32_t u32InLen, uint32_t u32OutLen);
ErrorStatus AES_DecryptData(AES_REGS* AESx, uint32_t u32DataIn[], uint32_t u32DataOut[], uint32_t u32InLen, uint32_t u32OutLen);

void AES_ReadMIC(AES_REGS* AESx, uint32_t *pu32MicData, AES_MicLenEnum eMicLen);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* AES_H */


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
