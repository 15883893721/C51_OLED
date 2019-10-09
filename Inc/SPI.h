#ifndef _SPI_H_
#define _SPI_H_

void OLED_WrDat_SPI(unsigned char dat);
void OLED_WrCmd_SPI(unsigned char cmd);

#endif

#include "reg52.h"
  sbit OLED_SCL=P1^3; //时钟CLK
  sbit OLED_SDA=P1^2; //MISO
  sbit OLED_CS=P1^1;  //CS
  sbit OLED_DC =P1^0; //数据/命令控制
