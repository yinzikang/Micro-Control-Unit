#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "beep.h"


int main(void)
 {
 	vu8 key=0;	
	delay_init();	    	 //��ʱ������ʼ��	  
	LED_Init();		  		//��ʼ����LED���ӵ�Ӳ���ӿ�
	BEEP_Init();         	//��ʼ���������˿�
	KEY_Init();         	//��ʼ���밴�����ӵ�Ӳ���ӿ�
	//PBout(5)=0;					//�ȵ������
	while(1)
	{
 		key=KEY_Scan(0);	//�õ���ֵ
	   	if(key)
		{						   
			switch(key)
			{				 
				case 3:	//���Ʒ�����
					//BEEP=!BEEP;
					//PBout(5)=!PBout(5);
					PBout(5)=!PBout(5);
					break; 
				case 2:	//����LED1��ת	 
					PEout(5)=!PEout(5);
					break;
				case 1:	//ͬʱ����LED0,PEout(5)��ת 
					PBout(5)=!PBout(5);
					PEout(5)=!PEout(5);
					break;
			}
		}else delay_ms(10); 
	}	 
}
