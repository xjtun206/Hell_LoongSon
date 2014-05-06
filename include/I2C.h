/*
 * I2C.h
 *
 *  Created on: 2014-2-14
 *      Author: liming
 */

#ifndef I2C_H_
#define I2C_H_

/*
 * ls1d_IIC_master_init
 * 将iic控制器设置成master模式，总线时钟频率为clk，
 */
void ls1d_IIC_master_init(_u32 clk);

/*
 * ls1d_IIC_slave_init
 * 将iic控制器设置成slave模式，从设备地址为slave_addr，
 */
void ls1d_IIC_slave_init(_u8 slave_addr);

/*
 * ls1d_IIC_write_addr
 * iic master设备向总线上写设备地址addr，以及读写指令cmd，
 */
void ls1d_IIC_write_addr(_u8 addr, _u8 cmd);

/*
 * ls1d_IIC_write_data
 * iic master设备向总线上写一个字节数据data，
 */
void ls1d_IIC_write_data(_u8 data);

/*
 * ls1d_IIC_write_data_stop
 * iic master设备向总线上写一个字节数据data，并发送结束信号，
 */
void ls1d_IIC_write_data_stop(_u8 data);

/*
 * ls1d_IIC_read
 * iic master设备从总线上读一个字节数据，
 * 操作成功，则返回data。
 */
_u8 ls1d_IIC_read();

/*
 * ls1d_IIC_read_stop
 * iic master设备向总线上读一个字节数据，并发送结束信号，
 * 操作成功，则返回data。
 */
_u8 ls1d_IIC_read_stop();

#endif /* I2C_H_ */
