/******************************************************************************
 * @file     ssp.c
 * @brief    SSP firmware functions.
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

#include "ssp.h"




/******************************************************************************
 * @brief      Initializes the SSP
 *
 * @param[in]  SSPx            :  Select the SSP port
 * @param[in]  u8MasterOrSlave :  Define SSP in master or slave mode
 *                                 - \ref SSP_MASTER_MODE
 *                                 - \ref SSP_SLAVE_MODE
 * @param[in]  u8DataSize      :  Define SSP data size in one frame
 * @param[in]  u32Baudrate     :  Define SSP baudrate
 * @param[in]  u1FramePolarity :  Select frame polarity from
 *                                SSP_FramePolarityEnum
 * @param[in]  u1ClockIdleLevel:  Select clock idle state from
 *                                SSP_ClockIdleLevelEnum
 * @param[in]  u1DataSendEdge  :  Select send data on which clock edge from
 *                                SSP_SendDataEdgeEnum
 *
 * @return     none
 *
 ******************************************************************************/
void SSP_Init(SSP_REGS* SSPx, uint8_t u8MasterOrSlave, uint8_t u8DataSize, uint32_t u32Baudrate, SSP_FramePolarityEnum u1FramePolarity, SSP_ClockIdleLevelEnum u1ClockIdleLevel, SSP_SendDataEdgeEnum u1DataSendEdge)
{
  /* Enable SSP clock */
  CLOCK_EnableModule(SSP_MODULE);

  /* Set SSP clock divider */
  CLOCK->SSPCLKCTL.bit.DIV = (SystemCoreClock / u32Baudrate - 1);
  
  /* Disable SSP */
  SSP_Disable(SSPx);
  
  /* Configure SSP function mode: Master or Slave */
  if(u8MasterOrSlave == SSP_MASTER_MODE)
  {
    SSPx->SSPCTL1.bit.FRMDIR = SSPCTL1_BIT_FRMDIR_MASTER_MODE;
    SSPx->SSPCTL1.bit.CLKDIR = SSPCTL1_BIT_CLKDIR_MASTER_MODE;
  }
  else
  {
    SSPx->SSPCTL1.bit.FRMDIR = SSPCTL1_BIT_FRMDIR_SLAVE_MODE;
    SSPx->SSPCTL1.bit.CLKDIR = SSPCTL1_BIT_CLKDIR_SLAVE_MODE;
    /* Use external clock in slave mode */
    SSPx->SSPCTL1.bit.SLVCLKSEL = SSPCTL1_BIT_SLVCLKSEL_SLAVE_EXTENAL_SCLK;
  }

  /* Configure SSP data size */
  if (u8DataSize <= 16)
  {
    SSPx->SSPCTL0.bit.ESIZESEL = SSPCTL0_BIT_ESIZESEL_DISABLE;
    SSPx->SSPCTL0.bit.SIZESEL = u8DataSize - 1;
  }
  else
  {
    SSPx->SSPCTL0.bit.ESIZESEL = SSPCTL0_BIT_ESIZESEL_ENABLE;
    SSPx->SSPCTL0.bit.SIZESEL = u8DataSize - 17;
  }

  /* Configure SSP Frame level according to user selection */
  SSPx->SSPCTL1.bit.FRMINV = u1FramePolarity;

  /* Configure SSP clock idle level according to user selection */
  SSPx->SSPCTL1.bit.CLKPOL = u1ClockIdleLevel;

  /* Configure SSP clock phase according to user selection */
  if(u1DataSendEdge == SSP_SEND_ON_RISING_EDGE)
  {
    /* CLKPHS = !CLKPOL */
    SSPx->SSPCTL1.bit.CLKPHS = ((u1ClockIdleLevel == 0)? 1 : 0);
  }
  else
  {
    /* CLKPHS = CLKPOS */
    SSPx->SSPCTL1.bit.CLKPHS = u1ClockIdleLevel;
  }

  /* Disable TXUDF and RXOVF interrupt */
  SSPx->SSPCTL0.bit.TFINTMSK = SSPCTL0_BIT_TFINTMSK_MASK;
  SSPx->SSPCTL0.bit.RFINTMSK = SSPCTL0_BIT_RFINTMSK_MASK;
}




