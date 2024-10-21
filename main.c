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

    //
    // Enable the GPIO port that is used for the on-board LED.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION); //blinky light

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOM); //used to enable to boost converter

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOK);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOP);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOJ);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOL);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);




    //
    // Check if the peripheral access is enabled.
    //
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPION) || !SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOK) || !SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOK) ||  !SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOM) )
    {
    }

    //
    // Enable the GPIO pin for the LED (PN0).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    //
    GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0);
    GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_4); //PM4 high voltage enable 170V
    GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_4, 0); //M4 boost Converter

    //Bulb 0 init pins that are attached to the decoder
    GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_1); //B0 K1
    GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_4); //B1 E4
    GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_5); //B2 E5
    GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_0); //B3 K0

    //bulb 0 off
    GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, GPIO_PIN_4 );
    GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, GPIO_PIN_5 );
    GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_0,GPIO_PIN_0 );
    GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_1, GPIO_PIN_1);



    //Bulb 1 init
    GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_4); //B0 D4
    GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_2); //B1 K2
    GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_3); //B2 K3
    GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_5); //B3 D5

    //Bulb 1 Off
    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_4, GPIO_PIN_4 );
    GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_2, GPIO_PIN_2 );
    GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_3,GPIO_PIN_3 );
    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_5, GPIO_PIN_5);


    //Bulb 2 init
    GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_2); //B0 D2
    GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_3); //B1 D3
    GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_1); //B2 D1
    GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_0); //B3 D0

    //Bulb 2 Off
    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_2, GPIO_PIN_2 );
    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, GPIO_PIN_3 );
    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1,GPIO_PIN_1 );
    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, GPIO_PIN_0);


    //Bulb 3 init
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2); //B0 F2
    GPIOPinTypeGPIOOutput(GPIO_PORTL_BASE, GPIO_PIN_4); //B1 L4
    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_2); //B2 B2
    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_3); //B3 B3


    //Bulb 3 Off
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2 );
    GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_4, GPIO_PIN_4 );
    GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2,GPIO_PIN_2 );
    GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, GPIO_PIN_3);

    //Bulb 4 init
    GPIOPinTypeGPIOOutput(GPIO_PORTJ_BASE, GPIO_PIN_0); //B0 J0
    GPIOPinTypeGPIOOutput(GPIO_PORTP_BASE, GPIO_PIN_3); //B1 P3
    GPIOPinTypeGPIOOutput(GPIO_PORTP_BASE, GPIO_PIN_4); //B2 P4
    GPIOPinTypeGPIOOutput(GPIO_PORTP_BASE, GPIO_PIN_5); //B3 P5

    //Bulb 4 Off
    GPIOPinWrite(GPIO_PORTJ_BASE, GPIO_PIN_0, GPIO_PIN_0 );
    GPIOPinWrite(GPIO_PORTP_BASE, GPIO_PIN_3, GPIO_PIN_3 );
    GPIOPinWrite(GPIO_PORTP_BASE, GPIO_PIN_4,GPIO_PIN_4 );
    GPIOPinWrite(GPIO_PORTP_BASE, GPIO_PIN_5, GPIO_PIN_5);

    //Bulb 5
    GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_5); //B0 M5
    GPIOPinTypeGPIOOutput(GPIO_PORTJ_BASE, GPIO_PIN_1); //B1 J1
    GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_7); //B2 M7
    GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_6); //B3 M6

    //Bulb 5 Off
    GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_5, GPIO_PIN_5 );
    GPIOPinWrite(GPIO_PORTJ_BASE, GPIO_PIN_1, GPIO_PIN_1 );
    GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_7,GPIO_PIN_7 );
    GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_6, GPIO_PIN_6);








    GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_4, GPIO_PIN_4); //M4 boost Converter

    //Turnin Bulbs 1 to 5 off




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
