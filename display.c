/*
 * display.c
 *
 *  Created on: Jan 5, 2025
 *      Author: mlin
 */
#include "display.h"

static uint8_t digit[6] = {0, 0, 0, 0, 2, 1};
static uint8_t colon = 0x0F;

static uint8_t hour = 12;
static uint8_t min = 0;
static uint8_t sec = 0;

void RTCHandler(void) {
	HibernateIntClear(HIBERNATE_INT_RTC_MATCH_0);
	static uint8_t light = 0xFF;
	GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, light);
	light = ~light;

	updateTime(HibernateRTCGet());

	HibernateRTCMatchSet(0, HibernateRTCGet() + 1);
}

void updateTime(uint32_t RTCCount) {
	RTCCount = RTCCount % 86400;	// Limit to 24hrs, 0 to 86400 sec
	sec = RTCCount % 60;
	RTCCount /= 60;
	min = RTCCount % 60;
	RTCCount /= 60;
	hour = RTCCount % 60;

	digit[0] = sec % 10;
	digit[1] = sec / 10;
	digit[2] = min % 10;
	digit[3] = min / 10;
	digit[4] = hour % 10;
	digit[5] = hour / 10;
}

uint8_t getDigit(int digNum) {
	return digit[digNum];
}
