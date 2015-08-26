/***************************************************************************
* 
* File              : SerLCD_characters.h
* Author			: Kurt E. Clothier
* Date				: February 8, 2013
* Modified			: February 9, 2013
*
* Description       : Header file containing the hex codes associated
*					: with various non-ASCII characters for use with
*					: LCD display drivers, primarily the HD44780.
*
* Associated Files	: SerLCD_2x16.h, SerLCD-2x16.c, SerLCD_commands.h
*
* More Information	: www.projectsbykec.com
*
****************************************************************************/

#ifndef _LCDchar_
#define _LCDchar_

/***************************************************************************
  ROM Code: A00
****************************************************************************/
#define _DOUBLELINE	0x01	// Two vertical bars = ||
#define _TRIPLELINE	0x02	// Three vertical bars = |||

#ifndef _ASCII_			// These Characters are identical to the ASCII table

#define _BS		0x08	// Backspace

#define _SPACE	0x20	// Space
#define _EXCLAM	0x21	// ! - Exclamation Point
#define _QUOTE	0x22	// " - Quotation Marks
#define _POUND	0x23	// # - Pound Sign
#define _DLR	0x24	// $ - Dollar Sign
#define _PRCNT	0x25	// % - Percent Sign
#define _AND	0x26	// & - Ampersand
#define _APO	0x27	// ' - Apostrophe
#define _LPAR	0x28	// ( - Left Parenthesis
#define _RPAR	0x29	// ) - Right Parenthesis
#define _AST	0x2A	// * - Asterisk
#define _PLUS	0x2B	// + - Plus Sign
#define _COMMA	0x2C	// , - Comma
#define _DASH	0x2D	// - - Hyphen, Minus, Dash
#define _PER	0x2E	// . - Period, Full Stop
#define _SLASH	0x2F	// / - Slash

#define _ZERO	0x30	// 0
#define _ONE	0x31	// 1
#define _TWO	0x32	// 2
#define _THREE	0x33	// 3
#define _FOUR	0x34	// 4
#define _FIVE	0x35	// 5
#define _SIX	0x36	// 6
#define _SEVEN	0x37	// 7
#define _EIGHT	0x38	// 8
#define _NINE	0x39	// 9
#define _COLON	0x3A	// : - Colon
#define _SCOL	0x3B	// ; - SemiColon
#define _LESS	0x3C	// < - Less Than Sign
#define _EQUAL	0x3D	// = - Equals Sign
#define _MORE	0x3E	// > - Greater Than Sign
#define _QUES	0x3F	// ? - Question Mark

#define _ATS	0x40	// @ - At Sign
#define _CAPA	0x41	// A
#define _CAPB	0x42	// B
#define _CAPC	0x43	// C
#define _CAPD	0x44	// D
#define _CAPE	0x45	// E
#define _CAPF	0x46	// F
#define _CAPG	0x47	// G
#define _CAPH	0x48	// H
#define _CAPI	0x49	// I
#define _CAPJ	0x4A	// J
#define _CAPK	0x4B	// K
#define _CAPL	0x4C	// L
#define _CAPM	0x4D	// M
#define _CAPN	0x4E	// N
#define _CAPO	0x4F	// O

#define _CAPP	0x50	// P
#define _CAPQ	0x51	// Q
#define _CAPR	0x52	// R
#define _CAPS	0x53	// S
#define _CAPT	0x54	// T
#define _CAPU	0x55	// U
#define _CAPV	0x56	// V
#define _CAPW	0x57	// W
#define _CAPX	0x58	// X
#define _CAPY	0x59	// Y
#define _CAPZ	0x5A	// Z
#define _LSBRC	0x5B	// [ - Left Square Bracket
//#define _BSLSH	0x5C	// \ - Backslash **SEE _YEN**
#define _RSBRC	0x5D	// ] - Right Square Bracket
#define _CARET	0x5E	// ^ - Caret
#define _UNDSC	0x5F	// _ - Underscore

