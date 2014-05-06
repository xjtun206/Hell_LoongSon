/*
 * spi-flash.h
 *
 *  Created on: 2014-3-4
 *      Author: liming
 */

#ifndef SPIFLASH_H_
#define SPIFLASH_H_

void spiflash_erase(_u32 addr_start, _u32 addr_end);
void spiflash_write(_u32 addr_w, _u32 addr_r, _u32 length);


#endif /* SPIFLASH_H_ */
