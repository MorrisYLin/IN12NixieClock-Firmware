/*
 * test.h
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
#include "driverlib/systick.h"
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"
#include "driverlib/hibernate.h"

/* Enables all needed GPIO ports and sets in/out
 */
int initPortPins();

/* Initializes the 32.786 kHz oscillator used as the source for the RTC
 * Must enable hibernate module since oscillator is attached to that
 */
int initOscillator();

/* Initializes all timers and other interrupts
 */
int initInterrupts();
