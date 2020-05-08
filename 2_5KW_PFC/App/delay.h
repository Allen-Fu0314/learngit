/******************************************************************************
 * @file     delay.h
 * @brief    Time-Delay module header file.
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


#ifndef DELAY_H
#define DELAY_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1168.h"




#define  DELAY_BY_CPU             0
#define  DELAY_BY_TIMER0          1
#define  DELAY_BY_TIMER1          2
#define  DELAY_BY_TIMER2          3


#define DELAY_FOR_FLASH           0
#define DELAY_FOR_RAM             1

#define DELAY_FOR_MEM             DELAY_FOR_FLASH




/******************************************************************************
 * @brief      Delay type selection
 * @param[in]  DELAY_TYPE
 *             - \ref DELAY_BY_CPU
 *             - \ref DELAY_BY_TIMER0
 *             - \ref DELAY_BY_TIMER1
 *             - \ref DELAY_BY_TIMER2
 *             
 * @detail     SPC1168 delay function supports 2 kinds of delay
 *             (1) CPU delay
 *                 Please select #define  DELAY_TYPE       DELAY_BY_CPU
 *                 CPU delay is made by a counter loop but with less precision.
 *                 If interrupt exerts while delay is running, the delay time will increase.
 *                 However it save hardware source that timer free.
 *                 Note:
 *                 CPU              Max delay time (sec)
 *                 150MHz           <28633 
 *                 120MHz           <35791
 *                 40 MHz           <107374
 *             
 *             (2) Delay with timer
 *                 Please select #define  DELAY_TYPE       DELAY_BY_TIMERx x=0~2
 *                 This type of delay realized by hardware timer which provides precisise delay.
 *                 It has a timeout mechanism to prevent a dead lock if timer hardware is disabled
 *                 by other events.
 *                 CPU              Max delay time (with timeout) (sec)
 *                 150MHz           <7158    about 2 hour
 *                 120MHz           <8947
 *                 40 MHz           <26843
 *                 PCLK             Max delay time (without timeout) (sec)
 *                 37.5MHz          114532
 *
 ******************************************************************************/
#define  DELAY_TYPE               DELAY_BY_CPU

#if DELAY_TYPE == DELAY_BY_TIMER0
  #define DELAY_TIMER             (TIMER0)
#elif DELAY_TYPE == DELAY_BY_TIMER1
  #define DELAY_TIMER             (TIMER1)
#elif DELAY_TYPE == DELAY_BY_TIMER2
  #define DELAY_TIMER             (TIMER2)
#endif




/**
 *  @brief  Delay Public Function Declaration
 */
void Delay_Init(void);
void Delay_Ms(uint32_t nms);
void Delay_Us(uint32_t nus);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* DELAY_H */


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED ***** END OF FILE ****/
