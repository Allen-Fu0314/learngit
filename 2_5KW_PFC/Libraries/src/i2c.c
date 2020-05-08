/******************************************************************************
 * @file     i2c.c
 * @brief    I2C firmware functions.
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

#include "i2c.h"




/******************************************************************************
 * @brief      Initializes I2C Speed
 *
 * @param[in]  I2Cx    :  Select the I2C module
 * @param[in]  u32Speed:  Operation speed (bps)
 *
 * @return     ErrorStatus:
 *                  ERROR if I2C clock is not fast enough to support the speed
 *
 ******************************************************************************/
ErrorStatus I2C_SpeedInit(I2C_REGS* I2Cx, uint32_t u32Speed)
{
  uint32_t u32PCnt;
  uint32_t u32HCnt;
  uint32_t u32LCnt;
  uint32_t u32LCntMin;
  uint32_t u32SpikeLen;
  uint32_t u32ClkFreq;
  
  u32ClkFreq = CLOCK_GetModuleClock(I2C_MODULE);
  u32PCnt    = u32ClkFreq / u32Speed;
  
  /* Standard mode (100 kbps) */
  if(u32Speed <= 100000)
  {
    u32SpikeLen = u32ClkFreq / 20000000;
    if((u32SpikeLen * 20000000) != u32ClkFreq)
    {
      u32SpikeLen = u32SpikeLen + 1;
    }
    
    u32LCntMin  = 47 * u32ClkFreq /10000000;
    if((u32LCntMin * 10000000) == (47 * u32ClkFreq))
    {
      u32LCntMin = u32LCntMin + 1;
    }
    else
    {
      u32LCntMin = u32LCntMin + 2;
    }
    
    if (u32LCntMin > (u32PCnt / 2))
    {
      u32LCnt = u32LCntMin;
    }
    else
    {
      u32LCnt = u32PCnt / 2;
    }
    
    u32HCnt = u32PCnt - u32LCnt;
    
    /* Check whether I2C clock is fast enough to support the speed */
    if ((u32LCnt < 9) || (u32HCnt < (u32SpikeLen + 13)))
    {
      return ERROR;
    }
    
    /* Set I2C operating speed mode */
    I2Cx->I2CCTL.bit.SPEED = I2CCTL_BIT_SPEED_100K_BPS;

    /* Spike suppresion */
    I2Cx->I2CFSSPKLEN.all = u32SpikeLen;
    
    /* Standard mode SCL hold low time counter */
    I2Cx->I2CSSLCNT.all = u32LCnt - 1;

    /* Standard mode SCL hold high time counter */
    I2Cx->I2CSSHCNT.all = u32HCnt - 7 - u32SpikeLen;
  }

  /* Fast mode (400 kbps) */
  else if (u32Speed <= 400000)
  {
    u32SpikeLen = u32ClkFreq / 20000000;
    if((u32SpikeLen * 20000000) != u32ClkFreq)
    {
      u32SpikeLen = u32SpikeLen + 1;
    }
    
    u32LCntMin = 13 * u32ClkFreq / 10000000;
    if((u32LCntMin * 10000000) == (13 * u32ClkFreq))
    {
      u32LCntMin = u32LCntMin + 1;
    }
    else
    {
      u32LCntMin = u32LCntMin + 2;
    }
    
    if(u32LCntMin > (u32PCnt / 2))
    {
      u32LCnt = u32LCntMin;
    }
    else
    {
      u32LCnt = u32PCnt / 2;
    }
    
    u32HCnt = u32PCnt - u32LCnt;
    
    /* Check whether I2C clock is fast enough to support the speed */
    if((u32LCnt < 9) || ( u32HCnt < (u32SpikeLen + 13)))
    {
      return ERROR;
    }
    
    /* Set I2C operating speed mode */
    I2Cx->I2CCTL.bit.SPEED = I2CCTL_BIT_SPEED_400K_BPS;

    /* Spike suppresion */
    I2Cx->I2CFSSPKLEN.all = u32SpikeLen;
    
    /* Fast mode SCL hold low time counter */
    I2Cx->I2CFSLCNT.all = u32LCnt - 1;
    
    /* Fast mode SCL hold high time counter */
    I2Cx->I2CFSHCNT.all = u32HCnt - 7 - u32SpikeLen;
  }

  /* High speed mode (3.4 Mbps) */
  else
  {
    u32SpikeLen = u32ClkFreq / 100000000;
    if((u32SpikeLen * 100000000) != u32ClkFreq)
    {
      u32SpikeLen = u32SpikeLen + 1;
    }
    
    u32HCnt = u32PCnt / 3;
    u32LCnt = u32HCnt * 2;
    /* Check whether I2C clock is fast enough to support the speed */
    if((u32LCnt < 9) || (u32HCnt < (u32SpikeLen + 13)))
    {
      return ERROR;
    }
    
    /* Set I2C operating speed mode */
    I2Cx->I2CCTL.bit.SPEED = I2CCTL_BIT_SPEED_3400K_BPS;

    /* High mode SCL hold low time counter */
    I2Cx->I2CHSLCNT.all = u32LCnt - 1;

    /* High mode SCL hold high time counter */
    I2Cx->I2CHSHCNT.all = u32HCnt - 7 - u32SpikeLen;
  }
  return SUCCESS;
}




