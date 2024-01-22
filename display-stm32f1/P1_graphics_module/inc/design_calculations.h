/*
 * design_calculations.h
 *
 *  Created on: Dec 21, 2022
 *      Author: samanratnabuddhacharya
 */

#ifndef P1_GRAPHICS_MODULE_INC_DESIGN_CALCULATIONS_H_
#define P1_GRAPHICS_MODULE_INC_DESIGN_CALCULATIONS_H_

#include "platform.h"

void calculate_range_for_barGraph(void);
void calculate_coordinateY_for_weekly_data(void);
void dynamic_dot(int16_t x, int16_t y);
void dynamic_exclamation(int16_t x, int16_t y);
void dynamic_warning_sign(void);
uint16_t calculate_odo_max(void);
void lock_screen_colon_blink(int16_t x, int16_t y, char* character);

#endif /* P1_GRAPHICS_MODULE_INC_DESIGN_CALCULATIONS_H_ */