/******************************************************************************
 * @brief      Initializes the SSP with pre-define settings
 *
 * @param[in]  SSPx           :  Select the SSP port
 * @param[in]  u8MasterOrSlave:  Define SSP in master or slave mode
 * @param[in]  u8DataSize     :  Define SSP data size in one frame
 * @param[in]  u32Baudrate    :  Define SSP baudrate
 *
 * @return     none
 *
 * @detail     As in a lot of SPI application scenario,
 *             Frame is active Low
 *             Clock idle      Low
 *             Data send on    Rising edge
 *             In these cases, user can use this funtion as a simple method to configure SSP
 *
 ******************************************************************************/
void SSP_InitEasy(SSP_REGS* SSPx, uint8_t u8MasterOrSlave, uint8_t u8DataSize, uint32_t u32Baudrate)
{
  SSP_Init(SSPx, u8MasterOrSlave, u8DataSize, u32Baudrate, SSP_FRM_ACTIVE_LOW, SSP_CLK_IDLE_LOW, SSP_SEND_ON_RISING_EDGE);
}




/******************************************************************************
 * @brief      Send data to SSP peripheral (Single Frame mode, Send only)
 *
 * @param[in]  SSPx    :  Select the SSP port
 * @param[in]  pu32Buf :  Pointer to the array that stored data to be sent
 * @param[in]  u32Count:  Number of data to be sent
 *
 * @return     none
 *
 ******************************************************************************/
void SSP_Send(SSP_REGS* SSPx, uint32_t *pu32Buf, uint32_t u32Count)
{
  uint32_t i;

  for(i = 0; i < u32Count; i++)
  {
    /* Wait until TxFIFO empty */
    while((SSP_GetTxFIFOLevel(SSPx) != 0) || (!SSP_IsTxNotFull(SSPx)));

    /* Send data */
    SSP_SendData(SSPx, pu32Buf[i]);
  }
}




/******************************************************************************
 * @brief      Receive data from SSP peripheral
 *
 * @param[in]  SSPx    :  Select the SSP port
 * @param[in]  pu32Buf :  Pointer to the buffer that stored the reveived data
 * @param[in]  u32Count:  Number of data to be received
 *
 * @return     Number of data that has been received
 *
 ******************************************************************************/
uint32_t SSP_Receive(SSP_REGS* SSPx, uint32_t *pu32Buf, uint32_t u32Count)
{
  uint32_t i;

  for(i = 0; i < u32Count; i++)
  {
    /* If RxFIFO was empty, just return */
    if(!SSP_IsRxNotEmpty(SSPx))
    {
      return i;
    }

    /* Receive data */
    pu32Buf[i] = SSP_ReceiveData(SSPx);
  }

  return i;
}




/******************************************************************************
 * @brief      SSP Master Transmit and Receive data (Single Frame mode, Full Duplex)
 *
 * @param[in]  SSPx           :  Select the SSP port
 * @param[in]  pu32WriteBuffer:  Pointer to the buffer that stored the data to be send
 * @param[in]  pu32ReadBuffer :  Pointer to the buffer that stored the reveived data
 * @param[in]  u32Count       :  Number of data to be send or received
 *
 * @return     none
 *
 ******************************************************************************/
void SSP_MasterTransceive(SSP_REGS* SSPx, uint32_t *pu32WriteBuffer, uint32_t *pu32ReadBuffer, uint32_t u32Count)
{
  uint32_t i;

  for(i = 0; i < u32Count; i++)
  {
    /* Wait until TxFIFO is empty */
    while((SSP_GetTxFIFOLevel(SSPx) != 0) || (!SSP_IsTxNotFull(SSPx)));

    /* Write data to TxFIFO */
    SSP_SendData(SSPx, *pu32WriteBuffer++);

    /* Wait until RxFIFO is not empty */
    while(!SSP_IsRxNotEmpty(SSPx));

    /* Read data from RxFIFO */
    *pu32ReadBuffer++ = SSP_ReceiveData(SSPx);
  }
}




/******************************************************************************
 * @brief      SSP Master Back-to-back Transmit and Receive data (Back to Back Mode)
 *
 * @param[in]  SSPx           :  Select the SSP port
 * @param[in]  pu32WriteBuffer:  Pointer to the buffer that stored the data to be send
 * @param[in]  pu32ReadBuffer :  Pointer to the buffer that stored the reveived data
 * @param[in]  u32Count       :  Number of data to be send or received
 *
 * @return     none
 *
 ******************************************************************************/
