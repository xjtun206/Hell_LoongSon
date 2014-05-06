/*
 * 1dfunc.h
 *
 *  Created on: 2013-11-4
 *      Author: liming
 */


#include <ls1d.h>

#include "uart.h"
#include "flash.h"
#include "xmodem.h"
#include "Interrupt.h"
#include "public.h"
#include "lcd.h"
#include "tdc.h"
#include "temp_flow.h"
#include "adc.h"
#include "I2C.h"
#include "flash-sf.h"
#include "watchdog.h"
#include "key.h"
#include "sleep.h"
#include "spi-flash.h"
#include "isp.h"

extern int printf(char *fmt,...);

struct SYSFLAG {
	_u32 softint:1;
	_u32 timer:1;   //产生一次时钟中断（8M）
	_u32 waker:1;   //产生一次wake中断
	_u32 key:1;
	_u32 res:1;

};
struct SYSINFO {
	_u32 wake_delay;
	_u32 timer_delay;

};
struct SYSTEM {
	TDCINFO tdc;
	struct SYSFLAG flag;
	struct SYSINFO info;
	void (*Schedule)();
	void (*batfail_process)();
	void (*iic_process)();  //iic-int process
	void (*uart_com)();  //uart-int process
	void (*exint_process)();
	_u32 debug;
	_u32 err;
	void *ptr;
};
extern struct SYSTEM LS1D;

