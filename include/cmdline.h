/*
 * cmdline.h
 *
 *  Created on: 2013-1-11
 *      Author: liming
 */

#ifndef CMDLINE_H_
#define CMDLINE_H_

#define MY_CMD(name,maxargs,repeat,cmd,usage,help)

#define V_NUM	8	//the number of argv
#define V_LEN	15	//the length of argv
#define CMD_BUFF	40

/*
 * cmdline
 * һ������ʽ�������жϳ����û������벻ͬ�Ĳ�������������оƬ�Ĳ�ͬ����ģ�顣
 * ����Ĳ�������<8��ÿ���������ַ�����<15��
 */
int cmdline(void);

#endif /* CMDLINE_H_ */
