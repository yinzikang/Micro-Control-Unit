#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "beep.h"


int main(void)
 {
 	vu8 key=0;	
	delay_init();	    	 //延时函数初始化	  
	LED_Init();		  		//初始化与LED连接的硬件接口
	BEEP_Init();         	//初始化蜂鸣器端口
	KEY_Init();         	//初始化与按键连接的硬件接口
	//PBout(5)=0;					//先点亮红灯
	while(1)
	{
 		key=KEY_Scan(0);	//得到键值
	   	if(key)
		{						   
			switch(key)
			{				 
				case 3:	//控制蜂鸣器
					//BEEP=!BEEP;
					//PBout(5)=!PBout(5);
					PBout(5)=!PBout(5);
					break; 
				case 2:	//控制LED1翻转	 
					PEout(5)=!PEout(5);
					break;
				case 1:	//同时控制LED0,PEout(5)翻转 
					PBout(5)=!PBout(5);
					PEout(5)=!PEout(5);
					break;
			}
		}else delay_ms(10); 
	}	 
}
