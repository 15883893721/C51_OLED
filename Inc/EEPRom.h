#include "reg52.h"

void EEPROMEnable(void);
void EEPROMDisable(void);
void EEPROMSetAddress(unsigned int addr);
void EEPROMStart(void);
unsigned char EEPROMReadByte(unsigned int addr);
void EEPROMWriteByte(unsigned int addr,unsigned char byte);
void EEPROMSectorErase(unsigned int addr);