/*
 * data_control.h
 *
 *  Created on: Dec 28, 2022
 *      Author: samanratnabuddhacharya
 */


#include "define.h"

#define AM		0
#define PM		1

typedef struct {
	uint8_t overall_odo_day1;
	uint8_t overall_odo_day2;
	uint8_t overall_odo_day3;
	uint8_t overall_odo_day4;
	uint8_t overall_odo_day5;
	uint8_t overall_odo_day6;
	uint8_t overall_odo_day7;
	uint8_t overall_avg_speed;
	uint8_t overall_max_speed;
	uint8_t overall_avg_whpkm;
	uint8_t day;
	float overall_odo;
} Dash_OverallDailyOdo_Handel;

typedef struct {
	uint8_t thikka_odo_day1;
	uint8_t thikka_odo_day2;
	uint8_t thikka_odo_day3;
	uint8_t thikka_odo_day4;
	uint8_t thikka_odo_day5;
	uint8_t thikka_odo_day6;
	uint8_t thikka_odo_day7;
	uint8_t thikka_avg_speed;
	uint8_t thikka_max_speed;
	uint8_t thikka_avg_whpkm;
	uint8_t day;
	float thikka_odo;
} Dash_ThikkaDailyOdo_Handel;

typedef struct {
	uint8_t babal_odo_day1;
	uint8_t babal_odo_day2;
	uint8_t babal_odo_day3;
	uint8_t babal_odo_day4;
	uint8_t babal_odo_day5;
	uint8_t babal_odo_day6;
	uint8_t babal_odo_day7;
	uint8_t babal_avg_speed;
	uint8_t babal_max_speed;
	uint8_t babal_avg_whpkm;
	uint8_t day;
	float babal_odo;
} Dash_BabalDailyOdo_Handel;

typedef struct {
	uint8_t suste_odo_day1;
	uint8_t suste_odo_day2;
	uint8_t suste_odo_day3;
	uint8_t suste_odo_day4;
	uint8_t suste_odo_day5;
	uint8_t suste_odo_day6;
	uint8_t suste_odo_day7;
	uint8_t suste_avg_speed;
	uint8_t suste_max_speed;
	uint8_t suste_avg_whpkm;
	uint8_t day;
	float suste_odo;
} Dash_SusteDailyOdo_Handel;

typedef struct {
	char user_name[10];
	char bike_name[10];
} Dash_UserInformation_Handler;

/*
 * hour					: Hours
 * minute				: Minutes
 * format				: 12hr / 24hr 	-> 12 / 24
 * daynight_indicator	: AM / PM 		-> 0 / 1
 * temperature			: Temperature Value
 */
//typedef struct {
//	uint8_t hour;
//	uint8_t minute;
//	uint8_t format;
//	uint8_t daynight_indicator;
//	uint8_t temperature;
//} Dash_DateTime_Handel;

typedef struct {
	uint8_t hour;
	uint8_t minute;
	uint8_t format;
	uint8_t daynight_indicator;
	uint8_t temperature;
	uint8_t weekday;
	uint8_t date;
	uint8_t month;
} Dash_DateTime_Handel;

typedef struct {
	uint8_t charger_status;
	uint8_t soc;
	uint8_t time2fullCharge;
	uint8_t charging_current;
} Dash_Soc_Handel;

typedef struct {
	uint8_t key;
	uint8_t drive_mode;
	uint8_t left_side_light;
	uint8_t right_side_light;
	uint8_t High_beam;
	uint8_t low_beam;
	uint8_t display_mode;
	uint8_t display_brightness_level;
} Dash_Auxiliary_Handel;

typedef struct {
	uint8_t stand_indicator;
	uint8_t gps_indicator;
	uint8_t temperature_indicator;
	uint8_t ble_indicator;
	uint8_t kill_switch;
	uint8_t mode_button_when_kill_and_stand_Switch_engaged;
} Dash_Indicator_Handel;

typedef struct {
	uint8_t vehicle_speed;
	uint8_t whpkm;
	uint8_t regen_status;
} Dash_SpeedWhpkm_Handel;

typedef struct {
	float odo;
	float trip;
} Dash_OdoTrip_Handler;

typedef struct {
	uint32_t passkey;
} Dash_PassKey_Handler;

typedef struct {
	uint8_t Command[8];
} Dash_Command_Handel;

typedef struct {
	uint32_t year;
	uint8_t day;
	uint8_t month;
} Dash_NewYear_Handler;

typedef struct {
	char release_notes[200];
} Dash_release_notes_Handler;



extern Dash_OverallDailyOdo_Handel 		overall_data;
extern Dash_SusteDailyOdo_Handel 		suste_data;
extern Dash_ThikkaDailyOdo_Handel 		thikka_data;
extern Dash_BabalDailyOdo_Handel 		babbal_data;
extern Dash_UserInformation_Handler 	ride_and_rider_names;
extern Dash_DateTime_Handel 			time_and_temperature;
extern Dash_Soc_Handel					SoC_and_chargingInfo;
extern Dash_Auxiliary_Handel			auxiliary_data;
extern Dash_Indicator_Handel			icons_indicator;
extern Dash_SpeedWhpkm_Handel			drivetrain_data;
extern Dash_OdoTrip_Handler				odometry;
extern Dash_PassKey_Handler				BLE_passkey;
extern Dash_Command_Handel				cmd_can;
extern Dash_NewYear_Handler 			new_year_date;
extern Dash_release_notes_Handler		ui_release_notes;


void Acquire_Data_From_CAN(uint32_t can_ID);
void Load_Overall_Data_To_Display(void);
void Load_Suste_Data_To_Display(void);
void Load_Thikka_Data_To_Display(void);
void Load_Babbal_Data_To_Display(void);
void Load_Ride_and_Rider_Names_To_Display(void);
void Load_Time_To_Display(uint8_t*, uint32_t, uint32_t);
void Load_SoC_ETA_To_Display(uint8_t*);
void Load_OTA_Data(uint8_t*);
void Acquire_Charging_Status(void);
void Load_Auxiliary_Info_To_Display(uint8_t*, uint32_t, uint32_t);
void Load_Indicator_Icons_To_Display(uint8_t*);
void Load_Drivetrain_Data_To_Display(void);
void Load_OdoTrip_Data_To_Display(uint8_t*);
void Load_Passkey_To_Display(uint8_t*, uint32_t, uint32_t);
void Load_New_Year_Date_To_Display(uint8_t*);
void Load_Release_Notes_To_Display(void);
void Load_Powertrain_Data(uint8_t*);
void Load_Username_Data(uint8_t*, uint32_t, uint32_t);
void Load_Bikename_Data(uint8_t*, uint32_t, uint32_t);
void Load_Network_Strength_Value(uint8_t*);
void Jump_To_Bootloader(void);
void Find_Day_of_week(int);
void Find_Month_of_Year(int);

//void load_can_ack_data(uint8_t UI, uint8_t ui_state, int timeValue);
void load_cmd_can_ack_data(uint8_t tier1_cmd, uint8_t tier2_cmd);



