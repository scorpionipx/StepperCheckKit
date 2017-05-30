#ifndef GLOBAL_H_
#define GLOBAL_H_

/* Includes */
/*============================================================================*/

/* Constants and types */
/*============================================================================*/
#define F_CPU		16000000L //clock freq-must be define before including util/delay.h

#define FALSE 0
#define TRUE 1


// GLOBAL STRUCT FOR BOOLEAN VARIABLES; USE BIT FIELDS TO IMPROVE MEMORY USAGE
struct boolean_struct
{
	unsigned int BOOL_0 : 1;
	unsigned int BOOL_1 : 1;
	unsigned int BOOL_2 : 1;
	unsigned int BOOL_3 : 1;
	unsigned int BOOL_4 : 1;
	unsigned int BOOL_5 : 1;
	unsigned int BOOL_6 : 1;
	unsigned int BOOL_7 : 1;
}GLOBAL_BOOL;

#define BUTTON_1_PRESSED GLOBAL_BOOL.BOOL_0   // BUTTON ONE PRESSED
#define BUTTON_2_PRESSED GLOBAL_BOOL.BOOL_1   // BUTTON TWO PRESSED

// Menus 
#define STATE_UNDEFINED      -1     // SHOULD NEVER OCCUR
#define STATE_INITIALIZING    0     // SHOULD BE ACTIVE LESS THAN A SECOND WHEN POWERING THE uC, AND NEVER REACHED AGAIN
#define STATE_APP_TITLE       1     // INDICATES A SUCCESSFULLY INITIALIZATION
#define STATE_MAIN_MENU       2     // ALLOWS USER TO CHOOSE NEXT ACTION



typedef signed char sint8;
typedef unsigned char uint8;
typedef signed int sint16;
typedef unsigned int uint16;
typedef signed long sint32;
typedef unsigned long uint32;

/* Exported Variables */
/*============================================================================*/

char STATE;
char STATEs[10];

#endif /* GLOBAL_H_ */ 

/* Notice: the file ends with a blank new line to avoid compiler warnings */
