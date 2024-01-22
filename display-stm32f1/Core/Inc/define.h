/*
 * define.h
 *
 *  Created on: Oct 4, 2021
 *      Author: saman
 */

#pragma once

#ifndef INC_DEFINE_H_
#define INC_DEFINE_H_



#include "stm32f1xx.h"
#include <math.h>
#include "Can_Communication.h"
#include "main.h"

#define LIGHT_MODE 		0
#define DARK_MODE 		1

#define SUSTE 			1
#define THIKKA 			2
#define BABBAL 			3
#define REVERSE 		4

#define DISCONNECTED 	0
#define CONNECTED 		1

#define DISABLED 		0
#define ENABLED 		1

#define HEADLIGHT_OFF 	0
#define LOW_BEAM 		1
#define HIGH_BEAM 		2

#define temperature_limit 			60

#define TIER1_CMD_CAN_SUCCESS_ACK 	1
#define RESET_REQUEST_MSG 			1

typedef enum {
	drl_sw_ON = 1, drl_sw_OFF
} drl_sw_state;

typedef enum {
	kill_sw_ON=1 , kill_sw_OFF
} kill_sw_state;

typedef enum {
	pass_sw_ON = 1, pass_sw_OFF
} pass_sw_state;

typedef enum {
	key_sw_ON = 1, key_sw_OFF
} key_sw_state;

typedef enum {
	low_beam_sw_ON = 1, low_beam_sw_OFF
} low_beam_sw_state;

typedef enum {
	no_press, single_press = 1, double_press, long_press, system_reset
} mode_sw_state;

typedef enum {
	horn_sw_press = 1, horn_sw_release
} horn_sw_state;

typedef enum {
	rtr_sw_ON = 1, rtr_sw_OFF
} rtr_sw_state;

typedef enum {
	ltr_sw_ON = 1, ltr_sw_OFF
} ltr_sw_state;

typedef enum {
	head_light_sw_ON = 1, head_light_sw_OFF
} head_light_sw_state;

typedef enum {
	break_sw_ON = 1, break_sw_OFF
} break_sw_state;

typedef enum {
	stand_sw_ON=1, stand_sw_OFF
} stand_sw_state;


#define DAILY_ODO_OVERALL		0x0804FCFA
#define DAILY_ODO_BABBAL		0x0805FCFA
#define DAILY_ODO_THIKKA		0x0806FCFA
#define DAILY_ODO_SUSTE			0x0807FCFA
#define USER_INFO				0x0808FCFA
#define DATE_TIME			    0x0809FCFA
#define SOC_ETA					0x080AFCFA
#define AUXILIARY_DATA			0x080BFCFA
#define SPEED					0x080CFCFA
#define ODO_TRIP				0x080DFCFA
#define DASH_INDICATOR			0x080EFCFA

#define PASSKEY					0x0810FCFA
#define NEW_YEAR				0x0811FCFA
#define VEHICLE_SPEED			0x0812FCFA
#define RELEASE_NOTES			0x0813FCFA
#define NETWORK_STRENGTH_CAN	0x0814FCFA
#define OTA_JUMP_REQUEST		0x0001FCFA
#define CMD_CAN					0x080FFCFA
#define CAN_ACK_ID				0x0830FCFA

#define BIKE_SERIES				0x0860FCFA
#define USER_NAME				0x0850FCFA
#define BIKE_NAME				0x0851FCFA

#define OTA_DATA				0x0002FCFB
#define OTA_INSTALLATION_STATE	0x0001FCFB

#define RESET_REQUEST			0x1001FAFC
#define TIMER_TIMEOUT_ACK		0x1002FAFC


enum OTA_STATES {

	PRECHECK_SOC						= 1,
	INSUFFICIENT_SOC_FOR_OTA			= 2,
	PRECHECK_NETWORK_STRENGTH			= 3,
	NETWORK_CONNECTION_ERROR			= 4,
	PRECHECK_FIRMWARE_VERSION			= 5,
	FIRMWARE_VERSION_UPTO_DATE			= 6,
	PRECHECK_BALANCE					= 7,
	INSUFFICIENT_BALANCE_FOR_OTA		= 8,
	DOWNLOADING_FIRMWARE				= 9,
	INSTALLING_FIRMWARE					= 10,
	FIRMWARE_INSTALLATION_SUCCESSFUL 	= 11,
	FIRMWARE_INSTALLATION_FAILED		= 12,
	OTA_AVAILABLE						= 13
};

