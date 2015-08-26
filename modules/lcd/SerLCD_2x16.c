/***************************************************************************
* 
* File              : SerLCD_2x16.c
*
* Author			: Kurt E. Clothier
* Date				: June 28, 2011
* Modified			: February 24, 2013
*
* Description       : Control the Sparkfun 2x16 Serial Enabled LCD
*					: http://www.sparkfun.com/datasheets/LCD/SerLCD_V2_5.PDF
*					: See the extended description below for more information.
*					: Descriptions of each function are found in SerLCD_2x16.h.
*
* Compiler			: AVR-GCC
* Hardware			: Any AVR micro controller with USART port
*
* Associated Files	: SerLCD_2x16.c, SerLCD_commands.h, SerLCD_characters.h
*
* More Information	: www.projectsbykec.com
*
****************************************************************************/
/*	--- Extended Description and Motivation ---
	These files were created to allow for the quick and painless use of the 
	Sparkfun serial enabled 2x16 LCD screens. The user manual is somewhat 
	poorly written and left me a bit confused on a few aspects. This tutorial:
	http://www.arduino.cc/playground/Learning/SparkFunSerLCD is helpful if an 
	Arduino is being used; however, I prefer to use the microcontroller alone.
	
	For proper operation, a USART port of the AVR must have been set up somewhere 
	else (such as "main.c"). The names of the "data register empty" flag as well
	as its containing register need to be defined below along with the name of the
	USART data register to ensure proper operation. For example, to enable the
	USART0 of the ATmega328p using an external 18.432MHz crystal:
	
	// ... somewhere in main.c ...
		UCSR0A = 0x00;						// Standard USART Transmission Speed; Single Processor Mode
		UCSR0B = _BV(TXEN0);				// Enable Transmitter (No Receiver Needed)
		UCSR0C = _BV(UCSZ01)| _BV(UCSZ00);	// 8 Bit Asynchronous USART; No Parity; 1 Stop Bit
		UBRR0 = 119;						// Baud Rate = 9600 : UBRRn = (F_osc / (16*BAUD)) - 1
		
	The defined register values are then:
	
		#define	USART_control_reg		UCSR0A	// USART0 Control and Status Register A
		#define	USART_data_reg_empty	UDRE0	// USART0 Data Register Empty Flag
		#define	USART_data_register		UDR0	// USART0 Data Register
		
	Using a different microcontroller and/or clock frequency may result in different values.
	Any C source files using these functions should include the header file:	#include "SerLCD_2x16.h"
	Both SerLCD_2x16.c and SerLCD_2x16.h should be placed within the main project folder, and "SerLCD_2x16.c" should
	be added to the makefile so it will compile as well:
	
		# Target file name (without extension).
		TARGET = main
		# List C source files here. (C dependencies are automatically generated.)
		SRC = $(TARGET).c	SerLCD_2x16.c
*/
/**************************************************************************
	Included Header Files
***************************************************************************/

#include "SerLCD_2x16.h"


// USART Control and Data Register Names 
// For the "LCD_byte()" command, you need to make sure the UART data register is empty...
// These are for Atmel ATMEGAx8... will be different for different uC
#define	USART_control_reg		UCSR0A	// USART Control and Status Register
#define	USART_data_reg_empty	UDRE0	// USART Data Register Empty Flag
#define	USART_data_register		UDR0	// USART Data Register

/**************************************************************************
	Global Variables
***************************************************************************/

/****************************************************************************
	Global LCD Functions
****************************************************************************/
// Need to make this work for different MCUs...
void USART0_initialize(void)
{
  UCSR0A = 0x00;						// Standard USART Transmission Speed; Single Processor Mode
  UCSR0B = _BV(TXEN0);					// Enable Transmitter (PD1)
  UCSR0C = _BV(UCSZ01)| _BV(UCSZ00);	// 8 Bit Asynchronous USART; No Parity; 1 Stop Bit
  UBRR0 = 119;							// Baud Rate = 9600 {UBRRn = F_osc/(16*BAUD) - 1}
}

// Need to move this function to a serial.c file...
void SERIAL_transmitByte(const unsigned char data)
{
  while(!(USART_control_reg & _BV(USART_data_reg_empty)));	// Ensure the Data Register is Empty
  USART_data_register = data;								// Load Data Register
}

void LCD_string(const char *str, const unsigned char clear)
{
  if(clear){									// If display should be cleared
    LCD_byte(_LCD_COMMAND_B);						// Command Byte B
	LCD_byte(_LCD_CLEAR_DISPLAY);					// Clear Display
  }
  while(*str){									// While data remains
    LCD_byte(*str);									// transmit data, byte by byte
	str++;											// increment pointer					
  }
}

void LCD_stringPGM(const char *str, const unsigned char clear)
{
  if(clear){									// If display should be cleared
	LCD_byte(_LCD_COMMAND_B);						// Command Byte B
	LCD_byte(_LCD_CLEAR_DISPLAY);					// Clear Display
  }
  while(pgm_read_byte(str)){					// While data remains
    LCD_byte(pgm_read_byte(str));					// transmit data, byte by byte
	str++;											// increment pointer							
  }
}

static void LCD_printHex(const unsigned char data)
{
  if(data < 0x0A) SERIAL_transmitByte(data + 0x30);	// 0 - 9 = ASCII: 0x30 - 0x39
  else SERIAL_transmitByte(data + 0x37);			// A - F = ASCII: 0x41 - 0x46
}

