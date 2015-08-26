/***************************************************************************
* 
* File              : definitions.h
*
* Author			: Kurt E. Clothier
* Date				: July 7, 2015
* Modified			: July 10, 2015
*
* Description       : Header file for lcdReader-vxx.c
*
* Compiler			: AVR-GCC
* Hardware			: ATMEGA328p
* Fuse Settings		: Default
*
* More Information	: http://www.projectsbykec.com/
*
****************************************************************************/

/***************************************************************************
	Constants & Status Flags
****************************************************************************/
// stat_flag
#define READ_LCD		0x80
#define DATA_READY		0x40
#define DELAY_MS		0x01

#define TIME_PRESS		50		// ms to "press" a scale button
#define TIME_RELEASE	25		// ms to pause between presses

#define TIME_COM_PULSE	20	// Time (X * 0.2ms) per 1/2 pulse cycle
#define TIME_READ_LCD	7	// Read LCD roughly (X * 0.2ms) after positive pulse edge


/***************************************************************************
	Hardware Definitions and Associated Macros
****************************************************************************/
// Open (ADC Available)
//#define	_BV(PC0)
//#define	_BV(PC1)
//#define	_BV(PC2)
//#define	_BV(PC3)

// LCD Lines
#define LCDP7	_BV(PB7)	// Digit 3
#define LCDP8	_BV(PB6)	
#define LCDP9	_BV(PB5)	// Digit 2
#define LCDP10	_BV(PB4)
#define LCDP11	_BV(PB3)	// Digit 1
#define LCDP12	_BV(PB2)
#define LCDP13	_BV(PB1)	// Digit 0
#define LCDP14	_BV(PB0)

#define LCDP15	_BV(PD5)	// Mode / Unit
#define LCDP16	_BV(PD4)

#define LCD1		_BV(PD6)
#define _AIN0		_BV(PD6)	// Analog Comparator Input = LCD COM 1
#define _AIN1		_BV(PD7)	// Analog Comparator Input = ~2.2V

// LCD Pin Input Masks
#define	LCD_DIGIT_PINS	(~PINB)
#define	LCD_MODE_PINS	(~PIND & (LCDP15 | LCDP16))

// Other Scale connections
#define BUT_UNIT	_BV(PD0)	// Unit Button on Scale
#define BUT_ZERO	_BV(PD1)	// Zero Button on Scale
#define SCALE_PWR	_BV(PD2)	// Scale Power Line Control

#define DISABLE_SCALE()	PORTD &= ~SCALE_PWR;
#define ENABLE_SCALE()	PORTD |= SCALE_PWR;

#define PUSH_UNIT_BUTTON()	do{DDRD |= BUT_UNIT; _delay_ms(TIME_PRESS); \
						       DDRD &= ~BUT_UNIT; _delay_ms(TIME_RELEASE);}while(0)
#define PUSH_ZERO_BUTTON()	do{DDRD |= BUT_ZERO; _delay_ms(TIME_PRESS); \
		                       DDRD &= ~BUT_ZERO; _delay_ms(TIME_RELEASE);}while(0)

#define HOLD_ZERO_BUTTON()		DDRD |= BUT_ZERO
#define RELEASE_ZERO_BUTTON()	DDRD &= ~BUT_ZERO

#define KEEP_SCALE_AWAKE()	PUSH_UNIT_BUTTON(); PUSH_UNIT_BUTTON()

/***************************************************************************
	LCD Data Storage Mapping
****************************************************************************/
#define	COM1	0
#define COM2	1
#define COM3	2
#define COM4	3
#define COMS	4

#define LCD_DIGITS	0
#define LCD_MODE	1

// Pin 5
//#define MODE_N
//#define MODE_Z
//#define MODE_AM
//#define MODE_PM

// Pin 6
//#define DIG_4C
//#define DIG_4B
//#define DIG_4	

// Pin 7
#define DIG_31		LCDP7
#define DIG_3D		(lcdPins[COM1][LCD_DIGITS] & DIG_31)
#define DIG_3E		(lcdPins[COM2][LCD_DIGITS] & DIG_31)
#define DIG_3G		(lcdPins[COM3][LCD_DIGITS] & DIG_31)
#define DIG_3F		(lcdPins[COM4][LCD_DIGITS] & DIG_31)

