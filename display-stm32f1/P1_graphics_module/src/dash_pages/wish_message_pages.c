
// Load Local libraries
#include "wish_message_pages.h"
#include "design_elements.h"

void Wish_Happy_Birthday(void) {

	App_Common_Init(&host);
	initialize_graphics_controller();
	background_color_black();
	clearscreen();

	show_small_yatri_logo();

	Barlow_extrabold_40();
	load_color_white();
	Gpu_CoCmd_Text(phost, 240, 70, 1, OPT_CENTERX | OPT_CENTERY, "HAPPY  BIRTHDAY !");

	Barlow_semibold_48();
	load_color_turquoise();
	Gpu_CoCmd_Text(phost, 240, 100, 1, OPT_CENTERX, dash_username);
//	Gpu_CoCmd_Text(phost, 240, 100, 1, OPT_CENTERX, "Thakur");

	Barlow_bold_24();
	load_color_lightMode_grey_137();
	Gpu_CoCmd_Text(phost, 121, 175, 1, 0, "You are");

	load_color_turquoise();
	Gpu_CoCmd_Text(phost, 208, 175, 1, 0, "#");

	load_color_white();
	Gpu_CoCmd_Text(phost, 225, 175, 1, 0, "Silently");

	load_color_turquoise();
	Gpu_CoCmd_Text(phost, 306, 175, 1, 0, "Bold");

	load_color_lightMode_grey_137();
	Gpu_CoCmd_Text(phost, 354, 175, 1, 0, ".");

	launch_dash();
	clear_buffer();
}

void Wish_Happy_New_Year(void) {

	App_Common_Init(&host);
	initialize_graphics_controller();
	background_color_black();
	clearscreen();

	show_small_yatri_logo();

	Barlow_bold_32();
	load_color_white();
	Gpu_CoCmd_Text(phost, 240, 80, 1, OPT_CENTERX | OPT_CENTERY, "HAPPY NEW YEAR");
	Gpu_CoCmd_Text(phost, 240, 125, 1, OPT_CENTERX | OPT_CENTERY, dash_year_BS);

	Barlow_semibold_32();
	load_color_turquoise();
	Gpu_CoCmd_Text(phost, 240, 170, 1, OPT_CENTERX | OPT_CENTERY, "Enjoy your ride.");

	launch_dash();
	clear_buffer();
}
