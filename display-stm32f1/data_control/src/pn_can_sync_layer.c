/*
 * pn_can_sync_layer.c
 *
 *  Created on: Nov 3, 2023
 *      Author: NIRUJA
 */

#include "pn_can_sync_layer.h"
#include "main.h"

extern CRC_HandleTypeDef hcrc;
//#define CONSOLE_ENABLE

static uint32_t crc32_calculate(uint8_t *buffer, uint32_t len) {
	__HAL_CRC_DR_RESET(&hcrc);
	uint32_t crc = HAL_CRC_Accumulate(&hcrc, (uint32_t*)buffer, (len/4));
	if((len%4)>0){
		uint8_t data[4] = {0,0,0,0};
		for(int i=0;i<(len%4);i++)
			data[i]=buffer[i+(len/4)*4];
		crc = HAL_CRC_Accumulate(&hcrc, (uint32_t*)data, 1);
	}
	return crc;
}

static uint32_t getMillis() {
	return HAL_GetTick();
}

/**
 * Receive thread for receiving should be called in thread continuously
 * @param link 	: Link where data is to be received
 * @param data	: Data that is to be received
 */
int rxSendThread(SyncLayerCANLink *link, SyncLayerCANData *data) {
	int isSuccess = 0;
	uint32_t id;
	uint8_t bytes[8];
	if (data->track == SYNC_LAYER_CAN_START_ACK) {
		id = link->startAckID;
		*(uint32_t*) bytes = data->id;
		*(uint16_t*) (&bytes[4]) = data->size;
		bytes[6] = data->numTry;
		if (link->canSend(id, bytes, 8)) {
			isSuccess = 1;
			data->track = SYNC_LAYER_CAN_DATA;
		}
	} else if (data->track == SYNC_LAYER_CAN_END_ACK) {
		id = link->endAckID;
		*(uint32_t*) bytes = data->id;

		uint8_t missingDataAvailable = 0;
		int missingFrameIndex = 0;
		int totalFrame = data->size / 7 + (data->size % 7 != 0);
		int totalGroupFrame = totalFrame / 8 + (totalFrame % 8 != 0);
		for (int group = 0; group < totalGroupFrame; group++) {
			uint8_t record = data->frameRecords[group];
			int remFrame = totalFrame - (group * 8);
			int bitLen = (remFrame > 8) ? 8 : remFrame;
			for (int bit = 0; bit < bitLen; bit++) {
				if (!(record & (1 << bit))) {
					missingDataAvailable = 1;
					missingFrameIndex = bit + 8 * group;
					break;
				}
			}
			if (missingDataAvailable)
				break;
		}

		if (missingDataAvailable) {
			bytes[4] = 1;
			bytes[5] = missingFrameIndex;
			if (link->canSend(id, bytes, 8)) {
				isSuccess = 1;
				data->track = SYNC_LAYER_CAN_MISSING_DATA;
			}
		} else {
			bytes[4] = 0;
			bytes[5] = 0;
			uint32_t crc = crc32_calculate(data->bytes, data->size);
			data->doesCRCMatch = data->crc == crc;
			bytes[6] = data->doesCRCMatch;

			if (link->canSend(id, bytes, 8)) {
				isSuccess = 1;
				if (data->doesCRCMatch)
					data->track = SYNC_LAYER_CAN_RECEIVE_SUCCESS;
				else {
					data->numTry--;
					if (data->numTry > 0) {
						data->track = SYNC_LAYER_CAN_START_REQ;
					} else {
						data->track = SYNC_LAYER_CAN_RECEIVE_FAILED;
					}
				}
			}
		}

	}

	if (isSuccess)
		data->waitTill = getMillis() + RECEIVE_TIMEOUT;

	if (getMillis() > data->waitTill) {
		data->numTry--;
		if (data->numTry > 0) {
			data->track = SYNC_LAYER_CAN_START_REQ;
		} else {
			data->track = SYNC_LAYER_CAN_RECEIVE_FAILED;
		}
	}

	return isSuccess;
}

/**
 * Receive thread for receiving should be called in thread where CAN data is being received
 * @param link 	: Link where data is to be received
 * @param data	: Data that is to be received
 * @param id	: CAN ID
 * @param bytes	: bytes received from CAN
 * @param len	: length of CAN bytes received
 */
int rxReceiveThread(SyncLayerCANLink *link, SyncLayerCANData *data,
		uint32_t id, uint8_t *bytes, uint16_t len) {
	int isSuccess = 0;
	if (data->track == SYNC_LAYER_CAN_START_REQ && id == link->startReqID) {
		for (int i = 0; i < sizeof(data->frameRecords); i++)
			data->frameRecords[i] = 0;
		isSuccess = 1;
		data->size = *(uint16_t*) (&bytes[4]);
		data->numTry = bytes[6];
		data->track = SYNC_LAYER_CAN_START_ACK;
	} else if (id == link->endReqID) {
		isSuccess = 1;
		data->crc = *(uint32_t*) (&bytes[4]);
		data->track = SYNC_LAYER_CAN_END_ACK;
	} else if (data->track == SYNC_LAYER_CAN_DATA) {
		isSuccess = 1;
		uint8_t frameIndex = bytes[0];
		int indexOffset = frameIndex * 7;
		int recordIndex = frameIndex / 8;
		int bitIndex = frameIndex % 8;
		data->frameRecords[recordIndex] = data->frameRecords[recordIndex]
				| (1 << bitIndex);
		for (int i = 0; i < (len - 1); i++)
			data->bytes[indexOffset + i] = bytes[i + 1];
	} else if (data->track == SYNC_LAYER_CAN_MISSING_DATA) {
		isSuccess = 1;
		uint8_t frameIndex = bytes[0];
		int indexOffset = frameIndex * 7;
		int recordIndex = frameIndex / 8;
		int bitIndex = frameIndex % 8;
		data->frameRecords[recordIndex] = data->frameRecords[recordIndex]
				| (1 << bitIndex);
		for (int i = 0; i < len - 1; i++)
			data->bytes[indexOffset + i] = bytes[i + 1];
	}

	if (isSuccess)
		data->waitTill = getMillis() + TRANSMIT_TIMEOUT;

	return isSuccess;
}


