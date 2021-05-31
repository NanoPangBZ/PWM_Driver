#include <stdio.h>
#include "stm32f10x.h"

#include "bsp_led.h"
#include "bsp_tim.h"
#include "bsp_usart.h"
#include "bsp_key.h"

#include "StreetMotor_driver.h"

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
	PWM_Init();
	Usart_Init();

	LED_CTR(1,1);
	LED_CTR(2,0);

	while(1)
	{
		if(Read_Key(0))
			LED_CTR(2,1);
		else
			LED_CTR(2,0);
	}
}
