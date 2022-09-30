/*
 * File:   button.c
 * Author: Owner
 *
 * Created on 06 ??????, 2022, 08:33 ?
 */


#include "button.h"

void button_init (uint8_t buttonPort, uint8_t buttonPin)
{
  DIO_init(buttonPort,buttonPin,IN ); //Button is an I?P device 
}

//check button state (if pressed)
void button_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *button_state)
{
  DIO_read(buttonPort,buttonPin,button_state);  
}
