#ifndef MAIN_H
#define MAIN_H

//#include "SystemConfig.h"
#include "ChargeFunction.h"
//#include "AdcFunction.h"

extern volatile unsigned char fg_1ms;
extern volatile unsigned char fg_2ms;
extern volatile unsigned char fg_10ms;
extern volatile unsigned char fg_100ms;
extern uint8_t fg_SOCrms;
extern RMSCALVAL rmscalval;
extern SYSTEMSTATE SysState;

extern void Sys_Config(void);
extern void PWM_Config(void);
extern void ADC_Config(void);
//extern void MeasureAC(void);
//extern void MeasureVoltage(void);
extern void MeasureCur(void);
extern void MeasureVout(void);
extern void MeasureAC(void);
extern void ChargeProtect(void);
extern float Cal_RMS(float* pData , int nNum);
extern void CalVin_rms(void);
extern void FSM_Handle(void);
extern void PowerControl(void);
extern void FaultResetVal(void);
extern void MotorDebug_UART(void);
			


#endif
