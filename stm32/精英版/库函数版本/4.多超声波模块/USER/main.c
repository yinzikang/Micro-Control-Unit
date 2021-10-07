#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"

/************************************************
 ALIENTEK精英STM32开发板实验10
 输入捕获实验 
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/
 


extern u8  TIM5CH1_CAPTURE_STA;		//输入捕获状态		    				
extern u16	TIM5CH1_CAPTURE_VAL;	//输入捕获值
extern u8  TIM5CH2_CAPTURE_STA;		//输入捕获状态		    				
extern u16	TIM5CH2_CAPTURE_VAL;	//输入捕获值
int main(void)
 {		
 	u32 temp1=0;
	u32 temp2=0;
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 //串口初始化为115200
	
 	Trig_Init();
	TIM5_Cap_Init(0XFFFF,72-1);	//以1Mhz的频率计数 
	while(1)
	{
		PBout(5) = 1;
 		delay_us(20);
		PBout(5) = 0;
 		if(TIM5CH1_CAPTURE_STA&0X80)//成功捕获到了一次上升沿
		{
			temp1=TIM5CH1_CAPTURE_STA&0X3F;
			temp1*=65536;//溢出时间总和
			temp1+=TIM5CH1_CAPTURE_VAL;//得到总的高电平时间
			temp1=temp1*0.17;
			printf("HIGH1:%d mm\r\n",temp1);//打印总的高点平时间
			TIM5CH1_CAPTURE_STA=0;//开启下一次捕获
		}
		if(TIM5CH2_CAPTURE_STA&0X80)//成功捕获到了一次上升沿
		{
			temp2=TIM5CH2_CAPTURE_STA&0X3F;
			temp2*=65536;//溢出时间总和
			temp2+=TIM5CH2_CAPTURE_VAL;//得到总的高电平时间
			temp2=temp2*0.17;
			printf("HIGH2:%d mm\r\n",temp2);//打印总的高点平时间
			TIM5CH2_CAPTURE_STA=0;//开启下一次捕获
		}
	}
 }

