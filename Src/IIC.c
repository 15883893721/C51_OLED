#include "IIC.h"

void IIC_Start(void)
{
   SCL = 1;		
   SDA = 1;
   SDA = 0;
   SCL = 0;
}

/**********************************************
//IIC Stop
**********************************************/
  void IIC_Stop(void)
{
   SCL = 0;
   SDA = 0;
   SCL = 1;
   SDA = 1;
}
/**********************************************
// IIC Write byte
**********************************************/
  void Write_IIC_Byte(unsigned char IIC_Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		if(IIC_Byte & 0x80)
			SDA= 1;
		else
			SDA = 0;
		SCL = 1;//i2c  is collecting dat or cmd.
		SCL = 0;//ready for next statements the "for()".
		IIC_Byte<<=1;
	}
		
	SDA = 1;
 SCL = 1;
		SCL = 0;

}

/*********************OLEDÐ´Êý¾Ý************************************/ 
  void OLED_WrDat_IIC(unsigned char dat)
{
  IIC_Start();
	Write_IIC_Byte(0x78);
	Write_IIC_Byte(0x40);			//write data
	Write_IIC_Byte(dat);
	IIC_Stop();

}
/*********************OLEDÐ´ÃüÁî************************************/										
  void OLED_WrCmd_IIC(unsigned char cmd)
{
  IIC_Start();
	Write_IIC_Byte(0x78);            //Slave address,SA0=0
	Write_IIC_Byte(0x00);			       //write command
	Write_IIC_Byte(cmd);
	IIC_Stop();

}
