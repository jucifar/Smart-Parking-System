#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(Reg,Bit_num) (Reg)|=(1<<Bit_num)
#define CLR_BIT(Reg,Bit_num) ((Reg)&=(~(1<<Bit_num)))
#define TOGGLE_BIT(Reg,Bit_num) (Reg)^=(1<<Bit_num)
#define GET_BIT(Reg,Bit_num) (Reg>>Bit_num)&(1)


#endif