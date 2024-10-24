//*****************************************************************************
//
// blinky.c - Simple example to blink the on-board LED.
//
// Copyright (c) 2013-2020 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
//
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
//
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
//
// This is part of revision 2.2.0.295 of the EK-TM4C1294XL Firmware Package.
//
//*****************************************************************************
#pragma once
#include "init.h"
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

//*****************************************************************************
//
//! \addtogroup example_list
//! <h1>Blinky (blinky)</h1>
//!
//! A very simple example that blinks the on-board LED using direct register
//! access.
//
//*****************************************************************************

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
// Blink the on-board LED.
//
//*****************************************************************************
int main(void)
{
    volatile uint32_t ui32Loop;





                                //msb --> //lsb
    int numsInBinary [10][4] = {{0,0,0,0},
                                {0,0,0,1},
                                {0,0,1,0},
                                {0,0,1,1},
                                {0,1,0,0},
                                {0,1,0,1},
                                {0,1,1,0},
                                {0,1,1,1},
                                {1,0,0,0},
                                {1,0,0,1}
    };
    int i = 7;

    while(1)
   {
        //
        // Turn on the LED.
        //
        GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, GPIO_PIN_0);

        GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_1, numsInBinary[i][3]<<1); //b0 k1 lsb
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, numsInBinary[i][2]<<4); //b1 E4
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, numsInBinary[i][1]<<5); //b2 E5
        GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_0, numsInBinary[i][0]<<0); //b3 k0 msb



        // Delay for a bit.
        //
        for(ui32Loop = 0; ui32Loop < 2000000; ui32Loop++)
        {
        }

        //
        // Turn off the LED.
        //
        GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0x0);

        //
        // Delay for a bit.
        //
        for(ui32Loop = 0; ui32Loop < 2000000; ui32Loop++)
        {
        }
        i = (i+1)%10;


    }


}
