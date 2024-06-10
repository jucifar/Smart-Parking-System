#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

typedef enum
{
  Clockwise,
  AntiClockwise
}Directions;

typedef enum
{
  En_Off,
  En_On
}Enable;

/* Set DIRECTION_PIN, STEP_PIN and EN_PIN as output */
void Stepper_Setup(u8 Copy_u8Port, u8 Copy_u8Dire_Pin, u8 Copy_u8Step_Pin, u8 Copy_u8EN_Pin );

/*Select The Direction Of Rotation */
void Stepper_Direction(u8 Copy_u8Direction,u8 Copy_u8Port, u8 Copy_u8Dire_Pin );
/* Generate Only One Step */
void Stepper_Step(u8 Copy_u8Port, u8 Copy_u8Step_Pin);
/* Generate a chain of steps with delay */
void Stepper_SetNumberOfStep(u16 Copy_u16NumSteps, u16 Copy_u16DelayBetweenSteps,u8 Copy_u8Port, u8 Copy_u8Step_Pin);
/* Set A Status Of Motor On / Off */
void Stepper_Enable(u8 Copy_u8enable,u8 Copy_u8Port, u8 Copy_u8EN_Pin);


#endif
