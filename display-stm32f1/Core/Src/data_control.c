/*
 * data_control.c
 *
 *  Created on: Dec 28, 2022
 *  Author: samanratnabuddhacharya
 */

#include "data_control.h"
#include "graphical_operations.h"
#include "Can_Communication.h"
#include "print.h"

extern UART_HandleTypeDef huart1;

Dash_OverallDailyOdo_Handel overall_data = { 0 };
Dash_SusteDailyOdo_Handel suste_data = { 0 };
Dash_ThikkaDailyOdo_Handel thikka_data = { 0 };
Dash_BabalDailyOdo_Handel babbal_data = { 0 };
Dash_UserInformation_Handler ride_and_rider_names = { 0 };
Dash_DateTime_Handel time_and_temperature = { 0 };
Dash_Soc_Handel SoC_and_chargingInfo = { 0 };
Dash_Auxiliary_Handel auxiliary_data = { 0 };
Dash_Indicator_Handel icons_indicator = { 0 };
Dash_SpeedWhpkm_Handel drivetrain_data = { 0 };
Dash_OdoTrip_Handler odometry = { 0 };
Dash_PassKey_Handler BLE_passkey = { 0 };
Dash_Command_Handel cmd_can = { 0 };
Dash_NewYear_Handler new_year_date = { 0 };
Dash_release_notes_Handler ui_release_notes;

int brightness_level = 128;

uint8_t tier1_cmd_can_success_ack[8] = { TIER1_CMD_CAN_SUCCESS_ACK };
uint8_t ota_available_timer_timeout_ack[8] = { OTA_UI };

extern TIM_HandleTypeDef htim4;
extern CAN_HandleTypeDef hcan;


void load_cmd_can_ack_data(uint8_t tier1_cmd, uint8_t tier2_cmd)
{

	uint8_t TXdataArray[8];

	TXdataArray[0] = tier1_cmd;
	TXdataArray[1] = tier2_cmd;

	transmit_can_message(&hcan, CMD_CAN, TXdataArray, sizeof(TXdataArray));
}


void Acquire_Data_From_CAN(uint32_t can_ID) {

		switch (can_ID) {

			case (DAILY_ODO_OVERALL):

				Load_Overall_Data_To_Display();
				break;

			case (DAILY_ODO_BABBAL):

				Load_Babbal_Data_To_Display();
				break;

			case (DAILY_ODO_THIKKA):

				Load_Thikka_Data_To_Display();
				break;

			case (DAILY_ODO_SUSTE):

				Load_Suste_Data_To_Display();
				break;

			case (RELEASE_NOTES):

				Load_Release_Notes_To_Display();
				break;

			default:

				break;
	}
}


void Load_Overall_Data_To_Display(void) {

	drive_mode_stat = 0;
	present_day = overall_data.day;

//	(uint64_t*)weekly_data[0] = *(uint64_t*)(&overall_data);

	weekly_data[6] = overall_data.overall_odo_day1;
	weekly_data[5] = overall_data.overall_odo_day2;
	weekly_data[4] = overall_data.overall_odo_day3;
	weekly_data[3] = overall_data.overall_odo_day4;
	weekly_data[2] = overall_data.overall_odo_day5;
	weekly_data[1] = overall_data.overall_odo_day6;
	weekly_data[0] = overall_data.overall_odo_day7;

//	Find_Day_of_week(present_day);

	sprint(dash_mode_specific_avgSpeed, "%d", overall_data.overall_avg_speed);
	sprint(dash_mode_specific_maxSpeed, "%d", overall_data.overall_max_speed);
	sprint(dash_mode_specific_avgWhperKM, "%d", overall_data.overall_avg_whpkm);
	sprint(dash_mode_specific_odo, "%d.%d km", (int) overall_data.overall_odo, ((int) (overall_data.overall_odo * 10)) % 10);

//	print("OVERALL  : |%d|__|%d|__|%d|__|%d|__|%d|__|%d|__|%d|__ AVG-SPEED %d __ MAX-SPEED %d __ AVG-WHPKM %d __ ODO %d.%d km\n", overall_data.overall_avg_speed, overall_data.overall_max_speed, overall_data.overall_avg_whpkm, (int) overall_data.overall_odo, ((int) (overall_data.overall_odo * 10)) % 10);
}


