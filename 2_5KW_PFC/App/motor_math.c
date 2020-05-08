/******************************************************************************
 * @file     motor_math.c
 * @version  V1.00
 * $Revision: 5 $
 * $Date: 15/04/01 5:51p $
 * @brief    Template project for BLDC motor MCU
 *
 * @note
 * Copyright (C) 2013 Spintrol Technology Corp. All rights reserved.
*****************************************************************************/

#pragma arm section code = "RAMCODE"


#include "motor_math.h"


const int16_t sinTable[C_SINE_TABLE_SIZE]={
     0,   201,   402,   603,   804,  1005,  1206,  1407,  1608,  1809,  2009,  2210,  2410,  2611,  2811,  3012,  //16
  3212,  3412,  3612,  3811,  4011,  4210,  4410,  4609,  4808,  5007,  5205,  5404,  5602,  5800,  5998,  6195,  //32
  6393,  6590,  6786,  6983,  7179,  7375,  7571,  7767,  7962,  8157,  8351,  8545,  8739,  8933,  9126,  9319,  //48
  9512,  9704,  9896, 10087, 10278, 10469, 10659, 10849, 11039, 11228, 11417, 11605, 11793, 11980, 12167, 12353,  //64
 12539, 12725, 12910, 13094, 13279, 13462, 13645, 13828, 14010, 14191, 14372, 14553, 14732, 14912, 15090, 15269,  //80
 15446, 15623, 15800, 15976, 16151, 16325, 16499, 16673, 16846, 17018, 17189, 17360, 17530, 17700, 17869, 18037,  //96
 18204, 18371, 18537, 18703, 18868, 19032, 19195, 19357, 19519, 19680, 19841, 20000, 20159, 20317, 20475, 20631,  //112
 20787, 20942, 21096, 21250, 21403, 21554, 21705, 21856, 22005, 22154, 22301, 22448, 22594, 22739, 22884, 23027,  //128
 23170, 23311, 23452, 23592, 23731, 23870, 24007, 24143, 24279, 24413, 24547, 24680, 24811, 24942, 25072, 25201,  //144
 25329, 25456, 25582, 25708, 25832, 25955, 26077, 26198, 26319, 26438, 26556, 26674, 26790, 26905, 27019, 27133,  //160
 27245, 27356, 27466, 27575, 27683, 27790, 27896, 28001, 28105, 28208, 28310, 28411, 28510, 28609, 28706, 28803,  //176
 28898, 28992, 29085, 29177, 29268, 29358, 29447, 29534, 29621, 29706, 29791, 29874, 29956, 30037, 30117, 30195,  //192
 30273, 30349, 30424, 30498, 30571, 30643, 30714, 30783, 30852, 30919, 30985, 31050, 31113, 31176, 31237, 31297,  //208
 31356, 31414, 31470, 31526, 31580, 31633, 31685, 31736, 31785, 31833, 31880, 31926, 31971, 32014, 32057, 32098,  //224
 32137, 32176, 32213, 32250, 32285, 32318, 32351, 32382, 32412, 32441, 32469, 32495, 32521, 32545, 32567, 32589,  //240
 32609, 32628, 32646, 32663, 32678, 32692, 32705, 32717, 32728, 32737, 32745, 32752, 32757, 32761, 32765, 32766,  //256

#if MATH_SINE_TABLE_TYPE_SEL == MATH_SINE_TABLE_QUARTER_PERIOD
 32767, 32767};  //Prevent overflow
#else
 32767, 32766, 32765, 32761, 32757, 32752, 32745, 32737, 32728, 32717, 32705, 32692, 32678, 32663, 32646, 32628,  //272
 32609, 32589, 32567, 32545, 32521, 32495, 32469, 32441, 32412, 32382, 32351, 32318, 32285, 32250, 32213, 32176,  //288
 32137, 32098, 32057, 32014, 31971, 31926, 31880, 31833, 31785, 31736, 31685, 31633, 31580, 31526, 31470, 31414,  //304
 31356, 31297, 31237, 31176, 31113, 31050, 30985, 30919, 30852, 30783, 30714, 30643, 30571, 30498, 30424, 30349,  //320
 30273, 30195, 30117, 30037, 29956, 29874, 29791, 29706, 29621, 29534, 29447, 29358, 29268, 29177, 29085, 28992,  //336
 28898, 28803, 28706, 28609, 28510, 28411, 28310, 28208, 28105, 28001, 27896, 27790, 27683, 27575, 27466, 27356,  //352
 27245, 27133, 27019, 26905, 26790, 26674, 26556, 26438, 26319, 26198, 26077, 25955, 25832, 25708, 25582, 25456,  //368
 25329, 25201, 25072, 24942, 24811, 24680, 24547, 24413, 24279, 24143, 24007, 23870, 23731, 23592, 23452, 23311,  //384
 23170, 23027, 22884, 22739, 22594, 22448, 22301, 22154, 22005, 21856, 21705, 21554, 21403, 21250, 21096, 20942,  //400
 20787, 20631, 20475, 20317, 20159, 20000, 19841, 19680, 19519, 19357, 19195, 19032, 18868, 18703, 18537, 18371,  //416
 18204, 18037, 17869, 17700, 17530, 17360, 17189, 17018, 16846, 16673, 16499, 16325, 16151, 15976, 15800, 15623,  //432
 15446, 15269, 15090, 14912, 14732, 14553, 14372, 14191, 14010, 13828, 13645, 13462, 13279, 13094, 12910, 12725,  //448
 12539, 12353, 12167, 11980, 11793, 11605, 11417, 11228, 11039, 10849, 10659, 10469, 10278, 10087,  9896,  9704,  //464
  9512,  9319,  9126,  8933,  8739,  8545,  8351,  8157,  7962,  7767,  7571,  7375,  7179,  6983,  6786,  6590,  //480
  6393,  6195,  5998,  5800,  5602,  5404,  5205,  5007,  4808,  4609,  4410,  4210,  4011,  3811,  3612,  3412,  //496
  3212,  3012,  2811,  2611,  2410,  2210,  2009,  1809,  1608,  1407,  1206,  1005,   804,   603,   402,   201,  //512
