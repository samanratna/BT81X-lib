// Load Local libraries
#include "design_elements.h"
#include "launch_control.h"
#include "print.h"

extern char *seven_days_of_a_week[7];
//extern int ui_color[5][3];
extern int ui_color[5];
extern int popup_color[5];


void mode_reverse(void) {

	load_color_turquoise();
	Barlow_extrabold_28();
	Gpu_CoCmd_Text(phost, 120, 95, 1, OPT_CENTER, "REVERSE");

	load_color_lightMode_grey_155();
	Barlow_semibold_20();
	Gpu_CoCmd_Text(phost, 120, 125, 1, OPT_CENTER, "SUSTE");
	Gpu_CoCmd_Text(phost, 120, 155, 1, OPT_CENTER, "THIKKA");
	Gpu_CoCmd_Text(phost, 120, 185, 1, OPT_CENTER, "BABBAL");
}

void mode_standby(void) {

	load_color_turquoise();
	Barlow_extrabold_28();
	Gpu_CoCmd_Text(phost, 120, 95, 1, OPT_CENTER, "REVERSE");

	load_color_lightMode_grey_155();
	Barlow_semibold_20();
	Gpu_CoCmd_Text(phost, 120, 125, 1, OPT_CENTER, "SUSTE");
	Gpu_CoCmd_Text(phost, 120, 155, 1, OPT_CENTER, "THIKKA");
	Gpu_CoCmd_Text(phost, 120, 185, 1, OPT_CENTER, "BABBAL");
}

void mode_suste(void) {

	load_color_turquoise();
	Barlow_extrabold_28();
	Gpu_CoCmd_Text(phost, 120, 125, 1, OPT_CENTER, "SUSTE");

	load_color_lightMode_grey_155();
	Barlow_semibold_20();
	Gpu_CoCmd_Text(phost, 120, 95, 1, OPT_CENTER, "REVERSE");
	Gpu_CoCmd_Text(phost, 120, 155, 1, OPT_CENTER, "THIKKA");
	Gpu_CoCmd_Text(phost, 120, 185, 1, OPT_CENTER, "BABBAL");
}

void mode_thikka(void) {

	load_color_turquoise();
	Barlow_extrabold_28();
	Gpu_CoCmd_Text(phost, 120, 155, 1, OPT_CENTER, "THIKKA");

	load_color_lightMode_grey_155();
	Barlow_semibold_20();
	Gpu_CoCmd_Text(phost, 120, 95, 1, OPT_CENTER, "REVERSE");
	Gpu_CoCmd_Text(phost, 120, 125, 1, OPT_CENTER, "SUSTE");
	Gpu_CoCmd_Text(phost, 120, 185, 1, OPT_CENTER, "BABBAL");
}

void mode_babbal(void) {

	load_color_turquoise();
	Barlow_extrabold_28();
	Gpu_CoCmd_Text(phost, 120, 185, 1, OPT_CENTER, "BABBAL");

	load_color_lightMode_grey_155();
	Barlow_semibold_20();
	Gpu_CoCmd_Text(phost, 120, 95, 1, OPT_CENTER, "REVERSE");
	Gpu_CoCmd_Text(phost, 120, 125, 1, OPT_CENTER, "SUSTE");
	Gpu_CoCmd_Text(phost, 120, 155, 1, OPT_CENTER, "THIKKA");
}

void load_sidelight_right(void) {

	load_color_turquoise();
	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
	App_WrCoCmd_Buffer(phost, VERTEX2II(480, 1, 0, 0));
	App_WrCoCmd_Buffer(phost, VERTEX2II(460, 272, 0, 0));
	App_WrCoCmd_Buffer(phost, END());

//	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
//	App_WrCoCmd_Buffer(phost, LINE_WIDTH(150));
//	App_WrCoCmd_Buffer(phost, VERTEX2II(467, 13, 0, 0));
//	App_WrCoCmd_Buffer(phost, VERTEX2II(467, 259, 0, 0));
//	App_WrCoCmd_Buffer(phost, END());
//	App_WrCoCmd_Buffer(phost, LINE_WIDTH(15));
}

void load_sidelight_left(void) {

	load_color_turquoise();
	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
	App_WrCoCmd_Buffer(phost, VERTEX2II(20, 1, 0, 0));
	App_WrCoCmd_Buffer(phost, VERTEX2II(0, 272, 0, 0));
	App_WrCoCmd_Buffer(phost, END());

//	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
//	App_WrCoCmd_Buffer(phost, LINE_WIDTH(150));
//	App_WrCoCmd_Buffer(phost, VERTEX2II(13, 13, 0, 0));
//	App_WrCoCmd_Buffer(phost, VERTEX2II(13, 259, 0, 0));
//	App_WrCoCmd_Buffer(phost, END());
//	App_WrCoCmd_Buffer(phost, LINE_WIDTH(15));
}

void load_sidelight_off(void) {

	App_WrCoCmd_Buffer(phost, COLOR_RGB(255, 255, 255));
	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
	App_WrCoCmd_Buffer(phost, VERTEX2II(24, 0, 0, 0));
	App_WrCoCmd_Buffer(phost, VERTEX2II(0, 272, 0, 0));
	App_WrCoCmd_Buffer(phost, END());
}

void load_passlight_on(void) {

//	App_WrCoCmd_Buffer(phost, COLOR_RGB(92, 148, 255));
//	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
//	App_WrCoCmd_Buffer(phost, VERTEX2II(0, 0, 0, 0));
//	App_WrCoCmd_Buffer(phost, VERTEX2II(480, 15, 0, 0));
//	App_WrCoCmd_Buffer(phost, END());

}

