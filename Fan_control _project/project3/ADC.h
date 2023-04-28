/*
 * ADC.h
 *
 *  Created on: Oct 6, 2022
 *      Author: mohammedhamdy32
 */



#ifndef ADC_H_
#define ADC_H_

#include "gpio.h"
#include "lcd.h"
#include "std_types.h"

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

typedef enum{
	VOLT_5,EXTERNAL_VOLT,INTERNAL_VOLT=3
}ADC_ReferenceVolatge;

typedef enum{
	Division_Factor_2A,Division_Factor_2B,Division_Factor_4,Division_Factor_8,
	Division_Factor_16,Division_Facto_32,Division_Factor_64,Division_Factor_128
}ADC_Prescaler;

typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

void ADC_init(ADC_ConfigType *Config_ptr);

//uint16 ADC_readChannel(uint8 channel);
uint16 ADC_readChannel(uint8 channel);



#endif
