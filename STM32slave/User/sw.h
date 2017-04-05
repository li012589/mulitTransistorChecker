#ifndef _SW_H
#define _SW_H

#include "stm32f10x.h"

#define ON 1
#define OFF 0

#define SWA0(a) if (a) \
	GPIO_SetBits(GPIOA,GPIO_Pin_0);\
	else	\
	GPIO_ResetBits(GPIOA,GPIO_Pin_0)
#define SWA1(a) if (a) \
	GPIO_SetBits(GPIOA,GPIO_Pin_1);\
	else	\
	GPIO_ResetBits(GPIOA,GPIO_Pin_1)
#define SWA2(a) if (a) \
	GPIO_SetBits(GPIOA,GPIO_Pin_2);\
	else	\
	GPIO_ResetBits(GPIOA,GPIO_Pin_2)
#define SWA3(a) if (a) \
	GPIO_SetBits(GPIOA,GPIO_Pin_3);\
	else	\
	GPIO_ResetBits(GPIOA,GPIO_Pin_3)
#define SWA4(a) if (a) \
	GPIO_SetBits(GPIOA,GPIO_Pin_4);\
	else	\
	GPIO_ResetBits(GPIOA,GPIO_Pin_4)
#define SWA5(a) if (a) \
	GPIO_SetBits(GPIOA,GPIO_Pin_5);\
	else	\
	GPIO_ResetBits(GPIOA,GPIO_Pin_5)
#define SWA6(a) if (a) \
	GPIO_SetBits(GPIOA,GPIO_Pin_6);\
	else	\
	GPIO_ResetBits(GPIOA,GPIO_Pin_6)
#define SWA7(a) if (a) \
	GPIO_SetBits(GPIOA,GPIO_Pin_7);\
	else	\
	GPIO_ResetBits(GPIOA,GPIO_Pin_7)
#define SWA8(a) if (a) \
	GPIO_SetBits(GPIOA,GPIO_Pin_8);\
	else	\
	GPIO_ResetBits(GPIOA,GPIO_Pin_8)
#define SWA11(a) if (a) \
	GPIO_SetBits(GPIOA,GPIO_Pin_11);\
	else	\
	GPIO_ResetBits(GPIOA,GPIO_Pin_11)
#define SWA12(a) if (a) \
	GPIO_SetBits(GPIOA,GPIO_Pin_12);\
	else	\
	GPIO_ResetBits(GPIOA,GPIO_Pin_12)
#define SWA15(a) if (a) \
	GPIO_SetBits(GPIOA,GPIO_Pin_15);\
	else	\
	GPIO_ResetBits(GPIOA,GPIO_Pin_15)
	
#define SWB0(a) if (a) \
	GPIO_SetBits(GPIOB,GPIO_Pin_0);\
	else	\
	GPIO_ResetBits(GPIOB,GPIO_Pin_0)
#define SWB1(a) if (a) \
	GPIO_SetBits(GPIOB,GPIO_Pin_1);\
	else	\
	GPIO_ResetBits(GPIOB,GPIO_Pin_1)
#define SWB2(a) if (a) \
	GPIO_SetBits(GPIOB,GPIO_Pin_2);\
	else	\
	GPIO_ResetBits(GPIOB,GPIO_Pin_2)
#define SWB3(a) if (a) \
	GPIO_SetBits(GPIOB,GPIO_Pin_3);\
	else	\
	GPIO_ResetBits(GPIOB,GPIO_Pin_3)
#define SWB4(a) if (a) \
	GPIO_SetBits(GPIOB,GPIO_Pin_4);\
	else	\
	GPIO_ResetBits(GPIOB,GPIO_Pin_4)
#define SWB5(a) if (a) \
	GPIO_SetBits(GPIOB,GPIO_Pin_5);\
	else	\
	GPIO_ResetBits(GPIOB,GPIO_Pin_5)
#define SWB8(a) if (a) \
	GPIO_SetBits(GPIOB,GPIO_Pin_8);\
	else	\
	GPIO_ResetBits(GPIOB,GPIO_Pin_8)
#define SWB9(a) if (a) \
	GPIO_SetBits(GPIOB,GPIO_Pin_9);\
	else	\
	GPIO_ResetBits(GPIOB,GPIO_Pin_9)
#define SWB10(a) if (a) \
	GPIO_SetBits(GPIOB,GPIO_Pin_10);\
	else	\
	GPIO_ResetBits(GPIOB,GPIO_Pin_10)
