/*
 * uart.h
 *
 *  Created on: 26 Jun 2013
 *      Author: Venom
 */

#ifndef UART_H_
#define UART_H_

#include "xparameters.h"
#include "xstatus.h"
#include "xuartlite_l.h"
#include "xuartlite.h"

XUartLite Uart;
XUartLite_Config Uart_config;

int uart_init(u32 DeviceID);
void uart_puts(u32 BaseAddress, volatile char *s);
void uart_putchar(u32 BaseAddress, char s);
Xuint8 uart_getchar(u32 BaseAddress);



#endif /* UART_H_ */
