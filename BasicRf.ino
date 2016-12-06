/*
Released under Creative Commons Attribution 4.0
by bitluni 2016
https://creativecommons.org/licenses/by/4.0/
Attribution means you can use it however you like as long you
mention that it's base on my stuff.
I'll be pleased if you'd do it by sharing http://youtube.com/bitlunislab
*/

#include "RF.h"

const int ID = 28013; 	//0..1048575 28013 was preprogrammed
const int CHANNEL = 0;	//0..1
const int RF_OSC = 200;	//rf signal cycle legth(µs). 200 works for me

const int RF_OUT = D6;

void setup() 
{
  pinMode(RF_OUT, OUTPUT);
}

void loop() 
{
	//turn off
	for(int i = 0; i < 5; i++)
	{
		rfWriteCode(RF_OUT, RF_OSC, ID, (1 << (CHANNEL + 1)));
	}
	delay(3000);
	//turn on
	for(int i = 0; i < 5; i++)
	{
		rfWriteCode(RF_OUT, RF_OSC, ID, 1 | (1 << (CHANNEL + 1)));
	}
	delay(3000);
}
