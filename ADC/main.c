#include "gpio.h"
#include "stm32f411xe.h"
volatile uint32_t adcData;
volatile uint32_t output;
int main(){
   
 
RCC->APB2ENR |=(1<<8);
gpio_init(PortA);
pinADC(PortA, 1);
ADC1->CR2 =0;
ADC1->CR2 |=1;
while((ADC1->CR2 & 1)==0){}
ADC1->SQR3=1;
ADC1->CR2 |= 1;


while(1){
    ADC1->CR2 |=(1<<30);
    while((ADC1->SR &2)==0){}
    adcData=ADC1->DR;
    output=(3300*adcData)/4095;
}
}
