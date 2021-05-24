#ifndef _BSP_LED_H_
#define _BSP_LED_H_

#include "stm32f10x.h"

#define LED_PART1   GPIOE
#define LED_Pin1    GPIO_Pin_0 | GPIO_Pin_1
#define LED_PART2   GPIOB
#define LED_Pin2    GPIO_Pin_5 | GPIO_Pin_4

static uint8_t LED_Pin[4] = {GPIO_Pin_1,GPIO_Pin_0,GPIO_Pin_5,GPIO_Pin_4};
static GPIO_TypeDef*LED_GPIO[4] = {GPIOE,GPIOE,GPIOB,GPIOB};

void LED_Init(void);
void LED_CTR(uint8_t LED,uint8_t NewState);

#endif
