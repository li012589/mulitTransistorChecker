
#include "stm32f10x.h"
#include <stdio.h>
#include <string.h>
/* Private function prototypes -----------------------------------------------*/
#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

#include "sw.h"
#include "usart1.h"
#include "I2C.h"
void Delay(u32 nCount);
uint8_t  Buffer_Rx[100];
uint8_t  Rx_Idx=0;
uint8_t  Flag_RcvOK = 0;    

int main(void)
{
	uint8_t i;
	uint8_t tmph;
	uint8_t tmpl;
USART1_Con();
	printf("\r\nUSART communication started\r\n");
SW_GPIO_Con();
	printf("\r\nGPIO configuration succeeded\r\n");

NVIC_Configuration();
	printf("\r\nNVIC configuration succeeded\r\n");
I2C_Initializes();  
	printf("\r\nI2C configuration succeeded,the slave address is 0x%X\r\n",OWN_ADDRESS >> 1);
	printf("\r\nAll systems OK, start running\r\n");
while (1)
{
	SWA5(ON);
	while(1)
  {
    if(1 == Flag_RcvOK)
    {
      Flag_RcvOK = 0;
      printf("\r\nOrder recived:\n\r"); 
			for(i=1;i<Rx_Idx;i++)
			{
				tmpl=Buffer_Rx[i]&0x0f;
				tmph=(Buffer_Rx[i]&0xf0) >> 4;
				if(tmph==1)
				{
					switch(tmpl)
					{
						case 0 : SWA0(ON);printf("\r\nSWA0 ON\r\n");break;
						case 1 : SWA1(ON);printf("\r\nSWA1 ON\r\n");break;
						case 2 : SWA2(ON);printf("\r\nSWA2 ON\r\n");break;
						case 3 : SWA3(ON);printf("\r\nSWA3 ON\r\n");break;
						case 4 : SWA4(ON);printf("\r\nSWA4 ON\r\n");break;
						case 5 : SWA5(ON);printf("\r\nSWA5 ON\r\n");break;
						case 6 : SWA6(ON);printf("\r\nSWA6 ON\r\n");break;
						case 7 : SWA7(ON);printf("\r\nSWA7 ON\r\n");break;
						case 8 : SWA8(ON);printf("\r\nSWA8 ON\r\n");break;
						case 11 : SWA11(ON);printf("\r\nSWA11 ON\r\n");break;
						case 12 : SWA12(ON);printf("\r\nSWA12 ON\r\n");break;
						case 15 : SWA15(ON);printf("\r\nSWA15 ON\r\n");break;
						default : printf("\r\n SWA SELECTION ERROR !!\r\n");SWD2(ON);
					}
				}
				else if(tmph==2)
				{
					switch(tmpl)
					{
						case 0 : SWA0(OFF);printf("\r\nSWA0 OFF\r\n");break;
						case 1 : SWA1(OFF);printf("\r\nSWA1 OFF\r\n");break;
						case 2 : SWA2(OFF);printf("\r\nSWA2 OFF\r\n");break;
						case 3 : SWA3(OFF);printf("\r\nSWA3 OFF\r\n");break;
						case 4 : SWA4(OFF);printf("\r\nSWA4 OFF\r\n");break;
						case 5 : SWA5(OFF);printf("\r\nSWA5 OFF\r\n");break;
						case 6 : SWA6(OFF);printf("\r\nSWA6 OFF\r\n");break;
						case 7 : SWA7(OFF);printf("\r\nSWA7 OFF\r\n");break;
						case 8 : SWA8(OFF);printf("\r\nSWA8 OFF\r\n");break;
						case 11 : SWA11(OFF);printf("\r\nSWA11 OFF\r\n");break;
						case 12 : SWA12(OFF);printf("\r\nSWA12 OFF\r\n");break;
						case 15 : SWA15(OFF);printf("\r\nSWA15 OFF\r\n");break;
						default : printf("\r\n SWA SELECTION ERROR !!\r\n");SWD2(ON);
					}
				}
				else if(tmph==3)
				{
					switch(tmpl)
					{
						case 0 : SWB0(ON);printf("\r\nSWB0 ON\r\n");break;
						case 1 : SWB1(ON);printf("\r\nSWB1 ON\r\n");break;
						case 2 : SWB2(ON);printf("\r\nSWB2 ON\r\n");break;
						case 3 : SWB3(ON);printf("\r\nSWB3 ON\r\n");break;
						case 4 : SWB4(ON);printf("\r\nSWB4 ON\r\n");break;
						case 5 : SWB5(ON);printf("\r\nSWB5 ON\r\n");break;
						case 8 : SWB8(ON);printf("\r\nSWB8 ON\r\n");break;
						case 9 : SWB9(ON);printf("\r\nSWB9 ON\r\n");break;
						case 10 : SWB10(ON);printf("\r\nSWB10 ON\r\n");break;
						case 11 : SWB11(ON);printf("\r\nSWB11 ON\r\n");break;
						case 12 : SWB12(ON);printf("\r\nSWB12 ON\r\n");break;
						case 13 : SWB13(ON);printf("\r\nSWB13 ON\r\n");break;
						case 14 : SWB14(ON);printf("\r\nSWB14 ON\r\n");break;
						case 15 : SWB15(ON);printf("\r\nSWB15 ON\r\n");break;
						default : printf("\r\n SWB SELECTION ERROR !!\r\n");SWD2(ON);
					}
				}
				else if(tmph==4)
				{
						switch(tmpl)
					{
						case 0 : SWB0(OFF);printf("\r\nSWB0 OFF\r\n");break;
						case 1 : SWB1(OFF);printf("\r\nSWB1 OFF\r\n");break;
						case 2 : SWB2(OFF);printf("\r\nSWB2 OFF\r\n");break;
						case 3 : SWB3(OFF);printf("\r\nSWB3 OFF\r\n");break;
						case 4 : SWB4(OFF);printf("\r\nSWB4 OFF\r\n");break;
						case 5 : SWB5(OFF);printf("\r\nSWB5 OFF\r\n");break;
						case 8 : SWB8(OFF);printf("\r\nSWB8 OFF\r\n");break;
						case 9 : SWB9(OFF);printf("\r\nSWB9 OFF\r\n");break;
						case 10 : SWB10(OFF);printf("\r\nSWB10 OFF\r\n");break;
						case 11 : SWB11(OFF);printf("\r\nSWB11 OFF\r\n");break;
						case 12 : SWB12(OFF);printf("\r\nSWB12 OFF\r\n");break;
						case 13 : SWB13(OFF);printf("\r\nSWB13 OFF\r\n");break;
						case 14 : SWB14(OFF);printf("\r\nSWB14 OFF\r\n");break;
						case 15 : SWB15(OFF);printf("\r\nSWB15 OFF\r\n");break;
						default : printf("\r\n SWB SELECTION ERROR !!\r\n");SWD2(ON);
					}
				}
				else if(tmph==5)
				{
					switch(tmpl)
					{
						case 0 : SWC0(ON);printf("\r\nSWC0 ON\r\n");break;
						case 1 : SWC1(ON);printf("\r\nSWC1 ON\r\n");break;
						case 2 : SWC2(ON);printf("\r\nSWC2 ON\r\n");break;
						case 3 : SWC3(ON);printf("\r\nSWC3 ON\r\n");break;
						case 4 : SWC4(ON);printf("\r\nSWC4 ON\r\n");break;
						case 5 : SWC5(ON);printf("\r\nSWC5 ON\r\n");break;
						case 6 : SWC6(ON);printf("\r\nSWC6 ON\r\n");break;
						case 7 : SWC7(ON);printf("\r\nSWC7 ON\r\n");break;
						case 8 : SWC8(ON);printf("\r\nSWC8 ON\r\n");break;
						case 9 : SWC9(ON);printf("\r\nSWC9 ON\r\n");break;
						case 10 : SWC10(ON);printf("\r\nSWC10 ON\r\n");break;
						case 11 : SWC11(ON);printf("\r\nSWC11 ON\r\n");break;
						case 12 : SWC12(ON);printf("\r\nSWC12 ON\r\n");break;
						case 13 : SWC13(ON);printf("\r\nSWC13 ON\r\n");break;
						case 14 : SWC14(ON);printf("\r\nSWC14 ON\r\n");break;
						case 15 : SWC15(ON);printf("\r\nSWC15 ON\r\n");break;
						default : printf("\r\n SWC SELECTION ERROR !!\r\n");SWD2(ON);
					}
				}
				else if(tmph==6)
				{
					switch(tmpl)
					{
						case 0 : SWC0(OFF);printf("\r\nSWC0 OFF\r\n");break;
						case 1 : SWC1(OFF);printf("\r\nSWC1 OFF\r\n");break;
						case 2 : SWC2(OFF);printf("\r\nSWC2 OFF\r\n");break;
						case 3 : SWC3(OFF);printf("\r\nSWC3 OFF\r\n");break;
						case 4 : SWC4(OFF);printf("\r\nSWC4 OFF\r\n");break;
						case 5 : SWC5(OFF);printf("\r\nSWC5 OFF\r\n");break;
						case 6 : SWC6(OFF);printf("\r\nSWC6 OFF\r\n");break;
						case 7 : SWC7(OFF);printf("\r\nSWC7 OFF\r\n");break;
						case 8 : SWC8(OFF);printf("\r\nSWC8 OFF\r\n");break;
						case 9 : SWC9(OFF);printf("\r\nSWC9 OFF\r\n");break;
						case 10 : SWC10(OFF);printf("\r\nSWC10 OFF\r\n");break;
						case 11 : SWC11(OFF);printf("\r\nSWC11 OFF\r\n");break;
						case 12 : SWC12(OFF);printf("\r\nSWC12 OFF\r\n");break;
						case 13 : SWC13(OFF);printf("\r\nSWC13 OFF\r\n");break;
						case 14 : SWC14(OFF);printf("\r\nSWC14 OFF\r\n");break;
						case 15 : SWC15(OFF);printf("\r\nSWC15 OFF\r\n");break;
						default : printf("\r\n SWC SELECTION ERROR !!\r\n");SWD2(ON);
					}
				}
				else
				{
					printf("\r\n SWC SELECTION ERROR !!\r\n");SWD2(ON);
				}
				//printf("\r\n%d %d %d\r\n",Buffer_Rx[i],tmph,tmpl);
				
			}				
    }
  }

};
}

void Delay(u32 nCount)
{
for(;nCount!=0;nCount--);

}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/*************************************** END OF FILE *************************************/
