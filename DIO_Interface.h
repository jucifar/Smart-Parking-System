/************************************************************************/
/************************************************************************/
/**************     SWC : DIO Driver             ************************/
/**************     Author : Ahmed Atef Osman    ************************/
/**************     Date : 27 / Aug / 2022       ************************/
/**************     Version : V1.0               ************************/ 
/************************************************************************/
/************************************************************************/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


/*Give Ports a value number by using enum */  

typedef enum {
	Port_A , // Port_A =0
    Port_B , // Port_B =1
    Port_C , // Port_C =2
    Port_D   // Port_D =3
    	
}et_Port ;

/*Give Pins a value number by using enum to acces them using int number */ 

typedef enum {
	Pin0 ,         //Pin0=0
	Pin1 ,         //Pin1=1
	Pin2 ,         //Pin2=2
	Pin3 ,         //Pin3=3
	Pin4 ,         //Pin4=4
	Pin5 ,         //Pin5=5
	Pin6 ,         //Pin6=6
	Pin7           //Pin7=7
	
}et_Pin ;

/*Create value number by using enum to acces them as int number for dirction register */

typedef enum {
	Input , //Input=0
	Output  //Output=1
}et_Direction ;

/*status of the signal*/

typedef enum {
	PinLow , //0
	PinHigh //1
}et_Status ;



/*Setting pin direction*/
void DIO_VidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);

/*Setting pin value*/
void DIO_VidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);


/*Getting pin value*/
void DIO_VidGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *pu8Data);


/*Setting Port direction*/
void DIO_VidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8DirectionValue);


/*Setting Port(Port register) value*/
void DIO_VidSetPortValue(u8 Copy_u8Port,u8 Copy_u8PortValue);

/*Getting Port value*/
void DIO_VidGetPortValue(u8 Copy_u8Port, u8 *pu8Data);
#endif