#if MATH_SINE_TABLE_TYPE_SEL == MATH_SINE_TABLE_HALF_PERIOD
 0}; 
#endif
#endif





#if MATH_ATAN_TYPE_SEL == MATH_ATAN_TYPE_TABLE
const int16_t atanTable[257] = 
{
	    0,    20,    41,    61,    81,   102,   122,   143,   163,   183,   204,   224,   244,   265,   285,   305,
	  326,   346,   366,   386,   407,   427,   447,   467,   487,   508,   528,   548,   568,   588,   608,   628,
	  649,   669,   689,   709,   729,   749,   769,   788,   808,   828,   848,   868,   888,   907,   927,   947,
	  967,   986,  1006,  1026,  1045,  1065,  1084,  1104,  1123,  1143,  1162,  1181,  1201,  1220,  1239,  1258,
	 1278,  1297,  1316,  1335,  1354,  1373,  1392,  1411,  1430,  1449,  1468,  1486,  1505,  1524,  1542,  1561,
	 1580,  1598,  1617,  1635,  1654,  1672,  1690,  1708,  1727,  1745,  1763,  1781,  1799,  1817,  1835,  1853,
	 1871,  1889,  1907,  1924,  1942,  1960,  1977,  1995,  2012,  2030,  2047,  2065,  2082,  2099,  2117,  2134,
	 2151,  2168,  2185,  2202,  2219,  2236,  2253,  2269,  2286,  2303,  2319,  2336,  2352,  2369,  2385,  2402,
	 2418,  2434,  2451,  2467,  2483,  2499,  2515,  2531,  2547,  2563,  2578,  2594,  2610,  2626,  2641,  2657,
	 2672,  2688,  2703,  2718,  2734,  2749,  2764,  2779,  2794,  2809,  2824,  2839,  2854,  2869,  2884,  2899,
	 2913,  2928,  2942,  2957,  2971,  2986,  3000,  3014,  3029,  3043,  3057,  3071,  3085,  3099,  3113,  3127,
	 3141,  3155,  3169,  3182,  3196,  3210,  3223,  3237,  3250,  3264,  3277,  3290,  3303,  3317,  3330,  3343,
	 3356,  3369,  3382,  3395,  3408,  3421,  3433,  3446,  3459,  3471,  3484,  3496,  3509,  3521,  3534,  3546,
	 3558,  3571,  3583,  3595,  3607,  3619,  3631,  3643,  3655,  3667,  3679,  3691,  3702,  3714,  3726,  3737,
	 3749,  3760,  3772,  3783,  3795,  3806,  3817,  3829,  3840,  3851,  3862,  3873,  3884,  3895,  3906,  3917,
	 3928,  3939,  3949,  3960,  3971,  3982,  3992,  4003,  4013,  4024,  4034,  4045,  4055,  4065,  4076,  4086, 
	 4096,
};	


int16_t Table_atan2(int16_t y, int16_t x)  /* 0~32767 0~2*pi */
{
    int32_t tmp;
	  int16_t result;
    
    if(x)
    {
        tmp = ((int32_t)y * 256) / x;
        
        if((tmp < 0) && (tmp >= -256))
        {
            tmp = -tmp;
            result = atanTable[tmp]*2;
        }
        else if(tmp < -256)
        {
            tmp = (-256 * 256)/tmp;
            result = I32_DEGREE_90 - atanTable[tmp]*2;
        }
        else if(tmp > 256)
        {
            tmp = (256 * 256) / tmp;
            result = I32_DEGREE_90 - atanTable[tmp]*2;
        }
        else if((tmp > 0) && (tmp <= 256))
        {
            result = atanTable[tmp]*2;
        }
        else
        {
            result = 0;
        }
    }
    else
    {
        result = I32_DEGREE_90;
    }
    
    if((x < 0) && (y >= 0))
        result = (int16_t)(I32_DEGREE_180 - result);
    else if((x < 0) && (y < 0))
        result = (int16_t)(I32_DEGREE_180 + result);
    else if((x >= 0) && (y < 0))
        result = (int16_t)( - result);

    return result;
}

#endif

#if MATH_ATAN_TYPE_SEL == MATH_ATAN_TYPE_CORDIC
const int16_t angle[] = {8192, 4836, 2555, 1297, 651, 326, 163, 81, 41, 20, 10, 5, 3, 1, 1};
int16_t Cordic_atan2(int16_t y, int16_t x) 
{
    int i,i32X,i32Y;
    int x_new, y_new,result;
	  
    i32X=abs(x<<15);
    i32Y=(y<<15);
	  
	  result = 0;
		for(i = 0; i < 12; i++)
		{
			if(i32Y > 0)
			{
					x_new = i32X + (i32Y >> i);
					y_new = i32Y - (i32X >> i);

					result += angle[i];
			}
			else
			{
					x_new = i32X - (i32Y >> i);
					y_new = i32Y + (i32X >> i);
							
					result -= angle[i];
			}
			i32X = x_new;
			i32Y = y_new;
		}
		
		
		if((x < 0))
		{
        result = (int16_t)(I32_DEGREE_180 - result);
		}
    return result;
//    
}

#endif

int16_t SAT0(int16_t in,int16_t sat)
{
	if(in>=sat)
	{
		return sat;
	}
	
	if(in<=0)
	{
		return 0;
	}
	return in;
}

