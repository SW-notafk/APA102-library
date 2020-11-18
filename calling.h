/*
File for defining classes - attributes and methods
*/
#ifndef call_h
#define call_h

#include <avr/io.h>
#include <string.h>
#define F_CPU 16000000

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
	
	char array[8][8][3] =   {{{0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}},
							{{0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}},
							{{0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}},
							{{0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}},
							{{0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}},
							{{0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}},
							{{0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}},
							{{0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}}};	
	
	private:
	void LedTransmit(uint8_t data);
	void ClearBoard();
	void SendColor(char r, char g, char b);
	void UpdateFrame(char row, char column, char r, char g, char b);
	
	#define SPI_DDR DDRB
	#define SS      PINB
	#define MOSI    PINB3
	#define MISO    PINB4
	#define SCK		PINB5
};
#endif
