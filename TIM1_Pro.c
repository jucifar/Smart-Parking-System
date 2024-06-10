#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "TIM1_Reg.h"
#include "TIM1_Private.h"


/* This function generate flag after 1 micro sec */
void TIMER1_VidInit_CTCMode(void)
{
	    /* SET CTC WITH TOP OCR1A*/
		SET_BIT(TCCR1B,TCCR1B_WGM12);
		/*Set Timer1 to count 1 micro sec */
		OCR1AL=1;
		/*SET Pre-scaler value divided by 8 */
		TCCR1B &= 0b11111000; // clear pre-scaler
		TCCR1B |= 2;
}

void Timer1_SetCTC_OCR1A_Value(u16 Copy_u16OCR1A_Value)
{
	OCR1AL=Copy_u16OCR1A_Value;
}


 /* Function with micro delay */
void Timer1_SetDelay_Micro(u32 Copy_DelayValue)
{
	TCNT1L = 0;                                  // Reset Timer1 counter
	TIFR |= (1 << TIFR_OCF1A);                   // Clear Timer1 compare match flag
	for(u32 i=0;i<Copy_DelayValue;i++)
	{
		while(((TIFR>>TIFR_OCF1A)&(0x01)) == 0); // Check flag if 1 then 1 micro sec it passed
		TIFR |=(1<<TIFR_OCF1A);                  // Clear Timer1 compare match flag
	}

	TCCR1B &= ~(1 << TCCR1B_CS12);  // Turn off Timer1
}

