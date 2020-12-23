

#include "reg51.h"
#include "lcd.h"
#include "Red.h"
typedef unsigned int u16;
typedef unsigned char u8;

sbit LSA = P2 ^ 2;
sbit LSB = P2 ^ 3;
sbit LSC = P2 ^ 4;

sbit IRIN = P3 ^ 2;
unsigned char code CDIS1[13] = {"The IR-key is"};
unsigned char code blank[16] = {"                "};
u8 IrValue[6];
u8 Time;
u8 DisplayData[8];
u8 pos;
/**
 * @description: 获取红外值对应的数字
 * @param {*} 
 * @return {*}
 * @author: 林其星
 */

void main()
{
    unsigned char i;
    unsigned char hongwai = ' ';
    LcdInit();
    IrInit();
    pos = -1;
    while (1)
    {
        LcdWriteCom(0x80);
        for (i = 0; i < 13; i++)
        {
            LcdWriteData(CDIS1[i]);
        }

        if (pos == 16)
        {
            pos = 0;
            LcdWriteCom(0xc0);
            for (i = 0; i < 16; i++)
            {
                LcdWriteData(blank[i]);
            }
        }
        hongwai = getNumValue(IrValue[2]);
        LcdWriteCom(0xc0 + pos);
        if (hongwai == ' ')
        {
            LcdWriteData(hongwai);
        }
        else
        {
            LcdWriteData(hongwai + 0x30);
        }
    }
}

/**
 * @description: 
 * @param {*}
 * @return {*}
 * @author: 林其星
 */

void ReadIr() interrupt 0
{
    u8 j, k;
    u16 err;
    Time = 0;
    delay(700);
    if (IRIN == 0)
    {

        err = 1000;
        while ((IRIN == 0) && (err > 0))
        {
            delay(1);
            err--;
        }
        if (IRIN == 1)
        {
            err = 500;
            while ((IRIN == 1) && (err > 0))
            {
                delay(1);
                err--;
            }
            for (k = 0; k < 4; k++)
            {
                for (j = 0; j < 8; j++)
                {

                    err = 60;
                    while ((IRIN == 0) && (err > 0))
                    {
                        delay(1);
                        err--;
                    }
                    err = 500;
                    while ((IRIN == 1) && (err > 0))
                    {
                        delay(10); //0.1ms
                        Time++;
                        err--;
                        if (Time > 30)
                        {
                            return;
                        }
                    }
                    IrValue[k] >>= 1;
                    if (Time >= 8)
                    {
                        IrValue[k] |= 0x80;
                    }
                    Time = 0;
                }
            }
        }
        if (IrValue[2] == ~IrValue[3])
        {
            pos++;
        }
        if (IrValue[2] != ~IrValue[3])
        {
            return;
        }
    }
}
