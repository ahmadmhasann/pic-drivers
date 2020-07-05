
#define _XTAL_FREQ 8000000 
#include <xc.h>
#include "types.h"
#include "macros.h"
#include "dio.h"


void timerInit(void) {    

    /*Enable timer 1 Interrupt*/
    TMR1IE = 1;
    
    /*Enable the Peripheral Interrupt*/
    PEIE = 1;
    
    /*Enable Global Interrupt*/
    GIE = 1;

    /*Enables Timer1*/
    TMR1ON = 1;

    
}