void load_passlight_off(void) {

	if (ui_mode == 0) {
		App_WrCoCmd_Buffer(phost, COLOR_RGB(255, 255, 255));
	} else {
		App_WrCoCmd_Buffer(phost, COLOR_RGB(0, 0, 0));
	}

	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
	App_WrCoCmd_Buffer(phost, VERTEX2II(35, 0, 0, 0));
	App_WrCoCmd_Buffer(phost, VERTEX2II(445, 15, 0, 0));
	App_WrCoCmd_Buffer(phost, END());
}

void show_Whpkm_indicator_line(void) {

	load_color_lightMode_gray();
	App_WrCoCmd_Buffer(phost, BEGIN(LINES));
	App_WrCoCmd_Buffer(phost, VERTEX2II(240, 67, 0, 0));
	App_WrCoCmd_Buffer(phost, VERTEX2II(240, 199, 0, 0));
	App_WrCoCmd_Buffer(phost, END());

	if (Is_WhperKM_positive == 0) {
		load_color_turquoise();
	} else if (Is_WhperKM_positive == 1) {
		load_color_red();
	}

	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
	App_WrCoCmd_Buffer(phost, VERTEX2II(237, 133 - (WhperKM_value * 66) / 255, 0, 0));
	App_WrCoCmd_Buffer(phost, VERTEX2II(243, 133 + (WhperKM_value * 66) / 255, 0, 0));
	App_WrCoCmd_Buffer(phost, END());
}

void show_battery_logo(void) {

	App_WrCoCmd_Buffer(phost, COLOR_RGB(100, 100, 100));
	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
	App_WrCoCmd_Buffer(phost, VERTEX2II(131, 62, 0, 0));
	App_WrCoCmd_Buffer(phost, VERTEX2II(153, 68, 0, 0));
	App_WrCoCmd_Buffer(phost, END());

	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
	App_WrCoCmd_Buffer(phost, VERTEX2II(109, 70, 0, 0));
	App_WrCoCmd_Buffer(phost, VERTEX2II(174, 210, 0, 0));
	App_WrCoCmd_Buffer(phost, END());

	App_WrCoCmd_Buffer(phost, COLOR_RGB(48, 213, 200));

	soc_increasing = 210 - ((140 * charging_SoC) / 100);
	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
	App_WrCoCmd_Buffer(phost, VERTEX2II(109, soc_increasing, 0, 0));
	App_WrCoCmd_Buffer(phost, VERTEX2II(174, 210, 0, 0));

	App_WrCoCmd_Buffer(phost, END());
}

void show_drive_mode(void) {

	switch (drive_mode) {

		case REVERSE:
			mode_reverse();
			break;

		case SUSTE:
			mode_suste();
			break;

		case THIKKA:
			mode_thikka();
			break;

		case BABBAL:
			mode_babbal();
			break;
	}
}

void show_Whpkm_value(void) {

	Barlow_bold_18();
	load_text_color();
	Gpu_CoCmd_Text(phost, 224, 232, 1, OPT_RIGHTX, dash_WhperKM);
	load_color_lightMode_gray();
	Gpu_CoCmd_Text(phost, 230, 232, 1, 0, "Wh/km");
}

void show_odometer(void) {

	Barlow_bold_18();
	load_color_lightMode_gray();
	Gpu_CoCmd_Text(phost, 31, 232, 1, 0, "ODO");
	load_text_color();
	Gpu_CoCmd_Text(phost, 69, 232, 1, 0, dash_odometry);
}

void show_trip_distance(void) {

	Barlow_bold_18();
	load_color_lightMode_gray();
	Gpu_CoCmd_Text(phost, 325, 232, 1, 0, "TRIP");
	load_text_color();
	Gpu_CoCmd_Text(phost, 368, 232, 1, 0, dash_trip);
}

void show_bikespeed(void) {

	load_text_color();
	Barlow_semibold_112();

	/* dash_speed1 is the speed data from CMD CAN
	 * dash_speed is the speed data from DATA CAN structure
	 */
	Gpu_CoCmd_Text(phost, 422, 137, 1, OPT_CENTERY | OPT_RIGHTX, dash_speed1);

	load_color_turquoise();
	Barlow_bold_20();
	Gpu_CoCmd_Text(phost, 422, 194, 1, OPT_CENTERY | OPT_RIGHTX, "km/h");
}

void show_sidelight(void) {

	if (right_sidelight_status) {
		load_sidelight_right();
	}
	if (left_sidelight_status) {
		load_sidelight_left();
	}
	if (!right_sidelight_status && !left_sidelight_status) {
	}
}

void show_passlight(void) {

	if (headlight_status) {
		load_passlight_on();
	} else {
		load_passlight_off();
	}
}

void show_kill_switch_icon(void) {

	load_color_white();

	if (kill_switch_status == key_sw_OFF) {

		if (mode_button_when_Switches_ON == 1) {
			Kill_Switch_Position_Change();
		} else {
			Kill_Switch_Static();
		}
	}
}

void Kill_Switch_Static(void) {

	switch (ui_mode) {

		case LIGHT_MODE:
			Load_ImageASTC(&host, 942656, COMPRESSED_RGBA_ASTC_5x5_KHR, 25, 25, 306, 9);
			break;

		case DARK_MODE:
			Load_ImageASTC(&host, 942208, COMPRESSED_RGBA_ASTC_5x5_KHR, 25, 25, 306, 9);
			break;
	}
}

