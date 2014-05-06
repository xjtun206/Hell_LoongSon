/*
 * sysinit.c
 *
 *  Created on: 2014Äê3ÔÂ12ÈÕ
 *      Author: liming
 */


#include "user.h"

_u32 DEBUG;

int sys_init()
{
	printf("\n%s...\n", __FUNCTION__);
	if(!(PMU_ChipCtrl & 0xf8000000))
	{
		DEBUG = 4;  //print information in detail, 3 is nomal

		memset(&LS1D, 0, sizeof(struct SYSTEM));
		LS1D.info.timer_delay = 0x1000000;
		LS1D.Schedule = ls1d_scheduler;

		memset(&TEST, 0, sizeof(struct LS1DTEST));
		TEST.timer.init = ls1d_timer_init;
		TEST.timer.process = ls1d_timer_process;
		TEST.timer.disable = ls1d_disable_timer;
		TEST.waker.init = ls1d_waker_init;
		TEST.waker.process = ls1d_waker_process;
		TEST.rtc.init = Calendar_Init;
		TEST.rtc.process = Calendar_print;
		TEST.softint.set = ls1d_set_soft_int;
		TEST.softint.process = ls1d_softint_process;
		TEST.wdt.set = ls1d_wdt_set;
		TEST.wdt.feed = ls1d_wdt_feed;
		TEST.wdt.disable = ls1d_wdt_disable;
		TEST.lcd.init = ls1d_Lcd_Init;
		TEST.lcd.process = lcd_print;
		TEST.lcd.poweron = ls1d_lcd_poweron;
		TEST.lcd.powerdown = ls1d_lcd_powerdown;
		TEST.lcd.clear = LcdClear;
		TEST.lcd.print_all = LcdPrintAll;
		TEST.lcd.write_reg = WriteLcdRegs;
		TEST.tdc.init = ls1d_InitTdc;
		TEST.tdc.select = ls1d_tdc_select;
		TEST.tdc.mop = Tdc_mop;
		TEST.tdc.start = ls1d_tdc_start;
		TEST.tdc.print = ls1d_tdc_print;
		TEST.key.open = ls1d_key_open;
		TEST.key.close = ls1d_key_close;
		TEST.key.process = ls1d_key_delay;
		TEST.adc.init = ls1d_adc_init;
		TEST.adc.process = ls1d_ADC_MEASURE;
		TEST.adc.disable = ls1d_adc_disable;

#if 0 //MBUS
#else //infrared
		TEST.com.init = ls1d_infrared_init;
		TEST.com.disable = ls1d_infrared_disable;
		TEST.com.process = ls1d_infrared_process;
		TEST.com.buf = (_u8 *)0xa0000000;
		TEST.com.len = 0x20;
#endif
		LS1D.uart_com = ls1d_infrared_process;
		LS1D.ptr = (void *)&TEST;
		LS1D.iic_process = ls1d_iic_test;
		LS1D.exint_process = ls1d_exint_test;
		LS1D.batfail_process = ls1d_batfail_test;

		TEST.flash.write = Flash_Write;
		TEST.flash.erase = Flash_Erase;
		TEST.flash.change_bound = ls1d_flash_boundary;
		TEST.flash.encrypt = ls1d_flash_encrypt;
		TEST.flash.verify = ls1d_flash_verify;
		TEST.i2c.master_init = ls1d_IIC_master_init;
		TEST.i2c.slave_init = ls1d_IIC_slave_init;
		TEST.i2c.write_addr = ls1d_IIC_write_addr;
		TEST.i2c.write_data = ls1d_IIC_write_data;
		TEST.i2c.write_the_last_data = ls1d_IIC_write_data_stop;
		TEST.i2c.read = ls1d_IIC_read;
		TEST.i2c.read_the_last_data = ls1d_IIC_read_stop;
		TEST.sleep = ls1d_sleep;
		TEST.delay = my1d_delay;

		board_init();

		PMU_SecToken = PMU_SecToken_chipctrl;
		PMU_ChipCtrl |= 0xf8000000;
	}

    return 0;

}

#if 0
void tgt_putchar(_u8 chr)
{
	while(!(Uart0_LSR & 0x20)) ;
	Uart0_TxData = chr;
}

_u8 tgt_getchar()
{
	_u8 chr;
	while(!(Uart0_LSR & 0x1)) ;
	chr = Uart0_RxData ;

	return chr;
}

_u8 tgt_testchar()
{
	_u8 chr;
	chr = (Uart0_LSR & 0x1);

	return chr;
}
#endif
