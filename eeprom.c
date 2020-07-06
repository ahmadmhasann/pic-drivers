/*
 * File:   eeprom.c
 * Author: Hassan
 *
 * Created on July 7, 2020
 */
#include <xc.h>
#include "types.h"
void eeprom_vid_write(u8 address, u8 data)
{
   unsigned char gie_Status;
    
    while(WR);            // check the WR bit to see if a previous Write operation is in progress
    EEADR=address;  // Write the address to EEADR.
    EEDATA=data;    // load the 8-bit data value to be written in the EEDATA register.
    WREN=1;               // Set the WREN bit to enable eeprom operation.
    gie_Status = GIE;     // Copy the current Interrupt state
    GIE = 0;              // Disable the interrupts
    EECON2=0x55;          // Execute the special instruction sequence
    EECON2=0xaa;          // Refer the datasheet for more info
    WR=1;                 // Set the WR bit to trigger the eeprom write operation.
    GIE = gie_Status;     // Restore the interrupts
    WREN=0;               // Disable the EepromWrite
    
}


u8 eeprom_u8_read (u8 address)
{
    while(RD || WR);           // check the WR&RD bit to see if a RD/WR is in progress
    EEADR=address;       // Write the address to EEADR.
    RD = 1;                    // Set the RD bit to trigger the eeprom read operation.
    return(EEDATA);            // Return the data read form eeprom.
    
}
