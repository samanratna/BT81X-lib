// Load Local libraries
#include "ota_ui_pages.h"
#include "design_elements.h"
#include "print.h"


void Precheck_SoC(void) {

	OTA_download_completion_pct = 0;
	OTA_est_time = 0;

	memset(dash_OTA_download_pct, 0, sizeof(dash_OTA_download_pct));
	memset(dash_OTA_eta_time, 0, sizeof(dash_OTA_eta_time));

	initialize_graphics_controller();
	background_color_black();
	clearscreen();

	show_small_yatri_logo();

	Barlow_bold_32();
	load_color_white();
	Gpu_CoCmd_Text(phost, 240, 90, 1, OPT_CENTERX, "Checking");

	load_color_turquoise();
	Gpu_CoCmd_Text(phost, 203, 135, 1, 0, "SoC");
	dynamic_dot(262, 135);

	UI_lastState = 1;

	launch_dash();
	clear_buffer();
//	HAL_Delay(100);
}

void Precheck_Network_Strength(void) {

	initialize_graphics_controller();
	background_color_black();
	clearscreen();

	show_small_yatri_logo();

	Barlow_bold_32();
	load_color_white();
	Gpu_CoCmd_Text(phost, 240, 90, 1, OPT_CENTERX, "Checking");

	load_color_turquoise();
	Gpu_CoCmd_Text(phost, 225, 135, 1, OPT_CENTERX, "Network Connectivity");
	dynamic_dot(380, 135);

	UI_lastState = 1;

	launch_dash();
	clear_buffer();
//	HAL_Delay(100);
}

void Precheck_Firmware_Version(void) {

	initialize_graphics_controller();
	background_color_black();
	clearscreen();

	show_small_yatri_logo();

	Barlow_bold_32();
	load_color_white();
	Gpu_CoCmd_Text(phost, 240, 90, 1, OPT_CENTERX, "Checking");

	load_color_turquoise();
	Gpu_CoCmd_Text(phost, 228, 135, 1, OPT_CENTERX, "Version");
	dynamic_dot(287, 135);

	UI_lastState = 1;

	launch_dash();
	clear_buffer();
//	HAL_Delay(100);
}

void Precheck_Balance(void) {

	initialize_graphics_controller();
	background_color_black();
	clearscreen();

	show_small_yatri_logo();

	Barlow_bold_32();
	load_color_white();
	Gpu_CoCmd_Text(phost, 240, 90, 1, OPT_CENTERX, "Checking");

	load_color_turquoise();
	Gpu_CoCmd_Text(phost, 230, 135, 1, OPT_CENTERX, "Balance in Wallet");
	dynamic_dot(354, 135);

	UI_lastState = 1;

	launch_dash();
	clear_buffer();
//	HAL_Delay(100);
}

void Downloading_Firmware(void) {

	initialize_graphics_controller();
	background_color_black();
	clearscreen();

	background_color_grey_118();
	load_color_white();
	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
	App_WrCoCmd_Buffer(phost, LINE_WIDTH(50));
	App_WrCoCmd_Buffer(phost, VERTEX2II(120, 125, 0, 0));
	App_WrCoCmd_Buffer(phost, VERTEX2II(360, 135, 0, 0));
	App_WrCoCmd_Buffer(phost, END());

	load_color_turquoise();
	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
	App_WrCoCmd_Buffer(phost, LINE_WIDTH(50));
	App_WrCoCmd_Buffer(phost, VERTEX2II(120, 125, 0, 0));
	App_WrCoCmd_Buffer(phost, VERTEX2II(120 + (240 * OTA_download_completion_pct) / 100, 135, 0, 0));
	App_WrCoCmd_Buffer(phost, END());

	show_small_yatri_logo();

	Barlow_bold_32();
	load_color_white();
	sprint(dash_OTA_download_pct, "%d", OTA_download_completion_pct);
	Gpu_CoCmd_Text(phost, 256, 75, 1, OPT_RIGHTX, dash_OTA_download_pct);

	Barlow_bold_18();
	Gpu_CoCmd_Text(phost, 258, 85, 1, 0, "%");

	Barlow_bold_20();
	sprint(dash_OTA_eta_time, "%d minutes remaining", OTA_est_time);
	Gpu_CoCmd_Text(phost, 240, 155, 1, OPT_CENTERX, dash_OTA_eta_time);

	UI_lastState = 1;

	launch_dash();
	clear_buffer();
//	HAL_Delay(100);
}

void Installing_Firmware(void) {

	initialize_graphics_controller();
	background_color_black();
	clearscreen();

	show_small_yatri_logo();

	Barlow_bold_32();
//	load_color_turquoise();
	r2p();
	Gpu_CoCmd_Text(phost, 240, 80, 1, OPT_CENTERX, "Installing Updates");
	load_color_white();
	Barlow_semibold_20();
	Gpu_CoCmd_Text(phost, 240, 125, 1, OPT_CENTERX, "The screen will turn off automatically");
	Gpu_CoCmd_Text(phost, 240, 145, 1, OPT_CENTERX, "after the update completes.");

	UI_lastState = 1;

	launch_dash();
	clear_buffer();
//	HAL_Delay(100);
}

