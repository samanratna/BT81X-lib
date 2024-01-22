/*
 * color_elements.c
 *
 *  Created on: Dec 20, 2022
 *      Author: samanratnabuddhacharya
 */

// Load Standard libraries
#include <stdio.h>
#include <stdbool.h>

// Load Riverdi libraries
#include "Platform.h"
#include "App_Common.h"

#include "graphical_operations.h"
#include "color_elements.h"
#include "define.h"

// Load Local Libraries
#include "main.h"

#define COLOR_VAL(x) ((4UL<<24)|x)
#define CLEAR_COLOR_VAL(x) ((2UL<<24)|x)

extern int ui_color[5];
int popup_color[6];

// Font colors
void load_color_turquoise(void) {
	App_WrCoCmd_Buffer(phost, COLOR_RGB(0, 206, 209));
}

void load_color_blue(void) {
	App_WrCoCmd_Buffer(phost, COLOR_RGB(92, 148, 255));
}

void load_color_black(void) {
	App_WrCoCmd_Buffer(phost, COLOR_RGB(0, 0, 0));
}

void load_color_orange(void) {
	App_WrCoCmd_Buffer(phost, COLOR_RGB(255, 153, 0));
}

void load_color_sap_green(void) {
	App_WrCoCmd_Buffer(phost, COLOR_RGB(0, 160, 47));
}

void load_color_red(void) {
	App_WrCoCmd_Buffer(phost, COLOR_RGB(255, 100, 100));
}

// Data color on UI
void load_text_color(void) {
//	App_WrCoCmd_Buffer(phost, COLOR_RGB(ui_color[1][0], ui_color[1][1], ui_color[1][2]));
	App_WrCoCmd_Buffer(phost, ui_color[1]);
}

// Sidelight Color
void load_sidelight_color(void) {
	App_WrCoCmd_Buffer(phost, COLOR_RGB(0, 206, 209));
}

void load_color_lightMode_gray(void) {
	App_WrCoCmd_Buffer(phost, COLOR_RGB(184, 184, 184));
}

void load_color_white(void) {
//	App_WrCoCmd_Buffer(phost, COLOR_VAL(0xffffff));
	App_WrCoCmd_Buffer(phost, COLOR_RGB(255, 255, 255));
}

void set_background_color(void) {
	App_WrCoCmd_Buffer(phost, ui_color[0]);
//	App_WrCoCmd_Buffer(phost, CLEAR_COLOR_RGB(ui_color[0][0], ui_color[0][1], ui_color[0][2]));
	App_WrCoCmd_Buffer(phost, CLEAR(1, 1, 1));
}

void set_background_color_wallpaper(void) {
	App_WrCoCmd_Buffer(phost, ui_color[3]);
//	App_WrCoCmd_Buffer(phost, COLOR_RGB(255, 255, 255));
//	App_WrCoCmd_Buffer(phost, COLOR_RGB(ui_color[3][0], ui_color[3][1], ui_color[3][2]));
	App_WrCoCmd_Buffer(phost, CLEAR(1, 1, 1));
}

void background_color_white(void) {
	App_WrCoCmd_Buffer(phost, CLEAR_COLOR_RGB(255, 255, 255));
	App_WrCoCmd_Buffer(phost, CLEAR(1, 1, 1));
}

void background_color_black(void) {
	App_WrCoCmd_Buffer(phost, COLOR_RGB(200, 100, 10));
	App_WrCoCmd_Buffer(phost, CLEAR(1, 1, 1));
}

void background_color_grey_118(void) {
	App_WrCoCmd_Buffer(phost, COLOR_RGB(118, 118, 118));
	App_WrCoCmd_Buffer(phost, CLEAR(1, 1, 1));
}

void load_color_darkMode_gray(void) {
	App_WrCoCmd_Buffer(phost, COLOR_RGB(0, 0, 0));
}

void load_color_lightMode_grey_137(void) {
	App_WrCoCmd_Buffer(phost, COLOR_RGB(137, 137, 137));
}

void load_color_lightMode_grey_196() {
	App_WrCoCmd_Buffer(phost, COLOR_RGB(196, 196, 196));
}

void load_color_lightMode_grey_155() {
	App_WrCoCmd_Buffer(phost, COLOR_RGB(155, 155, 155));
}

void load_color_light_green(){
	App_WrCoCmd_Buffer(phost, COLOR_RGB(0, 217, 22));
}

void load_color_dark_green(){
	App_WrCoCmd_Buffer(phost, COLOR_RGB(0, 185, 55));
}

void load_color_grey_30(){
	App_WrCoCmd_Buffer(phost, COLOR_RGB(30, 30, 30));
}

void r2p(void){
	App_WrCoCmd_Buffer(phost, COLOR_RGB(r_value, g_value, b_value));
}

