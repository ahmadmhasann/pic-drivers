


/* 
 * File: i2c.c
 * Author: Ahmed Hassan
 * Created : July 7, 2020 
 */
#define _XTAL_FREQ 8000000 
#include <xc.h>
#include "macros.h"
#include "types.h"
#include "dio.h"

void i2c_vid_init_master (u16 feq_k) {
    dio_vid_set_pin_direction(C, 3, PIN_INPUT);
    dio_vid_set_pin_direction(C, 4, PIN_INPUT);
    /*No collision*/
    WCOL = 0;
    
    /*No overflow*/
    SSPOV = 0;
    
    /*Enables the serial port and configures the SDA and SCL pins as the serial port pins*/
    SSPEN = 1;
    
    /*I2C Master mode, clock = FOSC/(4 * (SSPADD + 1))*/
    SSPM3 = 1;
    SSPM2 = 0;
    SSPM1 = 0;
    SSPM0 = 0;
    SSPCON2 = 0x00;
    
    /*clock select*/
    SSPADD = (_XTAL_FREQ/(4*feq_k*100))-1;
    
    SSPSTAT = 0x00;
    
}

void i2c_vid_wait (void) {
    /*waits until any operation completes*/
    while ( (SSPSTAT & 0b00000100) || (SSPCON2 & 0b00011111));
}


void I2C_Begin()
{
  i2c_vid_wait();  //Hold the program is I2C is busy 
  SEN = 1;     //Begin IIC pg85/234
}
void I2C_End()
{
  i2c_vid_wait(); //Hold the program is I2C is busy 
  PEN = 1;    //End IIC pg85/234
}
void I2C_Write(unsigned data)
{
  i2c_vid_wait(); //Hold the program is I2C is busy
  SSPBUF = data;         //pg82/234
}

unsigned short I2C_Read(unsigned short ack)
{
  unsigned short incoming;
  i2c_vid_wait();
  RCEN = 1;

  i2c_vid_wait();
  incoming = SSPBUF;      //get the data saved in SSPBUF

  i2c_vid_wait();
  ACKDT = (ack)?0:1;    //check if ack bit received 
  ACKEN = 1;          //pg 85/234

  return incoming;
}




