/*
 * pn_sync_layer_main.c
 *
 *  Created on: Nov 29, 2023
 *      Author: peter
 */

#include "pn_can_sync_layer.h"
#include "Can_Communication.h"
#include "data_control.h"

// Link with PN can protocol
//SyncLayerCanLink display_vcu_link = { 0x0813FCFA, 0x0814FCFA, 0x0815FCFA, 0x0816FCFA, 0x0817FCFA, 0x0818FCFA, 0x0819FCFA};
SyncLayerCANLink display_vcu_link = {0x0853FCFA, 0x0854FCFA, 0x0855FCFA, 0x0856FCFA,canSend};

typedef enum{
	SYNC_OVERALL_DATA,
	SYNC_BABAL_DATA,
	SYNC_THIKKA_DATA,
	SYNC_SUSTE_DATA,
//	SYNC_USER_DATA,
//	SYNC_TIME_TEMP_DATA,
//	SYNC_SOC_CHARGE_DATA,
//	SYNC_AUXILIARY_DATA,
//	SYNC_ICONS_INDICATOR,
//	SYNC_DRIVETRAIN_DATA,
//	SYNC_ODOMETRY_DATA,
//	SYNC_BLE_PASSKEY_DATA,
//	SYNC_NEW_YEAR_DATE,
	SYNC_UI_RELEASE_NOTES,

	SYNC_SIZE
}SyncDataEnum;

SyncLayerCANData syncData[SYNC_SIZE]={
		{.id= DAILY_ODO_OVERALL,.bytes=(uint8_t*)(&overall_data),.size = sizeof(Dash_OverallDailyOdo_Handel),.track=SYNC_LAYER_CAN_START_REQ},
		{.id= DAILY_ODO_BABBAL,.bytes=(uint8_t*)(&babbal_data),.size = sizeof(Dash_BabalDailyOdo_Handel),.track=SYNC_LAYER_CAN_START_REQ},
		{.id= DAILY_ODO_THIKKA,.bytes=(uint8_t*)(&thikka_data),.size = sizeof(Dash_ThikkaDailyOdo_Handel),.track=SYNC_LAYER_CAN_START_REQ},
		{.id= DAILY_ODO_SUSTE,.bytes=(uint8_t*)(&suste_data),.size = sizeof(Dash_SusteDailyOdo_Handel),.track=SYNC_LAYER_CAN_START_REQ},
//		{.id= USER_INFO,.bytes=(uint8_t*)(&ride_and_rider_names),.size = sizeof(Dash_UserInformation_Handler),.track=SYNC_LAYER_CAN_START_REQ},
//		{.id= DATE_TIME,.bytes=(uint8_t*)(&time_and_temperature),.size = sizeof(Dash_DateTime_Handel),.track=SYNC_LAYER_CAN_START_REQ},
//		{.id= SOC_ETA,.bytes=(uint8_t*)(&SoC_and_chargingInfo),.size = sizeof(Dash_Soc_Handel),.track=SYNC_LAYER_CAN_START_REQ},
//		{.id= AUXILIARY_DATA,.bytes=(uint8_t*)(&auxiliary_data),.size = sizeof(Dash_Auxiliary_Handel),.track=SYNC_LAYER_CAN_START_REQ},
//		{.id= DASH_INDICATOR,.bytes=(uint8_t*)(&icons_indicator),.size = sizeof(Dash_Indicator_Handel),.track=SYNC_LAYER_CAN_START_REQ},
//		{.id= SPEED,.bytes=(uint8_t*)(&drivetrain_data),.size = sizeof(Dash_SpeedWhpkm_Handel),.track=SYNC_LAYER_CAN_START_REQ},
//		{.id= ODO_TRIP,.bytes=(uint8_t*)(&odometry),.size = sizeof(Dash_OdoTrip_Handler),.track=SYNC_LAYER_CAN_START_REQ},
		//{.id= PASSKEY,.bytes=(uint8_t*)(&BLE_passkey),.size = sizeof(Dash_PassKey_Handler),.track=SYNC_LAYER_CAN_START_REQ},
//		{.id= NEW_YEAR,.bytes=(uint8_t*)(&new_year_date),.size = sizeof(Dash_NewYear_Handler),.track=SYNC_LAYER_CAN_START_REQ},
		{.id= RELEASE_NOTES,.bytes=(uint8_t*)(&ui_release_notes),.size = sizeof(Dash_release_notes_Handler),.track=SYNC_LAYER_CAN_START_REQ}
};

static void rxCallback(uint32_t id, uint8_t *bytes, uint16_t size, uint8_t status) {
	if (!status)
		return;
	Acquire_Data_From_CAN(id);
}

extern int rxSendThread(SyncLayerCANLink *link, SyncLayerCANData *data);
void pn_can_sync_layer_thread() {
	NVIC_DisableIRQ(USB_LP_CAN1_RX0_IRQn);
	for (int i = 0; i < SYNC_SIZE; i++) {
		rxSendThread(&display_vcu_link, &syncData[i]);
		if (syncData[i].track == SYNC_LAYER_CAN_RECEIVE_SUCCESS) {
			rxCallback(syncData[i].id, syncData[i].bytes, syncData[i].size, 1);
			syncData[i].track = SYNC_LAYER_CAN_START_REQ;
		} else if (syncData[i].track == SYNC_LAYER_CAN_RECEIVE_FAILED) {
			rxCallback(syncData[i].id, syncData[i].bytes, syncData[i].size, 0);
			syncData[i].track = SYNC_LAYER_CAN_START_REQ;
		}
	}
	NVIC_EnableIRQ(USB_LP_CAN1_RX0_IRQn);
}

extern int rxReceiveThread(SyncLayerCANLink *link, SyncLayerCANData *data,uint32_t id, uint8_t *bytes, uint16_t len);
void pn_can_sync_layer_recCAN(uint32_t id, uint8_t*bytes ,uint8_t len) {
	uint32_t data_id = *(uint32_t*) bytes;
	for (int i = 0; i < SYNC_SIZE; i++) {
		if ((data_id == syncData[i].id) || (syncData[i].id == id)){
			rxReceiveThread(&display_vcu_link, &syncData[i], id, bytes, len);
		}
	}
}

