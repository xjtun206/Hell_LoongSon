/*
 * Interrupt.h
 *
 *  Created on: 2013-1-16
 *      Author: liming
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

/*
 * SOFT_INT��TIMER1_INT��WAKER_INT��KEY_INT��BAT_FAIL��RES_VALID��INTC��EXINT
 * �ֱ���8���жϵĴ�������
 */
void SOFT_INT();
void TIMER1_INT();
void WAKER_INT();
void KEY_INT();
void BAT_FAIL();
void RES_VALID();
void INTC();
void EXINT();

/*
 * Schedule
 * ������Ⱥ�����
 */
void Schedule();

/*
 * IRQ_Exception
 * �жϴ�����������ڡ�
 */
void IRQ_Exception();   //�жϴ�����

/*
 * ls1d_waker_init
 * ��ʼ��wake��ʱ����ʹ��waker�жϡ�
 */
void ls1d_waker_init(_u32 wake_delay);

/*
 * ls1d_timer_init
 * ��ʼ��8M��ʱ����
 *
 * ls1d_disable_timer
 * �ر�8M��ʱ����
 */
void ls1d_timer_init(_u32 timer_delay);
void ls1d_disable_timer();

/*
 * ls1d_set_soft_int
 * �����������һ��soft�жϡ�
 */
void ls1d_set_soft_int();


#endif /* INTERRUPT_H_ */
