#include "StreetMotor_driver.h"

void StreetMotor_CTR(unsigned char num,double angle)
{
    if(num < STREET_MOTOR_NUM && angle>0 && angle<180)
        PWM_Out_Port(num,AngleToWidth(angle));
}

unsigned int AngleToWidth(double angle)
{
    unsigned int temp;
    temp = (int)(11.111*angle);
    temp += 500;
    return temp;
}


