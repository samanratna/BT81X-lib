/*
 * Can_Start.c
 *
 *  Created on: Nov 27, 2022
 *      Author: Thakur Paudel
 */

#include "Can_Start.h"
#include <stdio.h>


#define filter_id1 		0x18FF28F4
#define filter_mask1 	0x1FFFFFFF

#define filter_id2 		0x18FE28F4
#define filter_mask2 	0x1FFFFFFF

#define filter_id3 		0x1806E5F4
#define filter_mask3 	0x1FFFFFFF

#define filter_id4 		0x18FF50E5
#define filter_mask4 	0x1FFFFFFF

#define filter_id5 		0x18FF0428
#define filter_mask5 	0x1FFFFFFF

#define filter_id6 		0x18FF0028
#define filter_mask6 	0x1FFFFFFF

void init_can(void) {

	hcan.Instance 						= CAN1;
	hcan.Init.Prescaler 				= 8;
	hcan.Init.Mode 						= CAN_MODE_NORMAL;
	hcan.Init.SyncJumpWidth 			= CAN_SJW_1TQ;
	hcan.Init.TimeSeg1 					= CAN_BS1_13TQ;
	hcan.Init.TimeSeg2 					= CAN_BS2_2TQ;
	hcan.Init.TimeTriggeredMode 		= DISABLE;
	hcan.Init.AutoBusOff 				= ENABLE;
	hcan.Init.AutoWakeUp 				= DISABLE;
	hcan.Init.AutoRetransmission 		= ENABLE;
	hcan.Init.ReceiveFifoLocked 		= DISABLE;
	hcan.Init.TransmitFifoPriority 		= DISABLE;

	if (HAL_CAN_Init(&hcan) != HAL_OK) {
		Error_Handler();
	}
}

void filter_can(void) {

	CAN_FilterTypeDef sFilterConfig 		= { 0 };
	sFilterConfig.FilterBank				= 0;
	sFilterConfig.FilterMode 				= CAN_FILTERMODE_IDMASK;
	sFilterConfig.FilterScale 				= CAN_FILTERSCALE_32BIT;
	sFilterConfig.FilterIdHigh 			= (0x00 >> 13) & 0xFFFF;  // STDID[10:0] and EXID[17:13]
	sFilterConfig.FilterIdLow 				= (0x00 << 3) & 0xFFF8;  // EXID[12:5] and 3 reserved
	sFilterConfig.FilterMaskIdHigh 		= (0x00 >> 13) & 0xFFFF;
	sFilterConfig.FilterMaskIdLow 			= (0x00 << 3) & 0xFFF8;  //0xFFF8;
	sFilterConfig.FilterFIFOAssignment 	= CAN_RX_FIFO0;
	sFilterConfig.FilterActivation 		= ENABLE;
	sFilterConfig.SlaveStartFilterBank 	= 14;
	HAL_CAN_ConfigFilter(&hcan, &sFilterConfig);

}



void start_can(void) {
	HAL_CAN_Start(&hcan);

}


void Start_Can_Communication(void) {

	init_can();
	filter_can();
	start_can();
}
