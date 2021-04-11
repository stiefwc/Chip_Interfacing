/* Include delay function */
#define F_CPU 16000000UL		/* Define CPU Frequency 8MHz */
#include <avr/io.h>
#include <util/delay.h>		/* Include delay header file */
#include <stdio.h>

static double ratio = 1.4222;

int main(void){

	// User input settings here
	int degreesOfRotation = 100; // total degrees of rotation for timelapse
	double minutesOfRotation = 1; // minutes for total timelapse
	int clockwise = 1; // 1 for true (clockwise), 0 for false (counterclockwise)

	
	double delay = (minutesOfRotation*15000)/(degreesOfRotation*ratio);

	DDRD = 0b00001111; // Port D pins 0,1,2,3 as output

		if (clockwise == 1)
				{
				for (int i=0; i<(degreesOfRotation*ratio); i++) // clockwise rotation
						{
						PORTD = 0x03;
						_delay_ms(delay);
						PORTD = 0x09;
						_delay_ms(delay);
						PORTD = 0x0C;
						_delay_ms(delay);
						PORTD = 0x06;
						_delay_ms(delay);
						}
				} else {
				for (int i=0; i<(degreesOfRotation*ratio); i++)  //counterclockwise rotation
					  {
					 	PORTD = 0x06;
						_delay_ms(delay);
						PORTD = 0x0C;
						_delay_ms(delay);
						PORTD = 0x09;
						_delay_ms(delay);
						PORTD = 0x03;
						_delay_ms(delay);
					 	}
			}
	}
