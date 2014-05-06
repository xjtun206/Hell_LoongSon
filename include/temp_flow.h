/*
 * temp_flow.h
 *
 *  Created on: 2013-11-8
 *      Author: liming
 */

#ifndef TEMP_FLOW_H_
#define TEMP_FLOW_H_

/*
 * time_to_flow
 * 根据时间差time和系数K计算速度，系数K的大小跟具体应用相关。
 */
_fp32 time_to_flow(_fp32 time, _fp32 k);  //mL/s

/*
 * time_to_temp
 * 根据热敏电阻的放电时间time和标准电阻的放电时间standard，计算热敏电阻的温度。
 */
_fp32 time_to_temp(_fp32 time, _fp32 standard);

#endif /* TEMP_FLOW_H_ */
