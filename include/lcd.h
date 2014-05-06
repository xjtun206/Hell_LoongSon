/*
 * lcd.h
 *
 *  Created on: 2013-1-10
 *      Author: liming
 */

#ifndef LCD_H_
#define LCD_H_

/*
 * ls1d_lcd_poweron
 * ��lcd��Դ
 *
 * ls1d_lcd_powerdown
 * �ر�lcd��Դ
 */
void ls1d_lcd_poweron();
void ls1d_lcd_powerdown();

/*
 * LcdClear
 * ��lcd�����Ļ�������0��
 */
void LcdClear(_u8 *buf);

/*
 * LcdPrintAll
 * ��lcd�����Ļ�����дȫ��1����
 */
void LcdPrintAll(_u8 *buf);

/*
 * WriteLcdRegs
 * ��lcd�����Ļ������ڵ�����д��lcd����������ʾbuffer��
 */
void WriteLcdRegs(_u8 *buf);

/*
 * Lcd_HW_Init
 * ��ʼ��lcd��������
 */
void Lcd_HW_Init();


#endif /* LCD_H_ */
