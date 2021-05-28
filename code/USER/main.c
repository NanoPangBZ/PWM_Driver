#include <stdio.h>
#include "stm32f10x.h"

#include "bsp_led.h"
#include "bsp_tim.h"
#include "bsp_usart.h"
#include "vofa_lib.h"

void delay_us(uint16_t us)
{
    uint16_t num = 0;
    uint16_t t = 0;
    for(num=0;num<us;num++)
    {
        t = 11;
        while(t!=0)
            t--;
    }
}

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

	LED_Init();
	Usart_Init();

	LED_CTR(2,1);

	Vofa_Input(12.0,0);

	while(1)
	{
		Usart_Sned(1,Vofa_Return(),sizeof(Vofa_Fram));
		delay_us(1000);
		delay_us(1000);
		delay_us(1000);
		delay_us(1000);
		delay_us(1000);
	}
}
