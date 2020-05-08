/******************************************************************************
 * @file     ssp.h
 * @brief    SSP module header file.
 * @version  V1.2.0
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


#ifndef SSP_H
#define SSP_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1168.h"




/**
 *  @brief  SSP frame signal polarity type definition
 */
typedef enum
{
  SSP_FRM_ACTIVE_LOW    = 0,                /*!< SSP frame signal = 0, signal actvie low  */
  SSP_FRM_ACTIVE_HIGH   = 1,                /*!< SSP frame signal = 1, signal actvie high */
} SSP_FramePolarityEnum;




/**
 *  @brief  SSP clock signal idle level type definition
 */
typedef enum
{
  SSP_CLK_IDLE_LOW      = 0,                /*!< SSP clock = 0, in idle state */
  SSP_CLK_IDLE_HIGH     = 1,                /*!< SSP clock = 1, in idle state */
} SSP_ClockIdleLevelEnum;




/**
 *  @brief  SSP Send data on which edge type definition
 */
typedef enum
{
  SSP_SEND_ON_RISING_EDGE         = 0,      /*!< SSP send data on rising edge and
                                                 receiveed data latched on falling edge */
  SSP_SEND_ON_FALLING_EDGE        = 1,      /*!< SSP send data on falling edge and
                                                 received data latched on rising edge */
} SSP_SendDataEdgeEnum;




/**
 *  @brief  SPI communication mode
 */
typedef enum
{
  SSP_SPI_MODE_0        = 0,                /*!< CLKPOL = 0, CLKPHS = 0 */
  SSP_SPI_MODE_1        = 1,                /*!< CLKPOL = 0, CLKPHS = 1 */
  SSP_SPI_MODE_2        = 2,                /*!< CLKPOL = 1, CLKPHS = 0 */
  SSP_SPI_MODE_3        = 3,                /*!< CLKPOL = 1, CLKPHS = 1 */
} SSP_SPIModeEnum;




/**
 *  @brief  SSP operation mode
 */
#define SSP_MASTER_MODE           (0x0)
#define SSP_SLAVE_MODE            (0x1)




/**
 *  @brief  SSP FIFO Depth (32-bit)
 */
#define SSP_FIFO_DEPTH            (16)




/******************************************************************************
 * @brief      Enable SSP port
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     none
 *
 ******************************************************************************/
#define SSP_Enable(SSPx)                    ((SSPx)->SSPCTL0.bit.EN = SSPCTL0_BIT_EN_ENABLE)




/******************************************************************************
 * @brief      Disable SSP port
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     none
 *
 ******************************************************************************/
#define SSP_Disable(SSPx)                   ((SSPx)->SSPCTL0.bit.EN = SSPCTL0_BIT_EN_DISABLE)




/******************************************************************************
 * @brief      Enable FIFO Packed Mode
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     none
 *
 ******************************************************************************/
#define SSP_EnableFIFOPackMode(SSPx)        ((SSPx)->SSPCTL0.bit.FPACKEN = SSPCTL0_BIT_FPACKEN_ENABLE)




/******************************************************************************
 * @brief      Disable FIFO Packed Mode
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     none
 *
 ******************************************************************************/
#define SSP_DisableFIFOPackMode(SSPx)       ((SSPx)->SSPCTL0.bit.FPACKEN = SSPCTL0_BIT_FPACKEN_DISABLE)




/******************************************************************************
 * @brief      Enable Receive FIFO Overflow Interrupt
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     none
 *
 ******************************************************************************/
#define SSP_EnableRxOverflowInt(SSPx)       ((SSPx)->SSPCTL0.bit.RFINTMSK = SSPCTL0_BIT_RFINTMSK_UNMASK)




/******************************************************************************
 * @brief      Disable Receive FIFO Overflow Interrupt
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     none
 *
 ******************************************************************************/
#define SSP_DisableRxOverflowInt(SSPx)      ((SSPx)->SSPCTL0.bit.RFINTMSK = SSPCTL0_BIT_RFINTMSK_MASK)




/******************************************************************************
 * @brief      Enable Transmit FIFO Underflow Interrupt
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     none
 *
 ******************************************************************************/
#define SSP_EnableTxUnderflowInt(SSPx)      ((SSPx)->SSPCTL0.bit.TFINTMSK = SSPCTL0_BIT_TFINTMSK_UNMASK)




/******************************************************************************
 * @brief      Disable Transmit FIFO Underflow Interrupt
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     none
 *
 ******************************************************************************/
#define SSP_DisableTxUnderflowInt(SSPx)     ((SSPx)->SSPCTL0.bit.TFINTMSK = SSPCTL0_BIT_TFINTMSK_MASK)




/******************************************************************************
 * @brief      Enable Receiver Time-out Interrupt
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     none
 *
 * @detail     Receive timeout interrupt do not generate NVIC interrupt service routine,
 *             it just generate an receive timeout status signal
 *
 ******************************************************************************/
#define SSP_EnableRxTimeoutInt(SSPx)        ((SSPx)->SSPCTL1.bit.RXTOIE = SSPCTL1_BIT_RXTOIE_ENABLE)




