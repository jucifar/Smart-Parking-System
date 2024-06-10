/************************************************************************/
/************************************************************************/
/**************     SWC : External_Inerrupt Driver **********************/
/**************     Author : Ahmed Atef Osman      **********************/
/**************     Date : 23 / Seb / 2022         **********************/
/**************     Version : V1.0                 **********************/ 
/************************************************************************/
/************************************************************************/

#ifndef GIE_PRIVATE_H_
#define GIE_PRIVATE_H_

#define  SREG   *((volatile u8*)0x5F)  // PSW Register (Program Status Register) that contian the flag registers


#define  SREG_INT   7                    // Bit 7 that responsible for Global interrupt enable 

#endif
