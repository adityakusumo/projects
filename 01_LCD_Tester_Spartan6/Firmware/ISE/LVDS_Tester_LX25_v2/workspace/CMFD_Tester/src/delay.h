/*
 * delay.h
 *
 *  Created on: Jul 3, 2013
 *      Author: xilinx_vm
 */

#ifndef DELAY_H_
#define DELAY_H_
#include "xparameters.h"
#include "xbasic_types.h"
#include "xtmrctr.h"

#define  TIMER_CLOCK 100000

// Function prototypes
void delay_us(Xuint32 time);
void delay_ms(Xuint32 time);
int delay_init(u32 Device_ID);

#endif /* DELAY_H_ */
