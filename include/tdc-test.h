/*
 * tdc-test.h
 *
 *  Created on: 2013-11-6
 *      Author: liming
 */

#ifndef TDCTEST_H_
#define TDCTEST_H_

struct tdc_interface {
	void *info;
	void (*init)();
	void (*select)();
	void (*mop)();
	void (*start)();
	void (*print)();
};

#define S_TDC	2
#define R_TDC	1
#define H_TDC	0


#endif /* TDCTEST_H_ */
