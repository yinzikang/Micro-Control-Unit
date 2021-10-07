#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint  unsigned int
sbit du = P2^6;
sbit we = P2^7;
uchar num1;
uchar num2;
unsigned char leddata[]=
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
unsigned char  wei[]=
{  
								0xfe,//??
								0xfd,//??
								0xfb,//??
								0xf7,//??
								0xef,//??
								0xdf,//??
								0xbf,//??
								0x7f //??                
};

void init_start()
{
	TMOD = 0x01;
	TH0 = (65535 - 45872) / 256;
	TL0 = (65535 - 45876) % 256;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}

void delay(int x)
{
	int i,j;
	for(i = x;i > 0;i --)
		for(j = 114;j > 0;j --);
}

void play()
{
	if(num2 <= 10)
	{
		int b,c;
		
		b = num2 / 10;
		c = num2 % 10;
		
		we = 1;
		P0 = wei[0];
		we = 0;
		P0 = 0xff;
			
		du = 1;
		P0 = leddata[b];
		du = 0;
		P0 = 0xff;
		
		delay(2);
		
		we = 1;
		P0 = wei[1];
		we = 0;
		P0 = 0xff;
			
		du = 1;
		P0 = leddata[c];
		du = 0;
		P0 = 0xff;
		
		delay(2);
	}
	else 
	{
		num2 = 0;
		P1 = _crol_(P1,1);
	}	
}

void main()
{
	P1 = 0xfe;
	init_start();
	while(1)
	{
		play();
	}
}

void T0_time() interrupt 1
{
	TH0 = (65535 - 45872) / 256;
	TL0 = (65535 - 45876) % 256;
	num1 ++;
	if(num1 == 2)
	{
		num1 = 0;
		num2 ++;
	}
}