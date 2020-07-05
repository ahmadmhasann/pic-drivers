/*
 * LCD.c
 *
 *  Created on: Aug 23, 2019
 *      Author: Ahmed Hassan
 */
#define _XTAL_FREQ 8000000 
#include <xc.h>
#include "types.h"
#include "lcd_cfg.h"
#include "lcd.h"
#include "dio.h"
#define L_ON	0x0F
#define L_OFF	0x08
#define L_CLR	0x01
#define L_L1	0x80
#define L_L2	0xC0
#define L_CR	0x0F		
#define L_NCR	0x0C	

#define L_CFG   0x38


void lcd_vid_write_charachter (u8 data) {
#ifdef LCD_8bit
    	dio_vid_set_pin_value(LCD_ControlPort, LCD_E, 1);
	dio_vid_set_port_value(LCD_DataPort, data);

	dio_vid_set_pin_value(LCD_ControlPort, RS, 1);
    	__delay_ms(3);

	//dio_vid_set_pin_value(LCD_ControlPort, RW, 0);
	dio_vid_set_pin_value(LCD_ControlPort, LCD_E, 0);
	__delay_ms(3);
	dio_vid_set_pin_value(LCD_ControlPort, LCD_E, 1);
	__delay_ms(1);
#else
	u8 data1 = (data>>4)<<4;
	u8 data2 = data<<4;
	dio_vid_set_pin_value(LCD_ControlPort, RS, 1);
	//dio_vid_set_pin_value(LCD_ControlPort, RW, 0);
	dio_vid_set_port_value(LCD_DataPort, data1);
	dio_vid_set_pin_value(LCD_ControlPort, LCD_E, 1);
	__delay_ms(1);
	dio_vid_set_pin_value(LCD_ControlPort, LCD_E, 0);
	__delay_ms(1);
	dio_vid_set_port_value(LCD_DataPort, data2);
	dio_vid_set_pin_value(LCD_ControlPort, LCD_E, 1);
	__delay_ms(1);
	dio_vid_set_pin_value(LCD_ControlPort, LCD_E, 0);
	__delay_ms(1);
#endif
}

void lcd_vid_write_command (u8 command) {

#ifdef LCD_8bit
    	dio_vid_set_pin_value(LCD_ControlPort, LCD_E, 1);
	dio_vid_set_port_value(LCD_DataPort, command);

	dio_vid_set_pin_value(LCD_ControlPort, RS, 0);
	//dio_vid_set_pin_value(LCD_ControlPort, RW, 0);
	__delay_ms(3);
	dio_vid_set_pin_value(LCD_ControlPort, LCD_E, 0);
    
	__delay_ms(3);
        	dio_vid_set_pin_value(LCD_ControlPort, LCD_E, 1);

#else
	u8 command1 = (command>>4)<<4;
	u8 command2 = command<<4;
	dio_vid_set_pin_value(LCD_ControlPort, RS, 0);
	//dio_vid_set_pin_value(LCD_ControlPort, RW, 0);
	dio_vid_set_port_value(LCD_DataPort, command1);
	dio_vid_set_pin_value(LCD_ControlPort, LCD_E, 1);
	__delay_ms(1);
	dio_vid_set_pin_value(LCD_ControlPort, LCD_E, 0);
	__delay_ms(1);
	dio_vid_set_port_value(LCD_DataPort, command2);
	dio_vid_set_pin_value(LCD_ControlPort, LCD_E, 1);
	__delay_ms(1);
	dio_vid_set_pin_value(LCD_ControlPort, LCD_E, 0);
	__delay_ms(1);
#endif
}


void lcd_vid_init(void) {
    dio_vid_set_pin_direction(LCD_ControlPort,RS,OUTPUT);
    dio_vid_set_pin_direction(LCD_ControlPort,LCD_E,OUTPUT);
    dio_vid_set_pin_value(LCD_ControlPort,LCD_E, LOW);
    __delay_ms(20);
        dio_vid_set_pin_value(LCD_ControlPort,LCD_E, HIGH);
        
	lcd_vid_write_command(L_CFG); //configura
	lcd_vid_write_command(L_OFF);
	lcd_vid_write_command(L_ON); //liga
	lcd_vid_write_command(L_CLR); //limpa
	lcd_vid_write_command(L_CFG); //configura
        lcd_vid_write_command(L_L1);
        
    

}

void lcd_vid_write_string(u8 str[]) {
	u8 i=0;
	while (str[i]!=0) {
		lcd_vid_write_charachter(str[i]);
		i++;
	}
}

void lcd_vid_write_number(s32 number) {
	if (number == 0) {
		lcd_vid_write_charachter('0');
		return;
	}
	else if (number<0) {
		lcd_vid_write_charachter('-');
		number*=-1;

	}
	u32 reservedNumber=1;
	while (number != 0) {
		reservedNumber = (reservedNumber*10) + (number%10);
		number/=10;
	}
	while (reservedNumber!=1) {
		lcd_vid_write_charachter((reservedNumber%10)+'0');
		reservedNumber/=10;
	}
}





void lcd_vid_set_position(u8 row, u8 col) {
	lcd_vid_write_command(128+col+row*64);
}


void lcd_vid_clear_screan (void) {
	lcd_vid_write_command(1);
}





