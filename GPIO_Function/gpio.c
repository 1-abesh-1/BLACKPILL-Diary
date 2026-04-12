#include "stm32f411xe.h"
#include "gpio.h"


void gpio_init(char port){
	RCC->AHB1ENR |=(1<<port);
}


void pinOutput(char port,char no){
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


target_port->MODER &= ~(0b11<<no*2);
target_port ->MODER|=(0b01<<no*2);
target_port ->OTYPER &= ~(0b1<<no);

}

void pin(char port,char no, char mode){
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


if(mode==1){target_port ->ODR|=(0b1<<no);}
else{
target_port->ODR &=~(0b1<<no);

}

}

