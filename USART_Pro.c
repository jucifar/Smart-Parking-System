/************************************************************************/
/************************************************************************/
/**************     Author : Ahmed Atef Osman      **********************/
/**************     SWC : USART_Driver             **********************/
/**************     Layer: MCAL                    **********************/
/**************     Date : 28 / OCT / 2022         **********************/
/**************     Version : V1.0                 **********************/
/************************************************************************/
/************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_Reg.h"
#include "USART_Private.h"
#include "USART_Config.h"
#include <util/delay.h>

void USART_VidIniti(void){
	u8 Local_u8UCSRC=0b10000000;
/*Select Synchronization mode*/
#if  SYNCHRO_MODE == DISABLE
	CLR_BIT(Local_u8UCSRC,UCSRC_UMSEL);
#elif SYNCHRO_MODE == ENABLE
	SET_BIT(Local_u8UCSRC,UCSRC_UMSEL);
#endif
	/*Character Size Mode*/
#if CHAR_SIZE == DATA_5_BIT
	CLR_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
	CLR_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
#elif CHAR_SIZE == DATA_6_BIT
	CLR_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
#elif CHAR_SIZE == DATA_7_BIT
	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
	CLR_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
#elif CHAR_SIZE == DATA_8_BIT
	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
#elif CHAR_SIZE == DATA_9_BIT
	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
	SET_BIT(UCSRB,UCSRB_UCSZ2);
#endif
	/*select parity mode (Disable)*/
#if PARITY_CHECK == DISABLE
	CLR_BIT(Local_u8UCSRC,UCSRC_UPM0);
	CLR_BIT(Local_u8UCSRC,UCSRC_UPM1);
#elif CHAR_SIZE == ODD_PARITY
	SET_BIT(Local_u8UCSRC,UCSRC_UPM0);
	SET_BIT(Local_u8UCSRC,UCSRC_UPM1);
#elif CHAR_SIZE == EVEN_PARITY
	CLR_BIT(Local_u8UCSRC,UCSRC_UPM0);
	SET_BIT(Local_u8UCSRC,UCSRC_UPM1);
#endif
	/*Set stop bit selection*/
#if STOP_BIT == ONE_STOP_BITS
	CLR_BIT(Local_u8UCSRC,UCSRC_USBS);
#elif STOP_BIT == TWO_STOP_BITS
	SET_BIT(Local_u8UCSRC,UCSRC_USBS);
#endif
/*Clock Polarity In Synchr_Mode */
#if CLOCK_POLARITY == RISING_TX_FALLING_RX
	CLR_BIT(Local_u8UCSRC,UCSRC_UCPOL);
#elif CLOCK_POLARITY == FALLING_TX_RISING_RX
	SET_BIT(Local_u8UCSRC,UCSRC_UCPOL);
#endif

UCSRC=Local_u8UCSRC;
/************************************************ UCSRA ************************************************************/
     #if   USART_TX_SPEED == NORMAL
	   CLR_BIT(UCSRA,UCSRA_U2X);
     #elif  USART_TX_SPEED == DOUBLED
	   CLR_BIT(UCSRA,UCSRA_U2X);
     #endif
     #if  MULTI_PROCESSOR_MODE == DISABLE
	   CLR_BIT(UCSRA,UCSRA_MPCM);
     #elif  MULTI_PROCESSOR_MODE == ENABLE
	   SET_BIT(UCSRA,UCSRA_MPCM);
     #endif

/**************************************************** UCSRB *********************************************************/
    #if     USART_RX_INTERRUPT == DISABLE
            CLR_BIT(UCSRB,UCSRB_RXCIE);
    #elif   USART_RX_INTERRUPR == ENABLE
            SET_BIT(UCSRB,UCSRB_RXCIE);
    #endif

    #if     USART_TX_INTERRUPT == DISABLE
            CLR_BIT(UCSRB,UCSRB_TXCIE);
    #elif   USART_TX_INTERRUPR == ENABLE
            SET_BIT(UCSRB,UCSRB_TXCIE);
    #endif

    #if     USART_UDRE_INTERRUPT == DISABLE
            CLR_BIT(UCSRB,UCSRB_UDRIE);
    #elif   USART_UDRE_INTERRUPT == ENABLE
            SET_BIT(UCSRB,UCSRB_UDRIE);
    #endif

  /*Set Tx and Rx Mode*/
   #if     USART_TX_EN == DISABLE
           CLR_BIT(UCSRB,UCSRB_TXEN);
   #elif   USART_TX_EN == ENABLE
           SET_BIT(UCSRB,UCSRB_TXEN);
   #endif

   #if     USART_RX_EN == DISABLE
           CLR_BIT(UCSRB,UCSRB_RXEN);
   #elif   USART_RX_EN == ENABLE
           SET_BIT(UCSRB,UCSRB_RXEN);
   #endif

	   /*Baud Rate Value*/

     u16 Local_u16UBRRValue ;
      Local_u16UBRRValue = BAUD_RATE;
      UBRRL=(u8)Local_u16UBRRValue;
      UBRRH=(u8)(Local_u16UBRRValue>>8);

}

void USART_VidTransmitData(u16 Copy_u16TransmittedData){
	while((GET_BIT(UCSRA,UCSRA_UDRE))!=1);
	UDR=Copy_u16TransmittedData;
	UCSRB |=((Copy_u16TransmittedData>>8)&(1));
}

u8 USART_u16ReceivedData(void){
	while((GET_BIT(UCSRA,UCSRA_RXC))!=1);

	return UDR;

}


void USART_VidAsynchroBaudRate(u16 Copy_u16BaudRateValue,u8 Copy_u8SpeedMode,u32 Copy_u32Freq){

u16 Local_u16BRRValue=0;
 if(Copy_u8SpeedMode==DISABLE){
     Local_u16BRRValue=(Copy_u32Freq/(16*(Copy_u16BaudRateValue)))-1;
     UBRRL=Local_u16BRRValue;
     UBRRH=(Local_u16BRRValue>>8);
 }
 if(Copy_u8SpeedMode==ENABLE){
      Local_u16BRRValue=(Copy_u32Freq/(8*(Copy_u16BaudRateValue)))-1;
      UBRRL=Local_u16BRRValue;
      UBRRH=(Local_u16BRRValue>>8);
  }

}


void USART_VidSendChar(u8 Copy_u8Char)
{
    while((GET_BIT(UCSRA,UCSRA_UDRE))==0);
    UDR = Copy_u8Char;
}

u8 USART_VidReceiveChar(void)
{
    while((GET_BIT(UCSRA,UCSRA_RXC))==0);
    return UDR ;
}



u8 USART_VidReceiveCharWith_TimeOut(void)
{u16 Local_u8Counter=0;

    while((Local_u8Counter<20000)&&((GET_BIT(UCSRA,UCSRA_RXC))==0))
    {
    	Local_u8Counter++;
    }
    return UDR ;
}

void USART_VidSendString(const u8 *Copy_pu8String)
{        u8 Local_u8Counter=0;
	while( Copy_pu8String[Local_u8Counter] != '\0' )
		{
		   USART_VidSendChar(Copy_pu8String[Local_u8Counter]);
		   Local_u8Counter++;
			  _delay_ms(1);
		}

}


