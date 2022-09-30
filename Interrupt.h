#ifndef INTERRUPT_H_ //File guard
#define	INTERRUPT_H_ //File guard
// to include all internal driver typedefs
// driver macros
// Driver functions prototypes
//#include "../types.h" // going up one directory then accessing header file
#include"../../Utilities/Registers.h"

// defining interrupt vectors

#define INT_0 __vector_1 // EXTERNAL INT0
#define INT_1 __vector_2 // EXTERNAL INT1
#define INT_2 __vector_3 // EXTERNAL INT2

// enable the GLOBAL INTERRUPT (Bit 6 in STATUS REGISTER = 1) 
#define sei() __asm__ __volatile__ ("sei" ::: "memory");
// clear (disable) the GLOBAL INTERRUPT (Bit 6 in STATUS REGISTER = 0)
#define cli() __asm__ __volatile__ ("cli" ::: "memory");
//ISR for calling interrupt routine
#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal, used));\
void INT_VECT(void)


// functions declarations
 void INT0_enable(void);
 

#endif