/******************************************************************************
 * @file     uart.h
 * @brief    UART module header file.
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


#ifndef UART_H
#define UART_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1168.h"




/**
 *  @brief  UART Transmit FIFO interrupt trigger threshold type definition
 */
typedef enum
{
  UART_TXFIFO_HALF_EMPTY          = UARTFCR_BIT_TXTH_TXFIFO_HALF_EMPTY,    /*!< Interrupt when FIFO is half empty */
  UART_TXFIFO_EMPTY               = UARTFCR_BIT_TXTH_TXFIFO_EMPTY          /*!< Interrupt when FIFO is empty      */
} UART_TxThresholdEnum;




/**
 *  @brief  UART Receive FIFO interrupt trigger threshold type definition
 */
typedef enum
{
  UART_RXFIFO_1BYTE_OR_MORE       = UARTFCR_BIT_RXTH_RX_FIFO_THRESHOLD_1,  /*!< 1  byte  or more in FIFO causes interrupt */
  UART_RXFIFO_8BYTE_OR_MORE       = UARTFCR_BIT_RXTH_RX_FIFO_THRESHOLD_8,  /*!< 8  bytes or more in FIFO causes interrupt */
  UART_RXFIFO_16BYTE_OR_MORE      = UARTFCR_BIT_RXTH_RX_FIFO_THRESHOLD_16, /*!< 16 bytes or more in FIFO causes interrupt */
  UART_RXFIFO_32BYTE_OR_MORE      = UARTFCR_BIT_RXTH_RX_FIFO_THRESHOLD_32  /*!< 32 bytes or more in FIFO causes interrupt */
} UART_RxThresholdEnum;




/******************************************************************************
 * @brief      Enable UART module
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     none
 *
 ******************************************************************************/
#define UART_Enable(UARTx)                  ((UARTx)->UARTDLH_UARTIER.UARTIER.all |= UARTIER_ALL_UUE_UART_ENABLE)




/******************************************************************************
 * @brief      Disable UART module
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     none
 *
 ******************************************************************************/
#define UART_Disable(UARTx)                 ((UARTx)->UARTDLH_UARTIER.UARTIER.bit.UUE = UARTIER_BIT_UUE_UART_DISABLE)




/******************************************************************************
 * @brief      Send one byte data to the UART peripheral
 *
 * @param[in]  UARTx :  Select the UART module
 * @param[in]  u8Data:  Byte data to be sent
 *
 * @return     none
 *
 ******************************************************************************/
#define UART_WriteByte(UARTx, u8Data)       ((UARTx)->UARTRBR_UARTTHR_UARTDLL.UARTTHR.all = (((uint32_t)(u8Data)) & 0xFF))




/******************************************************************************
 * @brief      Receive one byte data from the UART peripheral
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     The received byte data
 *
 ******************************************************************************/
#define UART_ReadByte(UARTx)                ((uint8_t)((UARTx)->UARTRBR_UARTTHR_UARTDLL.UARTRBR.all))




/******************************************************************************
 * @brief      Enable UART interrupt
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     none
 *
 ******************************************************************************/
#define UART_EnableInt(UARTx)               ((UARTx)->UARTMCR.all |= UARTMCR_ALL_GIE_ENABLE)




/******************************************************************************
 * @brief      Disable UART interrupt
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     none
 *
 ******************************************************************************/
#define UART_DisableInt(UARTx)              ((UARTx)->UARTMCR.bit.GIE = UARTMCR_BIT_GIE_DISABLE)




/******************************************************************************
 * @brief      Enable Receiver Data Available (trigger threshold reached) Interrupt
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     none
 *
 ******************************************************************************/
#define UART_EnableRxDataAvailableInt(UARTx)    ((UARTx)->UARTDLH_UARTIER.UARTIER.bit.RAVIE = UARTIER_BIT_RAVIE_RX_DATA_INT_ENABLE)




/******************************************************************************
 * @brief      Disable Receiver Data Available (trigger threshold reached) Interrupt
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     none
 *
 ******************************************************************************/
#define UART_DisableRxDataAvailableInt(UARTx)   ((UARTx)->UARTDLH_UARTIER.UARTIER.bit.RAVIE = UARTIER_BIT_RAVIE_RX_DATA_INT_DISABLE)




/******************************************************************************
 * @brief      Enable Transmit Data Request Interrupt
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     none
 *
 ******************************************************************************/
#define UART_EnableTxDataRequestInt(UARTx)      ((UARTx)->UARTDLH_UARTIER.UARTIER.bit.TIE = UARTIER_BIT_TIE_TX_FIFO_INT_ENABLE)




/******************************************************************************
 * @brief      Disable Transmit Data Request Interrupt
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     none
 *
 ******************************************************************************/
