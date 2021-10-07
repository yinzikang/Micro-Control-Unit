#include <reg52.h>
#define uint unsigned int
#define uchar unsigned char
sbit du = P2^6;
sbit we = P2^7;
uchar key,a1,a2,a3,a4,wei,count = 0;
uchar code table[] = {
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
								0x00,  //"??"
};

void delay(uint x)
{
	uint i,j;
	for(i=x;i>0;i--)
	for(j=110;j>0;j--);
}

void display(uchar num1,uchar num2,uchar num3,uchar num4)
{
		we = 1;
		P0 = 0xfe;
		we = 0;
		du = 1;
		P0 = table[num1];
		du = 0;
		delay(2);

		we = 1;
		P0 = 0xfd;
		we = 0;
		du = 1;
		P0 = table[num2];
		du = 0;
		delay(2);
		
		we = 1;
		P0 = 0xfb;
		we = 0;
		du = 1;
		P0 = table[num3];
		du = 0;
		delay(2);
		
		we = 1;
		P0 = 0xf7;
		we = 0;
		du = 1;
		P0 = table[num4];
		du = 0;
		delay(2);
		
}

void init()
{
	switch(wei)
	{
		case 1:
			a1 = key;
			break;
		case 2:
			a2 = key;
			break;
		case 3:
			a3 = key;
			break;
		case 4:
			a4 = key;
			break;
	}
}
void keyscan()
{
	uchar temp;
	P3 = 0xfe;
	temp = P3;
	temp = temp&0xf0;
	if(temp != 0xf0)
	{
		delay(10);
		temp = P3;
		temp = temp&0xf0;
		if(temp != 0xf0)
		{
			count++;
			temp = P3;
			switch(temp)
			{
				case 0xee:
					key = 0;
					wei++;
					break;
				case 0xde:
					key = 1;
					wei++;
					break;
				case 0xbe:
					key = 2;
					wei++;
					break;
				case 0x7e:
					key = 3;
					wei++;
					break;
			}
			while(temp != 0xf0)
			{
				temp = P3;
				temp = temp&0xf0;
			}
			init();
		}
	}
	P3 = 0xfd;
	temp = P3;
	temp = temp&0xf0;
	if(temp != 0xf0)
	{
		delay(10);
		temp = P3;
		temp = temp&0xf0;
		if(temp != 0xf0)
		{
			count++;
			temp = P3;
			switch(temp)
			{
				case 0xed:
					key = 4;
					wei++;
					break;
				case 0xdd:
					key = 5;
					wei++;
					break;
				case 0xbd:
					key = 6;
					wei++;
					break;
				case 0x7d:
					key = 7;
					wei++;
					break;
			}
			while(temp != 0xf0)
			{
				temp = P3;
				temp = temp&0xf0;
			}
			init();
		}
	}
	P3 = 0xfb;
	temp = P3;
	temp = temp&0xf0;
	if(temp != 0xf0)
	{
		delay(10);
		temp = P3;
		temp = temp&0xf0;
		if(temp != 0xf0)
		{
			count++;
			temp = P3;
			switch(temp)
			{
				case 0xeb:
					key = 8;
					wei++;
					break;
				case 0xdb:
					key = 9;
					wei++;
					break;
				case 0xbb:
					key = 10;
					break;
			}
			while(temp != 0xf0)
			{
				temp = P3;
				temp = temp&0xf0;
			}
			init();
		}
	}
	display(a1,a2,a3,a4);
}

void main()
{
	du = 1;
	P0 = 0;
	du = 0;
	we = 1;
	P0 = 0;
	we = 0;
	while(1)
	{
		keyscan();
	}
}
