# 2021年机械创新大赛仿生机器人

核心板的代码&原理图&pcb生产文件

[TOC]

# PCB

## 第一板pcb

1. type-c接口没有接地
2. 稳压芯片的电解电容封装错误
3. 稳压芯片的电解电容表示反了
4. xm1.25系类接口电源标识错误
5. logo太小不清晰
6. DC12V电源输入封装错误
7. 定位孔位置被元器件阻挡
8. 可适当缩小pcb尺寸

**2021/5/19 12:04 **

# Code

## BSP

### 1.pwm输出

​	**TIM3 4 5 8所有通道输出50Hz1000us脉宽测试通过**

​	**2021/5/24**

### 2.LED控制

​	**LED除LED3以外,其余都可以通过LED_CTR()控制，LED3上电常亮，可能是pcb或者单片机方面的问题**

​	**2021/5/24**

### 3.串口

​	**串口1重定向没问题，中断接收没问题。使用printf()中若包涵汉字会报警告**

​	**2021/5/25**

​	**串口DMA发送过一次后无法再次发送，printf()中包含汉字会出现乱码。DMA发送完成能进入中断，可能是Usart_send()或者Usart_Tx_Clear()函数出现问题。**

​	**2021/5/27**

​	**串口DMA发送的bug已经解决，汉字如果是使用utf-8的编码集的话就会出现乱码的情况，通过txt打开文件，内存为的时候将编码集改成ANCI就不会出现乱码的情况。Vofa+上位机不知道什么原因，无法获取串口的信息，都是Vofa+能检测到串口有信号。**

​	——已经查清楚了，是vofa+本身的优化导致字符的显示比较慢(大概)，波形图的控制完全OK。使用utf-8只会导致正点原子的串口助手汉字乱码，vofa+支持utf-8的字符编码。

​	**2021/5/28**

### 4.按键

​	**代码书写完成，等待调试**

​	**2021/5/31**

## DRIVER

### 1.舵机驱动

```c
#ifndef _STREET_MOTOR_DRIVER_H_
#define _STREET_MOTOR_DRIVER_H_

/*********************************************************
 * PWM输出接口 PWM_Out_Port(Channel,Width)
 * Channel: 通道标号        unsigned char
 * Width:   脉宽(单位us)    unsigned short int
 * 无返回值
 * 接口要求:能在规定通道输出50Hz的PWM波,脉宽参数Width
 *      2021/5/28   庞碧璋
*********************************************************/

#define STREET_MOTOR_NUM    16
#define PWM_Out_Port(Channel,Width)     PWM_Out(Channel,Width)

extern void PWM_Out_Port(unsigned char Channel,unsigned short int Width);

void StreetMotor_CTR(unsigned char num,double angle);
unsigned int AngleToWidth(double angle);

#endif
```

​	**2021/5/30**

## LIB

### 1.vofa+上位机

​	**通道0输出恒定值测试通过**

​	**2021/5/30**

​	