#ifndef BUTTON_H_ //File guard
#define	BUTTON_H_ //File guard
// to include all internal driver typedefs
// driver macros
// Driver functions prototypes
//#include "../types.h" // going up one directory then accessing header file
//#include"../../Utilities/Registers.h"
#include "../../MCAL/DIO/dio.h"// included here, then in button.c we include only button.h
//button.h is in upper layer, and it can call lower layers such as DIO.h 

//Macros for button state
#define pressed 0
#define released 1

//initializing button port and pin configuration
void button_init (uint8_t buttonPort, uint8_t buttonPin);

//check button state (if pressed)
void button_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *button_state);
#endif