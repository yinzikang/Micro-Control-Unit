#include "hcsr04.h"

int main()
{
    
        float length;
        
        GPIO_cfg();
      NVIC_cfg();
        USART_cfg();    
        printf("串口初始化成功！\n");
    
        Hcsr04Init();    
        printf("超声波初始化成功！\n");//测试程序是否卡在下面两句上面

        length = Hcsr04GetLength();
        printf("距离为:%.3f\n",length);
    
    
}