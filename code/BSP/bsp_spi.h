#ifndef _BSP_SPI_H_
#define _BSP_SPI_H_

/*****************************
 * 软件模拟SPI通讯
 * 用于OLED12864 SPI-7pin
 * 适用16路舵机驱动板V1
 * 主控:stm32f103vet6
 *  2021/6/1    庞碧璋
*****************************/

#include "stm32f10x.h"

#define SPI_SCL_SET()     GPIO_SetBits(GPIOE,GPIO_Pin_6)
#define SPI_SCL_RESET()   GPIO_ResetBits(GPIOE,GPIO_Pin_6)
#define SPI_SDA_SET()     GPIO_SetBits(GPIOE,GPIO_Pin_5)
#define SPI_SDA_RESET()   GPIO_ResetBits(GPIOE,GPIO_Pin_5)   
#define SPI_RST_SET()     GPIO_SetBits(GPIOE,GPIO_Pin_4)
#define SPI_RST_RESET()   GPIO_ResetBits(GPIOE,GPIO_Pin_4)
#define SPI_CS_SET()      GPIO_SetBits(GPIOE,GPIO_Pin_2)
#define SPI_CS_RESET()    GPIO_ResetBits(GPIOE,GPIO_Pin_2)
#define SPI_DC_SET()      GPIO_SetBits(GPIOE,GPIO_Pin_3)
#define SPI_DC_RESET()    GPIO_ResetBits(GPIOE,GPIO_Pin_3)

void OLED_SPI_Init(void);
void OLED_SPI_Send(uint8_t dat,uint8_t cmd);

#endif

