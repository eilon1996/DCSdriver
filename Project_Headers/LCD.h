
#ifndef _LCD_H_
#define _LCD_H_

#include "MKL25Z4_registers.h"
#include "connection_map.h"


#define LCD_WAIT DelayMs(5)


#define LCD_DATA_OFFSET 0x00 //data pin selection offset for 4 bit mode, variable range is 0-4, default 0 - Px.0-3, no offset



#define FOURBIT_MODE	0x0
#define EIGHTBIT_MODE	0x1
#define LCD_MODE        FOURBIT_MODE

#define OUTPUT_DATA     (LCD_MODE ? 0xFF : (0x0F << LCD_DATA_OFFSET))
#define INPUT_DATA      0x00


#define	lcd_cursor(x)			lcd_cmd(((x)&0x7F)|0x80)
#define lcd_clear()				lcd_cmd(0x01)
#define lcd_putchar(x)			lcd_data(x)
#define lcd_goto(x)				lcd_cmd(0x80+(x))
#define lcd_cursor_right()		lcd_cmd(0x14)
#define lcd_cursor_left()		lcd_cmd(0x10)
#define lcd_display_shift()		lcd_cmd(0x1C)
#define lcd_home()				lcd_cmd(0x02)
#define cursor_off              lcd_cmd(0x0C)
#define cursor_on               lcd_cmd(0x0F)
#define lcd_function_set        lcd_cmd(0x3C) // 8bit,two lines,5x10 dots
#define lcd_new_line            lcd_cmd(0xC0)

void lcd_write_lsb_output_data(unsigned char c);
void lcd_write_msb_output_data(unsigned char c);
extern void lcd_cmd(unsigned char);
extern void lcd_data(unsigned char);
extern void lcd_puts(const char * s);
extern void lcd_init();
extern void lcd_strobe();
extern void DelayMs(unsigned int);
extern void DelayUs(unsigned int);



#endif