void Load_Suste_Data_To_Display(void) {

	drive_mode_stat = 1;
	present_day = suste_data.day;

	weekly_data[6] = suste_data.suste_odo_day1;
	weekly_data[5] = suste_data.suste_odo_day2;
	weekly_data[4] = suste_data.suste_odo_day3;
	weekly_data[3] = suste_data.suste_odo_day4;
	weekly_data[2] = suste_data.suste_odo_day5;
	weekly_data[1] = suste_data.suste_odo_day6;
	weekly_data[0] = suste_data.suste_odo_day7;

//	Find_Day_of_week(present_day);

	sprint(dash_mode_specific_avgSpeed, "%d", suste_data.suste_avg_speed);
	sprint(dash_mode_specific_maxSpeed, "%d", suste_data.suste_max_speed);
	sprint(dash_mode_specific_avgWhperKM, "%d", suste_data.suste_avg_whpkm);
	sprint(dash_mode_specific_odo, "%d.%d km", (int) suste_data.suste_odo, (int) (suste_data.suste_odo * 10) % 10);
}


void Load_Thikka_Data_To_Display(void) {

	drive_mode_stat = 2;
	present_day = thikka_data.day;

	weekly_data[6] = thikka_data.thikka_odo_day1;
	weekly_data[5] = thikka_data.thikka_odo_day2;
	weekly_data[4] = thikka_data.thikka_odo_day3;
	weekly_data[3] = thikka_data.thikka_odo_day4;
	weekly_data[2] = thikka_data.thikka_odo_day5;
	weekly_data[1] = thikka_data.thikka_odo_day6;
	weekly_data[0] = thikka_data.thikka_odo_day7;

//	Find_Day_of_week(present_day);

	sprint(dash_mode_specific_avgSpeed, "%d", thikka_data.thikka_avg_speed);
	sprint(dash_mode_specific_maxSpeed, "%d", thikka_data.thikka_max_speed);
	sprint(dash_mode_specific_avgWhperKM, "%d", thikka_data.thikka_avg_whpkm);
	sprint(dash_mode_specific_odo, "%d.%d km", (int) thikka_data.thikka_odo, (int) (thikka_data.thikka_odo * 10) % 10);
}


void Load_Babbal_Data_To_Display(void) {

	drive_mode_stat = 3;
	present_day = babbal_data.day;


	weekly_data[6] = babbal_data.babal_odo_day1;
	weekly_data[5] = babbal_data.babal_odo_day2;
	weekly_data[4] = babbal_data.babal_odo_day3;
	weekly_data[3] = babbal_data.babal_odo_day4;
	weekly_data[2] = babbal_data.babal_odo_day5;
	weekly_data[1] = babbal_data.babal_odo_day6;
	weekly_data[0] = babbal_data.babal_odo_day7;

//	Find_Day_of_week(present_day);

	sprint(dash_mode_specific_avgSpeed, "%d", babbal_data.babal_avg_speed);
	sprint(dash_mode_specific_maxSpeed, "%d", babbal_data.babal_max_speed);
	sprint(dash_mode_specific_avgWhperKM, "%d", babbal_data.babal_avg_whpkm);
	sprint(dash_mode_specific_odo, "%d.%d km", (int) babbal_data.babal_odo, (int) (babbal_data.babal_odo * 10) % 10);
}


void Load_Ride_and_Rider_Names_To_Display(void) {

	sprint(dash_welcome_username, "Welcome, %s!", ride_and_rider_names.user_name);
	sprint(dash_bikename, "%s", ride_and_rider_names.bike_name);
	sprint(dash_username, "%s", ride_and_rider_names.user_name);
}