void Kill_Switch_Position_Change(void) {

	static uint8_t kill_switch_position = 0;

	if (kill_switch_position == 0) {

		switch (ui_mode) {

			case LIGHT_MODE:
				Load_ImageASTC(&host, 942656, COMPRESSED_RGBA_ASTC_5x5_KHR, 25, 25, 306, 9);
				break;

			case DARK_MODE:
				Load_ImageASTC(&host, 942208, COMPRESSED_RGBA_ASTC_5x5_KHR, 25, 25, 306, 9);
				break;
		}
		kill_switch_position = 1;

	} else if (kill_switch_position == 1) {

		switch (ui_mode) {

			case LIGHT_MODE:

				Load_ImageASTC(&host, 942656, COMPRESSED_RGBA_ASTC_5x5_KHR, 25, 25, 306, 15);
				break;

			case DARK_MODE:

				Load_ImageASTC(&host, 942208, COMPRESSED_RGBA_ASTC_5x5_KHR, 25, 25, 306, 15);
				break;
		}
		kill_switch_position = 0;
	}
}

void show_stand_icon(void) {

	load_color_white();

	if (stand_status == 1) {

		if (mode_button_when_Switches_ON == 1) {

			Stand_Switch_Position_Change();
		} else {
			Stand_Switch_Static();
		}
	}
}

void Stand_Switch_Static(void) {

	switch (ui_mode) {

		case LIGHT_MODE:
			Load_ImageASTC(&host, 744000, COMPRESSED_RGBA_ASTC_5x5_KHR, 25, 25, 333, 9);
			break;

		case DARK_MODE:
			Load_ImageASTC(&host, 1014656, COMPRESSED_RGBA_ASTC_5x5_KHR, 25, 25, 333, 9);
			break;
	}
}

void Stand_Switch_Position_Change(void) {

	static uint8_t stand_switch_position = 0;

	if (stand_switch_position == 0) {

		switch (ui_mode) {

			case LIGHT_MODE:
				Load_ImageASTC(&host, 744000, COMPRESSED_RGBA_ASTC_5x5_KHR, 25, 25, 333, 9);
				break;

			case DARK_MODE:
				Load_ImageASTC(&host, 1014656, COMPRESSED_RGBA_ASTC_5x5_KHR, 25, 25, 333, 9);
				break;
		}
		stand_switch_position = 1;

	} else if (stand_switch_position == 1) {

		switch (ui_mode) {

			case LIGHT_MODE:

				Load_ImageASTC(&host, 744000, COMPRESSED_RGBA_ASTC_5x5_KHR, 25, 25, 333, 15);
				break;

			case DARK_MODE:

				Load_ImageASTC(&host, 1014656, COMPRESSED_RGBA_ASTC_5x5_KHR, 25, 25, 333, 15);
				break;
		}
		stand_switch_position = 0;
	}
}

void show_icons_home(void) {

	show_battery_icon();
//	show_temperature_icon();
	show_bluetooth_icon();
	show_location_icon();
	show_headlight_status_icon();
	show_network_strength();

	if (series == 1) {
		show_series1_icon();
	} else {
		dont_show_series1_icon();
	}
}

void show_icons_stats(void) {

//	show_kill_switch_icon();
	show_stand_icon();
	show_bluetooth_icon();
	show_battery_icon();
	show_bike_render();
	show_headlight_status_icon();
	show_network_strength();

	if (series == 1) {
		show_series1_icon();
	} else {
		dont_show_series1_icon();
	}
}

void show_icons_chargingUI(void) {

	show_background_extrude();
	show_circle();
}

void show_SoC_circular_bar(void) {

	if (animation_interrupt == 1) {
		App_WrCoCmd_Buffer(phost, RESTORE_CONTEXT());
		animation_interrupt = 0;
	}

	load_color_turquoise();
	temp_animation_flag = allow_animation;

	if (Charging_just_started) {

		for (int i = 0; i <= charging_SoC; i++) {

			if (temp_animation_flag != allow_animation) {
				App_WrCoCmd_Buffer(phost, SAVE_CONTEXT());
				animation_interrupt = 1;
				break;
			}

			if (ending_splashscreen_flag == 1) {
				break;
			}

			ui_mode = DARK_MODE;
			set_ui_mode();
			initialize_graphics_controller();
			background_color_grey_118();
			clearscreen();

			sprint(dash_chargingSoC, "%d%%", i);

			load_color_turquoise();
			show_SoC_level(i);

			load_color_white();
			show_icons_chargingUI();

			show_charging_SoC();
			show_eta();
			show_travelBoldly();

			UI_lastState = 1;

			launch_dash();
			clear_buffer();
		}
		if (temp_animation_flag == allow_animation) {
			Charging_just_started = 0;
		}
	}
	if (temp_animation_flag == allow_animation) {
		clearscreen();
		show_SoC_level(charging_SoC);
	}
}

