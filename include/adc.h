/*
 * adc.h
 *
 *  Created on: 2013-11-13
 *      Author: liming
 */

#ifndef ADC_H_
#define ADC_H_

/*
 * ls1d_ADC_MEASURE
 * 执行一次电压检测，参考电压为芯片VIO引脚的输入电压，
 * 返回测量通道channel（输入电压）相对于参考电压的比值。
 */
_u32 ls1d_ADC_MEASURE(_u8 channel);

#endif /* ADC_H_ */
