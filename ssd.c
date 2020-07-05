/*
 * File:   ssd.c
 * Author: Hassan
 *
 * Created on 01 ?????, 2020, 03:44 ?
 */


#define _XTAL_FREQ 8000000 
#include <xc.h>
#include "config.h"
#include "types.h"
#include "macros.h"
#include "dio.h"
#include "lcd.h"

#define SEVEN_SEGMENT_PORT D
#define ENABLE_1_PORT A
#define ENABLE_2_PORT A
#define ENABLE_3_PORT A
#define ENABLE_4_PORT A
#define ENABLE_1_PIN 2
#define ENABLE_2_PIN 3
#define ENABLE_3_PIN 4
#define ENABLE_4_PIN 5

u8 ssd_get_number(u8 number) {
    switch (number) {
        case 0:
            return 0x3F;
        case 1:
            return 0x06;
        case 2:
            return 0x5B;
        case 3:
            return 0x4F;
        case 4:
            return 0x66;
        case 5:
            return 0x6D;
        case 6:
            return 0x7D;
        case 7:
            return 0x07;
        case 8:
            return 0x7F;
        case 9:
            return 0x6F;
        case 10:
            return 0x77;
        case 11:
            return 0x7c;
        case 12:
            return 0x58;
        case 13:
            return 0x5E;
        case 14:
            return 0x79;
        case 15:
            return 0x71;
        default:
            return 0;
    }
}

void ssd_init(void) {
    dio_vid_set_port_direction(SEVEN_SEGMENT_PORT, 0);
    dio_vid_set_pin_direction(ENABLE_1_PORT, ENABLE_1_PIN, 0);
    dio_vid_set_pin_direction(ENABLE_2_PORT, ENABLE_2_PIN, 0);
}

void ssd_set_state (u8 state) {
    u8 ones = state % 10;
    u8 tens = state / 10;
        while (1) {
        dio_vid_set_port_value(SEVEN_SEGMENT_PORT, ssd_get_number(ones));
        dio_vid_set_pin_value(ENABLE_1_PORT, ENABLE_1_PIN, 0);
        __delay_ms(1);
        dio_vid_set_pin_value(ENABLE_1_PORT, ENABLE_1_PIN, 1);
        dio_vid_set_port_value(D, ssd_get_number(tens));
        dio_vid_set_pin_value(ENABLE_2_PORT, ENABLE_2_PIN, 0);
        __delay_ms(1);
        dio_vid_set_pin_value(ENABLE_2_PORT, ENABLE_2_PIN, 1);
    }
}