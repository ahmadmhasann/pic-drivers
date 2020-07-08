/*
 * File:   counter.c
 * Author: Ahmed Hassan
 *
 * Created on July 8,  2020
 */


#define _XTAL_FREQ 8000000 
#include <xc.h>
#include "config.h"
#include "types.h"
#include "macros.h"
#include "dio.h"
#include "ssd.h"
#include "eeprom_external.h"

#define UP_BUTTON 2
#define DOWN_BUTTON 1

u8 buttonPressedFlag = 0;
u8 settingModeFlag = 0;
u16 settingModeSecondsCounter = 0;
u8 counter = 60;

void counter_vid_init(void) {

    dio_vid_set_pin_direction(B, UP_BUTTON, INPUT_PIN);
    dio_vid_set_pin_direction(B, DOWN_BUTTON, INPUT_PIN);
    counter = eeprom_external_vid_read(0);
    if (counter < 35 || counter > 75 || counter % 5 != 0)
        counter = 60;
    ssd_vid_set_state(SSD_ON);
    ssd_vid_set_symbol(counter);

}

void counter_vid_update(void) {
    if (dio_u8_read_pin_value(B, UP_BUTTON) == 0 && buttonPressedFlag == 0) {
        settingModeFlag = 1;
        settingModeSecondsCounter = 0;
        buttonPressedFlag = 1;
        if (counter + 5 < 80) {
            eeprom_external_vid_write(0, counter + 5);
            counter += 5;
            ssd_vid_set_symbol(counter);
        }
    } else if (dio_u8_read_pin_value(B, DOWN_BUTTON) == 0 && buttonPressedFlag == 0) {
        settingModeFlag = 1;
        settingModeSecondsCounter = 0;
        buttonPressedFlag = 1;
        if (counter - 5 > 30) {
            eeprom_external_vid_write(0, counter - 5);
            counter -= 5;
            ssd_vid_set_symbol(counter);
        }
    }
    if (dio_u8_read_pin_value(B, UP_BUTTON) && dio_u8_read_pin_value(B, DOWN_BUTTON))
        buttonPressedFlag = 0;

}
