/*
 * Can_Start.h
 *
 *  Created on: Nov 27, 2022
 *      Author: Thakur Paudel
 */

#ifndef INC_CAN_START_H_
#define INC_CAN_START_H_

#include "main.h"

extern CAN_HandleTypeDef hcan;

void init_can(void);
void filter_can(void);
void Start_Can_Communication(void);

#endif /* INC_CAN_START_H_ */
