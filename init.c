/*
 * test.c
 *
 *  Created on: Oct 23, 2024
 *      Author: jacob
 */
#pragma once
#include "init.h"
#include "ports_pins_config.h"

int initPortPins() {
	// HVen (boost converter enable)
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOM);

	// Heartbeat LED
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);

	// Enable all ports used by encoders for Nixie drivers
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOK);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOP);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOJ);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOL);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

	// Wait until peripheral access is enabled.
	while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOM)
			|| !SysCtlPeripheralReady(SYSCTL_PERIPH_GPION)
			|| !SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOK)
			|| !SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE)
			|| !SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD)
			|| !SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOP)
			|| !SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)
			|| !SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOJ)
			|| !SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOL)
			|| !SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB)) {
	}

	// PM4 is HVen (170V boost converter enable)
	GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_4);
	GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_4, 0); // disable boost converter

	// Heartbeat LED
	GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0);

	//Bulb 0 init
	GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_1); //B0 K1
	GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_4); //B1 E4
	GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_5); //B2 E5
	GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_0); //B3 K0

	//Bulb 0 off
	GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_1, GPIO_PIN_1);
	GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, GPIO_PIN_4);
	GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, GPIO_PIN_5);
	GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_0, GPIO_PIN_0);

	//Bulb 1 init
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_4); //B0 D4
	GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_2); //B1 K2
	GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_3); //B2 K3
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_5); //B3 D5

	//Bulb 1 off
	GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_4, GPIO_PIN_4);
	GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_2, GPIO_PIN_2);
	GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_3, GPIO_PIN_3);
	GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_5, GPIO_PIN_5);

	//Bulb 2 init
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_2); //B0 D2
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_3); //B1 D3
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_1); //B2 D1
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_0); //B3 D0

	//Bulb 2 off
	GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_2, GPIO_PIN_2);
	GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, GPIO_PIN_3);
	GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, GPIO_PIN_1);
	GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, GPIO_PIN_0);

	//Bulb 3 init
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2); //B0 F2
	GPIOPinTypeGPIOOutput(GPIO_PORTL_BASE, GPIO_PIN_4); //B1 L4
	GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_2); //B2 B2
	GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_3); //B3 B3

	//Bulb 3 off
	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
	GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_4, GPIO_PIN_4);
	GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, GPIO_PIN_2);
	GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, GPIO_PIN_3);

	//Bulb 4 init
	GPIOPinTypeGPIOOutput(GPIO_PORTJ_BASE, GPIO_PIN_0); //B0 J0
	GPIOPinTypeGPIOOutput(GPIO_PORTP_BASE, GPIO_PIN_3); //B1 P3
	GPIOPinTypeGPIOOutput(GPIO_PORTP_BASE, GPIO_PIN_4); //B2 P4
	GPIOPinTypeGPIOOutput(GPIO_PORTP_BASE, GPIO_PIN_5); //B3 P5

	//Bulb 4 off
	GPIOPinWrite(GPIO_PORTJ_BASE, GPIO_PIN_0, GPIO_PIN_0);
	GPIOPinWrite(GPIO_PORTP_BASE, GPIO_PIN_3, GPIO_PIN_3);
	GPIOPinWrite(GPIO_PORTP_BASE, GPIO_PIN_4, GPIO_PIN_4);
	GPIOPinWrite(GPIO_PORTP_BASE, GPIO_PIN_5, GPIO_PIN_5);

	//Bulb 5 init
	GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_5); //B0 M5
	GPIOPinTypeGPIOOutput(GPIO_PORTJ_BASE, GPIO_PIN_1); //B1 J1
	GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_7); //B2 M7
	GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_6); //B3 M6

	//Bulb 5 off
	GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_5, GPIO_PIN_5);
	GPIOPinWrite(GPIO_PORTJ_BASE, GPIO_PIN_1, GPIO_PIN_1);
	GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_7, GPIO_PIN_7);
	GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_6, GPIO_PIN_6);

	//Colon init
	for (int i = 0; i < 4; i++) {
		GPIOPinTypeGPIOOutput(colon_PORTS[i], colon_PINS[i]);
	}

	//Colon off
	for (int i = 0; i < 4; i++) {
		GPIOPinWrite(colon_PORTS[i], colon_PINS[i], colon_PINS[i]);
	}

	return 0;
}

int initOscillator() {
	SysCtlPeripheralEnable(SYSCTL_PERIPH_HIBERNATE); // enable hibernate module just for its RTC

	while (!SysCtlPeripheralReady(SYSCTL_PERIPH_HIBERNATE)) { // wait for ready
	}

	HibernateEnableExpClk(32786); // The RTC oscillator on the devboard is 32.786 kHz

	for (int i = 160000; i != 0; i--) {
	}

	HibernateClockConfig(HIBERNATE_OSC_LOWDRIVE);
	HibernateRTCEnable();

	HibernateRTCSet(0); // Setting hibernate value to 0

	return 0;
}

extern void RTCHandler(void);

int initInterrupts() {
	// enabling peripherals
//	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER7); // RTC on Timer 7

//	while (!SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER7)) { // Wait for ready
//	}

	// timer configurations
//	SysTickPeriodSet(0x00ffffff); // full length
//	TimerConfigure(TIMER7_BASE, TIMER_CFG_RTC);

	// interrupt configurations
//	TimerIntRegister(TIMER7_BASE, TIMER_BOTH, RTCHandler);

	// interrupt enables
//	SysTickIntEnable();
//	TimerIntEnable(TIMER7_BASE, TIMER_RTC_MATCH);
	HibernateIntEnable(HIBERNATE_INT_RTC_MATCH_0);

	// timer enables
//	SysTickEnable();
//	TimerRTCEnable(TIMER7_BASE); // explicitly need RTC style of enable

	// Processor interrupt enable
	IntEnable(INT_HIBERNATE);

	// Setting 1-second interrupt
	uint32_t currentTime = HibernateRTCGet();
	HibernateRTCMatchSet(0, currentTime + 1);

	return 0;
}
