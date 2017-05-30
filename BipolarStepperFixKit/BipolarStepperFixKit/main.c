/*
 * BipolarStepperFixKit.c
 *
 * Created: 29-May-17 9:59:12 AM
 * Author : ScorpionIPX
 */ 

#include "Global.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "IPX_Interrupt.h"
#include "IPX_LCD_Display.h"
#include "IPX_BipolarDriver.h"

void init_uC(void);

int main(void)
{
	init_uC();
	
    while (1) 
    {
	    bipolar_drive_forward();
    }
}


void init_uC(void)
{
	STATE = STATE_INITIALIZING;
	
	STATEs[0] = STATE_INITIALIZING;
	STATEs[1] = STATE_APP_TITLE;
	STATEs[2] = STATE_MAIN_MENU;
	STATEs[3] = STATE_UNDEFINED;
	STATEs[4] = STATE_UNDEFINED;
	STATEs[5] = STATE_UNDEFINED;
	STATEs[6] = STATE_UNDEFINED;
	STATEs[7] = STATE_UNDEFINED;
	STATEs[8] = STATE_UNDEFINED;
	STATEs[9] = STATE_UNDEFINED;
	
	init_bipolar_control();
	init_LCD_Display();
	init_interrupt_200ms();
	
	_delay_ms(20);
	
	display_initializing_message();
	_delay_ms(500);
	
	STATE = STATE_APP_TITLE;
	display_application_title();
	
	_delay_ms(1000);
	
	sei();
}
