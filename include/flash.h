/*
 * flash.h
 *
 *  Created on: 2013-1-16
 *      Author: liming
 */

#ifndef ISP_H_
#define ISP_H_

/*
 * Flash_Erase
 * 擦除addr地址（包含此地址）之后的num个flash页，页大小为FLASH_PAGE_SIZE。
 * 如果擦除成功，则返回0；
 * 		擦除失败，则返回发生擦除错误的页号（1~num+1）。
 */
_u32 Flash_Erase(_u32 addr, _u32 num);

/*
 * Flash_Write
 * 烧写addr地址（包含此地址）之后的num个字，字大小为4字节，支持跨页写和多页写。
 * 无需另外进行擦除操作，写操作之后进行校验。
 * 如果烧写成功，则返回0；
 * 		擦除失败，则返回1;
 * 		校验失败，则返回发生校验错误的字的序号（1~num+1）。
 */
_u32 Flash_Write(_u32 addr, _u32 *data, _u32 num);



#endif /* ISP_H_ */