/******************************************************************************
 * @brief      Initializes the I2C master
 *
 * @param[in]  I2Cx    :  Select the I2C module
 * @param[in]  u32Speed:  Operation speed (bps)
 *
 * @return     ErrorStatus:
 *                  ERROR if I2C clock is not fast enough to support the speed
 *
 ******************************************************************************/
ErrorStatus I2C_MasterInit(I2C_REGS* I2Cx, uint32_t u32Speed)
{
  /* Enable I2C Module Clock */
  CLOCK_EnableModule(I2C_MODULE);
  
  /* Disable I2C */
  I2Cx->I2CENABLE.all = 0;

  /* Slave is diable */
  I2Cx->I2CCTL.bit.SLVDIS = I2CCTL_BIT_SLVDIS_SLAVE_DISABLE;

  /* Master enable */
  I2Cx->I2CCTL.bit.MASTER = I2CCTL_BIT_MASTER_ENABLE;

  /* Restart enable */
  I2Cx->I2CCTL.bit.RESTARTEN = I2CCTL_BIT_RESTARTEN_ENABLE;

  /* Init I2C Speed */
  if(u32Speed > 400000) /* For high-speed mode, set fast-speed as 400k */
  {
    I2C_SpeedInit(I2Cx, 400000);
  }
  
  if(I2C_SpeedInit(I2Cx, u32Speed) == SUCCESS)
  {
    /* Enable I2C */
    I2Cx->I2CENABLE.all = I2CENABLE_ALL_EN_ENABLE;
    return SUCCESS;
  }
  else
  {
    return ERROR;
  }
}




/******************************************************************************
 * @brief      Initializes the I2C slave
 *
 * @param[in]  I2Cx      :  Select the I2C module
 * @param[in]  eAddrMode :  Address mode
 *                          See I2C_AddrModeEnum for details
 *                           - \ref I2C_ADDR_7BIT
 *                           - \ref I2C_ADDR_10BIT
 * @param[in]  u16SlvAddr:  Slave address
 * @param[in]  u32Speed  :  Operation speed (bps)
 *
 * @return     ErrorStatus:
 *                  ERROR if I2C clock is not fast enough to support the speed
 *
 ******************************************************************************/
