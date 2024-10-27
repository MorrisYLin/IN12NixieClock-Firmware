/*
 * bulbFunctions.h
 *
 *  Created on: Oct 23, 2024
 *      Author: jacob
 */

#ifndef BULB_FUNCTIONS_H_
#define BULB_FUNCTIONS_H_

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "init.h"
#include "ports_pins_config.h"

//returns 0 if bulbNum is valid
int bulb_off(int bulbNum);

/*if bulbNum is not a valid bulb number (0-6) then function returns -1
*Turns the bulb off and returns 10 if displayNum is >9.
*Turns bulb to displayNum and returns 0 if displayNum is valid and bulb number is valid
 */

int bulb_displayNumber(int bulbNum, uint8_t displayNum);




#endif /* BULB_FUNCTIONS_H_ */
