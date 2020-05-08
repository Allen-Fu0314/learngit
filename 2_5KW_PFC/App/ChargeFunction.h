#ifndef CHARGEFUNCTION_H
#define CHARGEFUNCTION_H
#include "spc1168.h"
#include "AdcFunction.h"
#include "isr.h"
#include "GlobalDefine.h"
#include "fsm.h"


typedef struct
{
    uint8_t fg_rmscount;
	uint8_t fg_rmsStart;
	uint8_t fg_rmsEnd ;
	uint8_t fg_rms;
	float RMSBuff ;
	uint16_t RMSCount;
	float RMSVin;
    float VinAcs;
	float RMSProtectMax;
	float RMSProtectMin;
    float UnderRMSValue;
    float OverRmsValue;
	float UnderRMSRecoverValue;
	float OverRMSRecoverValue;
    float RMS110V;
    
}RMSCALVAL;

typedef struct
{
	float B0_V;
	float B1_V;
	float B0_I;
	float B1_I;
	float B2_I;
	float E0;
	float E1;
	float Vin;
	float Vout;
	float Ia;
	float Ib;
	float Vrms;
	float Vref;
	float Vdiff;
	float Vdiff_last;
	float Vloop;
	float Vloop_last;
	float Vloop_last2;
	float Vfilter;
	float Ifilter;
	float Vfilter_last;
	float Ifilter_last;
	float Vfilter_last2;
	float Ifilter_last2;
	float Ia_last;
	float Ia_last2;
    float Ib_last;
    float Ib_last2;
	float Iref;
	float Iref_last;
	float Iadiff;
	float Iadiff_last;
	float Iadiff_last2;
	float Ibdiff;
	float Ibdiff_last;
	float Ibdiff_last2;
	float Duty_a;
	float Duty_b;
	float Dutya_NoVinlast;
	float Dutya_NoVinlast2;
    float Dutyb_NoVinlast;
	float Dutyb_NoVinlast2;
	float Duty_blast;
	float Dutya_NoVin;
    float Dutyb_NoVin;
	float Vout_80;
	float Vout_cmd;
	float Vout_cmd_95;
	float Vout_cmd_110;
	uint16_t Duty_max;
	uint16_t Duty_min;
	uint16_t Duty_avalue;
	uint16_t Duty_bvalue;
	uint16_t pwmperiod;
	uint16_t softstart_duty;
	uint16_t softStartvalue;
	uint8_t state_slew;
	uint32_t WdtClk;
}PWMCALVAL;

typedef struct
{
	uint16_t DeadTimeClk;
	uint16_t DeadTimeCnt;
	
	uint16_t Duty2a;
	uint16_t Duty2b;
	uint32_t PWMfreq;
	uint16_t Freq_max;
	uint16_t Freq_min;
	uint16_t Freq_100k;
	float Duty1;
	float Vout;
	float Vout_last;
	float Duty1_last;
	float B0;
	float B1;
	float SrValueA;
	float SrValueB;
}LLC_CAL;


enum PLLSTATUS
{
  Positivephase,
	Negativephase,
	Wrongphase
};

typedef union{
    enum
    {
        pwmSwState_normalOperation = 1,
				pwmSwState_positiveZeroCrossing1,
				pwmSwState_positiveZeroCrossing2,
				pwmSwState_positiveZeroCrossing3,
        pwmSwState_positiveHalf,
				pwmSwState_negativeZeroCrossing1,
        pwmSwState_negativeZeroCrossing2,
				pwmSwState_negativeZeroCrossing3,
				pwmSwState_negativeHalf,
        pwmSwState_defaultState,
    }enum_pwmSwState;
    int16_t pad;
}pwmSwState;


typedef	struct
{
	float	wn;	//	bias raid frequency
	float	fn;	//	bias frequency
	float	wo;	//	instantenous frequency by loop result
	float	arg;	//	phase angle of grid system
	float arg_Prev;

	float	w;	//	raid frequency of grid voltage for reading and fault detection

	float	w_avg;
	float	w_lpf;
	float	w_avg_tmp;
	float	w_avg_sum;

	uint16_t	fg_locked;	//	temporary phase lock flag
}PLL_VAL;

//	10.	bdc runtime variables


typedef	struct
{
	uint16_t	debounce_time;	//	pll phase lock debounce time for stablizing
	uint16_t	debounce_cnt;
	
	float	freq_max;	//	max runtime frequency
	float	freq_min;	//	minimum runtime frequency
	float	freq_nor;	//	nominal 50/60Hz
	float	freq_var;	//	range of freq viberation, normally in 0.5Hz

	float	freq_hyst_high;	//	frequency fault recover threshold
	float	freq_hyst_low;

	uint16_t	freq_hyst_cnt;
	uint16_t	freq_hyst_delaytime;	//	recover time
}PLL_CONF;

