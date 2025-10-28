#include "stm32f10x.h"                  // Device header
#include "Delay.h"
void ButtonInit(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef gpio_struct;
	gpio_struct.GPIO_Mode=GPIO_Mode_IPU;
	gpio_struct.GPIO_Speed=GPIO_Speed_50MHz;
	gpio_struct.GPIO_Pin=GPIO_Pin_13|GPIO_Pin_15;
	GPIO_Init(GPIOB,&gpio_struct);
}
uint8_t getButton1Value(void){
	uint8_t num=1;
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13)==0){
		delayByMs(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13)==0){}
		delayByMs(20);
		num=0;
	}
	return num;

}
uint8_t getButton2Value(void){
	uint8_t num=1;
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15)==0){
		delayByMs(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15)==0){}
		delayByMs(20);
		num=0;
	}
	return num;

}
