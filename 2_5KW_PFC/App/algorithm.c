#include "algorithm.h"


RMSCAL rmscal;
extern PWMCALVAL pwmcalval;
extern RMSCALVAL rmscalval;

void CalRms()
{
	rmscal.LastVoltage = rmscal.RealVoltage;
	rmscal.RealVoltage = pwmcalval.Vin;
	if(rmscal.fg_FallingEdge)
	{
		if(rmscal.RealVoltage>=0)
		{
			rmscal.VinRMS = rmscal.calvalue/rmscal.calcount;
			rmscalval.RMSVin = rmscal.VinRMS;
			rmscalval.fg_rms = 1;
			rmscal.calcount = 0;
			rmscal.calvalue =0;
			
		}
	}
	if((rmscal.RealVoltage>=0)&&(rmscal.LastVoltage<0))
	{
		rmscal.fg_FallingEdge = 0;
		rmscal.fg_RisingEdge = 1;

	}
	if((rmscal.RealVoltage<0)&&(rmscal.LastVoltage>=0))
	{
		rmscal.fg_FallingEdge = 1;
		rmscal.fg_RisingEdge = 0;
		rmscal.calcount++;
		rmscal.calvalue+=rmscal.RealVoltage*rmscal.RealVoltage;
	}
	if((rmscal.fg_RisingEdge)||(rmscal.fg_FallingEdge))
	{
		rmscal.calcount++;
		rmscal.calvalue+=rmscal.RealVoltage*rmscal.RealVoltage;
	}
}

