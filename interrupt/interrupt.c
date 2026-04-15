#include "stm32f411xe.h"
#include "gpio.h"

char binary(char port){
    switch (port)
    {
    case PortA: return 0;
    case PortB: return 1;
    case PortC: return 2;
    case PortD: return 3;
    case PortE: return 4;
    case PortH: return 7;
    default: return 0; // or handle error
    }

}

void rcc(){
    RCC->APB2ENR |= (1 << 14);
}
void set(char port, char no){
    
    int n=0;
int x=no%4;
    if(no>=0 && no<=3){n=0;}
    if(no>=4 && no<=7){n=1;}
    if(no>=8 && no<=11){n=2;}
    if(no>=12 && no<=15){n=3;}
    
SYSCFG ->EXTICR[n] &= ~(0b1111<<4*x);
SYSCFG ->EXTICR[n] |=binary(port)<<4*x;
EXTI->IMR |=0b1<<no;
EXTI->RTSR |=0b1<<no;

}
void nvic(char port_no){
    __disable_irq();
switch (port_no)
{
case 0: NVIC_EnableIRQ(EXTI0_IRQn); break;
case 1: NVIC_EnableIRQ(EXTI1_IRQn); break;
case 2: NVIC_EnableIRQ(EXTI2_IRQn); break;
case 3: NVIC_EnableIRQ(EXTI3_IRQn); break;
case 4: NVIC_EnableIRQ(EXTI4_IRQn); break;

case 5:
case 6:
case 7:
case 8:
case 9:
    NVIC_EnableIRQ(EXTI9_5_IRQn);
    break;

default:
    NVIC_EnableIRQ(EXTI15_10_IRQn);
    break;
}
__enable_irq();

}
