#ifndef __OLED_H__
#define __OLED_H__



#include "codetab.h"
#include "Config.h"
static void OLED_WrCmd(unsigned char cmd);
static void OLED_WrDat(unsigned char dat);
void OLED_SetPos(unsigned char x, unsigned char y);
void OLED_Fill(unsigned char bmp_dat);
void OLED_CLS(void);
void OLED_ON(void);
void OLED_OFF(void);
void OLED_Init(void);
//void OLED_DrawPoint(unsigned char x,unsigned char y,unsigned char t);
//void OLED_Char(unsigned char x, unsigned char y, unsigned char ch);
void OLED_ShowChar(unsigned char x, unsigned char y, unsigned char ch[], unsigned char TextSize);
void OLED_ShowCN(unsigned char x, unsigned char y, unsigned char N);
void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[]);

#endif

