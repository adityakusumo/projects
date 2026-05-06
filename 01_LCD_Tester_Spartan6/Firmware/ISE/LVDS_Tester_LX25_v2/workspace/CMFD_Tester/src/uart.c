/*
 * uart.c
 *
 *  Created on: 4 Jul 2013
 *      Author: Venom
 */
#include "uart.h"

int uart_init(u32 DeviceID)
{
	XStatus status;

	status = XUartLite_Initialize(&Uart,DeviceID);
	if (status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	status = XUartLite_SelfTest(&Uart);
	if (status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	Uart_config.BaudRate=19200;
	return XST_SUCCESS;
}

void uart_puts(u32 BaseAddress, volatile char *s)
{
	while(*s)
	{
		XUartLite_SendByte(BaseAddress,*s);
		*s++;
	}
}

void uart_putchar(u32 BaseAddress, char s)
{
	XUartLite_SendByte(BaseAddress,s);
}

u8 XUartLite_RecvByte2(u32 BaseAddress)
{
	if (XUartLite_IsReceiveEmpty(BaseAddress)){return 0;}
	else{return (u8)XUartLite_ReadReg(BaseAddress, XUL_RX_FIFO_OFFSET);}

//	if (XUartLite_IsReceiveEmpty(BaseAddress));
//	return (u8)XUartLite_ReadReg(BaseAddress, XUL_RX_FIFO_OFFSET);
}

Xuint8 uart_getchar(u32 BaseAddress)
{
	Xuint8 data;
//	data=XUartLite_RecvByte(BaseAddress);
	data=XUartLite_RecvByte2(BaseAddress);
	return data;
}
