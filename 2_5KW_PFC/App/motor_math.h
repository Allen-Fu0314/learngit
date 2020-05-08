/******************************************************************************
 * @file     motor_math.h
 * @version  V1.00
 * $Revision: 5 $
 * $Date: 17/21/03 5:51p $
 * @brief    
 *
 * @note
 * Copyright (C) 2017 Spintrol Technology Corp. All rights reserved.
*****************************************************************************/
#ifndef __MOTOR_MATH_H__
#define __MOTOR_MATH_H__

#include "spc1168.h"
#include "stdio.h"
#include "math.h"
#include "motor_filter.h"


/****************************************************************************//**
 * @brief      Select the method of calculation of sine and cosine 
 *
 * @select     MATH_SINE_TABLE_TYPE_SEL
 *             In Spintrol motor demo kit, sine function with theta accuracy is 10 bit fixed.  
 *             User can select the different sine table according to dedicated 
 *             application and resource.
 *             - \ref MATH_SINE_TABLE_HALF_PERIOD 
 *                    The table size is half with half period sine table.
 *                    The table size is 1024 Byte, that means, 1KB.
 *             - \ref MATH_SINE_TABLE_QUARTER_PERIOD 
 *                    The table size is quarter full period sine table.
 *                    The table size is 512 Byte, that means, 0.5KB.
 *******************************************************************************/
#define MATH_SINE_TABLE_HALF_PERIOD    (0)
#define MATH_SINE_TABLE_QUARTER_PERIOD (1)
#define MATH_SINE_TABLE_TYPE_SEL       MATH_SINE_TABLE_QUARTER_PERIOD

/****************************************************************************//**
 * @brief      Select the method of calculation atan2(y,x) 
 *
 * @select     MATH_ATAN_TYPE_SEL
 *               The atan2 calculation method (Default is MATH_ATAN_TYPE_TABLE)
 *             - \ref MATH_ATAN_TYPE_TABLE
 *                    It cost table size of table of atan but speed is fast. 
 *                    The table size is 512 byte.
 *             - \ref MATH_ATAN_TYPE_CORDIC 
 *                    The table size is small but takes more CPU cycles to compute.
 *                    The method suits on the application that code size critical.
 *                    The table size is 30 byte.
 *******************************************************************************/
#define MATH_ATAN_TYPE_TABLE   (0)
#define MATH_ATAN_TYPE_CORDIC  (1)
#define MATH_ATAN_TYPE_SEL     MATH_ATAN_TYPE_TABLE


//-  Define Region   -//
#if MATH_SINE_TABLE_TYPE_SEL   == MATH_SINE_TABLE_HALF_PERIOD
  #define C_SINE_TABLE_SIZE 513 
#elif MATH_SINE_TABLE_TYPE_SEL == MATH_SINE_TABLE_QUARTER_PERIOD
  #define C_SINE_TABLE_SIZE (257+1) 
#endif

#define ShiftQ15ThetaToQ

#define I32_DEGREE_360			((int32_t)(-32767))
#define I32_DEGREE_180			((int32_t)32767)
#define I32_DEGREE_120			((int32_t)(21845))
#define I32_DEGREE_90				((int32_t)(I32_DEGREE_180/2))
#define I32_DEGREE_90_2			((int32_t)(32768/2))

#define I32_DEGREE_60				((int32_t)(10922))
#define I32_DEGREE_45				((int32_t)(I32_DEGREE_90/2))
#define I32_DEGREE_30				((int32_t)(I32_DEGREE_180/3))

#define I32_2_PI		    		((int32_t)(32767*2))
#define I32_PI  		    		((int32_t)(32767))
#define I32_PI_Q10          ((uint32_t)((3.14159265358979)*1024))

#define DegreeToPi(x)       ((int32_t)((x)*32767/180))


#define C_1_OVER_SQRT3_Q15  18918
#define C_SQRT3_Q15  				56755
#define C_1_OVER_2_Q15      16383
#define C_SQRT3_OVER_2_Q15  28377 
#define C_2_OVER_SQRT3_Q15  37836 
#define C_1_OVER_3_Q15 			10922
#define C_2_OVER_3_Q15 			21844
#define _MultiplyQ15(x,y)   ((((int32_t)(x))*((int32_t)(y)))>>15)


typedef	union	
{
	uint32_t	All;
	struct
	{
		uint16_t Low;
		uint16_t High;
	}Half; 
}UnionUint32_t;


struct SVPWM_T {
	int32_t i32Amp;
	int32_t i32AmpLimit;
	int32_t i32AmpFilter;
	struct LPF_T sAmpLPF;
};


/****************************************************************************//**
 * @brief      Right shift with rounding
 * @input      Z: input value
 * @input      N: shift bits 
 * @return     result
 *
 *******************************************************************************/
#define RSN(Z, N) (((Z)>>(N)) + (((Z) & ((0x1)<<((N)-1))) != 0))   //

