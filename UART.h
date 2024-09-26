/*
 * UART.h
 *
 * Created: 23/07/2024 00:54:29
 *  Author: Usuario
 */ 

#include <avr/io.h>
#include <util/delay.h>



#ifndef UART_H_
#define UART_H_


void UART_init(void);						// función para iniciar el USART 
unsigned char UART_read(void);				// Lectura
void UART_write(unsigned char);				// Escritura
void UART_write_txt(char*);					// Cadena de caracteres
void send_via_uart(uint8_t id);

#endif /* UART_H_ */