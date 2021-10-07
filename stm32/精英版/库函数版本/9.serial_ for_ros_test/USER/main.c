#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
 
/************************************************
 ALIENTEK精英STM32开发板实验4
 串口 实验   
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/
 int main(void)
 {		
	u16 data[5] = {0x00,0x01,0x02,0x03,0x04};
 	u16 t;  	
	u16 times=0;
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(9600);	 //串口初始化为115200
 	while(1)
	{
		//if(USART_RX_STA&0x8000)
		{					   
			for(t=0;t<5;t++)
			{
				USART_SendData(USART1, data[t]);//向串口1发送数据
				while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束
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
//				LED0=!LED0;//闪烁LED,提示系统正在运行.
//				times = 0;
//			}
//			delay_ms(10);   
//		}
	}	 
 }

