/*
 * pwd_timer0.c
 *
 *  Created on: Oct 9, 2022
 *      Author: mohammedhamdy32
 */

#include "pwm_timer0.h"
#include "gpio.h"
#include "common_macros.h"
#include "avr/io.h"

void PWM_Timer0_Start(uint8 duty_cycle)
{
	GPIO_setupPinDirection(PORTB_ID , PIN3 , OUTPUT);

	SET_BIT(TCCR0,WGM00); /*Waveform Generation Mode is Fast PWM */
	SET_BIT(TCCR0,WGM01);

	SET_BIT(TCCR0,COM01); /*Non_inverting PWM mode */

	SET_BIT(TCCR0,CS01); /*8_prescaler */

	TCNT0=0;

	SET_BIT(TIMSK,OCIE0); /*open intrrupt*/

	OCR0 = 255*((float)duty_cycle/100.0) ; /*to change the duty cycle percent to compare mode value*/

}
