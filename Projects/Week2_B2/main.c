/*
 * Week2_B2.c
 *
 * Created: 5-2-2020 13:49:58
 * Author : matth
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

uint8_t counter = 0;

#define COUNTERMAX 5

ISR(INT0_vect)
{
	counter++;
	if (counter > COUNTERMAX)
	{
		counter = 0;
		PORTD = 0x02;
	}
}

ISR(INT1_vect)
{
	counter++;
	if (counter > COUNTERMAX)
	{
		counter = 0;
		PORTD = 0x04;
	}
}

ISR(INT2_vect)
{
	counter++;
	if (counter > COUNTERMAX)
	{
		counter = 0;
		PORTD = 0x08;
	}
}

ISR(INT3_vect)
{
	counter++;
	if (counter > COUNTERMAX)
	{
		counter = 0;
		PORTD = 0x01;
	}
}

int main(void)
{
	DDRD = 0x0F;	//Set 4-7 to input, set 0-3 to output 
	
	EICRA |= 0xFF;	//pin 0-3 are rising edge
	EIMSK |= 0X0F;	//Enable pin0-3
	
	sei();
	PORTD = 0X01;
	
    while (1) 
    {
    }
}

