#ifndef APPLICATION_H_ //File guard
#define	APPLICATION_H_ //File guard
// to include all internal driver typedefs
// driver macros
// Driver functions prototypes
//#include "../types.h" // going up one directory then accessing header file
#include "../ECUAL/LED/led.h"
#include "../ECUAL/BUTTON/button.h"
#include "../MCAL/TIMER/timer.h"
#include "../MCAL/INTERRUPT/Interrupt.h"
// declaring functions related LED action
void app_init(void);
void app_start(void);
void Loop_5sec(void);

#endif