#ifndef _PID_LIB_H_
#define _PID_LIB_H_

/**************************
 * IncPID算法封装库
 * 2021/5 作者:庞碧璋
**************************/

typedef struct
{
    int that_Err;
    int last_Err1;
    int last_Err2;
    int Target;
    int Output;
    int MAX;
    int MIN;
    double Kp;
    double Ki;
    double Kd;
}PID_Struct;

void IncPID_Realize(PID_Struct*ptr,int curr);    //curr->当前值
void PositionPID_Realize(PID_Struct*ptr,int curr);
void PID_Struct_Reset(PID_Struct*ptr);          //pid结构体初始化

#endif
