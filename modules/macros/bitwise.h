/***************************************************************************
* 
* File              : bitwise.h
* Author			: Kurt E. Clothier
* Date				: February 8, 2015
* Modified			: April 23, 2015
*
* Description       : Bitwise macros for increased code readability
*
* Compiler			: GCC
* Preprocessor Info	: http://gcc.gnu.org/onlinedocs/gcc-2.95.3/cpp_1.html
*
* Licensing    		: Creative Commons: by Attribution 3.0 
*              		: See http://www.projectsbykec.com/legal
*
* More Information	: http://www.projectsbykec.com/
*
****************************************************************************/

#ifndef _BITWISE_H_
#define _BITWISE_H_

/***************************************************************************
	Bitwise Macros
****************************************************************************/
#ifndef _BV
#define	_BV(BIT)	(1 << (BIT))
#endif // _BV

#define SET_BIT(BYTE, BIT)		(BYTE |= (BIT))
#define CLEAR_BIT(BYTE, BIT)	(BYTE &= ~(BIT))
#define TOGGLE_BIT(BYTE, BIT)	(BYTE ^= (BIT))

#define SET_BV(BYTE, BV)		(BYTE |= (1<<BV))
#define CLEAR_BV(BYTE, BV)		(BYTE &= ~(1<<BV))
#define TOGGLE_BV(BYTE, BV)		(BYTE ^= (1<<BV))

#define	BIT_IS_HI(BYTE, BIT)	(BYTE & (BIT))
#define	BIT_IS_LO(BYTE, BIT)	(!(BYTE & (BIT)))

#define	BV_IS_HI(BYTE, BIT)	(BYTE & _BV(BIT))
#define	BV_IS_LO(BYTE, BIT)	(!(BYTE & _BV(BIT)))

#define	LOOP_UNTIL_BIT_HI(BYTE, BIT)	do{ } while (BIT_IS_LO(BYTE, BIT))
#define	LOOP_UNTIL_BIT_LO(BYTE, BIT)	do{ } while (BIT_IS_HI(BYTE, BIT))

#define	LOOP_UNTIL_BV_HI(BYTE, BIT)	do{ } while (BV_IS_LO(BYTE, BIT))
#define	LOOP_UNTIL_BV_LO(BYTE, BIT)	do{ } while (BV_IS_HI(BYTE, BIT))
	
#define	LOOP_WHILE_BIT_HI(BYTE, BIT)	LOOP_UNTIL_BIT_LO(BYTE, BIT)
#define	LOOP_WHILE_BIT_LO(BYTE, BIT)	LOOP_UNTIL_BIT_HI(BYTE, BIT)

#define	LOOP_WHILE_BV_HI(BYTE, BIT)		LOOP_UNTIL_BV_LO(BYTE, BIT)
#define	LOOP_WHILE_BV_LO(BYTE, BIT)		LOOP_UNTIL_BV_HI(BYTE, BIT)

#define	SWAP(A, B)	do { (A)^=(B); (B)^=(A); (A)^=(B); }while(0)	// Can't pass expressions

#endif // _BITWISE_H_

