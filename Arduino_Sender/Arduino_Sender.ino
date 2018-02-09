
/*
 * ArduBoardControler.ino
 *
 * Created: 9/5/2015 7:12:40 PM
 * Author: AC
 */ 
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
#include <SPI.h>

#include "Config.h"
#include "nRF24L01.h"
#include "RF24.h"
#include "datatypes.h"
#include "local_datatypes.h"
#ifdef DEBUG
#include "VescUart.h" //SerialPrint for received Data Package
#endif


// Set up nRF24L01 radio on SPI bus plus pins 9 & 10

RF24 radio(CEPIN,CSPIN);

struct bldcMeasure VescMeasuredValues;

// Declaration of global variables and const

long failedCounter = 0;
boolean sendOK = false;
boolean recOK = false;
int averageCycles = 2;
int data;
void setup()
{	

#ifdef DEBUG
	Serial.begin(9600);
	Serial.println("Tx Started");
#endif

	//Initialization of Radio
	radio.begin();
	radio.enableAckPayload();
	radio.enableDynamicPayloads();
	radio.openWritingPipe(pipe);
  data=1;
}

void loop()
{
	sendOK = radio.write(&data, sizeof(data));
	//read Acknowledegement message from RX
	while (radio.isAckPayloadAvailable())
	{
		radio.read(&VescMeasuredValues, sizeof(VescMeasuredValues));
		recOK = true;
	}
	if (sendOK)
	{
#ifdef DEBUG
		Serial.println("Send successfully!");
		Serial.print("Failed= "); Serial.println(failedCounter);
#endif //DEBUG
		sendOK = false;
	}
	else
	{
		Serial.println("Send failed!");
		failedCounter++;}
		if (recOK)
		{
#ifdef DEBUG
			Serial.println("Received values from Vesc:");
			SerialPrint(VescMeasuredValues);
#endif //DEBUG
		}
}
		


