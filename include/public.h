/*
 * public.h
 *
 *  Created on: 2013-1-10
 *      Author: liming
 */

#ifndef PUBLIC_H_
#define PUBLIC_H_

_s32 printf_float(_fp32 data);  //print float number
_u32 str2num(_u8 *s);
void my1d_delay(_u32 number);
//_fp32 average(_fp32 *data, _u32 num);  //return the average of data[0]~data[num-1]
_u32 UintToBcd(_u32 data, _u8 *bcd_buf);  //translate a unsinged int data to BCD code
//_fp32 my_average(_fp32 *delta, _u32 len, _u32 num);   //��delta��len�����ݽ�������ȥ��num��С�ĺʹ�ģ���ʣ�����ƽ��

#endif /* PUBLIC_H_ */
