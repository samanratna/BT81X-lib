// Load Local libraries
#include "primary_ui_pages.h"
#include "design_elements.h"
#include "color_elements.h"

extern int popup_color[6];

void Starting_Splashscreen(void) {

	App_Common_Init(&host);
	initialize_graphics_controller();
	clearscreen();

	starting_splashscreen_transparency_level = (starting_splashscreen_transparency_level >= 250? 250:starting_splashscreen_transparency_level + 15);

	App_WrCoCmd_Buffer(phost, COLOR_A(starting_splashscreen_transparency_level));

#if 1
	if (continue_scaling == 1){
		// New Code here
		Gpu_CoCmd_LoadIdentity(phost);
		Gpu_CoCmd_Translate(phost, 65536 * 128, 65536 * 128);
		Gpu_CoCmd_Scale(phost, (1 + starting_splashscreen_scaling) * 65536, (1 + starting_splashscreen_scaling) * 65536);
		Gpu_CoCmd_Translate(phost, 65536 * -128, 65536 * -128);
		Gpu_CoCmd_SetMatrix(phost);
	}
#endif

	Load_ImageASTC(&host, 952320, COMPRESSED_RGBA_ASTC_5x5_KHR, 300, 190, 95, 10);

#if 0
	// New Code here
	Gpu_CoCmd_LoadIdentity(phost);
	Gpu_CoCmd_Scale(phost,1 * 65536, 1 * 65536);
	Gpu_CoCmd_SetMatrix(phost);
#endif

	Barlow_bold_24();
	load_color_white();

//	App_WrCoCmd_Buffer(phost, COLOR_A(starting_splashscreen_transparency_level));
	Gpu_CoCmd_Text(phost, 240, 240, 1, OPT_CENTERX | OPT_CENTERY, dash_welcome_username);

	launch_dash();
	clear_buffer();

	if (continue_scaling == 1){

		if (upscale == 1){

			if (starting_splashscreen_scaling < 0.1){

				starting_splashscreen_scaling = starting_splashscreen_scaling + 0.01;

			} else {

				upscale = 0;
			}

		} else {

			if (starting_splashscreen_scaling > 0){

				starting_splashscreen_scaling = starting_splashscreen_scaling - 0.01;

			} else {

				upscale = 1;
				continue_scaling = 0;
			}

		}
	}

	UI_lastState = 1;
}

void Ending_Splashscreen(void) {

	clearscreen();

	if (initiate_ending_splashscreen_fade){

		ending_splashscreen_transparency_level -= 15;
	}

	App_WrCoCmd_Buffer(phost, COLOR_A(ending_splashscreen_transparency_level));

	if (initiate_downscale == 1){

		Gpu_CoCmd_LoadIdentity(phost);
		Gpu_CoCmd_Translate(phost, 65536 * 128, 65536 * 32);
		Gpu_CoCmd_Scale(phost, (1 - ending_splashscreen_scaling) * 65536, (1 - ending_splashscreen_scaling) * 65536);
		Gpu_CoCmd_Translate(phost, 65536 * -128, 65536 * -32);
		Gpu_CoCmd_SetMatrix(phost);
	}

	Load_ImageASTC(&host, 943104, COMPRESSED_RGBA_ASTC_5x5_KHR, 240, 60, 122, 110);

	Gpu_CoCmd_LoadIdentity(phost);
	Gpu_CoCmd_Scale(phost,1 * 65536, 1 * 65536);
	Gpu_CoCmd_SetMatrix(phost);

	Barlow_bold_24();
	load_color_white();

	launch_dash();
	clear_buffer();

	if (initiate_downscale == 1){
		if (ending_splashscreen_scaling < 0.8){
			ending_splashscreen_scaling += 0.05;
		} else {
			initiate_downscale = 0;
			ending_splashscreen_scaling = 0.05;
		}
	}

	UI_lastState = 1;
}