void show_SoC_level(int charging_SoC) {

	if (charging_SoC >= 0 && charging_SoC <= 25) {

		App_WrCoCmd_Buffer(phost, BEGIN(EDGE_STRIP_A));
		App_WrCoCmd_Buffer(phost, VERTEX2II(140, 127, 0, 0));
		App_WrCoCmd_Buffer(phost, VERTEX2II(140 + (charging_SoC * 125) / 25, 2 + (charging_SoC * 125) / 25, 0, 0));
		App_WrCoCmd_Buffer(phost, END());

	} else if (charging_SoC > 25 && charging_SoC <= 50) {

		App_WrCoCmd_Buffer(phost, BEGIN(EDGE_STRIP_A));
		App_WrCoCmd_Buffer(phost, VERTEX2II(140, 127, 0, 0));
		App_WrCoCmd_Buffer(phost, VERTEX2II(265, 127, 0, 0));
		App_WrCoCmd_Buffer(phost, END());

		App_WrCoCmd_Buffer(phost, BEGIN(EDGE_STRIP_R));
		App_WrCoCmd_Buffer(phost, VERTEX2II(140, 127, 0, 0));
		App_WrCoCmd_Buffer(phost, VERTEX2II(265 - ((charging_SoC - 25) * 125) / 25, 127 + ((charging_SoC - 25) * 125) / 25, 0, 0));
		App_WrCoCmd_Buffer(phost, END());

	} else if (charging_SoC > 50 && charging_SoC <= 75) {

		App_WrCoCmd_Buffer(phost, BEGIN(EDGE_STRIP_A));
		App_WrCoCmd_Buffer(phost, VERTEX2II(140, 127, 0, 0));
		App_WrCoCmd_Buffer(phost, VERTEX2II(265, 127, 0, 0));
		App_WrCoCmd_Buffer(phost, END());

		App_WrCoCmd_Buffer(phost, BEGIN(EDGE_STRIP_R));
		App_WrCoCmd_Buffer(phost, VERTEX2II(140, 127, 0, 0));
		App_WrCoCmd_Buffer(phost, VERTEX2II(140, 252, 0, 0));
		App_WrCoCmd_Buffer(phost, END());

		App_WrCoCmd_Buffer(phost, BEGIN(EDGE_STRIP_B));
		App_WrCoCmd_Buffer(phost, VERTEX2II(140, 127, 0, 0));
		App_WrCoCmd_Buffer(phost, VERTEX2II(140 - ((charging_SoC - 50) * 125) / 25, 252 - ((charging_SoC - 50) * 125) / 25, 0, 0));
		App_WrCoCmd_Buffer(phost, END());

	} else if (charging_SoC > 75 && charging_SoC <= 100) {

		App_WrCoCmd_Buffer(phost, BEGIN(EDGE_STRIP_A));
		App_WrCoCmd_Buffer(phost, VERTEX2II(140, 127, 0, 0));
		App_WrCoCmd_Buffer(phost, VERTEX2II(265, 127, 0, 0));
		App_WrCoCmd_Buffer(phost, END());

		App_WrCoCmd_Buffer(phost, BEGIN(EDGE_STRIP_R));
		App_WrCoCmd_Buffer(phost, VERTEX2II(140, 127, 0, 0));
		App_WrCoCmd_Buffer(phost, VERTEX2II(140, 252, 0, 0));
		App_WrCoCmd_Buffer(phost, END());

		App_WrCoCmd_Buffer(phost, BEGIN(EDGE_STRIP_B));
		App_WrCoCmd_Buffer(phost, VERTEX2II(140, 127, 0, 0));
		App_WrCoCmd_Buffer(phost, VERTEX2II(15, 127, 0, 0));
		App_WrCoCmd_Buffer(phost, END());

		App_WrCoCmd_Buffer(phost, BEGIN(EDGE_STRIP_L));
		App_WrCoCmd_Buffer(phost, VERTEX2II(140, 127, 0, 0));
		App_WrCoCmd_Buffer(phost, VERTEX2II(16 + ((charging_SoC - 75) * 125) / 25, 127 - ((charging_SoC - 75) * 125) / 25, 0, 0));
		App_WrCoCmd_Buffer(phost, END());
	}
}

void show_soc_percent_value(void) {

	if (charging_SoC <= 20) {

		load_color_red();

	} else {

		if (ui_mode == LIGHT_MODE) {
			load_color_light_green();
		} else if (ui_mode == DARK_MODE) {
			load_color_dark_green();
		}
	}

	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
	App_WrCoCmd_Buffer(phost, LINE_WIDTH(75));
	App_WrCoCmd_Buffer(phost, VERTEX2II(414, 14, 0, 0));
	App_WrCoCmd_Buffer(phost, VERTEX2II(414 + (charging_SoC * 27 / 100), 24, 0, 0));
	App_WrCoCmd_Buffer(phost, LINE_WIDTH(15));

//	switch (ui_mode) {
//
//		case LIGHT_MODE:
//			load_color_black();
//			break;
//
//		case DARK_MODE:
//			load_color_white();
//			break;
//	}

	Barlow_bold_18();
	load_color_black();

	Gpu_CoCmd_Text(phost, 424, 12, 1, OPT_CENTERX, dash_dischargingSoC);
}

void show_bikename(void) {

	load_text_color();
	Barlow_bold_20();
	Gpu_CoCmd_Text(phost, 54, 12, 1, 0, dash_bikename);
}

void show_temperature_value(void){

	switch (ui_mode) {
		case LIGHT_MODE:
			load_color_black();
			break;

		case DARK_MODE:
			load_color_white();
			break;
	}

	Barlow_bold_20();
	Gpu_CoCmd_Text(phost, 340, 12, 1, OPT_CENTERX, dash_temperature_value);
}

void show_series1_icon(void) {

	load_color_white();

	switch (ui_mode) {

		case LIGHT_MODE:
			Load_ImageASTC(&host, 1014208, COMPRESSED_RGBA_ASTC_5x5_KHR, 23, 25, 30, 8);
			break;

		case DARK_MODE:
			Load_ImageASTC(&host, 1013760, COMPRESSED_RGBA_ASTC_5x5_KHR, 23, 25, 30, 8);
			break;
	}
}

void dont_show_series1_icon(void) {

	r2p();

	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
	App_WrCoCmd_Buffer(phost, LINE_WIDTH(70));
	App_WrCoCmd_Buffer(phost, VERTEX2II(32, 12, 0, 0));
	App_WrCoCmd_Buffer(phost, VERTEX2II(49, 27, 0, 0));
	App_WrCoCmd_Buffer(phost, END());

	Barlow_bold_18();

	switch (ui_mode) {

		case LIGHT_MODE:

			load_color_white();
			break;

		case DARK_MODE:

			load_color_black();
			break;
	}
	Gpu_CoCmd_Text(phost, 30, 13, 1, 0, "P1");
}

