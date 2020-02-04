#define F_CPU 8e6

#include <avr/io.h>
#include <util/delay.h>

void blinkstrip(void);
void blinkseparate(void);
void blinkWhileButtonPressed(void);
void walkingLEDs(void);
void lightpatterns(void);
void displaySequence(short*, int);
void blinkStates(void);

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
	//walkingLEDs();
	//lightpatterns();
	blinkStates();
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

/* Opdracht B4 */
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

/* Opdracht B5 */
void lightpatterns(void)
{
	short toCenterFromCenter[7] = {0x81, 0x42, 0x24, 0x18, 0x24, 0x42, 0x81};
	short ledsWalking[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};

	DDRD = 0b11111111;	//ALL pins PORTD are set to output

	while(1)
	{
		displaySequence(toCenterFromCenter, 7);
		displaySequence(ledsWalking, 8);

	}
}

void displaySequence(short arr[], int arraySize)
{
	for(int i = 0; i < arraySize; i++)
	{
		PORTD = arr[i];
		wait( 200 );
	}
}

/* Opdracht B6 */
void blinkStates()
{
	DDRD = 0b11111111;	//ALL pins PORTD are set to output
	int interval = 1000;
	int elapsedmillis = 0;
	int isLedOn = 0;

	while(1)
	{
		if (elapsedmillis - interval >= 0)	//Check if the elapsed time has already reached the interval
		{
			if (isLedOn == 0)
			{
				PORTD = 0x80;
				isLedOn = 1;
				}else{
				PORTD = 0x00;
				isLedOn = 0;
			}
			elapsedmillis -= interval;	//reset elapsed time
		}
		
		if ((PINC & 0x01) && (interval == 250))	//check for button inputs and change interval
		{
			interval = 1000;
			}else if((PINC & 0x01) && (interval == 1000)){
			interval = 250;
		}
		wait( 1 );
		elapsedmillis++;
	}
}
