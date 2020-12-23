/*
 * @Description: 
 * @Version: 0.0
 * @Autor: kying-Star
 * @Date: 2020-12-20 21:26:18
 * @LastEditors: kyingstar
 * @LastEditTime: 2020-12-20 21:44:57
 */
#include "Red.h"
sbit IRIN = P3 ^ 2;
uint getNumValue(uchar Ir)
{
  uchar hongwai = ' ';
  switch (Ir)
  {
  case 0x16:
    hongwai = 0;
    break;
  case 0x0c:
    hongwai = 1;
    break;
  case 0x18:
    hongwai = 2;
    break;
  case 0x5e:
    hongwai = 3;
    break;
  case 0x08:
    hongwai = 4;
    break;
  case 0x1c:
    hongwai = 5;
    break;
  case 0x5a:
    hongwai = 6;
    break;
  case 0x42:
    hongwai = 7;
    break;
  case 0x52:
    hongwai = 8;
    break;
  case 0x4a:
    hongwai = 9;
    break;
  }
  return hongwai;
}

void delay(uint i)
{
  while (i--)
    ;
}

void IrInit()
{
  IT0 = 1;
  EX0 = 1;
  EA = 1;

  IRIN = 1;
}