/***************************************************************************
* 
* File              : SerLCD_commands.h
*
* Author			: Kurt E. Clothier
* Date				: February 24, 2013
* Modified			: February 24, 2013
*
* Description       : Commands for controlling the Sparkfun 2x16 Serial Enabled LCD
*					: http://www.sparkfun.com/datasheets/LCD/SerLCD_V2_5.PDF
*					: See the extended description below for more information.
*					: Descriptions of each function are found in SerLCD_2x16.h.
*
* Compiler			: AVR-GCC
* Hardware			: Any AVR micro controller with USART port
*
* Associated Files	: SerLCD_2x16.h, SerLCD-2x16.c, SerLCD_characters.h
*
* More Information	: www.projectsbykec.com
*
****************************************************************************/

// Uncomment to use LCD configuration functions
//#define _LCD_CONFIGURE_	1

// SerLCD Special Commands
#define _LCD_COMMAND_A				0x7C	// Decimal: 124
#define _LCD_COMMAND_B				0xFE	// Decimal: 254

// SerLCD Command Characters
#define _LCD_CLEAR_DISPLAY			0x01
#define _LCD_CURSOR_HOME			0x02
#define _LCD_MOVE_CURSOR_RIGHT		0x14
#define _LCD_MOVE_CURSOR_LEFT		0x10
#define _LCD_SCROLL_RIGHT			0x1C
#define _LCD_SCROLL_LEFT			0x18
#define _LCD_DISPLAY_ON				0x0C
#define _LCD_DISPLAY_OFF			0x08
#define _LCD_UNDERLINE_CUR_ON		0x0E
#define _LCD_UNDERLINE_CUR_OFF		0x0C
#define _LCD_BLINKING_CUR_ON		0x0D
#define _LCD_BLINKING_CUR_OFF		0x0C
#define _LCD_TOGGLE_SPLASH_SCREEN	0x09

#define _LCD_BACKLIGHT_OFF			128
#define _LCD_BACKLIGHT_FULL			157
#define _LCD_CUR_POS_LINE_1			127		// 128 = first position, first line
#define _LCD_CUR_POS_LINE_2			191		// 192 = First position, second line
#define _LCD_CHARACTERS_20			0x03
#define _LCD_CHARACTERS_16			0x04
#define _LCD_LINES_2				0x05
#define _LCD_LINES_4				0x06
#define _LCD_NULL_					0x00
#define _LCD_UPDATE_SPLASH_SCREEN	0x6A	// "j"
#define _LCD_BAUD_2400				0x6B	// "k"
#define _LCD_BAUD_4800				0x6C	// "l"
#define _LCD_BAUD_9600				0x6D	// "m"
#define _LCD_BAUD_14400				0x6E	// "n"
#define _LCD_BAUD_19200				0x6F	// "o"
#define _LCD_BAUD_38400				0x70	// "p"
#define _LCD_BAUD_RESET				0x72	// "r"

//Entry Mode Set Commands
#define _LCD_DECREMENT_DISPLAY_SHIFT_OFF	0x04
#define _LCD_DECREMENT_DISPLAY_SHIFT_ON		0x05
#define _LCD_INCREMENT_DISPLAY_SHIFT_OFF	0x06
#define _LCD_INCREMENT_DISPLAY_SHIFT_ON		0x07

// SerLCD Configurations
#define	_LCD_NUM_LINES				2
#define	_LCD_NUM_POSITIONS			16


