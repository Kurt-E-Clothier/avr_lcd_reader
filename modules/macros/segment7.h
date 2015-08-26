/***************************************************************************
* 
* File              : segment7.h
* Author			: Kurt E. Clothier
* Date				: August 1, 2012
* Modified			: April 23, 2015
*
* Description       : Header file containing the hex codes 
*					: for generating a seven segment display
*					: using an 8 bit parallel out register.
*
* Compiler			: GCC
* Preprocessor Info	: http://gcc.gnu.org/onlinedocs/gcc-2.95.3/cpp_1.html
* Licensing    		: Creative Commons: by Attribution 3.0 
*              		: See http://www.projectsbykec.com/legal
*
* More Information	: http://www.projectsbykec.com/
*
****************************************************************************

	Available characters are shown in the table below and can be 
	called as "SEGMENT" plus the desired character. For example, 
	to create the character 'E' use "SEGMENTE" while the character
	'9' is created using "SEGMENT9".
	Logical OR any value with "SEGMENTDP" to turn on the dot/point.

    __A__
   |     |
 F |     | B
   |__G__|			MSB > | DP | G | F | E| D | C | B | A | < LSB
   |     |
 E |     | C
   |__D__|   . DP

	#	DP	G	F	E	D	C	B	A	HEX
 -------------------------------------------
		0	0	0	0	0	0	0	0	0x00
	.	1	x	x	x	x	x	x	x	0x80
	0	x	0	1	1	1	1	1	1	0x3F
	1	x	0	0	0	0	1	1	0	0x06
	2	x	1	0	1	1	0	1	1	0x5B
	3	x	1	0	0	1	1	1	1	0x4F
	4	x	1	1	0	0	1	1	0	0x66
	5	x	1	1	0	1	1	0	1	0x6D
	6	x	1	1	1	1	1	0	1	0x7D
	7	x	0	0	0	0	1	1	1	0x07
	8	x	1	1	1	1	1	1	1	0x7F
	9	x	1	1	0	0	1	1	1	0x67
	A	x	1	1	1	0	1	1	1	0x77
	b	x	1	1	1	1	1	0	0	0x7C
	c	x	1	0	1	1	0	0	0	0x58
	C	x	0	1	1	1	0	0	1	0x39
	d	x	1	0	1	1	1	1	0	0x5E
	E	x	1	1	1	1	0	0	1	0x79
	F	x	1	1	1	0	0	0	1	0x71
	H	x	1	1	1	0	1	1	0	0x76
	i	x	0	0	0	0	1	0	0	0x04
	J	x	0	0	1	1	1	1	0	0x1E
	L	x	0	1	1	1	0	0	0	0x38
	n	x	1	0	1	0	1	0	0	0x54
	o	x	1	0	1	1	1	0	0	0x5C
	P	x	1	1	1	0	0	1	1	0x73
	r	x	1	0	1	0	0	0	0	0x50
	S	x	1	1	0	1	1	0	1	0x6D
	u	x	0	0	1	1	1	0	0	0x1C
	U	x	0	1	1	1	1	1	0	0x3E

****************************************************************************/

#ifndef _SEGMENT7_
#define _SEGMENT7_

/***************************************************************************
  Alpha-Numerical Display Segments
****************************************************************************/
#define SEGMENTBL	0x00	// Blank
#define SEGMENTDP	0x80	// Dot, Point
#define SEGMENT0	0x3F	// Zero
#define SEGMENT1	0x06	// One
#define SEGMENT2	0x5B	// Two
#define SEGMENT3	0x4F	// Three
#define SEGMENT4	0x66	// Four
#define SEGMENT5	0x6D	// Five
#define SEGMENT6	0x7D	// Six
#define SEGMENT7	0x07	// Seven
#define SEGMENT8	0x7F	// Eight
#define SEGMENT9	0x67	// Nine
#define SEGMENTA	0x77	// 'A'
#define SEGMENTb	0x7C	// 'b'
#define SEGMENTc	0x58	// 'c'
#define SEGMENTC	0x39	// 'C'
#define SEGMENTd	0x5E	// 'd'
#define SEGMENTE	0x79	// 'E'
#define SEGMENTF	0x71	// 'F'
#define SEGMENTH	0x76	// 'H'
#define SEGMENTi	0x04	// 'i'
#define SEGMENTJ	0x1E	// 'J'
#define SEGMENTL	0x38	// 'L'
#define SEGMENTn	0x54	// 'n'
#define SEGMENTo	0x5C	// 'o'
#define SEGMENTP	0x73	// 'P'
#define SEGMENTr	0x50	// 'r'
#define SEGMENTS	0x6D	// 'S'
#define SEGMENTu	0x1C	// 'u'
#define SEGMENTU	0x3E	// 'U'

#endif // _SEGMENT7_


