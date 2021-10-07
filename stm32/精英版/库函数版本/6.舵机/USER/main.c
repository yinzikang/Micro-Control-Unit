#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
 
/************************************************
 ALIENTEK��ӢSTM32������ʵ��9
 PWM���ʵ��  
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

 int main(void)
 {		
	 int delay_time = 1000;
//	int t = 500;	 
// 	u16 led0pwmval=0;
//	u8 dir=1;	
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 //���ڳ�ʼ��Ϊ115200
 	LED_Init();			     //LED�˿ڳ�ʼ��
 	TIM3_PWM_Init(200,7200);	 //PWMƵ��=72000000/3600/400=50
	while(1)
	{
		delay_ms(delay_time);
		TIM_SetCompare2(TIM3, 195); //��Ӧ0��
        delay_ms(delay_time);
		TIM_SetCompare2(TIM3, 190); //��Ӧ45��
        delay_ms(delay_time);
		TIM_SetCompare2(TIM3, 185); //��Ӧ90��
		delay_ms(delay_time);
		TIM_SetCompare2(TIM3, 180); //��Ӧ135��
        delay_ms(delay_time);
		TIM_SetCompare2(TIM3, 175); //��Ӧ180��
	}	 
 }

//http://www.openedv.com/posts/list/52608.htm
 