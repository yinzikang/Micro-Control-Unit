#include<reg52.h>
#include<intrins.h>
#include"init.h"

void show()
{
	 wei = 1;
	 P0 = 0xfe;
	 wei = 0;

	 dun = 1;
	 P0 = leddata[x];
	 dun = 1;
}	