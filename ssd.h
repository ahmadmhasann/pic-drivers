/*
 * File:   ssd.h
 * Author: Hassan
 *
 * Created on July 6,  2020
 */

#ifndef SSD_H_
#define	SSD_H_

#define SSD_PORT D

#define SSD_ENABLE_1_PORT A
#define SSD_ENABLE_2_PORT A
#define SSD_ENABLE_3_PORT A
#define SSD_ENABLE_4_PORT A

#define SSD_ENABLE_1_PIN 2
#define SSD_ENABLE_2_PIN 3
#define SSD_ENABLE_3_PIN 4
#define SSD_ENABLE_4_PIN 5

#define SSD_1 1
#define SSD_2 2
#define SSD_3 3
#define SSD_4 4
#define SSD_OFF 0
#define SSD_ON 1

extern u16 ssdNumber;

void ssd_vid_2_digits_init(void);
void ssd_vid_2_digits_update();
u8 ssd_u8_get_symbol(u8 number);
void ssd_vid_set_symbol(u8 ssdNumber, u8 symbol);
u8 ssd_u8_get_state(u8 ssdNumber);
void ssd_vid_set_state(u8 ssdNumber, u8 state);



#endif	

