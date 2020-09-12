#include "REG52.h"
sbit LED = P0 ^ 0;
void main()
{
    while (1)
    {
        LED = 1;
    }
}
