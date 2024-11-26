/*
 * test.c
 *
 *  Created on: Oct 23, 2024
 *      Author: jacob
 */
#pragma once
#include "init.h"


int init(){
    //
     // Enable the GPIO port that is used for the on-board LED.
     //
     SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION); //blink light
     SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOM); //used to enable to boost converter

     SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOK); //bulb 0
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



     GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, GPIO_PIN_4 );
     GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, GPIO_PIN_5 );
     GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_0,GPIO_PIN_0 );
     GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_1, GPIO_PIN_1);

     GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_4, GPIO_PIN_4); //M4 boost Converter

     return 0;

}


