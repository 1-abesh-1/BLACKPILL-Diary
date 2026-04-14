#include "stm32f411xe.h"
#include "gpio.h"

GPIO_TypeDef *target(char port){
GPIO_TypeDef *target_port;

switch (port) {

    case PortA:
        target_port = GPIOA;
        break;

    case PortB:
        target_port = GPIOB;
        break;

    case PortC:
        target_port = GPIOC;
        break;

    case PortD:
        target_port = GPIOD;
        break;

    case PortE:
        target_port = GPIOE;
        break;

    case PortH:
        target_port = GPIOH;
        break;

    default:
        target_port = GPIOA; // fallback (or error handler)
        break;
}

return target_port;
}
void gpio_init(char port){
	RCC->AHB1ENR |=(1<<port);
}


void pinOutput(char port,char no){
	GPIO_TypeDef *target_port=target(port);



target_port->MODER &= ~(0b11<<no*2);
target_port ->MODER|=(0b01<<no*2);
target_port ->OTYPER &= ~(0b1<<no);

}

void pinInput(char port,char no){
	GPIO_TypeDef *target_port=target(port);


  target_port ->MODER &= ~(0b11<<no*2);
   target_port ->MODER |= (0b00<<no*2);
   target_port ->OTYPER &= ~0b1<<no;

   
   target_port ->PUPDR &= ~(0b11<<no*2);
   target_port ->PUPDR |= (0b10<<no*2);

}




int status(char port, char no){
GPIO_TypeDef *target_port=target(port);

return (target_port->IDR & (1 << no)) ? 1 : 0;

}



void pin(char port,char no, char mode){
	GPIO_TypeDef *target_port=target(port);



if(mode==1){target_port ->ODR|=(0b1<<no);}
else{
target_port->ODR &=~(0b1<<no);

}

}