#define SWB11(a) if (a) \
	GPIO_SetBits(GPIOB,GPIO_Pin_11);\
	else	\
	GPIO_ResetBits(GPIOB,GPIO_Pin_11)
#define SWB12(a) if (a) \
	GPIO_SetBits(GPIOB,GPIO_Pin_12);\
	else	\
	GPIO_ResetBits(GPIOB,GPIO_Pin_12)
#define SWB13(a) if (a) \
	GPIO_SetBits(GPIOB,GPIO_Pin_13);\
	else	\
	GPIO_ResetBits(GPIOB,GPIO_Pin_13)
#define SWB14(a) if (a) \
	GPIO_SetBits(GPIOB,GPIO_Pin_14);\
	else	\
	GPIO_ResetBits(GPIOB,GPIO_Pin_14)
#define SWB15(a) if (a) \
	GPIO_SetBits(GPIOB,GPIO_Pin_15);\
	else	\
	GPIO_ResetBits(GPIOB,GPIO_Pin_15)

#define SWC0(a) if (a) \
	GPIO_SetBits(GPIOC,GPIO_Pin_0);\
	else	\
	GPIO_ResetBits(GPIOC,GPIO_Pin_0)
#define SWC1(a) if (a) \
	GPIO_SetBits(GPIOC,GPIO_Pin_1);\
	else	\
	GPIO_ResetBits(GPIOC,GPIO_Pin_1)
#define SWC2(a) if (a) \
	GPIO_SetBits(GPIOC,GPIO_Pin_2);\
	else	\
	GPIO_ResetBits(GPIOC,GPIO_Pin_2)
#define SWC3(a) if (a) \
	GPIO_SetBits(GPIOC,GPIO_Pin_3);\
	else	\
	GPIO_ResetBits(GPIOC,GPIO_Pin_3)
#define SWC4(a) if (a) \
	GPIO_SetBits(GPIOC,GPIO_Pin_4);\
	else	\
	GPIO_ResetBits(GPIOC,GPIO_Pin_4)
#define SWC5(a) if (a) \
	GPIO_SetBits(GPIOC,GPIO_Pin_5);\
	else	\
	GPIO_ResetBits(GPIOC,GPIO_Pin_5)
#define SWC6(a) if (a) \
	GPIO_SetBits(GPIOC,GPIO_Pin_6);\
	else	\
	GPIO_ResetBits(GPIOC,GPIO_Pin_6)
#define SWC7(a) if (a) \
	GPIO_SetBits(GPIOC,GPIO_Pin_7);\
	else	\
	GPIO_ResetBits(GPIOC,GPIO_Pin_7)
#define SWC8(a) if (a) \
	GPIO_SetBits(GPIOC,GPIO_Pin_8);\
	else	\
	GPIO_ResetBits(GPIOC,GPIO_Pin_8)
#define SWC9(a) if (a) \
	GPIO_SetBits(GPIOC,GPIO_Pin_9);\
	else	\
	GPIO_ResetBits(GPIOC,GPIO_Pin_9)
#define SWC10(a) if (a) \
	GPIO_SetBits(GPIOC,GPIO_Pin_10);\
	else	\
	GPIO_ResetBits(GPIOC,GPIO_Pin_10)
#define SWC11(a) if (a) \
	GPIO_SetBits(GPIOC,GPIO_Pin_11);\
	else	\
	GPIO_ResetBits(GPIOC,GPIO_Pin_11)
#define SWC12(a) if (a) \
	GPIO_SetBits(GPIOC,GPIO_Pin_12);\
	else	\
	GPIO_ResetBits(GPIOC,GPIO_Pin_12)
#define SWC13(a) if (a) \
	GPIO_SetBits(GPIOC,GPIO_Pin_13);\
	else	\
	GPIO_ResetBits(GPIOC,GPIO_Pin_13)
#define SWC14(a) if (a) \
	GPIO_SetBits(GPIOC,GPIO_Pin_14);\
	else	\
	GPIO_ResetBits(GPIOC,GPIO_Pin_14)
#define SWC15(a) if (a) \
	GPIO_SetBits(GPIOC,GPIO_Pin_15);\
	else	\
	GPIO_ResetBits(GPIOC,GPIO_Pin_15)
	
#define SWD2(a) if (a) \
	GPIO_SetBits(GPIOD,GPIO_Pin_2);\
	else	\
	GPIO_ResetBits(GPIOD,GPIO_Pin_2)

void SW_GPIO_Con(void);

#endif /*_led_h*/