void SVPWM(int32_t i32_V_Alpha,int32_t i32_V_Beta,int32_t i32_PWM_Full_Scale,int16_t* pi32_PWM_A,int16_t* pi32_PWM_B,int16_t* pi32_PWM_C)	
{
  #define _IQSVPWM(x) ((int16_t)(((float)(x))*32767.0))
	//- 20161209 Maxwell modify to avoid overflow -> -//
	/*
	int16_t Va,Vb,Vc,t1,t2,temp_sv1,temp_sv2,Sector,Ta,Tb,Tc;
	*/
	//- 20161209 Maxwell modify to avoid overflow <- -//
	
	//- 20161209 Maxwell modify to avoid overflow -> -//
	int32_t Va,Vb,Vc,t1,t2,temp_sv1,temp_sv2,Sector,Ta,Tb,Tc;
	//- 20161209 Maxwell modify to avoid overflow <- -//
	
  Sector = 0;																	
  
	temp_sv1=_MultiplyQ15(C_1_OVER_2_Q15,i32_V_Beta);											
	temp_sv2=_MultiplyQ15(C_SQRT3_OVER_2_Q15,i32_V_Alpha);	/* 0.8660254 = sqrt(3)/2*/		
  
																				
/* Inverse clarke transformation */												
	Va = i32_V_Beta;																
	Vb = -temp_sv1 + temp_sv2;													
	Vc = -temp_sv1 - temp_sv2;			

	if (Va>(0)) Sector = 1;													
	if (Vb>(0)) Sector = Sector+2;											
	if (Vc>(0)) Sector = Sector+4;			
/* X,Y,Z (Va,Vb,Vc) calculations X = Va, Y = Vb, Z = Vc */						
	Va = -i32_V_Beta;																
	Vb = -temp_sv1 - temp_sv2;													
	Vc = -temp_sv1 + temp_sv2;		


/* Sector 0: this is special case for (Ualpha,Ubeta) = (0,0)*/					
																				
switch(Sector)																	
{																				
	case 0:																		
	Ta = _IQSVPWM(0.5);															
	Tb = _IQSVPWM(0.5);															
	Tc = _IQSVPWM(0.5);															
	break;																		
	case 1:   /*Sector 1: t1=Z and t2=Y (abc ---> Tb,Ta,Tc)*/					
	t1 = Vc;																	
	t2 = Vb;																	
	Tb = (_IQSVPWM(1)-t1-t2)>>1;	/* tbon = (1-t1-t2)/2	*/						
	Ta = Tb+t1;			 	/* taon = tbon+t1		*/						
	Tc = Ta+t2;			  	/* tcon = taon+t2		*/						
	break;																		
	case 2:	  /* Sector 2: t1=Y and t2=-X (abc ---> Ta,Tc,Tb)*/ 				
	t1 = Vb;																	
	t2 = -Va;																	
	Ta = (_IQSVPWM(1)-t1-t2)>>1;	/*  taon = (1-t1-t2)/2	*/						
	Tc = Ta+t1;				/*  tcon = taon+t1		*/						
	Tb = Tc+t2;				/*  tbon = tcon+t2		*/						
	break;																		
	case 3:	  /* Sector 3: t1=-Z and t2=X (abc ---> Ta,Tb,Tc)*/					
	t1 = -Vc;																	
	t2 = Va;																	
	Ta = (_IQSVPWM(1)-t1-t2)>>1;	/*  taon = (1-t1-t2)/2	*/						
	Tb = Ta+t1;				/*	tbon = taon+t1		*/						
	Tc = Tb+t2;				/*	tcon = tbon+t2		*/						
	break;																		
	case 4:	  /* Sector 4: t1=-X and t2=Z (abc ---> Tc,Tb,Ta)*/					
	t1 = -Va;																	
	t2 = Vc;																	
	Tc = (_IQSVPWM(1)-t1-t2)>>1;	/*	tcon = (1-t1-t2)/2	*/						
	Tb = Tc+t1;				/*	tbon = tcon+t1		*/						
	Ta = Tb+t2;				/*	taon = tbon+t2		*/						
	break;																		
	case 5:	  /* Sector 5: t1=X and t2=-Y (abc ---> Tb,Tc,Ta)*/					
	t1 = Va;																	
	t2 = -Vb;					/*	tbon = (1-t1-t2)/2	*/						
	Tb = (_IQSVPWM(1)-t1-t2)>>1;	/*	tcon = tbon+t1		*/						
	Tc = Tb+t1;				/*	taon = tcon+t2		*/						
	Ta = Tc+t2;																
	break;																		
	case 6:	  /* Sector 6: t1=-Y and t2=-Z (abc ---> Tc,Ta,Tb)*/				
	t1 = -Vb;																	
	t2 = -Vc;																	
	Tc = (_IQSVPWM(1)-t1-t2)>>1;	/*	tcon = (1-t1-t2)/2	*/						
	Ta = Tc+t1;				/*	taon = tcon+t1		*/						
	Tb = Ta+t2;				/*	tbon = taon+t2		*/						
	break;																		
}																				

	*pi32_PWM_A=_MultiplyQ15(Ta,i32_PWM_Full_Scale); 
	*pi32_PWM_B=_MultiplyQ15(Tb,i32_PWM_Full_Scale); 
	*pi32_PWM_C=_MultiplyQ15(Tc,i32_PWM_Full_Scale);

  *pi32_PWM_A=SAT0(*pi32_PWM_A,i32_PWM_Full_Scale);
	*pi32_PWM_B=SAT0(*pi32_PWM_B,i32_PWM_Full_Scale);
	*pi32_PWM_C=SAT0(*pi32_PWM_C,i32_PWM_Full_Scale);

	
}


