/*
 * interrupt.h
 *	Used for interrupt, save and restore regs.
 *
 *  Created on: 2013-1-10
 *      Author: liming
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

/****************************************************************************/
#define	SAVE_ALL	\
	addi	sp, -132;	\
	sw	$0, 0x80(sp);	\
	sw	$1, 0x7c(sp);	\
	sw	$2, 0x78(sp);	\
	sw	$3, 0x74(sp);	\
	sw	$4, 0x70(sp);	\
	sw	$5, 0x6c(sp);	\
	sw	$6, 0x68(sp);	\
	sw	$7, 0x64(sp);	\
	sw	$8, 0x60(sp);	\
	sw	$9, 0x5c(sp);	\
	sw	$10, 0x58(sp);	\
	sw	$11, 0x54(sp);	\
	sw	$12, 0x50(sp);	\
	sw	$13, 0x4c(sp);	\
	sw	$14, 0x48(sp);	\
	sw	$15, 0x44(sp);	\
	sw	$16, 0x40(sp);	\
	sw	$17, 0x3c(sp);	\
	sw	$18, 0x38(sp);	\
	sw	$19, 0x34(sp);	\
	sw	$20, 0x30(sp);	\
	sw	$21, 0x2c(sp);	\
	sw	$22, 0x28(sp);	\
	sw	$23, 0x24(sp);	\
	sw	$24, 0x20(sp);	\
	sw	$25, 0x1c(sp);	\
	sw	$26, 0x18(sp);	\
	sw	$27, 0x14(sp);	\
	sw	$28, 0x10(sp);	\
	sw	$29, 0xc(sp);	\
	sw	$30, 0x8(sp);	\
	sw	$31, 0x4(sp)


#define	LOAD_ALL	\
	lw	$0, 0x80(sp);	\
	lw	$1, 0x7c(sp);	\
	lw	$2, 0x78(sp);	\
	lw	$3, 0x74(sp);	\
	lw	$4, 0x70(sp);	\
	lw	$5, 0x6c(sp);	\
	lw	$6, 0x68(sp);	\
	lw	$7, 0x64(sp);	\
	lw	$8, 0x60(sp);	\
	lw	$9, 0x5c(sp);	\
	lw	$10, 0x58(sp);	\
	lw	$11, 0x54(sp);	\
	lw	$12, 0x50(sp);	\
	lw	$13, 0x4c(sp);	\
	lw	$14, 0x48(sp);	\
	lw	$15, 0x44(sp);	\
	lw	$16, 0x40(sp);	\
	lw	$17, 0x3c(sp);	\
	lw	$18, 0x38(sp);	\
	lw	$19, 0x34(sp);	\
	lw	$20, 0x30(sp);	\
	lw	$21, 0x2c(sp);	\
	lw	$22, 0x28(sp);	\
	lw	$23, 0x24(sp);	\
	lw	$24, 0x20(sp);	\
	lw	$25, 0x1c(sp);	\
	lw	$26, 0x18(sp);	\
	lw	$27, 0x14(sp);	\
	lw	$28, 0x10(sp);	\
	lw	$29, 0xc(sp);	\
	lw	$30, 0x8(sp);	\
	lw	$31, 0x4(sp);	\
	addi	sp, 132

/****************************************************************************/

#endif /* INTERRUPT_H_ */
