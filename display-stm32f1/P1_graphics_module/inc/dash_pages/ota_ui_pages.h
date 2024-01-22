/*
 * ui_pages.h
 *
 *  Created on: Dec 21, 2022
 *      Author: samanratnabuddhacharya
 */

#ifndef INC_GRAPHICS_HEADERS_DASH_PAGES_UI_PAGES_H_
#define INC_GRAPHICS_HEADERS_DASH_PAGES_UI_PAGES_H_

void Precheck_SoC(void);
void Precheck_Network_Strength(void);
void Precheck_Firmware_Version(void);
void Precheck_Balance(void);
void Downloading_Firmware(void);
void Installing_Firmware(void);
void Firmware_Installation_Successful(void);
void Firmware_Installation_Failed(void);
void Network_Connection_Error(void);
void Firmware_Version_Upto_Date(void);
void Insufficient_SoC_For_OTA(void);
void Insufficient_Balance_For_OTA(void);
//void show_OTA_popup(void);

#endif /* INC_GRAPHICS_HEADERS_DASH_PAGES_UI_PAGES_H_ */
