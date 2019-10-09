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
* Description: ��ʱ/������timer0��������;
*
* Others: none;
*
* Function List:
*	1. void Timer0_Init(unsigned char Mode, unsigned int Num);  ��ʱ��0��ʼ��,�����趨��ʱ��ģʽ�ͼ����Ĵ���
*
*************************************************************************************/
#include "Timer.h"

/*****************************************************************
* 
* Mode = 0,Num = 0~8191  -> ��ʽ0 -- �������ֵ8192,�ж�֮����Ҫ��װ��ֵ��
* Mode = 1,Num = 0~65534 -> ��ʽ1 -- �������ֵ65535,�ж�֮����Ҫ��װ��ֵ��
* Mode = 2,Num = 0~255   -> ��ʽ2 -- �������ֵ256,�ж�֮��������װ��ֵ��
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
