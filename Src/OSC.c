/************************************************************************************
*  Copyright (c), 2015, HelTec Automation Technology co.,LTD.
*            All rights reserved.
*
* File name: OSC.c
* Project  : HelTec
* Processor: STC89C52
* Compiler : Keil C51 V9.52.0.0
* 
* Author : Aaron.Lee
* Version: 1.00
* Date   : 2014.3.24
* Email  : leehunter8801@gmail.com
* Modification: none
*
* Description: 超声波模块驱动程序;
*
* Others: none;
*
* Function List:
* 1. void OSC_Triger(void);//定时器0中断服务函数
* 2. void Count(void);//串口中断服务函数
*	3. float Distance(void);//主函数
*
*************************************************************************************/

#include "OSC.h"
#include "Delay.h"

sbit TRIG = P1^4; //正式工程时应该写到Config.h中
sbit ECHO = P1^5;

/*触发一次*/
void OSC_Triger(void)
{
	TRIG = 1;//给一个高电平，触发模块发出超声波信号
	DelayMs(800);
	TRIG = 0;
}

/********************************************
* 超声波模块发出信号时 -- 开始计数；
* 声波碰到物体返回模块时 -- 停止计数;
* 12MHz晶振，计数器每增加一次为1us.
********************************************/
void Count(void)
{
	while(!ECHO);//等待ECHO输出高电平
	TR0 = 1;//开始计数高电平的持续时间
	while(ECHO);//等待ECHO输出低电平，说明超声波信号碰到物体并已经返回
	TR0 = 0;//计数器工作结束
}

/*计算距离*/
float Distance(void)
{
	unsigned int time;
	float S;
	
	TH0 = 0;
	TL0 = 0;//要的是计数,不是产生中断然后溢出,所以这里要给0
	
	OSC_Triger();
	Count();
	
	time = TH0*256 + TL0;//time的最大值为18000，最远测3.1米
	S = (time*1.7l)/100;

	return(S);//float型数据,单位为cm
}