typedef	struct
{
	float	b0;
	float	b1;

	float	u[2];
	float	y[2];

	float	max;
	float	min;

	uint16_t	scale;
	uint16_t	cnt;
	//	----------------------------------------------
	//	(20170224)	add averaging multiplier for sacle
	//	add averaging multiplier
	float	avg_mul;
	//	----------------------------------------------

}CTRL_P1Z1;

typedef	struct
{
	float	u[3];	//	sogi input value
	float	al[3];	//	alpha-axis
	float	be[3];	//	structural beta-axis
	//	dp plant variables
	float	d[2];
	float	q[2];
	//	calculating time
	float	dt;

	//	sogi parameters
	float	b0;
	float	a1;
	float	a2;
	float	qb0;
	
	//	sin and cos values for matrix transformation
	float	cos_val;
	float	sin_val;
	float sin_Prev;
}SOGI_VAL;

//	9.	bdc pwm settings
typedef	struct
{
	//	9.1	switching period and interruption scale
	uint16_t	prd;
	float	scale;
	//	9.2	control period
	float	t_ctrl;

	//	9.3	switching frequency
	float	freq;
	//	9.4	duty cycle limitation
	uint16_t	min_duty;
	uint16_t	max_duty;
	//	9.5	half period and quarter period
	uint16_t	prd_half;	//	1/2 period
	uint16_t	prd_quarter;	//	1/4 period
	
}BDC_PWM;

typedef struct
{
    float Fault_RMS;
	float Fault_Vref;
	float Fault_Vout;
    float Fault_Ia;
    float Fault_Ib;
    float Fault_Dutya;
    float Fault_Dutyb; 
    float Fault_Iref;
}FAULTVAL;


typedef union 
{
       uint16_t allFault;
       struct
       {
       uint16_t OverVoltage:1;
       uint16_t UnderVoltage:1;
       uint16_t OverCurrent:1;
       uint16_t ShortCircuit:1;
       uint16_t HardwareOV:1;
       uint16_t HardwareOC:1;
       uint16_t SysRestart:1;
       uint16_t SoftwareTZ:1;
       uint16_t WrongPLL:1;
       uint16_t OverVoltage450V;
       uint16_t bit10:1;
       uint16_t bit11:1;
       uint16_t bit12:1;
       uint16_t bit13:1;
       uint16_t bit14:1;
       uint16_t bit15:1;
       }oneFault;
}FAULTSTATE;

#define fg_AllFault        				FaultState.allFault
#define fg_OverVoltage        		FaultState.oneFault.OverVoltage
#define fg_UnderVoltage          	FaultState.oneFault.UnderVoltage
#define fg_OverCurrent         		FaultState.oneFault.OverCurrent
#define fg_ShortCircuit         	FaultState.oneFault.ShortCircuit
#define fg_HardwareOV							FaultState.oneFault.HardwareOV
#define fg_HardwareOC							FaultState.oneFault.HardwareOC
#define fg_SysRestart  						FaultState.oneFault.SysRestart
#define fg_SoftwareTZ							FaultState.oneFault.SoftwareTZ
#define fg_WrongPLL								FaultState.oneFault.WrongPLL
#define fg_OverVoltage450V        FaultState.oneFault.OverVoltage450V






#define SET_PWM_DBRED(PWMx,u16Delay)  								PWM_SetDeadBandRisingDelay(PWMx,u16Delay)
#define SET_PWM_DBFED(PWMx,u16Delay)                  PWM_SetDeadBandFallingDelay(PWMx,u16Delay)     
#define PWM_OFF                                       PWM_ForceCHAandCHBLow(PWM1);
#define PWM_ON                                        PWM_DisableForceCHAandCHB(PWM1);
#define PWM_CH1_OFF																		PWM_ForceCHALow(PWM1);
#define PWM_CH2_OFF																		PWM_ForceCHBLow(PWM1);
#define PWM_CH1_ON																		PWM_DisableForceCHA(PWM1);
#define PWM_CH2_ON																		PWM_DisableForceCHB(PWM1);

//#define PWM_CH1_ON																		PWM_ForceCHALow(PWM2);
//#define PWM_CH2_ON																		PWM_ForceCHBLow(PWM2);

  

void VoltageCal(void);
void CalVin_rms(void);
void BatteryDetect(void);
void ChargeControl(void);
void PWMcal(void);
void PLL_Status(void);
void ChargeProtect(void);
void Parameter_Loading(void);
void FaultResetVal(void);


extern inline void MeasureCurrent(void);
extern inline void MeasureVoltage(void);
extern void CalRms(void);



void PLLCal(void);
void ResetVal(void);
void	set_sogi_coff(float k, float freq,float dt);
void set_p1z1_coff(float g0, float b1, float max, float min,float dt);
void set_pwm(float freq, float scale);
void	set_pll_conf(float	nor_freq);
void	pll_chk_phase_lock(void);
void ClearCloop(enum PLLSTATUS pll,int times);






#endif