void show_bike_render(void) {

	load_color_white();

	switch (ui_mode) {

		case LIGHT_MODE:
			Load_ImageASTC(&host, 992256, COMPRESSED_RGBA_ASTC_5x5_KHR, 160, 104, 25, 61);
			break;

		case DARK_MODE:
			Load_ImageASTC(&host, 1003008, COMPRESSED_RGBA_ASTC_5x5_KHR, 160, 104, 25, 61);
			break;
	}
}

void show_battery_icon(void) {

	switch (ui_mode) {

		case LIGHT_MODE:
			load_color_grey_30();
			break;

		case DARK_MODE:
			load_color_white();
			break;
	}

	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
	App_WrCoCmd_Buffer(phost, LINE_WIDTH(90));
	App_WrCoCmd_Buffer(phost, VERTEX2II(414, 14, 0, 0));
	App_WrCoCmd_Buffer(phost, VERTEX2II(441, 24, 0, 0));
	App_WrCoCmd_Buffer(phost, END());
//	App_WrCoCmd_Buffer(phost, LINE_WIDTH(15));

	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
	App_WrCoCmd_Buffer(phost, LINE_WIDTH(20));
	App_WrCoCmd_Buffer(phost, VERTEX2II(448, 16, 0, 0));
	App_WrCoCmd_Buffer(phost, VERTEX2II(448, 21, 0, 0));
	App_WrCoCmd_Buffer(phost, END());
//	App_WrCoCmd_Buffer(phost, LINE_WIDTH(15));

	switch (ui_mode) {

		case LIGHT_MODE:
			load_color_white();
			break;

		case DARK_MODE:
			load_color_black();
			break;
	}

	App_WrCoCmd_Buffer(phost, COLOR_RGB(174, 174, 174));
	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
	App_WrCoCmd_Buffer(phost, LINE_WIDTH(75));
	App_WrCoCmd_Buffer(phost, VERTEX2II(414, 14, 0, 0));
	App_WrCoCmd_Buffer(phost, VERTEX2II(441, 24, 0, 0));
	App_WrCoCmd_Buffer(phost, END());
	App_WrCoCmd_Buffer(phost, LINE_WIDTH(15));
}

void show_temperature_icon(void) {

	int x_position = 335;
	int y_position = 7;

	load_color_white();
	switch (ui_mode) {

		case LIGHT_MODE:

			if (controller_temperature == 0) {
				Load_ImageASTC(&host, 745408, COMPRESSED_RGBA_ASTC_5x5_KHR, 20, 24, x_position, y_position);
			} else {
				Load_ImageASTC(&host, 744768, COMPRESSED_RGBA_ASTC_5x5_KHR, 20, 24, x_position, y_position);
			}
			break;

		case DARK_MODE:

			if (controller_temperature == 0) {
				Load_ImageASTC(&host, 745088, COMPRESSED_RGBA_ASTC_5x5_KHR, 20, 24, x_position, y_position);
			} else {
				Load_ImageASTC(&host, 744448, COMPRESSED_RGBA_ASTC_5x5_KHR, 20, 24, x_position, y_position);
			}
			break;
	}
}

void show_travelBoldly(void) {

	Barlow_bold_24();
	load_color_turquoise();
	Gpu_CoCmd_Text(phost, 165, 225, 1, 0, "#");
	Gpu_CoCmd_Text(phost, 253, 225, 1, 0, "Boldly");

	load_color_white();
	Gpu_CoCmd_Text(phost, 183, 225, 1, 0, "Travel");
}

void show_bluetooth_icon(void) {

	load_color_white();
	switch (ui_mode) {

		case LIGHT_MODE:

			switch (BLE_paired) {

				case CONNECTED:
//					Load_ImageASTC(&host, 747072, COMPRESSED_RGBA_ASTC_5x5_KHR, 25, 25, 370, 8);
					Load_ImageASTC(&host, 747072, COMPRESSED_RGBA_ASTC_5x5_KHR, 25, 25, 380, 8);
					break;

				case DISCONNECTED:
//					Load_ImageASTC(&host, 747968, COMPRESSED_RGBA_ASTC_5x5_KHR, 25, 25, 370, 8);
					Load_ImageASTC(&host, 747968, COMPRESSED_RGBA_ASTC_5x5_KHR, 25, 25, 380, 8);
					break;
			}
			break;

		case DARK_MODE:

			switch (BLE_paired) {

				case CONNECTED:
//					Load_ImageASTC(&host, 746624, COMPRESSED_RGBA_ASTC_5x5_KHR, 25, 25, 368, 8);
					Load_ImageASTC(&host, 746624, COMPRESSED_RGBA_ASTC_5x5_KHR, 25, 25, 380, 8);
					break;

				case DISCONNECTED:
//					Load_ImageASTC(&host, 747520, COMPRESSED_RGBA_ASTC_5x5_KHR, 25, 25, 368, 8);
					Load_ImageASTC(&host, 747520, COMPRESSED_RGBA_ASTC_5x5_KHR, 25, 25, 380, 8);
					break;
			}
			break;
	}
}

void show_location_icon(void) {

	int x_position = 310;
	int y_position = 9;

	switch (ui_mode) {

		case LIGHT_MODE:
			switch (gps_tracking_status) {

				case ENABLED:
					Load_ImageASTC(&host, 938432, COMPRESSED_RGBA_ASTC_5x5_KHR, 20, 25, x_position, y_position);
					break;

				case DISABLED:
					Load_ImageASTC(&host, 937792, COMPRESSED_RGBA_ASTC_5x5_KHR, 20, 25, x_position, y_position);
					break;
			}
			break;

		case DARK_MODE:

			switch (gps_tracking_status) {

				case ENABLED:
					Load_ImageASTC(&host, 938112, COMPRESSED_RGBA_ASTC_5x5_KHR, 20, 25, x_position, y_position);
					break;

				case DISABLED:
					Load_ImageASTC(&host, 937472, COMPRESSED_RGBA_ASTC_5x5_KHR, 20, 25, x_position, y_position);
					break;
			}
			break;
	}
}

