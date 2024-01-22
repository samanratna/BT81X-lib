/*
 * graphical_operations.h
 *
 *  Created on: Dec 21, 2022
 *      Author: samanratnabuddhacharya
 */

#ifndef SRC_GRAPHICAL_OPERATIONS_H_
#define SRC_GRAPHICAL_OPERATIONS_H_

#include "Platform.h"
#include "App_Common.h"

#include "ble_ui_pages.h"
#include "charging_ui_pages.h"
#include "ota_ui_pages.h"
#include "primary_ui_pages.h"
#include "wish_message_pages.h"

#include "color_elements.h"
#include "fonts.h"

extern Gpu_Hal_Context_t host, *phost;
extern uint32_t fontAddr;

void init_host(void);
void initialize_graphics_controller(void);
void display_power_down(void);
void display_power_up(void);
void launch_dash(void);
void clearscreen(void);
void clear_buffer(void);
void Load_ImageASTC(Gpu_Hal_Context_t *phost, uint32_t adr, uint16_t fmt, uint16_t iw, uint16_t ih, uint16_t position_X, uint16_t position_Y);
void Draw_Triangle(int x_axis, int y_axis, int height, int border_width, int rgb[3]);

uint8_t random_lim(uint8_t lim);
uint8_t random_range(uint8_t min, uint8_t lim);

#endif /* SRC_GRAPHICAL_OPERATIONS_H_ */
