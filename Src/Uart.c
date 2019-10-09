/************************************************************************************
*  Copyright (c), 2015, HelTec Automation Technology co.,LTD.
*            All rights reserved.
*
* File name: Uart.c
* Project  : HelTec
* Processor: STC89C52
* Compiler : Keil C51 V9.52.0.0
* 
* Author : Aaron.Lee
* Version: 1.01
* Date   : 2014.7.30
* Email  : leehunter8801@gmail.com
* Modification:
* 2014-7-30 : ���Ӳ�����ѡ��
*
* Description: UARTͨ��;
*
* Others: none;
*
* Function List:
*	1. void UART_Init(void);  ���ڳ�ʼ��
* 2. void UART_SentChar(unsigned char chr);  ����һ���ַ�
* 3. unsigned char UART_RecChar(void);  ��ѯ��ʽ����һ���ַ�
* 4. void UART_SendString(unsigned char *str);  �����ַ���
*
*************************************************************************************/
#include "Uart.h"

void UART_Init()
{
	
    TMOD |= 0x20;       //T1�����ڷ�ʽ2

	// ���� SCON
#if (PARITYBIT == NONE_PARITY)
	SCON = 0x50;            //8-bit variable UART
#elif (PARITYBIT == ODD_PARITY) || (PARITYBIT == EVEN_PARITY) || (PARITYBIT == MARK_PARITY)
	SCON = 0xda;            //9-bit variable UART, parity bit initial to 1
#elif (PARITYBIT == SPACE_PARITY)
	SCON = 0xd2;            //9-bit variable UART, parity bit initial to 0
#endif

	// ����ϵͳ���񼰲���������T1�Զ���װ��ʼֵ
	TH1 = TL1 = -(FOSC/12/32/BAUD); //Set auto-reload vaule

	TR1 = 1;	       //������ʱ��1
//	ES = 1;
	/*
	switch(baud)
	{
		case 2400:  //����Ĭ��12M����,12M�������ʹ��2400�Ĳ�����
		{
			TMOD |= 0x20;       //T1�����ڷ�ʽ2
			PCON |= 0x00;       //SMOD = 0
			SCON |= 0x50;	      //���ڷ�ʽ1 8������λ
			TH1=0xf3;TL1=0xf3;  //2400������
			TR1 = 1;	          //������ʱ��1
			ES=1;               //�������ж�
		}
		case 9600: //11.0592M�ľ������Ч
		{
			TMOD |= 0x20;       //T1�����ڷ�ʽ2
			PCON |= 0x00;       //SMOD = 0
			SCON |= 0x50;	      //���ڷ�ʽ1 8������λ
			TH1=0xfd;TL1=0xfd; //9600������
			TR1 = 1;	          //������ʱ��1
			ES=1;              //�������ж�
		}
	}
	*/
}

/*����һ���ַ�*/
void UART_SentChar(unsigned char chr)
{
	SBUF = chr;
	while(!TI);
		TI = 0;
}

/*��ѯ��ʽ -- ����һ���ַ�*/
unsigned char UART_RecChar(void)
{
	unsigned char data recive;

	while(!RI);
		RI = 0;
	recive = SBUF;

	return(recive);
}

/*�����ַ���*/
void UART_SendString(unsigned char *str)
{
	while(str && *str) //���str�Ƿ���Ч
	{
		UART_SentChar(*str++); //��������
	}
}
