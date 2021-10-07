#include<reg52.h>
#include<intrins.h>
#define  uchar	unsigned char
#define  uint unsigned int

extern  void show();
extern void delay(uint z);
extern uchar key_check();
extern uchar x;
sbit wei = P2^7;
sbit dun = P2^6;
unsigned char leddata[] = { 
 
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
                0x00,  //Ï¨Ãð
                0x00  //×Ô¶¨Òå
 
                         } ;
