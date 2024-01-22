


// Load Local libraries
#include "charging_ui_pages.h"
#include "design_elements.h"

void Wait_For_Verification(void) {

	initialize_graphics_controller();
	background_color_black();
	clearscreen();

	show_small_yatri_logo();

	Barlow_bold_32();
	load_color_white();
	Gpu_CoCmd_Text(phost, 240, 85, 1, OPT_CENTERX, "Please Disconnect Until");

	load_color_turquoise();
	Gpu_CoCmd_Text(phost, 1, 140, 1, 0, "Previous Transaction Completes");
	dynamic_exclamation(465, 140);

	UI_lastState = 1;

	launch_dash();
	clear_buffer();
//	HAL_Delay(10);
}

void Click_To_Disconnect_Charger(void) {

	ui_mode = DARK_MODE;
	set_ui_mode();
	App_Common_Init(&host);

	initialize_graphics_controller();
	background_color_black();
	clearscreen();

	show_small_yatri_logo();

	Barlow_bold_32();
	load_color_white();
	Gpu_CoCmd_Text(phost, 240, 85, 1, OPT_CENTERX, "Please Disconnect");
	Gpu_CoCmd_Text(phost, 157, 140, 1, 0, "the");
//	load_color_white();
	dynamic_exclamation(325, 140);

	load_color_turquoise();
	Gpu_CoCmd_Text(phost, 210, 140, 1, 0, "Charger");


	UI_lastState = 1;

	launch_dash();
	clear_buffer();
//	HAL_Delay(10);
}

void Charger_Out_Of_Service(void) {

	initialize_graphics_controller();
	background_color_black();
	clearscreen();

	show_small_yatri_logo();

	Barlow_bold_32();
	load_color_white();
	Gpu_CoCmd_Text(phost, 240, 80, 1, OPT_CENTERX, "Out of Service at the moment");

	load_color_turquoise();
	Gpu_CoCmd_Text(phost, 235, 140, 1, OPT_CENTERX, "Please Disconnect");
	dynamic_exclamation(370, 140);

	UI_lastState = 1;

	launch_dash();
	clear_buffer();
//	HAL_Delay(10);
}

void Press_Button_To_Initiate_Charging(void) {

	ui_mode = DARK_MODE;
	set_ui_mode();
	App_Common_Init(&host);

	initialize_graphics_controller();
	background_color_black();
	clearscreen();

	show_small_yatri_logo();

	Barlow_bold_32();
	load_color_white();
	Gpu_CoCmd_Text(phost, 240, 85, 1, OPT_CENTERX, "Press the Side Button");
	Gpu_CoCmd_Text(phost, 100, 140, 1, 0, "to initiate");

//	load_color_turquoise();
	r2p();
	Gpu_CoCmd_Text(phost, 242, 140, 1, 0, "Charging");

	load_color_white();
	dynamic_exclamation(372, 140);

	UI_lastState = 1;

	launch_dash();
	clear_buffer();
//	HAL_Delay(10);
}

void Insufficient_Balance_For_Charging(void) {

	initialize_graphics_controller();
	background_color_black();
	clearscreen();

	show_small_yatri_logo();

	Barlow_bold_32();
	load_color_white();
	Gpu_CoCmd_Text(phost, 240, 85, 1, OPT_CENTERX, "Insufficient Balance in Wallet");

	r2p();
	Gpu_CoCmd_Text(phost, 240, 140, 1, OPT_CENTERX, "Please Recharge!");

	UI_lastState = 1;

	launch_dash();
	clear_buffer();
//	HAL_Delay(10);
}

void Verification_Process(void) {

	initialize_graphics_controller();
	background_color_black();
	clearscreen();

	show_small_yatri_logo();

	Barlow_bold_32();
	r2p();
	Gpu_CoCmd_Text(phost, 240, 85, 1, OPT_CENTERX, "Verifying Your Bike");

	load_color_turquoise();
	Gpu_CoCmd_Text(phost, 150, 140, 1, 0, "Please Wait");
	dynamic_dot(320, 140);

	UI_lastState = 1;

	launch_dash();
	clear_buffer();
}

void Retry_Verification(void) {

	initialize_graphics_controller();
	background_color_black();
	clearscreen();

	show_small_yatri_logo();

	Barlow_bold_32();
	load_color_white();
	Gpu_CoCmd_Text(phost, 165, 85, 1, 0, "Retrying");
	dynamic_dot(290, 85);

	load_color_turquoise();
	Gpu_CoCmd_Text(phost, 240, 140, 1, OPT_CENTERX, "Please Wait");

	UI_lastState = 1;

	launch_dash();
	clear_buffer();
//	HAL_Delay(10);
}

void Verification_Failed(void) {

	initialize_graphics_controller();
	background_color_black();
	clearscreen();

	show_small_yatri_logo();

	Barlow_bold_32();
	load_color_white();
	Gpu_CoCmd_Text(phost, 240, 85, 1, OPT_CENTERX, "Verification Failed");

	load_color_turquoise();
	Gpu_CoCmd_Text(phost, 235, 140, 1, OPT_CENTERX, "Please Disconnect");
	dynamic_exclamation(370, 140);

	UI_lastState = 1;

	launch_dash();
	clear_buffer();
}

void Charging_Initiated(void) {

	ui_mode = DARK_MODE;
	set_ui_mode();
	App_Common_Init(&host);
	initialize_graphics_controller();
	clearscreen();

	background_color_grey_118();

	show_SoC_circular_bar();

	load_color_white();
	show_icons_chargingUI();
	show_charging_SoC();
	show_eta();
	show_travelBoldly();

	UI_lastState = 1;

	launch_dash();
	clear_buffer();
}





