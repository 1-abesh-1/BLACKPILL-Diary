#include "gpio.h"
#include "interrupt.h"
#include "stm32f411xe.h"
#include "clock.h"


void hse_on(){
    RCC->CR |= (1<<16);

    uint32_t timeout = 1000000;
    while(!(RCC->CR & (1<<17)) && timeout--){
        // wait
    }

    if (!(RCC->CR & (1<<17))){
       
        while(1);
    }
}

void hse_off(){
    RCC->CR &=~(1<<16);
}

void pll_on(){
    RCC->CR |=(1<<24);
}
void pll_off(){
    RCC->CR &=~(1<<24);
}


void mco1(char clk){
    gpio_init(PortA);
    pinAf(PortA,8);

RCC->CFGR &= ~(0b111 << 24);

RCC->CFGR |= (0b000 << 24);
    RCC->CFGR &=~(0b11<<21);
    RCC->CFGR |=(clk<<21);
}

