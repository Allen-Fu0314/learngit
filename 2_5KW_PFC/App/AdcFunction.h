#ifndef ADCFUNCTION_H
#define ADCFUNCTION_H
#include "math.h"
#include "spc1168.h"
#include "isr.h"
#include "ChargeFunction.h"

#define 							V_VOLTAGE_CAL_VALUE          2000
#define 							ADC_CAL_VOLTAGE_VALUE(x)     (3.657*x)/8192				 
#define               SAMPLETIMENS                 150
#define               CONVTIMENS                   150

#define               AD_CruA                      	ADC_SOC_1
#define               AD_CruB                       ADC_SOC_2
#define               AD_Ref                      	ADC_SOC_3
#define               AD_Vout                       ADC_SOC_4
#define               AD_Vin                        ADC_SOC_5
#define               AD_Vrms                       ADC_SOC_6

#define               ADValue_AC10V                 180

extern volatile unsigned char fg_EndofConversion;

typedef struct
{
	int16_t Vin;
	int16_t Vout;
	int16_t Ia;
    int16_t Ib;
    int16_t Vrms;
	int16_t Iref;
}ADCVALUE;

typedef struct
{
	int16_t VIN;
	int16_t VOUT;
	int16_t IA;
	float IB;
	float VinRMS;
	float VoutProtect;
}PROTECTVAL;

inline void MeasureVoltage(void);
inline void MeasureCurrent(void); 


void ADC_Config(void);
void MeasureSumVol(void);
float Cal_RMS(float* pData , int nNum);

unsigned int maxnum(uint16_t array[] , int count);
unsigned int minnum(uint16_t array[],int count);

#endif