ErrorStatus I2C_SlaveInit(I2C_REGS* I2Cx, I2C_AddrModeEnum eAddrMode, uint16_t u16SlvAddr, uint32_t u32Speed)
{
  uint32_t u32SDASetup;
  
  /* Enable I2C Module Clock */
  CLOCK_EnableModule(I2C_MODULE);
  
  /* Disable I2C */
  I2Cx->I2CENABLE.all = 0;

  /* Slave is enable */
  I2Cx->I2CCTL.bit.SLVDIS = I2CCTL_BIT_SLVDIS_SLAVE_ENABLE;

  /* Master disable */
  I2Cx->I2CCTL.bit.MASTER = I2CCTL_BIT_MASTER_DISABLE;

  /* Restart enable */
  I2Cx->I2CCTL.bit.RESTARTEN = I2CCTL_BIT_RESTARTEN_ENABLE;

  /* Slave address mode */
  I2Cx->I2CCTL.bit.SLVADDR10B = eAddrMode;

  /* Slave address */
  I2Cx->I2CSLVADDR.all = u16SlvAddr;

  if(u32Speed <= 100000)
  {
    /* SDA Minimum Set Up Delay 250ns */
    u32SDASetup = CLOCK_GetModuleClock(I2C_MODULE) / 4000000 + 1;
  }
  else if (u32Speed <= 400000)
  {
    /* SDA Minimum Set Up Delay 100ns */
    u32SDASetup = CLOCK_GetModuleClock(I2C_MODULE) / 10000000 + 1;
  }
  else
  {
    /* SDA Minimum Set Up Delay 30ns */
    u32SDASetup = CLOCK_GetModuleClock(I2C_MODULE) * 3 / 100000000 + 1;
  }

  /* Check whether I2C clock is fast enough to support the speed */
  if(u32SDASetup < 2)
  {
    return ERROR;
  }
  else
  {
    I2Cx->I2CSDASETUP.all = u32SDASetup;
  }
  
  /* Enable I2C */
  I2Cx->I2CENABLE.all = I2CENABLE_ALL_EN_ENABLE;
  
  return SUCCESS;
}




/******************************************************************************
 * @brief      Enable I2C General Call function
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 ******************************************************************************/
void I2C_EnableGeneralCall(I2C_REGS* I2Cx)
{
  I2Cx->I2CMASTERADDR.bit.SPECIAL = 1;
  I2Cx->I2CMASTERADDR.bit.GCORSTART = 0;
}




/******************************************************************************
 * @brief      Disable I2C General Call function
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 ******************************************************************************/
void I2C_DisableGeneralCall(I2C_REGS* I2Cx)
{
  I2Cx->I2CMASTERADDR.bit.SPECIAL = 0;
}




/******************************************************************************
 * @brief      Enable I2C START BYTE function
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 ******************************************************************************/
void I2C_EnableStartByte(I2C_REGS* I2Cx)
{
  I2Cx->I2CMASTERADDR.bit.SPECIAL = 1;
  I2Cx->I2CMASTERADDR.bit.GCORSTART = 1;
}




/******************************************************************************
 * @brief      Disable I2C START BYTE function
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 ******************************************************************************/
void I2C_DisableStartByte(I2C_REGS* I2Cx)
{
  I2Cx->I2CMASTERADDR.bit.SPECIAL = 0;
}




/******************************************************************************
 * @brief      Clear specified interrupt flag
 *
 * @param[in]  I2Cx    :  Select the I2C module
 * @param[in]  eIntType:  Specified interrupt type
 *                        See I2C_IntEnum for details
 *                         - \ref I2C_INT_RX_UNDER
 *                         - \ref I2C_INT_RX_OVER
 *                         - \ref I2C_INT_TX_OVER
 *                         - \ref I2C_INT_RD_REQ
 *                         - \ref I2C_INT_TX_ABORT
 *                         - \ref I2C_INT_RX_DONE
 *                         - \ref I2C_INT_ACTIVITY
 *                         - \ref I2C_INT_STOP_DET
 *                         - \ref I2C_INT_START_DET
 *                         - \ref I2C_INT_GEN_CALL
 *                         - \ref I2C_INT_ALL
 *
 * @return     none
 *
 ******************************************************************************/
