#ifndef GLOBALDEFINE_H
#define GLOBALDEFINE_H
//#include "fsm.h"

#define    OVP_VALUE				410
#define    OVP_FASTVALUE    410
#define    OVP_RECOVERVALUE 400
#define    OCP_VALUE        23
#define    DEBOUNCE_OVP     8
#define    DEBOUNCE_OCP			8


//one Period is 200M/60K/2 = 1666
#define PFC2_FREQ 						60000
#define PFC2_ON   					  PWM_RunCounter(PWM1)
#define PFC2_OFF  					  PWM_StopCounter(PWM1)
#define PFC2_Duty(x)      		PWM_SetCMPA(PWM1,x)
#define PFC2B_Duty(x)					PWM_SetCMPB(PWM1,x)

#define MINVOLTAGE_POWERON     0.0166f              //5v/137.3636
#define PI_F_2								6.2831853072f
#define PI_F                 3.14159265758f
#define FEEDFORWARD_VOLTAGE       0.1f              //used for changed the feedforward vlotage val
#define ZERO_POINT_VALUE         300
#define VAC_FREQ									50
#define	MIN_DUTY_PERCENT	(float)0.02	//	minimum duty cycle
	
//	2.2	voltage loop and control period
#define	S_CVR_KP	(float)0.134033//
#define	S_CVR_B0	(float)-0.996416//-0.967062
#define	S_CVR_PERIOD	(float)0.001
//	-----------------------------
#define	S_ID_LIMIT	(float)0.549
	
#define CPR_KP  (float)182.142321
#define CPR_B0  (float)-0.995563
#define	CPR_LPF_FREQ	20
#define	CPR_FREQ_BIAS	(float)0.5  
	
#define v110_ON 			    GPIO_WritePin(GPIO_30,GPIO_LEVEL_HIGH) //SUCH AS :GPIO_10  GPIO_LEVEL_HIGH
#define v110_OFF				GPIO_WritePin(GPIO_30,GPIO_LEVEL_LOW) 

#define  ZC_ON                  PWM_ForceCHBHigh(PWM0); 
                               // PWM_SetCMPB(PWM0, 844);    

#define  ZC_OFF                 PWM_ForceCHBLow(PWM0);


#define HardwareOVP_Testing 			GPIO_ReadPin(GPIO_8)
#define HardwareOCP_Testing 			GPIO_ReadPin(GPIO_2)


#define VinRMS_Protect  1                     //Switch rmsprotect
#define DEBUG           0						
#define Iafilter         0




#endif