void SVPWM_ForOverMod(int32_t i32_V_Alpha,int32_t i32_V_Beta,int32_t i32_PWM_Full_Scale,int16_t* pi32_PWM_A,int16_t* pi32_PWM_B,int16_t* pi32_PWM_C)	
{
  #define _IQSVPWM(x) ((int32_t)(((float)(x))*32767.0))
	//- 20161209 Maxwell modify to avoid overflow -> -//
	/*
	int16_t Va,Vb,Vc,t1,t2,temp_sv1,temp_sv2,Sector,Ta,Tb,Tc;
	*/
	//- 20161209 Maxwell modify to avoid overflow <- -//
	
	//- 20161209 Maxwell modify to avoid overflow -> -//
	int32_t Va,Vb,Vc,t1,t2,temp_sv1,temp_sv2,Sector,Ta,Tb,Tc;
	//- 20161209 Maxwell modify to avoid overflow <- -//
	
  Sector = 0;																	
  
	
	temp_sv1=_MultiplyQ15(C_1_OVER_2_Q15,i32_V_Beta);											
	temp_sv2=_MultiplyQ15(C_SQRT3_OVER_2_Q15,i32_V_Alpha);	/* 0.8660254 = sqrt(3)/2*/		
  
//	temp_sv1=_MultiplyQ15(C_1_OVER_SQRT3_Q15,i32_V_Beta);											
//	temp_sv2=i32_V_Alpha;	/* 0.8660254 = sqrt(3)/2*/		
	
																				
/* Inverse clarke transformation */												
	Va = i32_V_Beta;																
	Vb = -temp_sv1 + temp_sv2;													
	Vc = -temp_sv1 - temp_sv2;			

	if (Va>(0)) Sector = 1;													
	if (Vb>(0)) Sector = Sector+2;											
	if (Vc>(0)) Sector = Sector+4;			
/* X,Y,Z (Va,Vb,Vc) calculations X = Va, Y = Vb, Z = Vc */						
	Va = -i32_V_Beta;																
	Vb = -temp_sv1 - temp_sv2;													
	Vc = -temp_sv1 + temp_sv2;		

  Va = (Va*(int32_t)C_2_OVER_SQRT3_Q15) >> 15;
	Vb = (Vb*(int32_t)C_2_OVER_SQRT3_Q15) >> 15;
	Vc = (Vc*(int32_t)C_2_OVER_SQRT3_Q15) >> 15;

/* Sector 0: this is special case for (Ualpha,Ubeta) = (0,0)*/					
																				
switch(Sector)																	
{																				
	case 0:																		
	Ta = _IQSVPWM(0.5);															
	Tb = _IQSVPWM(0.5);															
	Tc = _IQSVPWM(0.5);															
	break;																		
	case 1:   /*Sector 1: t1=Z and t2=Y (abc ---> Tb,Ta,Tc)*/					
	t1 = Vc;																	
	t2 = Vb;																	
	Tb = (_IQSVPWM(1)-t1-t2)>>1;	/* tbon = (1-t1-t2)/2	*/						
	Ta = Tb+t1;			 	/* taon = tbon+t1		*/						
	Tc = Ta+t2;			  	/* tcon = taon+t2		*/						
	break;																		
	case 2:	  /* Sector 2: t1=Y and t2=-X (abc ---> Ta,Tc,Tb)*/ 				
	t1 = Vb;																	
	t2 = -Va;																	
	Ta = (_IQSVPWM(1)-t1-t2)>>1;	/*  taon = (1-t1-t2)/2	*/						
	Tc = Ta+t1;				/*  tcon = taon+t1		*/						
	Tb = Tc+t2;				/*  tbon = tcon+t2		*/						
	break;																		
	case 3:	  /* Sector 3: t1=-Z and t2=X (abc ---> Ta,Tb,Tc)*/					
	t1 = -Vc;																	
	t2 = Va;																	
	Ta = (_IQSVPWM(1)-t1-t2)>>1;	/*  taon = (1-t1-t2)/2	*/						
	Tb = Ta+t1;				/*	tbon = taon+t1		*/						
	Tc = Tb+t2;				/*	tcon = tbon+t2		*/						
	break;																		
	case 4:	  /* Sector 4: t1=-X and t2=Z (abc ---> Tc,Tb,Ta)*/					
	t1 = -Va;																	
	t2 = Vc;																	
	Tc = (_IQSVPWM(1)-t1-t2)>>1;	/*	tcon = (1-t1-t2)/2	*/						
	Tb = Tc+t1;				/*	tbon = tcon+t1		*/						
	Ta = Tb+t2;				/*	taon = tbon+t2		*/						
	break;																		
	case 5:	  /* Sector 5: t1=X and t2=-Y (abc ---> Tb,Tc,Ta)*/					
	t1 = Va;																	
	t2 = -Vb;					/*	tbon = (1-t1-t2)/2	*/						
	Tb = (_IQSVPWM(1)-t1-t2)>>1;	/*	tcon = tbon+t1		*/						
	Tc = Tb+t1;				/*	taon = tcon+t2		*/						
	Ta = Tc+t2;																
	break;																		
	case 6:	  /* Sector 6: t1=-Y and t2=-Z (abc ---> Tc,Ta,Tb)*/				
	t1 = -Vb;																	
	t2 = -Vc;																	
	Tc = (_IQSVPWM(1)-t1-t2)>>1;	/*	tcon = (1-t1-t2)/2	*/						
	Ta = Tc+t1;				/*	taon = tcon+t1		*/						
	Tb = Ta+t2;				/*	tbon = taon+t2		*/						
	break;																		
}																				

	*pi32_PWM_A=_MultiplyQ15(Ta,i32_PWM_Full_Scale); 
	*pi32_PWM_B=_MultiplyQ15(Tb,i32_PWM_Full_Scale); 
	*pi32_PWM_C=_MultiplyQ15(Tc,i32_PWM_Full_Scale);

  *pi32_PWM_A=SAT0(*pi32_PWM_A,i32_PWM_Full_Scale);
	*pi32_PWM_B=SAT0(*pi32_PWM_B,i32_PWM_Full_Scale);
	*pi32_PWM_C=SAT0(*pi32_PWM_C,i32_PWM_Full_Scale);

}

