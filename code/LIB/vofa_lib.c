#include "vofa_lib.h"

void Vofa_Input(float data,unsigned char Channel)
{
    if(Channel < Vofa_Channel_Num)
        Vofa_Sbuffer.data[Channel] = data;
}
