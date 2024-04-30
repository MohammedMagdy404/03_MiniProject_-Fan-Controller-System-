 /******************************************************************************
 *
 * Module: ADC
 * File Name: adc.c
 * Description: Source file for the AVR ADC driver
 * Author: Mohamed Magdy
 *
 *******************************************************************************/

#include "adc.h"


void ADC_init(const ADC_ConfigType * Config_Ptr){
	ADMUX |= ((Config_Ptr->V_reference)<<6);

	// Choose the ADC0 as default channel
	ADMUX |= (Config_Ptr->ch_number);
	// Enable the ADC
	SET_BIT(ADCSRA,ADEN);
	/*
	//Disable ADC Interrupts
	CLEAR_BIT(ADCSRA,ADIE);
	*/
	//Adjust PreScaler
	ADCSRA |= (Config_Ptr->clock);
}


uint16 ADC_readChannel(uint8 ch_num){
	// set channel number
	ADMUX = (ADMUX & 0xE0) | (ch_num & 0x1F);

	// Start the conversion
	SET_BIT(ADCSRA,ADSC);

	// Polling Until ADIF = 1
	while(BIT_IS_CLEAR(ADCSRA,ADIF));

	// clear flag ADIF
	SET_BIT(ADCSRA, ADIF);

	// return DATA in ADC register
	return ADC;
}
