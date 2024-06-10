/************************************************************************/
/************************************************************************/
/**************     Author : Ahmed Atef Osman      **********************/
/**************     SWC : USART_Driver             **********************/
/**************     Layer: MCAL                    **********************/
/**************     Date : 28 / OCT / 2022         **********************/
/**************     Version : V1.0                 **********************/
/************************************************************************/
/************************************************************************/

#ifndef USART_REG_H_
#define USART_REG_H_

/*UDR is responsible for access Tx an Rx data */
#define UDR    *((volatile u8*)0x2C)

/*USART Control and Status Register A � UCSRA , it contains flags of many operations that generated by USART
 * UCSRA_RXC  -->  USART Receive Complete Flag
 * UCSRA_TXC  -->  USART Transmit Complete Flag
 * UCSRA_UDRE -->  USART Data Register Empty Flag
 * UCSRA_FE   -->  Frame Error Flag
 * UCSRA_DOR  -->  Data OverRun Flag
 * UCSRA_PE   -->  Parity Error Flag
 * UCSRA_U2X  -->  Double the USART Transmission Speed ,This bit select between normal speed or doubling normal speed x2
 * UCSRA_MPCM -->  Multi-processor Communication Mode ,This bit is responsible for enabling Multi-Masters and Multi-Slaves Tx/Rx Relationship Mode
 **/
#define UCSRA  *((volatile u8*)0x2B)

#define UCSRA_RXC   7
#define UCSRA_TXC   6
#define UCSRA_UDRE  5
#define UCSRA_FE    4
#define UCSRA_DOR   3
#define UCSRA_PE    2
#define UCSRA_U2X   1
#define UCSRA_MPCM  0

/*Description: USART Control and Status Register B � UCSRB
 * This register is a control and status register, the most bit of it is used to enable and disable interrupts of USART
 * and another operations
 */

#define UCSRB  *((volatile u8*)0x2A)

#define UCSRB_RXCIE    7    // RX Complete Interrupt Enable
#define UCSRB_TXCIE    6    // TX Complete Interrupt Enable
#define UCSRB_UDRIE    5    // USART Data Register Empty Interrupt Enable
#define UCSRB_RXEN     4    // Receiver Enable
#define UCSRB_TXEN     3    // Transmitter Enable
#define UCSRB_UCSZ2    2    // Character Size
#define UCSRB_RXB8     1    // Receive Data Bit 8
#define UCSRB_TXB8     0    // Transmit Data Bit 8



/*Description: USART Control and Status Register C � UCSRC
 *
 */

#define UCSRC  *((volatile u8*)0x40)

#define UCSRC_URSEL     7    // Register Select between UCSRC and UBRRH
#define UCSRC_UMSEL     6    // USART Mode Select
#define UCSRC_UPM1      5    // Parity Mode
#define UCSRC_UPM0      4    // Receiver Enable
#define UCSRC_USBS      3    // Stop Bit Select
#define UCSRC_UCSZ1     2    // Character Size1
#define UCSRC_UCSZ0     1    // Character Size0
#define UCSRC_UCPOL     0    // Clock Polarity




/* Description: USART Baud Rate Registers � UBRRL and UBRRH
 *
 * */
#define UBRRH *((volatile u8*)0x40)
#define UBRRL *((volatile u8*)0x29)



#endif
