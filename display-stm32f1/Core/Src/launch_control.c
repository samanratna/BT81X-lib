/*
 * launch_control.c
 *
 *  Created on: Dec 23, 2022
 *      Author: samanratnabuddhacharya
 */

#include "launch_control.h"
#include "Can_Communication.h"
#include "primary_ui_pages.h"
#include "print.h"

//extern CAN_HandleTypeDef hcan;

void Select_Startup_Message_Screen(void) {

	switch (tier2_cmd_can) {

		case (NEW_YEAR_WISH):
			Wish_Happy_New_Year();
			break;

		case (BIRTHDAY_WISH):
			Wish_Happy_Birthday();
			break;
	}
}

void Select_DC_Charging_Page(void) {

	switch (tier2_cmd_can) {

		case (PRESS_BUTTON_TO_INITIATE_CHARGING):
			Press_Button_To_Initiate_Charging();
			break;

		case (VERIFICATION_PROCESS):
			Verification_Process();
			break;

		case (CHARGING_INITIATED):
			Charging_Initiated();
			break;

		case (VERIFICATION_FAILED):
			Verification_Failed();
			break;

		case (CHARGER_OUT_OF_SERVICE):
			Charger_Out_Of_Service();
			break;

		case (INSUFFICIENT_BALANCE_FOR_CHARGING):
			Insufficient_Balance_For_Charging();
			break;

		case (CLICK_TO_DISCONNECT_CHARGER):
			Click_To_Disconnect_Charger();
			break;

		case (WAIT_FOR_VERIFICATION):
			Wait_For_Verification();
			break;

		case (RETRY_VERIFICATION):
			Retry_Verification();
			break;
	}
}

void Select_Firmware_Update_Page(void) {

	switch (tier2_cmd_can) {

		case (PRECHECK_SOC):
			Precheck_SoC();
			break;

		case (INSUFFICIENT_SOC_FOR_OTA):
			Insufficient_SoC_For_OTA();
			break;

		case (PRECHECK_NETWORK_STRENGTH):
			Precheck_Network_Strength();
			break;

		case (NETWORK_CONNECTION_ERROR):
			Network_Connection_Error();
			break;

		case (PRECHECK_FIRMWARE_VERSION):
			Precheck_Firmware_Version();
			break;

		case (FIRMWARE_VERSION_UPTO_DATE):
			Firmware_Version_Upto_Date();
			break;

		case (PRECHECK_BALANCE):
			Precheck_Balance();
			break;

		case (INSUFFICIENT_BALANCE_FOR_OTA):
			Insufficient_Balance_For_OTA();
			break;

		case (DOWNLOADING_FIRMWARE):
			Downloading_Firmware();
			break;

		case (INSTALLING_FIRMWARE):
			Installing_Firmware();
			break;

		case (FIRMWARE_INSTALLATION_SUCCESSFUL):
			Firmware_Installation_Successful();
			break;

		case (FIRMWARE_INSTALLATION_FAILED):
			Firmware_Installation_Failed();
			break;
	}
}

void Select_BLE_Connection_Page(void) {

	switch (tier2_cmd_can) {

		case (SHOW_PAIRING_KEY):
			Show_Passkey();
			break;

		case (PAIRING_SUCCESSFUL):
			if (pairing_successful_flag == 1) {
				Pairing_Successful();
			}
			break;

		case (PAIRING_FAILED):
			if (key_status == key_sw_ON){
				Pairing_Failed();
			}
			break;
	}
}

void Launch_UI(void) {

#if 0
	switch (tier1_cmd_can) {
		case STARTUP_SPLASHSCREEN:
			printf("TIER1 CMD CAN :: STARTUP_SPLASHSCREEN\n");
			break;

		case STARTUP_MESSAGE_SCREEN:
			printf("TIER1 CMD CAN :: STARTUP_MESSAGE_SCREEN\n");
			break;

		case ENDING_SPLASHSCREEN:
			printf("TIER1 CMD CAN :: ENDING_SPLASHSCREEN\n");
			break;

		case STATS:
			printf("TIER1 CMD CAN :: STATS\n");
			break;

		case DRIVE_MODE:
			printf("TIER1 CMD CAN :: DRIVE_MODE\n");
			break;

		case AC_CHARGING:
			printf("TIER1 CMD CAN :: AC_CHARGING\n");
			break;

		case DC_CHARGING:
			printf("TIER1 CMD CAN :: DC_CHARGING\n");
			break;

		case OTA_UI:
			printf("TIER1 CMD CAN :: OTA_UI\n");
			break;

		case OBD_UI:
			printf("TIER1 CMD CAN :: OBD_UI\n");
			break;

		case BLE_UI:
			printf("TIER1 CMD CAN :: BLE_UI\n");
			break;

		case POWER_DOWN:
			printf("TIER1 CMD CAN :: POWER_DOWN\n");
			break;

		case SYSTEM_RESET:
			printf("TIER1 CMD CAN :: SYSTEM_RESET\n");
			break;
	}
#endif

	initialize_graphics_controller();

	switch (tier1_cmd_can) {

		case (STARTUP_SPLASHSCREEN):
			if (starting_splashscreen_flag == 1) {
				Starting_Splashscreen();
			}
			break;

		case (STARTUP_MESSAGE_SCREEN):
			Select_Startup_Message_Screen();
			break;

		case (ENDING_SPLASHSCREEN):
			if (ending_splashscreen_flag == 1) {
				Ending_Splashscreen();
			}
			break;

		case (STATS):
			Stats_UI();
			break;

		case (DRIVE_MODE):
			Discharging_UI();
			break;

		case (AC_CHARGING):
			Charging_Initiated();
			break;

		case (DC_CHARGING):
			Select_DC_Charging_Page();
			break;

		case (OTA_UI):
			Select_Firmware_Update_Page();
			break;

//		case (OBD_UI):
//			break;

		case (BLE_UI):
			Select_BLE_Connection_Page();
			break;

		case (POWER_DOWN):
			display_power_down();
			break;

		case (SYSTEM_RESET):
			HAL_NVIC_SystemReset();
			break;

		default:
			display_power_down();
//			Stats_UI();
			break;
	}
}

void Display_Backlight_Power_Recycle(void) {

	display_power_down();
	HAL_Delay(10);
	display_power_up();
}

