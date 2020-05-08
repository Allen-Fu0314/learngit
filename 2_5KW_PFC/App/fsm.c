#include "fsm.h"
#include "stdio.h"

SYSTEMSTATE SysState;
SYSTEMFLAG SysFlag;
SYSTEM_DEBOUNCE Debounce;
extern RMSCALVAL rmscalval;
extern PWMCALVAL pwmcalval;
extern FAULTSTATE FaultState;
extern PLL_VAL pll_val;
extern enum PLLSTATUS pllstatus;
extern PROTECTVAL protectval;
extern pwmSwState pwm_SwState;




void FSM_Handle(void)
{
	switch(SysState)
	{
		case sys_idle:
		SysFlag.fg_relay = 0;
	//	pwm_SwState.enum_pwmSwState =pwmSwState_defaultState;
		if(SysFlag.fg_UNDERRMS)
		{
			if((rmscalval.RMSVin >rmscalval.UnderRMSRecoverValue)&&(rmscalval.RMSVin<rmscalval.RMSProtectMax)&&(protectval.VOUT>protectval.VoutProtect))
			{
				SysState = sys_normal;
				
				pwm_SwState.enum_pwmSwState =pwmSwState_normalOperation;
				SysFlag.fg_UNDERRMS =0;
			}
		}else if(SysFlag.fg_OVERRMS)
		{
			if((rmscalval.RMSVin >rmscalval.RMSProtectMin)&&(rmscalval.RMSVin<rmscalval.OverRMSRecoverValue)&&(protectval.VOUT>protectval.VoutProtect))
			{
				SysState = sys_normal;
				
				
				pwm_SwState.enum_pwmSwState =pwmSwState_normalOperation;
				SysFlag.fg_OVERRMS =0;
			}
		}else
		{
				if((rmscalval.RMSVin >rmscalval.RMSProtectMin)&&(rmscalval.RMSVin<rmscalval.RMSProtectMax)&&(protectval.VOUT>protectval.VoutProtect))
			{
				SysState = sys_normal;
				SysFlag.fg_Vref = 1;
				//pwmcalval.Vref = pwmcalval.Vout;
				
			//	pwm_SwState.enum_pwmSwState =pwmSwState_normalOperation;
				//SysFlag.fg_OVERRMS =0;
			}
		}

			break;
			
		case sys_normal:
	//
		if((rmscalval.RMSVin <rmscalval.UnderRMSValue)||(rmscalval.RMSVin>rmscalval.OverRmsValue)||(protectval.VOUT<protectval.VoutProtect))
			{
				if(++Debounce.debounce_fsmN2I >40)
				{
					if(rmscalval.RMSVin>rmscalval.OverRmsValue)
					{
						SysFlag.fg_OVERRMS =1;
					}else if(rmscalval.RMSVin<rmscalval.UnderRMSValue)
					{
						SysFlag.fg_UNDERRMS =1;
					}
					SysState = sys_idle;
					PWM_OFF;
					ResetVal();
					SysFlag.fg_relay = 0;
				}
				
			}else
			{
				Debounce.debounce_fsmN2I = 0;
			}
			break;
			
		case sys_fault:
				SysFlag.fg_relay = 0;
               
         //       pwm_SwState.enum_pwmSwState =pwmSwState_defaultState;
                PWM_OFF;
				if(!fg_AllFault)
				{
					SysState = sys_idle;
					FaultResetVal();
				}
			break;
		
		case sys_hold:
			break;
			
	}
}

void PowerControl(void)
{
	if(SysFlag.fg_110V)
	{
	//	v110_ON;
	}else
	{
	//	v110_OFF;
	}
		
}


