/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Nada
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_INTERNAL_REF_VOLT_VALUE  2.56

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum {
	DIVISION_FACTOR_2,
	DIVISION_FACTOR__2,
	DIVISION_FACTOR_4,
	DIVISION_FACTOR_8,
	DIVISION_FACTOR_16,
	DIVISION_FACTOR_32,
	DIVISION_FACTOR_64,
	DIVISION_FACTOR_128
} ADC_Prescaler;

typedef enum {
	AREF, AVCC, RESERVED, INTERNAL_REFTANCE_VOLTAGE
} ADC_ReferenceVolatge;

typedef struct {
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
} ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType *Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