void LCD_hex(const unsigned char hexData, const unsigned char prefix)
{
  if(prefix){							// Should we print "0x" ?
	LCD_stringPGM(PSTR("0x"), 0);		// Print "0x", do not clear screen
  }
  LCD_printHex(hexData >> 4);			// Print HI nibble
  LCD_printHex(hexData & 0x0F);			// Print LO nibble
}

void LCD_binary(unsigned char byte, const unsigned char prefix)
{
  unsigned char x = 8;
  if(prefix){								// Should we print "0x" ?
	LCD_stringPGM(PSTR("0b"), 0);			// Print "0x", do not clear screen
  }
  do{
    if(byte & 0x80) SERIAL_transmitByte(_ONE);	// Print "1" if MSB is HI
	else SERIAL_transmitByte(_ZERO);			// Print "0" if MSB is LO
	byte <<= 1;									// Left shift byte by 1 bit
  }while(--x);									// Loop through 8 bits
}

static unsigned int LCD_printDecimal(unsigned int value, const unsigned int compare)
{
  unsigned char digit = 0;
  if(value >= compare){
	do{
	  value -= compare;
	  digit++;
	}while(value >= compare);
	SERIAL_transmitByte(digit + 0x30);		// 0 - 9 = ASCII: 0x30 - 0x39
  }
  else SERIAL_transmitByte(_ZERO);			// 0 = ASCII: 0x30
  
  return value;
}

void LCD_decimal(unsigned int value)
{
  if(value > 9999){
	value = LCD_printDecimal(value, 10000);
	value = LCD_printDecimal(value, 1000);
	value = LCD_printDecimal(value, 100);
	value = LCD_printDecimal(value, 10);
  }
  else if(value > 999){
	value = LCD_printDecimal(value, 1000);
	value = LCD_printDecimal(value, 100);
	value = LCD_printDecimal(value, 10);
  }
  else if(value > 99){
    value = LCD_printDecimal(value, 100);
	value = LCD_printDecimal(value, 10);
  }
  else if(value > 9){
	value = LCD_printDecimal(value, 10);
  }
  SERIAL_transmitByte(value + 0x30);		// 0 - 9 = ASCII: 0x30 - 0x39
}

void LCD_brightness(unsigned char value)
{
  if(value > 29) value = 29;			// Ensure Proper Value
  LCD_byte(_LCD_COMMAND_A);					// Special Command A
  LCD_byte(value + _LCD_BACKLIGHT_OFF);		// backlight value
}

unsigned char LCD_setCursor(unsigned char line, unsigned char position)
{
  unsigned char good_value = 1;							// Value for return
  if((position > 0) && (position <= _LCD_NUM_POSITIONS)){	// Good Entry Values
	LCD_byte(_LCD_COMMAND_B);					// special Command B (254)
	switch (line) {								// Check line entry
	  case 1:									// line 1
		LCD_byte(_LCD_CUR_POS_LINE_1 + position);	// Set to 127 + position
		break;
	  case 2:									// line 2
		LCD_byte(_LCD_CUR_POS_LINE_2 + position);	// Set to 191 + position
		break;
	  default:									// Unknown line
		LCD_byte(_LCD_NULL_);						// Null Character
		good_value = 0;								// Return Bad value
	  break;
    }
  }
  else good_value = 0;							// Return Bad Value
  return(good_value);							// retrun value
}

void LCD_entryMode(unsigned char mode)
{
  LCD_byte(_LCD_COMMAND_B);
  switch (mode) {
    case 0x00:
	  LCD_byte(_LCD_DECREMENT_DISPLAY_SHIFT_OFF);
	  break;
	case 0x01:
	  LCD_byte(_LCD_DECREMENT_DISPLAY_SHIFT_ON);
	  break;
	case 0x10:
	  LCD_byte(_LCD_INCREMENT_DISPLAY_SHIFT_OFF);
	  break;
	case 0x11:
	  LCD_byte(_LCD_INCREMENT_DISPLAY_SHIFT_ON);
	  break;
	default:
	  LCD_byte(_LCD_INCREMENT_DISPLAY_SHIFT_OFF);
	  break;
  }
}

#ifdef _LCD_CONFIGURE_
unsigned char LCD_typeSetup(unsigned char lines, unsigned char characters)
{
  unsigned char good_value = 1;
  LCD_byte(_LCD_COMMAND_A);
  switch (characters) {
	case 16:
	  LCD_byte(_LCD_CHARACTERS_16);
      break;
	case 20:
	  LCD_byte(_LCD_CHARACTERS_20);
	  break;
	default:
	  LCD_byte(_LCD_NULL_);
	  good_value = 0;
	  break;
  }
  LCD_byte(_LCD_COMMAND_A);
  switch (lines) {
	case 2:
	  LCD_byte(_LCD_LINES_2);
      break;
	case 4:
	  LCD_byte(_LCD_LINES_4);
	  break;
	default:
	  LCD_byte(_LCD_NULL_);
	  good_value = 0;
	  break;
  }
  return(good_value);
}

void LCD_baudRate(unsigned char baud)
{
  LCD_byte(_LCD_COMMAND_A);
  switch (baud) {
    case 1:
	  LCD_byte(_LCD_BAUD_2400);
	  break;
	case 2:
	  LCD_byte(_LCD_BAUD_4800);
	  break;
    case 3:
	  LCD_byte(_LCD_BAUD_9600);
	  break;
	case 4:
	  LCD_byte(_LCD_BAUD_14400);
	  break;
    case 5:
	  LCD_byte(_LCD_BAUD_19200);
	  break;
	case 6:
	  LCD_byte(_LCD_BAUD_38400);
	  break;
	default:
	  LCD_byte(_LCD_BAUD_9600);
	  break;
  }
}

#endif /*_LCD_CONFIGURE_ */

