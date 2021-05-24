#include "bsp_led.h"

void LED_Init(void)
{
    GPIO_InitTypeDef    GPIO_InitStruct;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_InitStruct.GPIO_Pin = LED_Pin1;
    GPIO_Init(LED_PART1,&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = LED_Pin2;
    GPIO_Init(LED_PART2,&GPIO_InitStruct);
}

void LED_CTR(uint8_t LED,uint8_t NewState)
{
    if(NewState)
        LED_GPIO[LED]->ODR |= LED_Pin[LED];
    else
        LED_GPIO[LED]->ODR &= ~LED_Pin[LED];
}
