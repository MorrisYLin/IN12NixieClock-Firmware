/*
 * display.h
 *
 *  Created on: Jan 5, 2025
 *      Author: mlin
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "bulb_functions.h"
#include "driverlib/hibernate.h"

void updateTime(uint32_t RTCCount);
uint8_t getDigit(int digNum);
void RTCHandler(void);
