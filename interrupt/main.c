#include "gpio.h"
#include "stm32f411xe.h"

int main(void) {
RCC ->APB2ENR |= 1<<14; //Kind of enabling irq clock though there is no irq clock. it is making the system ready to work with irqs
 
PinIntputSet(PB3);
PinIntputSet(PB4);
PinOutputSet(PA0);
PinOutputSet(PA1);
PinOutputSet(PA2);
SYSCFG ->EXTICR[0] &= ~0b1111<<4*3;

SYSCFG->EXTICR[0] |= (0b0001 << 4*3); //pb3
SYSCFG ->EXTICR[1] &= ~0b1111;

SYSCFG->EXTICR[1] |= 0b0001; //pb4
EXTI ->IMR |=0b11000;

EXTI-> RTSR |=0b10000;//PB4 as rising trigger

EXTI-> RTSR |=0b1000;//PB3 as falling trigger

__disable_irq();
NVIC_EnableIRQ(EXTI3_IRQn);
NVIC_EnableIRQ(EXTI4_IRQn);
__enable_irq();
while(1){




}




}

void EXTI3_IRQHandler(){
EXTI ->PR |=0b1000;
PinToggle(PA0);
}

void EXTI4_IRQHandler(){
EXTI ->PR |=0b10000;
PinToggle(PA2);
}
