#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "spc1168.h"
#include "ChargeFunction.h"
typedef struct
{
	uint8_t fg_RisingEdge;
	uint8_t fg_FallingEdge;
	uint16_t calcount;
	float LastVoltage;
	float RealVoltage;
	float calvalue;
	float VinRMS;
}RMSCAL;

void CalRms(void);

#endif
