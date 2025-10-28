#include "stm32f10x.h"                  // Device header
void LedInit(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef gpio_struct;
	gpio_struct.GPIO_Mode=GPIO_Mode_Out_PP;
	gpio_struct.GPIO_Speed=GPIO_Speed_50MHz;
	gpio_struct.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_2;
	GPIO_Init(GPIOA,&gpio_struct);
}
void Led1TurnOn(void){
	
	GPIO_SetBits(GPIOA,GPIO_Pin_0);

}
void Led1TurnOff(void){
	GPIO_ResetBits(GPIOA,GPIO_Pin_0);

}
void Led1Switch(void){
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)){
		Led1TurnOff();
	}else{
		Led1TurnOn();
	}
}
void Led2TurnOn(void){
	GPIO_SetBits(GPIOA,GPIO_Pin_2);

}
void Led2TurnOff(void){
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);

}
void Led2Switch(void){
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2)){
		Led2TurnOff();
	}else{
		Led2TurnOn();
	}
}
