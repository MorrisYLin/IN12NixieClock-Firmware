#pragma once
#include <clock.h>
#include "init.h"
#include "bulb_functions.h"
#include "ports_pins_config.h"
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_hibernate.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/hibernate.h"

//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************
#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
    while(1);
}
#endif

//*****************************************************************************
//
// main loop and initialization code
//
//*****************************************************************************


int main(void) {
	// Port and power initialization
	initPortPins();
	initOscillator();
	initInterrupts();
	bulb_power_on();

	while (1) {
		for (int i = 0; i < 6; i++) {
			bulb_displayNumber(i, getDigit(i));
		}
	}

	// Main loop for testing RTC counting from 0 upwards
//	uint32_t oldHIB_RTCC = 0;
//	while (1) {
//		if (oldHIB_RTCC != HWREG(HIB_RTCC)) {	//HWREG() macro defined in hw_types.h, casts parameter as volatile uint32_t * and dereferences
//			oldHIB_RTCC = HWREG(HIB_RTCC);		//HIB_RTCC defined in hw_hibernate.h
//			displayNumber(oldHIB_RTCC);
//		}
//	}

// Main loop for testing bulb, bulb driver circuits, and bulb api
// Cycles through 0, 1, 2, 3, ... , 9, off
//	while (1) {
//		for (int i = 0; i <= 10; i++) {
//			for (int j = 0; j < 6; j++) {
//				bulb_displayNumber(j, i);
//			}
//			for (int k = 0; k < 1500000; k++) {
//			}
//		}
//	}

	return 0;
}

//*****************************************************************************
//
// Interrupt Service Routines
// Vector table & ISR function prototypes kept in tm4c1294ncpdt_startup_ccs.c
//
//*****************************************************************************
void SysTickHandler(void) {
	static uint8_t light = 0xFF;
	GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, light);
	light = ~light;
}
