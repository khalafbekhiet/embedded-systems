/*
 * File:   timer.c
 * Author: Owner
 *
 * Created on 06 ??????, 2022, 08:35 ?
 */


#include "timer.h"

void TMR0_init()
    {
     
    // TMR0 is configured in normal mode
     /*(WGM01:0 = 0). In this mode, the counting direction is always up
      *  (incrementing), and no counter clear is performed. The counter simply
      *  overruns when it passes its maximum 8-bit value (TOP = 0xFF) and then restarts
      *  from the bottom (0x00).
      */
    //initialize TMR0
    //  7     6     5     4     3    2    1    0
    // FOC0 WGM00 COM01 COM00 WGM01 CS02 CS01 CS00
    TCCR0 = 0x0;// no clock, no timer set
    TCNT0 = 0x0; // TMR0 initial value = 1 
    TIFR = 0x01; //Clear overflow flag
    }
//-----------------------------------------------------
unsigned int overflow_counter =0;
void TMR0_ON(uint8_t prescaler)// CS02 CS01 CS00: 0-5 RANGE
   {//CS=1 CLK, CS =2 CLK/8 , CS=3 CLK/64, CS=4 CLK/256, CS=5 CLK/1024 
    TCCR0= prescaler;// for traffic light app, 500 m sec delay needs prescaler of 1024 (TCCR0 = 5),
    TCNT0 = 12; //initial value of timer for 500 m sec delay
        // tot_overflows is defined in timer.h
        while(overflow_counter < tot_overflows)// next loop will be repeated 2 times
        {
          // check TIFR0 overflow flag bit (TOV0) if 0, that means one overflow occured
          while ((TIFR& (1<<0))==0)// compare TIFR0 with 0000 0001 to check for Bit0 state.
          {
              // do nothing, this is called busy wait.
          }
        //while ((TIFR & (1<<0))== 0); // same as above while-loop  

          // set TOV0 flag after being reset by overflow.
          TIFR |=(1<<0);
          overflow_counter++;
        } 
    // stopping timer
      TCCR0 =0x0;// no clock, no timer set
      overflow_counter = 0;
   }

//-----------------------------------------------------
void TMR0_OFF()
   {
   TCCR0 =0x0;// no clock, no timer set    
   }
uint8_t cnt;

void Loop_5sec()
{
 for (cnt = 0; cnt<10; cnt++)
 {
    TMR0_ON(5); 
 }
}

