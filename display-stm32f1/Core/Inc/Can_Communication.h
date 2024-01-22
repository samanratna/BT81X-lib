/*
 * Can_Communication.h
 *
 *  Created on: Nov 27, 2022
 *      Author: Thakur Paudel
 */

#ifndef INC_CAN_COMMUNICATION_H_
#define INC_CAN_COMMUNICATION_H_

#include "main.h"

//#define display_response_can_id		0x18FF50E1
//#define display_ack_can_id			0x18FF50E2
//#define display_stop_can_id			0x18FF50E3

extern CAN_HandleTypeDef hcan;

typedef enum {
	TRANSMIT_ERROR, NO_FREE_MAILBOX, CAN_PENDING, TRANSMIT_OK
} CAN_StatusType_Def;

extern uint8_t RxDataCan1[8];
extern uint32_t TxMailboxes;
extern uint32_t RxFifo;
extern CAN_RxHeaderTypeDef RxHeader;
extern CAN_TxHeaderTypeDef TxHeader;
uint32_t check_can_pending(CAN_HandleTypeDef *can);
uint32_t check_can_free_mailbox(CAN_HandleTypeDef *can);
uint8_t abort_can_message_transmit(CAN_HandleTypeDef *can, uint32_t tx_mailbox);
CAN_StatusType_Def transmit_can_message(CAN_HandleTypeDef *can, uint32_t can_id, uint8_t data[], uint8_t data_len);
int canSend(uint32_t id, uint8_t *bytes, uint8_t len);

#endif /* INC_CAN_COMMUNICATION_H_ */

