/*
 * File:   main.c
 * Author: Hassan
 *
 * Created on July 4, 2020
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
volatile u8 buttonPressedFlag = 0;



void checkButtons() {
    if (dio_u8_read_pin_value(B, 3) == 0 && buttonPressedFlag == 0) {
        buttonPressedFlag = 1;
        if (ssdNumber + 5 < 80) {
            eeprom_external_vid_write(0, ssdNumber + 5);
            ssdNumber += 5;
        }
    } else if (dio_u8_read_pin_value(B, 4) == 0 && buttonPressedFlag == 0) {
        buttonPressedFlag = 1;
        if (ssdNumber - 5 > 30) {
            eeprom_external_vid_write(0, ssdNumber - 5);
            ssdNumber -= 5;
        }
    }
    if (dio_u8_read_pin_value(B, 3) && dio_u8_read_pin_value(B, 4)) {
        buttonPressedFlag = 0;
    }
}

int main(void) {
    ssd_vid_2_digits_init();
    i2c_vid_master_init();
    dio_vid_set_port_direction(B, 255);
    ssdNumber = eeprom_external_vid_read(0);
    if (ssdNumber < 35 || ssdNumber > 75 || ssdNumber % 5 != 0)
        ssdNumber = 60;
    sch_vid_init();
    sch_u8_add_task(checkButtons, 1, 1);
    sch_u8_add_task(ssd_vid_2_digits_update, 5, 5);

    while (1) {
        sch_vid_dispatch_tasks();
    }


}
