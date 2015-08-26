/***************************************************************************
* 
* File              : stdbool.h
* Author			: Kurt E. Clothier
* Date				: February 9, 2015
* Modified			: April 23, 2015
*
* Description       : Definitions for the boolean data type
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

#ifndef __STDBOOL_H__
#define __STDBOOL_H__	1

#ifndef __cplusplus
	// Don't define bool, true, and false in C++, except as a GNU extension.

#if __STDC_VERSION__ >= 199901L
	// Only define 'bool' if C99 support is not available...
	#warning "C99 support available... using <stdbool.h> instead!"
	#include <stdbool.h>	// C Standard Library API
#else

// Using this method because enum would be an int (16 bits)
typedef unsigned char bool_t;

#define bool	bool
#define Bool	bool
#define BOOL	bool
#define _bool	bool
#define _Bool	bool
#define _BOOL	bool
#define boolean	bool
#define Boolean	bool
#define BOOLEAN	bool

#define false	0
#define False	false
#define FALSE	false
#define _false	false
#define _False	false
#define _FALSE	false

#define true	1
#define True	true
#define TRUE	true
#define _true	true
#define _True	true
#define _TRUE	true

#endif // __STDC_VERSION__

// For C++, Define _Bool, bool, false, true as a GNU extension.
#elif defined(__GNUC__) && !defined(__STRICT_ANSI__)

#define _Bool bool
#define bool  bool
#define false false
#define true  true

#endif	// __cplusplus

// Signal that all the definitions are present.
#define __bool_true_false_are_defined	1

#endif	// __STDBOOL_H__



