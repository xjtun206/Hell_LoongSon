/*
 * flash-sf.h
 *  Special functions for LS1D-flash.
 *
 *  Created on: 2014-2-21
 *      Author: liming
 */

#ifndef FLASHSF_H_
#define FLASHSF_H_

/*
 * ls1d_flash_boundary
 * 设置flash代码保护边界4K-bound（addr）。
 * 如果设置成功，则返回0；
 */
_u32 ls1d_flash_boundary(_u32 addr);

/*
 * ls1d_flash_encrypt
 * 设置flash加密下边界addr_l和上边界addr_h。
 * 如果设置成功，则返回0；
 */
_u32 ls1d_flash_encrypt(_u32 addr_l, _u32 addr_h);

/*
 * ls1d_flash_verify
 * 对加密地址addr保存的数据data进行校验。
 * 如果校验成功，则返回0；
 */
_u32 ls1d_flash_verify(_u32 addr, _u32 data);

#endif /* FLASHSF_H_ */