void I2C_ClearInt(I2C_REGS* I2Cx, I2C_IntEnum eIntType)
{
  volatile uint32_t dummyData;

  switch(eIntType)
  {
    case I2C_INT_RX_UNDER:
      dummyData = I2Cx->I2CRXUDFCLR.all;
      break;

    case I2C_INT_RX_OVER:
      dummyData = I2Cx->I2CRXOVFCLR.all;
      break;

    case I2C_INT_TX_OVER:
      dummyData = I2Cx->I2CTXOVFCLR.all;
      break;

    case I2C_INT_RD_REQ:
      dummyData = I2Cx->I2CRDREQCLR.all;
      break;

    case I2C_INT_TX_ABORT:
      dummyData = I2Cx->I2CTXABRTCLR.all;
      break;

    case I2C_INT_RX_DONE:
      dummyData = I2Cx->I2CRXDONECLR.all;
      break;

    case I2C_INT_ACTIVITY:
      dummyData = I2Cx->I2CACTCLR.all;
      break;

    case I2C_INT_STOP_DET:
      dummyData = I2Cx->I2CSTOPDETCLR.all;
      break;

    case I2C_INT_START_DET:
      dummyData = I2Cx->I2CSTARTDETCLR.all;
      break;

    case I2C_INT_GEN_CALL:
      dummyData = I2Cx->I2CGENCALLCLR.all;
      break;

    case I2C_INT_ALL:
      dummyData = I2Cx->I2CINTCLR.all;
      break;

    default:
      break;
  }
}




/******************************************************************************
 * @brief      I2C Master Mode Send Data function
 *
 * @param[in]  I2Cx          :  Select the I2C module
 * @param[in]  eAddrMode     :  Address mode
 *                              See I2C_AddrModeEnum for details
 *                               - \ref I2C_ADDR_7BIT
 *                               - \ref I2C_ADDR_10BIT
 * @param[in]  u16TargetAddr :  Target Slave address
 * @param[in]  pu8WriteBuffer:  Pointer to the buffer that stored the data to be sent
 * @param[in]  u32Count      :  Number of data to be sent or received
 *
 * @return     none
 *
 ******************************************************************************/
void I2C_MasterWrite(I2C_REGS* I2Cx, I2C_AddrModeEnum eAddrMode,
  uint16_t u16TargetAddr, uint8_t *pu8WriteBuffer, uint32_t u32Count)
{
  uint32_t i;

  /* Set Address Mode */
  I2C->I2CMASTERADDR.bit.MASTERADDR10B = eAddrMode;

  /* Set Target Slave Address*/
  I2C->I2CMASTERADDR.bit.TARADDR = u16TargetAddr;

  for(i = 0; i < u32Count; i++)
  {
    /* Write TxFIFO, Send Address and Send Data If Master Get ACK */
    I2C_WriteByte(I2Cx, pu8WriteBuffer[i]);

    /* Wait Slave Receive Data And Send ACK Again,
     * Then Master Stop Bus Because of TxFIFO Empty
     */

    /* Wait Until TxFIFO Empty */
    while(!I2C_IsTxEmpty(I2Cx)) { }

    /* Wait I2C Bus Idle */
    while(I2C_IsActivity(I2Cx)) { }

    /* Do Not Get ACK, Master Abort Send Data, Flush TxFIFO, Send Stop Signal */
    if(I2C_GetTxAbortIntRawFlag(I2Cx))
    {
      /* Clear Event Flag */
      I2C_ClearInt(I2Cx, I2C_INT_TX_ABORT);
      return;
    }
  }
}




/******************************************************************************
 * @brief      I2C Slave Mode Receive Data function
 *
 * @param[in]  I2Cx         :  Select the I2C module
 * @param[in]  pu8ReadBuffer:  Pointer to the buffer that stored the received data
 * @param[in]  u32Count     :  Number of data to be sent or received
 *
 * @return     none
 *
 ******************************************************************************/
