
// Load Local libraries
#include "ble_ui_pages.h"
#include "design_elements.h"

void Show_Passkey(void) {

	start_timeout_passkey = 1;
	initialize_graphics_controller();
	background_color_black();

	clearscreen();
	show_small_yatri_logo();

	Barlow_bold_32();
	load_color_white();
	Gpu_CoCmd_Text(phost, 240, 40, 1, OPT_CENTERX, "Passkey to pair with YatriHub");

	Barlow_semibold_48();
	load_color_turquoise();
	Gpu_CoCmd_Text(phost, 240, 88, 1, OPT_CENTERX, dash_passkey);

	Barlow_bold_32();
	load_color_white();
	Gpu_CoCmd_Text(phost, 240, 180, 1, OPT_CENTERX, dash_passkey_timeout);

	UI_lastState = 1;

	launch_dash();
	clear_buffer();
}

void Pairing_Successful(void) {

	initialize_graphics_controller();
	background_color_black();

	clearscreen();
	show_small_yatri_logo();

	Barlow_extrabold_40();
	load_color_white();
	Gpu_CoCmd_Text(phost, 240, 85, 1, OPT_CENTERX, "Pairing");

	load_color_turquoise();
	Gpu_CoCmd_Text(phost, 240, 140, 1, OPT_CENTERX, "Successful");

	UI_lastState = 1;

	launch_dash();
	clear_buffer();
}

void Pairing_Failed(void) {

	initialize_graphics_controller();
	background_color_black();

	clearscreen();
	show_small_yatri_logo();

	Barlow_extrabold_40();
	load_color_white();
	Gpu_CoCmd_Text(phost, 175, 105, 1, OPT_CENTERX, "Pairing");

	load_color_turquoise();
	Gpu_CoCmd_Text(phost, 300, 105, 1, OPT_CENTERX, "Failed");

	UI_lastState = 1;

	launch_dash();
	clear_buffer();
}
