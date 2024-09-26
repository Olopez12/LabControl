/*
 * Lab_Control.c
 *
 * Created: 20/09/2024 11:14:40
 * Author : Usuario
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "UART/UART.h"

#define DEBOUNCE_TIME 100  // Tiempo de antirrebote en milisegundos

uint8_t debounce(uint8_t pin);
void setup();
void check_buttons();

int main(void)
{
	setup();
	UART_init();

	while (1)
	{
		// Revisar los botones continuamente
		check_buttons();

		// Apagar PD2 a PD7 después de cada ciclo para evitar que los LEDs queden encendidos
		PORTD &= ~(0xFC);
	}

	return 0;
}

void setup() {
	// Configurar PD2-PD7 como salida para los LEDs
	DDRD |= 0xFC;

	// Configurar PB0-PB5 como entrada para los botones
	
	DDRB &= ~(0x3F);
	// Habilitar resistencias pull-up en PB0-PB5
	PORTB |= 0x3F;
}

uint8_t debounce(uint8_t pin) {
	if (!(PINB & (1 << pin))) {  // Si el botón está presionado
		_delay_ms(DEBOUNCE_TIME);  // Esperar el tiempo de antirrebote
		if (!(PINB & (1 << pin))) {  // Verificar de nuevo si el botón sigue presionado
			return 1;  // Confirmar que el botón está presionado
		}
	}
	return 0;  // El botón no está presionado
}

void check_buttons() {
	// Revisar qué botón se presionó (PB0 a PB5) y encender el LED correspondiente
	if (debounce(PINB0)) {
		PORTD |= (1 << PIND2);  // Encender LED en PD2
		send_via_uart('1');     // Enviar el número '1'
	}
	if (debounce(PINB1)) {
		PORTD |= (1 << PIND3);  // Encender LED en PD3
		send_via_uart('2');     // Enviar el número '2'
	}
	if (debounce(PINB2)) {
		PORTD |= (1 << PIND4);  // Encender LED en PD4
		send_via_uart('3');     // Enviar el número '3'
	}
	if (debounce(PINB3)) {
		PORTD |= (1 << PIND5);  // Encender LED en PD5
		send_via_uart('4');     // Enviar el número '4'
	}
	if (debounce(PINB4)) {
		PORTD |= (1 << PIND6);  // Encender LED en PD6
		send_via_uart('5');     // Enviar el número '5'
	}
	if (debounce(PINB5)) {
		PORTD |= (1 << PIND7);  // Encender LED en PD6
		send_via_uart('6');     // Enviar el número '5'
	}
}