void Load_Time_To_Display(uint8_t *data, uint32_t Receive_id, uint32_t data_len) {
	time_and_temperature = *(Dash_DateTime_Handel*)data;

//	time_and_temperature.daynight_indicator = data[3];
//	time_and_temperature.format = data[2];
//	time_and_temperature.hour = data[0];
//	time_and_temperature.minute =  data[1];
//	time_and_temperature.temperature = data[4];
//	time_and_temperature.month = data[7];
//	time_and_temperature.date = data[6];

	Find_Month_of_Year(data[7]);

	sprint(lock_screen_date, "%d %s", time_and_temperature.date, lock_screen_month);
	sprint(lock_screen_time_hrs, "%02d", time_and_temperature.hour);
	sprint(lock_screen_time_min, "%02d", time_and_temperature.minute);


	sprint(dash_time, "%02d:%02d %s", time_and_temperature.hour, time_and_temperature.minute,
			(time_and_temperature.format == 12?
					(time_and_temperature.daynight_indicator==AM?"AM":"PM"):"")
					);

//	print("CAN_ID : 0x0%x :  DATE_TIME : %s  %d-HR  %d:%d  %d-TEMP\n", Receive_id, (time_and_temperature.daynight_indicator == 0)? "DAY": "NIGHT", time_and_temperature.format, time_and_temperature.hour, time_and_temperature.minute, time_and_temperature.temperature);
}


void Load_SoC_ETA_To_Display(uint8_t *data) {

	SoC_and_chargingInfo = *((Dash_Soc_Handel*) data);

	charging_SoC = SoC_and_chargingInfo.soc;
	charger_connected_but_not_charging = SoC_and_chargingInfo.charging_current;

	sprint(dash_dischargingSoC, "%d", SoC_and_chargingInfo.soc);
	sprint(dash_chargingSoC, "%d%%", SoC_and_chargingInfo.soc);

	charging_eta = SoC_and_chargingInfo.time2fullCharge;

	charging_eta_hours = SoC_and_chargingInfo.time2fullCharge / 60;
	charging_eta_minutes = SoC_and_chargingInfo.time2fullCharge % 60;

//	sprint(dash_chargingETA, "%c%s%s%d %s%c",
//
//			(charging_eta_hours >= 1?charging_eta_hours+'0':'\0'),
//			(charging_eta_hours >= 1?" hour":""),
//			(charging_eta_hours > 1?"s ":" "),
//			charging_eta_minutes,
//			(charging_eta_hours >= 1?"min":"minute"),
//			(charging_eta_hours >= 1?' ':(charging_eta_minutes > 1?'s':' '))
//			);

	if (SoC_and_chargingInfo.time2fullCharge <= 60 && SoC_and_chargingInfo.time2fullCharge > 0) {

			sprint(dash_chargingETA, "%d minute%c", SoC_and_chargingInfo.time2fullCharge, (SoC_and_chargingInfo.time2fullCharge > 1?'s':' '));

	} else if (SoC_and_chargingInfo.time2fullCharge > 60) {

		charging_eta_hours = SoC_and_chargingInfo.time2fullCharge / 60;
		charging_eta_minutes = SoC_and_chargingInfo.time2fullCharge % 60;

		sprint(dash_chargingETA, "%d hour%c %d min", charging_eta_hours, (charging_eta_hours > 1?'s':' '), charging_eta_minutes);
	}

//	print("CAN_ID : 0x0%x :  SOC_DATA  : S0C - %d   ETA - %d MINS\n", Receive_id, SoC_and_chargingInfo.soc, SoC_and_chargingInfo.time2fullCharge);
}


