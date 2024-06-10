#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include  <util/delay.h>
#include "Stepper_Interface.h"


void Stepper_Setup(u8 Copy_u8Port, u8 Copy_u8Dire_Pin, u8 Copy_u8Step_Pin, u8 Copy_u8EN_Pin )
{   /* Set DIRECTION_PIN, STEP_PIN and EN_PIN as output */
	DIO_VidSetPinDirection(Copy_u8Port,Copy_u8Dire_Pin,Output);
	DIO_VidSetPinDirection(Copy_u8Port,Copy_u8Step_Pin,Output);
	DIO_VidSetPinDirection(Copy_u8Port,Copy_u8EN_Pin,Output);

}


void Stepper_Direction(u8 Copy_u8Direction,u8 Copy_u8Port, u8 Copy_u8Dire_Pin )
{ /*Select The Direction Of Rotation */
	if(Copy_u8Direction == Clockwise)
	{
		DIO_VidSetPinValue(Copy_u8Port,Copy_u8Dire_Pin,PinHigh);
	}

	else if(Copy_u8Direction == AntiClockwise)
		{
			DIO_VidSetPinValue(Copy_u8Port,Copy_u8Dire_Pin,PinLow);
		}
}

/* Generate Only One Step */
void Stepper_Step(u8 Copy_u8Port, u8 Copy_u8Step_Pin)
{
	DIO_VidSetPinValue(Copy_u8Port,Copy_u8Step_Pin,PinHigh);
	_delay_us(2);
	DIO_VidSetPinValue(Copy_u8Port,Copy_u8Step_Pin,PinLow);
	_delay_us(2);
}
/* Generate a chain of steps with delay */
void Stepper_SetNumberOfStep(u16 Copy_u16NumSteps, u16 Copy_u16DelayBetweenSteps,u8 Copy_u8Port, u8 Copy_u8Step_Pin)
{
	for(u16 i =0 ; i<Copy_u16NumSteps; i++)
	{
		Stepper_Step(Copy_u8Port,Copy_u8Step_Pin);
		_delay_ms(Copy_u16DelayBetweenSteps);
	}

}
/* Set A Status Of Motor On / Off */
void Stepper_Enable(u8 Copy_u8enable,u8 Copy_u8Port, u8 Copy_u8EN_Pin)
{

  if(Copy_u8enable == En_On)
	{
	  DIO_VidSetPinValue(Copy_u8Port,Copy_u8EN_Pin,PinLow);
	}

  if(Copy_u8enable == En_Off)
	{
	  DIO_VidSetPinValue(Copy_u8Port,Copy_u8EN_Pin,PinHigh);
	}

}
