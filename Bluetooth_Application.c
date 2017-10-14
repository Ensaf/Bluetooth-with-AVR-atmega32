/*
 * Bluetooth_Application.c
 *
 * Created: 10/13/2017 11:58:14 PM
 *  Author: Ensaf Atef
 */ 


#include <avr/io.h>
#include "USART.h"		/* include USART library */
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void)
{
	char Recieved_Data;

	DDRC=0xff;
	DDRD&=~(1<<0);
	DDRD|=(1<<1);

	USART_Init(9600);			/* initialize USART with 9600 baud rate */
	
	
	while(1)
	{
		Recieved_Data = USART_RxChar();
		
		if (Recieved_Data == '0')
		{
			PORTC|=(1<<0);
			USART_SendString("LED_ON");
		}
		
		if (Recieved_Data == '1')
		{
			PORTC&=~(1<<0);
			USART_SendString("LED_OFF");
		}
		

		_delay_ms(1000);
		

	}
	return 0;
}