void show_headlight_status_icon(void) {

	if (headlight_status != HEADLIGHT_OFF){

		switch (headlight_status) {

			case LOW_BEAM:
				load_color_turquoise();
				break;

			case HIGH_BEAM:
				load_color_blue();
				break;

			default:
				break;
		}

		App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
		App_WrCoCmd_Buffer(phost, LINE_WIDTH(270));
		App_WrCoCmd_Buffer(phost, VERTEX2II(200, 20, 0, 0));
		App_WrCoCmd_Buffer(phost, VERTEX2II(280, 20, 0, 0));
		App_WrCoCmd_Buffer(phost, END());
		App_WrCoCmd_Buffer(phost, LINE_WIDTH(15));
	}
}

void show_background_extrude(void) {

	switch (ui_mode) {

		case LIGHT_MODE:
			Load_ImageASTC(&host, 852992, COMPRESSED_RGBA_ASTC_5x5_KHR, 480, 275, 0, 0);
			break;

		case DARK_MODE:
			Load_ImageASTC(&host, 768512, COMPRESSED_RGBA_ASTC_5x5_KHR, 480, 275, 0, 0);
			break;
	}
}

void show_circle(void) {

	switch (ui_mode) {

		case LIGHT_MODE:
			Load_ImageASTC(&host, 760000, COMPRESSED_RGBA_ASTC_5x5_KHR, 115, 115, 84, 69);
			Load_ImageASTC(&host, 749952, COMPRESSED_RGBA_ASTC_5x5_KHR, 40, 60, 121, 96);
			break;

		case DARK_MODE:
			Load_ImageASTC(&host, 751488, COMPRESSED_RGBA_ASTC_5x5_KHR, 115, 115, 84, 69);

			if (charger_connected_but_not_charging == 1) {

				Load_ImageASTC(&host, 748416, COMPRESSED_RGBA_ASTC_5x5_KHR, 40, 60, 121, 96);
			} else {

				Load_ImageASTC(&host, 1090560, COMPRESSED_RGBA_ASTC_5x5_KHR, 40, 60, 121, 96);
			}
			break;
	}
}

void show_charging_SoC(void) {

	Barlow_semibold_48();
	load_color_white();
	Gpu_CoCmd_Text(phost, 257, 75, 1, 0, dash_chargingSoC);  // add dash_soc variable
}

void show_eta(void) {

	switch (tier1_cmd_can) {

		case AC_CHARGING:

			if (charging_SoC >= 100) {

				Barlow_semibold_32();
//				load_color_lightMode_grey_155();
				load_color_turquoise();
				Gpu_CoCmd_Text(phost, 257, 140, 1, 0, "Fully Charged");

			} else {

				load_color_lightMode_grey_155();
				Barlow_semibold_32();
				Gpu_CoCmd_Text(phost, 257, 132, 1, 0, dash_chargingETA);

				Barlow_semibold_14();
//				load_color_lightMode_grey_155();
				Gpu_CoCmd_Text(phost, 317, 170, 1, 0, "to full charge");
			}

			break;

		case DC_CHARGING:

			if (charging_SoC < 100){

				load_color_lightMode_grey_155();
				Barlow_semibold_32();
				Gpu_CoCmd_Text(phost, 257, 132, 1, 0, dash_chargingETA);

				if (charging_SoC >= 0 && charging_SoC < 80){

					Barlow_semibold_20();
					Gpu_CoCmd_Text(phost, 257, 170, 1, 0, "to 80%");

				} else if (charging_SoC >= 80 && charging_SoC < 100){

					Barlow_semibold_14();
					Gpu_CoCmd_Text(phost, 317, 170, 1, 0, "to full charge");
				}

			} else if (charging_SoC >= 100) {

				Barlow_semibold_32();
				load_color_turquoise();
				Gpu_CoCmd_Text(phost, 257, 140, 1, 0, "Fully Charged");
			}

//			if (charging_SoC >= 0 && charging_SoC < 80) {
//
//				load_color_lightMode_grey_155();
//				Barlow_semibold_32();
//				Gpu_CoCmd_Text(phost, 257, 132, 1, 0, dash_chargingETA);
//
//				Barlow_semibold_20();
////				load_color_lightMode_grey_155();
//				Gpu_CoCmd_Text(phost, 257, 170, 1, 0, "to 80%");
//
//			} else if (charging_SoC >= 80 && charging_SoC < 100) {
//
//				load_color_lightMode_grey_155();
//				Barlow_semibold_32();
//				Gpu_CoCmd_Text(phost, 257, 132, 1, 0, dash_chargingETA);
//
//				Barlow_semibold_14();
////				load_color_lightMode_grey_155();
//				Gpu_CoCmd_Text(phost, 317, 170, 1, 0, "to full charge");
//
//			} else if (charging_SoC >= 100) {
//
//				Barlow_semibold_32();
////				load_color_lightMode_grey_155();
//				load_color_turquoise();
//				Gpu_CoCmd_Text(phost, 257, 140, 1, 0, "Fully Charged");
//			}

			break;

		default:

			break;
	}
}

void show_realtime(void) {

	load_text_color();

	if (headlight_status == 1 || headlight_status == 2) {
		load_color_white();
	}

	Barlow_bold_20();
	Gpu_CoCmd_Text(phost, 240, 11, 1, OPT_CENTERX, dash_time);
}

