#define F_CPU 8e6

#include <avr/io.h>
#include <util/delay.h>


void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

int main(void)
{
	//blinkstrip();
	//blinkseparate();
	//blinkWhileButtonPressed();
	walkingLEDs();
}

/* Opdracht A2 */
void blinkstrip()
{
	DDRD = 0b11111111;	//ALL pins PORTD are set to output
	
	while (1)
	{
		PORTD = 0xAA;	//write 10101010b PORTD
		wait( 250 );
		PORTD = 0x55;	//write 01010101b PORTD
		wait( 250 );
	}
}

/* Opdracht B2 */
void blinkseparate()
{

	DDRD = 0b11111111;	//ALL pins PORTD are set to output

	while (1)
	{
		PORTD = 0x80;	//write 10000000b PORTD
		wait( 500 );
		PORTD = 0x40;	//write 01000000b PORTD
		wait( 550 );
	}
}

/* Opdracht B3 */
void blinkWhileButtonPressed()
{
	DDRD = 0b11111111;	//ALL pins PORTD are set to output

	while (1)
	{
		while (PINC & 0x01)
		{
			PORTD = 0x80;
			wait( 250 );
			PORTD = 0x00;
			wait( 250 );
		}
	}
}

void walkingLEDs()
{
	DDRD = 0b11111111;	//ALL pins PORTD are set to output
	int x = 0;

	while (1)
	{
		PORTD = 1 << x%8;
		x++;
		wait( 50 );
	}
}
