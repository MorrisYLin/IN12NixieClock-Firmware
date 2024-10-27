/*
 * bulb_functions.c
 *
 *  Created on: Oct 23, 2024
 *      Author: jacob
 */
#pragma once
#include "bulb_functions.h"
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

int bulb_off(int bulbNum){

    for(int i = 0; i < 4; i++){
        GPIOPinWrite(bulb_PORTS[bulbNum][i], bulb_PINS[bulbNum][i], bulb_PINS[bulbNum][i]);

    }
    return 0;
}

int bulb_displayNumber(int bulbNum, uint8_t displayNum){
    if(bulbNum > 3 || bulbNum < 0){
        return -1;
    }

    if(displayNum > 9){
        bulb_off(bulbNum);
        return 10;
    }

    for(int decoderPin = 0; decoderPin < 4; decoderPin++){
        int bit = (displayNum>>decoderPin)& 0x01;
        GPIOPinWrite(bulb_PORTS[bulbNum][decoderPin], bulb_PINS[bulbNum][decoderPin], bit ? bulb_PINS[bulbNum][decoderPin] : 0);
    }

    return 0;
}