enum DC_CHARGING_STATES {

	PRESS_BUTTON_TO_INITIATE_CHARGING	= 0,
	VERIFICATION_PROCESS				= 1,
	CHARGING_INITIATED					= 2,
	VERIFICATION_FAILED					= 3,
	CHARGER_OUT_OF_SERVICE				= 6,
	INSUFFICIENT_BALANCE_FOR_CHARGING	= 7,
	CLICK_TO_DISCONNECT_CHARGER			= 8,
	WAIT_FOR_VERIFICATION				= 9,
	RETRY_VERIFICATION					= 10
};

enum BLE_STATES {

	SHOW_PAIRING_KEY	= 1,
	PAIRING_SUCCESSFUL	= 2,
	PAIRING_FAILED		= 3
};

enum PRIMARY_UI_STATES {

	STARTUP_SPLASHSCREEN	= 1,
	STARTUP_MESSAGE_SCREEN	= 2,
	ENDING_SPLASHSCREEN		= 3,
	STATS					= 4,
	DRIVE_MODE				= 5,
	AC_CHARGING				= 6,
	DC_CHARGING				= 7,
	OTA_UI					= 8,
	OBD_UI					= 9,
	BLE_UI					= 10,
	POWER_DOWN				= 11,
	SYSTEM_RESET			= 12,
	NETWORK_STRENGTH		= 13,
	UI_INTRUSION_INPUT		= 14
};

enum MESSAGE_SCREENS {

	NEW_YEAR_WISH	= 1,
	BIRTHDAY_WISH	= 2
};

enum NETWORK_STRENGTH {
	NO_SIGNAL	= 4,
	STRONG		= 3,
	MEDIUM		= 2,
	WEAK		= 1
};

enum CAN_ACK_UI {

	CAN_ACK_STARTUP_SPLASHSCREEN				= 1,
	CAN_ACK_ENDING_SPLASHSCREEN					= 2,
	CAN_ACK_PAIRING_SUCCESSFUL					= 3,
	CAN_ACK_PAIRING_FAILED						= 4,
	CAN_ACK_SHOW_PAIRING_KEY					= 5,
	CAN_ACK_FIRMWARE_INSTALLATION_SUCCESSFUL	= 6,
	CAN_ACK_FIRMWARE_INSTALLATION_FAILED		= 7,
	CAN_ACK_OTA_AVAILABLE						= 8,
	CAN_ACK_BIRTHDAY_WISH						= 9,
	CAN_ACK_NEW_YEAR_WISH						= 10
};

enum CAN_ACK_UI_STATES {

	BEGINNING	= 1,
	ENDING		= 2
};

enum CAN_ACK_TIMING {

	TIME_STARTING_SPLASHSCREEN				= 2000,
	TIME_ENDING_SPLASHSCREEN				= 1300,
	TIME_PAIRING_SUCCESSFUL					= 2000,
	TIME_PAIRING_FAILED						= 2000,
	TIME_SHOW_PAIRING_KEY					= 20000,
	TIME_FIRMWARE_INSTALLATION_SUCCESSFUL	= 2000,
	TIME_FIRMWARE_INSTALLATION_FAILED		= 2000,
	TIME_OTA_AVAILABLE						= 5000,
	TIME_BIRTHDAY_WISH						= 3000,
	TIME_NEW_YEAR_WISH						= 3000
};

enum CALL_NOTIFICATION_STATUS {
	IDLE		= 0,
	INCOMING	= 1,
	MISSED		= 2,
	DENIED		= 3
};

extern int series;
extern int Charging_just_started;
extern uint8_t bike_speed;
extern uint8_t Is_Head_Light;
extern uint8_t dash_Is_passlight_on;
extern uint8_t Verification_Status;
extern uint8_t charging_SoC;
extern uint8_t charging_eta;
extern uint8_t charging_eta_hours;
extern uint8_t charging_eta_minutes;
extern uint8_t discharging_SoC;
extern uint8_t onBoardCharging_Status;
extern uint8_t onBoardCharging_eta;

/*
 * AUXILIARY CONTROL
 */
