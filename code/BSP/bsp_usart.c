#include <stdio.h>
#include "bsp_usart.h"

void Usart_Init(void)
{
    Usart_GPIO_Config();
    Usart_Config();
    Usart_NVIC_Config();
}

void Usart_Config(void)
{
    USART_InitTypeDef   USART_InitStruct;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB1Periph_UART5,ENABLE);

    USART_InitStruct.USART_BaudRate = 115200;
    USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_InitStruct.USART_Parity = USART_Parity_No;
    USART_InitStruct.USART_StopBits = USART_StopBits_1;
    USART_InitStruct.USART_WordLength = USART_WordLength_8b;

    for(uint8_t temp=0;temp<5;temp++)
        USART_Init(Target_Usart[temp],&USART_InitStruct);
}

void Usart_NVIC_Config(void)
{
    NVIC_InitTypeDef    NVIC_InitStruct;

    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 12;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;

    NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
    NVIC_Init(&NVIC_InitStruct);
    NVIC_InitStruct.NVIC_IRQChannel = USART2_IRQn;
    NVIC_Init(&NVIC_InitStruct);
    NVIC_InitStruct.NVIC_IRQChannel = USART3_IRQn;
    NVIC_Init(&NVIC_InitStruct);
    NVIC_InitStruct.NVIC_IRQChannel = UART4_IRQn;
    NVIC_Init(&NVIC_InitStruct);
    NVIC_InitStruct.NVIC_IRQChannel = UART5_IRQn;
    NVIC_Init(&NVIC_InitStruct);

    for(uint8_t temp=0;temp<5;temp++)
        USART_ITConfig(Target_Usart[temp],USART_IT_RXNE,ENABLE);
}

void Usart_GPIO_Config(void)
{
    GPIO_InitTypeDef    GPIO_InitStruct;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
    GPIO_PinRemapConfig(GPIO_Remap_USART2,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

    //Usart发送引脚
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
    GPIO_Init(GPIOA,&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
    GPIO_Init(GPIOD,&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
    GPIO_Init(GPIOB,&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_12;
    GPIO_Init(GPIOC,&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    
    //Usart接收引脚
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
    GPIO_Init(GPIOA,&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_2;
    GPIO_Init(GPIOD,&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11;
    GPIO_Init(GPIOB,&GPIO_InitStruct);
    GPIO_Init(GPIOC,&GPIO_InitStruct);
}

int fputc (int c, FILE *fp)
{
	USART_SendData(USART1,c);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE) == RESET);
	return c;
}