// Pin 8
#define DIG_32		LCDP8
#define DIG_3DP		(lcdPins[COM1][LCD_DIGITS] & DIG_32)
#define DIG_3C		(lcdPins[COM2][LCD_DIGITS] & DIG_32)
#define DIG_3B		(lcdPins[COM3][LCD_DIGITS] & DIG_32)
#define DIG_3A		(lcdPins[COM4][LCD_DIGITS] & DIG_32)

// Pin 9
#define DIG_21		LCDP9
#define DIG_2D		(lcdPins[COM1][LCD_DIGITS] & DIG_21)
#define DIG_2E		(lcdPins[COM2][LCD_DIGITS] & DIG_21)
#define DIG_2G		(lcdPins[COM3][LCD_DIGITS] & DIG_21)
#define DIG_2F		(lcdPins[COM4][LCD_DIGITS] & DIG_21)

// Pin 10
#define DIG_22		LCDP10
#define DIG_2DP		(lcdPins[COM1][LCD_DIGITS] & DIG_22)
#define DIG_2C		(lcdPins[COM2][LCD_DIGITS] & DIG_22)
#define DIG_2B		(lcdPins[COM3][LCD_DIGITS] & DIG_22)
#define DIG_2A		(lcdPins[COM4][LCD_DIGITS] & DIG_22)

// Pin 11
#define DIG_11		LCDP11
#define DIG_1D		(lcdPins[COM1][LCD_DIGITS] & DIG_11)
#define DIG_1E		(lcdPins[COM2][LCD_DIGITS] & DIG_11)
#define DIG_1G		(lcdPins[COM3][LCD_DIGITS] & DIG_11)
#define DIG_1F		(lcdPins[COM4][LCD_DIGITS] & DIG_11)

// Pin 12
#define DIG_12		LCDP12
#define DIG_1DP		(lcdPins[COM1][LCD_DIGITS] & DIG_12)
#define DIG_1C		(lcdPins[COM2][LCD_DIGITS] & DIG_12)
#define DIG_1B		(lcdPins[COM3][LCD_DIGITS] & DIG_12)
#define DIG_1A		(lcdPins[COM4][LCD_DIGITS] & DIG_12)

// Pin 13
#define DIG_01		LCDP13
#define DIG_0D		(lcdPins[COM1][LCD_DIGITS] & DIG_01)
#define DIG_0E		(lcdPins[COM2][LCD_DIGITS] & DIG_01)
#define DIG_0G		(lcdPins[COM3][LCD_DIGITS] & DIG_01)
#define DIG_0F		(lcdPins[COM4][LCD_DIGITS] & DIG_01)

// Pin 14
#define DIG_02		LCDP14
#define DIG_0DP		(lcdPins[COM1][LCD_DIGITS] & DIG_02)
#define DIG_0C		(lcdPins[COM2][LCD_DIGITS] & DIG_02)
#define DIG_0B		(lcdPins[COM3][LCD_DIGITS] & DIG_02)
#define DIG_0A		(lcdPins[COM4][LCD_DIGITS] & DIG_02)

// Pin 15
#define MODE_FL		(lcdPins[COM1][LCD_MODE] & LCDP15)
#define MODE_ML		(lcdPins[COM2][LCD_MODE] & LCDP15)
#define MODE_G		(lcdPins[COM3][LCD_MODE] & LCDP15)
#define MODE_K		(lcdPins[COM4][LCD_MODE] & LCDP15)

// Pin 16
#define MODE_LIQ	(lcdPins[COM1][LCD_MODE] & LCDP16)
#define MODE_M		(lcdPins[COM2][LCD_MODE] & LCDP16)
#define MODE_W		(lcdPins[COM3][LCD_MODE] & LCDP16)
#define MODE_T		(lcdPins[COM4][LCD_MODE] & LCDP16)

// special Occurences
#define DIG_COLON	DIG_3DP
#define DIG_2DEC	DIG_2DP
#define DIG_1DEC	DIG_1DP
#define MODE_LB		DIG_1DP

/***************************************************************************
	Other Macros
****************************************************************************/

#define ENABLE_ACI()	ACSR |= _BV(ACIE)		// Enable Analog Comparator ISR
#define DISABLE_ACI()	ACSR &= ~_BV(ACIE)		// Disable Analog Comparator ISR

#define ENABLE_TIM0A()	TIMSK0 |= _BV(OCIE0A)		// Enable timer0A ISR
#define DISABLE_TIM0A()	TIMSK0 &= ~_BV(OCIE0A)		// Disable timer0A ISR

#define DISABLE_INTERRUPTS()	cli()
#define ENABLE_INTERRUPTS()		sei()

