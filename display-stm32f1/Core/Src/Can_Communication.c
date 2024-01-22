/*
 * Can_Communication.c
 *
 *  Created on: Nov 27, 2022
 *      Author: Thakur Paudel
 */

#include <stdio.h>

#include "Can_Communication.h"
#include "define.h"
#include "graphical_operations.h"
#include "data_control.h"
#include "print.h"


uint32_t TxMailboxes;
uint32_t RxFifo;
CAN_RxHeaderTypeDef RxHeader;
CAN_TxHeaderTypeDef TxHeader;
uint8_t RxDataCan1[8];
uint32_t previous_id = 0;

#define true 	1
#define false 	0


extern void pn_can_sync_layer_recCAN(uint32_t id, uint8_t *bytes, uint8_t len);


uint32_t check_can_pending(CAN_HandleTypeDef *can) {

	return HAL_CAN_IsTxMessagePending(can, TxMailboxes);
}


uint8_t abort_can_message_transmit(CAN_HandleTypeDef *can, uint32_t tx_mailbox) {

	HAL_StatusTypeDef state;
	state = HAL_CAN_AbortTxRequest(can, tx_mailbox);

	if (state == HAL_OK) {

		return 1;

	} else if (state == HAL_ERROR) {

		return 0;
	}

	return 0;
}


uint32_t check_can_free_mailbox(CAN_HandleTypeDef *can) {

	uint32_t free_mailbox = 0;
	uint32_t temp_mailbox = HAL_CAN_GetTxMailboxesFreeLevel(can);

	switch (temp_mailbox) {

		case 1:
			free_mailbox = 1;
			break;
		case 2:
			free_mailbox = 2;
			break;
		case 3:
			free_mailbox = 3;
			break;
		default:
			free_mailbox = 0;
			break;
	}

	return free_mailbox;
}


int canSend(uint32_t id, uint8_t *bytes, uint8_t len) {

	return (transmit_can_message(&hcan, id, bytes, len));

}


// transmit the can message
CAN_StatusType_Def transmit_can_message(CAN_HandleTypeDef *can, uint32_t can_id, uint8_t data[], uint8_t data_len) {

	CAN_StatusType_Def can_tx_status = TRANSMIT_ERROR;

	if (check_can_free_mailbox(can) == 0) {

		if (check_can_pending(can) == -1) {

			can_tx_status = NO_FREE_MAILBOX;

			if (abort_can_message_transmit(can, TxMailboxes) != 1) {

				can_tx_status = CAN_PENDING;
			}
		}
	}

	TxHeader.ExtId = can_id;
	TxHeader.RTR = CAN_RTR_DATA;
	TxHeader.IDE = CAN_ID_EXT;
	TxHeader.DLC = data_len;
	TxHeader.TransmitGlobalTime = DISABLE;

	if (HAL_CAN_AddTxMessage(can, &TxHeader, data, &TxMailboxes) != HAL_OK) {

		can_tx_status = TRANSMIT_ERROR;

	} else {

		can_tx_status = TRANSMIT_OK;
	}

	return can_tx_status;
}


