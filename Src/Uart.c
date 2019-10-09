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
* 2014-7-30 : 增加波特率选择
*
* Description: UART通信;
*
* Others: none;
*
* Function List:
*	1. void UART_Init(void);  串口初始化
* 2. void UART_SentChar(unsigned char chr);  发送一个字符
* 3. unsigned char UART_RecChar(void);  查询方式接收一个字符
* 4. void UART_SendString(unsigned char *str);  发送字符串
*
*************************************************************************************/
#include "Uart.h"

void UART_Init()
{
	
    TMOD |= 0x20;       //T1工作于方式2

	// 配置 SCON
#if (PARITYBIT == NONE_PARITY)
	SCON = 0x50;            //8-bit variable UART
#elif (PARITYBIT == ODD_PARITY) || (PARITYBIT == EVEN_PARITY) || (PARITYBIT == MARK_PARITY)
	SCON = 0xda;            //9-bit variable UART, parity bit initial to 1
#elif (PARITYBIT == SPACE_PARITY)
	SCON = 0xd2;            //9-bit variable UART, parity bit initial to 0
#endif

	// 根据系统晶振及波特率设置T1自动重装初始值
	TH1 = TL1 = -(FOSC/12/32/BAUD); //Set auto-reload vaule

	TR1 = 1;	       //启动定时器1
//	ES = 1;
	/*
	switch(baud)
	{
		case 2400:  //板上默认12M晶振,12M晶振才能使用2400的波特率
		{
			TMOD |= 0x20;       //T1工作于方式2
			PCON |= 0x00;       //SMOD = 0
			SCON |= 0x50;	      //串口方式1 8个数据位
			TH1=0xf3;TL1=0xf3;  //2400比特率
			TR1 = 1;	          //启动定时器1
			ES=1;               //开串口中断
		}
		case 9600: //11.0592M的晶振才有效
		{
			TMOD |= 0x20;       //T1工作于方式2
			PCON |= 0x00;       //SMOD = 0
			SCON |= 0x50;	      //串口方式1 8个数据位
			TH1=0xfd;TL1=0xfd; //9600比特率
			TR1 = 1;	          //启动定时器1
			ES=1;              //开串口中断
		}
	}
	*/
}

/*发送一个字符*/
void UART_SentChar(unsigned char chr)
{
	SBUF = chr;
	while(!TI);
		TI = 0;
}

/*查询方式 -- 接收一个字符*/
unsigned char UART_RecChar(void)
{
	unsigned char data recive;

	while(!RI);
		RI = 0;
	recive = SBUF;

	return(recive);
}

/*发送字符串*/
void UART_SendString(unsigned char *str)
{
	while(str && *str) //检测str是否有效
	{
		UART_SentChar(*str++); //发送数据
	}
}
