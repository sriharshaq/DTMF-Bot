
#include "sensors.h"

void sensorsBegin(void)
{
//SMK_DIR &= ~(SMK_BIT);
Adcbegin();
}


unsigned int sensorsReadIR(void)
{
	unsigned int val = 0;
	unsigned int i;
	for(i=0;i<=AVG_SAMPLE_RATE;i++)
	{
		val = val +  analogRead(IR_CH);
	}
	return val / AVG_SAMPLE_RATE;
}

unsigned int sensorsReadFire(void)
{
		unsigned int val = 0;
		unsigned int i;
		for(i=0;i<=AVG_SAMPLE_RATEi++)
		{
			val = val +  analogRead(FIR_CH);
		}
		return val / AVG_SAMPLE_RATE;
}

unsigned char sensorsDetectObstacle(void)
{
if(sensorsReadIR() > IR_THRESHOLD)
return 0;  // Obstacle Found
else
return 1; // No obstacle
}

unsigned char sensorsDetectFire(void)
{
if(sensorsReadFire() > IR_THRESHOLD)
return 0;  // Fire Detected
else
return 1; // No Fires
}