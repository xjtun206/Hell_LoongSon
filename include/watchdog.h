/*
 * watchdog.h
 *
 *  Created on: 2014-3-4
 *      Author: liming
 */

#ifndef WATCHDOG_H_
#define WATCHDOG_H_

/*
 * ls1d_wdt_set
 * ��ʼ�����Ź���ʱ����
 *
 * ls1d_wdt_feed
 * ι����
 *
 * ls1d_wdt_disable
 * �رտ��Ź���
 */
void ls1d_wdt_set(_u32 time);  //second
void ls1d_wdt_feed();
void ls1d_wdt_disable();

#endif /* WATCHDOG_H_ */
