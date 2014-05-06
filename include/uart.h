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
 * ��ʼ��uart1������������������Ϊ2400����ʹ��uart1_rx�жϡ�
 * 8bit  1stop, odd parity
 */
void Uart1_2400B(void);

/*
 * Uart1_38400B
 * ��ʼ��uart1������������������Ϊ38400��
 * 8bit  1stop, odd parity
 */
void Uart1_38400B(void);

/*
 * Uart0_2400B
 * ��ʼ��uart0������������������Ϊ2400����ʹ��uart0_rx�жϡ�
 * 8bit  1stop, odd parity
 */
void Uart0_2400B(void);

/*
 * Uart0_38400B
 * ��ʼ��uart0������������������Ϊ38400��
 * 8bit  1stop, odd parity
 */
void Uart0_38400B(void);

/*
 * IrSend
 * ͨ��selectѡ��uart0��uart1������һ���ַ�����
 */
void IrSend(_u8 *str, _u32 select);

#endif /* UART_H_ */
