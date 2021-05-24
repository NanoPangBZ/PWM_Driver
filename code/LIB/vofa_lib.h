#ifndef _VOFA_LIB_H_
#define _VOFA_LIB_H_

/*************************
 * vofa+上位机调试接口
 *     2021/5/14 庞碧璋
*************************/

#define Vofa_Channel_Num    10  //帧通道数

typedef struct
{
    float data[Vofa_Channel_Num];
    unsigned char FramEnd[4];
}Vofa_Fram;

static Vofa_Fram Vofa_Sbuffer = {{0},{0x00,0x00,0x80,0x7f}};

void Vofa_Input(float data,unsigned char Channel);

#endif
