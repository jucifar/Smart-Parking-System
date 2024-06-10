/************************************************************************/
/************************************************************************/
/**************     Author : Ahmed Atef Osman      **********************/
/**************     SWC : USART_Driver               **********************/
/**************     Layer: MCAL                    **********************/
/**************     Date : 28 / OCT / 2022         **********************/
/**************     Version : V1.0                 **********************/
/************************************************************************/
/************************************************************************/

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

/*Baud Rate Options for clock 8MHz:
 * 51 >>>>>>>>>BR_9600
 *
 */

#define BAUD_RATE    51
/************************************  Character_Size  *******************************************************/
/*Character Size Options:
 * DATA_5_BIT
 * DATA_6_BIT
 * DATA_7_BIT
 * DATA_8_BIT
 * DATA_9_BIT
 */

#define CHAR_SIZE   DATA_8_BIT

/*Parity Error OPtions:
 * DISABLE
 * ODD_PARITY
 * EVEN_PARITY
 */
#define PARITY_CHECK   DISABLE

/*STOP_BIT OPtions:
 * TWO_STOP_BITS
 * ONE_STOP_BITS
 */
#define STOP_BIT  ONE_STOP_BITS
/*SYNCHRONIZATION OPtions:
 * DISABLE  <ACTIVE_ASYNCHRO_MODE>
 * ENABLE   <ACTIVE_SYNCHRO_MODE>
 */

#define SYNCHRO_MODE   DISABLE
/*Clock_Polarity OPtions:
 * RISING_TX_FALLING_RX
 * FALLING_TX_RISING_RX
 */

#define CLOCK_POLARITY   RISING_TX_FALLING_RX



/************************************  UCSRA_Regisiter  ******************************************************/
/*Speed Options:
 * NORMAL
 * DOUBLED
 */

#define USART_TX_SPEED      NORMAL
/*MULTI_PROCESSOR_MODE  Options:
 * DISABLE
 * ENABLE
 */

#define  MULTI_PROCESSOR_MODE   DISABLE

/************************************ UCSRB_Regisiter  *******************************************************/
/* Options:
 * DISABLE
 * ENABLE
 */

#define USART_RX_INTERRUPT        DISABLE
#define USART_TX_INTERRUPT        DISABLE
#define USART_UDRE_INTERRUPT      DISABLE


#define USART_TX_EN       ENABLE
#define USART_RX_EN       ENABLE

#endif
