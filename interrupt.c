/*
 * File:   interrupt.c
 * Author: Owner
 *
 * Created on 06 ??????, 2022, 08:34 ?
 */


#include "Interrupt.h"
void INT0_enable( ){
    sei();// enable global interrupt
    // set INT with rising edge of pin input, ISC01 ISC00 = 1 1. 
    MCUCR |=(1<<0)| (1<<1); // setting bit 0 and bit 1 to '1'
    GICR |=(1<<6); //enable external interrupt INT0 (Bit 6 in GICR))
    
}

