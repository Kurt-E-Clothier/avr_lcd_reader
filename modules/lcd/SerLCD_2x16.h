/***************************************************************************
* 
* File              : SerLCD_2x16.h
* Author			: Kurt E. Clothier
* Date				: June 28, 2011
* Modified			: February 24, 2013
*
* Description       : Header file for SerLCD_2x16.c
*					: Code: #include "SerLCD_2x16.h"
*					: See complete description in SerLCD_2x16.c
*
* Compiler			: AVR-GCC
* Hardware			: Any AVR micro controller with USART port
*
* Associated Files	: SerLCD_2x16.c, SerLCD_commands.h, SerLCD_characters.h
*
* More Information	: www.projectsbykec.com
*
****************************************************************************/

#ifndef _SerLCD_2x16_
#define _SerLCD_2x16_

#include <avr/io.h>					// MCU Register Names
#include <avr/pgmspace.h>			// Read/Write variables to flash program memory
#include "SerLCD_characters.h"		// Header file containing creatable characters
#include "SerLCD_commands.h"		// Header file containing command codes

/**************************************************************************
	Global Variables
***************************************************************************/

/**************************************************************************
	Global Function Prototypes
***************************************************************************/

/*** USART0_initialize ***
	Set up the USART0 for use with LCD screen.  							*/
void USART0_initialize(void);

/*** SERIAL_transmitByte ***
	Waits until the USART data register is empty and then loads the data
	register with the user defined 8 bit value. 							*/
void SERIAL_transmitByte(const unsigned char data);

/*** LCD_string ***
	Transmits a user defined string one byte at a time using LCD_byte.
	Although not enforced, the user must remember that there are only
	2 lines of data, 16 characters each. So each string should be no
	bigger than 32 characters including spaces. To clear the display
	before typing, pass 1 for 'clear', otherwise pass 0.					*/
void LCD_string(const char *str, const unsigned char clear);

/*** LCD_stringPGM ***
	This is the same as the previous LCD_string function, but uses a
	string stored in program memory instead of data memory. It should
	be called as: LCD_stringPGM(PSTR("Test String"), <clear>);				*/
void LCD_stringPGM(const char *str, const unsigned char clear);

/*** LCD_hex ***
	This function can be used to print hex values of 1 byte in size. 
	Passing a 1 for 'prefix' will print "0x" before the hex value.			*/
void LCD_hex(const unsigned char hexData, const unsigned char prefix);

/*** LCD_binary ***
	This function can be used to print binary values of 1 byte in size. It
	is more economical than converting the value to a string using sprintf.
	Passing a 1 for 'prefix' will print "0b" before the binary value.		*/
void LCD_binary(unsigned char byte, const unsigned char prefix);

/*** LCD_decimal ***
	This function can be used to print decimal values of 2 byte in size. It
	is more economical than converting the value to a string using sprintf.
	While this function can handle values up to 65535, it will only print 
	as many decimals places as necessary (no leading zeros).				*/
void LCD_decimal(unsigned int value);

/*** LCD_byte ***
	This is the SERIAL_transmitByte function in an alternate package.		*/
#define LCD_byte(DATA)	SERIAL_transmitByte(DATA)

/*** LCD_clear ***
	Removes all characters from the LCD screen and resets cursor position.	*/
#define LCD_clear()	do{ LCD_byte(_LCD_COMMAND_B); LCD_byte(_LCD_CLEAR_DISPLAY); }while(0)

/*** LCD_curHome ***
	Moves the cursor to the top-left character position.					*/
#define LCD_curHome() do{ LCD_byte(_LCD_COMMAND_B); LCD_byte(_LCD_CURSOR_HOME); }while(0)

/*** LCD_on ***
	Enables the Visual Display. This will also disable the cursor underline
	as well as the blinking block cursor.									*/
#define LCD_on() do{ LCD_byte(_LCD_COMMAND_B); LCD_byte(_LCD_DISPLAY_ON); }while(0)

/*** LCD_off ***
	Disables the Visual Display, but the backlight remains on.				*/
#define LCD_off() do{ LCD_byte(_LCD_COMMAND_B); LCD_byte(_LCD_DISPLAY_OFF); }while(0)

/*** LCD_cursorRight ***
	Moves the cursor right one space.										*/
#define LCD_cursorRight() do{ LCD_byte(_LCD_COMMAND_B); LCD_byte(_LCD_MOVE_CURSOR_RIGHT); }while(0)

/*** LCD_cursorLeft ***
	Moves the cursor left one space.										*/
#define LCD_cursorLeft() do{ LCD_byte(_LCD_COMMAND_B); LCD_byte(_LCD_MOVE_CURSOR_LEFT); }while(0)

/*** LCD_scrollRight ***
	Scrolls the entire display to the right.								*/
#define LCD_scrollRight() do{ LCD_byte(_LCD_COMMAND_B); LCD_byte(_LCD_SCROLL_RIGHT); }while(0)

/*** LCD_scrollLeft ***
	Scrolls the entire display to the left.									*/
#define LCD_scrollLeft() do{ LCD_byte(_LCD_COMMAND_B); LCD_byte(_LCD_SCROLL_LEFT); }while(0)

/*** LCD_underlineCurOn ***
	An underscore appears where the cursor currently is.					*/
