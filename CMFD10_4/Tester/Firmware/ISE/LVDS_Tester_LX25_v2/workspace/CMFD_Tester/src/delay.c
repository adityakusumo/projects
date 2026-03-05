/*
 * delay.h
 *
 *  Created on: 26 Jun 2013
 *      Author: Venom
 */

#include "delay.h"


// Global variables
XTmrCtr DelayTimer;



int delay_init(u32 Device_ID)
{
	Xuint32 status;

	status = XTmrCtr_Initialize(&DelayTimer, Device_ID);
	if (status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	XTmrCtr_SetOptions(&DelayTimer, 1, XTC_DOWN_COUNT_OPTION);

	return XST_SUCCESS;
}

// Delay function (microseconds)
void delay_us(Xuint32 time)
{
	  XTmrCtr_SetResetValue(&DelayTimer, 1, time * (TIMER_CLOCK/1000));
	  XTmrCtr_Start(&DelayTimer, 1);
	  while(!(XTmrCtr_IsExpired(&DelayTimer, 1))){}
	  XTmrCtr_Stop(&DelayTimer, 1);
}

// Delay function (milliseconds)
void delay_ms(Xuint32 time)
{
	  XTmrCtr_SetResetValue(&DelayTimer, 1, time * TIMER_CLOCK);
	  XTmrCtr_Start(&DelayTimer, 1);
	  while(!(XTmrCtr_IsExpired(&DelayTimer, 1))){}
	  XTmrCtr_Stop(&DelayTimer, 1);
}
