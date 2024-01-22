/*
 * define.c
 *
 *  Created on: Jul 4, 2023
 *      Author: Sanjeeb Malla
 */

#include "define.h"

int series;
int Charging_just_started;
uint8_t bike_speed;
uint8_t Is_Head_Light;
uint8_t dash_Is_passlight_on;
uint8_t Verification_Status;
uint8_t charging_SoC;
uint8_t charging_eta;
uint8_t charging_eta_hours;
uint8_t charging_eta_minutes;
uint8_t discharging_SoC;
uint8_t onBoardCharging_Status;
uint8_t onBoardCharging_eta;


int low_beam_status;
int high_beam_status;
int headlight_status;
uint8_t ui_mode;
uint8_t key_status;
uint8_t drive_mode;
uint8_t right_sidelight_status;
uint8_t left_sidelight_status;


int bikeSpeed;
int bikeSpeed1;

int overall_maxSpeed;
int trip_maxSpeed;
int overall_avgSpeed;
int trip_avgSpeed;

uint32_t start_time;
uint32_t end_time;

int timeout_for_passkey;
int write_reset;

uint16_t overall_travelledDistance;
uint16_t trip_travelledDistance;

uint8_t dot_count;
int mode_button_when_Switches_ON;
int UI_lastState;

long int passkey_value;
int pairing_status;

int start_timeout_passkey;
int BLE_paired;

char dash_time[20];

char dash_speed[30];
char dash_speed1[30];

char dash_odometry[50];
char dash_trip[50];
char dash_chargingSoC[30];
char dash_dischargingSoC[30];
char dash_chargingETA[30];
char dash_passkey[30];
char dash_passkey_timeout[30];
char dash_username[20];
char dash_welcome_username[30];
char dash_babye_username[30];
char dash_year_BS[30];
char dash_bikename[30];
char dash_WhperKM[30];

char dash_mode_specific_avgSpeed[30];
char dash_mode_specific_maxSpeed[30];
char dash_mode_specific_avgWhperKM[30];
char dash_mode_specific_odo[30];

char dash_temperature_value[4];


int BLE_timer_out;

unsigned int soc_increasing;
unsigned int current_soc_value;

int charger_connected_but_not_charging;
int first_pair;

int battery_warning = 0;

uint8_t charging_type;

uint32_t Starting_Splashscreen_timeout_flag;
uint32_t Starting_Splashscreen_timer;
int starting_splashscreen_transparency_level = 160;
int continue_scaling = 1;
int upscale = 1;

int initiate_downscale = 0;


float starting_splashscreen_scaling = 0.01;
float ending_splashscreen_scaling = 0.05;

uint32_t Ending_Splashscreen_timeout_flag;
uint32_t Ending_Splashscreen_timer;
int ending_splashscreen_transparency_level = 250;
int initiate_ending_splashscreen_fade;

int odo_graph_label1;
char odo_graph_label_char1[100];
char odo_graph_label_char2[100];
char odo_graph_label_char3[100];
uint16_t odo_graph_label[3];

int drive_mode_stat;

uint16_t temp_odo_increment;
uint16_t coordinateY[7];
uint16_t present_maximum_odo;
uint16_t last_maximum_odo;

int controller_temperature;
int gps_tracking_status;
int WhperKM_value;
int Is_WhperKM_positive;
int stand_status;
int kill_switch_status;
int error_Code_Display;
int stats_to_home;
int present_day;
uint16_t weekly_data[8];
int mode_specific_avgSpeed;
int mode_specific_maxSpeed;
int mode_specific_avgWhperKM;
int testDataCAN;
int Is_watchdog_reset;
int dash_brightness_level;
uint32_t mode_specific_odo;

uint8_t tier1_cmd_can;
uint8_t tier2_cmd_can;


// OTA parameters
int OTA_Verification_Status;
int OTA_download_completion_pct;
int OTA_est_time;
int OTA_request;
int OTA_received;
int OTA_available;
int OTA_popup_timer_start;
int OTA_popup_timer_active;
uint16_t OTA_popup_timer;

