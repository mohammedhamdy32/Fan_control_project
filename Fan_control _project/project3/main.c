/*
 ======================================================================================
 Name        : potentiometer.c
 Author      : Mohamed Tarek
 Description : Test the ADC driver designed with polling technique using potentiometer
 Date        : 18/6/2017
 ======================================================================================
 */
#include "ADC.h"
#include "lcd.h"
#include "avr/io.h"
#include "dc_motor.h"
#include "pwm_timer0.h"
#include "lm35_sensor.h"

int main(void)
{
	/*ADC*/
	ADC_ConfigType ADC_Conf = {INTERNAL_VOLT,Division_Factor_8};
	ADC_init(&ADC_Conf);
	/*DC_motor*/
	DcMotor_Init();
	DcMotor_Rotate(CLOCK_WISE , 50);
	/*LCD*/
	LCD_init();
	SREG |= (1<<7); /*set I bit*/
	/*PWM*/

	int temp;
	LCD_writeString("The fan is ");
	LCD_moveCursor(1, 0);
	LCD_writeString("The temp = ");
	while(1)
	{
		temp = LM35_getTemperature();
		if(temp <30)
		{
			LCD_moveCursor(0, 11);
			LCD_writeString("OFF");
			DcMotor_Rotate(STOP,0);

		}else if( temp>=30 && temp<60)
		{
			LCD_moveCursor(0, 11);
			LCD_writeString("ON ");
			DcMotor_Rotate(CLOCK_WISE,25);
		}else if( temp>=60 && temp<90)
		{
			LCD_moveCursor(0, 11);
			LCD_writeString("ON");
			DcMotor_Rotate(CLOCK_WISE,50);
		}else if(temp>=90 && temp<120)
		{
			LCD_moveCursor(0, 11);
			LCD_writeString("ON");
			DcMotor_Rotate(CLOCK_WISE,75);
		}else
		{
			LCD_moveCursor(0, 11);
			LCD_writeString("ON");
			DcMotor_Rotate(CLOCK_WISE,100);
		}

		LCD_moveCursor(1, 11);

		if( temp >= 100)
		{
			LCD_integerToString(temp);
		}
		else
		{
			LCD_integerToString(temp);
			LCD_writeChar(' ');

		}
	}
}


