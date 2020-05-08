#ifndef FSM_H
#define FSM_H

#include "ChargeFunction.h"
#include "AdcFunction.h"


typedef enum
{
	sys_idle,
	sys_normal,
	sys_fault,
	sys_hold
}SYSTEMSTATE;

typedef struct 
{
	uint8_t fg_relay;
	uint8_t fg_powerA;
	uint8_t fg_powerB;
	uint8_t fg_ForceDelete;
	uint8_t fg_SoftStart;
	uint8_t fg_PowerGood;
	uint8_t fg_Vref;
	uint8_t fg_PwmSet;
	uint8_t fg_lastPositive;
	uint8_t fg_closeGiLoop;
	uint8_t fg_closeGvLoop;
	uint8_t fg_saturated;
	uint16_t fg_PositiveTimer;
	uint16_t fg_NegativeTimer;
	uint16_t fg_WrongTimer;
	uint16_t WrongPhasetimes;
	uint8_t fg_OVERRMS;
	uint8_t fg_UNDERRMS;
    uint8_t fg_110V;
    uint16_t DelayPWM;
}SYSTEMFLAG;

typedef struct
{
	uint16_t debounce_fsmN2I;
	uint8_t debounce_PWMforce;
	uint8_t debounce_PowerGood;
	uint16_t debounce_PwmSet;
}SYSTEM_DEBOUNCE;



void FSM_Handle(void);
void PowerControl(void);
extern void ResetVal(void);
#endif
