#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
 
/************************************************
 ALIENTEK��ӢSTM32������ʵ��4
 ���� ʵ��   
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/
 int main(void)
 {		
	u16 data[5] = {0x00,0x01,0x02,0x03,0x04};
 	u16 t;  	
	u16 times=0;
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(9600);	 //���ڳ�ʼ��Ϊ115200
 	while(1)
	{
		//if(USART_RX_STA&0x8000)
		{					   
			for(t=0;t<5;t++)
			{
				USART_SendData(USART1, data[t]);//�򴮿�1��������
				while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
			}
			delay_ms(1000);
			printf("12345");
			delay_ms(1000);
			printf("abcde");
			delay_ms(1000);
			printf("12345\n");
			delay_ms(1000);
			printf("abcde\n");
			delay_ms(1000);
			//USART_RX_STA=0;
		}
//		else
//		{
//			times++; 
//			if(times%1000==0)
//			{
//				LED0=!LED0;//��˸LED,��ʾϵͳ��������.
//				times = 0;
//			}
//			delay_ms(10);   
//		}
	}	 
 }

