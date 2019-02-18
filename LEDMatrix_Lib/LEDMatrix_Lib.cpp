#include "LEDMatrix_Lib.h"
#include "Adafruit_NeoPixel.h"
#include "LedControl.h"


LEDMatrix::LEDMatrix(int size, int matrixChip, int matrixLayout, int pins[]){
	_size = size;
	_matrixChip = matrixChip;
	_matrixLayout = matrixLayout;
	_pins = pins;
	_flipX = false;
	_flipY = false;
}

void LEDMatrix::init(){
	switch(_matrixChip){
		case MATRIX_WS2812B:
			_ws2812b = new Adafruit_NeoPixel(_size*_size, _pins[0], NEO_GRB + NEO_KHZ800);
			_ws2812b->begin();
			break;
		
		case MATRIX_MAX7219:
			_max7219 = new LedControl(_pins[0], _pins[2], _pins[1], _size*_size/64);
			for(int i = 0; i < _size*_size/64; i++)
				_max7219->shutdown(i, false);
			break;
	}
}

void LEDMatrix::draw_pixel(int x, int y, int r, int g, int b){
	if(_flipX)
		x = _size - 1 - x;
	if(_flipY)
		y = _size - 1 - y;
	switch(_matrixChip){
		case MATRIX_WS2812B:		
			if(_matrixLayout == MATRIX_LAYOUT_ZIGZAG && y % 2 != 0){
				x = _size - x - 1;
			}
			_ws2812b->setPixelColor(x + y*_size, r, g, b);
			break;
		
		case MATRIX_MAX7219: {
			int quadX;
			int quadY;
			int inQuadX;
			int inQuadY;
			
			quadX = x/8;
			quadY = y/8;
			
			inQuadX = y%8;
			inQuadY = 7 - x%8;
			
			if(quadY % 2 != 0 && _matrixLayout == MATRIX_LAYOUT_ZIGZAG){
				quadX = _size/8 - 1 - quadX;
				inQuadX = 7 - inQuadX;
				inQuadY = 7 - inQuadY;
			}
			_max7219->setLed(quadX + quadY*(_size/8), inQuadX, inQuadY, r+g+b != 0);
			break;
		}
			
			
	}
}

void LEDMatrix::update(){
	switch(_matrixChip){
		case MATRIX_WS2812B:
			_ws2812b->show();
			break;
		
		case MATRIX_MAX7219:
			break;
	}
}

void LEDMatrix::setFlip(bool flipX, bool flipY){
	_flipX = flipX;
	_flipY = flipY;
}