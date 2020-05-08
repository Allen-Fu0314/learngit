/******************************************************************************
 * @file     aes.c
 * @brief    AES firmware functions.
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

#include "aes.h"




/******************************************************************************
 * @brief      AES CBC mode initialize with some predefined configurations
 *
 * @param[in]  AESx      :  Select the AES module
 * @param[in]  au32IV    :  Array stores AES initial vectors
 * @param[in]  au32Key   :  Array stores AES Keys
 * @param[in]  eKeySize  :  Key size
 * @param[in]  u32MstrLen:  M-String length (in bytes)
 *
 * @return     none
 *
 ******************************************************************************/
void AES_CBCModeInit(AES_REGS* AESx, uint32_t au32IV[], uint32_t au32Key[], AES_KeySizeEnum eKeySize, uint32_t u32MstrLen)
{
  uint32_t i, j;
  
  /* Clear Interrupt Flags and Raw Flags */
  AESx->AESIC.all =  AESIC_ALL_DONE_CLEAR 
                   | AESIC_ALL_IFIFOFULL_CLEAR 
                   | AESIC_ALL_OFIFOEMPTY_CLEAR;
  
  /* CBC Mode */
  AESx->AESCTL0.bit.MODE = AESCTL0_BIT_MODE_CBC;
  
  /* Encryption */
  AESx->AESCTL0.bit.DECRYPTEN = AESCTL0_BIT_DECRYPTEN_ENCRYPT;
  
  /* Key Size */
  AESx->AESCTL0.bit.KEYSIZE = eKeySize;
  
  /* Set Init Vector */
  for(i = 0; i < 4; i++)
  {
    AESx->AESIV[3 - i].all = au32IV[i];
  }
  
  j = (eKeySize < 2)? (4 << eKeySize) : 6;
  /* Set AES Key */
  for(i = 0; i < j; i++)
  {
    AESx->AESKEY[7 - i].all = au32Key[i];
  }
  
  /* Set A-String Length */
  AESx->AESASTRLEN.all = 0;
  
  /* Set M-String Length */
  AESx->AESMSTRLEN.all = u32MstrLen;
}




/******************************************************************************
 * @brief      AES CCM mode initialize with some predefined configurations
 *
 * @param[in]  AESx      :  Select the AES module
 * @param[in]  au32IV    :  Array stores AES initial vectors
 * @param[in]  au32Key   :  Array stores AES Keys
 * @param[in]  eKeySize  :  Key size
 * @param[in]  u32MstrLen:  M-String length (in bytes)
 * @param[in]  u32MstrLen:  A-String length (in bytes)
 *
 * @return     none
 *
 ******************************************************************************/
void AES_CCMModeInit(AES_REGS* AESx, uint32_t au32IV[], uint32_t au32Key[], AES_KeySizeEnum eKeySize, uint32_t u32MstrLen, uint32_t u32AstrLen)
{
  uint32_t i, j;
  
  /* Clear Interrupt Flags and Raw Flags */
  AESx->AESIC.all =  AESIC_ALL_DONE_CLEAR 
                   | AESIC_ALL_IFIFOFULL_CLEAR 
                   | AESIC_ALL_OFIFOEMPTY_CLEAR;
  
  /* CCM Mode */
  AESx->AESCTL0.bit.MODE = AESCTL0_BIT_MODE_CCM;
  
  /* Encryption */
  AESx->AESCTL0.bit.DECRYPTEN = AESCTL0_BIT_DECRYPTEN_ENCRYPT;
  
  /* Key Size */
  AESx->AESCTL0.bit.KEYSIZE = eKeySize;
  
  /* MIC Length = 16 Bytes  */
  AESx->AESCTL0.bit.MICLEN = AESCTL0_BIT_MICLEN_16BYTE;
  
  /* Set Init Vector */
  for(i = 0; i < 4; i++)
  {
    AESx->AESIV[3 - i].all = au32IV[i];
  }
  
  j = (eKeySize < 2)? (4 << eKeySize) : 6;
  /* Set AES Key */
  for(i = 0; i < j; i++)
  {
    AESx->AESKEY[7 - i].all = au32Key[i];
  }
  
  /* Set A-String Length */
  AESx->AESASTRLEN.all = u32AstrLen;
  
  /* Set M-String Length */
  AESx->AESMSTRLEN.all = u32MstrLen;
  
  /* Enable MIC output */
  AESx->AESCTL0.bit.OUTMIC = AESCTL0_BIT_OUTMIC_ENABLE;
}




/******************************************************************************
 * @brief      Encrypt data
 *
 * @param[in]  AESx      :  Select the AES module
 * @param[in]  u32DataIn :  Array stores raw data
 * @param[in]  u32DataOut:  Array stores encrypted data
 * @param[in]  u32InLen  :  Raw data length (in words)
 * @param[in]  u32OutLen :  Encrypted data length (in words)
 *
 * @return     SUCCESS or ERROR
 *
 ******************************************************************************/
