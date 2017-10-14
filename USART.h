/*
 * USART.h
 *
 * Created: 10/13/2017 11:49:49 PM
 *  Author: Ensaf Atef
 */ 


#ifndef USART_H_				
#define USART_H_

#define F_CPU 16000000UL					
#include <avr/io.h>							
#define BAUD_PRESCALE (((F_CPU / (BAUDRATE * 16UL))) - 1)	// Define prescale value 

void USART_Init(unsigned long);				
char USART_RxChar();						
void USART_TxChar(char);					
void USART_SendString(char*);				


#endif					
