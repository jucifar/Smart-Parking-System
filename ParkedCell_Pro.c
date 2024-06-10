#include "STD_TYPES.h"
#include <util/delay.h>

#include "DIO_Interface.h"
#include "Stepper_Interface.h"


#define LIFTER_PORTUP         Port_A
#define LIFTER_PORTUP_DIRE    Pin0
#define LIFTER_PORTUP_STEP    Pin1
#define LIFTER_PORTUP_EN      Pin2

/* Define Stepper of Rotation Motion */
#define LIFTER_PORTROT         Port_A
#define LIFTER_PORTROT_DIRE    Pin3
#define LIFTER_PORTROT_STEP    Pin4
#define LIFTER_PORTROT_EN      Pin5

/* Define Stepper of Latch Motion */
#define LIFTER_PORT_LAT         Port_B
#define LIFTER_PORT_LAT_DIRE    Pin7
#define LIFTER_PORT_LAT_STEP    Pin6
#define LIFTER_PORT_LAT_EN        Pin5


/* Lifter Go Up The Specific Level */
void Lifter_VidGoUp( u16 Copy_u16NumOfSteps,u8 Copy_u8StepDelay, u8 Copy_u8Port, u8 Copy_u8DirePin,u8 Copy_u8Dire, u8 Copy_u8StepPin, u8 Copy_u8EnPin)
{
	/* enable on the motor*/
		Stepper_Enable(En_On,Copy_u8Port,Copy_u8EnPin);
		/*set the direction of the motor */
		Stepper_Direction(Copy_u8Dire,Copy_u8Port,Copy_u8DirePin);
		/* Set the desired number of the steps */
		Stepper_SetNumberOfStep(Copy_u16NumOfSteps,Copy_u8StepDelay,Copy_u8Port,Copy_u8StepPin);
		/* enable off the motor*/
		Stepper_Enable(En_Off,Copy_u8Port,Copy_u8EnPin);

}


/*Lifter Rotation Function */
void Lifter_VidRotating(u16 Copy_u16NumOfSteps,u8 Copy_u8StepDelay, u8 Copy_u8Port, u8 Copy_u8DirePin, u8 Copy_u8Dire,u8 Copy_u8StepPin, u8 Copy_u8EnPin)
{
    /* enable on the motor*/
	Stepper_Enable(En_On,Copy_u8Port,Copy_u8EnPin);
	/*set the direction of the motor */
	Stepper_Direction(Copy_u8Dire,Copy_u8Port,Copy_u8DirePin);
	/* Set the desired number of the steps */
	Stepper_SetNumberOfStep(Copy_u16NumOfSteps,Copy_u8StepDelay,Copy_u8Port,Copy_u8StepPin);
	/* enable off the motor*/
	Stepper_Enable(En_Off,Copy_u8Port,Copy_u8EnPin);

}

/* latch go through the cell to park the car */
void LifterLatch_VidGoPark(u16 Copy_u16NumOfSteps,u8 Copy_u8StepDelay, u8 Copy_u8Port, u8 Copy_u8DirePin,u8 Copy_u8Dire, u8 Copy_u8StepPin, u8 Copy_u8EnPin)
{
	    /* enable on the motor*/
		Stepper_Enable(En_On,Copy_u8Port,Copy_u8EnPin);
		/*set the direction of the motor */
		Stepper_Direction(Copy_u8Dire,Copy_u8Port,Copy_u8DirePin);
		/* Set the desired number of the steps */
		Stepper_SetNumberOfStep(Copy_u16NumOfSteps,Copy_u8StepDelay,Copy_u8Port,Copy_u8StepPin);
		/* enable off the motor*/
		Stepper_Enable(En_Off,Copy_u8Port,Copy_u8EnPin);

}

/* Start Parking function latch by pulling the car */
void LifterLatch_VidStartPark(u16 Copy_u16NumOfSteps,u8 Copy_u8StepDelay, u8 Copy_u8Port, u8 Copy_u8DirePin,u8 Copy_u8Dire, u8 Copy_u8StepPin, u8 Copy_u8EnPin)
{
	    /* enable on the motor*/
		Stepper_Enable(En_On,Copy_u8Port,Copy_u8EnPin);
		/*set the direction of the motor */
		Stepper_Direction(Copy_u8Dire,Copy_u8Port,Copy_u8DirePin);
		/* Set the desired number of the steps */
		Stepper_SetNumberOfStep(Copy_u16NumOfSteps,Copy_u8StepDelay,Copy_u8Port,Copy_u8StepPin);
		/* enable off the motor*/
		Stepper_Enable(En_Off,Copy_u8Port,Copy_u8EnPin);
}

/* Return home */
void Lifter_VidReturnHome(u16 Copy_u16NumOfSteps,u8 Copy_u8StepDelay, u8 Copy_u8Port, u8 Copy_u8DirePin,u8 Copy_u8Dire, u8 Copy_u8StepPin, u8 Copy_u8EnPin)
{
	LifterLatch_VidStartPark( Copy_u16NumOfSteps,Copy_u8StepDelay, Copy_u8Port, Copy_u8DirePin, Copy_u8Dire,  Copy_u8StepPin,  Copy_u8EnPin);
	  _delay_ms(100);
    Lifter_VidRotating(Copy_u16NumOfSteps,Copy_u8StepDelay, Copy_u8Port, Copy_u8DirePin, Copy_u8Dire,  Copy_u8StepPin,  Copy_u8EnPin);
	  _delay_ms(100);
	Lifter_VidGoUp(Copy_u16NumOfSteps,Copy_u8StepDelay, Copy_u8Port, Copy_u8DirePin, Copy_u8Dire,  Copy_u8StepPin,  Copy_u8EnPin);
     _delay_ms(100);
    LifterLatch_VidGoPark(Copy_u16NumOfSteps,Copy_u8StepDelay, Copy_u8Port, Copy_u8DirePin, Copy_u8Dire,  Copy_u8StepPin,  Copy_u8EnPin);
     _delay_ms(50);

}


/* Park in the selected section */

void Cell_VidParking(u8 Copy_u8NumCell)
{
switch(Copy_u8NumCell)
{
     case '1': LifterLatch_VidStartPark(25,100,Port_A,Pin7,Clockwise,Pin6,Pin5);
               _delay_ms(100);
               Lifter_VidGoUp(4000,10,Port_D,Pin5,AntiClockwise,Pin6,Pin7);
               _delay_ms(100);
               Lifter_VidRotating(50,100,Port_D,Pin2,Clockwise,Pin3,Pin4);
               _delay_ms(100);
               LifterLatch_VidGoPark(25,100,Port_A,Pin7,Clockwise,Pin6,Pin5);
                _delay_ms(100);
               Lifter_VidGoUp(200,10,Port_D,Pin5,Clockwise,Pin6,Pin7);
                 _delay_ms(100);
                 break;

}


}

/* Leave the selected section */
/*void Cell_VidLeaving(u8 Copy_u8NumCell)
{




}
*/





