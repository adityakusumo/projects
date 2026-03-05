/*
 * Gpio.c
 *
 *  Created on: 13 Mar 2018
 *      Author: aditya_kusumo
 */
#include "gpio.h"
int gpio_init(u32 DeviceID)
{
	XStatus status;
	status = XGpio_Initialize(&gpio,DeviceID);
	if (status!=XST_SUCCESS){
		return XST_FAILURE;
	}
	return XST_SUCCESS;
}
void set(u32 mask)
{
	XGpio_SetDataDirection(&gpio,1,mask & ~mask);
	XGpio_DiscreteSet(&gpio,1,mask);
}
void reset(u32 mask)
{
	XGpio_SetDataDirection(&gpio,1,mask & ~mask);
	XGpio_DiscreteClear(&gpio,1,mask);
}
int PushButton_init(u32 DeviceID)
{
	XStatus status;
	XGpio_Initialize(&gpPB, DeviceID);
	if (status!=XST_SUCCESS){
		return XST_FAILURE;
	}
	return XST_SUCCESS;
}
int ReadPushButton(int mask)
{
	int val;
	val = longbit - mask;
	return val;
}
