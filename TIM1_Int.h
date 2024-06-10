/************************************************************************/
/************************************************************************/
/**************     Author : Ahmed Atef Osman      **********************/
/**************     SWC : TIMER1_Driver            **********************/
/**************     Layer: MCAL                    **********************/
/**************     Date : 15 / OCT / 2022          *********************/
/**************     Version : V1.0                 **********************/
/************************************************************************/
/************************************************************************/

#ifndef TIM1_INT_H_
#define TIM1_INT_H_


void TIMER1_VidInit_CTCMode(void);
/*set OCR1A VALUE */
void Timer1_SetCTC_OCR1A_Value(u16 Copy_u16OCR1A_Value);
/* Initialize Timer1 to generate delay with micro sec  */
void Timer1_SetDelay_Micro(u16 Copy_DelayValue);

#endif
