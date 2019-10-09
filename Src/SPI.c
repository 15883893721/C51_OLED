#include "SPI.h"

/*********************OLEDд����************************************/ 
void OLED_WrDat_SPI(unsigned char dat)
{
	unsigned char i;
	OLED_DC=1;
	for(i=0;i<8;i++) //����һ����λ���� 
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

	/*********************OLEDд����************************************/										
void OLED_WrCmd_SPI (unsigned char cmd)
{
	unsigned char i;
	OLED_DC=0;
	for(i=0;i<8;i++) //����һ����λ����
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

		