#ifndef LED_H_ //File guard
#define	LED_H_ //File guard
// to include all internal driver typedefs
// driver macros
// Driver functions prototypes
//#include "../types.h" // going up one directory then accessing header file
#include"../../Utilities/Registers.h"
#include "../../MCAL/DIO/dio.h"// included here, then in led.c we include only led.h
//led.h is in upper layer, and it can call lower layers such as DIO.h

#include "../../MCAL/TIMER/timer.h"// for led_blink function, we need to include timer.h
//led.h is in upper layer, and it can call lower layers such as timer.h

#define Red 0
#define Yellow 1
#define Green 2


// declaring functions related LED action
void led_init(uint8_t ledPort,uint8_t ledPin);
void led_on(uint8_t ledPort,uint8_t ledPin);
void led_off(uint8_t ledPort,uint8_t ledPin);
void led_toggle(uint8_t ledPort,uint8_t ledPin);
void led_blink(uint8_t ledPort,uint8_t ledPin);
#endif