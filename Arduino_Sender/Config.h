// Config.h

/*
Copyright 2015 - 2017 Andreas Chaitidis Andreas.Chaitidis@gmail.com

This program is free software : you can redistribute it and / or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.If not, see <http://www.gnu.org/licenses/>.

*/

// Config TX

#ifndef _CONFIG_h
#define _CONFIG_h



#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

//General settings:

#define DEBUG //use if debug information over serial required

// Definition of Pipe for nRF24

const uint64_t pipe = 0xE8E8F0F0E1LL;

//Pin definition

//**for Mega2560 (old status!!)
#ifdef __AVR_ATmega2560__ 

#define CEPIN				9
#define CSPIN				10
#endif

//**for Arduino ATmega328p (Nano)

#ifdef ARDUINO_AVR_NANO

//SPI definition (for better readability)

#define MOSI				11
#define MISO				12
#define SCK					13

//nRF24: 
#define CEPIN				9
#define CSPIN				10
//other Pins

//Definition of Serial
#define DEBUGSERIAL			Serial
#define SERIALIO			Serial
#endif

#endif
