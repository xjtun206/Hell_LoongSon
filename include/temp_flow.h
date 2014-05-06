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
 * ����ʱ���time��ϵ��K�����ٶȣ�ϵ��K�Ĵ�С������Ӧ����ء�
 */
_fp32 time_to_flow(_fp32 time, _fp32 k);  //mL/s

/*
 * time_to_temp
 * ������������ķŵ�ʱ��time�ͱ�׼����ķŵ�ʱ��standard����������������¶ȡ�
 */
_fp32 time_to_temp(_fp32 time, _fp32 standard);

#endif /* TEMP_FLOW_H_ */