#define UART_DisableTxDataRequestInt(UARTx)     ((UARTx)->UARTDLH_UARTIER.UARTIER.bit.TIE = UARTIER_BIT_TIE_TX_FIFO_INT_DISABLE)




/******************************************************************************
 * @brief      Enable Receiver Error Interrupt
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     none
 *
 ******************************************************************************/
#define UART_EnableRxErrorInt(UARTx)        ((UARTx)->UARTDLH_UARTIER.UARTIER.bit.RLSE = UARTIER_BIT_RLSE_RX_LINE_INT_ENABLE)




/******************************************************************************
 * @brief      Disable Receiver Error Interrupt
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     none
 *
 ******************************************************************************/
#define UART_DisableRxErrorInt(UARTx)       ((UARTx)->UARTDLH_UARTIER.UARTIER.bit.RLSE = UARTIER_BIT_RLSE_RX_LINE_INT_DISABLE)




/******************************************************************************
 * @brief      Enable Receiver Time-out Interrupt
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     none
 *
 ******************************************************************************/
#define UART_EnableRxTimeoutInt(UARTx)      ((UARTx)->UARTDLH_UARTIER.UARTIER.bit.RTOIE = UARTIER_BIT_RTOIE_RX_TIMEOUT_INT_ENABLE)




/******************************************************************************
 * @brief      Disable Receiver Time-out Interrupt
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     none
 *
 ******************************************************************************/
#define UART_DisableRxTimeoutInt(UARTx)     ((UARTx)->UARTDLH_UARTIER.UARTIER.bit.RTOIE = UARTIER_BIT_RTOIE_RX_TIMEOUT_INT_DISABLE)




/******************************************************************************
 * @brief      Get Global Interrupt status
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     0 - A Interrupt not occurred
 *             1 - Interrupts has occurred
 *
 ******************************************************************************/
#define UART_GetGlobalIntStatus(UARTx)      (((UARTx)->UARTIIR_UARTFCR.UARTIIR.bit.NIP == UARTIIR_BIT_NIP_INT_OCCUR)? (1) : (0))




/******************************************************************************
 * @brief      Get Transmit FIFO requests data interrupt status
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     0 - Transmit FIFO requests data interrupt not occurred
 *             1 - Transmit FIFO requests data interrupt occurred
 *
 ******************************************************************************/
#define UART_GetTxDataRequestIntStatus(UARTx)     (((UARTx)->UARTIIR_UARTFCR.UARTIIR.bit.IID == UARTIIR_BIT_IID_TX_FIFO_REQUEST_DATA_INT)? (1) : (0))




/******************************************************************************
 * @brief      Get Received data available interrupt status
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     0 - Received data available interrupt not occurred
 *             1 - Received data available interrupt occurred
 *
 ******************************************************************************/
#define UART_GetRxDataAvailableIntStatus(UARTx)   (((UARTx)->UARTIIR_UARTFCR.UARTIIR.bit.IID == UARTIIR_BIT_IID_RX_DATA_READY_INT)? (1) : (0))




/******************************************************************************
 * @brief      Get Receive error(Overrun, parity, framing, break, FIFO error) interrupt status
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     0 - Received error interrupt not occurred
 *             1 - Received error interrupt occurred
 *
 ******************************************************************************/
#define UART_GetRxErrorIntStatus(UARTx)     (((UARTx)->UARTIIR_UARTFCR.UARTIIR.bit.IID == UARTIIR_BIT_IID_RX_ERROR_INT)? (1) : (0))




/******************************************************************************
 * @brief      Get Receive timeout interrupt status
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     0 - No time out interrupt is pending
 *             1 - Time out interrupt is pending.(FIFO mode only)
 *
 ******************************************************************************/
#define UART_GetRxTimeoutIntStatus(UARTx)   ((UARTx)->UARTIIR_UARTFCR.UARTIIR.bit.TOD)




/******************************************************************************
 * @brief      Disable UART FIFOs
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     none
 *
 ******************************************************************************/
#define UART_DisableFIFO(UARTx)             ((UARTx)->UARTIIR_UARTFCR.UARTFCR.all = UARTFCR_ALL_TRFIFOE_FIFO_DISABLE)




/******************************************************************************
 * @brief      Clear receive FIFO
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     none
 *
 ******************************************************************************/
#define UART_ClearRxFIFO(UARTx)             ((UARTx)->UARTIIR_UARTFCR.UARTFCR.all = (UARTFCR_ALL_CLRRF_CLEAR_RX_FIFO | UARTFCR_ALL_TRFIFOE_FIFO_ENABLE))




/******************************************************************************
 * @brief      Clear transmit FIFO
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     none
 *
 ******************************************************************************/
