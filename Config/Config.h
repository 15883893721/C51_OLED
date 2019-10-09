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
* Description: 工程配置文件,如一些全局的宏定义;
*
* Others: none;
*
* Function List: none
*
*************************************************************************************/

//系统晶振 -- 11.0592MHz
//时钟周期 -- To = 1/11.0592 (uS)
//指令周期 -- TC = 12*To = 12/11.0592 (uS)

#include "IIC.h"
#include "SPI.h"

#define    SPI_IIC_TYPE      1 //SPI_TYPE = 1 is SPI ,SPI_TYPE = 0 is IIC 
#define CHIP_IS_SSD1306         1     //1 - SSD1306; 0 -- SH1106    
#define	Brightness	0xCF  //亮度 0x00~0xff
#define X_WIDTH 		128  //SH1106 is 132,SSD1306 is 128
//#define Y_WIDTH 		64
#define INCH				0  // 0 is 0.96 inch & 0.91 inch ,1 is 0.49 inch(This Macro definition is for IIC with SSD1306)


#ifndef __CONFIG_H__
#define __CONFIG_H__


#endif
