#include "hcsr04.h"

int main()
{
    
        float length;
        
        GPIO_cfg();
      NVIC_cfg();
        USART_cfg();    
        printf("���ڳ�ʼ���ɹ���\n");
    
        Hcsr04Init();    
        printf("��������ʼ���ɹ���\n");//���Գ����Ƿ���������������

        length = Hcsr04GetLength();
        printf("����Ϊ:%.3f\n",length);
    
    
}