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
 * ����flash���뱣���߽�4K-bound��addr����
 * ������óɹ����򷵻�0��
 */
_u32 ls1d_flash_boundary(_u32 addr);

/*
 * ls1d_flash_encrypt
 * ����flash�����±߽�addr_l���ϱ߽�addr_h��
 * ������óɹ����򷵻�0��
 */
_u32 ls1d_flash_encrypt(_u32 addr_l, _u32 addr_h);

/*
 * ls1d_flash_verify
 * �Լ��ܵ�ַaddr���������data����У�顣
 * ���У��ɹ����򷵻�0��
 */
_u32 ls1d_flash_verify(_u32 addr, _u32 data);

#endif /* FLASHSF_H_ */
