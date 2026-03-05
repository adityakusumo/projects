/*
 * main.c
 *
 *  Created on: Jun 21, 2021
 *      Author: DIT
 */
#include <xparameters.h>
#include <xbasic_types.h>
#include <xstatus.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "delay.h"
//#include "font2.h"
//#include <math.h>
#include <xuartlite_l.h>
#include <xuartlite.h>
#include "uart.h"
#include "gpio.h"

#define Led0 0x01
#define Led1 0x02
#define TIMER_DEVICEID	XPAR_XPS_TIMER_0_DEVICE_ID
#define LED_ID			XPAR_LEDS_DEVICE_ID
#define UART_BASEADDR	XPAR_XPS_UARTLITE_0_BASEADDR
#define UART_DEVICEID	XPAR_XPS_UARTLITE_0_DEVICE_ID

char rxdat=0, rxdatL;
char txt[30];
unsigned int len=0, mode=0, cnt=0, cnt2=0;

int main(void)
{
	print("Peripheral Initialization..!\r\n");
	delay_init(TIMER_DEVICEID);
	uart_init(UART_DEVICEID);
	gpio_init(LED_ID);

	delay_ms(10);
	print("Initialization done!!!\r\n");

	reset(Led0|Led1);
	delay_ms(9000);

	while(1){
		set(Led0|Led1);
	}

//	while(0)
//	{
//		rxdat=(char)uart_getchar(UART_BASEADDR);
//
//		if (rxdat==(char)0xC5){
//			if(mode==0)
//				mode=1;
//			else
//				mode=0;
//		}
//
//
//		if (mode==0) {
//			set(Led0|Led1);
//			delay_ms(50);
//		}else{
//			reset(Led0|Led1);
//			delay_ms(50);
//		}
//
////		rxdatL = rxdat;
//
//		len=sprintf(txt, "recv:%c mode:%u\r\n", rxdat+0, mode);
//		uart_puts(UART_BASEADDR,(volatile char*)txt);
//
//		XUartLite_ClearStats(&Uart);
//	}
}
