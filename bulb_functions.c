/*
 * bulb_functions.c
 *
 *  Created on: Oct 23, 2024
 *      Author: jacob
 */

#include "bulb_functions.h"

void bulb_power_on() {
	GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_4, GPIO_PIN_4);
}

void bulb_power_off() {
	GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_4, 0);
}

int bulb_off(uint8_t bulbNum) {
	return bulb_displayNumber(bulbNum, 15);
}

int bulb_displayNumber(uint8_t bulbNum, uint8_t displayNum) {
	if (bulbNum > 5)
		return -1;
	for (int decoderPin = 0; decoderPin < 4; decoderPin++) {
		int bit = (displayNum >> decoderPin) & 0x01;
		GPIOPinWrite(bulb_PORTS[bulbNum][decoderPin],
				bulb_PINS[bulbNum][decoderPin],
				bit ? bulb_PINS[bulbNum][decoderPin] : 0);
	}

	return 0;
}

void colon_display(uint8_t colon) {
	for (int decoderPin = 0; decoderPin < 4; decoderPin++) {
		int bit = (colon >> decoderPin) & 0x01;
		GPIOPinWrite(colon_PORTS[decoderPin], colon_PINS[decoderPin],
				bit ? colon_PINS[decoderPin] : 0);
	}
}

int displayNumber(uint32_t num) {
	for (int i = 0; i < 6; i++) {
		bulb_displayNumber(i, num % 10);
		num /= 10;
	}
	return 0;
}
