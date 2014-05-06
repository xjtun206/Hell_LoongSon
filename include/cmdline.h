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
 * 一个交互式命令行中断程序，用户可输入不同的测试命令来测试芯片的不同功能模块。
 * 命令的参数个数<8，每个参数的字符长度<15。
 */
int cmdline(void);

#endif /* CMDLINE_H_ */
