#ifndef SYSTEMCONFIG_H
#define SYSTEMCONFIG_H

#include "spc1168.h"
#include "ChargeFunction.h"

#define 				TimerPeridCount 						 20000
#define         Timer2PeridCount 							80000
#define         AD_CurrentCount				       200	

void Sys_Config(void);
void PWM_Coonfig(void);
void TIMER1_Init(uint32_t u32TimerPeriodUs);
static void PWM_Init(PWM_REGS* PWMx, uint32_t u32PWMFreqHz, uint32_t DeadTime);

extern void PLLCal(void);
extern void	pll_chk_phase_lock(void);




#endif
