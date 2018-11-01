#ifndef LEDMATRIX_LIB_H
#define LEDMATRIX_LIB_H

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>
#include <LedControl.h>

#define MATRIX_WS2812B		0
#define MATRIX_MAX7219		1

#define MATRIX_LAYOUT_ZIGZAG	0
#define MATRIX_LAYOUT_ROW		1

class LEDMatrix{
	private:
		int 	_size;
		int 	_matrixChip;
		int 	_matrixLayout;
		int[] 	_pins;
		
		Adafruit_NeoPixel 	_ws2812b;
		LedControl 			_max7219;
	
	public:
		LEDMatrix(int size, int matrixChip, int matrixLayout, int[] pins);
		void init();
		void draw_pixel(int x, int y, int r, int g, int b);		
		void update();	
};

#endif