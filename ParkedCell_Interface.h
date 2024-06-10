#ifndef PARKEDCELL_INTERFACE_H_
#define PARKEDCELL_INTERFACE_H_

/* Define Stepper of vertical Motion */





/* Park in the selected section */

void Cell_VidParking(u8 Copy_u8NumCell);
/* Lifter Go Up The Specific Level */
void Lifter_VidGoUp(u16 Copy_u16NumOfSteps,u8 Copy_u8StepDelay, u8 Copy_u8Port, u8 Copy_u8DirePin, u8 Copy_u8Dire,u8 Copy_u8StepPin, u8 Copy_u8EnPin);
/*Lifter Rotation Function */
void Lifter_VidRotating(u16 Copy_u16NumOfSteps,u8 Copy_u8StepDelay, u8 Copy_u8Port, u8 Copy_u8DirePin, u8 Copy_u8Dire, u8 Copy_u8StepPin, u8 Copy_u8EnPin);
/* latch go through the cell to park the car */
void LifterLatch_VidGoPark(u16 Copy_u16NumOfSteps,u8 Copy_u8StepDelay, u8 Copy_u8Port, u8 Copy_u8DirePin, u8 Copy_u8Dire, u8 Copy_u8StepPin, u8 Copy_u8EnPin);

/* Start Parking function latch by pulling the car */
void LifterLatch_VidStartPark(u16 Copy_u16NumOfSteps,u8 Copy_u8StepDelay, u8 Copy_u8Port, u8 Copy_u8DirePin, u8 Copy_u8Dire, u8 Copy_u8StepPin, u8 Copy_u8EnPin);

/*Return home Lifter Function */
void Lifter_VidReturnHome(void);

/* Leave the selected section */
/*void Cell_VidLeaving(u8 Copy_u8NumCell);*/



#endif
