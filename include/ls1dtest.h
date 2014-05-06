/*
 * 1dtest.h
 *
 *  Created on: 2013-11-4
 *      Author: liming
 */


#include <ls1d.h>

#include "cmdline.h"
#include "cmd.h"
#include "Calendar.h"
#include "lcd-test.h"
#include "tdc-test.h"
#include "flash-test.h"
#include "i2c-test.h"
#include "exint.h"
#include "batfail.h"


extern int printf(char *fmt,...);
extern int strcmp(const char *s1, const char *s2);
extern _u8 tgt_getchar();
extern void tgt_putchar(_u8 chr);
extern _u32 str2num(_u8 *s);
extern void * memset(void * s,int c, int count);
extern void *memcpy(void *s1, const void *s2, int n);

extern _s32 printf_float(_fp32 data);
extern void Uart1_2400B(void);
extern void Uart1_38400B(void);
extern void Uart0_2400B(void);
extern void Uart0_38400B(void);
void IrSend(_u8 *str, _u32 select);

struct SYSTASK_MASK {
	_u32 calendar:1;
	_u32 lcd:1;
	_u32 tdc:1;

};
struct SYSTASK {
	_u32 softint:2;
	_u32 timer:2;   //产生一次时钟中断（8M）
	_u32 waker:2;   //产生一次wake中断
	_u32 calendar:2;   //产生一次calendar任务
	_u32 lcd:2;   //产生一次lcd任务
	_u32 tdc_start:2;
	_u32 tdc_print:2;
	_u32 key:2;

};
struct LS1DTEST {
	struct SYSTASK task;
	struct SYSTASK_MASK mask;
	struct timer_interface timer;
	struct calendar_interface calendar;
	struct waker_interface waker;
	struct rtc_interface rtc;
	struct softint_interface softint;
	struct watchdog_interface wdt;
	struct lcd_interface lcd;
	struct tdc_interface tdc;
	struct key_interface key;
	struct adc_interface adc;
	struct communicate_interface com;
	struct flash_interface flash;
	struct i2c_interface i2c;
	void (*sleep)();
	void (*delay)(_u32 number);

};
extern struct LS1DTEST TEST;

extern _u32 DEBUG;
/********************************Debug Option/Print*******************************************************************************************************************/
#define PRINT 1       //only print necessory information

#if PRINT
#define debug(fmt,args...)			printf(fmt, ##args);
#define debugX(level,fmt,args...) 	if(DEBUG>=level) printf(fmt, ##args);
#define BUG()						debugX(1, "BUG: failure at %s:%d in %s()!\n", __FILE__, __LINE__, __FUNCTION__);
#define BUG_ON(condition) 			if(condition) BUG();
#else
#define debug(fmt,args...)
#define debugX(level,fmt,args...)
#define BUG()
#define BUG_ON(condition)
#endif /* BUG */

