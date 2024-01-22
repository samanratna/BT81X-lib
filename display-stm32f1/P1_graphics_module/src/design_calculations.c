/*
 * design_calculations.c
 *
 *  Created on: Dec 21, 2022
 *      Author: samanratnabuddhacharya
 */

#include "design_calculations.h"
#include "design_elements.h"
#include "stdlib.h"
#include "print.h"

int ui_color[5];
extern char *seven_days_of_a_week[7];

//uint16_t weekly_data[7] = {50, 60, 70, 260, 20, 30, 40};

void calculate_range_for_barGraph(void) {

	present_maximum_odo = calculate_odo_max();

	if (present_maximum_odo != last_maximum_odo) {

		temp_odo_increment = present_maximum_odo;

		while (temp_odo_increment % 3 != 0 || temp_odo_increment % 10 != 0) {
			temp_odo_increment += 1;
		}

		for (int i = 0; i < 3; i++) {
			odo_graph_label[i] = (temp_odo_increment * (i + 1)) / 3;
		}
	}

	last_maximum_odo = present_maximum_odo;

	if (odo_graph_label[2] == 0) {

		odo_graph_label[0] = 10;
		odo_graph_label[1] = 20;
		odo_graph_label[2] = 30;
	}

	sprint(odo_graph_label_char1, "%d", odo_graph_label[0]);
	sprint(odo_graph_label_char2, "%d", odo_graph_label[1]);
	sprint(odo_graph_label_char3, "%d", odo_graph_label[2]);

	load_text_color();
	Barlow_medium_12();
	Gpu_CoCmd_Text(phost, 236, 65, 1, OPT_RIGHTX | OPT_CENTERY, odo_graph_label_char3);
	Gpu_CoCmd_Text(phost, 236, 97, 1, OPT_RIGHTX | OPT_CENTERY, odo_graph_label_char2);
	Gpu_CoCmd_Text(phost, 236, 129, 1, OPT_RIGHTX | OPT_CENTERY, odo_graph_label_char1);
	Gpu_CoCmd_Text(phost, 236, 164, 1, OPT_RIGHTX | OPT_CENTERY, "km");
}

void calculate_coordinateY_for_weekly_data(void) {

	for (int i = 0; i < 7; i++) {
		coordinateY[i] = ((157 - (weekly_data[i] * 92 / odo_graph_label[2])));
	}
}

uint16_t calculate_odo_max(void) {

	uint16_t max_odo = weekly_data[0];

	for (int i = 0; i < sizeof(weekly_data) / sizeof(weekly_data[0]); i++) {
		if (weekly_data[i] >= max_odo) {
			max_odo = weekly_data[i];
		}
	}
	return max_odo;
}

void dynamic_dot(int16_t x, int16_t y) {

	if (dot_count <= 10) {

		Gpu_CoCmd_Text(phost, x, y, 1, 0, ".");

	} else if (dot_count > 10 && dot_count < 20) {

		Gpu_CoCmd_Text(phost, x, y, 1, 0, "..");

	} else if (dot_count > 20 && dot_count < 30) {

		Gpu_CoCmd_Text(phost, x, y, 1, 0, "...");

	} else if (dot_count > 30 && dot_count < 50) {

		Gpu_CoCmd_Text(phost, x, y, 1, 0, "");

	} else if (dot_count >= 50) {

		dot_count = 0;
	}
	dot_count++;
}

void dynamic_exclamation(int16_t x, int16_t y) {

	if (dot_count <= 40) {

		Gpu_CoCmd_Text(phost, x, y, 1, 0, "!");

	} else if (dot_count > 40 && dot_count < 60) {

		Gpu_CoCmd_Text(phost, x, y, 1, 0, "");

	} else if (dot_count >= 60) {

		dot_count = 0;
	}
	dot_count++;
}


void dynamic_warning_sign(void) {

	if (dot_count <= 10) {

		Draw_Triangle(428, 30, 19, 1, yellow);
		Barlow_bold_24();
		load_color_black();
		Gpu_CoCmd_Text(phost, 422, 11, 1, 0, "!");

//	} else if (dot_count > 10 && dot_count < 18) {


	} else if (dot_count >= 18) {

		dot_count = 0;
	}
	dot_count++;
}

void lock_screen_colon_blink(int16_t x, int16_t y, char* character){

	if (dot_count <= 40) {

		Gpu_CoCmd_Text(phost, x, y, 1, 0, character);

	} else if (dot_count > 40 && dot_count < 60) {

		Gpu_CoCmd_Text(phost, x, y, 1, 0, "");

	} else if (dot_count >= 60) {

		dot_count = 0;
	}
	dot_count++;
}
