/*
 * ADC.c
 *
 *  Created on: Oct 6, 2022
 *      Author: mohammedhamdy32
 */

#include "ADC.h"
#include "common_macros.h"
#include "avr/io.h" /* To use the IO Ports Registers */


void ADC_init(ADC_ConfigType *Config_ptr)
{

	ADMUX = (ADMUX & 0x3F) | ( (Config_ptr->ref_volt)<<6 ); //copy ref_volt in ADMUX

	SET_BIT(ADCSRA,ADEN); // make ADC enable

	ADCSRA = (ADCSRA & 0xF8) | (Config_ptr->prescaler) ; /*copy the prescaler in  ADCSRA */

}



uint16 ADC_readChannel(uint8 channel)
{

    //ADMUX = (ADMUX | channel);
	ADMUX = (channel & 0x07) | (ADMUX & 0XE0);
	SET_BIT(ADCSRA,ADSC); //start Conversion
	while( BIT_IS_CLEAR(ADCSRA,ADIF) ); //polling

	SET_BIT(ADCSRA,ADIF); //TO clear the flage

	return ADC;
}
