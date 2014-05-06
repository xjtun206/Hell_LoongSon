/*
 * sleep.h
 *
 *  Created on: 2014-3-4
 *      Author: liming
 */

#ifndef SLEEP_H_
#define SLEEP_H_

/*
 * ls1d_sleep
 * ��io_selectд��PMU_ChipCtrl�����ø��ù�ϵ��
 * ����io_direction��ֵ����GPIO�������������
 * ����io_status��ֵ����GPIO�������ƽ��
 */
void ls1d_sleep(_u32 io_select, _u32 io_direction, _u32 io_status);

/*
 * Check_Data
 * ����һ�����ݲɼ�ϵͳ��˵��ϵͳ��λ����֮�󣬽�������Ҫ�ָ���ʷ���ݣ�
 * һ��أ���Ҫ��һ������ʧ�ļ������е��ض�λ�ö�����ʷ���ݣ�
 * �����ls1dоƬ��Ƭ��flash�У�����1KB�������SRAM�ж�����ʷ���ݣ�
 * ���û������������ж���ú�����ʵ�֡�
 */
void Check_Data();

#endif /* SLEEP_H_ */