#define _ACCNT	0x60	// ` - Grave Accent
#define _LOWA	0x61	// a
#define _LOWB	0x62	// b
#define _LOWC	0x63	// c
#define _LOWD	0x64	// d
#define _LOWE	0x65	// e
#define _LOWF	0x66	// f
#define _LOWG	0x67	// g
#define _LOWH	0x68	// h
#define _LOWI	0x69	// i
#define _LOWJ	0x6A	// j
#define _LOWK	0x6B	// k
#define _LOWL	0x6C	// l
#define _LOWM	0x6D	// m
#define _LOWN	0x6E	// n
#define _LOWO	0x6F	// o

#define _LOWP	0x70	// p
#define _LOWQ	0x71	// q
#define _LOWR	0x72	// r
#define _LOWS	0x73	// s
#define _LOWT	0x74	// t
#define _LOWU	0x75	// u
#define _LOWV	0x76	// v
#define _LOWW	0x77	// w
#define _LOWX	0x78	// x
#define _LOWY	0x79	// y
#define _LOWZ	0x7A	// z
#define _LBRC	0x7B	// { - Left Bracket
#define _VBAR	0x7C	// | - Vertical Bar
#define _RBRC	0x7D	// } - Right Bracket

#endif // _ASCII_

#define _YEN	0x5C	// Yen Sign
#define _RARROW	0x7E	// -> - Right Arrow
#define _LARROW	0x7F	// <- - Left Arrow

// empty symbols (seen as a space)

#define _LOWBOX		0xA1	// Low Box
#define _TOPANGLE	0xA2	// Right angle at top
#define _BOTANGLE	0xA3	// Right angle at bottom
#define _HALFSLASH	0xA4	// half of a slash mark
#define _BULLET		0xA5	// Bullet Point
// unknown symbols
#define _EREVERSE	0xAE	// Capital letter E in reverse

// unknown symbols

#define _XSLANT		0xD2	// slanted lower case letter x
// unknown symbols
#define _SQUARE		0xDB	// Square shape
// unknown symbols
#define _QUOTE2		0xDE	// slanted quotation marks
#define _DEGREE		0xDF	// Degrees symbol

#define _ALPHA		0xE0	// Greek small letter Alpha 
#define _ADIAERESIS	0xE1	// Small Letter a with Diaeresis (two dots)
#define _BETA		0xE2	// Greek small letter Beta 
#define _EPSILON	0xE3	// Greek small letter Epsilon
#define _MU			0xE4	// Greek small letter Mu (Micro Symbol)
#define _SIGMA_S	0xE5	// Greek small letter Sigma
#define _RHO_S		0xE6	// Greek Small letter Rho
#define _GMODIFIER	0xE7	// Modifier small letter g
#define _ROOT		0xE8	// Root Symbol
#define	_INVERSE	0xE9	// Inverse = ^-1 (power of negative one)
#define _YOT		0xEA	// Greek Letter Yot (j)
#define _XPOWER		0xEB	// to the power of x = ^x
#define _CENTS		0xEC	// Cents sign (currency)
#define _LATINL		0xED	// Latin capital letter L with 2 lines
#define _NMACRON	0xEE	// small letter n with macron (line over top) 
#define _ODIAERESIS 0xEF	// small letter o with diaeresis (two dots)

#define _RHO_C		0xF0	// Greek capital letter Rho
#define _QOPH		0xF1	// Phonemic Representation of ancient letter
#define _THETA		0xF2	// Greek small letter Theta
#define _INFINITY	0xF3	// Infinity Symbol
#define _OMEGA		0xF4	// Greek capital letter Omega (Ohm Symbol)
#define _UDIAERESIS	0xF5	// Small Letter u with Diaeresis (two dots)
#define _SIGMA_C	0xF6	// Greek capital letter Sigma	
#define _PI			0xF7	// Greek small letter Pi
#define _XMACRON	0xF8	// small letter x with macron (line over top)
#define _Y_ALT		0xF9	// Alternate lower-case y
// unknown Asian symbols
#define _ALIEN		0xFC	// Alien symbol... like space invaders
#define _DIVIDE		0xFD	// Normal Divide Sign
#define _BLACKBOX	0xFF	// Filled in Box

#endif // _LCDchar_


