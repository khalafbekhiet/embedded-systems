/*
 * Project:   On_demand Traffic light
 *  File:   DIO.c
 * Author: Khalaf Ahmed Mahmoud
 *
 * Created on 06 Sep, 2022.
 */

#include "dio.h"

void DIO_init (uint8_t portNumber, uint8_t pinNumber,uint8_t direction )
{
 switch (portNumber)
 {
     case PORT_A:
         if (direction == IN)// if direction was set to IN
         {
             DDRA &= ~(1<<pinNumber); // setting pin as INPUT
         }
         else if (direction ==  OUT)// if direction was set to OUT
         {
           DDRA |=(1<<pinNumber);// setting pin as OUTPUT pin  
         }
         else 
         {
             // Error handling technique, to be discussed later
         }
         break;
     case PORT_B:
         if (direction == IN)// if direction was set to IN
         {
             DDRB &= ~(1<<pinNumber); // setting pin as INPUT
         }
         else if (direction == OUT)// if direction was set to OUT
         {
           DDRB |=(1<<pinNumber);// setting pin as OUTPUT pin  
         }
         else 
         {
             // Error handling technique, to be discussed later
             // as we could make the function return a value in case of error
         }
         break;
     case PORT_C:
         if (direction == IN)// if direction was set to IN
         {
             DDRC &= ~(1<<pinNumber); // setting pin as INPUT
         }
         else if (direction == OUT)// if direction was set to OUT
         {
           DDRC |=(1<<pinNumber);// setting pin as OUTPUT pin  
         }
         else 
         {
             // Error handling technique, to be discussed later
             // as we could make the function return a value in case of error
         }
         break;
     case PORT_D:
         if (direction == IN)// if direction was set to IN
         {
             DDRD &= ~(1<<pinNumber); // setting pin as INPUT
         }
         else if (direction == OUT)// if direction was set to OUT
         {
           DDRD |=(1<<pinNumber);// setting pin as OUTPUT pin  
         }
         else 
         {
             // Error handling technique, to be discussed later
             // as we could make the function return a value in case of error
         }
         break;
 }      
}
//-------------------------------------------------------------------------------
void DIO_write(uint8_t portNumber, uint8_t pinNumber,uint8_t data_write)
{
  switch (portNumber)
 {
      case PORT_A:
         if (data_write == LOW)// if data_write = 0
         {
             PORTA &= ~(1<<pinNumber); // output of pin = 0 (ZERO volt))
         }
         else if ( data_write == HIGH)// if data_write = 1
         {
           PORTA |=(1<<pinNumber);// output of pin = 1 (5 volt)) 
         }
         else 
         {
             // Error handling technique, to be discussed later
         }
         break;
      case PORT_B:
         if (data_write == LOW)// if data_write = 0
         {
             PORTB &= ~(1<<pinNumber); // output of pin = 0 (ZERO volt))
         }
         else if ( data_write == HIGH)// if data_write = 1
         {
           PORTB |=(1<<pinNumber);// output of pin = 1 (5 volt))  
         }
         else 
         {
             // Error handling technique, to be discussed later             
         }
         break;
      case PORT_C:
         if (data_write == LOW)// if data_write = 0
         {
             PORTC &= ~(1<<pinNumber); // output of pin = 0 (ZERO volt))
         }
         else if ( data_write == HIGH)// if data_write = 1
         {
           PORTC |=(1<<pinNumber);// output of pin = 1 (5 volt))  
         }
         else 
         {
             // Error handling technique, to be discussed later             
         }
         break;
      case PORT_D:
         if (data_write == LOW)// if data_write = 0
         {
             PORTD &= ~(1<<pinNumber); // output of pin = 0 (ZERO volt))
         }
         else if ( data_write == HIGH)// if data_write = 1
         {
           PORTD |=(1<<pinNumber);// output of pin = 1 (5 volt))  
         }
         else 
         {
             // Error handling technique, to be discussed later            
         }
         break;
  }       
}//writing data to DIO.

//------------------------------------------------------------------------------
void DIO_read(uint8_t portNumber, uint8_t pinNumber,uint8_t *data_read)
{
  switch (portNumber)
 {
      case PORT_A:
        //reading value of pin (0 or 1), then shift back to right so that State equals value of PIN
          //value of PIN will be either 0 or 1.
        *data_read = (PINA & (1<<pinNumber))>>pinNumber; // read pin value
        break;
      case PORT_B:
        *data_read = (PINB & (1<<pinNumber))>>pinNumber; // read pin value
         break;
      case PORT_C:
         *data_read = (PINC & (1<<pinNumber))>>pinNumber; // read pin value
         break;
      case PORT_D:
         *data_read = (PIND & (1<<pinNumber))>>pinNumber; // read pin value
         break;
      default:
         //error handling code
         break;
  }          
}// reading data from DIO, return is a pointer to data.

//------------------------------------------------------------------------------
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber)
{
  switch (portNumber)
 {
      case PORT_A:
            PORTA ^=(1<<pinNumber);
            break;
      case PORT_B:
            PORTB ^=(1<<pinNumber);
            break;
      case PORT_C:
            PORTC ^=(1<<pinNumber);
            break;
      case PORT_D:
            PORTD ^=(1<<pinNumber);
            break;
      default:
         //error handling code
         break;
  }            
}//toggling DIO data
