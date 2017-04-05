#include "usart1.h"

void USART1_Con(void)
{
 GPIO_InitTypeDef GPIO_InitStructure;
 USART_InitTypeDef USART1_InitStructure;

 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_USART1,ENABLE);

 GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
 GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
 GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
 GPIO_Init(GPIOA,&GPIO_InitStructure);


 GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;
 GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
 //GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
 GPIO_Init(GPIOA,&GPIO_InitStructure);


 USART1_InitStructure.USART_BaudRate=115200;
 USART1_InitStructure.USART_WordLength=USART_WordLength_8b;
 USART1_InitStructure.USART_Parity=USART_Parity_No;
 USART1_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
 USART1_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
 USART_Init(USART1,&USART1_InitStructure);
 USART_Cmd(USART1,ENABLE);

}

int fputc(int ch,FILE *f)
{
USART_SendData(USART1,(unsigned char) ch);
while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);
return(ch);
}

void USART1_printf(USART_TypeDef* USARTx,uint8_t *Data,...)
{
const char *s;
int d;
char buf[16];
va_list ap;
va_start(ap,Data);
while(*Data!=0)
{
	if(*Data==0x5c)
	{
		switch (*++Data)
		{
		case 'r':
			USART_SendData(USARTx,0x0d);
			Data++;
			break;
		case 'n':
			USART_SendData(USARTx,0x0a);
			Data++;
			break;
		default	 :
			Data++;
			break;
		}
			
	}
	else if(*Data=='%')
	{
		switch(*++Data)
		{
		case 's':
			s=va_arg(ap,const char*);
			for(;*s;s++)
			{
			USART_SendData(USARTx,*s);
			while(USART_GetFlagStatus(USARTx,USART_FLAG_TC)==RESET);
			}
			Data++;
			break;
		case 'd' :
			d=va_arg(ap,int);
			itoa(d,buf,10);
			for(s=buf;*s;s++)
			{
				USART_SendData(USARTx,*s);
				while(USART_GetFlagStatus(USARTx,USART_FLAG_TC)==RESET);
			}
			Data++;
			break;
		default:
			Data++;
			break;
		}

	}
	else USART_SendData(USARTx,*Data++);
	while(USART_GetFlagStatus(USARTx,USART_FLAG_TC)==RESET);
}
}

static char *itoa(int value,char *string,int radix)
{
int i,d;
int flag=0;
char *ptr=string;

if(radix!=10)
{
	*ptr=0;
	return string;
}
if(!value)
{
	*ptr++= 0x030;
	*ptr=0;
	return string;
}
if(value<0)
{
	*ptr++='-';
	value*=-1;
}
for(i=10000;i>0;i/=10)
{
	d=value/i;
	if(d||flag)
	{
	 	*ptr++=(char)(d+0x30);
		value-=(d*i);
		flag=1;
	}

}
*ptr=0;
return string;
}


