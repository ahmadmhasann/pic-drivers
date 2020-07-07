/*
 * File:   main.c
 * Author: Hassan
 *
 * Created on 29 ?????, 2020, 01:07 ?
 */
#define _XTAL_FREQ 8000000 
#include <xc.h>
#include<pic16f877a.h>

#include "config.h"
#include "types.h"
#include "macros.h"
#include "dio.h"
#include "lcd.h"
#include "ssd.h"
#include "scheduler.h"
#include "timer.h"
#include "i2c.h"
#include "eeprom.h"
#include "eeprom_external.h"
u16 counter = 0;
volatile u8 setTemperature;
volatile u8 buttonPressedFlag = 0;

void test(void) {
    counter++;
    if (counter == 500) {
        counter = 0;
        PORTB = ~PORTB;
    }
}

void toggleB(void) {
    PORTB = ~PORTB;
}

void showNumber25(void) {
    ssd_set_state(setTemperature);
}

void checkButtons() {
    if (dio_u8_read_pin_value(B, 3) == 0 && buttonPressedFlag == 0) {
        buttonPressedFlag = 1;
        if (setTemperature + 5 < 80) {
            eeprom_external_vid_write(0, setTemperature + 5);
            setTemperature += 5;
        }
    } else if (dio_u8_read_pin_value(B, 4) == 0 && buttonPressedFlag == 0) {
        buttonPressedFlag = 1;
        if (setTemperature - 5 > 30) {
            eeprom_external_vid_write(0, setTemperature - 5);
            setTemperature -= 5;
        }
    }
    if (dio_u8_read_pin_value(B, 3) && dio_u8_read_pin_value(B, 4)) {
        buttonPressedFlag = 0;
    }
}

int main(void) {
    ssd_init();
    i2c_vid_master_init();
    dio_vid_set_port_direction(B, 255);
    setTemperature = eeprom_external_vid_read(0);
    if (setTemperature < 35 || setTemperature > 75 || setTemperature % 5 != 0)
        setTemperature = 60;
    sch_vid_init();
    sch_u8_add_task(checkButtons, 1, 1);
    sch_u8_add_task(showNumber25, 10, 10);



    while (1) {
        sch_vid_dispatch_tasks();
    }


}
