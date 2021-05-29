#ifndef _VOFA_LIB_H_
#define _VOFA_LIB_H_

/*************************
 * vofa+上位机调试
 *     2021/5/14 庞碧璋
*************************/

#define Vofa_Channel_Num    10       //帧通道数
#define Vofa_Send_Port(dat,len)    Usart_Send(1,dat,len)

#include "bsp_usart.h"

typedef struct
{
    float data[Vofa_Channel_Num];
    unsigned char FramEnd[4];
}Vofa_Fram;
static Vofa_Fram Vofa_Sbuffer = {{0},{0x00,0x00,0x80,0x7f}};

void Vofa_Send(void);
void Vofa_Input(float data,unsigned char Channel);
unsigned char*Vofa_Return(void);

#endif