extern int brightness_level;
extern int low_beam_status;
extern int high_beam_status;
extern int headlight_status;
extern uint8_t ui_mode;
extern uint8_t key_status;
extern uint8_t drive_mode;
extern uint8_t right_sidelight_status;
extern uint8_t left_sidelight_status;

extern int bikeSpeed;
extern int bikeSpeed1;

extern int battery_warning;

extern int overall_maxSpeed;
extern int trip_maxSpeed;
extern int overall_avgSpeed;
extern int trip_avgSpeed;

extern uint32_t start_time;
extern uint32_t end_time;

extern int timeout_for_passkey;
extern int write_reset;

extern uint16_t overall_travelledDistance;
extern uint16_t trip_travelledDistance;

extern uint8_t dot_count;
extern int mode_button_when_Switches_ON;
extern int UI_lastState;

// Bluetooth
extern long int passkey_value;
extern int pairing_status;
//int got_passkey;
//int pairing_success_flag;
//int pairing_failed_flag;
//int start_pairing_successful_timeout;
//int start_pairing_failed_timeout;
//int start_success_flag;
//int pairing_failed_flag;
//int out_of_pairing;
//int got_passkey;
extern int start_timeout_passkey;
extern int BLE_paired;
//long int start_success_timeout;
//long int start_failed_timeout;

extern char dash_time[20];

extern char dash_speed[30];
extern char dash_speed1[30];

extern char dash_odometry[50];
extern char dash_trip[50];
extern char dash_chargingSoC[30];
extern char dash_dischargingSoC[30];
extern char dash_chargingETA[30];
extern char dash_passkey[30];
extern char dash_passkey_timeout[30];
extern char dash_username[20];
extern char dash_welcome_username[30];
extern char dash_babye_username[30];
extern char dash_year_BS[30];
extern char dash_bikename[30];
extern char dash_WhperKM[30];

extern char dash_mode_specific_avgSpeed[30];
extern char dash_mode_specific_maxSpeed[30];
extern char dash_mode_specific_avgWhperKM[30];
extern char dash_mode_specific_odo[30];

extern char dash_temperature_value[4];

extern int BLE_timer_out;

extern unsigned int soc_increasing;
extern unsigned int current_soc_value;

extern int charger_connected_but_not_charging;
extern int first_pair;
/*
 * 1: Wall Charging
 * 2: Fast Charging
 */
extern uint8_t charging_type;

//Splashscreen timer variables

// Starting Splashscreen timeout
extern uint32_t Starting_Splashscreen_timeout_flag;
extern uint32_t Starting_Splashscreen_timer;

// Ending Splashscreen timeout
extern uint32_t Ending_Splashscreen_timeout_flag;
extern uint32_t Ending_Splashscreen_timer;

extern int odo_graph_label1;
extern char odo_graph_label_char1[100];
extern char odo_graph_label_char2[100];
extern char odo_graph_label_char3[100];
extern uint16_t odo_graph_label[3];

extern int drive_mode_stat;

extern uint16_t temp_odo_increment;
extern uint16_t coordinateY[7];
extern uint16_t present_maximum_odo;
extern uint16_t last_maximum_odo;

extern int controller_temperature;
extern int gps_tracking_status;
extern int WhperKM_value;
extern int Is_WhperKM_positive;
extern int stand_status;
extern int kill_switch_status;
extern int error_Code_Display;
extern int stats_to_home;
extern int present_day;
extern uint16_t weekly_data[8];
extern int mode_specific_avgSpeed;
extern int mode_specific_maxSpeed;
extern int mode_specific_avgWhperKM;
extern int testDataCAN;
extern int Is_watchdog_reset;
extern int dash_brightness_level;
extern uint32_t mode_specific_odo;

extern uint8_t tier1_cmd_can;
extern uint8_t tier2_cmd_can;

// OTA parameters
extern int OTA_Verification_Status;
extern int OTA_download_completion_pct;
extern int OTA_est_time;
extern int OTA_request;
extern int OTA_received;
extern int OTA_available;
extern int OTA_popup_timer_start;
extern int OTA_popup_timer_active;
extern uint16_t OTA_popup_timer;

extern int OTA_failed_timer_start;
extern uint16_t OTA_failed_timer_value;
extern int first_bike_ON;

extern char dash_OTA_download_pct[30];
extern char dash_OTA_eta_time[30];

extern uint32_t counter1;
extern int names_received;