void Load_Auxiliary_Info_To_Display(uint8_t *data, uint32_t Receive_id, uint32_t data_len) {

	if ((tier1_cmd_can != AC_CHARGING) && (tier1_cmd_can != DC_CHARGING)){

		auxiliary_data = *((Dash_Auxiliary_Handel*) data);

		key_status = auxiliary_data.key;
		right_sidelight_status = auxiliary_data.right_side_light;
		left_sidelight_status = auxiliary_data.left_side_light;
		low_beam_status = auxiliary_data.low_beam;
		high_beam_status = auxiliary_data.High_beam;
		drive_mode = auxiliary_data.drive_mode;
		ui_mode = auxiliary_data.display_mode;
		brightness_level = (auxiliary_data.display_brightness_level * 128) / 255;

		headlight_status = ((low_beam_status == 1 && high_beam_status == 0)?
				LOW_BEAM:
				(high_beam_status? HIGH_BEAM: HEADLIGHT_OFF));

//		if (low_beam_status == 1 && high_beam_status == 0) {
//
//			headlight_status = LOW_BEAM;
//
//		} else if (high_beam_status) {
//
//			headlight_status = HIGH_BEAM;
//
//		} else {
//
//			headlight_status = HEADLIGHT_OFF;
//		}

//		print("CAN_ID : 0x0%x :  AUX_DATA  : %s  %s  %s  %s  %s\n", Receive_id, (key_status == 1)? "KEY__ON":"KEY_OFF", (left_sidelight_status == 1)? "<<<":"===", (right_sidelight_status == 1)? ">>>":"===", (low_beam_status == 1)? "L_BEAM": "------", (high_beam_status == 1)? "H_BEAM": "------", drive_mode, ui_mode, brightness_level);
	}
}


void Load_Indicator_Icons_To_Display(uint8_t *data) {

	icons_indicator = *((Dash_Indicator_Handel*) data);

	BLE_paired = icons_indicator.ble_indicator;
	stand_status = icons_indicator.stand_indicator;
	gps_tracking_status = icons_indicator.gps_indicator;
	kill_switch_status = icons_indicator.kill_switch;

	if (kill_switch_status == kill_sw_OFF){

		kill_switch_just_pressed = 1;
		kill_transparency_level = 180;
	}

	mode_button_when_Switches_ON = icons_indicator.mode_button_when_kill_and_stand_Switch_engaged;
	controller_temperature = icons_indicator.temperature_indicator;

	sprint(dash_temperature_value, "%d", controller_temperature);
//	print("CAN_ID : 0x0%x : INDICATOR  : BLE |%s| STAND |%s| GPS |%s| KILL |%s| HOLD |%s| TEMP |%d|\n", Receive_id, (BLE_paired == 1)? "^^":"--", (stand_status == 1)? "^^":"--", (gps_tracking_status == 1)? "^^":"--", (kill_switch_status == 1)? "^^":"--", (mode_button_when_Switches_ON == 1)? "^^":"--", controller_temperature);
}


void Load_OdoTrip_Data_To_Display(uint8_t *data) {

	odometry.odo = *((float*)(&data[0]));
	odometry.trip = *((float*)(&data[4]));

	sprint(dash_odometry, "%d.%d km", (int) odometry.odo, (int) (odometry.odo * 10) % 10);
	sprint(dash_trip, "%d.%d km", (int) odometry.trip, (int) (odometry.trip * 10) % 10);

//	print("CAN_ID : 0x0%x :  ODO-TRIP  : %d.%d km   %d.%d km\n", Receive_id, (int) odometry.odo, (int) (odometry.odo * 10) % 10, (int) odometry.trip, (int) (odometry.trip * 10) % 10);
}


void Load_Passkey_To_Display(uint8_t *data, uint32_t Receive_id, uint32_t data_len) {

	BLE_passkey.passkey = *((uint32_t*)(&data[0]));

	memset(dash_passkey, 0, sizeof(dash_passkey));
	sprint(dash_passkey, "%06d", (int)BLE_passkey.passkey);

//	print("CAN_ID : 0x0%x :   PASSKEY  : %d\n", Receive_id, (int)BLE_passkey.passkey);
}


void Load_New_Year_Date_To_Display(uint8_t *data) {

	new_year_date.year = *((uint32_t*) (&data[0]));
	new_year_date.month = data[4];
	new_year_date.day = data[5];

	memset(dash_year_BS, 0, sizeof(dash_year_BS));
	sprint(dash_year_BS, "%lu", new_year_date.year);

//	print("CAN ID : 0x0%x :  NEW_YEAR  : %d - %d - %d\n", Receive_id, new_year_date.year, new_year_date.month, new_year_date.day);
}


