#ifndef _OLED12864_DRIVER_H_
#define _OLED12864_DRIVER_H_

#define OLED_SPI_Port()
#define OLED_IIC_Port()

#define SPI_Send_Port(dat,cmd)  OLED_SPI_Send(dat,cmd)
extern void SPI_Send_Port(unsigned char dat,unsigned char cmd);

//显存
static unsigned char OLED_Sbuffer[128][64];
static unsigned char OLED_Init_Cmd[28] = {0xae,0x00,0x10,0x40,0x81,
                                          0xcf,0xa1,0xc8,0xa6,0xa8,
                                          0x3f,0xd3,0x00,0xd5,0x80,
                                          0xD9,0xF1,0xDA,0x12,0xDB,
                                          0x40,0x20,0x02,0x8D,0x14,
                                          0xA4,0xA6,0xAF};

void OLED12864_Init(void);
void OLED12864_Refresh(void);

#endif  //_OLED12864_DRIVER_H_

