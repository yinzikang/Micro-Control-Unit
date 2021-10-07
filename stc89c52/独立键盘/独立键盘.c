#include<stdio.h>
#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint  unsigned int
	
sbit we = P2^7;
sbit du = P2^6;
sbit key1 = P3^0;
sbit key2 = P3^1;
sbit key3 = P3^2;
sbit key4 = P3^3;

uchar num1,num2;
uchar leddata[]=
{  
                0x3F,  //"0"
                0x06,  //"1"
                0x5B,  //"2"
                0x4F,  //"3"
                0x66,  //"4"
                0x6D,  //"5"
                0x7D,  //"6"
                0x07,  //"7"
                0x7F,  //"8"
                0x6F,  //"9"
                0x77,  //"A"
                0x7C,  //"B"
                0x39,  //"C"
                0x5E,  //"D"
                0x79,  //"E"
                0x71,  //"F"
                0x76,  //"H"
                0x38,  //"L"
                0x37,  //"n"
                0x3E,  //"u"
                0x73,  //"P"
                0x5C,  //"o"
                0x40,  //"-"
                0x00,  //??
                0x00  //???
 };

void delay(uint x)
{
	int i,j;
	for(i = x;i > 0;i --)
		for(j = 114;j > 0;j --);
}

void play(int x)
{
	int a,b;
	a = x / 10;
	b = x % 10;
	
	we = 1;
	P0 = 0xfe;
	we = 0;
	
	du = 1;
	P0 = leddata[a];
	du = 0;
	delay(1);
	
	we = 1;
	P0 = 0xfd;
	we = 0;
	
	du = 1;
	P0 = leddata[b];
	du = 0;
	delay(1);
}

void init_start()
{
	TMOD = 0X01;
	TH0 = (65535 - 45872) / 256;
	TL0 = (65535 - 45872) % 256;
	EA = 1;
	ET0 = 1;
}

void scan()
{
	if(key1 == 0)
	{
		delay(10);
		if(key1 == 0)
		{
			num2 ++;
			while(!key1);
		}
	}
	
	if(key2 == 0)
	{
		delay(10);
		if(key2 == 0)
		{
			num2 --;
			while(!key2);
		}
	}
	
	if(key3 == 0)
	{
		delay(10);
		if(key3 == 0)
		{
			TR0 = ~TR0;
			while(!key3);
		}
	}
	
	if(key4 == 0)
	{
		delay(10);
		if(key4 == 0)
		{
			num2 = 0;
			while(!key4);
		}
	}
}

void main()
{
	init_start();
	while(1)
	{
		scan();
		play(num2);
	}
}

void T0_time() interrupt 1
{
	TH0 = (65535 - 45872) / 256;
	TL0 = (65535 - 45872) % 256;
	num1 ++;
	if(num1 == 20)
	{
		num1 = 0;
		num2 ++;
		if(num2 == 60)
		{
			num2 = 0;
		}
	}
}	