void I2C_SlaveRead(I2C_REGS* I2Cx, uint8_t *pu8ReadBuffer, uint32_t u32Count)
{
  uint32_t i;
  
  for(i = 0; i < u32Count; i++)
  {
    /* Slave Receive Data, And Send ACK */

    /* Wait Until RxFIFO Not Empty */
    while(!I2C_IsRxNotEmpty(I2Cx)) { }

    /* Read RxFIFO, Read Data */
    pu8ReadBuffer[i] = I2C_ReadByte(I2Cx);
  }
}




/******************************************************************************
 * @brief      I2C Master Mode Receive Data function
 *
 * @param[in]  I2Cx         :  Select the I2C module
 * @param[in]  eAddrMode    :  Address mode
 *                             See I2C_AddrModeEnum for details
 *                              - \ref I2C_ADDR_7BIT
 *                              - \ref I2C_ADDR_10BIT
 * @param[in]  u16TargetAddr:  Target Slave address
 * @param[in]  pu8ReadBuffer:  Pointer to the buffer that stored the received data
 * @param[in]  u32Count     :  Number of data to be sent or received
 *
 * @return     none
 *
 ******************************************************************************/
void I2C_MasterRead(I2C_REGS* I2Cx, I2C_AddrModeEnum eAddrMode,
  uint16_t u16TargetAddr, uint8_t *pu8ReadBuffer, uint32_t u32Count)
{
  uint32_t i;

  /* Set Address Mode */
  I2C->I2CMASTERADDR.bit.MASTERADDR10B = eAddrMode;

  /* Set Target Slave Address*/
  I2C->I2CMASTERADDR.bit.TARADDR = u16TargetAddr;

  for(i = 0; i < u32Count; i++)
  {
    /* Write TxFIFO, Send Read Comamnd */
    I2C_MasterReadCmd(I2Cx);

    /* Wait Slave Send Data If Master Get ACK,
     * Then Master Receive One Data,
     * Send NACK and Stop Bus Because of TxFIFO Empty;
     */

    /* Wait Until RxFIFO Not Empty */
    while(!I2C_IsRxNotEmpty(I2Cx))
    {
      /* Do Not Get ACK, Master Abort Send Data, Flush TxFIFO, Send Stop Signal */
      if(I2C_GetTxAbortIntRawFlag(I2Cx))
      {
        /* Clear Event Flag */
        I2C_ClearInt(I2Cx, I2C_INT_TX_ABORT);
        return;
      }
    }

    /* Read RxFIFO, Read Data */
    pu8ReadBuffer[i] = I2C_ReadByte(I2Cx);

    /* Wait I2C Bus Idle */
    while(I2C_IsActivity(I2Cx)) { }
  }
}




/******************************************************************************
 * @brief      I2C Slave Mode Send Data function
 *
 * @param[in]  I2Cx          :  Select the I2C module
 * @param[in]  pu8WriteBuffer:  Pointer to the buffer that stored the data to be sent
 * @param[in]  u32Count      :  Number of data to be sent or received
 *
 * @return     none
 *
 ******************************************************************************/
void I2C_SlaveWrite(I2C_REGS* I2Cx, uint8_t *pu8WriteBuffer, uint32_t u32Count)
{
  uint32_t i;

  for(i = 0; i < u32Count; i++)
  {
    /* Slave Send ACK If Master Request Address Matched 
    */

    /* Wait Until Detect Read Request */
    while(!I2C_GetReadRequestIntRawFlag(I2Cx)) { }

    /* Clear Event Flag */
    I2C_ClearInt(I2Cx, I2C_INT_RD_REQ);

    /* Write TxFIFO, Send Data */
    I2C_WriteByte(I2Cx, pu8WriteBuffer[i]);

    /* Wait Master Send ACK/NACK
     */

    /* Wait Until Master Receiver Done, Slave Get NACK */
    while(!I2C_GetRxDoneIntRawFlag(I2Cx)) { }

    /* Clear Event Flag */
    I2C_ClearInt(I2Cx, I2C_INT_RX_DONE);
  }
}




