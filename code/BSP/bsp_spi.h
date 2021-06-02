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

#define D0

void SPI_Init(void);
void SPI_Send(void);

#endif