#define LCD_underlineCurOn() do{ LCD_byte(_LCD_COMMAND_B); LCD_byte(_LCD_UNDERLINE_CUR_ON); }while(0)

/*** LCD_blinkingCurOn ***
	A blinking block appears where the cursor currently is.					*/
#define LCD_blinkingCurOn() do{ LCD_byte(_LCD_COMMAND_B); LCD_byte(_LCD_BLINKING_CUR_ON); }while(0)

/*** LCD_cursorOff ***
	Disables the cursor underline or blinking block.						*/
#define LCD_cursorOff() LCD_on()

/*** LCD_brightness ***
	Manual conroll of backlight brightness: 0 = Off; 29 = Full On			*/
void LCD_brightness(unsigned char value);

/*** LCD_setCursor ***
	Moves the cusor to the user defined position and line by calculating
	the appropriate position value according to the manual. The line value
	should be 1-2, position should be 1-16. Returns 0 if a bad value is 
	given. As stated in the user manual from Sparkfun:
	"A cursor move to outside the viewable area is possible and the cursor 
	position variable will be updated accurately." Available positions:
				Line 1: [ 1 2 3 ... 14 15 16 ]
				Line 2: [ 1 2 3 ... 14 15 16 ]								*/
unsigned char LCD_setCursor(unsigned char line, unsigned char position);

/*** LCD_entryMode ***
	This function allows the user to change the direction characters are
	displayed on the screen. There are four possible modes described as:
		0x00: Decrement the Address Counter; Display Shift is Off
		0x01: Decrement the Address Counter; Display Shift is On
		0x10: Increment the Address Counter; Display Shift is Off
		0x11: Increment the Address Counter; Display Shift is On
	If the address counter is decremented, a string will be displayed in 
	reverse. For example: "Hello" will be printed as "olleH" starting
	with the "H" and ending with the "o." 
	If the Display Shift is on, then the entire display will shift when
	a new character is entered: to the right for a decrementing counter 
	and to the left for an incrementing counter.
	Examples: starting at position 7, cursor underline on, string = "Hello"
	Position: [ 0 1 2 3 4 5 6 7 8 9 A B C D E F ]
		0x00: [     _ o l l e H                 ]
		0x01: [               _ o l l e H       ]	<< (Scrolls Entire Screen Right)
		0x10: [               H e l l 0 _       ]	<< This is the default
		0x11: [     H e l l o _                 ]   << Right Allignment (Scrolls Entire Screen Left)
	*/
void LCD_entryMode(unsigned char mode);

/*** LCD_initialize ***
	Turns the LCD screen on (LCD_on) and clears it (LCD_clear).				*/
#define LCD_initialize() do{ LCD_clear(); LCD_on(); LCD_entryMode(0x10); }while(0)

/****************** Retained Settings ***************************************
	The following functions can be used to change the default settings of
	the LCD. These settings are saved to EEPROM and will be retained until
	they are modified again. Also, using these function has been known to 
	stop the the LCD from working properly without a power cycle. Thus, the
	use of these functions should be limited to an initial set up of the 
	LCD. They should not be a part of the final source code unless the AVR
	has control over the LCD power supply and is able to cycle the power.
	For use, uncomment <#define _LCD_CONFIGURE_ 1>.
****************************************************************************/

// Uncomment to use LCD configuration functions
//#define _LCD_CONFIGURE_	1

#ifdef _LCD_CONFIGURE_

/*** LCD_numCharacters ***
	The SerLCD can interface to 2x16, 2x20, 4x16, and 4x20 character LCDs. 
	This function should not be used if the purchased unit is already 
	connected to an LCD as the firmware should already be programmed with 
	the correct values. Returns 0 if a bad value is given.					*/
unsigned char LCD_typeSetup(unsigned char lines, unsigned char characters);

/*** LCD_toggleSplash ***
	Calling this function will either enable or disable the 500ms splash 
	screen at boot up. To test, cycle the power.							*/

#define LCD_toggleSplash() do{ LCD_byte(_LCD_COMMAND_A); LCD_byte(_LCD_TOGGLE_SPLASH_SCREEN); }while(0)

/*** LCD_updateSplash ***
	To save a custom splash screen (2 lines max), set up the top 2 lines of
	of the display as the splash screen should appear and call this.		*/
#define LCD_updateSplash() do{ LCD_byte(_LCD_COMMAND_A); LCD_byte(_LCD_UPDATE_SPLASH_SCREEN); }while(0)

/*** LCD_baudRate ***
	The default baud rate is 9600bps, but this value can be changed. The
	following values for the baud rate are accepted:
			baud rate	|	"baud"		baud rate	|	"baud"
			---------------------		---------------------
				2400	|	1				114400	|	4
				4800	|	2				19200	|	5
				9600	|	3				38400	|	6	
	From the user manual:
	"If the Serial LCD gets into an unknown state, or you otherwise can't
	communicate with it at the baud rate to which it is set, enter 
	"<control>r" at 9600 baud while the splash screen is active and the 
	unit will reset to 9600 baud. 											*/
void LCD_baudRate(unsigned char baud);

#endif	//_LCD_CONFIGURE_

#endif	// _SerLCD_2x16_