ErrorStatus AES_EncryptData(AES_REGS* AESx, uint32_t u32DataIn[], uint32_t u32DataOut[], uint32_t u32InLen, uint32_t u32OutLen)
{
  uint32_t i = 0, j = 0;
  
  /* Set AES operate mode */
  AES_EncryptMode(AESx);
  
  /* Clear Input FIFO */
  AES_ClearInputFIFO(AESx);
  
  /* Clear Output FIFO */
  AES_ClearOutputFIFO(AESx);
  
  /* Start AES operation */
  AES_Start(AESx);
  
  /* Check AES operation error */
  if(AES_IsOperateError(AESx))
  {
    return ERROR;
  }
  
  /* Write and Read */
  while((i < u32InLen) || (j < u32OutLen))
  {
    /* Write raw data to input fifo */
    while((i < u32InLen) && (AES_IsInputFull(AESx) != 1))
    {
      AES_FeedData(AESx, u32DataIn[i++]);
    }
    
    /* Read encrypted data from output fifo */
    while((j < u32OutLen) && (AES_IsOutputEmpty(AESx) != 1))
    {
      u32DataOut[j++] = AES_ReadData(AESx);
    }
  }
  
  /* Wait until AES operation done */
  while(AES_IsOperateDone(AESx) != 1);
  
  /* Check AES operation error */
  if(AES_IsOperateError(AESx))
  {
    return ERROR;
  }
  
  return SUCCESS;
}




/******************************************************************************
 * @brief      Decrypt data
 *
 * @param[in]  AESx      :  Select the AES module
 * @param[in]  u32DataIn :  Array stores encrypted data
 * @param[in]  u32DataOut:  Array stores decrypted data
 * @param[in]  u32InLen  :  Encrypted data length (in words)
 * @param[in]  u32OutLen :  Decrypted data length (in words)
 *
 * @return     SUCCESS or ERROR
 *
 ******************************************************************************/
ErrorStatus AES_DecryptData(AES_REGS* AESx, uint32_t u32DataIn[], uint32_t u32DataOut[], uint32_t u32InLen, uint32_t u32OutLen)
{
  uint32_t i = 0, j = 0;
  
  /* Set AES operate mode */
  AES_DecryptMode(AESx);
  
  /* Clear Input FIFO */
  AES_ClearInputFIFO(AESx);
  
  /* Clear Output FIFO */
  AES_ClearOutputFIFO(AESx);
  
  /* Start AES operation */
  AES_Start(AESx);
  
  /* Check AES operation error */
  if(AES_IsOperateError(AESx))
  {
    return ERROR;
  }
  
  /* Write and Read */
  while((i < u32InLen) || (j < u32OutLen))
  {
    /* Write encrypted data to input fifo */
    while((i < u32InLen) && (AES_IsInputFull(AESx) != 1))
    {
      AES_FeedData(AESx, u32DataIn[i++]);
    }
    
    /* Read decrypted data from output fifo */
    while((j < u32OutLen) && (AES_IsOutputEmpty(AESx) != 1))
    {
      u32DataOut[j++] = AES_ReadData(AESx);
    }
  }
  
  /* Wait until AES operation done */
  while(AES_IsOperateDone(AESx) != 1);
  
  /* Check AES operation error */
  if(AES_IsOperateError(AESx))
  {
    return ERROR;
  }
  
  return SUCCESS;
}




/******************************************************************************
 * @brief      Read AES MIC result
 *
 * @param[in]  AESx        :  Select the AES module
 * @param[in]  eMicLen     :  Expected MIC data length
 *                            Please see AES_MicLenEnum for detail
 *
 * @param[out]  pu32MicData:  Pointer to the array that stored MIC result
 *
 * @return     none
 *
 ******************************************************************************/
void AES_ReadMIC(AES_REGS* AESx, uint32_t *pu32MicData, AES_MicLenEnum eMicLen)
{
  /* Captured the mic data */
  switch(eMicLen)
  {
    case 0:
      pu32MicData[0] = AESx->AESOV[3].all;
      break;
    
    case 1:
      pu32MicData[0] = AESx->AESOV[2].all;
      pu32MicData[1] = AESx->AESOV[3].all;
      break;
    
    case 2:
      pu32MicData[0] = AESx->AESOV[1].all;
      pu32MicData[1] = AESx->AESOV[2].all;
      pu32MicData[2] = AESx->AESOV[3].all;
      break;
    
    case 3:
      pu32MicData[0] = AESx->AESOV[0].all;
      pu32MicData[1] = AESx->AESOV[1].all;
      pu32MicData[2] = AESx->AESOV[2].all;
      pu32MicData[3] = AESx->AESOV[3].all;
      break;
    
    default:
      break;
  }
}


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
