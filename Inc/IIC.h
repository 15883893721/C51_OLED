#ifndef _IIC_H_
#define _IIC_H_

void IIC_Start(void);
void IIC_Stop(void);
void Write_IIC_Byte(unsigned char IIC_Byte);
void OLED_WrDat_IIC(unsigned char dat);
void OLED_WrCmd_IIC(unsigned char cmd);
#endif

#include "reg52.h"

	sbit SCL=P1^3;     //SCL
  sbit SDA=P1^2;     //SDA
	sbit CS=P1^1; //CS
