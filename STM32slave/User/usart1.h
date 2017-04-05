#ifndef _USART1
#define _USART1

#include "stdarg.h"
#include "stdio.h"
#include "stm32f10x.h"


void USART1_Con(void);
int fputc(int ch,FILE *f);
void USART1_printf(USART_TypeDef* USARTx,uint8_t *Data,...);
static char *itoa(int value,char *string,int radiox);

#endif
