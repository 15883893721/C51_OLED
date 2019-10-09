/************************************************************************************
*  Copyright (c), 2015, HelTec Automation Technology co.,LTD.
*            All rights reserved.
*
* File name: Timer.c
* Project  : HelTec
* Processor: STC89C52
* Compiler : Keil C51 V9.52.0.0
* 
* Author : Aaron.Lee
* Version: 1.00
* Date   : 2014.3.21
* Email  : leehunter8801@gmail.com
* Modification: none
*
* Description: 定时/计数器timer0操作函数;
*
* Others: none;
*
* Function List:
*	1. void Timer0_Init(unsigned char Mode, unsigned int Num);  定时器0初始化,可以设定定时器模式和计数的次数
*
*************************************************************************************/
#include "Timer.h"

/*****************************************************************
* 
* Mode = 0,Num = 0~8191  -> 方式0 -- 计数最大值8192,中断之后需要重装初值；
* Mode = 1,Num = 0~65534 -> 方式1 -- 计数最大值65535,中断之后需要重装初值；
* Mode = 2,Num = 0~255   -> 方式2 -- 计数最大值256,中断之后无需重装初值；
* 
******************************************************************/
void Timer0_Init(unsigned char Mode, unsigned int Num)
{
	switch(Mode)
	{
		case 0:
		{
			TMOD |= 0x00;
			TH0=(8192-Num)/32;
			TL0=(8192-Num)%32;
		}break;
		case 1:
		{
			TMOD |= 0x01;
			TH0=(65535-Num)/256;
			TL0=(65535-Num)%256;
		}break;
		case 2:
		{
			TMOD |= 0x02;
			TH0 = 256 - Num;
			TL0 = 256 - Num;
		}break;
	}
	TR0=1;
	ET0=1;
}
