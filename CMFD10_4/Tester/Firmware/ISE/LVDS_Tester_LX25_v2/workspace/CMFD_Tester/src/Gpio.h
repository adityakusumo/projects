/*
 * Gpio.h
 *
 *  Created on: 13 Mar 2018
 *      Author: aditya_kusumo
 */

#ifndef GPIO_H_
#define GPIO_H_
#include "xstatus.h"
#include "xgpio.h"
#include "xgpio_l.h"
#include "xutil.h"
#define longbit 0x0F
XGpio gpio;
XGpio gpPB;
int gpio_init(u32 DeviceID);
void set(u32 mask);
void reset(u32 mask);
int PushButton_init(u32 DeviceID);
int ReadPushButton(int mask);
#endif /* GPIO_H_ */
