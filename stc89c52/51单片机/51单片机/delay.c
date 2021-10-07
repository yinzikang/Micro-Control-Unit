#include<reg52.h>
#include<intrins.h>
#include<init.h>
void delay(uint z)
{
	uint i,j;
	for(i = z;i > 0;i --)
		for(j = 120;j > 0;j --);
} 						