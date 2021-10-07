
//接线：模块TRIG接 P1.2  ECH0 接P1.1
//串口波特率9600
/***********************************************************************************************************/	  
	#include   <reg52.h>
	#include   <intrins.h>
	#include <stdio.h>
	sbit  Echo  = P1^0;
    sbit  Trig  = P1^1;
	unsigned int  time=0;
	unsigned int  timer=0;
	float         S=0;
	int C = 0;
    bit           flag =0;
	

/********************************************************/
    void Conut(void)
	{
	 time=TH0*256+TL0;
	 TH0=0;
	 TL0=0;
	 S=(time*1.87)/100;     //算出来是mm
	 C = S/10;
	if(flag==1)		    //超出测量
	 {
	  flag=0;
	 }
	  printf("%d %d\n",S,C); 
	}
/********************************************************/ 
void delayms(unsigned int ms)
{
	unsigned char i=100,j;
	for(;ms;ms--)
	{
		while(--i)
		{
			j=10;
			while(--j);
		}
	}
}
/********************************************************/
     void zd0() interrupt 1 		 //T0中断用来计数器溢出,超过测距范围
  {
    flag=1;							 //中断溢出标志
  }
/********************************************************/
   void  StartModule() 		         //T1中断用来扫描数码管和计800MS启动模块
  {
	  Trig=1;			                 //800MS  启动一次模块
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  Trig=0;
  }
/********************************************************/
void main(void)
{  
    TMOD=0x21;		   //设T0为方式1，GATE=1；
	SCON=0x50;
	TH1=0xFD;
	TL1=0xFD;
	TH0=0;
	TL0=0; 
	TR0=1;  
	ET0=1;             //允许T0中断
	TR1=1;			   //开启定时器
	TI=1;

	EA=1;			   //开启总中断


	while(1)
	{
	 StartModule();
	 while(!Echo);		//当Echo为零时等待
	 TR0=1;			    //开启计数
	 while(Echo);			//当Echo为1计数并等待
	 TR0=0;				//关闭计数
     Conut();			//计算
	 delayms(100);		//100MS

	}

}              