/******************************************************************************
 * @brief      I2C Master Mode Bulk Send Data function
 *
 * @param[in]  I2Cx          :  Select the I2C module
 * @param[in]  eAddrMode     :  Address mode
 *                              See I2C_AddrModeEnum for details
 *                               - \ref I2C_ADDR_7BIT
 *                               - \ref I2C_ADDR_10BIT
 * @param[in]  u16TargetAddr :  Target Slave address
 * @param[in]  pu8WriteBuffer:  Pointer to the buffer that stored the data to be sent
 * @param[in]  u32Count      :  Number of data to be sent or received
 *
 * @return     none
 *
 ******************************************************************************/
void I2C_MasterBulkWrite(I2C_REGS* I2Cx, I2C_AddrModeEnum eAddrMode,
  uint16_t u16TargetAddr, uint8_t *pu8WriteBuffer, uint32_t u32Count)
{
  uint32_t i;

  /* Set Address Mode */
  I2C->I2CMASTERADDR.bit.MASTERADDR10B = eAddrMode;

  /* Set Target Slave Address*/
  I2C->I2CMASTERADDR.bit.TARADDR = u16TargetAddr;

  /* TxFIFO Can Not Empty During Bulk Transmit */
  for(i = 0; i < u32Count; i++)
  {
    /* Wait Until TxFIFO not Full */
    while(!I2C_IsTxNotFull(I2Cx))
    {
      /* Do Not Get ACK, Master Abort Send Data, Flush TxFIFO, Send Stop Signal */
      if(I2C_GetTxAbortIntRawFlag(I2Cx))
      {
        /* Clear Event Flag */
        I2C_ClearInt(I2Cx, I2C_INT_TX_ABORT);
        return ;
      }
    }

    /* Write TxFIFO, Send Data If Master Get ACK */
    I2C_WriteByte(I2Cx, pu8WriteBuffer[i]);
  }

  /* Wait Slave Receive Data And Send ACK Again,
     * Until Master Stop Bus Because of TxFIFO Empty
     */
  
  /* Wait Until TxFIFO Empty */
  while(!I2C_IsTxEmpty(I2Cx)) { }

  /* Wait I2C Bus Idle */
  while(I2C_IsActivity(I2Cx)) { }

  /* Do Not Get ACK, Master Abort Send Data, Flush TxFIFO, Send Stop Signal */
  if(I2C_GetTxAbortIntRawFlag(I2Cx))
  {
    /* Clear Event Flag */
    I2C_ClearInt(I2Cx, I2C_INT_TX_ABORT);
    return ;
  }
}




/******************************************************************************
 * @brief      I2C Slave Mode Bulk Receive Data function
 *
 * @param[in]  I2Cx         :  Select the I2C module
 * @param[in]  pu8ReadBuffer:  Pointer to the buffer that stored the received data
 * @param[in]  u32Count     :  Number of data to be sent or received
 *
 * @return     none
 *
 ******************************************************************************/
void I2C_SlaveBulkRead(I2C_REGS* I2Cx, uint8_t *pu8ReadBuffer, uint32_t u32Count)
{
  uint32_t i;

  for(i = 0; i < u32Count; i++)
  {
    /* Slave Receive Data, And Send ACK
     */

    /* Wait Until RxFIFO Not Empty */
    while(!I2C_IsRxNotEmpty(I2Cx)) { }

    /* Read RxFIFO, Read Data */
    pu8ReadBuffer[i] = I2C_ReadByte(I2Cx);
  }
}




/******************************************************************************
 * @brief      I2C Master Mode Bulk Receive Data function
 *
 * @param[in]  I2Cx         :  Select the I2C module
 * @param[in]  eAddrMode    :  Address mode
 *                             See I2C_AddrModeEnum for details
 *                              - \ref I2C_ADDR_7BIT
 *                              - \ref I2C_ADDR_10BIT
 * @param[in]  u16TargetAddr:  Target Slave address
 * @param[in]  pu8ReadBuffer:  Pointer to the buffer that stored the received data
 * @param[in]  u32Count     :  Number of data to be sent or received
 *
 * @return     none
 *
 ******************************************************************************/
