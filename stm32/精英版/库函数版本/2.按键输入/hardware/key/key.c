#include "key.h"
#include "delay.h"
void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
}

u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//按键按松开标志
	if(mode)key_up=1;  //支持连按		  
	if(key_up&&(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)==0||GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)==0||GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==1))
	{
		delay_ms(10);//去抖动 
		key_up=0;
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)==0)return 1;
		else if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)==0)return 2;
		else if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==1)return 3;
	}else if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)==1&&GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)==1&&GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==0)key_up=1; 	    
 	return 0;// 无按键按下
}
