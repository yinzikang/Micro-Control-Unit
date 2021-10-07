//?????????,????,?????
#include<reg51.h>
#include <intrins.h>
#define uchar unsigned char
#define uint unsigned int
sbit key=P3^0 ;                                        //????
uchar num=0;                                        //??????

void keyscan()                                        //???????
{
        static bit key_sign=0;                //??????
        static uchar count=0;                //????                        
        if(key==0)                                        //??????
        {
                count++;                                        //????
                if(count>=100)                        //100????????0
                {                        
                        count=100;                        //????
                        if(key_sign==0)                //???????0
                        {
                                key_sign=1;                //???????1,??????
                                num++;
                                if(num>=3)                //?????
                                        num=0;
                        }
                }
        }
        else                                                        //????
        {
                key_sign=0;                                //???????0
                count=0;                                        //?????0
        }
}

void display()                                        //?????
{
        static uint count1=0;                       //????
        count1++;                                        //????
        if(count1>=10000)
        {
                count1=0;
                switch(num)                                //????
                {
                        case 0: 
                        P1=0xfe;                                //????
                        break;

                        case 1: 
                        P1=_crol_(P1,1);                   //?????
                        break;
        
                        case 2: 
                        P1=_cror_(P1,1);        //?????
                        break;

//                        case N: 
//                        N??
//                        break;

                }
        }
}                

void main()
{
//        P1=0xfe;
        while(1)
        {
                keyscan();                                //???????
                display();                                //?????
        }
}
