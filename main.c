#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "GIE_Int.h"
#include "DIO_Interface.h"
#include "USART_Int.h"
#include "Stepper_Interface.h"

void Parking_Mode();
void Leaving_Mode();
u8 Local_u8Mode=0;
u8 Bug=0;

int main()
{
    /* Stepper Motor Initialization */
	Stepper_Setup(Port_D,Pin2,Pin3,Pin4); //  Pin0 >>> Direction,  Pin1 >>> Step,  Pin2 >>> Enable
	Stepper_Setup(Port_D,Pin5,Pin6,Pin7);
	Stepper_Setup(Port_A,Pin7,Pin6,Pin5);
	/* Global Interrupt enable */
		   GIE_VidEnable();

    /*USART Initialization */
	   DIO_VidSetPinDirection(Port_D,Pin0,Input);
	   DIO_VidSetPinDirection(Port_D,Pin1,Output);
	   USART_VidIniti();

	while(1){

	    /* Select mode  */
	 	USART_VidSendString("\n************ Welcome To Smart Park **************\n");
	 	USART_VidSendString("Choose your mode\n  a- For Park Mode\n  b- Leaving Mode\n ");
	 	USART_VidSendString("*************************************************\n");


	 	Local_u8Mode=USART_VidReceiveChar();
	 	Bug=USART_VidReceiveChar();
	 	Bug=USART_VidReceiveChar();
	 	switch(Local_u8Mode)
	 	{
	 	  case 'a': Parking_Mode();break;




	 /*default: USART_VidSendString("*********** Worng_Input ***********\n");break;*/
	 	}

	}



}

/* Implementation of parking function */
void Parking_Mode()
{
	u8 Local_u8Cell =0;
	USART_VidSendString("\n************ Park_Mode **************\n");
	USART_VidSendString("\n Available Cells:\n   - 1\n - 2\n - 3");
	USART_VidSendString("\nPlease Select The Desired Cell :\n");
	Local_u8Cell=USART_VidReceiveChar();
	Bug=USART_VidReceiveChar();
	Bug=USART_VidReceiveChar();
	while(Local_u8Cell==0);
 Cell_VidParking(Local_u8Cell);
}



