#include "test_app.h"
#include <stdio.h>

void Key_test(void)
{
    if(Read_Key(0))
        printf("Key_Input\r\n");
    delay_us(5000);
}

void delay_us(uint16_t us)
{
    uint16_t num = 0;
    uint16_t t = 0;
    for(num=0;num<us;num++)
    {
        t = 11;
        while(t!=0)
            t--;
    }
}
