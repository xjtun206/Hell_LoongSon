/*
 * uart.h
 *
 *  Created on: 2014-2-21
 *      Author: liming
 */

#ifndef UART_H_
#define UART_H_


/*
 * Uart1_2400B
 * 初始化uart1控制器，波特率设置为2400，并使能uart1_rx中断。
 * 8bit  1stop, odd parity
 */
void Uart1_2400B(void);

/*
 * Uart1_38400B
 * 初始化uart1控制器，波特率设置为38400。
 * 8bit  1stop, odd parity
 */
void Uart1_38400B(void);

/*
 * Uart0_2400B
 * 初始化uart0控制器，波特率设置为2400，并使能uart0_rx中断。
 * 8bit  1stop, odd parity
 */
void Uart0_2400B(void);

/*
 * Uart0_38400B
 * 初始化uart0控制器，波特率设置为38400。
 * 8bit  1stop, odd parity
 */
void Uart0_38400B(void);

/*
 * IrSend
 * 通过select选择uart0和uart1，发送一个字符串。
 */
void IrSend(_u8 *str, _u32 select);

#endif /* UART_H_ */
