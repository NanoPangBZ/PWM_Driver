#ifndef _OLED12864_DRIVER_H_
#define _OLED12864_DRIVER_H_

#define OLED_SPI_Port()
#define OLED_IIC_Port()

//显存
static unsigned char OLED_Sbuffer[128][64];
static unsigned char OLED_Cmd[5];

void OLED12864_Init(void);
void OLED12864_Refresh(void);

#endif  //_OLED12864_DRIVER_H_