void Load_Release_Notes_To_Display(void){

	memset(dash_release_notes, 0, sizeof(dash_release_notes));
	sprint(dash_release_notes, "%s", ui_release_notes.release_notes);

//	print("RELEASE NOTES : %s\n", dash_release_notes);
}

void Load_Username_Data(uint8_t *data, uint32_t Receive_id, uint32_t data_len){

	*((uint64_t*)dash_username) = *((uint64_t*)(&data[0]));
	dash_username[data_len] ='\0';

	sprint(dash_welcome_username, "Welcome, %s!", dash_username);
//	print("CAN_ID : 0x0%x :  USER_NAME : %s\n", Receive_id, dash_username);
}

void Load_Bikename_Data(uint8_t *data, uint32_t Receive_id, uint32_t data_len){

	*((uint64_t*)dash_bikename) = *((uint64_t*)(&data[0]));
	dash_bikename[data_len] = '\0';

//	print("CAN_ID : 0x0%x :  BIKE_NAME : %s\n", Receive_id, dash_bikename);
}

void Load_Powertrain_Data(uint8_t *data){

	bikeSpeed1 = data[0];
	WhperKM_value = data[1];
	Is_WhperKM_positive = data[2];

	sprint(dash_speed1, "%d", bikeSpeed1);
	sprint(dash_WhperKM, "%d", WhperKM_value);
}

void Load_OTA_Data(uint8_t *data){

	OTA_download_completion_pct = data[0];
	OTA_est_time = data[1];
}

void Load_Network_Strength_Value(uint8_t *data){

	network_strength_value = data[0];
}

