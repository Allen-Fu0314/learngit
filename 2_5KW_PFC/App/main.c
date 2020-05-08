////////////////////////////////////////////////////////////////////////
//
// Copyright (c) [2014-2018] Spintrol Co., Limited
// All Rights Reserved.
//
// NOTICE:  All information contained herein is, and remains
// the property of Spintrol Co., Limited  and its suppliers,
// if any.  The intellectual and technical concepts contained
// herein are proprietary to Spintrol Co., Limited and its
// suppliers and may be covered by Patents, patents in process,
// and are protected by trade secret or copyright law.
//
// Dissemination of this information or reproduction of this material
// is strictly forbidden unless prior written permission is obtained
// from Spintrol Co., Limited.
//
////////////////////////////////////////////////////////////////////////

#include"spc1168.h"

#include<stdio.h>
#include "main.h"

#define               REF3V3_CODE            242221056        /* Ideal code for 3.3V input related to +-3.657143V range. 7392(ideal_code)*32768 */
#define               REF1V2_CODE            88080384         /* Ideal code for 1.2V input related to +-3.657143V range. 2688(ideal_code)*32768 */
#define               LSB                    29257            /* Ideal ADC LSB Votage: 0.44643mV * 65536 */
#define               NREP                   32               /* Unit: time */
#define               TDLY                   1                /* Unit: us */

int32_t               voltage;
int16_t               adc_sha_offset         =0;              /* sampler A offset [-80,80] */
int16_t               adc_shb_offset         =0;              /* sampler B offset [-80,80] */
int16_t               adc_shc_offset         =0;              /* sampler C offset [-80,80] */
uint32_t              adc_sha_gain           =0;              /* sampler A Gain [31130,34406] */
uint32_t              adc_shb_gain           =0;              /* sampler A Gain [31130,34406] */
uint32_t              adc_shc_gain           =0;              /* sampler A Gain [31130,34406] */
float  value;
uint16_t pwm2_clockdiv;
uint16_t pwm_period;
uint16_t pwm2_period;
uint16_t pwm_cmpa;
uint16_t pwm2_cmpa;
uint16_t pwm2_direction;
uint16_t pwm2_CounterValue;
uint32_t pwm2_clock;
uint16_t u16CMPANextVal;
/****************************************************************************//**
 * @brief      ADC Calibration Function to get ADC calibration parameter
 *             method for sampler ADC A : (1) the two channel of sampler A connect to AGND, and save the measure result as 'adc_sha_offset'
 *                                        (2) connect the two channel of sampler A to VDD (3.3V), the measure result is 'VDD_CODE'
 *                                        (3) use 'adc_sha_offset' and 'VDD_CODE' to calculate 'adc_sha_gain'
 *                                        (4) from now on, we get the gain and offset calibration value : 'adc_sha_gain' and 'adc_sha_offset'
 *             method for sampler B and C is the same as A.
 *
 * @param[in]  
 *
 * @return The gain and offset for SHA is saved to adcgaintrim_shagain and adcoffsettrim_shaoffset. 
 *         The gain and offset for SHB is saved to adcgaintrim_shbgain and adcoffsettrim_shboffset. 
 *         These four parameter are save as the global variations.
 *
 * ADC calibration function 
 *******************************************************************************/




int main()
{
	Sys_Config();
	PWM_Config();
	ADC_Config();
	Parameter_Loading();

	
	while(1)
	{
			WDT_FeedDog(WDT1);
			ChargeProtect();	
			
			FSM_Handle();
	//	PowerControl();
        if(fg_10ms)
        {
            fg_10ms =0;
            MotorDebug_UART();
//            if(value <1)
//            {
//                value +=0.1f;
//            }else
//            {
//                value =0.1;
//            }
//             PFC2_Duty(1666*value);
//            PFC2B_Duty(1666*value);
        }
	}
	
}
