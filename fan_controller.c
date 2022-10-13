/*
 ================================================================================================
 Name        : fan_controller.c
 Author      : Nada
 Description : Main Application of a fan controller.
 Date        : Oct 7, 2022
 ================================================================================================
 */

#include "motor.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "adc.h"

uint8 fan_state = STOP;
uint8 static temp = 0;
uint8 static speed = 0;

/*
 * Description:
 * Get temperature of sensor, according to temperature determine fan state and its speed.
 */

void APP_fanControl(void) {
	temp = LM35_getTemperature();
	if (temp < 30) {
		fan_state = STOP;
		speed = 0;
	} else if (temp >= 30 && temp < 60) {
		fan_state = CW;
		speed = 25;
	} else if (temp >= 60 && temp < 90) {
		fan_state = CW;
		speed = 50;
	} else if (temp >= 90 && temp < 120) {
		fan_state = CW;
		speed = 75;
	} else {
		fan_state = CW;
		speed = 100;
	}
	DcMotor_Rotate(fan_state, speed);
}

int main() {
	/*ADC chosen configurations*/
	ADC_ConfigType ADC_Config = { DIVISION_FACTOR_8, INTERNAL_REFTANCE_VOLTAGE };
	ADC_init(&ADC_Config);
	LCD_init();
	DcMotor_Init();

	/* display current state and temperature on LCD screen */
	LCD_moveCursor(0, 3);
	LCD_displayString("Fan is ");
	LCD_moveCursor(1, 3);
	LCD_displayString("Temp =    C");

	while (1) {
		/* update state according to temperature */
		APP_fanControl();
		/* Display continuously on LCD screen */
		LCD_moveCursor(0, 10);
		if (fan_state == STOP) {
			LCD_displayString("OFF");
		} else {
			LCD_displayString("ON");
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
		LCD_moveCursor(1, 10);
		if (temp >= 100) {
			LCD_intgerToString(temp);
		} else {
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
	}
	return 0;
}
