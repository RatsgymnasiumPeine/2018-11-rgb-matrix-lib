#include "LEDMatrix_Lib.h"

LEDMatrix::LEDMatrix(int size, int matrixChip, int matrixLayout, int[] pins){
	_size = size;
	_matrixChip = matrixChip;
	_matrixLayout = matrixLayout;
	_pins = pins;
}

void LEDMatrix::init(){
	
}

void LEDMatrix::draw_pixel(int x, int y, int r, int g, int b){
	
}