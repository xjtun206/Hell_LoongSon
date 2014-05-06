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
 * 初始化看门狗定时器。
 *
 * ls1d_wdt_feed
 * 喂狗。
 *
 * ls1d_wdt_disable
 * 关闭看门狗。
 */
void ls1d_wdt_set(_u32 time);  //second
void ls1d_wdt_feed();
void ls1d_wdt_disable();

#endif /* WATCHDOG_H_ */