// Starting Splashscreen Timer
extern int starting_splashscreen_flag;
extern uint32_t starting_splashscreen_timer;

// Ending Splashscreen Timer
extern int ending_splashscreen_flag;
extern uint32_t ending_splashscreen_timer;

// BLE Pairing Successful Timer
extern int pairing_successful_flag;
extern uint32_t pairing_successful_timer;

// BLE Pairing Failed Timer
extern int pairing_failed_flag;
extern uint32_t pairing_failed_timer;

// BLE Pairing Passkey Timer
extern int pairing_passkey_flag;
extern int pairing_passkey_timer;

// OTA Successful Timer
extern int ota_successful_flag;
extern uint32_t ota_successful_timer;

// OTA_Failed Timer
extern int ota_failed_flag;
extern uint32_t ota_failed_timer;

// OTA_available_popup
extern int ota_available_flag;
extern uint32_t ota_available_timer;

// Birthday Message Timer
extern int birthday_message_flag;
extern uint32_t birthday_message_timer;

// New Year Message Timer
extern int new_year_message_flag;
extern uint32_t new_year_message_timer;

extern uint32_t test_counter;
extern uint32_t engine_counter;
extern uint32_t chipid_counter;
extern int allow_animation;
extern int temp_animation_flag;
extern int animation_interrupt;
extern int animation_transition;

// OTA CAN message
extern int ota_trigger_from_esp;

// rgb values
extern int r_value;
extern int g_value;
extern int b_value;

// Network Strength
extern int network_strength_value;

// release notes
extern char dash_release_notes[200];

// Kill Switch Page
extern int kill_transparency_level;
extern int kill_switch_just_pressed;

// CAN ACK Flags
extern int starting_splashscreen_CAN_ACK_SEND;
extern int ending_splashscreen_CAN_ACK_SEND;
extern int pairing_successful_CAN_ACK_SEND;
extern int pairing_failed_CAN_ACK_SEND;
extern int pairing_passkey_CAN_ACK_SEND;
extern int ota_successful_CAN_ACK_SEND;
extern int ota_failure_CAN_ACK_SEND;
extern int ota_available_CAN_ACK_SEND;
extern int birthday_CAN_ACK_SEND;
extern int new_year_CAN_ACK_SEND;

extern int graphics_test_flag;


extern int yellow[3];


extern int starting_splashscreen_transparency_level;
extern int ending_splashscreen_transparency_level;
extern int initiate_ending_splashscreen_fade;

extern float starting_splashscreen_scaling;
extern float ending_splashscreen_scaling;
extern int continue_scaling;
extern int upscale;

extern int initiate_downscale;

extern char lock_screen_time[10];
extern char today[10];

extern char lock_screen_time_hrs[4];
extern char lock_screen_time_min[4];

extern char lock_screen_month[15];
//extern uint8_t month;
extern char lock_screen_date[25];

extern char* DAYS[7];
extern char* MONTHS[12];

// call statuses
extern int call_status;
extern int y_position_call_popup;
extern unsigned int incoming_call_blinker;
extern int show_blinker;
extern int incoming_call_transparency;
extern int call_notification_timing[3];


//extern uint8_t beginning_starting_splashscreen[8];
//extern uint8_t beginning_ending_splashscreen[8];
//extern uint8_t beginning_pairing_successful[8];
//extern uint8_t beginning_pairing_failed[8];
//extern uint8_t beginning_show_pairing_key[8];
//extern uint8_t beginning_firmware_installation_successful[8];
//extern uint8_t beginning_firmware_installation_failed[8];
//extern uint8_t beginning_ota_available[8];
//extern uint8_t beginning_birthday_wish[8];
//extern uint8_t beginning_new_year_wish[8];
//
//extern uint8_t ending_starting_splashscreen[8];
//extern uint8_t ending_ending_splashscreen[8];
//extern uint8_t ending_pairing_successful[8];
//extern uint8_t ending_pairing_failed[8];
//extern uint8_t ending_show_pairing_key[8];
//extern uint8_t ending_firmware_installation_successful[8];
//extern uint8_t ending_firmware_installation_failed[8];
//extern uint8_t ending_ota_available[8];
//extern uint8_t ending_birthday_wish[8];
//extern uint8_t ending_new_year_wish[8];

#endif /* INC_DEFINE_H_ */
