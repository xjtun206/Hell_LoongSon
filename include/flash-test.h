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
 * flash 擦写次数老化测试1，反复擦写flash_addr~0xbfc0ff00之间的flash页。
 *
 * flash_w_test2
 * flash 擦写次数老化测试2，反复擦写test_base_addr开始的100个flash页。
 */
_s32 flash_w_test1(_u32 flash_addr, _u32 test_data);
_s32 flash_w_test2();

#endif /* FLASH_H_ */
