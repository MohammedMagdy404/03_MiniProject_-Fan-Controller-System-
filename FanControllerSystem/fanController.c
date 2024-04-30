/******************************************************************************
 *
 * Project Name: FanControllerSystem
 *
 * File Name: fanController.c
 *
 * Description: Source file for Fan Controller System Project
 *
 * Author: Mohamed Magdy
 *
 *******************************************************************************/

#include "fanController.h"


uint8 temp_value;
uint8 speed_value;

int main(void){

	/* Create configuration structure for ADC driver */
	ADC_ConfigType ADC_Configurations = {Internal_Ref, ADC2, F_CPU_8};

	LCD_init(); /* initialize LCD driver */
	ADC_init(&ADC_Configurations); /* initialize ADC driver */
	DcMotor_Init(); /* initialize DC_MOTOR driver */

	LCD_displayString("    FAN IS OFF  ");

	while(1){
		temp_value = LM35_getTemperature();

		LCD_moveCursor(1,0);
		LCD_displayString("    Temp = ");
		LCD_intgerToString(temp_value);
		LCD_displayString(" C");

		//		DcMotor_Rotate(CW, 128);

		// Motor Adjustment
		if(temp_value < 30)
		{
			speed_value = 0;
			DcMotor_Rotate(stop, speed_value);
		}
		else if(temp_value >= 90)
		{
			speed_value = (75/25) * 64;
			DcMotor_Rotate(CW, speed_value);
		}
		else
		{
			/*
			 * configure the speed to be increase based on the temperature value
			 * if 30C then speed = 30 * (5/6) = 25/25 *64
			 * if 60C then speed = 60 * (5/6) = 50/25 *64
			 */
			//			speed_value = (temp_value * (5/6))/25 * 64; ---> this is wrong cause 5/6 = 0
			speed_value = ((temp_value / 6) * 5)/25.0 * 64;
			DcMotor_Rotate(CW, speed_value);
		}

		/*
		else if(temp_value >= 60){
			speed_value = 50;
			DcMotor_Rotate(CW, speed_value);
		}else{
			speed_value = 25;
			DcMotor_Rotate(CW, speed_value);
		}
		 */


		// LCD Adjustment
		if(speed_value == 0){

			LCD_moveCursor(0,0);
			LCD_displayString("    FAN IS OFF  ");
		}
		else{

			LCD_moveCursor(0,0);
			LCD_displayString("    FAN IS ON  ");
		}

	}

}