void OverModand5SVPWM(int32_t i32_V_Alpha,int32_t i32_V_Beta,int32_t i32_PWM_Full_Scale,int16_t* pi32_PWM_A,int16_t* pi32_PWM_B,int16_t* pi32_PWM_C)	
{
	int32_t Va,Vb,Vc,t1,t2,temp_sv1,temp_sv2,Sector,Ta,Tb,Tc;
	
  Sector = 0;																	
 
	temp_sv1=_MultiplyQ15(C_1_OVER_2_Q15,i32_V_Beta);											
	temp_sv2=_MultiplyQ15(C_SQRT3_OVER_2_Q15,i32_V_Alpha);	/* 0.8660254 = sqrt(3)/2*/		
  
//	temp_sv1=_MultiplyQ15(C_1_OVER_SQRT3_Q15,i32_V_Beta);											
//	temp_sv2=i32_V_Alpha;	/* 0.8660254 = sqrt(3)/2*/		
	
																				
/* Inverse clarke transformation */												
	Va = i32_V_Beta;																
	Vb = -temp_sv1 + temp_sv2;													
	Vc = -temp_sv1 - temp_sv2;			

	if (Va>(0)) Sector = 1;													
	if (Vb>(0)) Sector = Sector+2;											
	if (Vc>(0)) Sector = Sector+4;			
	
	
	
/* X,Y,Z (Va,Vb,Vc) calculations X = Va, Y = Vb, Z = Vc */						
	Va = -i32_V_Beta;																
	Vb = -temp_sv1 - temp_sv2;													
	Vc = -temp_sv1 + temp_sv2;		

  Va = (Va*(int32_t)C_2_OVER_SQRT3_Q15) >> 15;
	Vb = (Vb*(int32_t)C_2_OVER_SQRT3_Q15) >> 15;
	Vc = (Vc*(int32_t)C_2_OVER_SQRT3_Q15) >> 15;

/* Sector 0: this is special case for (Ualpha,Ubeta) = (0,0)*/					
//	printf("Sector=%d\n",Sector);																			
switch(Sector)																	
{																				
	case 0:																		
	Ta = _IQSVPWM(0.5);															
	Tb = _IQSVPWM(0.5);															
	Tc = _IQSVPWM(0.5);															
	break;																		
	case 1:   /*Sector 1: t1=Z and t2=Y (abc ---> Tb,Ta,Tc)*/					
	t1 = Vc;																	
	t2 = Vb;																	
	Tb = (_IQSVPWM(1)-t1-t2)>>1;	/* tbon = (1-t1-t2)/2	*/						
	Ta = Tb+t1;			 	/* taon = tbon+t1		*/						
	Tc = Ta+t2;			  	/* tcon = taon+t2		*/						
	
	Tb = Tb - Tc;
	Ta = Ta - Tc;
	Tc = 0;
	break;																		
	case 2:	  /* Sector 2: t1=Y and t2=-X (abc ---> Ta,Tc,Tb)*/ 				
	t1 = Vb;																	
	t2 = -Va;																	
	Ta = (_IQSVPWM(1)-t1-t2)>>1;	/*  taon = (1-t1-t2)/2	*/						
	Tc = Ta+t1;				/*  tcon = taon+t1		*/						
	Tb = Tc+t2;				/*  tbon = tcon+t2		*/			
	
  Ta = Ta - Tb;
	Tc = Tc - Tb;
	Tb = 0;
	break;																		
	case 3:	  /* Sector 3: t1=-Z and t2=X (abc ---> Ta,Tb,Tc)*/					
	t1 = -Vc;																	
	t2 = Va;																	
	Ta = (_IQSVPWM(1)-t1-t2)>>1;	/*  taon = (1-t1-t2)/2	*/						
	Tb = Ta+t1;				/*	tbon = taon+t1		*/						
	Tc = Tb+t2;				/*	tcon = tbon+t2		*/						
	
		
  Ta = Ta - Tc;
	Tb = Tb - Tc;
	Tc = 0;
	break;																		
	case 4:	  /* Sector 4: t1=-X and t2=Z (abc ---> Tc,Tb,Ta)*/					
	t1 = -Va;																	
	t2 = Vc;																	
	Tc = (_IQSVPWM(1)-t1-t2)>>1;	/*	tcon = (1-t1-t2)/2	*/						
	Tb = Tc+t1;				/*	tbon = tcon+t1		*/						
	Ta = Tb+t2;				/*	taon = tbon+t2		*/				

  Tc = Tc - Ta;
	Tb = Tb - Ta;
	Ta = 0;	
	break;																		
	case 5:	  /* Sector 5: t1=X and t2=-Y (abc ---> Tb,Tc,Ta)*/					
	t1 = Va;																	
	t2 = -Vb;					/*	tbon = (1-t1-t2)/2	*/						
	Tb = (_IQSVPWM(1)-t1-t2)>>1;	/*	tcon = tbon+t1		*/						
	Tc = Tb+t1;				/*	taon = tcon+t2		*/						
	Ta = Tc+t2;				

  Tb = Tb - Ta;
	Tc = Tc - Ta;
	Ta = 0;		
	break;																		
	case 6:	  /* Sector 6: t1=-Y and t2=-Z (abc ---> Tc,Ta,Tb)*/				
	t1 = -Vb;																	
	t2 = -Vc;																	
	Tc = (_IQSVPWM(1)-t1-t2)>>1;	/*	tcon = (1-t1-t2)/2	*/						
	Ta = Tc+t1;				/*	taon = tcon+t1		*/						
	Tb = Ta+t2;				/*	tbon = taon+t2		*/			

  Tc = Tc - Tb;
	Ta = Ta - Tb;
	Tb = 0;		
	break;																		
}																				



	*pi32_PWM_A=_MultiplyQ15(Ta,i32_PWM_Full_Scale); 
	*pi32_PWM_B=_MultiplyQ15(Tb,i32_PWM_Full_Scale); 
	*pi32_PWM_C=_MultiplyQ15(Tc,i32_PWM_Full_Scale);
  *pi32_PWM_A=SAT0(*pi32_PWM_A,i32_PWM_Full_Scale);
  *pi32_PWM_B=SAT0(*pi32_PWM_B,i32_PWM_Full_Scale);
  *pi32_PWM_C=SAT0(*pi32_PWM_C,i32_PWM_Full_Scale);
}


