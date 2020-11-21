/*
File for defining classes - attributes and methods
*/
#ifndef call_h
#define call_h

#include <avr/io.h>
#include <string.h>
#define F_CPU 16000000

///Main class for the driver that holds necessary attributes and methods 
class LedStrip{
	public:
	void LedInit();
	void SetSeveralAndSend(uint8_t LedAmount, uint8_t brightness, uint8_t blue, uint8_t green, uint8_t red);
	void SetOneLed(char row, char column, char r, char g, char b);
	
	void CreateStartFrame();
	void CreateLedFrame(uint8_t LedAmount, uint8_t brightness, uint8_t blue, uint8_t green, uint8_t red);
	void CreateLedBlankFrame(uint8_t LedAmount);
	void CreateEndFrame();
	
	void DisplayText(char text[]);
	
	///Three dimensional array that depicts every LED that can be used on the 8x8 board.
	///This attribute is used by the "SetOneLed" method. 
	char array[8][8][3] =   {{{0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}},
							{{0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}},
							{{0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}},
							{{0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}},
							{{0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}},
							{{0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}},
							{{0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}},
							{{0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}}};
	
	///Function used to set brightness of LEDs used in functions like DisplayText or SetOneLed							
	uint8_t global_brightness = 1;							
	
	private:
	void LedTransmit(uint8_t data);
	void SendColor(char r, char g, char b);
	void UpdateFrame(char row, char column, char r, char g, char b);
	void ClearBoard();
	
	#define SPI_DDR DDRB
	#define SS      PINB
	#define MOSI    PINB3
	#define MISO    PINB4
	#define SCK		PINB5
};
#endif
