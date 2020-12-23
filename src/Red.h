/*
 * @Description: 
 * @Version: 0.0
 * @Autor: kying-Star
 * @Date: 2020-12-20 21:13:16
 * @LastEditors: kyingstar
 * @LastEditTime: 2020-12-20 21:43:34
 */
#ifndef __RED_H_
#define __RED_H_

#define LCD1602_4PINS

#include <reg51.h>

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

uint getNumValue(uchar Ir);
void delay(uint i);
void IrInit();
#endif
