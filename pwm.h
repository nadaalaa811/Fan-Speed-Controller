/******************************************************************************
 *
 * Module: PWM Signal
 *
 * File Name: pwm.h
 *
 * Description: header file for PWM driver
 *
 * Author: Nada
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
 * Description:
 * Generate a PWM signal with Timer0 using PWM Mode
 */
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
