/*
 * board.c
 *
 *  Created on: 2014年3月12日
 *      Author: liming
 */


#include "user.h"

/***********************************Lcd Option*****************************************************************************************************************/
#if 0
	//0~9 A b C d E F
	const _u8 LCD_NUMBER[] = {
	    0x7d, /* "0" */
	    0X60, /* "1" */
	    0X3e, /* "2" */
	    0X7a, /* "3" */
	    0X63, /* "4" */
	    0X5b, /* "5" */
	    0X5F, /* "6" */
	    0X70, /* "7" */
	    0X7F, /* "8" */
	    0X7b  /* "9" */
	};
	const _u8 LCD_WORD[] = {
	    0x77, /* "A" */
	    0x4F, /* "b" */
	    0x1D, /* "C" */
	    0x6E, /* "d" */
	    0x1F, /* "E" */
	    0x17  /* "F" */
	};
	#define MINUS	0x2
	#define DOT		0x80
#else
	//0~9 A b C d E F
	const _u8 LCD_NUMBER[] = {
	    0xeb, /* "0" */
	    0X60, /* "1" */
	    0Xc7, /* "2" */
	    0Xe5, /* "3" */
	    0X6c, /* "4" */
	    0Xad, /* "5" */
	    0Xaf, /* "6" */
	    0Xe0, /* "7" */
	    0Xef, /* "8" */
	    0Xed  /* "9" */
	};
	const _u8 LCD_WORD[] = {
	    0xee, /* "A" */
	    0x2f, /* "b" */
	    0x07, /* "C" */
	    0x67, /* "d" */
	    0x8f, /* "E" */
	    0x8e  /* "F" */
	};
	#define MINUS	0x4
	#define DOT		0x10
#endif

/***********************************temp-flow Option*****************************************************************************************************************/
#define FLOW_V	(1.49f*1.49f*3.14f*13.5f*13.5f/(2*62*4*1000))

/***********************************key Option*****************************************************************************************************************/
#define KEY_OFF		0x800        //when the key is off, the key_bit of gpio_in will be high



void ls1d_timer_process()
{
	printf("\n...8MHz Timer interrupt...\r\n\n");
}
void ls1d_waker_process()
{
	printf("\n...waker interrupt...\r\n\n");
}
void ls1d_softint_process()
{
	printf("\n...soft interrupt...\r\n\n");
}

void user_task()
{
	if(TEST.task.softint) {
		TEST.task.softint--;
		TEST.softint.process();
	}
	if(TEST.task.timer) {
		TEST.task.timer--;
		TEST.timer.process();
	}
	if(TEST.task.waker) {
		TEST.task.waker--;
		TEST.waker.process();
	}
	if(TEST.task.calendar) {
		TEST.task.calendar--;
		TEST.rtc.process(&TEST.calendar);
	}
	if(TEST.task.lcd) {
		TEST.task.lcd--;
		TEST.lcd.process(&TEST.lcd);
	}
	if(TEST.task.key) {
		TEST.task.key--;
		TEST.key.process();
	}
	if(TEST.task.tdc_start) {
		TEST.task.tdc_start--;
		TEST.tdc.start();
	}
	if(TEST.task.tdc_print) {
		TEST.task.tdc_print--;
		TEST.tdc.print(&LS1D.tdc);
	}

}

void ls1d_scheduler()
{
	if(LS1D.flag.softint) {
		LS1D.flag.softint = 0;
		TEST.task.softint++;

	}
	if(LS1D.flag.timer) {
		LS1D.flag.timer = 0;
		TEST.task.timer++;

	}
	if(LS1D.flag.waker) {
		LS1D.flag.waker = 0;
		TEST.task.waker++;
		if(TEST.mask.calendar)
			TEST.task.calendar++;
		if(TEST.mask.lcd)
			TEST.task.lcd++;
		if(TEST.mask.tdc)
			TEST.task.tdc_start++;

	}
	if(LS1D.flag.key) {
		LS1D.flag.key = 0;
		TEST.task.key++;

	}
	if(LS1D.flag.res) {
		LS1D.flag.res = 0;
		TEST.task.tdc_print++;

	}
	user_task();
}

void ls1d_Lcd_Init(struct lcd_hw_interface *hw)
{
	Lcd_HW_Init();
	hw->number = LCD_NUMBER;
	hw->word = LCD_WORD;
	hw->minus = MINUS;
	hw->dot = DOT;
	hw->num_length = LCD_NUM_LENGTH;

}

