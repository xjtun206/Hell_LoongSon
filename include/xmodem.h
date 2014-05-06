/*
 * xmodem.h
 *
 *  Created on: 2013-1-16
 *      Author: liming
 */

#ifndef XMODEM_H_
#define XMODEM_H_

_u32 xmodem(void);

#define SPI_FLASH	0   //Choose flash for spi_flash or chip_flash.
/***********************************xmodem/ISP Option*****************************************************************************************************************/
#define FLASH_PAGE_SIZE		128
#if SPI_FLASH
#define FLASH_ERASE_START	0xbe002000    //Notice that the min-erase block of spi-flash st25vf080 is 4kB.
#define FLASH_ERASE_END		0xbe00ffff   //56kB
#else
#define FLASH_ERASE_START	0xbf002000    //Notice that the min-erase block of 1dchip-flash is 128B.
#define FLASH_ERASE_END		0xbf00ffff   //56kB
#endif

#define BLOCKSIZE       FLASH_PAGE_SIZE
#define COUNT_MASK		PMU_Count_RTC_MASK

struct str_XMODEM
{
    unsigned char SOH;                  //
    unsigned char BlockNo;               //
    unsigned char nBlockNo;               //
    unsigned char Xdata[BLOCKSIZE];       //
    unsigned char CRC16hi;               //CRC16
    unsigned char CRC16lo;               //CRC16
};

#endif /* XMODEM_H_ */
