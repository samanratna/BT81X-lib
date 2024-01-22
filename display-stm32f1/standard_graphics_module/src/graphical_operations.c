// Load local libraries
#include "graphical_operations.h"
#include "define.h"
#include "print.h"

// Initialize SPI Clock Frequency for Display
void init_host(void) {
	phost = &host;
	App_Common_Init(&host);
}

// Setup Graphics Controller
void initialize_graphics_controller(void) {
	fontAddr = RAM_G;

	if (graphics_test_flag == 1){
		return;
	}

	graphics_test_flag = 1;

	Gpu_CoCmd_FlashFast(phost, 0);
	App_Flush_Co_Buffer(phost);
	Gpu_Hal_WaitCmdfifo_empty(phost);
	Gpu_CoCmd_Dlstart(phost);

	graphics_test_flag = 0;
}

// Unset GPIO to power off the display
void display_power_down(void) {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
	UI_lastState = 0;
}

// Set GPIO to power on the display
void display_power_up(void) {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
	UI_lastState = 0;
}

// Display a page
void launch_dash(void) {
	App_WrCoCmd_Buffer(phost, DISPLAY());
}

// Clearscreen
void clearscreen(void) {
	App_WrCoCmd_Buffer(phost, CLEAR(1, 1, 1));
}

// Clears buffer in the end of every loop
void clear_buffer(void) {
	Gpu_CoCmd_Swap(phost);
	Gpu_CoCmd_Dlstart(phost);
	App_Flush_Co_Buffer(phost);
	Gpu_Hal_WaitCmdfifo_empty(phost);
}

// Load Images
void Load_ImageASTC(Gpu_Hal_Context_t *phost, uint32_t adr, uint16_t fmt, uint16_t iw, uint16_t ih, uint16_t position_X, uint16_t position_Y) {

//	Gpu_CoCmd_Dlstart(phost);
	Gpu_CoCmd_FlashSource(phost, adr);

	// Set address of the flash to load the image
	Gpu_CoCmd_SetBitmap(phost, (0x800000 | adr / 32), fmt, iw, ih);

	// Load the image in the form of Bitmap
	App_WrCoCmd_Buffer(phost, BEGIN(BITMAPS));
	App_WrCoCmd_Buffer(phost, VERTEX2II(position_X, position_Y, 0, 0));
	App_WrCoCmd_Buffer(phost, END());
	App_WrCoCmd_Buffer(phost, RESTORE_CONTEXT());

//	Gpu_CoCmd_Swap(phost);
}

/*
 *	(x_axis, y_axis) -> Mid-point of the base of the triangle
 *	height -> height of the triangle
 */
void Draw_Triangle(int x_axis, int y_axis, int height, int border_width, int rgb[3]){

	int base_y_position	= y_axis;
	int top_y_position	= (y_axis - height);
//	int colors = rgb[0];
//	int border_width	= 1;

	load_color_black();

	for (int i = 0; i < 20; i++){

		if (top_y_position + (i*2) <= (base_y_position + border_width)){
			App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
			App_WrCoCmd_Buffer(phost, LINE_WIDTH(32));
			App_WrCoCmd_Buffer(phost, VERTEX2II(x_axis + i, (top_y_position - border_width) + (i*2), 0, 0));
			App_WrCoCmd_Buffer(phost, VERTEX2II(x_axis + i + 1, base_y_position + border_width, 0, 0));
			App_WrCoCmd_Buffer(phost, END());

			App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
			App_WrCoCmd_Buffer(phost, VERTEX2II(x_axis - i, (top_y_position - border_width) + (i*2), 0, 0));
			App_WrCoCmd_Buffer(phost, VERTEX2II(x_axis - i - 1, base_y_position + border_width, 0, 0));
			App_WrCoCmd_Buffer(phost, END());
		}
	}

	App_WrCoCmd_Buffer(phost, COLOR_RGB(rgb[0], rgb[1], rgb[2]));
//	load_color_red();

	for (int i = 0; i < 20; i++){

		if (top_y_position + (i*2) <= base_y_position){
			App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
			App_WrCoCmd_Buffer(phost, LINE_WIDTH(32));
			App_WrCoCmd_Buffer(phost, VERTEX2II(x_axis + i, top_y_position + (i*2), 0, 0));
			App_WrCoCmd_Buffer(phost, VERTEX2II(x_axis + i + 1, base_y_position, 0, 0));
			App_WrCoCmd_Buffer(phost, END());

			App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
			App_WrCoCmd_Buffer(phost, VERTEX2II(x_axis - i, top_y_position + (i*2), 0, 0));
			App_WrCoCmd_Buffer(phost, VERTEX2II(x_axis - i - 1, base_y_position, 0, 0));
			App_WrCoCmd_Buffer(phost, END());
		}
	}

	App_WrCoCmd_Buffer(phost, LINE_WIDTH(12));
}


