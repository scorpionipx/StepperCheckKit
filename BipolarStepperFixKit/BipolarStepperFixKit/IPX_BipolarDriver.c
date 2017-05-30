/*
 * IPX_BipolarDriver.c
 *
 * Created: 29-May-17 10:41:49 AM
 *  Author: ScorpionIPX
 */ 

#include "Global.h"
#include "IPX_BipolarDriver.h"
#include <util/delay.h>


void init_bipolar_control(void)
{
	MOTOR_DDR |= (1 << MOTOR_COIL_A_POSITIVE) | (1 << MOTOR_COIL_A_NEGATIVE) | (1 << MOTOR_COIL_B_POSITIVE) | (1 << MOTOR_COIL_B_NEGATIVE);
	MOTOR_PORT &= ~((1 << MOTOR_COIL_A_POSITIVE) | (1 << MOTOR_COIL_A_NEGATIVE) | (1 << MOTOR_COIL_B_POSITIVE) | (1 << MOTOR_COIL_B_NEGATIVE));
}

void bipolar_four_steps_forward()
{
	unsigned int STEP_DELAY_MS = 50;
	
	MOTOR_STEP_1;
	
	_delay_ms(STEP_DELAY_MS);
	
	MOTOR_STEP_2;
	
	_delay_ms(STEP_DELAY_MS);
	
	MOTOR_STEP_3;
	
	_delay_ms(STEP_DELAY_MS);
	
	MOTOR_STEP_4;
	
	_delay_ms(STEP_DELAY_MS);
	
	/* CONTROL OFF */
	MOTOR_OFF;
	
}

void bipolar_drive_forward()
{
	unsigned int STEP_DELAY_MS = 500;
	
	MOTOR_STEP_1;
	_delay_ms(STEP_DELAY_MS);
	
	MOTOR_STEP_2;
	_delay_ms(STEP_DELAY_MS);
	
	MOTOR_STEP_3;
	_delay_ms(STEP_DELAY_MS);
	
	MOTOR_STEP_4;
	_delay_ms(STEP_DELAY_MS);
}