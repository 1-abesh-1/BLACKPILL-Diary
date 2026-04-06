#include "stm32f411xe.h"

int main(void) {

  RCC->AHB1ENR |=0b111; //ENABLING PORT A & B
  GPIOA -> MODER &=~(0b11);
   GPIOA -> MODER |=0b01; 
   GPIOA ->OTYPER &= ~0b1;
    GPIOA ->ODR |=1;
    
     GPIOB -> MODER &=~(0b11 << 14);
   GPIOB -> MODER |=0b01<<14; 
   GPIOB ->OTYPER &= ~0b1<<7;
    GPIOB ->ODR |=1<<7;

    GPIOC -> MODER &=~(0b11 << 26);
   GPIOC -> MODER |=0b01<<26; 
   GPIOC ->OTYPER &= ~0b1<<13;
   // GPIOC ->ODR |=1<<13;
}