// Must with SVPWM_ForOverMod
void OverModulationConstrain2(int32_t i32V_AlphaIn,int32_t i32V_BetaIn,int16_t* pi16V_AlphaOut,int16_t* pi16V_BetaOut)
{
	  int16_t i16VectorTheta;
	  int16_t theta_1,theta_2;
	  int32_t i32LengthofHex;
   	uint32_t u32VAMP;
	  int32_t i32AlphaOut,i32BetaOut;
	
	  i16VectorTheta = Motor_atan2(i32V_BetaIn/2,i32V_AlphaIn/2); // Avoid atan2 input exceeds 32767
	
	  // Calculate the boundary of hexagonal
	  if(i16VectorTheta >=0 && i16VectorTheta<I32_DEGREE_60)
		{
			theta_1 = 0; theta_2 = I32_DEGREE_60;
		}
		else if(i16VectorTheta >=I32_DEGREE_60 && i16VectorTheta<(I32_DEGREE_60*2))
		{
			theta_1 = I32_DEGREE_60; theta_2 = (I32_DEGREE_60*2);
		}
		else if(i16VectorTheta >=(I32_DEGREE_60*2) && i16VectorTheta<I32_DEGREE_180)
		{
			theta_1 = (I32_DEGREE_60*2); theta_2 = I32_DEGREE_180;
		}
		else if(i16VectorTheta <=0 && i16VectorTheta>(-I32_DEGREE_60))
		{
			theta_1 = 0; theta_2 = -I32_DEGREE_60;
		}
		else if(i16VectorTheta <= -I32_DEGREE_60 && i16VectorTheta> -(I32_DEGREE_60*2))
		{
			theta_1 = -I32_DEGREE_60; theta_2 = -(I32_DEGREE_60*2);
		}
		else if(i16VectorTheta <=(I32_DEGREE_60*2) && i16VectorTheta>= -I32_DEGREE_180)
		{
			theta_1 = -(I32_DEGREE_60*2); theta_2 = -I32_DEGREE_180;
		}
		
		//i32LengthofHex = ((((1<<30)-1)/(Cosine(i16VectorTheta -(theta_1+theta_2)/2 )))*(int32_t)C_SQRT3_OVER_2_Q15)>>15;
		i32LengthofHex = ((929887695)/(Cosine(i16VectorTheta -(theta_1+theta_2)/2 )));
		
		
		u32VAMP = fast_sqrt((uint32_t)(i32V_AlphaIn*i32V_AlphaIn) 
	                  + (uint32_t)(i32V_BetaIn*i32V_BetaIn)); 
	
	  if (u32VAMP>(i32LengthofHex))  // 0.866*VDC
	  {
			i32AlphaOut = (i32LengthofHex*Cosine(i16VectorTheta))>>15;
		  i32BetaOut = (i32LengthofHex*Sine(i16VectorTheta))>>15;
	  }
		else
		{
			i32AlphaOut = i32V_AlphaIn;
			i32BetaOut  = i32V_BetaIn;
		}
		
		if(i32AlphaOut>=32767) i32AlphaOut =32767;
		if(i32AlphaOut<=-32767) i32AlphaOut =-32767;
		if(i32BetaOut>=32767) i32BetaOut =32767;
		if(i32BetaOut<=-32767) i32BetaOut =-32767;
		*pi16V_AlphaOut = i32AlphaOut;
		*pi16V_BetaOut  = i32BetaOut;
}


uint32_t fast_sqrt(uint32_t val)
{
  int r = 0;
  int shift,x;
  for(shift=0; shift<32; shift+=2)
  { 
		x=0x40000000l >> shift; 
   if(x + r <= val)
   { 
		val -= x + r;
		r    = (r >> 1) | x;
   } 
	 else
   { 
		 r = r >> 1;
   }
  }
        //if(r < val) ++r;
   return r;
};


const uint32_t sqrt_tab[129] =
{
	0x10000000,0x06a01000,0x051616a0,0x044a1bb6,0x03c72000,0x036a23c7,
	0x03242731,0x02ec2a55,0x02bf2d41,0x02983000,0x02793298,0x025c3511,
	0x0243376d,0x022d39b0,0x021a3bdd,0x02093df7,0x01f84000,0x01ea41f8,
	0x01dc43e2,0x01d045be,0x01c4478e,0x01ba4952,0x01af4b0c,0x01a74cbb,
	0x019e4e62,0x01955000,0x018e5195,0x01875323,0x017f54aa,0x01795629,
	0x017357a2,0x016d5915,0x01675a82,0x01625be9,0x015d5d4b,0x01585ea8,
	0x01536000,0x014e6153,0x014a62a1,0x014663eb,0x01426531,0x013e6673,
	0x013a67b1,0x013768eb,0x01336a22,0x012f6b55,0x012d6c84,0x01296db1,
	0x01266eda,0x01237000,0x01207123,0x011d7243,0x011b7360,0x0118747b,
	0x01167593,0x011276a9,0x011177bb,0x010e78cc,0x010c79da,0x01097ae6,
	0x01087bef,0x01057cf7,0x01037dfc,0x01017eff,0x00ff8000,0x00fd80ff,
	0x00fb81fc,0x00f982f7,0x00f883f0,0x00f584e8,0x00f485dd,0x00f386d1,
	0x00f087c4,0x00ef88b4,0x00ed89a3,0x00ec8a90,0x00ea8b7c,0x00e98c66,
	0x00e78d4f,0x00e68e36,0x00e48f1c,0x00e39000,0x00e190e3,0x00e091c4,
	0x00df92a4,0x00de9383,0x00dc9461,0x00db953d,0x00d99618,0x00d996f1,
	0x00d797ca,0x00d698a1,0x00d59977,0x00d49a4c,0x00d39b20,0x00d19bf3,
	0x00d19cc4,0x00cf9d95,0x00cf9e64,0x00cd9f33,0x00cca000,0x00cba0cc,
	0x00cba197,0x00c9a262,0x00c8a32b,0x00c8a3f3,0x00c6a4bb,0x00c6a581,
	0x00c4a647,0x00c4a70b,0x00c3a7cf,0x00c2a892,0x00c1a954,0x00c0aa15,
	0x00c0aad5,0x00beab95,0x00beac53,0x00bdad11,0x00bcadce,0x00bbae8a,
	0x00bbaf45,0x00bab000,0x00b9b0ba,0x00b8b173,0x00b8b22b,0x00b6b2e3,
	0x00b7b399,0x00b5b450,0x00b5b505
};

