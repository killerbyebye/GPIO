#include "stm32f10x.h"                  // Device header
#include "Led.h"
#include "Button.h"
#include "OLED.h"
#include "Delay.h"
int main(void){
	OLED_Init();
	LedInit();
	ButtonInit();
	uint8_t one=1;
	uint8_t two=1;
	OLED_ShowString(1,1,"Button1:");
	OLED_ShowString(2,1,"Button2:");
	while(1){
		one=getButton1Value();
		two=getButton2Value();
		OLED_ShowBinNum(1,9,one,1);
		OLED_ShowBinNum(2,9,two,1);
		delayByMs(100);
		if(!one){
			Led1Switch();
		}
		if(!two){
			Led2Switch();
		}
	}
}
	