void Firmware_Installation_Successful(void) {

	initialize_graphics_controller();
	background_color_black();
	clearscreen();

	show_small_yatri_logo();

	Barlow_bold_32();
	load_color_white();
	Gpu_CoCmd_Text(phost, 100, 110, 1, 0, "Firmware");

	load_color_turquoise();
	Gpu_CoCmd_Text(phost, 245, 110, 1, 0, "Updated");
	Gpu_CoCmd_Text(phost, 368, 110, 1, 0, "!");

	UI_lastState = 1;

	launch_dash();
	clear_buffer();

	HAL_Delay(2000);
	if (ota_trigger_from_esp == 1) {
		ota_trigger_from_esp = 0;
		display_power_down();
	}
}

void Firmware_Installation_Failed(void) {

	initialize_graphics_controller();
	background_color_black();
	clearscreen();

	show_small_yatri_logo();

	Barlow_bold_32();
	load_color_white();
	Gpu_CoCmd_Text(phost, 240, 90, 1, OPT_CENTERX, "Firmware Update");

	load_color_turquoise();
	Gpu_CoCmd_Text(phost, 240, 135, 1, OPT_CENTERX, "Failed!");

	UI_lastState = 1;

	launch_dash();
	clear_buffer();

	if (OTA_received == 1) {
		OTA_failed_timer_start = 1;
	}

	HAL_Delay(2000);
	if (ota_trigger_from_esp == 1) {
		ota_trigger_from_esp = 0;
		display_power_down();
	}
}

void Network_Connection_Error(void) {

	initialize_graphics_controller();
	background_color_black();
	clearscreen();

	show_small_yatri_logo();

	Barlow_bold_32();
	load_color_white();
	Gpu_CoCmd_Text(phost, 240, 90, 1, OPT_CENTERX, "Network");

	load_color_turquoise();
	Gpu_CoCmd_Text(phost, 240, 135, 1, OPT_CENTERX, "Connection Error");

	UI_lastState = 1;

	launch_dash();
	clear_buffer();
	HAL_Delay(2000);
	OTA_received = 0;
}

void Firmware_Version_Upto_Date(void) {

	initialize_graphics_controller();
	background_color_black();
	clearscreen();

	show_small_yatri_logo();

	Barlow_bold_32();
	load_color_white();
	Gpu_CoCmd_Text(phost, 240, 90, 1, OPT_CENTERX, "You are already");

	load_color_turquoise();
	Gpu_CoCmd_Text(phost, 240, 135, 1, OPT_CENTERX, "up to date!");

	UI_lastState = 1;

	launch_dash();
	clear_buffer();
	HAL_Delay(2000);
	OTA_received = 0;
}

void Insufficient_SoC_For_OTA(void) {

	initialize_graphics_controller();
	background_color_black();
	clearscreen();

	show_small_yatri_logo();

	Barlow_bold_32();
	load_color_white();
	Gpu_CoCmd_Text(phost, 240, 90, 1, OPT_CENTERX, "Insufficient SoC");

	load_color_turquoise();
	Gpu_CoCmd_Text(phost, 238, 135, 1, OPT_CENTERX, "Please Charge");
	dynamic_exclamation(340, 135);

	UI_lastState = 1;

	launch_dash();
	clear_buffer();
	HAL_Delay(2000);
	OTA_received = 0;
}

void Insufficient_Balance_For_OTA(void) {

	initialize_graphics_controller();
	background_color_black();
	clearscreen();

	show_small_yatri_logo();

	Barlow_bold_32();
	load_color_white();
	Gpu_CoCmd_Text(phost, 240, 90, 1, OPT_CENTERX, "Insufficient Balance");

	load_color_turquoise();
	Gpu_CoCmd_Text(phost, 240, 135, 1, OPT_CENTERX, "Please Recharge!");

	UI_lastState = 1;

	launch_dash();
	clear_buffer();
	HAL_Delay(2000);
	OTA_received = 0;
}

//void show_OTA_popup(void) {
//
//	load_color_turquoise();
//	App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
//	App_WrCoCmd_Buffer(phost, VERTEX2II(25, 9, 0, 0));
//	App_WrCoCmd_Buffer(phost, VERTEX2II(190, 34, 0, 0));
//	App_WrCoCmd_Buffer(phost, END());
//
//	Barlow_bold_20();
//	load_color_white();
//	Gpu_CoCmd_Text(phost, 105, 25, 1, OPT_CENTERX | OPT_CENTERY, "OTA Available!");
//}

