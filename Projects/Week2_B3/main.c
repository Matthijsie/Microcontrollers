/*
 * Week2_B3.c
 *
 * Created: 12-2-2020 12:19:55
 * Author : matth
 */ 
#define F_CPU 8e6

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

const unsigned char NUMBERS[16] =
{
	//dgfedcba
	0b00111111, // 0
	0b00000110, // 1
	0b01011011, // 2
	0b01001111, // 3
	0b01100110, // 4
	0b01101101, // 5
	0b01111101, // 6
	0b00000111, // 7
	0b01111111, // 8
	0b01101111, // 9
	0b01110111, // A
	0b01111100, // b
	0b00111001, // C
	0b01011110, // d
	0b01111001, // E
	0b01110001, // F
};int getal = 0;

ISR(INT0_vect)
{
	getal++;
	if (PIND & 0x02)
	{
		getal = 0;
	}
}

ISR(INT1_vect)
{
	getal--;
	if (PIND & 0x01)
	{
		getal = 0;
	}
}


void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

int main(void)
{
	DDRB = 0xFF;	//set ALL pins to output on port B

	DDRD = 0x00;	//set ALL pins to input on port D
	EICRA |= 0x0F;	//Pin 0-1 are rising edge
	EIMSK |= 0x03;	//enable pin 0-1
	sei();
	
	PORTB = NUMBERS[0];
	
    while (1) 
    {
		if (getal >= 0 && getal <= 15)	//Between 0 and 15 (Both included)
		{
			PORTB = NUMBERS[getal];
		}else{
			PORTB = NUMBERS[14];	//E
		}
		wait( 10 );
    }
}

