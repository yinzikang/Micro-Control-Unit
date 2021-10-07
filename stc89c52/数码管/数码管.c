#include<reg52.h>
#include<intrins.h>
sbit du = P2^6;
sbit we = P2^7;
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
								0xfe,//一位
								0xfd,//二位
								0xfb,//三位
								0xf7,//四位
								0xef,//五位
								0xdf,//六位
								0xbf,//七位
								0x7f //八位                
};
void delay(int x)
{
	int i,j;
	for(i = x;i > 0;i --)
		for(j = 114;j > 0;j --);
}
void play(int x,int y)
{
	we = 1;
	P0 = wei[x];
	we = 0;
	P0 = 0xff;
		
	du = 1;
	P0 = leddata[y];
	du = 0;
	P0 = 0xff;
	
	delay(2);
}
void main()
{
	int i;
	while(1)
	{
		for(i = 0;i < 8;i ++)
		{
			play(i,8 - i);
		}
	}
}
