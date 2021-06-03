#include "bsp_spi.h"

void OLED_SPI_Init(void)
{
    GPIO_InitTypeDef    GPIO_InitStruct;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_5 | GPIO_Pin_6;

    GPIO_Init(GPIOE,&GPIO_InitStruct);

    GPIO_SetBits(GPIOE , GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_5 | GPIO_Pin_6 );
}

void OLED_SPI_Send(uint8_t dat,uint8_t cmd)
{
    if(cmd)
        SPI_DC_SET();
    else
        SPI_DC_RESET();
    SPI_SCL_RESET();
    for(uint8_t temp=0;temp<8;temp++)
    {
        SPI_SCL_RESET();
        SPI_SCL_RESET();
        if(dat&0x80)
        {
            SPI_SDA_SET();
            SPI_SDA_SET();
        }
        else
        {
            SPI_SDA_RESET();
            SPI_SDA_RESET();
        }
        SPI_SCL_SET();
        SPI_SCL_SET();
        dat <<= 1;
    }
    SPI_CS_SET();
    SPI_DC_SET();
}
