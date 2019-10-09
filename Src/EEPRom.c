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
	ISP_CONTR |= 0x81;//ʹ�ܲ����úõȴ�ʱ��
}

void EEPROMDisable(void)
{
	ISP_CONTR =0x00; //��ֹEEPROM
	ISP_CMD   =0x00; //��ISP����
	ISP_TRIG  =0x00; //����
	ISP_ADDRH =0x00; //����
	ISP_ADDRL =0x00; //����
}

void EEPROMSetAddress(unsigned int addr)
{
	addr+=EEPROM_START_ADDRESS; //��ʼ����ַΪ0x2000
	ISP_ADDRH=(unsigned char)(addr>>8); //���ö�д��ַ���ֽ�
	ISP_ADDRL=(unsigned char) addr; //���ö�д��ַ���ֽ�
}

void EEPROMStart(void)
{
	ISP_TRIG=0x46;
	ISP_TRIG=0xB9;
}

unsigned char EEPROMReadByte(unsigned int addr)
{
	ISP_DATA=0x00; //���ISP_DATA
	ISP_CMD=0x01; //��ģʽ
	EEPROMEnable(); //EEPROM ʹ��
	EEPROMSetAddress(addr); //����EEPROM��ַ
	EEPROMStart(); //EEPROM ����
	DelayUs(10); //��ȡһ���ֽ�Ҫ10us
	EEPROMDisable(); //��ֹEEPROM
	return (ISP_DATA); //���ض���������
}

void EEPROMWriteByte(unsigned int addr,unsigned char byte)//��EEPROM��д��һ��Byte������!!!��ĳ������д������֮ǰ�����Ȳ���������
{
	EEPROMEnable();
	ISP_CMD=0x02;
	EEPROMSetAddress(addr);
	ISP_DATA=byte;
	EEPROMStart();
	DelayUs(60);
	EEPROMDisable();
}

void EEPROMSectorErase(unsigned int addr)//��������
{
	ISP_CMD=0x03;
	EEPROMEnable();
	EEPROMSetAddress(addr);
	EEPROMStart();
	DelayMs(10);
	EEPROMDisable();
}
