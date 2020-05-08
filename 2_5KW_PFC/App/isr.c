/**************************************************************************//**
 * @file     isr.c
 * @brief    Template for all exceptions handler and peripherals interrupt 
 *           service routine.
 * @version  V1.2.0
 * @date     15-April-2019
 *
 * @note
 * Copyright (C) 2019 Spintrol Limited Corporation. All rights reserved.
 *
 * @attention
 * THIS SOFTWARE JUST PROVIDES CUSTOMERS WITH CODING INFORMATION REGARDING 
 * THEIR PRODUCTS, WHICH AIMS AT SAVING TIME FOR THEM. SPINTROL SHALL NOT BE
 * LIABLE FOR THE USE OF THE SOFTWARE. SPINTROL DOES NOT GUARANTEE THE 
 * CORRECTNESS OF THIS SOFTWARE AND RESERVES THE RIGHT TO MODIFY THE SOFTWARE 
 * WITHOUT NOTIFICATION.
 *
 ******************************************************************************/

#include "isr.h"



//---------------------------------------------------------------------------
// Cortex-M4 Processor Exceptions Handlers
//---------------------------------------------------------------------------

/****************************************************************************//**
 * @brief      This function handles NMI exception
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void NMI_Handler(void)
{
  
}




/****************************************************************************//**
 * @brief      This function handles Hard Fault exception
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void HardFault_Handler(void)
{
  
}




/****************************************************************************//**
 * @brief      This function handles Memory Manage exception
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void MemManage_Handler(void)
{
  
}




/****************************************************************************//**
 * @brief      This function handles Bus Fault exception
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void BusFault_Handler(void)
{
  
}




/****************************************************************************//**
 * @brief      This function handles Usage Fault exception
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void UsageFault_Handler(void)
{
  
}




/****************************************************************************//**
 * @brief      This function handles SVCall exception
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void SVC_Handler(void)
{
  
}




/****************************************************************************//**
 * @brief      This function handles Debug Monitor exception
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void DebugMon_Handler(void)
{
  
}




/****************************************************************************//**
 * @brief      This function handles PendSVC exception
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void PendSV_Handler(void)
{
  
}




/****************************************************************************//**
 * @brief      This function handles SysTick Handler
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void SysTick_Handler(void)
{
  
}




/******************************************************************************/
/*                 SPC1168 Peripherals Interrupt Handlers                     */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_spc1168.s).                                                 */
/******************************************************************************/

/****************************************************************************//**
 * @brief      This function handles Memory error interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void MEM_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles Power error interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void POWER_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles Clock error interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void CLOCK_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles WDT1 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/




/****************************************************************************//**
 * @brief      This function handles GPIO level-triggered interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void GPIO_LEVEL_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles GPIO edge-triggered interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void GPIO_EDGE_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles SIO0 Int A interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void SIO0A_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles SIO0 Int B interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void SIO0B_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles UART interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void UART_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles SSP interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void SSP_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles I2C interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void I2C_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles ADC EOC0 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void ADC3_IRQHandler(void)
{

	
    
}

void ADC4_IRQHandler(void)
{
	  
   
 
}

void ADC6_IRQHandler(void)
{
		

		
	
    
}

void ADC0_IRQHandler(void)
{
	


}




/****************************************************************************//**
 * @brief      This function handles ADC EOC1 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
/*
void ADC1_IRQHandler(void)
{

}
*/


/****************************************************************************//**
 * @brief      This function handles ADC EOC2 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void ADC2_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles ADC EOC3 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/





/****************************************************************************//**
 * @brief      This function handles ADC EOC4 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
 /*
void ADC4_IRQHandler(void)
{

}
*/



/****************************************************************************//**
 * @brief      This function handles ADC EOC5 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
// *******************************************************************************/
//void ADC5_IRQHandler(void)
//{

//}




/****************************************************************************//**
 * @brief      This function handles ADC EOC6 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
/*
void ADC6_IRQHandler(void)
{

}
*/



/****************************************************************************//**
 * @brief      This function handles ADC EOC7 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void ADC7_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles ADC EOC8 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void ADC8_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles ADC EOC9 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void ADC9_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles ADC EOC10 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void ADC10_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles ADC EOC11 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void ADC11_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles ADC EOC12 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void ADC12_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles ADC EOC13 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void ADC13_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles ADC EOC14 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void ADC14_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles ADC EOC15 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void ADC15_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles ADC PPU0 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void ADCPPU0_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles ADC PPU1 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void ADCPPU1_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles ADC PPU2 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void ADCPPU2_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles ADC PPU3 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void ADCPPU3_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles ADC PPU4 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void ADCPPU4_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles ADC PPU5 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void ADCPPU5_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles PWM0 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
/*
void PWM1_IRQHandler(void)
{

}
*/



/****************************************************************************//**
 * @brief      This function handles PWM1 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/







/****************************************************************************//**
 * @brief      This function handles PWM2 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void PWM2_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles PWM3 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void PWM3_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles PWM4 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void PWM4_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles PWM5 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void PWM5_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles PWM0 Trip-zone interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void PWM0TZ_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles PWM1 Trip-zone interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void PWM1TZ_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles PWM2 Trip-zone interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void PWM2TZ_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles PWM3 Trip-zone interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void PWM3TZ_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles PWM4 Trip-zone interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void PWM4TZ_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles PWM5 Trip-zone interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void PWM5TZ_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles ECAP interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void ECAP_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles TIMER0 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
/*
void TIMER0_IRQHandler(void)
{

}
*/



/****************************************************************************//**
 * @brief      This function handles TIMER1 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/





/****************************************************************************//**
 * @brief      This function handles TIMER2 interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
/*
void TIMER2_IRQHandler(void)
{
	
}
*/



/****************************************************************************//**
 * @brief      This function handles CRC interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void CRC_IRQHandler(void)
{

}




/****************************************************************************//**
 * @brief      This function handles AES interrupt request
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void AES_IRQHandler(void)
{

}


/******************* (C) COPYRIGHT 2019 SPINTROL LIMITED CO. *****END OF FILE****/
