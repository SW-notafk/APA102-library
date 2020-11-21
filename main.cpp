#include <avr/io.h>
///Including the header file 
#include "calling.h"
///Specifying the clock speed
#define F_CPU 16000000

///Main function for the program
int main(void)
{
	LedStrip ledstrip;
	ledstrip.LedInit();
	
    while (1)
	{
		
	} 
    
}
