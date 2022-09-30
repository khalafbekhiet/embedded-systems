


/*
 * * Project:   On_demand Traffic light
 * File:   main.c
 * Author: Khalaf Ahmed Mahmoud
 *
 * Created on 06 Sep, 2022.
 */

//#include <avr/io.h>
//#include "registers.h"
//#define F_CPU 1000000U// 1MHz clock

#include "Application/application.h"
//#include <util/delay.h>

int main(void) {
    
    //  uint8_t ButtonState;
    app_init();
    while(1)
    {
      
     app_start();   
     
    }
  //  return(0);
}