int OTA_failed_timer_start;
uint16_t OTA_failed_timer_value;
int first_bike_ON;

char dash_OTA_download_pct[30];
char dash_OTA_eta_time[30];

uint32_t counter1;
int names_received;

// Starting Splashscreen Timer
int starting_splashscreen_flag;
uint32_t starting_splashscreen_timer;

// Ending Splashscreen Timer
int ending_splashscreen_flag;
uint32_t ending_splashscreen_timer;

// BLE Pairing Successful Timer
int pairing_successful_flag;
uint32_t pairing_successful_timer;

// BLE Pairing Failed Timer
int pairing_failed_flag;
uint32_t pairing_failed_timer;

// BLE Pairing Passkey Timer
int pairing_passkey_flag;
int pairing_passkey_timer;

// OTA Successful Timer
int ota_successful_flag;
uint32_t ota_successful_timer;

// OTA_Failed Timer
int ota_failed_flag;
uint32_t ota_failed_timer;

// OTA_available_popup
int ota_available_flag;
uint32_t ota_available_timer;

// Birthday Message Timer
int birthday_message_flag;
uint32_t birthday_message_timer;

// New Year Message Timer
int new_year_message_flag;
uint32_t new_year_message_timer;

uint32_t test_counter;
uint32_t engine_counter;
uint32_t chipid_counter;
int allow_animation;
int temp_animation_flag;
int animation_interrupt;
int animation_transition;

// OTA CAN message
int ota_trigger_from_esp;

// rgb values
int r_value;
int g_value;
int b_value;

// Network Strength
int network_strength_value;

// release notes
char dash_release_notes[200];

// Kill Switch Page
int kill_transparency_level = 180;
int kill_switch_just_pressed;

// CAN ACK Flags
int starting_splashscreen_CAN_ACK_SEND;
int ending_splashscreen_CAN_ACK_SEND;
int pairing_successful_CAN_ACK_SEND;
int pairing_failed_CAN_ACK_SEND;
int pairing_passkey_CAN_ACK_SEND;
int ota_successful_CAN_ACK_SEND;
int ota_failure_CAN_ACK_SEND;
int ota_available_CAN_ACK_SEND;
int birthday_CAN_ACK_SEND;
int new_year_CAN_ACK_SEND;

int graphics_test_flag;



int yellow[3] = {255, 204, 42};

char lock_screen_time[10];
char today[10];

char lock_screen_time_hrs[4];
char lock_screen_time_min[4];

char lock_screen_month[15];
char lock_screen_date[25];

char* DAYS[7]		= {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
char* MONTHS[12]	= {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// call statuses
int call_status;
int show_blinker;
unsigned int incoming_call_blinker	= 0;
int y_position_call_popup			= 29;
int incoming_call_transparency		= 250;

// Show with no transparency, fading time, time with complete transparency
int call_notification_timing[3] = {500, 500, 200};


//uint8_t month;
//uint8_t beginning_starting_splashscreen[8];
//uint8_t beginning_ending_splashscreen[8];
//uint8_t beginning_pairing_successful[8];
//uint8_t beginning_pairing_failed[8];
//uint8_t beginning_show_pairing_key[8];
//uint8_t beginning_firmware_installation_successful[8];
//uint8_t beginning_firmware_installation_failed[8];
//uint8_t beginning_ota_available[8];
//uint8_t beginning_birthday_wish[8];
//uint8_t beginning_new_year_wish[8];
//
//uint8_t ending_starting_splashscreen[8];
//uint8_t ending_ending_splashscreen[8];
//uint8_t ending_pairing_successful[8];
//uint8_t ending_pairing_failed[8];
//uint8_t ending_show_pairing_key[8];
//uint8_t ending_firmware_installation_successful[8];
//uint8_t ending_firmware_installation_failed[8];
//uint8_t ending_ota_available[8];
//uint8_t ending_birthday_wish[8];
//uint8_t ending_new_year_wish[8];