void show_ride_profile_stats(void) {

	load_text_color();
	Barlow_semibold_32();
	Gpu_CoCmd_Text(phost, 256, 187, 1, OPT_CENTERX, dash_mode_specific_avgSpeed);

	load_color_lightMode_grey_137();
	Barlow_bold_12();
	Gpu_CoCmd_Text(phost, 256, 225, 1, OPT_CENTERX, "AVG SPEED");

	load_text_color();
	Barlow_semibold_32();
	Gpu_CoCmd_Text(phost, 332, 187, 1, OPT_CENTERX, dash_mode_specific_maxSpeed);

	load_color_lightMode_grey_137();
	Barlow_bold_12();
	Gpu_CoCmd_Text(phost, 332, 225, 1, OPT_CENTERX, "MAX SPEED");

	load_text_color();
	Barlow_semibold_32();
	Gpu_CoCmd_Text(phost, 415, 187, 1, OPT_CENTERX, dash_mode_specific_avgWhperKM);

	load_color_lightMode_grey_137();
	Barlow_bold_12();
	Gpu_CoCmd_Text(phost, 415, 225, 1, OPT_CENTERX, "AVG WH/KM");
}

void show_stats_odo(void) {

	load_color_turquoise();
	Barlow_extrabold_24();

	switch (drive_mode_stat) {

		case 0:
			Gpu_CoCmd_Text(phost, 108, 188, 1, OPT_CENTERX, "OVERALL");
			break;

		case 1:
			Gpu_CoCmd_Text(phost, 108, 188, 1, OPT_CENTERX, "SUSTE");
			break;

		case 2:
			Gpu_CoCmd_Text(phost, 108, 188, 1, OPT_CENTERX, "THIKKA");
			break;

		case 3:
			Gpu_CoCmd_Text(phost, 108, 188, 1, OPT_CENTERX, "BABBAL");
			break;
	}

	Barlow_bold_18();
	load_color_lightMode_grey_137();
	Gpu_CoCmd_Text(phost, 59, 221, 1, 0, "ODO");

	load_text_color();
	Gpu_CoCmd_Text(phost, 99, 221, 1, 0, dash_mode_specific_odo);
}

void show_odo_graph(void) {

	calculate_range_for_barGraph();
	calculate_coordinateY_for_weekly_data();

	switch (ui_mode) {

		case LIGHT_MODE:
			load_color_lightMode_grey_196();
			break;

		case DARK_MODE:
			load_color_white();
			break;
	}

	App_WrCoCmd_Buffer(phost, BEGIN(LINES));
	App_WrCoCmd_Buffer(phost, VERTEX2II(243, 161, 0, 0));
	App_WrCoCmd_Buffer(phost, VERTEX2II(448, 162, 0, 0));
	App_WrCoCmd_Buffer(phost, END());

	show_days_in_graph(present_day);

	load_color_turquoise();
	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));

	for (int i = 0; i < 7; i++) {

		App_WrCoCmd_Buffer(phost, VERTEX2II((263 + 28 * i) + 8, 157, 0, 0));
		App_WrCoCmd_Buffer(phost, VERTEX2II((263 + 28 * i) - 8, coordinateY[i], 0, 0));
	}

	App_WrCoCmd_Buffer(phost, END());
}

void show_days_in_graph(int present_day) {

	switch (ui_mode) {

		case LIGHT_MODE:

			load_color_lightMode_grey_137();
			break;

		case DARK_MODE:
			load_color_white();
			break;
	}

	Barlow_medium_10();

	for (int i = 0; i < 7; i++) {

		if (present_day >= 0) {

			Gpu_CoCmd_Text(phost, (263 + 28 * (6 - i)), 165, 1, OPT_CENTERX, seven_days_of_a_week[present_day]);
			present_day -= 1;

		} else if (present_day < 0) {

			present_day = 6;
			Gpu_CoCmd_Text(phost, (263 + 28 * (6 - i)), 165, 1, OPT_CENTERX, seven_days_of_a_week[present_day]);
			present_day -= 1;

		}
	}
}

void show_small_yatri_logo(void) {

	load_color_white();
	Load_ImageASTC(&host, 1089024, COMPRESSED_RGBA_ASTC_5x5_KHR, 80, 20, 202, 225);
}

void add_transparent_film(void) {
	App_WrCoCmd_Buffer(phost, COLOR_A(210));
	App_WrCoCmd_Buffer(phost, popup_color[4]);
//	App_WrCoCmd_Buffer(phost, COLOR_RGB(popup_color[4][0], popup_color[4][1], popup_color[4][2]));

	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
	App_WrCoCmd_Buffer(phost, LINE_WIDTH(200));
	App_WrCoCmd_Buffer(phost, VERTEX2II(13, 13, 0, 0));
	App_WrCoCmd_Buffer(phost, VERTEX2II(467, 259, 0, 0));
	App_WrCoCmd_Buffer(phost, END());
}

void popup_test(void) {
	App_WrCoCmd_Buffer(phost, COLOR_A(255));
	App_WrCoCmd_Buffer(phost, popup_color[0]);
//	App_WrCoCmd_Buffer(phost, COLOR_RGB(popup_color[0][0], popup_color[0][1], popup_color[0][2]));
	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
	App_WrCoCmd_Buffer(phost, VERTEX2II(112, 70, 0, 0));
	App_WrCoCmd_Buffer(phost, VERTEX2II(367, 200, 0, 0));
	App_WrCoCmd_Buffer(phost, END());

	ota_info_here();
}

