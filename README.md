# LEDMatrix_Lib
Helper library for building LED matrices out of RGB LED Stripes or multiple LED matrix blocks.

# Table of Contents
1. [Matrix Styles (Chips)](#matrix-styles-chips)
2. [Matrix Connection Layouts](#matrix-connection-layouts)
	* [MAX7219](#max7219-layout)
	* [WS2812B](#ws2812b-layout)
3. [Function Documentation](#function-documentation)
	* [LEDMatrix::LEDMatrix()](#ledmatrixledmatrix)
	* [LEDMatrix::init()](#ledmatrixinit)
	* [LEDMatrix::update()](#ledmatrixupdate)
	* [LEDMatrix::draw_pixel()](#ledmatrixdrawpixel)
	* [LEDMatrix::draw_line()](#ledmatrixdrawline)
	* [LEDMatrix::draw_circle()](#ledmatrixdrawcircle)


## Matrix Styles (Chips)
You can either build your matrices with MAX7219 based 8x8 matrices or with custom build matrices out of WS2812B (NeoPixel) LEDs often found on RGB LED Stripes.
Either use MATRIX_MAX7219 or MATRIX_WS2812B as matrixChip parameters.

<img src="img/Chips.svg" width="100%" />

## Matrix Connection Layouts
You can either connect the rows of your matrix in ZIGZAG or ROW mode. Use either MATRIX_LAYOUT_ZIGZAG or MATRIX_LAYOUT_ROW as matrixLayout parameters.
Below are some examples on how to wire each layout.

### MAX7219 Layout
<img src="img/MAX7219Layout.svg" width="100%" />

### WS2812B Layout
<img src="img/WS2812BLayout.svg" width="100%" />

## Function Documentation
### LEDMatrix::LEDMatrix()
**Command:** ```LEDMatrix::LEDMatrix(int size, int matrixChip, int matrixLayout, int[] pins)```  
**Params:**  
	* int _size_: the size of the matrix, e.g. 16 for a 16x16 matrix  
	* int _matrixChip_: one of the matrix chip constants (MATRIX_MAX7219 or MATRIX_WS2812B)  
	* int _matrixLayout_: one of the matrix layout constants (MATRIX_LAYOUT_ZIGZAG or MATRIX_LAYOUT_ROW)  
	* int[] _pins_: the pins used to control the matrix; array length depends on used matrixChip  

**Returns:**  
	* _LEDMatrix Object_  

**Description:**  
>  Creates a new LEDMatrix object. You need to pass the matrix size, matrix chip, matrix layout and the pins on which the matrix is connected to the arduino.
>  For WS2812B _pins_ contains a single value: DIN.
>  For MAX7219 _pins_ contains 3 values: DIN, CS, CLK

### LEDMatrix::init()
**Command:** ```LEDMatrix::init()```  
**Params:**  
	* _nothing_  

**Returns:**  
	* _nothing_  

**Description:**  
>  Initializes the pins and backend libraries. This method is required to be run in the setup() block.

### LEDMatrix::draw_pixel()
**Command:** ```LEDMatrix::draw_pixel(int x, int y, int r, int g, int b)```  
**Params:**  
	* int _x_: X coordinate of the pixel  
	* int _y_: Y coordinate of the pixel  
	* int _r_: red value of the pixel  
	* int _g_: green value of the pixel  
	* int _b_: blue value of the pixel  
	
**Returns:**  
	* _nothing_  

**Description:**  
>  Draws a single pixel on the LED matrix. For B/W matrices every color value except black (0, 0, 0) is white.
>  Note that this operation only modifies the internal buffer on ws2812b. On max7219 the change will be visible immediately

### LEDMatrix::update()
**Command:** ```LEDMatrix::update()```  
**Params:**  
	* _nothing_
	
**Returns:**  
	* _nothing_  

**Description:**  
>  Updates to matrix to represent the internal frame buffer. This method should be called if you want to display your changes on the matrix.