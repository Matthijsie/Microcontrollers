#define F_CPU 8e6

#include "lcd.h"
#include <avr/io.h>
#include <util/delay.h>

int main( void )
{
	// Init I/O
	DDRD = 0xFF;			// PORTD(7) output, PORTD(6:0) input

	// Init LCD
	lcd_init();

	// Write sample string
	lcd_set_cursor(0x41);
	lcd_display_text("I am confusion");

	// Loop forever
	while (1)
	{
		PORTD ^= (1<<7);	// Toggle PORTD.7
		_delay_ms( 250 );
	}

	return 1;
}
