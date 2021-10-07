#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"

/************************************************
 ALIENTEK��ӢSTM32������ʵ��10
 ���벶��ʵ�� 
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/
 


extern u8  TIM5CH1_CAPTURE_STA;		//���벶��״̬		    				
extern u16	TIM5CH1_CAPTURE_VAL;	//���벶��ֵ
extern u8  TIM5CH2_CAPTURE_STA;		//���벶��״̬		    				
extern u16	TIM5CH2_CAPTURE_VAL;	//���벶��ֵ
int main(void)
 {		
 	u32 temp1=0;
	u32 temp2=0;
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 //���ڳ�ʼ��Ϊ115200
	
 	Trig_Init();
	TIM5_Cap_Init(0XFFFF,72-1);	//��1Mhz��Ƶ�ʼ��� 
	while(1)
	{
		PBout(5) = 1;
 		delay_us(20);
		PBout(5) = 0;
 		if(TIM5CH1_CAPTURE_STA&0X80)//�ɹ�������һ��������
		{
			temp1=TIM5CH1_CAPTURE_STA&0X3F;
			temp1*=65536;//���ʱ���ܺ�
			temp1+=TIM5CH1_CAPTURE_VAL;//�õ��ܵĸߵ�ƽʱ��
			temp1=temp1*0.17;
			printf("HIGH1:%d mm\r\n",temp1);//��ӡ�ܵĸߵ�ƽʱ��
			TIM5CH1_CAPTURE_STA=0;//������һ�β���
		}
		if(TIM5CH2_CAPTURE_STA&0X80)//�ɹ�������һ��������
		{
			temp2=TIM5CH2_CAPTURE_STA&0X3F;
			temp2*=65536;//���ʱ���ܺ�
			temp2+=TIM5CH2_CAPTURE_VAL;//�õ��ܵĸߵ�ƽʱ��
			temp2=temp2*0.17;
			printf("HIGH2:%d mm\r\n",temp2);//��ӡ�ܵĸߵ�ƽʱ��
			TIM5CH2_CAPTURE_STA=0;//������һ�β���
		}
	}
 }