void Jump_To_Bootloader(void){

	HAL_FLASH_Unlock();

	FLASH_EraseInitTypeDef EraseInitStruct;
	uint32_t PageError;

	EraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
	EraseInitStruct.PageAddress = 0x08003000;
	EraseInitStruct.NbPages = 1;

	HAL_FLASHEx_Erase(&EraseInitStruct, &PageError);
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, 0x08003000, 1);
	HAL_FLASH_Lock();
	HAL_NVIC_SystemReset();
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {

	if (htim == &htim4) {

		/*
		 * PRIMARY UI TIMING
		 */
		// Starting Splashscreen
		if (starting_splashscreen_flag == 1) {

			starting_splashscreen_timer++;

			ending_splashscreen_timer = 0;		// Reset Ending Splashscreen timer
			ending_splashscreen_flag = 0;		// Reset Ending Splashscreen flag

			if (starting_splashscreen_timer >= 2000) {

				starting_splashscreen_timer = 0;
				starting_splashscreen_flag = 0;
				transmit_can_message(&hcan, TIMER_TIMEOUT_ACK, tier1_cmd_can_success_ack, sizeof(tier1_cmd_can_success_ack));
			}
		}

		// Ending Splashscreen
		else if (ending_splashscreen_flag == 1) {

			ending_splashscreen_timer++;

			starting_splashscreen_timer = 0;
			starting_splashscreen_flag = 0;

			if (ending_splashscreen_timer == 1000){

				initiate_ending_splashscreen_fade = 1;
				initiate_downscale = 1;
			}

			if (ending_splashscreen_transparency_level < 40) {
			//			if (ending_splashscreen_timer >= 1300) {

				ending_splashscreen_timer = 0;
				ending_splashscreen_flag = 0;
				display_power_down();

				initiate_ending_splashscreen_fade = 0;
				ending_splashscreen_transparency_level = 250;
			}
		}

		/*
		 * BLE UI TIMING
		 */
		// Pairing Successful
		if (pairing_successful_flag == 1) {

			pairing_successful_timer++;
			if (pairing_successful_timer >= 2000) {
				pairing_successful_timer = 0;
				pairing_successful_flag = 0;
				tier1_cmd_can = STATS;
			}
		}

		// Pairing Failed
		if (pairing_failed_flag == 1) {

			pairing_failed_timer++;
			if (pairing_failed_timer >= 2000) {
				pairing_failed_timer = 0;
				pairing_failed_flag = 0;

				if (key_status == key_sw_ON){
					tier1_cmd_can = STATS;
				}
			}
		}

		// Passkey Timer
		if (pairing_passkey_flag == 1) {

			pairing_passkey_timer++;
			if (pairing_passkey_timer >= 20000) {
				pairing_passkey_timer = 0;
				pairing_passkey_flag = 0;
			}
			sprint(dash_passkey_timeout, "Timeout in %d seconds", (20 - (pairing_passkey_timer / 1000)));
		}

		/*
		 * OTA UI TIMING
		 */
		// OTA Successful
		if (ota_successful_flag == 1) {

			ota_successful_timer++;
			if (ota_successful_timer >= 2000) {
				ota_successful_timer = 0;
				ota_successful_flag = 0;
			}
		}

		// OTA Failed
		if (ota_failed_flag == 1) {

			ota_failed_timer++;
			if (ota_failed_timer >= 2000) {
				ota_failed_timer = 0;
				ota_failed_flag = 0;
			}
		}

		// OTA available
		if (ota_available_flag == 1) {

			ota_available_timer++;

			if (ota_available_timer >= 5000) {
				ota_available_timer = 0;
				ota_available_flag = 0;
				transmit_can_message(&hcan, TIMER_TIMEOUT_ACK, ota_available_timer_timeout_ack, sizeof(ota_available_timer_timeout_ack));
			}
		}

		/*
		 * WISH MESSAGE SCREEN
		 */
		// Birthday
		if (birthday_message_flag == 1) {

			ending_splashscreen_timer = 0;		// Reset Ending Splashscreen timer
			ending_splashscreen_flag = 0;		// Reset Ending Splashscreen flag

			birthday_message_timer++;
			if (birthday_message_timer >= 3000) {
				birthday_message_timer = 0;
				birthday_message_flag = 0;

				transmit_can_message(&hcan, TIMER_TIMEOUT_ACK, tier1_cmd_can_success_ack, sizeof(tier1_cmd_can_success_ack));
			}
		}

		// New Year
		if (new_year_message_flag == 1) {

			ending_splashscreen_timer = 0;		// Reset Ending Splashscreen timer
			ending_splashscreen_flag = 0;		// Reset Ending Splashscreen flag

			new_year_message_timer++;
			if (new_year_message_timer >= 3000) {
				new_year_message_timer = 0;
				new_year_message_flag = 0;

				transmit_can_message(&hcan, TIMER_TIMEOUT_ACK, tier1_cmd_can_success_ack, sizeof(tier1_cmd_can_success_ack));
			}
		}

		// Incoming Call
		if (call_status == INCOMING){

			incoming_call_blinker++;

			if (incoming_call_blinker <= call_notification_timing[0] && incoming_call_blinker > 0){
				show_blinker = 1;
				incoming_call_transparency = 255;
			}

			if (incoming_call_blinker <= (call_notification_timing[1] + call_notification_timing[0]) && incoming_call_blinker > call_notification_timing[1]){

				show_blinker = 1;
				if (incoming_call_blinker % 2 == 0){
					incoming_call_transparency--;
				}

			} else if (incoming_call_blinker > (call_notification_timing[1] + call_notification_timing[0]) && incoming_call_blinker < (call_notification_timing[2] + call_notification_timing[1] + call_notification_timing[0])) {

				show_blinker = 0;
				incoming_call_transparency = 255;

			} else if (incoming_call_blinker > (call_notification_timing[2] + call_notification_timing[1] + call_notification_timing[0])){

				incoming_call_blinker = 0;
			}
		} else {
			incoming_call_blinker = 0;
		}
	}
}



void Find_Day_of_week(int day){

	sprint(today, "%s", DAYS[day]);
}

void Find_Month_of_Year(int month){

	sprint(lock_screen_month, "%s", MONTHS[month - 1]);
}


