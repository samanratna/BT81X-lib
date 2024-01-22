/*
 * pn_can_sync_layer.h
 *
 *  Created on: Nov 3, 2023
 *      Author: NIRUJA
 */

#ifndef PN_CAN_SYNC_LAYER_H_
#define PN_CAN_SYNC_LAYER_H_
#include "main.h"

#define TRANSMIT_TIMEOUT 	5000
#define RECEIVE_TIMEOUT  	5000

typedef enum {
	SYNC_LAYER_CAN_START_REQ,
	SYNC_LAYER_CAN_START_ACK,
	SYNC_LAYER_CAN_DATA,
	SYNC_LAYER_CAN_MISSING_DATA,
	SYNC_LAYER_CAN_END_REQ,
	SYNC_LAYER_CAN_END_ACK,
	/////////////////////////
	SYNC_LAYER_CAN_TRANSMIT_SUCCESS,
	SYNC_LAYER_CAN_TRANSMIT_FAILED,
	SYNC_LAYER_CAN_RECEIVE_SUCCESS,
	SYNC_LAYER_CAN_RECEIVE_FAILED
} SyncLayerCANTrack;

typedef struct {
	uint32_t id;
	uint8_t *bytes;
	uint16_t size;
	uint8_t numTry;
	////////////For receiver//////////
	uint8_t frameRecords[19];
	////////////For both///////////
	uint32_t crc;
	SyncLayerCANTrack track;
	uint8_t doesCRCMatch;
	uint32_t waitTill;
	uint8_t isTimeOut;
} SyncLayerCANData;

typedef struct {
	uint32_t startReqID;
	uint32_t startAckID;
	uint32_t endReqID;
	uint32_t endAckID;
/////////////////////////
	int (*canSend)(uint32_t id, uint8_t *bytes, uint8_t len);
} SyncLayerCANLink;

void pn_can_sync_layer_thread(void);


#endif /* PN_CAN_SYNC_LAYER_H_ */