uint16_t sqrtu16(uint32_t x)
{
	uint16_t Scale;
	UnionUint32_t Undata;
	uint16_t HighPart,LowPart;

	uint32_t Tmp = x;

	if (Tmp == 0) 
	{
		return 0;
	}
	else if(Tmp >= 0x80000000)
	{
		return 46340;
	}


	if(Tmp < 65536)
	{
		Tmp = Tmp << 15;
		Scale = 15;
	}
	else 
	{
		Scale = 0;
	}
	
	while (!(Tmp & 0x80000000)){
		Scale ++;
		Tmp = Tmp << 1;
	}
	Scale = (Scale - 1) & 0xFFFFFFFE;

	Undata.All = x << Scale;


	Undata.All = Undata.All >> 8;
	HighPart = Undata.Half.High;
	LowPart = Undata.Half.Low;

	Tmp = ((uint32_t)LowPart*(sqrt_tab[HighPart] >> 16) + (sqrt_tab[HighPart] << 16)) >> ((Scale >> 1) + 16);

	return Tmp;
}

float Q_rsqrt( float number )
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;
 
	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//      y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed
 
	return y;
}


int Quick_Mod(int x,int y)
{
	y=(y<0)?(-y):(y);
	while(!(x<y && x>=0))  
	{
		if(x>=y) x=x-y;
		if(x<0) x=x+y;
	}
	return x;
	
}
#define FAST_MATH_Q15_SHIFT 6
int16_t Sine2(int16_t i16_Theta)
{
  int32_t sinVal;                                  /* Temporary variables for input, output */
  int32_t index;                                   /* Index variables */
  int16_t a, b;                                    /* Four nearest output values */
  int16_t fract;                                   /* Temporary values for fractional values */
	
	if(abs(i16_Theta)>16384)
		i16_Theta=32768-i16_Theta;	
	
	if(i16_Theta>=0)
	{  
		index = (i16_Theta)>>FAST_MATH_Q15_SHIFT;
		a     = sinTable[index];
		b     = sinTable[index + 1];
		fract = (i16_Theta - (index << FAST_MATH_Q15_SHIFT));
	}
	else
	{
		index = (-i16_Theta)>>FAST_MATH_Q15_SHIFT;
		a = -sinTable[index];
		b = -sinTable[index + 1];
		fract = (-i16_Theta - (index << FAST_MATH_Q15_SHIFT));
	}
			/* Calculation of fractional value */
		sinVal  = ((1 << FAST_MATH_Q15_SHIFT) - fract) * a;
		sinVal = (sinVal + fract * b) >> FAST_MATH_Q15_SHIFT;		
	
	return (int16_t)sinVal;
}

/**
 * @brief Fast approximation to the trigonometric cosine function for Q15 data.
 * @param[in] x Scaled input value in radians.
 * @return  cos(x).
 *
 * The Q15 input value is in the range [0 +0.9999] and is mapped to a radian
 * value in the range [0 2*pi).
 */

int16_t Cosine2(int16_t i16_Theta)
{
  int32_t cosinVal;                                /* Temporary variables for input, output */
  int32_t index;                                   /* Index variables */
  int16_t a, b;                                    /* Four nearest output values */
  int16_t fract;                                   /* Temporary values for fractional values */

	
	i16_Theta = i16_Theta + I32_DEGREE_90_2;
	
	if(abs(i16_Theta)>16384)
		i16_Theta=32768-i16_Theta;	
	
	if(i16_Theta>=0)
	{  
		index = (i16_Theta)>>FAST_MATH_Q15_SHIFT;
		a     = sinTable[index];
		b     = sinTable[index + 1];
		fract = (i16_Theta - (index << FAST_MATH_Q15_SHIFT));
	}
	else
	{
		index = (-i16_Theta)>>FAST_MATH_Q15_SHIFT;
		a = -sinTable[index];
		b = -sinTable[index + 1];
		fract = (-i16_Theta - (index << FAST_MATH_Q15_SHIFT));
	}
			/* Calculation of fractional value */
		cosinVal  = ((1 << FAST_MATH_Q15_SHIFT) - fract) * a;
		cosinVal  = (cosinVal + fract * b) >> FAST_MATH_Q15_SHIFT;		
	
	return (int16_t)cosinVal;
}

void FloatToQ15withShift(float f, int16_t* i16T, int8_t* i8shift)
{
	int8_t i8shiftTemp;
	i8shiftTemp = 0;
	if (f > 32767.0)
	{
		while (f / 2.0 > 1.0)
		{
			f = f / 2.0;
			i8shiftTemp --;
		}
	}
	else
	{
		while (f * 2.0 < 1.0)
		{
			f = f * 2.0;
			i8shiftTemp ++;
//			printf("%f, %d\n", f, i8shiftTemp);
		}
	}
	
	*i16T    = (int16_t)(f * 32768.0);
	*i8shift = i8shiftTemp;
}


int32_t Sign(int32_t i32x)
{
	if(i32x<0)
	{
	  return -1;
	}
	else if(i32x>0)
	{
		return 1;
	}
	else if(i32x<0)
	{
		return -1;
	}
  else
  {
    return 0;
  }
}
void SVPWM2_Init(struct SVPWM_T* p)
{
	
}