void ls1d_tdc_print(TDCINFO *TDC)
{
	_fp32 tmp;
	_u32 i;

	if(TDC->err) {
		printf("error\n");
	} else {
		switch(TDC->mop) {
		case mode_0:
		case mode_2:
//			printf("\n------------flow-result:-----------------");
			for(i=0; i<16; i++)
			if((i == 0)||(i == 1)||(i == 2)||(i == 6)||(i == 7)
					||(i == 8)||(i == 9)||(i == 10)||(i == 14)||(i == 15))
				printf("\nresult[%d]: 0x%x", i, TDC->result[i]);

			printf("\nup:%d\tdown:%d\tdelta:%d",
					(_u32)TDC->tdc_data.ftime1,
					(_u32)TDC->tdc_data.ftime2,
					(_u32)TDC->tdc_data.time_delta
			);
			break;
		case mode_1:
		case mode_3:
#if 0
			for(i=0; i<4; i++)
				printf("PT%d: %d\t", i+1, (_u32)TDC->tdc_data.ptime[i]);
			printf("\n");
#else
			tmp = TDC->tdc_data.ptime[2] + TDC->tdc_data.ptime[3];
			_fp32 temp1 = time_to_temp(TDC->tdc_data.ptime[0]*2, tmp);
			_fp32 temp2 = time_to_temp(TDC->tdc_data.ptime[1]*2, tmp);
			printf("\ntemp1:");
			printf_float(temp1);
			printf("\ttemp2:");
			printf_float(temp2);
#endif
			break;
		case mode_4:
			printf("\ntdc->cal: %d\n", TDC->tdc_data.cal);
			break;
		case mode_5:
			break;
		case mode_6:
			break;
		}
	}
	printf("\n--------------------------end---------------------\n\n");
//		PMU_SecToken = PMU_SecToken_command;
//		PMU_CommandW = 0x1;  //cpu power down

}
void ls1d_key_delay()
{
	static _u32 last_count;
	_u32 count, gpio_in, key_delay = 0;
	count = now();

	gpio_in = PMU_GPIO_I;
	if(gpio_in & KEY_OFF)
	{
		printf("\nkey_int: off\n");
		key_delay = (count - last_count)%0x100000;
		printf("\tkey_delay: %d\n", key_delay);
	}
	else
	{
		debugX(4, "key_int: on\n");
		last_count = count;
	}

}

_u32 ls1d_adc_init(_u8 channel)
{
	switch(channel) {
	case 0: /* adci_0*/
	case 1: /* adci_1*/
		INTERRUPT_DISABLE;
		PMU_SecToken = PMU_SecToken_chipctrl;
		PMU_ChipCtrl |= 0x40;
		INTERRUPT_ENABLE;
		PMU_GPIO_OE |= 0x1000;  //empi output
		PMU_GPIO_O &= ~0x1000;  //empi output '0'
		break;
	case 2: /* Vcore */
	case 3: /* 1.0V*/
		break;
	default:
		break;
	}
	return 0;
}
_u32 ls1d_adc_disable(_u8 channel)
{
	switch(channel) {
	case 0: /* adci_0*/
	case 1: /* adci_1*/
		PMU_GPIO_O |= 0x1000;  //empi output '1'
		break;
	case 2: /* Vcore */
	case 3: /* 1.0V*/
		break;
	default:
		break;
	}
	return 0;
}

void ls1d_infrared_init(_u32 select)
{
    PMU_GPIO_OE |= (1 << 10)|(1<<2);  //IRPWR -> GPIO output
    PMU_GPIO_O |= (1 << 10)|(1<<2);  //IRPWR -> GPIO output
	//IR_PWR_ON();

    if(select == 0)
    {
    	Uart0_2400B();
    	Uart0_MCR |= 0x80; //0xa0;  	//MCR bit7: enable 38k;  bit6: Rx录芦脨脭;  bit5: Tx录芦脨脭
    }
    else
    {
    	Uart1_2400B();
    	Uart1_MCR |= 0x80; //0xa0;  	//MCR bit7: enable 38k;  bit6: Rx录芦脨脭;  bit5: Tx录芦脨脭
    }

}

void ls1d_infrared_disable(_u32 select)
{
    PMU_GPIO_O &= ~((1 << 10)|(1<<2));  //IRPWR -> GPIO output
	//IR_PWR_OFF();
    if(select == 0)
    	INT_EN     &= ~0x08;		//disable uart0 int
    else
		INT_EN     &= ~0x04;		//disable uart1 int

}

void ls1d_infrared_process(void *ptr, _u32 select)
{
	struct LS1DTEST *TEST = (struct LS1DTEST *)ptr;
	if(select == 0)
		(*TEST).com.buf[(*TEST).com.ptr++] = Uart0_RxData;
	else
		(*TEST).com.buf[(*TEST).com.ptr++] = Uart1_RxData;

}

void board_init()
{
	printf("\n%s: %s\nsoftware_version: %s\n",
			__FUNCTION__,
			BOARD_INFO,
			SOFTWARE_VER);

	/* 上电后lcd屏幕全显 */
	PMU_SecToken = PMU_SecToken_chipctrl;
	PMU_ChipCtrl &= ~(1<<9);
	PMU_SecToken = PMU_SecToken_chipctrl;
	PMU_ChipCtrl |= (1<<8);
	LCD_FB_0 = 0xffffffff;
	LCD_FB_1 = 0xffffffff;
	LCD_FB_2 = 0xffffffff;
}
