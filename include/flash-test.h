/*
 * flash-test.h
 *
 *  Created on: 2014-2-13
 *      Author: liming
 */

#ifndef FLASH_H_
#define FLASH_H_

/*
 * flash_w_test1
 * flash ��д�����ϻ�����1��������дflash_addr~0xbfc0ff00֮���flashҳ��
 *
 * flash_w_test2
 * flash ��д�����ϻ�����2��������дtest_base_addr��ʼ��100��flashҳ��
 */
_s32 flash_w_test1(_u32 flash_addr, _u32 test_data);
_s32 flash_w_test2();

#endif /* FLASH_H_ */
