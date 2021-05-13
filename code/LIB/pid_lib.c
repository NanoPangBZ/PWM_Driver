#include "pid_lib.h"

void IncPID_Realize(PID_Struct*ptr,int curr)
{
    double Inc;     //本次增量
    //计算当前误差
    ptr->that_Err = ptr->Target - curr;
    //计算本次增量
    Inc = (ptr->Kp)*(ptr->that_Err - ptr->last_Err1) +
          (ptr->Ki)*(ptr->that_Err) +
          (ptr->Kd)*(ptr->that_Err - 2*ptr->last_Err1 + ptr->last_Err2);
    //累加本次增量
    ptr->Output += (int)Inc;
    //Err记录
    ptr->last_Err2 = ptr->last_Err1;
    ptr->last_Err1 = ptr->that_Err;
    //范围判断
    if(ptr->Output > ptr->MAX)
        ptr->Output = ptr->MAX;
    else if(ptr->Output < ptr->MIN)
        ptr->Output = ptr->MIN;
}

void PositionPID_Realize(PID_Struct*ptr,int curr)
{
    
}

void PID_Struct_Reset(PID_Struct*ptr)
{
    ptr->Kd = 0.0;
    ptr->Ki = 0.0;
    ptr->Kp = 0.0;
    ptr->last_Err1 = 0;
    ptr->last_Err2 = 0;
    ptr->MAX = 10000;
    ptr->MIN = -10000;
    ptr->Output = 0;
    ptr->Target = 0;
    ptr->that_Err = 0;
}
