#include "bsp_key.h"

void Key_Init(void)
{
    GPIO_InitTypeDef    GPIO_InitStruct;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;

    for(uint8_t temp=0;temp<4;temp++)
    {
        GPIO_InitStruct.GPIO_Pin = KEY_Pin[temp];
        GPIO_Init(KEY_GPIO[temp],&GPIO_InitStruct);
        KEY_GPIO[temp]->ODR &= ~KEY_Pin[temp];
    }
}

uint8_t Read_Key(uint8_t Channel)
{
    if(Channel < KEY_NUM-1)
    {
        if(KEY_GPIO[Channel]->IDR &= KEY_Pin[Channel])
            return 1;
        else
            return 0;
    }
    return 0;
}
