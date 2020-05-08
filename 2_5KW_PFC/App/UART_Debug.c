#include "UART_Debug.h"
#include "ChargeFunction.h"
#include "stdio.h"
uint8_t UART_Cmd=0;
uint8_t u8ResetEnabled;
UART_TX_MESSAGE uart_tx_message;
RESETVAL resetval;
extern PWMCALVAL pwmcalval;
extern PROTECTVAL protectval;
extern FAULTSTATE FaultState;
extern PLL_VAL pll_val;
extern SYSTEMSTATE SysState;
extern RMSCALVAL rmscalval;
extern FAULTVAL faultval;


void UART_DataCollection()
{
   
    uart_tx_message.I = protectval.IA;
    uart_tx_message.Vout = protectval.VOUT;
    uart_tx_message.Vinrms = rmscalval.RMSVin;
 //   uart_tx_message.PLLvalue = pll_val.arg;
    uart_tx_message.Pwm_period = pwmcalval.pwmperiod;
    uart_tx_message.SysState = SysState;
    uart_tx_message.FaultState = FaultState.allFault;
 
}
void MotorDebug_UART()
{
      if(UART->UARTLSR.bit.DR == 1) //RX ready
    {    
      UART_Cmd=UART_ReadByte(UART);
			
			if (MotorDebug_UART_Command_Comm(UART_Cmd) != 1)
			{
				if (MotorDebug_UART_Command_Special(uart_tx_message, UART_Cmd) != 1)
				{
				}
			}
			if((UART_Cmd!='r') && (UART_Cmd!='R'))
            {
			  printf("UART_Cmd=%c\n",UART_Cmd);
			}
    }
}

int16_t MotorDebug_UART_Command_Comm(uint8_t UART_Cmd)
{
	if(UART_Cmd == 'p')
	{
		
			printf("Vout Voltage=%dV, Ia Current=%dA\n ", protectval.VOUT , protectval.IA  );	
		return 1;
        
	}
	else if(UART_Cmd=='o')
	{
            printf("Vout Voltage=%dV, Ia Current=%dA\n ", protectval.VOUT , protectval.IA);
		return 1;
	}
	else if(UART_Cmd=='f')
	{
		printf("The FaultState is %x \n" , FaultState.allFault);
        printf("The OVP  == %d \n " , FaultState.oneFault.OverVoltage);
        printf("The OCP  == %d \n " , FaultState.oneFault.OverCurrent);
        printf("The SoftwareTZ  == %d \n " , FaultState.oneFault.SoftwareTZ);
        printf("The HardwareOC  == %d \n " , FaultState.oneFault.HardwareOC);
        printf("The HardwareOV  == %d \n " , FaultState.oneFault.HardwareOV);
        
        printf("The faultVref is %3f\n" , faultval.Fault_Vref);
        printf("The faultVout is %3f\n" , faultval.Fault_Vout);
         printf("The faultDutya is %3f\n" , faultval.Fault_Dutya);
         printf("The faultDutyb is %3f\n" , faultval.Fault_Dutyb);
         printf("The faultIa is %3f\n" , faultval.Fault_Ia);
         printf("The faultIb is %3f\n" , faultval.Fault_Ib);
        printf("The faultIref is %3f\n" , faultval.Fault_Iref);
        
        
        
		return 1;
	}
	else if(UART_Cmd=='[')
	{
		
		return 1;
	}
	else if(UART_Cmd=='9')
	{
		
		return 1;
	}
	else if(UART_Cmd=='8')
	{
		
		return 1;
	}
	return 0;
}

int16_t MotorDebug_UART_Command_Special(UART_TX_MESSAGE tx_message, short UART_Cmd)
{
 if(UART_Cmd=='v')
	{				 			
						 
		 printf("Now the vloop =%3f\n" , pwmcalval.Vloop );	
		return 1;
	}	
	else if(UART_Cmd=='i')
	{
		 				 
		 printf("Now the iloop =%3f\n" , pwmcalval.Duty_a);	
		return 1;		 
	}			
	else if(UART_Cmd=='a')
	{
		
		return 1;
	}
	else if(UART_Cmd=='b')
	{
		
		
		return 1;
	}

	else if(UART_Cmd=='*')
	{
//		 psMotor->sOther.u8ShowInfoFlag  = 1;
		 printf("Printf Now\n");
		 return 1;
	}
	else if(UART_Cmd=='/')
	{
//		psMotor->sOther.u8ShowInfoFlag  = 0;
		printf("Printf Disable\n");	
		return 1;		
	}
	else if(UART_Cmd=='t')
	{		
        printf("This is a test , the ovp will be set");
       FaultState.oneFault.OverCurrent = 1;
		return 1;
	}
	else if(UART_Cmd=='s')
	{
	
		return 1;		
	}
	else if(UART_Cmd=='q') //show system information
	{	
		printf("CurrentA  is %dA\n",protectval.IA);	

        printf("CurrentB  is %3fA\n",protectval.IB);
		
		printf("Vout Voltage is %dV\n",protectval.VOUT );
		
		printf("VIN is %dV \n",protectval.VIN);

		printf("The system is %d\n , 0->idle , 1->normal , 2->fault\n",SysState);
        
        printf("The RMSvalue is %3f\n" , rmscalval.RMSVin);
        
        printf("The Dutya is %3f\n" , pwmcalval.Duty_a);
        
        printf("The Dutyb is %3f\n" , pwmcalval.Duty_b);
        		
	}
	else if(UART_Cmd=='e')
	{
		printf("reset\n");
		u8ResetEnabled = 1;
		return 1;
	}

	if(UART_Cmd=='r')
	{
		//MotorDebugBuffer_StartRecData(&gsDebugBuffer);
		
		return 1;
	}
	if(UART_Cmd=='R')
	{
		//MotorDebugBuffer_StartDumpData(&gsDebugBuffer);
		return 1;
	}
	return 0;
}

void Sys_Restart(void)
{
      if (u8ResetEnabled != 1)
	{
		WDT_WALLOW(WDT1);
		WDT_FeedDog(WDT1);
	}
	else
	{
		printf(".");
	}
/*
			if (resetval.u8_RestartFlag == 1)
			{
				resetval.u32_RestartCountMs += 100;
				if (resetval.u32_RestartCountMs > 300000)
				{
					resetval.u8_RestartFlag = 0;
					resetval.u32_RestartCountMs = 0;
				}
			}
			else
			{
				resetval.u32_RestartCountMs = 0;
			}
*/
}
