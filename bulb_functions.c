/*
 * bulb_functions.c
 *
 *  Created on: Oct 23, 2024
 *      Author: jacob
 */


int bulb_Off(int bulbNum){
    for(int i = 0; i < 4; i++){
        GPIOinWrite(bulb_PORTS[bulbNum][i], bulb_PINS[bulbNum][i], bulb_PINS[bulbNum][i]);
    }
    return 0;
}

int bulb_DisplayNumber(int bulbNum, uint8_t displayNum){
    if(displayNum > 9){
        bulb_Off(bulbNum);
        return -1;
    }
    for(int i = 0; i < 4; i++){
        int bit = (displayNum>>i)& 0x01;
        GPIOinWrite(bulb_PORTS[bulbNum][i], bulb_PINS[bulbNum][i], bit <<bulb_PINS[bulbNum][i]);
    }

    return 0;
}

