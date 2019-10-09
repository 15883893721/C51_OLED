#include "EEPRom.h"
#include "Delay.h"

sfr ISP_DATA  = 0xe2;
sfr ISP_ADDRH = 0xe3;
sfr ISP_ADDRL = 0xe4;
sfr ISP_CMD   = 0xe5;
sfr ISP_TRIG  = 0xe6;
sfr ISP_CONTR = 0xe7;

#define EEPROM_START_ADDRESS 0x2000

void EEPROMEnable(void)
{
	ISP_CONTR |= 0x81;//使能并设置好等待时间
}

void EEPROMDisable(void)
{
	ISP_CONTR =0x00; //禁止EEPROM
	ISP_CMD   =0x00; //无ISP操作
	ISP_TRIG  =0x00; //清零
	ISP_ADDRH =0x00; //清零
	ISP_ADDRL =0x00; //清零
}

void EEPROMSetAddress(unsigned int addr)
{
	addr+=EEPROM_START_ADDRESS; //初始化地址为0x2000
	ISP_ADDRH=(unsigned char)(addr>>8); //设置读写地址高字节
	ISP_ADDRL=(unsigned char) addr; //设置读写地址低字节
}

void EEPROMStart(void)
{
	ISP_TRIG=0x46;
	ISP_TRIG=0xB9;
}

unsigned char EEPROMReadByte(unsigned int addr)
{
	ISP_DATA=0x00; //清空ISP_DATA
	ISP_CMD=0x01; //读模式
	EEPROMEnable(); //EEPROM 使能
	EEPROMSetAddress(addr); //设置EEPROM地址
	EEPROMStart(); //EEPROM 启动
	DelayUs(10); //读取一个字节要10us
	EEPROMDisable(); //禁止EEPROM
	return (ISP_DATA); //返回读到的数据
}

void EEPROMWriteByte(unsigned int addr,unsigned char byte)//向EEPROM中写入一个Byte的数据!!!在某个扇区写入数据之前必须先擦除该扇区
{
	EEPROMEnable();
	ISP_CMD=0x02;
	EEPROMSetAddress(addr);
	ISP_DATA=byte;
	EEPROMStart();
	DelayUs(60);
	EEPROMDisable();
}

void EEPROMSectorErase(unsigned int addr)//扇区擦除
{
	ISP_CMD=0x03;
	EEPROMEnable();
	EEPROMSetAddress(addr);
	EEPROMStart();
	DelayMs(10);
	EEPROMDisable();
}
