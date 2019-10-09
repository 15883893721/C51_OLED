#ifndef __UART_H__
#define __UART_H__

#include "reg52.h"

#define FOSC 12000000L      //System frequency
#define BAUD 2400           //UART baudrate

/*Define UART parity mode*/
#define NONE_PARITY     0   //None parity
#define ODD_PARITY      1   //Odd parity
#define EVEN_PARITY     2   //Even parity
#define MARK_PARITY     3   //Mark parity
#define SPACE_PARITY    4   //Space parity

#define PARITYBIT NONE_PARITY   //Testing even parity

void UART_Init();
void UART_SentChar(unsigned char chr);
unsigned char UART_RecChar(void);
void UART_SendString(unsigned char *str);

#endif
