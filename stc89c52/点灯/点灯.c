#include<reg52.h>
#include<intrins.h>
unsigned char deng[] = 
{
	0xfe,
	0xfc,
	0xf8,
	0xf0,
	0xe0,
	0xc0,
	0x80,
	0x00
};
void delay(int x)
{
	int i,j;
	for(i= x;i > 0;i --)
		for(j = 114;j > 0;j --);
}
void main()
{
	int x = 16,y = 0;
	while(1)
	{
		P1 = deng[y];
		while(x--)
		{
			P1 = _crol_(P1,1);
			delay(20);
		}
		x = 16;
		y ++;
		if(y == 8) y = 0;
	}
}