// CAN Receive Section
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *can) {

	if (HAL_CAN_GetRxMessage(&hcan, CAN_RX_FIFO0, &RxHeader, RxDataCan1) != HAL_OK) {

		return;
	}

	uint32_t Receive_id = RxHeader.ExtId;
	uint32_t data_len = RxHeader.DLC;

	if ((Receive_id & 0xf4) == 0xf4){
		return;
	}

	switch (Receive_id) {

		case NEW_YEAR:

			Load_New_Year_Date_To_Display(RxDataCan1);
			break;

		case PASSKEY:

			Load_Passkey_To_Display(RxDataCan1, Receive_id, data_len);
			break;

		case ODO_TRIP:

			Load_OdoTrip_Data_To_Display(RxDataCan1);
			break;

		case USER_NAME:

			Load_Username_Data(RxDataCan1, Receive_id, data_len);
			break;

		case BIKE_NAME:

			Load_Bikename_Data(RxDataCan1, Receive_id, data_len);
			break;

		case DATE_TIME:

			Load_Time_To_Display(RxDataCan1, Receive_id, data_len);
			break;

		case AUXILIARY_DATA:

			Load_Auxiliary_Info_To_Display(RxDataCan1, Receive_id, data_len);
			break;

		case SOC_ETA:

			Load_SoC_ETA_To_Display(RxDataCan1);
			break;

		case DASH_INDICATOR:

			Load_Indicator_Icons_To_Display(RxDataCan1);
			break;

		case VEHICLE_SPEED:

			Load_Powertrain_Data(RxDataCan1);
			break;

		case OTA_DATA:

			Load_OTA_Data(RxDataCan1);
			break;

		case OTA_INSTALLATION_STATE:

			tier1_cmd_can = OTA_UI;
			tier2_cmd_can = RxDataCan1[0];
			ota_trigger_from_esp = 1;

			if ((tier1_cmd_can == OTA_UI) && (tier2_cmd_can == FIRMWARE_INSTALLATION_SUCCESSFUL)) {

				ota_successful_flag = 1;
				ota_successful_CAN_ACK_SEND = 0;

			} else if ((tier1_cmd_can == OTA_UI) && (tier2_cmd_can == FIRMWARE_INSTALLATION_FAILED)) {

				ota_failed_flag = 1;
				ota_failure_CAN_ACK_SEND = 0;
			}

			load_cmd_can_ack_data(tier1_cmd_can, tier2_cmd_can);
			break;

		case NETWORK_STRENGTH_CAN:

			Load_Network_Strength_Value(RxDataCan1);
			break;

		case BIKE_SERIES:

			series = RxDataCan1[0];
			break;

		case OTA_JUMP_REQUEST:

			Jump_To_Bootloader();
			break;

		case CMD_CAN:

//			print("CMD CAN: -- %s --\n",
//					(RxDataCan1[0] == 1)? "STARTING_SPLASHSCREEN":
//					(RxDataCan1[0] == 2)? "STARTUP_MESSAGE_SCREEN":
//					(RxDataCan1[0] == 3)? "ENDING_SPLASHSCREEN":
//					(RxDataCan1[0] == 4)? "STATS":
//					(RxDataCan1[0] == 5)? "DRIVE_MODE":
//					(RxDataCan1[0] == 6)? "AC_CHARGING":
//					(RxDataCan1[0] == 7)? "DC_CHARGING":
//					(RxDataCan1[0] == 8)? "OTA_UI":
//					(RxDataCan1[0] == 9)? "OBD_UI":
//					(RxDataCan1[0] == 10)? "BLE_UI":
//					(RxDataCan1[0] == 11)? "POWER_DOWN":
//					(RxDataCan1[0] == 12)? "SYSTEM_RESET":
//					(RxDataCan1[0] == 13)? "NETWORK_STRENGTH":
//					(RxDataCan1[0] == 14)? "UI_INTRUSION":
//					"WRONG COMMAND CAN"
//			);

			tier1_cmd_can = RxDataCan1[0];
			tier2_cmd_can = RxDataCan1[1];

			if (tier1_cmd_can == AC_CHARGING) {

				ending_splashscreen_flag = 0;
				ending_splashscreen_timer = 0;

				App_Flush_Co_Buffer(phost);			// Clear buffer
				Charging_just_started = 1;

				if (allow_animation == 0) {
					allow_animation = 1;
				} else if (allow_animation == 1) {
					allow_animation = 0;
				}
			}

			if (tier1_cmd_can == DC_CHARGING) {

				ending_splashscreen_flag = 0;
				ending_splashscreen_timer = 0;

				if (tier2_cmd_can == CHARGING_INITIATED) {

					Charging_just_started = 1;

					if (allow_animation == 0) {
						allow_animation = 1;
					} else if (allow_animation == 1) {
						allow_animation = 0;
					}
				}
			}

			if (tier1_cmd_can == STARTUP_SPLASHSCREEN) {

				// Turn ON startupSplashscreen
				starting_splashscreen_flag = 1;
				ending_splashscreen_flag = 0;

				// Reset endingSplashscreen timer
				ending_splashscreen_timer = 0;

				starting_splashscreen_transparency_level = 0;

				// Reset
				dot_count = 0;
				display_power_up();

			} else if (tier1_cmd_can == ENDING_SPLASHSCREEN) {

				// Turn OFF endingSplashscreen
				ending_splashscreen_flag = 1;
				starting_splashscreen_flag = 0;
				birthday_message_flag = 0;
				new_year_message_flag = 0;

				// Reset startingSplashscreen timer
				starting_splashscreen_timer = 0;
				birthday_message_timer = 0;
				new_year_message_timer = 0;

				kill_transparency_level = 180;
				continue_scaling = 1;


			} else if ((tier1_cmd_can == BLE_UI) && (tier2_cmd_can == PAIRING_SUCCESSFUL)) {

	//			print("CMD CAN: -- PAIRING_SUCCESSFUL --\n");

				if (key_status == key_sw_ON) {

					pairing_successful_flag = 1;
				}

			} else if ((tier1_cmd_can == BLE_UI) && (tier2_cmd_can == PAIRING_FAILED)) {

	//			print("CMD CAN: -- PAIRING_FAILED --\n");

				if (key_status == key_sw_ON) {

					pairing_failed_flag = 1;
				}

			} else if ((tier1_cmd_can == BLE_UI) && (tier2_cmd_can == SHOW_PAIRING_KEY)) {

	//			print("CMD CAN: -- PAIRING_KEY --\n");

				if (key_status == key_sw_ON) {

					pairing_passkey_flag = 1;
				}

			} else if ((tier1_cmd_can == STARTUP_MESSAGE_SCREEN) && (tier2_cmd_can == NEW_YEAR_WISH)) {

	//			print("CMD CAN: -- NEW YEAR --\n");
				new_year_message_flag = 1;

			} else if ((tier1_cmd_can == STARTUP_MESSAGE_SCREEN) && (tier2_cmd_can == BIRTHDAY_WISH)) {

				birthday_message_flag = 1;

			} else if ((tier1_cmd_can == OTA_UI) && (tier2_cmd_can == OTA_AVAILABLE)) {

				tier1_cmd_can = STATS;
	//			print("CMD CAN: -- OTA AVAILABLE --\n");
				ota_available_flag = 1;

			} else if (tier1_cmd_can == UI_INTRUSION_INPUT) {

				// INTRUDE OTA AVAILABLE UI
				ota_available_flag = 0;
				ota_available_timer = 0;

				// INITIATE STATS PAGE
				tier1_cmd_can = STATS;
			}

			load_cmd_can_ack_data(RxDataCan1[0], RxDataCan1[1]);
			break;

		default:
			break;
	}

	pn_can_sync_layer_recCAN(Receive_id, RxDataCan1, data_len);

}

