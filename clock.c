/*
 * display.c
 *
 *  Created on: Jan 5, 2025
 *      Author: mlin
 */
#include <clock.h>

static uint8_t digit[6] = { 0, 0, 0, 0, 0, 0 };
static uint8_t colon = 0x0F;

static uint32_t year = 2025;
static uint8_t month = 1;
static uint8_t day = 1;

static uint8_t hour = 0;
static uint8_t min = 0;
static uint8_t sec = 0;

void RTCHandler(void) {
	HibernateIntClear(HIBERNATE_INT_RTC_MATCH_0);
	static uint8_t light = 0xFF;
	GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, light);
	light = ~light;

	updateTime();

	HibernateRTCMatchSet(0, HibernateRTCGet() + 1);
}

void updateTime() {
	sec++;

	if (sec == 60) {
		min++;
		sec = 0;
	}
	if (min == 60) {
		hour++;
		min = 0;
	}
	if (hour == 24) {
		hour = 0;
	}

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
