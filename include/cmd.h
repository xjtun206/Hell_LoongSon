/*
 * cmd.h
 *
 *  Created on: 2013-11-1
 *      Author: liming
 */

#ifndef CMD_H_
#define CMD_H_

int do_d1(int argc, void *argv[]);
int do_d4(int argc, void *argv[]);
int do_m1(int argc, void *argv[]);
int do_m4(int argc, void *argv[]);
int do_sleep(int argc, void *argv[]);
int clock_test(int argc, void *argv[]);
int lcd_test(int argc, void *argv[]);
int key_test(int argc, void *argv[]);
int exint_test(int argc, void *argv[]);
int float_test(int argc, void *argv[]);
int eeprom_test(int argc, void *argv[]);
int iic_test(int argc, void *argv[]);
int wdt_test(int argc, void *argv[]);
int timer_test(int argc, void *argv[]);
int softint_test(int argc, void *argv[]);
int batfail_test(int argc, void *argv[]);
int infrared_test(int argc, void *argv[]);
int adc_test(int argc, void *argv[]);
int tdc_test(int argc, void *argv[]);
int flash_test(int argc, void *argv[]);
int disable_timer(int argc, void *argv[]);
int debug_level(int argc, void *argv[]);


struct timer_interface {
	void (*init)();
	void (*process)();
	void (*disable)();
};
struct waker_interface {
	void (*init)();
	void (*process)();
};
struct rtc_interface {
	void (*init)();
	void (*process)();
};
struct softint_interface {
	void (*set)();
	void (*process)();
};
struct watchdog_interface {
	void (*set)();
	void (*feed)();
	void (*disable)();
};
struct key_interface {
	void (*open)();
	void (*close)();
	void (*process)();
};
struct adc_interface {
	_u32 (*init)(_u8 channel);
	_u32 (*process)(_u8 channel);
	_u32 (*disable)(_u8 channel);
};
struct communicate_interface {
	void (*init)(_u32 select);
	void (*disable)(_u32 select);
	_u8 *buf;
	_u32 ptr;
	_u32 len;
	void (*process)(void *ptr, _u32 select);
};
struct flash_interface {
	_u32 (*write)(_u32 addr, _u32 *data, _u32 num);
	_u32 (*erase)(_u32 addr, _u32 num);
	_u32 (*change_bound)(_u32 addr);
	_u32 (*encrypt)(_u32 addr_l, _u32 addr_h);
	_u32 (*verify)(_u32 addr, _u32 data);
};
struct i2c_interface {
	void (*master_init)(_u32 clk);
	void (*slave_init)(_u8 slave_addr);
	void (*write_addr)(_u8 addr, _u8 cmd);
	void (*write_data)(_u8 data);
	void (*write_the_last_data)(_u8 data);
	_u8 (*read)();
	_u8 (*read_the_last_data)();
};

#endif /* CMD_H_ */
