/*
 * bulbFunctions.h
 *
 *  Created on: Oct 23, 2024
 *      Author: jacob
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "ports_pins_config.h"

/* Bulbs are numbered accordingly:
 * 		h h : m m : s s
 * 		5 4   3 2   1 0
 * Colons are numbered accordingly:
 *			2	  0
 *			3	  1
 */

/* Turns on boost converter.
 */
void bulb_power_on();

/* Turns off boost converter.
 */
void bulb_power_off();

/* Turns off a bulb.
 * If bulbNum is invalid, no effect and returns -1.
 */
int bulb_off(uint8_t bulbNum);

/* Displays number onto specified bulb number.
 * If displayNum > 9 bulb is shut off (by behavior of decoder)
 * If bulbNum is invalid, no effect and returns -1.
 */
int bulb_displayNumber(uint8_t bulbNum, uint8_t displayNum);
