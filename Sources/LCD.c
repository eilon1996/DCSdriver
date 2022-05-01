/* - - - - - - - LCD interface - - - - - - - - -
 *	This code will interface to a standard LCD controller
 *  It uses it in 4 or 8 bit mode.
 */
//#include "msp430g2553.h"
#include "LCD.h"

//******************************************************************
// send a command to the LCD
//******************************************************************
void lcd_clear_output_data_pins(){
	setOutputData(lcd.d4, 0);
	setOutputData(lcd.d5, 0);
	setOutputData(lcd.d6, 0);
	setOutputData(lcd.d7, 0);
}
//******************************************************************
void lcd_set_output_data_pins(unsigned char c){
	setOutputData(lcd.d4, GET_BIT_VALUE(c, 0));
	setOutputData(lcd.d5, GET_BIT_VALUE(c, 1));
	setOutputData(lcd.d6, GET_BIT_VALUE(c, 2));
	setOutputData(lcd.d7, GET_BIT_VALUE(c, 3));
}

//******************************************************************
void lcd_write_output_data_pins(unsigned char c){
	lcd_clear_output_data_pins();
	lcd_set_output_data_pins(c);
	lcd_strobe();
}

void lcd_write_char_to_data_pins(unsigned char c){
	lcd_write_output_data_pins(((c >> 4) & 0x0F) << LCD_DATA_OFFSET);
	lcd_write_output_data_pins((c & (0x0F)) << LCD_DATA_OFFSET);
}

void lcd_cmd(unsigned char c){

	LCD_WAIT; // may check LCD busy flag, or just delay a little, depending on lcd.h

	if (LCD_MODE == FOURBIT_MODE)
	{
		lcd_write_char_to_data_pins(c);
	}
}
//******************************************************************
// send data to the LCD
//******************************************************************
void lcd_data(unsigned char c){

	LCD_WAIT; // may check LCD busy flag, or just delay a little, depending on lcd.h

	lcd_clear_output_data_pins(0xF);
	setOutputData(lcd.reset, 1);
	if (LCD_MODE == FOURBIT_MODE)
	{
		lcd_write_char_to_data_pins(c);
	}
	setOutputData(lcd.reset, 0);
}
//******************************************************************
// write a string of chars to the LCD
//******************************************************************
void lcd_puts(const char * s){

	while(*s)
		lcd_data(*s++);
}
//******************************************************************
// initialize the LCD
//******************************************************************
void lcd_init(){

	char init_value;

	if (LCD_MODE == FOURBIT_MODE) init_value = 0x3 << LCD_DATA_OFFSET;
	setOutputData(lcd.reset, OUTPUT);
	setOutputData(lcd.enable, OUTPUT);
	setOutputData(lcd.readWrite, OUTPUT);
	setOutputData(lcd.d4, OUTPUT);
	setOutputData(lcd.d5, OUTPUT);
	setOutputData(lcd.d6, OUTPUT);
	setOutputData(lcd.d7, OUTPUT);

	setOutputData(lcd.reset, 0);
	setOutputData(lcd.enable, 0);
	setOutputData(lcd.readWrite, 0);

	DelayMs(15);
	lcd_write_output_data_pins(init_value);
	DelayMs(5);
	lcd_write_output_data_pins(init_value);
	DelayUs(200);
	lcd_write_output_data_pins(init_value);
	lcd_strobe();

	if (LCD_MODE == FOURBIT_MODE){
		LCD_WAIT; // may check LCD busy flag, or just delay a little, depending on lcd.h

		lcd_write_output_data_pins(0x2 << LCD_DATA_OFFSET);// Set 4-bit mode
		lcd_cmd(0x28); // Function Set
	}

	lcd_cmd(0xF); //Display On, Cursor On, Cursor Blink
	lcd_cmd(0x1); //Display Clear
	lcd_cmd(0x6); //Entry Mode
	lcd_cmd(0x80); //Initialize DDRAM address to zero
}
//******************************************************************
// Delay usec functions
//******************************************************************
void DelayUs(unsigned int cnt){

	unsigned char i;
        for(i=cnt ; i>0 ; i--) asm("nop"); // tha command asm("nop") takes raphly 1usec

}
//******************************************************************
// Delay msec functions
//******************************************************************
void DelayMs(unsigned int cnt){

	unsigned char i;
    for(i=cnt ; i>0 ; i--) DelayUs(1000); // tha command asm("nop") takes raphly 1usec

}
//******************************************************************
// lcd strobe functions
//******************************************************************
void lcd_strobe(){

	setOutputData(lcd.enable, 1);
  	asm("nop");
  	asm("nop");
	setOutputData(lcd.enable, 0);
}
