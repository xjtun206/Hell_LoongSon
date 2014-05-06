/*
 * Calendar.h
 *
 *  Created on: 2013-1-16
 *      Author: liming
 */

#ifndef CALENDAR_H_
#define CALENDAR_H_

struct Date_Time{
    _u32 Year;
    _u32 Month;
    _u32 Day;
    _u32 Hour;
    _u32 Minute;
    _u32 Second;
};
struct calendar_interface {
	struct Date_Time clock;
	_u32 tick;
	void (*init)();
	void (*refresh)();
	void (*modify)();
};


/*
 * Calendar_Init
 * ��ʼ����ʱ��Calendar�����ݽṹ��
 *
 * Calendar_print
 * ��ӡ��ʱ��Calendar��ʱ����Ϣ��
 */
void Calendar_Init(struct calendar_interface *calendar);
void Calendar_print(struct calendar_interface *calendar);

#endif /* CALENDAR_H_ */
