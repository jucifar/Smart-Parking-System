/************************************************************************/
/************************************************************************/
/**************     Author : Ahmed Atef Osman      **********************/
/**************     SWC : USART_Driver             **********************/
/**************     Layer: MCAL                    **********************/
/**************     Date : 25 / NOV / 2022         **********************/
/**************     Version : V1.0                 **********************/
/************************************************************************/
/************************************************************************/
#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

/************************************ UCSRA_Regisiter  *******************************************************/
/*Speed Options:
 * NORMAL
 * DOUBLED
 */
#define NORMAL  100
#define DOUBLED 101

/*MULTI_PROCESSOR_MODE  Options:
 * DISABLE
 * ENABLE
 */
#define DISABLE  102
#define ENABLE   103

/*STOP_BIT OPtions:
 * TWO_STOP_BITS
 * ONE_STOP_BITS
 */

#define TWO_STOP_BITS 104
#define ONE_STOP_BITS 105

/*Character Size Options:
 * DATA_5_BIT
 * DATA_6_BIT
 * DATA_7_BIT
 * DATA_8_BIT
 * DATA_9_BIT
 */
#define DATA_5_BIT 106
#define DATA_6_BIT 107
#define DATA_7_BIT 108
#define DATA_8_BIT 109
#define DATA_9_BIT 110

/*Parity Error OPtions:
 * DISABLE
 * ODD_PARITY
 * EVEN_PARITY
 */

#define ODD_PARITY   111
#define EVEN_PARITY  112

/*Clock_Polarity OPtions:
 * RISING_TX_FALLING_RX
 * FALLING_TX_RISING_RX
 */
#define RISING_TX_FALLING_RX 113
#define FALLING_TX_RISING_RX 114

#define BR_9600    115



#endif
