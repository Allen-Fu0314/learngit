#include "AdcFunction.h"


uint8_t fg_rms = 0;
uint8_t fg_SOCrms = 0;
//float Vinbuff[75];
extern PWMCALVAL pwmcalval;
extern enum PLLSTATUS pllstatus;

ADCVALUE ADCvalue;
PROTECTVAL protectval;
//13λADC
void ADC_Config()
{
		//Vout AD
	 ADC_Reset(); 
	//Currenta AD
    ADC_EasyInit1(AD_CruA,ADC6_GPIO6,ADCTRIG_PWM1SOCA);
    ADC_EasyInit1(AD_CruB,ADC7_GPIO7,ADCTRIG_PWM1SOCA);
	ADC_EasyInit1(AD_Vout,ADC4_GPIO4,ADCTRIG_PWM1SOCA);
//	ADC_EasyInit1(AD_Vin, ADC0_GPIO0,ADCTRIG_PWM1SOCA);
    ADC_EasyInit1(AD_Vrms,ADC1_GPIO1,ADCTRIG_PWM1SOCA);
//	ADC_EasyInit1(AD_Ref,ADC10_GPIO10,ADCTRIG_PWM1SOCA);

	//	ADC_SetAverageCnt(ADC_SOC_6, ADCSOCCTL0_BIT_AVGCNT_AVG_8);
	ADC_SetSOCSH(ADC_SOC_1, SHA_AND_SHB_SHC);
	NVIC_EnableIRQ(ADC1_IRQn);
}


void ADC1_IRQHandler(void)
{
         ADCvalue.Ia = ADC_GetTrimResult1(AD_CruA);
        ADCvalue.Ib = ADC_GetTrimResult1(AD_CruB);
//       ADCvalue.Iref = ADC_GetTrimResult1(AD_Ref);
//		ADCvalue.Vin = ADC_GetResult(AD_Vin);
		ADCvalue.Vout = ADC_GetTrimResult1(AD_Vout);
        ADCvalue.Vrms = ADC_GetTrimResult1(AD_Vrms);    
		
      /* Clear SOC INT */
  ADC_ClearInt1();

  /* Clear SOC INT flag */
  ADC_ClearInt(ADC_SOC_1);
}

void ADC5_IRQHandler(void)
{

}




inline void MeasureVoltage()
{

		pwmcalval.Vout =ADCvalue.Vout*0.000446465f;  //22/3022 = 0.00728 3022/22 = 137.3636   3.657/8191= 0.000446465
		protectval.VOUT = (int16_t)(pwmcalval.Vout*141.9f);   //  1/0.00625
		protectval.VIN = (int16_t)(pwmcalval.Vin*141.9f); // 1/0.0036217
		protectval.IA =(int16_t)(pwmcalval.Ia*7.407f);
    protectval.IB =(int16_t)(pwmcalval.Ib*7.407f);

	
}

inline void MeasureCurrent()  
{
		pwmcalval.Ia =(float)ADCvalue.Ia*0.000446465f;//(ADCvalue.Ia-ADCvalue.Iref)*0.000446465f;    //200/34 = 5.882352*0.000446411 = 0.00262595
		protectval.IA =(int16_t)(pwmcalval.Ia)*7.407f; //6.944f);
		pwmcalval.Ib =(float)ADCvalue.Ib*0.000446465f;//(ADCvalue.Ia-ADCvalue.Iref)*0.000446465f;    //200/34 = 5.882352*0.000446411 = 0.00262595
		protectval.IB =(int16_t)(pwmcalval.Ia)*7.407f;
		
}







void MeasureSumVol()
{

}

void TIMER2_IRQHandler(void)
{

	
}

void TIMER0_IRQHandler(void)
{
	TIMER_ClearInt(TIMER0);
}

unsigned int maxnum(uint16_t array[] , int count)
{
	  unsigned int max = array[0];
		unsigned char i;
    for(i=1;i<count;i++)
    {
        if(array[i]>max)
				{
            max = array[i];
        }
    }
    return max; 
}

unsigned int minnum(uint16_t array[],int count)
{
   unsigned int min = array[0];
		unsigned char i;
    for(i=1;i<count;i++)
    {
        if(array[i]<min)
				{
            min = array[i];
        }
    }
    return min;
}
