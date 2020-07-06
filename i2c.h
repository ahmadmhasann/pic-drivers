

/* 
 * File: i2c.h
 * Author: Ahmed Hassan
 * Created : July 7, 2020 
 */


#ifndef I2C_H
#define	I2C_H

unsigned short I2C_Read(unsigned short ack);
void I2C_Write(unsigned data);
void I2C_End();
void I2C_Begin();
void i2c_vid_wait (void);
void i2c_vid_init_master (u16 feq_k);


#endif

