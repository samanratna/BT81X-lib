/*
 * design_elements.h
 *
 *  Created on: Dec 20, 2022
 *      Author: samanratnabuddhacharya
 */

#ifndef INC_DESIGN_ELEMENTS_H_
#define INC_DESIGN_ELEMENTS_H_

// Load Standard libraries
#include <stdio.h>
#include <stdbool.h>

#include "graphical_operations.h"
#include "design_calculations.h"
#include "data_control.h"

#include "define.h"

// Drive Modes
void mode_reverse(void);
void mode_standby(void);
void mode_suste(void);
void mode_thikka(void);
void mode_babbal(void);

// Sidelight Status
void load_sidelight_right(void);
void load_sidelight_left(void);
void load_sidelight_off(void);
void show_sidelight(void);

// Passlight Status
void show_passlight(void);
void load_passlight_on(void);
void load_passlight_off(void);

// Icons and images
void show_icons_stats(void);
void show_kill_switch_icon(void);
void show_stand_icon(void);
void show_battery_logo(void);
void show_ble_status(void);
void show_Whpkm_indicator_line(void);
void show_icons_home(void);
void show_icons_chargingUI(void);
void show_SoC_circular_bar(void);
void show_series1_icon(void);
void dont_show_series1_icon(void);
void show_bike_render(void);
void show_battery_icon(void);
void show_bluetooth_icon(void);
void show_location_icon(void);
void show_headlight_status_icon(void);
void show_background_extrude(void);
void show_circle(void);
void show_odo_graph(void);
void show_small_yatri_logo(void);
void show_temperature_icon(void);

// Data to be shown on UI
void show_days_in_graph(int present_day);
void show_drive_mode(void);
void show_Whpkm_value(void);
void show_odometer(void);
void show_trip_distance(void);
void show_bikespeed(void);
void show_stats_odo(void);
void show_SoC_level(int charging_SoC);
void show_soc_percent_value(void);
void show_bikename(void);
void show_travelBoldly(void);
void show_charging_SoC(void);
void show_eta(void);
void show_realtime(void);
void show_ride_profile_stats(void);
void show_temperature_value(void);

void Kill_Switch_Position_Change(void);
void Kill_Switch_Static(void);

void Stand_Switch_Position_Change(void);
void Stand_Switch_Static(void);

void add_transparent_film(void);
void popup_test(void);
void ota_info_here(void);
void add_background_wallpaper(void);
void set_transparency_level(void);

void show_network_strength(void);
void show_incoming_call_notification(void);


#endif /* INC_DESIGN_ELEMENTS_H_ */
