 /******************************************************************************
 *
 * Project Name: FanControllerSystem
 *
 * File Name: dcMotor.h
 *
 * Description: Source file for DC-MOTOR
 *
 * Author: Mohamed Magdy
 *
 *******************************************************************************/

#ifndef DCMOTOR_H_
#define DCMOTOR_H_



/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#include "gpio.h"
#include <avr/io.h>
#include "std_types.h"





/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum{
	CW,A_CW,stop
}DcMotor_State;






/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * The Function responsible for setup the direction for the two
 * motor pins through the GPIO driver.
 * Stop at the DC-Motor at the beginning through the GPIO driver.
 */

void DcMotor_Init(void);


/*
 * Description :
 * The function responsible for rotate the DC Motor CW/ or A-CW or
 * stop the motor based on the state input state value.
 * Send the required duty cycle to the PWM driver based on the
 * required speed value.
 */

void DcMotor_Rotate(DcMotor_State state, uint8 speed);


/*
 * Description:
 * Generate a PWM signal with frequency 500Hz
 * Timer0 will be used with pre-scaler F_CPU/8
 * F_PWM=(F_CPU)/(256*N) = (10^6)/(256*8) = 500Hz
 * Duty Cycle can be changed by updating the value
 * in The Compare Register
 */

void PWM_Timer0_Start(uint8 duty_cycle);


#endif /* DCMOTOR_H_ */
