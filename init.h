/*
 * test.h
 *
 *  Created on: Oct 23, 2024
 *      Author: jacob
 */

#ifndef INIT_H_
#define INIT_H_

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

int init();

extern int bulb0_PORTS[4];
extern int bulb0_PINS[4];

extern int bulb1_PORTS[4];
extern int bulb1_PINS[4];

extern int bulb2_PORTS[4];
extern int bulb2_PINS[4];

extern int bulb3_PORTS[4];
extern int bulb3_PINS[4];

extern int bulb4_PORTS[4];
extern int bulb4_PINS[4];

extern int bulb5_PORTS[4];
extern int bulb5_PINS[4];

extern int bulb_PORTS[6][4];

extern int bulb_PINS[6][4];


#endif /* INIT_H_ */