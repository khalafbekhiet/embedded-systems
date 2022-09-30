/* this header file is a replacement fo avr/io.h file
 **************************************************
 *          Defining all MC registers
 * ************************************************
 */
#ifndef REGISTERS_H_ //File gaurd
#define	REGISTERS_H_ //File guard
#include "types.h" // including a definition h file for uint8_t

/* 
 **************************************************
 *          1- DIO REGISTERS
 * ************************************************
 */
#define PORTA *((volatile uint8_t*)0x3B)//define an 8-bit register at ddress 0x3B as PORTA
#define DDRA *((volatile uint8_t*)0x3A)//define an 8-bit register at ddress 0x3A as DDRA
#define PINA *((volatile uint8_t*)0x39)//define an 8-bit register at ddress 0x39 as PINA

#define PORTB *((volatile uint8_t*)0x38)//define an 8-bit register at ddress 0x38 as PORTB
#define DDRB *((volatile uint8_t*)0x37)//define an 8-bit register at ddress 0x37 as DDRB
#define PINB *((volatile uint8_t*)0x36)//define an 8-bit register at ddress 0x36 as PINB

#define PORTC *((volatile uint8_t*)0x35)//define an 8-bit register at ddress 0x35 as PORTC
#define DDRC *((volatile uint8_t*)0x34)//define an 8-bit register at ddress 0x34 as DDRC
#define PINC *((volatile uint8_t*)0x33)//define an 8-bit register at ddress 0x33 as PINC

#define PORTD *((volatile uint8_t*)0x32)//define an 8-bit register at ddress 0x3B as PORTD
#define DDRD *((volatile uint8_t*)0x31)//define an 8-bit register at ddress 0x3A as DDRD
#define PIND *((volatile uint8_t*)0x30)//define an 8-bit register at ddress 0x39 as PIND

/* 
 **************************************************
 *          2- TIMER REGISTERS
 * ************************************************
 */
 // TCCR0 = FOC0 WGM00 COM01 COM00 WGM01 CS02 CS01 CS00
#define TCCR0 *((volatile uint8_t*)0x53)//TMR0 Control Register
#define TCNT0 *((volatile uint8_t*)0x52)//TMR0 Data register, counts from 0 or any pre-set value
// TIFR = OCF2 TOV2 ICF1 OCF1A OCF1B TOV1 OCF0 TOV0
#define TIFR *((volatile uint8_t*)0x58)//TIFR  Bit 0 contains TOV0 (TMR0 overflow flag)
// TIMSK = OCIE2 TOIE2 TICIE1 OCIE1A OCIE1B TOIE1 OCIE0 TOIE0
#define TIMSK *((volatile uint8_t*)0x59)// Timer Iterrupt Flag, Bit0 and Bit1 relate to TMR0

//TMR1 relevant Registers
#define TCCR1A *((volatile uint8_t*)0x4F)//COM1A1 COM1A0 COM1B1 COM1B0 FOC1A FOC1B WGM11 WGM10
#define TCCR1B *((volatile uint8_t*)0x4E)//ICNC1 ICES1 ? WGM13 WGM12 CS12 CS11 CS10
#define TCNT1H *((volatile uint8_t*)0x4D)// upper 8-bits of TMR1
#define TCNT1L *((volatile uint8_t*)0x4C)// Lower 8-bits of TMR1
//TIFR  Bit2 contains TOV1 (TMR1 overflow flag)
// TIMSK Bits 2 - 5 relate to TMR1

//TMR2 relevant Registers
#define TCCR2 *((volatile uint8_t*)0x45)//define an 8-bit register at ddress 0x53 as TCCR0
#define TCNT2 *((volatile uint8_t*)0x44)//define an 8-bit register at ddress 0x52 as TCNT0
//TIFR  Bit 6 contains TOV2 (TMR2 overflow flag)
// TIMSK Bit6 and Bit7 relate to TMR2


/* 
 **************************************************
 *          3- INTERRUPT REGISTERS
 * ************************************************
 */
#define MCUCR *((volatile uint8_t*)0x55)//define an 8-bit register at ddress 0x55 as MCUCR
#define MCUCSR *((volatile uint8_t*)0x54)//define an 8-bit register at ddress 0x54 as MCUCSR
#define GICR *((volatile uint8_t*)0x5B)//define an 8-bit register at ddress 0x5B as GICR
#define GIFR *((volatile uint8_t*)0x5A)//define an 8-bit register at ddress 0x5A as GIFR


#endif

   