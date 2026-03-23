#include "gpio.h"
#include "time.h"

void ImportantSetupToMakePinReady(void);
int i,j;

int main(void){
   ImportantSetupToMakePinReady();
   
unsigned char myByte=0b0000U;
GPIOA->ODR=myByte;
while (1){
	
unsigned char m_bit=0;
for(int a=0;a<10;a++){
for(int i=0;i<4;i++){
   m_bit=i;
GPIOA->ODR|=(1<<m_bit);
DelayMs(300);
GPIOA->ODR&=~(1<<m_bit);
DelayMs(300);
}
}

for(int i=0;i<10;i++){
GPIOA->ODR= 0b1010U;

DelayMs(200);
GPIOA->ODR = 0b0101U;

DelayMs(200);
}
GPIOA->ODR=0b0000U;
DelayMs(200);


}

}



void ImportantSetupToMakePinReady(void){
	PinOutputSet(PA0);
	PinOutputSet(PA1);
	PinOutputSet(PA2);
	PinOutputSet(PA3);
	PinOutputSet(PA4);
	PinOutputSet(PA5);
	PinOutputSet(PA6);
	PinOutputSet(PA7);
}

