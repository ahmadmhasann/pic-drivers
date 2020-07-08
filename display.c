/*
 * File:   display.c
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
#include "counter.h"

#define HEATER_ON_PIN 3
#define COOLER_ON_PIN 4
#define DEVICE_STATE_PIN 5
u8 displayFlag = 0xff;

void display_init(void) {
    dio_vid_set_port_value(B, LOW_PORT);
    ssd_vid_init();
    dio_vid_set_pin_direction(B, HEATER_ON_PIN, OUTPUT_PIN);
    dio_vid_set_pin_direction(B, COOLER_ON_PIN, OUTPUT_PIN);
    dio_vid_set_pin_direction(B, DEVICE_STATE_PIN, OUTPUT_PIN);
    dio_vid_set_pin_value(B, DEVICE_STATE_PIN, HIGH_PIN);
}

void display_vid_blink(void) {
    /*Exit setting mode if 5 seconds passed without changing*/
    if (settingModeSecondsCounter > 5 && settingModeFlag == 1) {
        settingModeFlag = 0;
        settingModeSecondsCounter = 0;
    }
    /*Increment the counter and blink every second*/
    else if (settingModeFlag) {
        settingModeSecondsCounter++;
        if (ssd_u8_get_state() == SSD_ON)
            ssd_vid_set_state(SSD_OFF);
        else {
                        ssd_vid_set_state(SSD_ON);

        }
    }
    else {
        ssd_vid_set_state(SSD_ON);
    }
}

void display_update(void) {
    if (settingModeSecondsCounter == 2500 && settingModeFlag == 1) {
        settingModeFlag = 0;
        settingModeSecondsCounter = 0;
    }
    settingModeSecondsCounter++;

    if (settingModeSecondsCounter % 500 == 0)
        displayFlag = ~displayFlag;
}