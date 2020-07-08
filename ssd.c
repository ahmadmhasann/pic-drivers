/*
 * File:   ssd.c
 * Author: Hassan
 *
 * Created on July 6,  2020
 */


#define _XTAL_FREQ 8000000 
#include <xc.h>
#include "config.h"
#include "types.h"
#include "macros.h"
#include "dio.h"
#include "lcd.h"
#include "ssd.h"

u16 ssdNumber = 0;

void ssd_vid_2_digits_init(void) {
    dio_vid_set_port_direction(SSD_PORT, 0);
    dio_vid_set_pin_direction(SSD_ENABLE_1_PORT, SSD_ENABLE_1_PIN, 0);
    dio_vid_set_pin_direction(SSD_ENABLE_2_PORT, SSD_ENABLE_2_PIN, 0);
    ssd_vid_set_state(SSD_1, SSD_OFF);
    ssd_vid_set_state(SSD_2, SSD_OFF);
}

void ssd_vid_2_digits_update() {
    u8 ones = ssdNumber % 10;
    u8 tens = ssdNumber / 10;
    if (ssd_u8_get_state(SSD_2) == SSD_ON) {
        ssd_vid_set_state(SSD_2, SSD_OFF);
        ssd_vid_set_state(SSD_1, SSD_ON);
        ssd_vid_set_symbol(SSD_1, tens);
    } else {
        ssd_vid_set_state(SSD_1, SSD_OFF);
        ssd_vid_set_state(SSD_2, SSD_ON);
        ssd_vid_set_symbol(SSD_2, ones);
    }
}

u8 ssd_u8_get_symbol(u8 number) {
    u8 symbol;
    switch (number) {
        case 0:
            symbol = 0x3F;
            break;
        case 1:
            symbol = 0x06;
            break;
        case 2:
            symbol = 0x5B;
            break;
        case 3:
            symbol = 0x4F;
            break;
        case 4:
            symbol = 0x66;
            break;
        case 5:
            symbol = 0x6D;
            break;
        case 6:
            symbol = 0x7D;
            break;
        case 7:
            symbol = 0x07;
            break;
        case 8:
            symbol = 0x7F;
            break;
        case 9:
            symbol = 0x6F;
            break;
        default:
            symbol = 0;
    }
    return symbol;

}

void ssd_vid_set_symbol(u8 ssdNumber, u8 number) {
    u8 symbol = ssd_u8_get_symbol(number);
    ssd_vid_set_state(ssdNumber, SSD_ON);
    dio_vid_set_port_value(SSD_PORT, symbol);
}

u8 ssd_u8_get_state(u8 ssdNumber) {
    u8 state;
    switch (ssdNumber) {
        case SSD_1:
            state = dio_u8_read_pin_value(SSD_ENABLE_1_PORT, SSD_ENABLE_1_PIN);
            break;
        case SSD_2:
            state = dio_u8_read_pin_value(SSD_ENABLE_2_PORT, SSD_ENABLE_2_PIN);
            break;
        case SSD_3:
            state = dio_u8_read_pin_value(SSD_ENABLE_3_PORT, SSD_ENABLE_3_PIN);
            break;
        case SSD_4:
            state = dio_u8_read_pin_value(SSD_ENABLE_4_PORT, SSD_ENABLE_4_PIN);
            break;
        default:
            state = 0;
    }
    return state;
}

void ssd_vid_set_state(u8 ssdNumber, u8 state) {
    switch (ssdNumber) {
        case SSD_1:
            dio_vid_set_pin_value(SSD_ENABLE_1_PORT, SSD_ENABLE_1_PIN, state);
            break;
        case SSD_2:
            dio_vid_set_pin_value(SSD_ENABLE_2_PORT, SSD_ENABLE_2_PIN, state);
            break;
        case SSD_3:
            dio_vid_set_pin_value(SSD_ENABLE_3_PORT, SSD_ENABLE_3_PIN, state);
            break;
        case SSD_4:
            dio_vid_set_pin_value(SSD_ENABLE_4_PORT, SSD_ENABLE_4_PIN, state);
            break;
        default:
            break;
    }
}