void I2C_MasterBulkRead(I2C_REGS* I2Cx, I2C_AddrModeEnum eAddrMode,
  uint16_t u16TargetAddr, uint8_t *pu8ReadBuffer, uint32_t u32Count)
{
  uint32_t u32RxCnt = 0;
  uint32_t u32TxCnt = 0;

  /* Set Address Mode */
  I2C->I2CMASTERADDR.bit.MASTERADDR10B = eAddrMode;

  /* Set Target Slave Address*/
  I2C->I2CMASTERADDR.bit.TARADDR = u16TargetAddr;

  /* Master Send Address, Wait Slave Send Data If Master Get ACK;
   * Then Master Receive Datas and Send ACK;
   * Send NACK and Stop Bus When TxFIFO Empty;
   */

  /* TxFIFO Can Not Empty During Bulk Transmit */
  while(u32TxCnt < u32Count )
  {
    /* TxFIFO not Full */
    if(I2C_IsTxNotFull(I2Cx))
    {
      /* Write TxFIFO, Send Read Comamnd */
      I2C_MasterReadCmd(I2Cx);
      u32TxCnt++;
    }

    /* RxFIFO Not Empty */
    if(I2C_IsRxNotEmpty(I2Cx))
    {
      /* Read RxFIFO, Read Data */
      *pu8ReadBuffer++ = I2C_ReadByte(I2Cx);
      u32RxCnt++;
    }

    /* I2C Bus Idle */
    if(!I2C_IsActivity(I2Cx))
    {
      /* Do Not Get ACK, Master Abort Send Data, Flush TxFIFO, Send Stop Signal */
      if(I2C_GetTxAbortIntRawFlag(I2Cx))
      {
        /* Read Clear Event Flag */
        I2C_ClearInt(I2Cx, I2C_INT_TX_ABORT);
      }
      return;
    }
  }

  /* Read the Rest of Data */
  while(u32RxCnt < u32Count)
  {
    /* RxFIFO Not Empty */
    if(I2C_IsRxNotEmpty(I2Cx))
    {
      /* Read RxFIFO, Read Data */
      *pu8ReadBuffer++ = I2C_ReadByte(I2Cx);
      u32RxCnt++;
    }
  }

  /* Wait Until TxFIFO Empty */
  while(!I2C_IsTxEmpty(I2Cx)) { }

  /* Wait I2C Bus Idle */
  while(I2C_IsActivity(I2Cx)) { }
}




/******************************************************************************
 * @brief      I2C Slave Mode Bulk Send Data function
 *
 * @param[in]  I2Cx          :  Select the I2C module
 * @param[in]  pu8WriteBuffer:  Pointer to the buffer that stored the data to be sent
 * @param[in]  u32Count      :  Number of data to be sent or received
 *
 * @return     none
 *
 ******************************************************************************/
void I2C_SlaveBulkWrite(I2C_REGS* I2Cx, uint8_t *pu8WriteBuffer, uint32_t u32Count)
{
  uint32_t i = 0;

  /* Slave Send ACK If Master Request Address Matched
   */

  /* Wait Until Detect Read Request */
  while(!I2C_GetReadRequestIntRawFlag(I2Cx)) { }

  /* Clear Event Flag */
  I2C_ClearInt(I2Cx, I2C_INT_RD_REQ);

  while(i < u32Count)
  {
    /* I2C Bus Idle */
    if(!I2C_IsActivity(I2Cx))
    {
      return;
    }

    /* TxFIFO not Full */
    if(I2C_IsTxNotFull(I2Cx))
    {
      /* Write TxFIFO, Send Data */
      I2C_WriteByte(I2Cx, pu8WriteBuffer[i]);
      i++;
    }
  }

  /* Wait Until Master Receiver Done, Slave Get NACK */
  while(!I2C_GetRxDoneIntRawFlag(I2Cx)) { }

  /* Clear Event Flag */
  I2C_ClearInt(I2Cx, I2C_INT_RX_DONE);
}


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
