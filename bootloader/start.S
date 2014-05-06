/*
 * start.S
 *	Jump to C from ASM.
 *
 *  Created on: 2013-1-10
 *      Author: liming
 */

#include <mipsregs.h>
#include <interrupt.h>

#define SRAM_BASEADDR			0xa0000000

	.set noreorder

	.globl _start
	.text
	/*
	 * 程序从这里执行的原因有两个：
	 *		（1）系统正常复位；
	 *		（2）系统从休眠中唤醒；
	 */
_start:
	/*
	 *	初始化CPU核，关闭8M定时器，初始化CP0控制部件和硬件浮点部件。
	 */
	li		t0, 0x8000000   #disable cp0_count
	mtc0	t0, CP0_CAUSE
	li      t0, 0x30400000
    mtc0    t0, CP0_STATUS
	li		t0, 0x00000000  #set fp reg, it's necessory
	ctc1	t0, $31

	/* disable NMI */
	li		t0, 0xbfea8010
	li		t1, 0x5a
	sb		t1, 0(t0)
	li		t1, 0xa5
	sb		t1, 0(t0)
	li		t1, 0x0
	sb		t1, 0(t0)

	/*
	 *	检测芯片引脚BS0引脚的输入电平(首先将此引脚设置为输入，然后进行检测)
	 *	如果为低电平，则芯片是执行片内flash中的程序，
	 *	如果为高电平，则芯片是执行片外spi-flash中的程序，则配置SPI控制器的PARAM寄存器，加快取指速度。
	 */
	li		t0, 0xbfeb0000
	lw		t1, 0x10(t0)
	li		t2, 0xfffbffff
	and		t3, t1, t2
	sw		t3, 0x10(t0)

	lw		t1, 0x18(t0)
	li		t2, 0x40000
	and		t3, t1, t2
	beq		zero, t3, 1f
	nop

	li		t0, 0xbfe70000
	li		t1, 0x17
	sb		t1, 0x4(t0)

1:
	/*
	 *	检测soft-flag标志位，系统复位后所有寄存器恢复默认值，此时soft-flag为0；
	 *	系统每次休眠之前，软件会保证soft-flag为一非0值，因此如果系统从休眠中唤醒，此时soft-flag不为0。
	 */
	li		t0, 0xbfeb0000
	lw		t1, 0xc(t0)
	li		t2, 0xf8000000		#check soft-flag
	and		t3, t1, t2
	bne		zero, t3, 100f		#如果是从休眠中唤醒，则不初始化不掉电的1K SRAM
	nop

	/*
	 *	系统复位操作之后，需要对不掉电的1K SRAM做初始化操作，即清零操作；
	 *	一般这段空间用来保存全局变量和一些关键数据。
	 */
	li		t1, 0xa0001000
	li		t2, 0x400
10:
	move	v0, zero
	sw		v0, 0x0(t1)
	addu	t1, 4
	addu	t2, -4
	bne		zero, t2, 10b
	nop

100:
	/*
	 *	初始化堆栈寄存器，一般堆栈使用掉电的4K SRAM
	 */
	li		t0, SRAM_BASEADDR+0xffc
	la		sp, 0(t0)

	/*
	 *	jump to C code
	 */
	la		t9, main
	jr		t9
	nop

1:
	b		1b			#如果main函数返回，则死循环
	nop

/*******************************************************************/

/*******************************************************************/

_finish:
	nop

/*
	将中断异常地址对齐到指定位置
*/
    .align 9
    nop
    .align 8
    nop
    .align 7
/*
	Please make sure that the address of IntHandle is 0xbfc00380!!!
*/
	/*
	 *	通用异常入口
	 */
IntHandle:
	.set noat
	SAVE_ALL

	bal		IRQ_Exception	#跳到中断处理函数
	nop

leave:
	LOAD_ALL
	eret
	.set at

_end:
	nop
	nop
