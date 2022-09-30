/*
 * Project:   On_demand Traffic light
 * File:   dio.h
 * Author: Khalaf Ahmed Mahmoud
 *
 * Created on 06 Sep, 2022.
 * this file contains all typedefs of DIO ports and pins.
 * it also contains declarations of functions used for accessing DIOs.
 */

#ifndef DIO_H_ //File guard
#define	DIO_H_ //File guard
// to include all internal driver typedefs
// driver macros
// Driver functions prototypes

#include"../../Utilities/Registers.h"
//Macros for ports names
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//enum EN_direction
//{IN, OUT}EN_direction;// this is equal to below two lines
#define IN 0
#define OUT 1

//Macros for Data_write
#define LOW 0
#define HIGH 1


//Functions Declarations
//this is for initialing DIRECTION of any pin in any port of MC(I/P, O/P) 
void DIO_init (uint8_t portNumber, uint8_t pinNumber,uint8_t direction );
void DIO_write(uint8_t portNumber, uint8_t pinNumber,uint8_t data_write); //writing data to DIO.
void DIO_read(uint8_t portNumber, uint8_t pinNumber,uint8_t *data_read); // reading data from DIO, return is a pointer to data.
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber); //toggling DIO data
#endif