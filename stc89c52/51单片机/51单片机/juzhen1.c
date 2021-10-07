#include<reg52.h>
#include<intrins.h>
#include<init.h>
uchar x;
uchar key_check()
{
 uchar key_l,key_h;
 while(1)
 {
		P3 = 0xf0;
		if((P3 & 0xf0) != 0xf0)
		{
			delay(5);
			if((P3 & 0xf0) != 0xf0)
			{
				key_l = P3 & 0xf0;
				P3 = key_l | 0x0f;
				key_h = P3 & 0x0f;
				while((P3 & 0x0f) != 0x0f);
			}
		}
	}	
  x = key_l + key_h;
	switch(x)
	{
		case 0xee : x = 1;
								break;
		case 0xde : x = 2;
								break;
		case 0xbe : x = 3;
								break;
		case 0xed : x = 4;
								break;
		case 0xdd : x = 5;
								break;
		case 0xbd : x = 6;
								break;
		case 0xeb : x = 7;
								break;
		case 0xdb : x = 8;
								break;
		case 0xbb : x = 9;
								break;
		case 0xd7 : x = 0;
								break;
	}
	return 1;
} 

