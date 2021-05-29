#ifndef _STREET_MOTOR_DRIVER_H_
#define _STREET_MOTOR_DRIVER_H_

/*********************************************************
 * PWM输出接口 PWM_Out_Port(Channel,Width)
 * Channel: 通道标号        unsigned char
 * Width:   脉宽(单位us)    unsigned short int
 * 无返回值
 * 接口要求:能在规定通道输出50Hz的PWM波,脉宽参数Width
 * 注意:更改某通道脉宽时要等待上一周期结束
 *      2021/5/30   庞碧璋
*********************************************************/

#define STREET_MOTOR_NUM    16
#define PWM_Out_Port(Channel,Width)     PWM_Out(Channel,Width)

extern void PWM_Out_Port(unsigned char Channel,unsigned short int Width);

void StreetMotor_CTR(unsigned char num,double angle);
unsigned int AngleToWidth(double angle);

#endif

