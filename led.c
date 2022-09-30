/*
 * * Project:   On_demand Traffic light
 * File:   led.c
 * Author: Khalaf Ahmed Mahmoud
 *
 * Created on 06 Sep, 2022.
 */


#include "led.h"
//-----------------------------------------------------------
void led_init(uint8_t ledPort,uint8_t ledPin)
{
 DIO_init(ledPort,ledPin,OUT );
 
}
//-----------------------------------------------------------
void led_on(uint8_t ledPort,uint8_t ledPin)
{
 DIO_write(ledPort,ledPin,HIGH );   
}
//-----------------------------------------------------------
void led_off(uint8_t ledPort,uint8_t ledPin)
{
 DIO_write(ledPort,ledPin,LOW );   
}
//-----------------------------------------------------------
void led_toggle(uint8_t ledPort,uint8_t ledPin)
{
 DIO_toggle(ledPort,ledPin);   
}
//-----------------------------------------------------------

void led_blink(uint8_t ledPort,uint8_t ledPin)// a 500 m sec ON - 500 m sec OFF duration  
{
 led_toggle (ledPort, ledPin); 
 TMR0_ON(5); 
 led_toggle (ledPort, ledPin);      
}

uint8_t cnt3; 
void LED_blink_5sec()
{
    for (cnt3 = 0; cnt3<10; cnt3++)
            {
              led_toggle (PORT_A, Yellow);// Cars Yellow LED ON
              led_toggle (PORT_B, Yellow);// Pedestrian Yellow LED ON
               TMR0_ON(5); 
            };
}