/*	Math table */
extern const int16_t sinTable[C_SINE_TABLE_SIZE];
extern const int16_t atanTable[257];	


#if MATH_SINE_TABLE_TYPE_SEL == MATH_SINE_TABLE_HALF_PERIOD
__STATIC_INLINE int16_t Sine(int16_t i16_Theta)
{
	//int16_t i16ThetaQ10;
	//i16ThetaQ10 = (i16_Theta>>6);//Q15->Q10
	if(i16_Theta>=0)
	{
	  return sinTable[(i16_Theta)>>6];
	}
	else
	{
		return -sinTable[(-i16_Theta)>>6];
	}
	
}
#elif MATH_SINE_TABLE_TYPE_SEL == MATH_SINE_TABLE_QUARTER_PERIOD
__STATIC_INLINE int16_t Sine(int16_t i16_Theta)
{
	/* 有問題的 */
	/*
	int16_t i16ThetaQ10;
	//- Complementary formula -//
	if((i16_Theta > I32_DEGREE_90) || (i16_Theta < (-I32_DEGREE_90)))
	{
		i16_Theta = I32_DEGREE_180 - i16_Theta;
	}
	
	i16ThetaQ10 = (i16_Theta>>6);//Q15->Q10

	if(i16ThetaQ10>=0)
	{
	  return sinTable[(i16ThetaQ10)];
	}
	else
	{
		return -sinTable[(-i16ThetaQ10)];
	}
	
	*/
	
	/*
	int16_t i16ThetaQ10;
	//- Complementary formula -//
	if((i16_Theta > I32_DEGREE_90) || (i16_Theta < (-16384)))
	{
		i16_Theta = I32_DEGREE_180 - i16_Theta;
	}
	
	i16ThetaQ10 = (i16_Theta>>6);//Q15->Q10

	if(i16ThetaQ10>=0)
	{
	  return sinTable[(i16ThetaQ10)];
	}
	else
	{
		return -sinTable[(-i16ThetaQ10)];
	}
	
	*/
	
	
	
  /* OK的 */ 
	//printf("i16_Theta0=%d\n",i16_Theta);

	if((i16_Theta > I32_DEGREE_90))
	{
		
		i16_Theta = (I32_DEGREE_180 - i16_Theta) + 64;		
	}
	else if((i16_Theta < (-16384)))
	{
		
		i16_Theta = (I32_DEGREE_180 - i16_Theta) - 62;
  	//i16_Theta = i16_Theta - 62;
	}
	
	if(i16_Theta>=0)
	{  
	  return sinTable[(i16_Theta)>>6];		
	}
	else
	{
		return -sinTable[(-i16_Theta)>>6];
	}

}
#endif


__STATIC_INLINE int16_t Cosine(int16_t i16_Theta)
{
	/* 20161210 半周期 抓取cosine 有錯誤問題 
	int16_t i16ThetaQ10;
	//printf("Input = %d,",i16_Theta);
	i16_Theta = i16_Theta + I32_DEGREE_90;
	//printf("Output = %d\n",i16_Theta);
	//- Complementary formula -//
	if((i16_Theta > I32_DEGREE_90) || (i16_Theta < (-I32_DEGREE_90)))
	{
		i16_Theta = I32_DEGREE_180 - i16_Theta;
		
	}
	//printf("i16_Theta = %d\n",i16_Theta);
	i16ThetaQ10 = i16_Theta>>6;//Q15->Q10
	//printf("i16ThetaQ10 = %d\n",i16ThetaQ10);
	if(i16ThetaQ10>=0)
	{
	  return sinTable[(i16ThetaQ10)];
	}
	else
	{
		return -sinTable[(-i16ThetaQ10)];
	}
	*/
	
	
	/* OK的 */
	i16_Theta = i16_Theta + I32_DEGREE_90;
	if((i16_Theta > I32_DEGREE_90) || (i16_Theta < (-16384)))
	{
		i16_Theta = I32_DEGREE_180 - i16_Theta;
		
	}
	
	if(i16_Theta>=0)
	{
	  return sinTable[(i16_Theta>>6)];
	}
	else
	{
		return -sinTable[(-i16_Theta)>>6];
	}
	
	
	
}



