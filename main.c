/*
 * File:   main.c
 * Author: Hassan
 *
 * Created on 29 ?????, 2020, 01:07 ?
 */
#define _XTAL_FREQ 8000000 
#include <xc.h>
#include "config.h"
#include "types.h"
#include "macros.h"
#include "dio.h"
#include "lcd.h"
#include "ssd.h"
#include "scheduler.h"
volatile u8 counter = 0;

void __interrupt() ISR (void) {
    if (TMR1IF == 1) // Timer 1 flag has been triggered due to timer overflow
    {
        TMR1IF = 0;
        counter++;
        if (counter == 15) {
            counter = 0;
            PORTB = ~PORTB;
        }
    }
}

int main(void) {

    dio_vid_set_port_direction(B, 0);
    dio_vid_set_port_value(B, 0);

    /*Enable timer 1 Interrupt*/
    TMR1IE = 1;
    /*Enable the Peripheral Interrupt*/
    PEIE = 1;
    /*Enable Global Interrupt*/
    GIE = 1;
    /*Enables Timer1*/
    TMR1ON = 1;

    
    /*while (1) {
    if (TMR1IF == 1) // Timer flag has been triggered due to timer overflow
    {
        TMR1IF = 0;
        counter++;
        if (counter == 15) {
            counter = 0;
            PORTB = ~PORTB;
        }

    }

    }*/
}
