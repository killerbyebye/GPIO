#include "stm32F10x.h"
void delayByUs(uint16_t us){
	SysTick->CTRL=0x00000005;
	SysTick->VAL=0;
	SysTick->LOAD=72*us-1;
	while(!(SysTick->CTRL & 0x00010000)){}
	SysTick->CTRL=0;
}
void delayByMs(uint16_t ms){
	if(ms==0){
		return;
	}
	while(ms--){
		delayByUs(1000);
	}
}
void delayByS(uint16_t s){
	if(s==0){
		return;
	}
	while(s--){
		delayByMs(1000);
	}
}
