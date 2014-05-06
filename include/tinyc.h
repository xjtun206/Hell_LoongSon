/*
 * tinyc.h
 *
 *  Created on: 2013-11-4
 *      Author: liming
 */

#ifndef TINYC_H_
#define TINYC_H_

/*
 * memcmp
 * ���ֵ�˳��Ƚ�ǰcount���ַ�����������ֵ���������£�
 * 				�� С��0��csС��ct��
 * 				�� ����0��cs����ct��
 * 				�� ����0��cs����ct��
 */
int memcmp(const void * cs,const void * ct,int count);

/*
 * memcpy
 * ��s2�е�n���ַ�������s1�С�������s1��
 */
void *memcpy(void *s1, const void *s2, int n);

/*
 * memset
 * ��s�е�ǰcount���ַ��滻Ϊc��������s��
 */
void *memset(void * s,int c, int count);

/*
 * strcat
 * ��src������dst��β��(����)��������dst��������ֹԭdst��'\0'��src�ĵ�һ���ַ����ǡ�
 */
char *strcat(char *dst, const char *src);

/*
 * strchr
 * ����ָ���ַ���p���ַ�c��һ�γ��ֵ�λ�õ�ָ�룬���p�в�����c���򷵻�NULL��
 */
char *strchr(const char *p, int c);

/*
 * strcmp
 * ���ֵ�˳��Ƚ������ַ�������������ֵ���������£�
 * 				�� С��0��s1С��s2��
 * 				�� ����0��s1����s2�����s1��s2���Ӵ���Ҳ����0����
 * 				�� ����0��s1����s2��
 */
int strcmp(const char *s1, const char *s2);

/*
 * strcspn
 * �����ַ���p���ɲ����ַ���s���ַ����ɵĵ�һ���Ӵ��ĳ��ȣ� ������p�е�һ����s�г��� ���ַ�λ��
 */
int strcspn (const char *p, const char *s);

/*
 * strspn
 * �����ַ���p�����ַ���s���ַ����ɵĵ�һ���Ӵ��ĳ��ȣ� ������p�е�һ������s�г��� ���ַ�λ��
 */
int strspn(const char *p, const char *s);

/*
 * strlen
 * �����ַ���str�ĳ��ȣ�'\0'�������ڡ�
 */
unsigned int strlen(char *str);

/*
 * strtok
 * ��p��������tok�еķֽ���綨�ĵ��ʡ�
 * ��strtok()��һϵ�е��ý����ַ���str1�ֳ���൥�ʣ���Щ������str2�е��ַ�Ϊ�ֽ����
 */
char *strtok(char *p, const char *tok);

/*
 * printf
 * ����format˵���ĸ�ʽ�ѱ�Ԫ���б�Ԫ���ݽ���ת�����ݲ�֧�ָ������ʹ�ӡ
 */
int printbase(long v,int w,int base,int sign);
int printhex(long v,int w);
int putchar(long c);
int puts(char *s);
int printf(char *fmt,...);
extern void tgt_putchar(unsigned char c);	/* ��Ӳ������ʵ����� */

#include "mytest-tinyc.h"

#endif /* TINYC_H_ */
