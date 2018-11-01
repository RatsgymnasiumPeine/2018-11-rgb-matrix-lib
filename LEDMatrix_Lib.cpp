#include "LEDMatrix_Lib.h"

LEDMatrix::LEDMatrix(int size, int matrixChip, int matrixLayout, int[] pins){
	_size = size;
	_matrixChip = matrixChip;
	_matrixLayout = matrixLayout;
	_pins = pins;
}

void LEDMatrix::init(){
	switch(_matrixChip){
		case MATRIX_WS2812B:
			_ws2812b = Adafruit_NeoPixel(_size*_size, _pins[0], NEO_GRB + NEO_KHZ800);
			break;
		
		case MATRIX_MAX7219:
			_max7219 = LedControl(_pins[0], _pins[1], _pins[2], _size/8);
			break;
	}
}

void LEDMatrix::draw_pixel(int x, int y, int r, int g, int b){
	
}

void LEDMatrix::update(){
	
}