void SSP_MasterB2BTransceive(SSP_REGS* SSPx, uint32_t *pu32WriteBuffer, uint32_t *pu32ReadBuffer, uint32_t u32Count)
{
  uint32_t u32RxCnt, u32TxCnt;
  uint32_t u32Delta;
  
  /* Initial index */
  u32RxCnt = 0;

  /* Wait until TxFIFO empty */
  while((SSP_GetTxFIFOLevel(SSPx) != 0) || (!SSP_IsTxNotFull(SSPx)));

  /* Write TxFIFO as quickly as possible, ensure TxFIFO not empty during SFRM active */
  if(u32Count <= SSP_FIFO_DEPTH)
  {
    u32Delta = u32Count ;
    
    while(u32Delta--)
    {
      /* Write data to TxFIFO */
      SSP_SendData(SSPx, *pu32WriteBuffer++);
    }
  }
  else
  {
    /* Initial index */
    u32TxCnt = 0;

    /* Send data during SFRM active */
    while(u32TxCnt < u32Count)
    {
      if(SSP_IsTxNotFull(SSPx))
      {
        u32Delta = u32Count - u32TxCnt;

        /* Data count that can be sent to TxFIFO */
        if((SSP_FIFO_DEPTH - SSP_GetTxFIFOLevel(SSPx)) < u32Delta)
        {
          u32Delta = SSP_FIFO_DEPTH - SSP_GetTxFIFOLevel(SSPx);
        }
        
        u32TxCnt += u32Delta;
        
        while(u32Delta--)
        {
          /* Write data to TxFIFO */
          SSP_SendData(SSPx, *pu32WriteBuffer++);

          /* Read RxFIFO if RxFIFO not empty */
          if(SSP_IsRxNotEmpty(SSPx))
          {
            /* Read  data from RxFIFO */
            *pu32ReadBuffer++ = SSP_ReceiveData(SSPx);
            u32RxCnt++;
          }
        }
      }
    }
  }

  /* Receive all datas during SFRM active */
  while(u32RxCnt < u32Count)
  {
    while(SSP_IsRxNotEmpty(SSPx))
    {
      /* Read data from RxFIFO */
      *pu32ReadBuffer++ = SSP_ReceiveData(SSPx);
      u32RxCnt++;
    }
  }
}




/******************************************************************************
 * @brief      SSP Slave Transmit and Receive data (Full Duplex)
 *
 * @param[in]  SSPx            :  Select the SSP port
 * @param[in]  pu32WriteBuffer :  Pointer to the buffer that stored the data to be send
 * @param[in]  pu32ReadBuffer  :  Pointer to the buffer that stored the reveived data
 * @param[in]  u32Count        :  Number of data to be send or received
 *
 * @return     none
 *
 ******************************************************************************/
void SSP_SlaveTransceive(SSP_REGS* SSPx, uint32_t *pu32WriteBuffer, uint32_t *pu32ReadBuffer, uint32_t u32Count)
{
  uint32_t u32RxCnt = 0;
  uint32_t u32TxCnt = 0;

  while(u32TxCnt < u32Count)
  {
    /* Write TxFIFO if TxFIFO is not full */
    if(SSP_IsTxNotFull(SSPx))
    {
      /* Write TxFIFO */
      SSP_SendData(SSPx, pu32WriteBuffer[u32TxCnt++]);
    }

    /* Read RxFIFO if RxFIFO is not empty */
    if(SSP_IsRxNotEmpty(SSPx))
    {
      /* Read RxFIFO */
      pu32ReadBuffer[u32RxCnt++] = SSP_ReceiveData(SSPx);
    }
  }

  /* Read RxFIFO until RxFIFO is empty */
  while(u32RxCnt < u32Count)
  {
    /* Read RxFIFO if RxFIFO is not empty */
    if( SSP_IsRxNotEmpty(SSPx) )
    {
      /* Read RxFIFO */
      pu32ReadBuffer[u32RxCnt++] = SSP_ReceiveData(SSPx);
    }
  }
}


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
