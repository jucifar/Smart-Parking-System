/************************************************************************/
/************************************************************************/
/**************     Author : Ahmed Atef Osman      **********************/
/**************     SWC : USART_Driver               **********************/
/**************     Layer: MCAL                    **********************/
/**************     Date : 28 / OCT / 2022         **********************/
/**************     Version : V1.0                 **********************/
/************************************************************************/
/************************************************************************/

#ifndef USART_INT_H_
#define USART_INT_H_


void USART_VidIniti(void);

void USART_VidTransmitData(u16 Copy_u16TransmittedData);

u16 USART_u16ReceivedData(void);

void USART_VidSetBaudRate(u16 Copy_u16BaudRateValue);

void USART_VidSendChar(u8 Copy_u8Char);

u8 USART_VidReceiveCharWith_TimeOut(void);

u8 USART_VidReceiveChar(void);

void USART_VidSendString(const u8 *Copy_pu8String);

#endif