#define UART_ClearTxFIFO(UARTx)             ((UARTx)->UARTIIR_UARTFCR.UARTFCR.all = (UARTFCR_ALL_CLRTF_CLEAR_TX_FIFO | UARTFCR_ALL_TRFIFOE_FIFO_ENABLE))




/******************************************************************************
 * @brief      Get receive FIFO level
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     Number of bytes (0-63) remaining in the Receive FIFO
 *
 ******************************************************************************/
#define UART_GetRxFIFOLevel(UARTx)          ((UARTx)->UARTFOR.all & UARTFOR_ALL_BYTECNT_Msk)




/******************************************************************************
 * @brief      Enable set break
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     none
 *
 ******************************************************************************/
#define UART_EnableSetBreak(UARTx)          ((UARTx)->UARTLCR.all |= UARTLCR_ALL_SB_FORCE_TX_0)




/******************************************************************************
 * @brief      Disable set break
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     none
 *
 ******************************************************************************/
#define UART_DisableSetBreak(UARTx)         ((UARTx)->UARTLCR.bit.SB = 0)




/******************************************************************************
 * @brief      Enable stick parity
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     none
 *
 ******************************************************************************/
#define UART_EnableStickParity(UARTx)       ((UARTx)->UARTLCR.all |= UARTLCR_ALL_STKYP_PARITY_EQU_INVERT_EPS)




/******************************************************************************
 * @brief      Disable stick parity
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     none
 *
 ******************************************************************************/
#define UART_DisableStickParity(UARTx)      ((UARTx)->UARTLCR.bit.STKYP = 0)




/******************************************************************************
 * @brief      Is FIFO error
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     0 - No FIFO or no errors in receive FIFO
 *             1 - At least one character in receive FIFO has errors
 *
 ******************************************************************************/
#define UART_IsFIFOError(UARTx)             ((UARTx)->UARTLSR.bit.FIFOERR)




/******************************************************************************
 * @brief      Is all the data in the transmitter has been shifted out
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     0 - There is data in the transmit shift register, the Transmit 
 *                 Holding Register, or the FIFO
 *             1 - All the data in the transmitter has been shifted out
 *
 ******************************************************************************/
#define UART_IsTxDone(UARTx)                ((UARTx)->UARTLSR.bit.TXDONE)




/******************************************************************************
 * @brief      Is data in the holding register or FIFO waiting to be shifted out
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     0 - There is data in the holding register or 
                   FIFO (more than half data) waiting to be shifted out
 *             1 - The transmit FIFO has half or less than half data
 *
 ******************************************************************************/
#define UART_IsTxDataRequest(UARTx)         ((UARTx)->UARTLSR.bit.TDRQ)




/******************************************************************************
 * @brief      Is break signal received
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     0 - No break signal has been received
 *             1 - Break signal received
 *
 ******************************************************************************/
#define UART_IsRxBreak(UARTx)               ((UARTx)->UARTLSR.bit.BI)




/******************************************************************************
 * @brief      Is frame error detected
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     0 - No Framing error
 *             1 - Invalid stop bit has been detected
 *
 ******************************************************************************/
#define UART_IsRxFrameError(UARTx)          ((UARTx)->UARTLSR.bit.FE)




/******************************************************************************
 * @brief      Is parity error detected
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     0 - No Parity Error
 *             1 - Parity error has occurred
 *
 ******************************************************************************/
#define UART_IsRxParityError(UARTx)         ((UARTx)->UARTLSR.bit.PE)




/******************************************************************************
 * @brief      Is receiver overflow
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     0 - No data has been overflow
 *             1 - Receive data has been overflow
 *
 ******************************************************************************/
#define UART_IsRxOverflow(UARTx)            ((UARTx)->UARTLSR.bit.OE)




/******************************************************************************
 * @brief      Is data available in BRB or receive FIFO
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     0 - No data has been received
 *             1 - Data is available in RBR or the FIFO
 *
 ******************************************************************************/
#define UART_IsRxNotEmpty(UARTx)            ((UARTx)->UARTLSR.bit.DR)




/**
 *  @brief  UART Public Function Declaration
 */
void UART_Init(UART_REGS* UARTx, uint32_t u32Baudrate);

void UART_SetFIFOTriggerThreshold(UART_REGS* UARTx, UART_RxThresholdEnum eRxTrigLvl, UART_TxThresholdEnum eTxTrigLvl);

void UART_Write(UART_REGS* UARTx, uint8_t *pu8Buffer, uint32_t u32Offset, uint32_t u32Count);
void UART_WriteText(UART_REGS* UARTx, const uint8_t *pu8Text);

void UART_Read(UART_REGS* UARTx, uint8_t *pu8Buffer, uint32_t u32Offset, uint32_t u32Count);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* UART_H */


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
