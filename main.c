/*
 * main.c
 *
 *  Created on: 2014-2-21
 *      Author: liming
 */


#include "user/user.h"


struct SYSTEM LS1D;
struct LS1DTEST TEST;

int main()
{

	Uart1_38400B();
	INTERRUPT_ENABLE;
	printf("\n------------Welcome to LS1D!---------------\n\n");

	sys_init();

	cmdline();

	/*Ö÷Ñ­»·*/
	while(1)
	{
		printf("111\n");
		printf("222\n");
		printf("333\n");
	}

	return 0;
}
