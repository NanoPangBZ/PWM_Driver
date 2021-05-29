#include <stdio.h>
#include "bsp_usart.h"

void Usart_Init(void)
{
    Usart_GPIO_Config();
    Usart_Config();
    Usart_NVIC_Config();
    Usart_DMA_Config();
    Usart_Enable();
}

void Usart_Config(void)
{
    USART_InitTypeDef   USART_InitStruct;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB1Periph_UART5,ENABLE);

    USART_InitStruct.USART_BaudRate = 115200 ;
    USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_InitStruct.USART_Parity = USART_Parity_No;
    USART_InitStruct.USART_StopBits = USART_StopBits_1;
    USART_InitStruct.USART_WordLength = USART_WordLength_8b;

    for(uint8_t temp=0;temp<5;temp++)
    {
        USART_Init(Target_Usart[temp],&USART_InitStruct);
        USART_ClearFlag(Target_Usart[temp],USART_FLAG_RXNE);
    }
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

void Usart_DMA_Config(void)
{
    DMA_InitTypeDef DMA_InitStruct;
    NVIC_InitTypeDef    NVIC_InitStruct;

    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2,ENABLE);

    DMA_InitStruct.DMA_BufferSize = 0;
    DMA_InitStruct.DMA_DIR = DMA_DIR_PeripheralDST;
    DMA_InitStruct.DMA_M2M = DMA_M2M_Disable;
    DMA_InitStruct.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_InitStruct.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStruct.DMA_Mode = DMA_Mode_Normal;
    DMA_InitStruct.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStruct.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStruct.DMA_Priority = DMA_Priority_Medium;

    DMA_InitStruct.DMA_PeripheralBaseAddr = (uint32_t)&USART1->DR;
    DMA_InitStruct.DMA_MemoryBaseAddr = (uint32_t)(&Usart_TX_Sbuffer[0][1]);
    DMA_Init(DMA1_Channel4,&DMA_InitStruct);

    DMA_ITConfig(DMA1_Channel4,DMA_IT_TC,ENABLE);

    NVIC_InitStruct.NVIC_IRQChannel = DMA1_Channel4_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 10;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;

    NVIC_Init(&NVIC_InitStruct);

    DMA_ClearFlag(DMA1_FLAG_TC4);

    USART_DMACmd(USART1,USART_DMAReq_Tx,ENABLE);

    Usart_TX_Sbuffer[0][0] = 0;
}

void Usart_Enable(void)
{
    for(uint8_t temp=0;temp<5;temp++)
        USART_Cmd(Target_Usart[temp],ENABLE);
}

uint8_t Usart_Send(uint8_t USARTx,uint8_t*dat,uint8_t len)
{
    if(Usart_TX_Sbuffer[USARTx-1][0] == 0 && len<USART_TX_SBUFFER_SIZE-1)
    {
        uint8_t temp;
        Usart_TX_Sbuffer[USARTx-1][0] = len;
        for(temp=0;temp<len;temp++)
            Usart_TX_Sbuffer[USARTx-1][temp+1] = *(dat+temp);
        Usart_Channel[USARTx-1]->CNDTR = len;
        Usart_Channel[USARTx-1]->CCR |= DMA_CCR1_EN;
        return 0;
    }
    return 1;
}

void Usart_Tx_Clear(uint8_t USARTx)
{
    Usart_TX_Sbuffer[USARTx-1][0] = 0;
}

void Usart_Rx_Input(uint8_t USARTx,uint8_t dat)
{
    //判断缓存区是否满载
    if(Usart_RX_Sbuffer[USARTx-1][0] < USART_RX_SBUFFER_SIZE-1)
    {
        Usart_RX_Sbuffer[USARTx-1][Usart_RX_Sbuffer[USARTx-1][0] + 1] = dat;
        Usart_RX_Sbuffer[USARTx-1][0]++;
        return;
    }
    Usart_RX_Sbuffer[USARTx-1][0] = USART_RX_SBUFFER_SIZE;
}

uint8_t*Read_Usart_Sbuffer(uint8_t USARTx)
{
    return Usart_RX_Sbuffer[USARTx-1];
}

int fputc (int c, FILE *fp)
{
	USART_SendData(USART1,c);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE) == RESET);
	return c;
}

/*************中断****************/

void USART1_IRQHandler(void)
{
    if(USART_GetITStatus(USART1,USART_IT_RXNE) == SET)
    {
        Usart_Rx_Input(1,(uint8_t)USART_ReceiveData(USART1));
        USART_ClearITPendingBit(USART1,USART_IT_RXNE);
    }
}

void USART2_IRQHandler(void)
{
    if(USART_GetITStatus(USART2,USART_IT_RXNE) == SET)
    {
        Usart_Rx_Input(2,(uint8_t)USART_ReceiveData(USART2));
        USART_ClearITPendingBit(USART2,USART_IT_RXNE);
    }
}

void USART3_IRQHandler(void)
{
    if(USART_GetITStatus(USART3,USART_IT_RXNE) == SET)
    {
        Usart_Rx_Input(3,(uint8_t)USART_ReceiveData(USART3));
        USART_ClearITPendingBit(USART3,USART_IT_RXNE);
    }
}

void UART4_IRQHandler(void)
{
    if(USART_GetITStatus(UART4,USART_IT_RXNE) == SET)
    {
        Usart_Rx_Input(4,(uint8_t)USART_ReceiveData(UART4));
        USART_ClearITPendingBit(UART4,USART_IT_RXNE);
    }
}

void UART5_IRQHandler(void)
{
    if(USART_GetITStatus(UART5,USART_IT_RXNE) == SET)
    {
        Usart_Rx_Input(5,(uint8_t)USART_ReceiveData(UART5));
        USART_ClearITPendingBit(UART5,USART_IT_RXNE);
    }
}

void DMA1_Channel4_IRQHandler(void)
{
    if(DMA_GetITStatus(DMA1_IT_TC4) == SET)
    {
        Usart_Tx_Clear(1);
        Usart_Channel[0]->CCR &= (uint16_t)(~DMA_CCR1_EN);
        DMA_ClearITPendingBit(DMA1_IT_TC4);
    }
}