/******************************************************************************
 * @brief      Disable Receiver Time-out Interrupt
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     none
 *
 ******************************************************************************/
#define SSP_DisableRxTimeoutInt(SSPx)       ((SSPx)->SSPCTL1.bit.RXTOIE = SSPCTL1_BIT_RXTOIE_DISABLE)




/******************************************************************************
 * @brief      Enable Transmit FIFO Empty (at or below TxFIFO threshold) Interrupt
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     none
 *
 ******************************************************************************/
#define SSP_EnableTxDataRequestInt(SSPx)    ((SSPx)->SSPCTL1.bit.TFIE = SSPCTL1_BIT_TFIE_ENABLE)




/******************************************************************************
 * @brief      Disable Transmit FIFO Empty (at or below TxFIFO threshold) Interrupt
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     none
 *
 ******************************************************************************/
#define SSP_DisableTxDataRequestInt(SSPx)   ((SSPx)->SSPCTL1.bit.TFIE = SSPCTL1_BIT_TFIE_DISABLE)




/******************************************************************************
 * @brief      Enable Receive FIFO Full (exceeds RxFIFO threshold) Interrupt
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     none
 *
 ******************************************************************************/
#define SSP_EnableRxDataAvailableInt(SSPx)  ((SSPx)->SSPCTL1.bit.RFIE = SSPCTL1_BIT_RFIE_ENABLE)




/******************************************************************************
 * @brief      Disable Receive FIFO Full (exceeds RxFIFO threshold) Interrupt
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     none
 *
 ******************************************************************************/
#define SSP_DisableRxDataAvailableInt(SSPx) ((SSPx)->SSPCTL1.bit.RFIE = SSPCTL1_BIT_RFIE_DISABLE)




/******************************************************************************
 * @brief      Get Transmit FIFO Level
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     Number of entries in TxFIFO
 *
 ******************************************************************************/
#define SSP_GetTxFIFOLevel(SSPx)            ((SSPx)->SSPSTS.bit.TFLVL)




/******************************************************************************
 * @brief      Get Receive FIFO Level
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     Number of entries minus one in RXFIFO
 *
 ******************************************************************************/
#define SSP_GetRxFIFOLevel(SSPx)            ((SSPx)->SSPSTS.bit.RFLVL)




/******************************************************************************
 * @brief      Set Receive FIFO Trigger Threshold
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     none
 *
 ******************************************************************************/
#define SSP_SetRxFIFOTriggerThreshold(SSPx,u8RxLevel)   ((SSPx)->SSPCTL1.bit.RFTH = (u8RxLevel))




/******************************************************************************
 * @brief      Set Transmit FIFO Trigger Threshold
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     none
 *
 ******************************************************************************/
#define SSP_SetTxFIFOTriggerThreshold(SSPx,u8TxLevel)   ((SSPx)->SSPCTL1.bit.TFTH = (u8TxLevel))




/******************************************************************************
 * @brief      Is Transmit FIFO Not Full
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     0 - TxFIFO is full
 *             1 - TxFIFO is not full
 *
 ******************************************************************************/
#define SSP_IsTxNotFull(SSPx)               ((SSPx)->SSPSTS.bit.TNF)




/******************************************************************************
 * @brief      Is Receive FIFO Not Empty
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     0 - RxFIFO is empty
 *             1 - RxFIFO is not empty
 *
 ******************************************************************************/
#define SSP_IsRxNotEmpty(SSPx)              ((SSPx)->SSPSTS.bit.RNE)




/******************************************************************************
 * @brief      Is Port Busy
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     0 - SSPx port is idle or disabled
 *             1 - SSPx port is currently transmitting or receiving framed data
 *
 ******************************************************************************/
#define SSP_IsBusy(SSPx)                    ((SSPx)->SSPSTS.bit.BUSY)




/******************************************************************************
 * @brief      Is Transmit FIFO Service Request
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     0 - TxFIFO level exceeds the TxFIFO threshold (TFTH + 1), or SSPx port disabled
 *             1 - TxFIFO level is at or below TxFIFO threshold (TFTH + 1), causes an interrupt request
 *
 ******************************************************************************/
#define SSP_IsTxServiceRequest(SSPx)        ((SSPx)->SSPSTS.bit.TFS)




/******************************************************************************
 * @brief      Is Receive FIFO Service Request
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     0 - RxFIFO level is at or below RxFIFO threshold (RFTH), or SSPx port is disabled
 *             1 - RxFIFO level exceeds RxFIFO threshold (RFTH), causes an interrupt request
 *
 ******************************************************************************/
#define SSP_IsRxServiceRequest(SSPx)        ((SSPx)->SSPSTS.bit.RFS)




/******************************************************************************
 * @brief      Is Receive FIFO Overflow
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     0 - Receive FIFO Overflow
 *             1 - Attempted data write to full RxFIFO, causes an interrupt request
 *
 ******************************************************************************/
#define SSP_IsRxOverflow(SSPx)              ((SSPx)->SSPSTS.bit.RFOVF)




