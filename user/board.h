/*
 * board.h
 *
 *  Created on: 2014Äê3ÔÂ12ÈÕ
 *      Author: liming
 */

#ifndef BOARD_H_
#define BOARD_H_


void ls1d_timer_process();
void ls1d_waker_process();
void ls1d_softint_process();
void user_task();
void ls1d_scheduler();
void ls1d_Lcd_Init(struct lcd_hw_interface *hw);
void ls1d_tdc_print(TDCINFO *TDC);
void ls1d_key_delay();
_u32 ls1d_adc_init(_u8 channel);
_u32 ls1d_adc_disable(_u8 channel);
void ls1d_infrared_init(_u32 select);
void ls1d_infrared_disable(_u32 select);
void ls1d_infrared_process(void *ptr, _u32 select);

void board_init();

#define BOARD_INFO		"LS1D_Eval_V1.0"
#define SOFTWARE_VER	"1.0"

#endif /* BOARD_H_ */
