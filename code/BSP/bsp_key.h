#ifndef _BSP_KEY_H_
#define _BSP_KEY_H_

#include "stm32f10x.h"

/*******************************
 * 适用2021机械创新大赛pcb
 *      2021/5/31 庞碧璋
*******************************/ 

#define KEY_NUM 4

static GPIO_TypeDef*KEY_GPIO[4] = {GPIOB,GPIOD,GPIOD,GPIOD};
static uint8_t KEY_Pin[4] = {GPIO_Pin_3,GPIO_Pin_7,GPIO_Pin_4,GPIO_Pin_3};

void Key_Init(void);
uint8_t Read_Key(uint8_t Channel);

#endif