void set_darkmode_ui_design_elements(void) {

	// Background color
//	ui_color[0][0] = 35;
//	ui_color[0][1] = 35;
//	ui_color[0][2] = 35;
	ui_color[0] = CLEAR_COLOR_VAL(0x232323);

//	(ui_color[0] = (4UL<<24)|(((23)&255UL)<<16)|(((23)&255UL)<<8)|(((23)&255UL)<<0));

	// Text color
	ui_color[1] = COLOR_VAL(0xffffff);
//	ui_color[1][0] = 255;
//	ui_color[1][1] = 255;
//	ui_color[1][2] = 255;

	// Mode Value
//	ui_color[2][0] = 255;
//	ui_color[2][1] = 255;
//	ui_color[2][2] = 255;
	ui_color[2] = COLOR_VAL(0xffffff);


	// Background Wallpaper color
//	ui_color[3][0] = 35;
//	ui_color[3][1] = 35;
//	ui_color[3][2] = 35;
	ui_color[3] = COLOR_VAL(0x232323);


	// Transparent film color
//	ui_color[4][0] = 200;
//	ui_color[4][1] = 200;
//	ui_color[4][2] = 200;
	ui_color[4] = COLOR_VAL(0xC8C8C8);





//	// Transparency level [0 -> 255]
//	ui_color[5][0] = 150;
}

void set_lightmode_ui_design_elements(void) {

	// Background color
//	ui_color[0][0] = 255;
//	ui_color[0][1] = 255;
//	ui_color[0][2] = 255;
	ui_color[0] = CLEAR_COLOR_VAL(0xffffff);

	// Text color
//	ui_color[1][0] = 0;
//	ui_color[1][1] = 0;
//	ui_color[1][2] = 0;
	ui_color[1] = COLOR_VAL(0x000000);

	// Mode Value
//	ui_color[2][0] = 0;
//	ui_color[2][1] = 206;
//	ui_color[2][2] = 209;
	ui_color[2] = COLOR_VAL(0x00CED1);

	// Background Wallpaper color
//	ui_color[3][0] = 255;
//	ui_color[3][1] = 255;
//	ui_color[3][2] = 255;
	ui_color[3] = COLOR_VAL(0xffffff);

	// Transparent film color
//	ui_color[4][0] = 255;
//	ui_color[4][1] = 255;
//	ui_color[4][2] = 255;
	ui_color[4] = COLOR_VAL(0xffffff);

//	// Transparency level [0 -> 255]
//	ui_color[5][0] = 200;
}

void set_ui_mode(void) {

	switch (ui_mode) {

		case LIGHT_MODE:

			// Light Mode
			set_lightmode_ui_design_elements();
			set_light_mode_pop_ui_elements_color_elements();
			break;

		case DARK_MODE:

			// Dark Mode
			set_darkmode_ui_design_elements();
			set_dark_mode_pop_ui_elements_color_elements();
			break;
	}
}

void transparent_film_color(void){
	App_WrCoCmd_Buffer(phost, ui_color[4]);
//	App_WrCoCmd_Buffer(phost, COLOR_RGB(ui_color[4][0], ui_color[4][1], ui_color[4][2]));
	App_WrCoCmd_Buffer(phost, CLEAR(1, 1, 1));
}

void set_light_mode_pop_ui_elements_color_elements(void){

	// pop-up wallpaper color
//	popup_color[0][0] = 210;
//	popup_color[0][1] = 210;
//	popup_color[0][2] = 210;
	popup_color[0] = COLOR_VAL(0xD2D2D2);


	// pop-up heading color
//	popup_color[1][0] = 0;
//	popup_color[1][1] = 0;
//	popup_color[1][2] = 0;
	popup_color[1] = COLOR_VAL(0x000000);

	// pop-up content color
//	popup_color[2][0] = 0;
//	popup_color[2][1] = 0;
//	popup_color[2][2] = 0;
	popup_color[2] = COLOR_VAL(0x000000);

	// divider line color
//	popup_color[3][0] = 150;
//	popup_color[3][1] = 150;
//	popup_color[3][2] = 150;
	popup_color[3] = COLOR_VAL(0x969696);

	// transparent film color
//	popup_color[4][0] = 90;
//	popup_color[4][1] = 90;
//	popup_color[4][2] = 90;
	popup_color[4] = COLOR_VAL(0x5A5A5A);

	// transparent film color for kill switch film
//	popup_color[5][0] = 64;
//	popup_color[5][1] = 64;
//	popup_color[5][2] = 64;
	popup_color[5] = COLOR_VAL(0x404040);



}

void set_dark_mode_pop_ui_elements_color_elements(void){

	// pop-up wallpaper color
//	popup_color[0][0] = 50;
//	popup_color[0][1] = 50;
//	popup_color[0][2] = 50;
	popup_color[0] = COLOR_VAL(0x323232);

	// pop-up heading color
//	popup_color[1][0] = 200;
//	popup_color[1][1] = 200;
//	popup_color[1][2] = 200;
	popup_color[1] = COLOR_VAL(0x404040);

	// pop-up content color
//	popup_color[2][0] = 180;
//	popup_color[2][1] = 180;
//	popup_color[2][2] = 180;
	popup_color[2] = COLOR_VAL(0xB4B4B4);

	// divider line color
//	popup_color[3][0] = 150;
//	popup_color[3][1] = 150;
//	popup_color[3][2] = 150;
	popup_color[3] = COLOR_VAL(0x969696);

	// transparent film color
//	popup_color[4][0] = 0;
//	popup_color[4][1] = 0;
//	popup_color[4][2] = 0;
	popup_color[4] = COLOR_VAL(0x000000);

	// transparent film color for kill switch film
//	popup_color[5][0] = 64;
//	popup_color[5][1] = 64;
//	popup_color[5][2] = 64;
//	popup_color[5] = COLOR_VAL(0x000000);
	popup_color[5] = COLOR_VAL(0x404040);

}
