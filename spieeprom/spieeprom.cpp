/*
 * spieeprom.cpp - library for SPI EEPROM IC's
 * https://bitbucket.org/trunet/spieeprom/
 * 
 * This library is based on code by Heather Dewey-Hagborg
 * available on http://www.arduino.cc/en/Tutorial/SPIEEPROM
 * 
 * by Wagner Sartori Junior <wsartori@gmail.com>
 * 
 * modified by R.Boullard to add 
 * writeAnything and readAnything functions
 *
 */

#include <SPI.h>
#include "spieeprom.h"

SPIEEPROM::SPIEEPROM() {
	eeprom_type = 0;
}

SPIEEPROM::SPIEEPROM(byte type) {
	if (type>1) {
		eeprom_type = 0;
	} else {
		eeprom_type = type;
	}
}

void SPIEEPROM::begin() {
	pinMode(SLAVESELECT, OUTPUT);
	SPI.begin();
	SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE0); 
    SPI.setClockDivider(SPI_CLOCK_DIV64);
}

void SPIEEPROM::send_address(long addr) {
	if (eeprom_type == 1) SPI.transfer((byte)(addr >> 16));	
  	SPI.transfer((byte)(addr >> 8));
  	SPI.transfer((byte)(addr));	
}

void SPIEEPROM::start_write() {
	digitalWrite(SLAVESELECT,LOW);
	SPI.transfer(WREN); //send WREN command
	digitalWrite(SLAVESELECT,HIGH);
	digitalWrite(SLAVESELECT,LOW);
	SPI.transfer(WRITE); //send WRITE command
}

bool SPIEEPROM::isWIP() {
	byte data;
	digitalWrite(SLAVESELECT,LOW);
	SPI.transfer(RDSR); // send RDSR command
	data = SPI.transfer(0xFF); //get data byte
	digitalWrite(SLAVESELECT,HIGH);
	return (data & (1 << 0));
}









