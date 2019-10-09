#include "SPI.h"

/*********************OLED写数据************************************/ 
void OLED_WrDat_SPI(unsigned char dat)
{
	unsigned char i;
	OLED_DC=1;
	for(i=0;i<8;i++) //发送一个八位数据 
	{
		if((dat << i) & 0x80)
		{
			OLED_SDA  = 1;
		}
		else  OLED_SDA  = 0;
		OLED_SCL = 0;
		OLED_SCL = 1;
	}
}

	/*********************OLED写命令************************************/										
void OLED_WrCmd_SPI (unsigned char cmd)
{
	unsigned char i;
	OLED_DC=0;
	for(i=0;i<8;i++) //发送一个八位数据
	{
		if((cmd << i) & 0x80)
		{
			OLED_SDA  = 1;
		}
		else
		{
			OLED_SDA  = 0;
		}
		OLED_SCL = 0;
		OLED_SCL = 1;
	}
}

		