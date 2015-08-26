/***************************************************************************
* 
* File              : avr.h
* Author			: Kurt E. Clothier
* Date				: November 7, 2011
* Modified			: April 23, 2015
*
* Description       : Header file for all AVR projects
*
* Compiler			: AVR-GCC
* Hardware			: Any AVR micro-controller
*
* Preprocessor Info	: http://gcc.gnu.org/onlinedocs/gcc-2.95.3/cpp_1.html
* More Information	: http://www.projectsbykec.com/
*
****************************************************************************/

#ifndef _AVR_H_
#define _AVR_H_

/***************************************************************************
	Header Files to Include
****************************************************************************/
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdint.h>
#include "modules/macros/stdbool.h"
#include "modules/macros/bitwise.h"
#include "modules/macros/constants.h"

/***************************************************************************
	Simplified Port Definitions
****************************************************************************/
#define PORT_(port) PORT ## port
#define DDR_(port)  DDR  ## port
#define PIN_(port)  PIN  ## port

#define PORT(port) PORT_(port)
#define DDR(port)  DDR_(port)
#define PIN(port)  PIN_(port)

/** Example Use
#define LED_PORT 	A
#define LED			(1<<PA0)
// ...
DDR(LED_PORT) |= LED;	// Set "LED" pin as output
PORT(LED_PORT) |= LED;	// Set "LED" pin HI
**/

/***************************************************************************
	Other Macros
****************************************************************************/
#define _NOP() asm volatile("nop")		// Assembly NOP instruction for delay

#endif // _AVR_H_

