
#ifndef TIMER_H_ //File guard
#define	TIMER_H_ //File guard

//macro for setting total no. of overflows to reset timer flag
// for 500 m sec delay and 1MHz clock, the prescaler is set to 1024 (TCCR = 0x05)
//no. of overflows = 2, and TCNT = 6.
# define tot_overflows 2

#include"../../Utilities/Registers.h"
   void TMR0_init();
   void TMR0_ON(uint8_t prescaler);
   void TMR0_OFF();
   void Loop_5sec();
   void LED_blink_5sec();
#endif