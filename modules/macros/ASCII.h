/***************************************************************************
* 
* File              : ASCII.h
* Author			: Kurt E. Clothier
* Date				: March 1, 2012
* Modified			: April 23, 2015
*
* Description       : Header file containing the hex codes associated
*					: with various ASCII characters and commands.
*					: American Standard Code for Information Interchange
*
* Compiler			: GCC
* Preprocessor Info	: http://gcc.gnu.org/onlinedocs/gcc-2.95.3/cpp_1.html
* Licensing    		: Creative Commons: by Attribution 3.0 
*              		: See http://www.projectsbykec.com/legal
*
* More Information	: http://www.projectsbykec.com/
*
****************************************************************************/

#ifndef _ASCII_
#define _ASCII_

/***************************************************************************
  Standard Table
****************************************************************************/
#define _NUL	0x00	// Null Character
#define _SOH	0x01	// Start of Heading
#define _STX	0x02	// Start of Text
#define _ETX	0x03	// End of Text
#define _EOT	0x04	// End of Transmission
#define _ENQ	0x05	// Enquiry
#define _ACK	0x06	// Acknowledge
#define _BEL	0x07	// Bell
#define _BS		0x08	// Backspace
#define _TAB	0x09	// Horizontal Tab
#define _LF		0x0A	// NL line fee, new line
#define _VT		0x0B	// Vertical tab
#define _FF		0x0C	// NP form fee, new page
#define _CT		0x0D	// Carriage return
#define _SO		0x0E	// Shift Out
#define _SI		0x0F	// Shift In

#define _DLE	0x10	// Data Link Escape
#define _DC1	0x11	// Device Control 1
#define _DC2	0x12	// Device Control 2
#define _DC3	0x13	// Device Control 3
#define _DC4	0x14	// Device Control 4
#define _NAK	0x15	// Negative Acknowledge
#define _SYN	0x16	// Synchronous idle
#define _ETB	0x17	// End of transmission block
#define _CAN	0x18	// Cancel
#define	_EM		0x19	// End of Medium
#define _SUB	0x1A	// Substitute
#define _ESC	0x1B	// Escape
#define _FS		0x1C	// File Separator
#define _GS		0x1D	// Group Separator
#define _RS		0x1E	// Record Separator
#define _US		0x1F	// Unit Separator

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
#define _BSLSH	0x5C	// \ - Backslash
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
#define _TILDE	0x7E	// ~ - Tilde

#endif // _ASCII_


