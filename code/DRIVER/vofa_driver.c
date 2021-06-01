#include "vofa_driver.h"
#include <stdio.h>

void Vofa_Send(void)
{
    while(
        Vofa_Send_Port((unsigned char*)&Vofa_Sbuffer,sizeof(Vofa_Fram))
    );
}

void Vofa_Input(float data,unsigned char Channel)
{
    if(Channel < Vofa_Channel_Num)
        Vofa_Sbuffer.data[Channel] = data;
}

unsigned char*Vofa_Return(void)
{
    return (unsigned char*)&Vofa_Sbuffer;
}
