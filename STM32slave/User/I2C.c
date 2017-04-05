#include "i2c.h"
#include "stm32f10x.h"

void I2C_GPIO_Configuration(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void I2C_Configuration(void)
{ 
	I2C_InitTypeDef I2C_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4 | RCC_APB1Periph_I2C1, ENABLE);
 

  I2C_DeInit(I2C1);                                                  //��λI2C

  I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;                         //I2Cģʽ
  I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;                 //ռ�ձ�(����ģʽʱ)
  I2C_InitStructure.I2C_OwnAddress1 = OWN_ADDRESS;                   //�豸��ַ
  I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;                        //Ӧ��
  I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
  I2C_InitStructure.I2C_ClockSpeed = I2C_SPEED;                      //�ٶ�
  I2C_Init(I2C1, &I2C_InitStructure);

  I2C_ITConfig(I2C1, I2C_IT_BUF | I2C_IT_EVT, ENABLE);               //ʹ���ж�

  I2C_Cmd(I2C1, ENABLE);                                             //ʹ��I2C
}

void I2C_Initializes(void)
{
  I2C_GPIO_Configuration();
  I2C_Configuration();
}

void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  /* ���ȼ����� */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

  /* �����ж� */
  NVIC_InitStructure.NVIC_IRQChannel = I2C1_EV_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;          //�����ȼ�
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;                 //�����ȼ�
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = I2C1_ER_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;                 //�����ȼ�
  NVIC_Init(&NVIC_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;          //�����ȼ�
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;                 //�����ȼ�
  NVIC_Init(&NVIC_InitStructure);
}
