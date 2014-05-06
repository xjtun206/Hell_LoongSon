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
 * ��iic���������ó�masterģʽ������ʱ��Ƶ��Ϊclk��
 */
void ls1d_IIC_master_init(_u32 clk);

/*
 * ls1d_IIC_slave_init
 * ��iic���������ó�slaveģʽ�����豸��ַΪslave_addr��
 */
void ls1d_IIC_slave_init(_u8 slave_addr);

/*
 * ls1d_IIC_write_addr
 * iic master�豸��������д�豸��ַaddr���Լ���дָ��cmd��
 */
void ls1d_IIC_write_addr(_u8 addr, _u8 cmd);

/*
 * ls1d_IIC_write_data
 * iic master�豸��������дһ���ֽ�����data��
 */
void ls1d_IIC_write_data(_u8 data);

/*
 * ls1d_IIC_write_data_stop
 * iic master�豸��������дһ���ֽ�����data�������ͽ����źţ�
 */
void ls1d_IIC_write_data_stop(_u8 data);

/*
 * ls1d_IIC_read
 * iic master�豸�������϶�һ���ֽ����ݣ�
 * �����ɹ����򷵻�data��
 */
_u8 ls1d_IIC_read();

/*
 * ls1d_IIC_read_stop
 * iic master�豸�������϶�һ���ֽ����ݣ������ͽ����źţ�
 * �����ɹ����򷵻�data��
 */
_u8 ls1d_IIC_read_stop();

#endif /* I2C_H_ */
