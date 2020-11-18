#include <avr/io.h>
#include "calling.h"
#define F_CPU 16000000


int main(void)
{
	LedStrip ledstrip;
	ledstrip.LedInit();
	
    while (1) 
    {
		ledstrip.DisplayText("");
    }
}

