/*
 * i2c-test.h
 *
 *  Created on: 2014-2-14
 *      Author: liming
 */

#ifndef I2CTEST_H_
#define I2CTEST_H_

/*
 * IIC_test_cycle
 * iic master∂À≤‚ ‘≥Ã–Ú°£
 *
 * ls1d_iic_test
 * iic slave∂À≤‚ ‘≥Ã–Ú°£
 */
void IIC_test_cycle(_u8 slave_addr);
void ls1d_iic_test(void);

/*
 * eeprom_test_cycle
 * iic eeprom∂¡–¥≤‚ ‘≥Ã–Ú°£
 */
void eeprom_test_cycle(_u8 eeprom_byte_addr, _u32 rd_num, _u32 wd_num);

#endif /* I2CTEST_H_ */
