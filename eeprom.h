/*
 * File:   eeprom.h
 * Author: Hassan
 *
 * Created on July 7, 2020
 */

#ifndef EEPROM_H
#define	EEPROM_H

void eeprom_vid_write(u8 address, u8 data);
u8 eeprom_u8_read (u8 address);


#endif	