void Discharging_UI(void) {

	App_Common_Init(&host);
	initialize_graphics_controller();
	set_ui_mode();
	background_color_black();

	clearscreen();

	add_background_wallpaper();		// Rounded corners wallpaper

	show_icons_home();
	show_soc_percent_value();

	if (battery_warning){
		dynamic_warning_sign();
	}

	show_realtime();

	if (call_status == INCOMING){
		show_incoming_call_notification();
	}
	show_bikename();
	show_temperature_value();
	show_Whpkm_indicator_line();
	show_drive_mode();
	show_trip_distance();
	show_odometer();
	show_Whpkm_value();
	show_bikespeed();
	show_sidelight();

	launch_dash();
	clear_buffer();

	UI_lastState = 1;
}

void Stats_UI(void) {

	App_Common_Init(&host);
	initialize_graphics_controller();

	set_ui_mode();
	background_color_black();

	clearscreen();

	add_background_wallpaper();		// Rounded corners wallpaper
	show_icons_stats();
	show_soc_percent_value();

	if (battery_warning){
		dynamic_warning_sign();
	}
	show_realtime();

	if (call_status == INCOMING){
		show_incoming_call_notification();
	}
	show_stats_odo();
	show_ride_profile_stats();
	show_sidelight();
	show_odo_graph();
	show_bikename();

	Find_Day_of_week(present_day);

	if (ota_available_flag == 1) {
		add_transparent_film();
		popup_test();
	}

	// Show the extra UI
	if (kill_switch_status == kill_sw_OFF) {

			if (kill_switch_just_pressed){

				kill_transparency_level += 15;

			} else {

				kill_transparency_level = 240;
			}

			App_WrCoCmd_Buffer(phost, COLOR_A(kill_transparency_level));
			App_WrCoCmd_Buffer(phost, popup_color[5]);
//			App_WrCoCmd_Buffer(phost, COLOR_RGB(popup_color[5][0], popup_color[5][1], popup_color[5][2]));
//			App_WrCoCmd_Buffer(phost, COLOR_RGB(64, 64, 64));

			App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
			App_WrCoCmd_Buffer(phost, LINE_WIDTH(200));
			App_WrCoCmd_Buffer(phost, VERTEX2II(13, 13, 0, 0));
			App_WrCoCmd_Buffer(phost, VERTEX2II(467, 259, 0, 0));
			App_WrCoCmd_Buffer(phost, END());

			App_WrCoCmd_Buffer(phost, COLOR_A(kill_transparency_level + 10));

			Barlow_semibold_112();
			r2p();
			Gpu_CoCmd_Text(phost, 240, 39, 1, OPT_CENTERX, ":");

			load_color_white();
			Gpu_CoCmd_Text(phost, 160, 39, 1, OPT_CENTERX, lock_screen_time_hrs);
			Gpu_CoCmd_Text(phost, 320, 39, 1, OPT_CENTERX, lock_screen_time_min);

			Barlow_bold_24();
			Gpu_CoCmd_Text(phost, 160, 163, 1, OPT_CENTERX, today);
			Gpu_CoCmd_Text(phost, 160, 191, 1, OPT_CENTERX, lock_screen_date);
			Gpu_CoCmd_Text(phost, 368, 183, 1, 0, "%");

			Barlow_semibold_48();

			(charging_SoC > 50?load_color_light_green():(charging_SoC <= 20?load_color_red():load_color_orange()));

			Gpu_CoCmd_Text(phost, 364, 168, 1, OPT_RIGHTX, dash_dischargingSoC);

			if (kill_transparency_level >= 240){
				kill_switch_just_pressed = 0;
			}

		} else if (kill_switch_status == kill_sw_ON) {

			if (kill_switch_just_pressed){

				kill_transparency_level -= 80;

				if (kill_transparency_level <= 0){
					kill_switch_just_pressed = 0;
				}

			} else {

				kill_transparency_level = 180;
			}
		}

	launch_dash();
	clear_buffer();

	UI_lastState = 1;
	HAL_Delay(1);
}
