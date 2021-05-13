#include "stm32f10x.h"

#include "bsp_rcc.h"
#include "bsp_tim.h"
#include "bsp_usart.h"

#include "pid_lib.h"

PID_Struct test = {0,0,0,0,0,0,0};

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	BSP_Clock_Init();
	PWM_Init();
	Usart_Init();
	IncPID_Realize(&test,1);
	while(1);
}