void SVPWM2(int32_t i32_V_Alpha,int32_t i32_V_Beta,int32_t i32_PWM_Full_Scale,int16_t* pi32_PWM_A,int16_t* pi32_PWM_B,int16_t* pi32_PWM_C, struct SVPWM_T* p)
{
    #define _IQSVPWM(x) ((int16_t)(((float)(x))*32767.0))


	int32_t Va,Vb,Vc,t1,t2,temp_sv1,temp_sv2,Sector,Ta,Tb,Tc;

	
 	Sector = 0;																	
  
	temp_sv1=_MultiplyQ15(C_1_OVER_2_Q15,i32_V_Beta);											
	temp_sv2=_MultiplyQ15(C_SQRT3_OVER_2_Q15,i32_V_Alpha);	/* 0.8660254 = sqrt(3)/2*/		
  
																				
	/* Inverse clarke transformation */												
	Va = i32_V_Beta;																
	Vb = -temp_sv1 + temp_sv2;													
	Vc = -temp_sv1 - temp_sv2;			

	if (Va>(0)) Sector = 1;													
	if (Vb>(0)) Sector = Sector+2;											
	if (Vc>(0)) Sector = Sector+4;	
	
	/* X,Y,Z (Va,Vb,Vc) calculations X = Va, Y = Vb, Z = Vc */						
	Va = -i32_V_Beta;																
	Vb = -temp_sv1 - temp_sv2;													
	Vc = -temp_sv1 + temp_sv2;		


	if(Sector==1)
	{
		t1 = Vc;
		t2 = Vb;
	}
	else if(Sector==2)
	{
		t1 = Vb;
		t2 = -Va;
	}
	else if(Sector==3)
	{
		t1 = -Vc;
		t2 = Va;
	}
	else if(Sector==4)
	{
		t1 = -Va;
		t2 = Vc;
	}
	else if(Sector==5)
	{
		t1 = Va;
		t2 = -Vb;
	}
	else if(Sector==6)
	{
		t1 = -Vb;
		t2 = -Vc;
	}
	else
	{
		t1 = 0;
		t2 = 0;
	}

	p->i32Amp = -(t1+t2);
	if(p->i32Amp >= p->i32AmpLimit)
	{
		t1 = (int32_t) p->i32AmpLimit * t1 / p->i32Amp;
		t2 = (int32_t) p->i32AmpLimit * t2 /p->i32Amp;
	}
	p->i32Amp = -(t1+t2);
	
	p->sAmpLPF.sInput.i16Input = p->i32Amp;
	LPF_Calculate(&p->sAmpLPF);
	p->i32AmpFilter = p->sAmpLPF.sOutput.i16Output;

																				
	switch(Sector)																	
	{																				
		case 0:																		
		Ta = _IQSVPWM(0.5);															
		Tb = _IQSVPWM(0.5);															
		Tc = _IQSVPWM(0.5);															
		break;																		

		case 1:   /*Sector 1: t1=Z and t2=Y (abc ---> Tb,Ta,Tc)*/																					
		Tb = (_IQSVPWM(1)-t1-t2)>>1;	/* tbon = (1-t1-t2)/2	*/						
		Ta = Tb+t1;			 	/* taon = tbon+t1		*/						
		Tc = Ta+t2;			  	/* tcon = taon+t2		*/						
		break;	
		
		case 2:	  /* Sector 2: t1=Y and t2=-X (abc ---> Ta,Tc,Tb)*/ 																				
		Ta = (_IQSVPWM(1)-t1-t2)>>1;	/*  taon = (1-t1-t2)/2	*/						
		Tc = Ta+t1;				/*  tcon = taon+t1		*/						
		Tb = Tc+t2;				/*  tbon = tcon+t2		*/						
		break;	
		
		case 3:	  /* Sector 3: t1=-Z and t2=X (abc ---> Ta,Tb,Tc)*/																						
		Ta = (_IQSVPWM(1)-t1-t2)>>1;	/*  taon = (1-t1-t2)/2	*/						
		Tb = Ta+t1;				/*	tbon = taon+t1		*/						
		Tc = Tb+t2;				/*	tcon = tbon+t2		*/						
		break;		
		
		case 4:	  /* Sector 4: t1=-X and t2=Z (abc ---> Tc,Tb,Ta)*/																					
		Tc = (_IQSVPWM(1)-t1-t2)>>1;	/*	tcon = (1-t1-t2)/2	*/						
		Tb = Tc+t1;				/*	tbon = tcon+t1		*/						
		Ta = Tb+t2;				/*	taon = tbon+t2		*/						
		break;	
		
		case 5:	  /* Sector 5: t1=X and t2=-Y (abc ---> Tb,Tc,Ta)*/									/*	tbon = (1-t1-t2)/2	*/						
		Tb = (_IQSVPWM(1)-t1-t2)>>1;	/*	tcon = tbon+t1		*/						
		Tc = Tb+t1;				/*	taon = tcon+t2		*/						
		Ta = Tc+t2;																
		break;		
		
		case 6:	  /* Sector 6: t1=-Y and t2=-Z (abc ---> Tc,Ta,Tb)*/																				
		Tc = (_IQSVPWM(1)-t1-t2)>>1;	/*	tcon = (1-t1-t2)/2	*/						
		Ta = Tc+t1;				/*	taon = tcon+t1		*/						
		Tb = Ta+t2;				/*	tbon = taon+t2		*/						
		break;																		
	}																				

	*pi32_PWM_A=_MultiplyQ15(Ta,i32_PWM_Full_Scale); 
	*pi32_PWM_B=_MultiplyQ15(Tb,i32_PWM_Full_Scale); 
	*pi32_PWM_C=_MultiplyQ15(Tc,i32_PWM_Full_Scale);

    *pi32_PWM_A=SAT0(*pi32_PWM_A,i32_PWM_Full_Scale);
	*pi32_PWM_B=SAT0(*pi32_PWM_B,i32_PWM_Full_Scale);
	*pi32_PWM_C=SAT0(*pi32_PWM_C,i32_PWM_Full_Scale);

}



#pragma arm section
/*** (C) COPYRIGHT 2017 Spintrol Technology Corp. ***/
