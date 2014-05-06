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
 * 按字典顺序比较前count个字符，返回整数值的意义如下：
 * 				· 小于0，cs小于ct；
 * 				· 等于0，cs等于ct；
 * 				· 大于0，cs大于ct；
 */
int memcmp(const void * cs,const void * ct,int count);

/*
 * memcpy
 * 把s2中的n个字符拷贝到s1中。并返回s1。
 */
void *memcpy(void *s1, const void *s2, int n);

/*
 * memset
 * 把s中的前count个字符替换为c，并返回s。
 */
void *memset(void * s,int c, int count);

/*
 * strcat
 * 把src拷贝到dst的尾部(连接)，并返回dst。其中终止原dst的'\0'被src的第一个字符覆盖。
 */
char *strcat(char *dst, const char *src);

/*
 * strchr
 * 返回指向字符串p中字符c第一次出现的位置的指针，如果p中不包含c，则返回NULL。
 */
char *strchr(const char *p, int c);

/*
 * strcmp
 * 按字典顺序比较两个字符串，返回整数值的意义如下：
 * 				· 小于0，s1小于s2；
 * 				· 等于0，s1等于s2（如果s1是s2的子串，也返回0）；
 * 				· 大于0，s1大于s2；
 */
int strcmp(const char *s1, const char *s2);

/*
 * strcspn
 * 返回字符串p中由不在字符串s中字符构成的第一个子串的长度， 即返回p中第一个在s中出现 的字符位置
 */
int strcspn (const char *p, const char *s);

/*
 * strspn
 * 返回字符串p中由字符串s中字符构成的第一个子串的长度， 即返回p中第一个不在s中出现 的字符位置
 */
int strspn(const char *p, const char *s);

/*
 * strlen
 * 返回字符串str的长度，'\0'不算在内。
 */
unsigned int strlen(char *str);

/*
 * strtok
 * 在p中搜索由tok中的分界符界定的单词。
 * 对strtok()的一系列调用将把字符串str1分成许多单词，这些单词以str2中的字符为分界符。
 */
char *strtok(char *p, const char *tok);

/*
 * printf
 * 按照format说明的格式把变元表中变元内容进行转换，暂不支持浮点类型打印
 */
int printbase(long v,int w,int base,int sign);
int printhex(long v,int w);
int putchar(long c);
int puts(char *s);
int printf(char *fmt,...);
extern void tgt_putchar(unsigned char c);	/* 跟硬件具体实现相关 */

#include "mytest-tinyc.h"

#endif /* TINYC_H_ */
