/*
 * fonts.c
 *
 *  Created on: Dec 20, 2022
 *      Author: samanratnabuddhacharya
 */

// Load local libraries
#include "graphical_operations.h"
#include "fonts.h"

/* Font Addresses */
void Barlow_bold_12(void) {
	Gpu_CoCmd_FlashRead(phost, RAM_G, 4096, 192);
	Gpu_Hal_WaitCmdfifo_empty(phost);
	Gpu_CoCmd_SetFont2(phost, 1, fontAddr, 0);
}

void Barlow_bold_18(void) {
	Gpu_CoCmd_FlashRead(phost, RAM_G, 20672, 192);
	Gpu_Hal_WaitCmdfifo_empty(phost);
	Gpu_CoCmd_SetFont2(phost, 1, fontAddr, 0);
}

void Barlow_bold_20(void) {
	Gpu_CoCmd_FlashRead(phost, RAM_G, 53632, 192);
	Gpu_Hal_WaitCmdfifo_empty(phost);
	Gpu_CoCmd_SetFont2(phost, 1, fontAddr, 0);
}

void Barlow_bold_32(void) {
	Gpu_CoCmd_FlashRead(phost, RAM_G, 103168, 192);
	Gpu_Hal_WaitCmdfifo_empty(phost);
	Gpu_CoCmd_SetFont2(phost, 1, fontAddr, 0);
}

void Barlow_bold_24(void) {
	Gpu_CoCmd_FlashRead(phost, RAM_G, 78400, 192);
	Gpu_Hal_WaitCmdfifo_empty(phost);
	Gpu_CoCmd_SetFont2(phost, 1, fontAddr, 0);
}

void Barlow_extrabold_20(void) {
	Gpu_CoCmd_FlashRead(phost, RAM_G, 136128, 192);
	Gpu_Hal_WaitCmdfifo_empty(phost);
	Gpu_CoCmd_SetFont2(phost, 1, fontAddr, 0);
}

void Barlow_extrabold_24(void) {
	Gpu_CoCmd_FlashRead(phost, RAM_G, 160896, 192);
	Gpu_Hal_WaitCmdfifo_empty(phost);
	Gpu_CoCmd_SetFont2(phost, 1, fontAddr, 0);
}

void Barlow_extrabold_28(void) {
	Gpu_CoCmd_FlashRead(phost, RAM_G, 185664, 192);
	Gpu_Hal_WaitCmdfifo_empty(phost);
	Gpu_CoCmd_SetFont2(phost, 1, fontAddr, 0);
}

void Barlow_extrabold_40(void) {
	Gpu_CoCmd_FlashRead(phost, RAM_G, 1088832, 192);
	Gpu_Hal_WaitCmdfifo_empty(phost);
	Gpu_CoCmd_SetFont2(phost, 1, fontAddr, 0);
}

void Barlow_medium_10(void) {
	Gpu_CoCmd_FlashRead(phost, RAM_G, 218624, 192);
	Gpu_Hal_WaitCmdfifo_empty(phost);
	Gpu_CoCmd_SetFont2(phost, 1, fontAddr, 0);
}

void Barlow_medium_12(void) {
	Gpu_CoCmd_FlashRead(phost, RAM_G, 227008, 192);
	Gpu_Hal_WaitCmdfifo_empty(phost);
	Gpu_CoCmd_SetFont2(phost, 1, fontAddr, 0);
}

void Barlow_semibold_14(void) {
	Gpu_CoCmd_FlashRead(phost, RAM_G, 243584, 192);
	Gpu_Hal_WaitCmdfifo_empty(phost);
	Gpu_CoCmd_SetFont2(phost, 1, fontAddr, 0);
}

void Barlow_semibold_20(void) {
	Gpu_CoCmd_FlashRead(phost, RAM_G, 260160, 192);
	Gpu_Hal_WaitCmdfifo_empty(phost);
	Gpu_CoCmd_SetFont2(phost, 1, fontAddr, 0);
}

void Barlow_semibold_32(void) {
	Gpu_CoCmd_FlashRead(phost, RAM_G, 284928, 192);
	Gpu_Hal_WaitCmdfifo_empty(phost);
	Gpu_CoCmd_SetFont2(phost, 1, fontAddr, 0);
}

void Barlow_semibold_48(void) {
	Gpu_CoCmd_FlashRead(phost, RAM_G, 317888, 192);
	Gpu_Hal_WaitCmdfifo_empty(phost);
	Gpu_CoCmd_SetFont2(phost, 1, fontAddr, 0);
}

void Barlow_semibold_112(void) {
	Gpu_CoCmd_FlashRead(phost, RAM_G, 391808, 192);
	Gpu_Hal_WaitCmdfifo_empty(phost);
	Gpu_CoCmd_SetFont2(phost, 1, fontAddr, 0);
}
