#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
 
/************************************************
 ALIENTEK精英STM32开发板实验9
 PWM输出实验  
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/

 int main(void)
 {		
	 int delay_time = 1000;
//	int t = 500;	 
// 	u16 led0pwmval=0;
//	u8 dir=1;	
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 //串口初始化为115200
 	LED_Init();			     //LED端口初始化
 	TIM3_PWM_Init(200,7200);	 //PWM频率=72000000/3600/400=50
	while(1)
	{
		delay_ms(delay_time);
		TIM_SetCompare2(TIM3, 195); //对应0度
        delay_ms(delay_time);
		TIM_SetCompare2(TIM3, 190); //对应45度
        delay_ms(delay_time);
		TIM_SetCompare2(TIM3, 185); //对应90度
		delay_ms(delay_time);
		TIM_SetCompare2(TIM3, 180); //对应135度
        delay_ms(delay_time);
		TIM_SetCompare2(TIM3, 175); //对应180度
	}	 
 }

//http://www.openedv.com/posts/list/52608.htm
 