#include "oled12864_driver.h"

void OLED12864_Init(void)
{
    unsigned char temp;
    for(temp=0;temp<28;temp++)
        SPI_Send_Port(OLED_Init_Cmd[temp],0);
}
