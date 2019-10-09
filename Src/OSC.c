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
* Description: ������ģ����������;
*
* Others: none;
*
* Function List:
* 1. void OSC_Triger(void);//��ʱ��0�жϷ�����
* 2. void Count(void);//�����жϷ�����
*	3. float Distance(void);//������
*
*************************************************************************************/

#include "OSC.h"
#include "Delay.h"

sbit TRIG = P1^4; //��ʽ����ʱӦ��д��Config.h��
sbit ECHO = P1^5;

/*����һ��*/
void OSC_Triger(void)
{
	TRIG = 1;//��һ���ߵ�ƽ������ģ�鷢���������ź�
	DelayMs(800);
	TRIG = 0;
}

/********************************************
* ������ģ�鷢���ź�ʱ -- ��ʼ������
* �����������巵��ģ��ʱ -- ֹͣ����;
* 12MHz���񣬼�����ÿ����һ��Ϊ1us.
********************************************/
void Count(void)
{
	while(!ECHO);//�ȴ�ECHO����ߵ�ƽ
	TR0 = 1;//��ʼ�����ߵ�ƽ�ĳ���ʱ��
	while(ECHO);//�ȴ�ECHO����͵�ƽ��˵���������ź��������岢�Ѿ�����
	TR0 = 0;//��������������
}

/*�������*/
float Distance(void)
{
	unsigned int time;
	float S;
	
	TH0 = 0;
	TL0 = 0;//Ҫ���Ǽ���,���ǲ����ж�Ȼ�����,��������Ҫ��0
	
	OSC_Triger();
	Count();
	
	time = TH0*256 + TL0;//time�����ֵΪ18000����Զ��3.1��
	S = (time*1.7l)/100;

	return(S);//float������,��λΪcm
}
