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

void delay(uint x)
{
	int i,j;
	for(i = x;i > 0;i --)
		for(j = 114;j > 0;j --);
}

int s1()
{
	if(key1 == 0)
	{
		delay(10);
		if(key1 == 0) return 1;
	}
	return 0;
}

int s2()
{
	if(key2 == 0)
	{
		delay(10);
		if(key2 == 0) return 1;
	}
	return 0;
}

int s3()
{
	if(key3 == 0)
	{
		delay(10);
		if(key3 == 0) return 1;
	}
	return 0;
}

int s4()
{
	if(key4 == 0)
	{
		delay(10);
		if(key4 == 0) return 1;
	}
	return 0;
}

void d1()
{
	while((!s1())&&(!s2())&&(!s3())&&(!s4()))
	{
		P1 = _crol_(P1,1);
		delay(200);
	}
}

void d2()
{
	while((!s1())&&(!s2())&&(!s3())&&(!s4()))
	{
		P1 = _cror_(P1,1);
		delay(200);
	}
}

void d3()
{
	while((!s1())&&(!s2())&&(!s3())&&(!s4()))
	{
		P1 = _crol_(P1,3);
		delay(200);
	}
}

void d4()
{
	while((!s1())&&(!s2())&&(!s3())&&(!s4()))
	{
		P1 = _cror_(P1,3);
		delay(200);
	}
}

void scan()
{
	while(1)
	{
		if(s1())
			if(!s1())
			{
				P1 = 0xfe;
				d1();
			}
		if(s2())
			if(!s2())
			{
				P1 = 0x7f;
				d2();
			}
		if(s3())
			if(!s3())
			{
				P1 = 0xfe;
				d3();
			}
		if(s4())
			if(!s4())
			{
				P1 = 0x7f;
				d4();
			}
	}
	
}

void main()
{
	scan();
}