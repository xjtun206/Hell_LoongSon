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
 * ����addr��ַ�������˵�ַ��֮���num��flashҳ��ҳ��СΪFLASH_PAGE_SIZE��
 * ��������ɹ����򷵻�0��
 * 		����ʧ�ܣ��򷵻ط������������ҳ�ţ�1~num+1����
 */
_u32 Flash_Erase(_u32 addr, _u32 num);

/*
 * Flash_Write
 * ��дaddr��ַ�������˵�ַ��֮���num���֣��ִ�СΪ4�ֽڣ�֧�ֿ�ҳд�Ͷ�ҳд��
 * ����������в���������д����֮�����У�顣
 * �����д�ɹ����򷵻�0��
 * 		����ʧ�ܣ��򷵻�1;
 * 		У��ʧ�ܣ��򷵻ط���У�������ֵ���ţ�1~num+1����
 */
_u32 Flash_Write(_u32 addr, _u32 *data, _u32 num);



#endif /* ISP_H_ */
