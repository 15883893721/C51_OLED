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
* Description: 128*64(or 132*64)点整OLED模块功能演示程序的主函数，仅适用heltec.taobao.com所售产品
*
* Others: none;
*
* Function List:
*
* 1. void delay(unsigned int z) -- 主函数中用于调整显示效果的延时函数,STC89C52 12MHZ z=1时大约延时1ms,其他频率需要自己计算
* 2. void main(void) -- 主函数
*
* History: none;
*
*************************************************************************************/
#include "OLED.h"
#include "Delay.h"

void main(void) 
{

	unsigned char i;

  OLED_Init(); //OLED初始化  
	while(1)
	{

   OLED_Fill(0xff); //屏全亮
    DelayS(1);
		OLED_Fill(0x00); //屏全灭
		DelayS(1);
		if(INCH == 0)
	 {
		OLED_ShowChar(0,0,"HelTecAutomation",1);
		OLED_ShowChar(5,1,"HELLOWORLD",2);
		OLED_ShowChar(5,4,"JUST DO TI",2);
		OLED_ShowChar(34,7,"2018-08-2",1);    
		DelayS(3);
		OLED_CLS();
		for(i=0; i<8; i++)//通过点整显示汉字 -- i表示字表数组的位置
		  {
			 OLED_ShowCN(i*16,0,i);
		 	 OLED_ShowCN(i*16,2,i+8);
		  } 
		DelayS(2);
		OLED_CLS();
		OLED_DrawBMP(0,0,132,8,BMP1);
		
	}	
	 
	
		if(INCH == 1)
	{
			for(i=2; i<6; i++)
		{
      OLED_ShowCN(i*16-8,4,i-2);
			 OLED_ShowCN(i*16+8,6,i+2);
		}
			DelayS(2);
		OLED_CLS();//??
		OLED_DrawBMP(32,4,96,8,BMP3);
	}
		DelayS(2);
		OLED_CLS();//清屏
	}
	
}