/******************************************************************************
 * @brief      Is Receive Time-out Interrupt pending
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     0 - No receiver time-out is pending
 *             1 - Receiver time-out pending, causes an interrupt request
 *
 ******************************************************************************/
#define SSP_IsRxTimeoutPending(SSPx)        ((SSPx)->SSPSTS.bit.RXTO)




/******************************************************************************
 * @brief      Is Transmit FIFO Underflow
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     0 - The TxFIFO has not experienced an underflow.
 *             1 - A read from the TxFIFO was attempted when the TxFIFO was
 *                 empty, causes an interrupt if it is enabled (<Transmit FIFO
 *                 Underrun Interrupt Mask> in the SSP Control Register 0 is 0)
 *
 ******************************************************************************/
#define SSP_IsTxUnderflow(SSPx)             ((SSPx)->SSPSTS.bit.TFUDF)




/******************************************************************************
 * @brief      Clock Synchronization Status
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     0 - The SSPx port is ready for slave clock operations
 *             1 - The SSPx port is currently busy synchronizing slave mode signals
 *
 ******************************************************************************/
#define SSP_IsBusySyncSlaveClock(SSPx)      ((SSPx)->SSPSTS.bit.SLVCLKSTS)




/******************************************************************************
 * @brief      TX FIFO Odd Sample Status
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     0 - TxFIFO entry has an even number of samples
 *             1 - TxFIFO entry has an odd number of samples
 *
 ******************************************************************************/
#define SSP_IsTxHasOddSample(SSPx)          ((SSPx)->SSPSTS.bit.TFODDSTS)




/******************************************************************************
 * @brief      RX FIFO Odd Sample Status
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     0 - RxFIFO entry has 2 samples
 *             1 - RxFIFO entry has 1 sample
 *
 ******************************************************************************/
#define SSP_IsRxHasOddSample(SSPx)          ((SSPx)->SSPSTS.bit.RFODDSTS)




/******************************************************************************
 * @brief      Clear Receive FIFO Overflow Interrupt
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     none
 *
 ******************************************************************************/
#define SSP_ClearRxOverflowInt(SSPx)        ((SSPx)->SSPSTS.all = SSPSTS_ALL_RFOVF_Msk)




/******************************************************************************
 * @brief      Clear Transmit FIFO Underflow Interrupt
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     none
 *
 ******************************************************************************/
#define SSP_ClearTxUnderflowInt(SSPx)       ((SSPx)->SSPSTS.all = SSPSTS_ALL_TFUDF_Msk)




/******************************************************************************
 * @brief      Clear Receive Time-out Interrupt
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     none
 *
 ******************************************************************************/
#define SSP_ClearRxTimeoutInt(SSPx)         ((SSPx)->SSPSTS.all = SSPSTS_ALL_RXTO_Msk)




/******************************************************************************
 * @brief      Set Rx Time-out interval
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     none
 *
 ******************************************************************************/
#define SSP_SetRxTimeout(SSPx,u32Timeout)   ((SSPx)->SSPTO.all = (u32Timeout))




/******************************************************************************
 * @brief      Send one "data size" length data to SSP peripheral
 *
 * @param[in]  SSPx   :  Select the SSP module
 * @param[in]  u32Data:  The data to be sent
 *
 * @return     none
 *
 ******************************************************************************/
#define SSP_SendData(SSPx,u32Data)          ((SSPx)->SSPDATA.all = (u32Data))




/******************************************************************************
 * @brief      Receive one "data size" length data from the SSP peripheral
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     The received data
 *
 ******************************************************************************/
#define SSP_ReceiveData(SSPx)               ((SSPx)->SSPDATA.all)




/**
 *  @brief  SSP Public Function Declaration
 */
void SSP_Init(SSP_REGS* SSPx, uint8_t u8MasterOrSlave, uint8_t u8DataSize, uint32_t u32Baudrate, SSP_FramePolarityEnum u1FramePolarity, SSP_ClockIdleLevelEnum u1ClockIdleLevel, SSP_SendDataEdgeEnum u1DataSendEdge);

void SSP_InitEasy(SSP_REGS* SSPx, uint8_t u8MasterOrSlave, uint8_t u8DataSize, uint32_t u32Baudrate);

void SSP_Send(SSP_REGS* SSPx, uint32_t *pu32Buf, uint32_t u32Count);
uint32_t SSP_Receive(SSP_REGS* SSPx, uint32_t *pu32Buf, uint32_t u32Count);

void SSP_MasterTransceive(SSP_REGS* SSPx, uint32_t *pu32WriteBuffer, uint32_t *pu32ReadBuffer, uint32_t u32Count);
void SSP_MasterB2BTransceive(SSP_REGS* SSPx, uint32_t *pu32WriteBuffer, uint32_t *pu32ReadBuffer, uint32_t u32Count);
void SSP_SlaveTransceive(SSP_REGS* SSPx, uint32_t *pu32WriteBuffer, uint32_t *pu32ReadBuffer, uint32_t u32Count);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* SSP_H */


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