__STATIC_INLINE void Clarke_Cal(int16_t i16_U,int16_t i16_V,int16_t i16_W,int16_t *pi16_Alpha,int16_t *pi16_Beta)
{

	*pi16_Alpha =_MultiplyQ15(i16_U,C_2_OVER_3_Q15)-_MultiplyQ15(i16_V,C_1_OVER_3_Q15)-_MultiplyQ15(i16_W,C_1_OVER_3_Q15);
	*pi16_Beta  =  ((i16_V - i16_W) * C_1_OVER_SQRT3_Q15) >> 15;  								 
}		
__STATIC_INLINE void  InvPark_Cal(int16_t i16_Vd,int16_t i16_Vq,int16_t i16_Theta,int16_t *pi16_Alpha,int16_t *pi16_Beta)
{
	int16_t i16_Cosine,i16_Sine;
	i16_Cosine=Cosine(i16_Theta);
	i16_Sine=Sine(i16_Theta);
	//printf("sine=%d,cos=%d\n",i32_Sine,i32_Cosine);
	*pi16_Alpha = (i16_Cosine* i16_Vd  - i16_Sine * i16_Vq) >> 15;	
	*pi16_Beta  = (i16_Cosine * i16_Vq + i16_Sine * i16_Vd) >> 15;	
}


__STATIC_INLINE void  Park_Cal(int16_t i16_Alpha,int16_t i16_Beta,int16_t i16_Theta,int16_t *pi16_Id,int16_t *pi16_Iq)
{
	int32_t i32_Cosine,i32_Sine;
	i32_Cosine=Cosine(i16_Theta);
	i32_Sine=Sine(i16_Theta);
	
	*pi16_Id  = (int16_t) ((i32_Cosine * i16_Alpha + i32_Sine * i16_Beta) >> 15);
	*pi16_Iq  = (int16_t) ((i32_Cosine * i16_Beta - i32_Sine * i16_Alpha) >> 15);	 
}		

int16_t Table_atan2(int16_t y, int16_t x);
int16_t Cordic_atan2(int16_t y,int16_t x);

__STATIC_INLINE int16_t Motor_atan2(int16_t y, int16_t x)
{
	#if MATH_ATAN_TYPE_SEL == MATH_ATAN_TYPE_TABLE
	  return Table_atan2(y,x);
	#elif MATH_ATAN_TYPE_SEL == MATH_ATAN_TYPE_CORDIC
	  return Cordic_atan2(y,x);
	#endif
				 
}		

void SVPWM(int32_t i32_V_Alpha,int32_t i32_V_Beta,int32_t i32_PWM_Full_Scale,int16_t* pi32_PWM_A,int16_t* pi32_PWM_B,int16_t* pi32_PWM_C);
uint32_t fast_sqrt( uint32_t i32Input );
float Q_rsqrt( float number );
int Quick_Mod(int x,int y);

int16_t Cosine2(int16_t i16_Theta);
int16_t Sine2(int16_t i16_Theta);

__STATIC_INLINE void  InvPark_Cal32(int16_t i16Vd,int16_t i16Vq,int16_t i16_Theta,int32_t *pi32_Alpha,int32_t *pi32_Beta)
{
	int16_t i16_Cosine,i16_Sine;
	i16_Cosine=Cosine2(i16_Theta);
	i16_Sine=Sine2(i16_Theta);
//	printf("sine=%d,cos=%d\n",i16_Sine,i16_Cosine);
	if((abs(i16Vd) + (abs(i16Vq)) > 32767))
	{
		i16Vd = i16Vd >> 1;
		i16Vq = i16Vq >> 1;
		*pi32_Alpha = (i16_Cosine* i16Vd - i16_Sine * i16Vq) >> 14;	
		*pi32_Beta  = (i16_Cosine *i16Vq + i16_Sine * i16Vd) >> 14;	
	}
	else
	{
		*pi32_Alpha = (i16_Cosine* i16Vd - i16_Sine * i16Vq) >> 15;	
		*pi32_Beta  = (i16_Cosine *i16Vq + i16_Sine * i16Vd) >> 15;	
//		printf("Vd %x, Vq%x\n",i16Vd, i16Vq);
//		printf("%x",  i16_Cosine* i16Vd);
//		printf("%x",  i16_Sine * i16Vq);
//		printf("%x",  i16_Cosine *i16Vq);
//		printf("%x\n",i16_Sine * i16Vd);
	}

}
int32_t Sign(int32_t i32x); 
void OverModulationConstrain2(int32_t i32V_AlphaIn,int32_t i32V_BetaIn,int16_t* pi16V_AlphaOut,int16_t* pi16V_BetaOut);
void SVPWM_ForOverMod(int32_t i32_V_Alpha,int32_t i32_V_Beta,int32_t i32_PWM_Full_Scale,int16_t* pi32_PWM_A,int16_t* pi32_PWM_B,int16_t* pi32_PWM_C);
void FloatToQ15withShift(float f, int16_t* i16T, int8_t* i8shift);

void SVPWM2_Init(struct SVPWM_T* p);
void SVPWM2(int32_t i32_V_Alpha,int32_t i32_V_Beta,int32_t i32_PWM_Full_Scale,int16_t* pi32_PWM_A,int16_t* pi32_PWM_B,int16_t* pi32_PWM_C, struct SVPWM_T* p);
#endif //__MOTOR_MATH_H__
/*** (C) COPYRIGHT 2017 Spintrol Technology Corp. ***/
