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
   

   GPIOA ->MODER &= ~(0b11<<4*2);
   GPIOA ->MODER |= (0b00<<4*2);
   GPIOA ->OTYPER &= ~0b1<<4;

   
   GPIOA ->PUPDR &= ~(0b11<<4*2);
   GPIOA ->PUPDR |= (0b10<<4*2);

   
   GPIOB ->MODER &= ~(0b11<<4*2);
   GPIOB ->MODER |= (0b00<<4*2);
   GPIOB ->OTYPER &= ~0b1<<4;

   
   GPIOB ->PUPDR &= ~(0b11<<4*2);
   GPIOB ->PUPDR |= (0b10<<4*2);

   
while(1){
if(GPIOA -> IDR & 0x10){

  GPIOA->ODR |= 0b1;

}else{
  GPIOA->ODR &= ~0b1;
}

if(GPIOB-> IDR & 0x10){

  GPIOB->ODR |= 0b1 <<7;
GPIOC->ODR |= 0b1 << 13;
}else{
  GPIOB->ODR &= ~0b1 <<7;
  
  GPIOC ->ODR &= ~(0b1<<13);
}

}



}
