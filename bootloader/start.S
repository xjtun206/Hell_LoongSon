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
	 * ���������ִ�е�ԭ����������
	 *		��1��ϵͳ������λ��
	 *		��2��ϵͳ�������л��ѣ�
	 */
_start:
	/*
	 *	��ʼ��CPU�ˣ��ر�8M��ʱ������ʼ��CP0���Ʋ�����Ӳ�����㲿����
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
	 *	���оƬ����BS0���ŵ������ƽ(���Ƚ�����������Ϊ���룬Ȼ����м��)
	 *	���Ϊ�͵�ƽ����оƬ��ִ��Ƭ��flash�еĳ���
	 *	���Ϊ�ߵ�ƽ����оƬ��ִ��Ƭ��spi-flash�еĳ���������SPI��������PARAM�Ĵ������ӿ�ȡָ�ٶȡ�
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
	 *	���soft-flag��־λ��ϵͳ��λ�����мĴ����ָ�Ĭ��ֵ����ʱsoft-flagΪ0��
	 *	ϵͳÿ������֮ǰ�������ᱣ֤soft-flagΪһ��0ֵ��������ϵͳ�������л��ѣ���ʱsoft-flag��Ϊ0��
	 */
	li		t0, 0xbfeb0000
	lw		t1, 0xc(t0)
	li		t2, 0xf8000000		#check soft-flag
	and		t3, t1, t2
	bne		zero, t3, 100f		#����Ǵ������л��ѣ��򲻳�ʼ���������1K SRAM
	nop

	/*
	 *	ϵͳ��λ����֮����Ҫ�Բ������1K SRAM����ʼ�������������������
	 *	һ����οռ���������ȫ�ֱ�����һЩ�ؼ����ݡ�
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
	 *	��ʼ����ջ�Ĵ�����һ���ջʹ�õ����4K SRAM
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
	b		1b			#���main�������أ�����ѭ��
	nop

/*******************************************************************/

/*******************************************************************/

_finish:
	nop

/*
	���ж��쳣��ַ���뵽ָ��λ��
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
	 *	ͨ���쳣���
	 */
IntHandle:
	.set noat
	SAVE_ALL

	bal		IRQ_Exception	#�����жϴ�������
	nop

leave:
	LOAD_ALL
	eret
	.set at

_end:
	nop
	nop