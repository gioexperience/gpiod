#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>

// compile
// sudo gcc gpio_btn.c -o /usr/local/bin/gpio_btn -lwiringPi


//********************************************************
//** wait for a "pulse" or "long press"
//** If there is a "short pulse" exit and write "SHORT"
//** If there is a "long pressing" exit and write "LONG"
//** if detect a noise, exit writing "...noise..."
//********************************************************


int main(int argc,char **argv) 
{
	int pin;
	long int t0;
	int val=0;
	int out=0;	//10=long	20=short
	
	pin=atoi(argv[1]);

	if (wiringPiSetupGpio() < 0)
	{	
		fprintf (stderr, "Errore: Unable to GPIO: %s\n", strerror (errno)) ;
		return 1 ;
	}

	//if start with HIGH value, wait for the LOW value
	if( digitalRead(pin)==1 )
	{
		while (digitalRead(pin)==1) 
			delay(50);
	}

	//continue do nothing while the state==0
	while (digitalRead(pin)==0) 
		delay(50);

	//now somebody press the button. We must stay in this loop 
	//when during the "pushing" of the button.
	//I consider a valid "push" if it during at least 100ms
	t0=millis();
	while (1) 
	{
		delay(50);
		val=digitalRead(pin);
		
		if( val==1 && millis()-t0>=2000 )	//if CONTINUE PRESSING for > 2000 ms
		{
			out=10;
			break;
		}
		
		if( val==0 ) //if RELEASE THE BUTTON...
		{
			if( millis()-t0>100 )	//if the pressing had during at least tot ms
				out=20;
			else	
				out=0;				//else break without output
			
			break;
		}
	}

	if( out==0 ) fprintf(stdout,"...noise...\n");
	if( out==10 ) fprintf(stdout,"LONG\n");
	if( out==20 ) fprintf(stdout,"SHORT\n");

	return 0;
}
