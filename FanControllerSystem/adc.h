/******************************************************************************
 *
 * Module: ADC
 * File Name: adc.h
 * Description: Header file for the AVR ADC driver
 * Author: Mohamed Magdy
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "lcd.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include "std_types.h"
#include "gpio.h"
#include "avr/io.h"		   /* To use ADC Registers */
#include <avr/interrupt.h> /* For ADC ISR */

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE 1023
#define ADC_REF_VOLT_VALUE 2.56

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum
{
	AREF,
	AVCC,
	Reserved,
	Internal_Ref
} ADC_REF_VOLTAGE;

typedef enum
{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
} ADC_ANALOG_CHANNEL;

typedef enum
{
	F_CPU_2_1,
	F_CPU_2_2,
	F_CPU_4,
	F_CPU_8,
	F_CPU_16,
	F_CPU_32,
	F_CPU_64,
	F_CPU_128
} ADC_ClockType;

typedef struct
{
	ADC_REF_VOLTAGE V_reference;
	ADC_ANALOG_CHANNEL ch_number;
	ADC_ClockType clock;
} ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver Based on configurations.
 */

void ADC_init(const ADC_ConfigType *Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */

uint16 ADC_readChannel(uint8 ch_num);

#endif /* ADC_H_ */
