#include<reg52.h>
#define uchar unsigned char
#define uint  unsigned char
sbit PWM = P1^0;
sbit jian = P3^0;
sbit jia = P3^1;
uint count;
uchar jd;

void delay(uint x)
{
	int i,j;
	for(i = x;i > 0;i --)
		for(j = 114;j > 0;j --);
}

void init()
{
	TMOD = 0X01;
	TH0 = 0xff;
	TL0 = 0xac;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}

void scan()
{
	if(!jia)
	{
		delay(10);
		if(!jia)
		{
			jd ++;
			count = 0;
			if(jd == 26) jd = 25;
			//while(!jia);
		}
	}
	if(!jian)
	{
		delay(10);
		if(!jian)
		{
			jd --;
			count = 0;
			if(jd == 5) jd = 6;
			//while(!jian);
		}
	}
}

void main()
{
	jd = 25;
	count = 0;
	init();
	while(1) 
	{
		scan();
	}
}

void T0_time() interrupt 1
{
	TH0 = 0xff;
	TL0 = 0xac;
	if(count <= jd) PWM = 1;
	else PWM = 0;
	count += 1;
	count %= 200;
}	