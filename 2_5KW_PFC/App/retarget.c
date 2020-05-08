/******************************************************************************
 * @file     retarget.c
 * @brief    'Retarget' layer for target-dependent low level functions
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

#include <stdio.h>
#include "spc1168.h"




/**
 *  @brief  These must be defined to avoid linking in stdio.o from the C Library
 */
struct __FILE { int handle;   /* Add whatever you need here */};
FILE __stdout;
FILE __stdin;
FILE __stderr;




/******************************************************************************
 * @brief      Get character from UART
 *
 * @param[in]  f:  Pointer to a FILE object that identifies the stream on which 
 *                 the operation is to be performed
 *
 * @return     The character read from UART
 *
 ******************************************************************************/
int fgetc(FILE *f)
{
  /* Wait until data is available in RBR or the FIFO */
  while((UART->UARTLSR.all & UARTLSR_ALL_DR_Msk) == UARTLSR_ALL_DR_NO_DATA_RECEVIED);
  
  return (int)UART_ReadByte(UART);
}




/******************************************************************************
 * @brief      Write character to stream
 *
 * @param[in]  ch:  Character to be written
 * @param[in]  f :  Pointer to a FILE object that identifies the stream on which 
 *                  the operation is to be written
 *
 * @return     The same character that has been written
 *
 ******************************************************************************/
int fputc(int ch, FILE *f)
{
  if(ch =='\n')
  {
    UART_WriteByte(UART, (uint8_t)'\r');
    while((UART->UARTLSR.all & UARTLSR_ALL_TXDONE_Msk) == UARTLSR_ALL_TXDONE_TRANSMIT_NOT_DONE){};
  }
  
  UART_WriteByte(UART,(uint8_t) ch);
  while((UART->UARTLSR.all & UARTLSR_ALL_TXDONE_Msk) == UARTLSR_ALL_TXDONE_TRANSMIT_NOT_DONE){};
  
  return ch;
}




void _ttywrch(int ch)
{
  UART_WriteByte(UART, (uint8_t) ch);
  while((UART->UARTLSR.all & UARTLSR_ALL_TXDONE_Msk) == UARTLSR_ALL_TXDONE_TRANSMIT_NOT_DONE){};
}




int __backspace(FILE *f)
{
  return 0;
}




int ferror(FILE *f)
{
  /* Your implementation of ferror */
  return EOF;
}




void _sys_exit(int return_code)
{
  /* Endless loop */
  while(1);
}


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