void ota_info_here(void) {
	App_WrCoCmd_Buffer(phost, popup_color[1]);
	Barlow_bold_18();
	Gpu_CoCmd_Text(phost, 240, 84, 1, OPT_CENTERX | OPT_CENTERY | OPT_CENTER, "New Update Available!");

	App_WrCoCmd_Buffer(phost, popup_color[3]);
//	App_WrCoCmd_Buffer(phost, popup_color[3][0], popup_color[3][1], popup_color[3][2]));

	App_WrCoCmd_Buffer(phost, BEGIN(LINES));
	App_WrCoCmd_Buffer(phost, LINE_WIDTH(10));
	App_WrCoCmd_Buffer(phost, VERTEX2II(111, 97, 0, 0));
	App_WrCoCmd_Buffer(phost, VERTEX2II(370, 97, 0, 0));
	App_WrCoCmd_Buffer(phost, END());

	load_color_white();
	App_WrCoCmd_Buffer(phost, popup_color[2]);
//	App_WrCoCmd_Buffer(phost, COLOR_RGB(popup_color[2][0], popup_color[2][1], popup_color[2][2]));
	Barlow_bold_18();
	Gpu_CoCmd_Text(phost, 125, 115, 1, 0, "Firmware v2.0.1");

	Barlow_semibold_14();
	Gpu_CoCmd_Text(phost, 125, 140, 1, 0, dash_release_notes);
}

void add_background_wallpaper(void) {
	set_background_color_wallpaper();
	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
	App_WrCoCmd_Buffer(phost, LINE_WIDTH(200));
	App_WrCoCmd_Buffer(phost, VERTEX2II(13, 13, 0, 0));
	App_WrCoCmd_Buffer(phost, VERTEX2II(467, 259, 0, 0));
	App_WrCoCmd_Buffer(phost, END());
}


void show_network_strength(void) {

	int x_position = 374;
	int top_y_position = 12;
	int base_y_position = 26;

	// weak signal bar
	App_WrCoCmd_Buffer(phost, COLOR_RGB(200, 200, 200));

	if (network_strength_value == STRONG || network_strength_value == MEDIUM || network_strength_value == WEAK){
		load_color_sap_green();
	}

	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
	App_WrCoCmd_Buffer(phost, LINE_WIDTH(32));
	App_WrCoCmd_Buffer(phost, VERTEX2II(x_position - 12, top_y_position + 12, 0, 0));
	App_WrCoCmd_Buffer(phost, VERTEX2II(x_position - 12, base_y_position, 0, 0));
	App_WrCoCmd_Buffer(phost, END());

	// medium signal bar
	App_WrCoCmd_Buffer(phost, COLOR_RGB(200, 200, 200));
	if (network_strength_value == MEDIUM || network_strength_value == STRONG){
			load_color_sap_green();
	}

	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
//	App_WrCoCmd_Buffer(phost, LINE_WIDTH(32));
	App_WrCoCmd_Buffer(phost, VERTEX2II(x_position - 6, top_y_position + 6, 0, 0));
	App_WrCoCmd_Buffer(phost, VERTEX2II(x_position - 6, base_y_position, 0, 0));
	App_WrCoCmd_Buffer(phost, END());

	// strong signal bar
	App_WrCoCmd_Buffer(phost, COLOR_RGB(200, 200, 200));
	if (network_strength_value == STRONG ){
			load_color_sap_green();
	}

	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
//	App_WrCoCmd_Buffer(phost, LINE_WIDTH(32));
	App_WrCoCmd_Buffer(phost, VERTEX2II(x_position, top_y_position, 0, 0));
	App_WrCoCmd_Buffer(phost, VERTEX2II(x_position, base_y_position, 0, 0));
	App_WrCoCmd_Buffer(phost, END());
	App_WrCoCmd_Buffer(phost, LINE_WIDTH(12));

	// No signal bar
	if (network_strength_value == NO_SIGNAL){

		App_WrCoCmd_Buffer(phost, COLOR_RGB(50, 50, 50));

		App_WrCoCmd_Buffer(phost, BEGIN(LINES));
		App_WrCoCmd_Buffer(phost, VERTEX2II(362, 14, 0, 0));
		App_WrCoCmd_Buffer(phost, VERTEX2II(374, 27, 0, 0));
		App_WrCoCmd_Buffer(phost, END());

		App_WrCoCmd_Buffer(phost, BEGIN(LINES));
		App_WrCoCmd_Buffer(phost, VERTEX2II(374, 14, 0, 0));
		App_WrCoCmd_Buffer(phost, VERTEX2II(362, 27, 0, 0));
		App_WrCoCmd_Buffer(phost, END());
	}

}

void show_incoming_call_notification(void) {

	load_color_sap_green();
	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
	App_WrCoCmd_Buffer(phost, LINE_WIDTH(390));
	App_WrCoCmd_Buffer(phost, VERTEX2II(180, y_position_call_popup, 0, 0));
	App_WrCoCmd_Buffer(phost, VERTEX2II(300, y_position_call_popup, 0, 0));
	App_WrCoCmd_Buffer(phost, END());
	App_WrCoCmd_Buffer(phost, LINE_WIDTH(15));

	Barlow_semibold_14();
	load_color_white();

	if (show_blinker){
		App_WrCoCmd_Buffer(phost, COLOR_A(incoming_call_transparency));
		Gpu_CoCmd_Text(phost, 240, y_position_call_popup - 19, 1, OPT_CENTERX, "Incoming Call");
	}

	App_WrCoCmd_Buffer(phost, COLOR_A(255));
	Barlow_bold_20();
	load_color_black();
	Gpu_CoCmd_Text(phost, 240, y_position_call_popup + 1, 1, OPT_CENTERX, "Thakur Paudel");
//	Gpu_CoCmd_Text(phost, 240, y_position_call_popup + 1, 1, OPT_CENTERX, "Ms. Shrestha");
}


