
/*
 * Project:   On_demand Traffic light
 * Author: Khalaf Ahmed Mahmoud
 *
 * Created on 06 Sep, 2022.
 */

#include "application.h"

//Declaring some variables
uint8_t cnt1;
uint8_t ButtonState = released ;// initial value of Button state
//variables for storing states of LED's pins
uint8_t redLightState, greenLightState, yellowLightState;
void app_init()
{
//    unsigned int cnt=0;
    TMR0_init(); //initializing TMR0
    
   //initialize ports pins for connected DIOs
    led_init(PORT_A,Green); //LED1 connected to PORTA0, configure PORTA0 as O/P
    led_init(PORT_A,Yellow); //LED2 connected to PORTA1,configure PORTA1 as O/P
    led_init(PORT_A,Red); //LED3 connected to PORTA1,configure PORTA1 as O/P
    
    led_init(PORT_B,Green); //LED4 connected to PORTB0, configure PORTB0 as O/P
    led_init(PORT_B,Yellow); //LED5 connected to PORTB1,configure PORTB1 as O/P
    led_init(PORT_B,Red); //LED6 connected to PORTB1,configure PORTB1 as O/P
    
    led_init(PORT_C,Green); // Auxiliary LED connected to PORTC0, for INT0-Active indication
    led_init(PORT_C,1); // Auxiliary LED connected to PORTC1, for Fault indication
    
    button_init(PORT_D,2);//button connected to PORTD2 (INT0))
    
    INT0_enable( );
    
    // at program start, just turn ON Fault LED for Start indication  
    led_on (PORT_C, 1);// Fault LED ON
    Loop_5sec();  // just a 5 sec delay for program start indication
    led_off (PORT_C, 1);// Fault LED OFF
 
}


void app_start(void) {
       //  button_read (PORT_D,2,&ButtonState);
       if(ButtonState == pressed)//button state went from LOW to HIGH (rising edge))
        { 
           led_on (PORT_C, 0);//  INT0-Active LED ON
            DIO_read(PORT_A,Green, &greenLightState);// Reading PINA0, store in greenLightState
            DIO_read(PORT_A,Yellow, &yellowLightState);// Reading PINA1, store in yellowLightState
            DIO_read(PORT_A,Red, &redLightState); // Reading PINA2, store in redLightState
            
           if (redLightState == 1)// if Cars RED LED is ON 
            {
             //  led_on (PORT_C, 1);//
               Loop_5sec();  // just extend the time by another 5 sec
            }
            //if Cars GREEN or YELLOW LEDs are ON
          else if (greenLightState == 1)
            {//set the yellow blinking for 5 sec
              LED_blink_5sec();// turn YELLOW LED ON for 5 sec
            
              led_on (PORT_A, Red);//Cars Red LED ON
              led_on (PORT_B, Green);// Pedestrian Green LED ON
              led_off (PORT_A, Green); //Cars GREEN LED OFF
              led_off (PORT_B, Red);//Pedestrian RED LED OFF
              Loop_5sec();
            }
          else //error handling
            {
              led_on (PORT_C, 1);// Fault indication, no light was detected
              PORTA = 0xFF;
              PORTB = 0xFF;
              Loop_5sec();
            }
            ButtonState = released ; // get out of interrupt back to normal 
            //indication that INT0 routine was finished
            led_off (PORT_C, 0);//  INT0_Active LED OFF
           
        }
        //Normal mode
        while (ButtonState == released)//button PIN = 1 (using pull-up resistor)
        {
         if (ButtonState == pressed) break;
        //Cars GREEN - Pedestrian RED 
         led_on (PORT_A, Green);//Cars Green LED ON
         led_on (PORT_B, Red);// Pedestrian Red LED ON
         led_off (PORT_A, Yellow); //Cars Yellow LED OFF
         led_off (PORT_B, Yellow);//Pedestrian Yellow LED OFF
         led_off (PORT_A, Red); //Cars Yellow LED OFF
         led_off (PORT_B, Green);//Pedestrian Yellow LED OFF
         Loop_5sec();
         
         if (ButtonState == pressed) break;
         //Cars GREEN + Yellow Blinking - Pedestrian RED + YELLOW Blinking
         LED_blink_5sec();
        
         if (ButtonState == pressed) break;
         //Cars RED  - Pedestrian GREEN
         led_on (PORT_A, Red);//Cars Red LED ON
         led_on (PORT_B, Green);// Pedestrian Green LED ON
         led_off (PORT_A, Yellow); //Cars Yellow LED OFF
         led_off (PORT_B, Yellow);//Pedestrian Yellow LED OFF
         led_off (PORT_A, Green); //Cars Yellow LED OFF
         led_off (PORT_B, Red);//Pedestrian Yellow LED OFF
         Loop_5sec();
        
         if (ButtonState == pressed) break;
         //Cars Yellow Blinking - Pedestrian YELLOW Blinking
         LED_blink_5sec();
        };
    
}
ISR(INT_0){
   //in case of INT0 Active (button pressed), change state of ButtonState
    ButtonState = pressed;
    
}
        
