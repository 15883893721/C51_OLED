/************************************************************************************
*  Copyright (c), 2013, HelTec Automatic Technology co.,LTD.
*            All rights reserved.
*
* Http:    www.heltec.cn
* Email:   support@heltec.cn
* WebShop: heltec.taobao.com
*
* Processor: STC89C52
* Compiler : Keil C51 Compiler
* 
* Author : Heltec Automation
*
* Others: none;
*
* Function List:
*	1. void DelayUs(unsigned int time);  ??uS
* 2. void DelayMs(unsigned int time);  ??mS
* 3. void DelayS( unsigned int time);  ??S
*
*************************************************************************************/

#include "Delay.h"


void DelayMs(unsigned int time)
{
  unsigned int i,j;
  for(i=0;i<time;i++)
    for(j=0;j<111;j++);
}

void DelayS(unsigned int time)
{
	unsigned int i;
	for(i=0;i<time;i++)
		DelayMs(1021);
}