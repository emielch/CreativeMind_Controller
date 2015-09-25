/*
Colore.h - Library for saving colors
Created by Emiel Harmsen 14-1-2015.
*/

#ifndef Colore_h
#define Colore_h

#include "Arduino.h"
#include "Color.h"
#include "Segment.h"
#include "Beam.h"



// --- main class, controlling library etc. ---

class Colore{
	public:
		Colore();
		void update();
		void begin(uint16_t leds, Segment **segments, byte segLen, Beam *beams, byte beamAm, void (*_setPixel)(int pixel, byte, byte, byte), Color (*_getPixel)(int), void (*_showPixels)());
		boolean addBeam(Segment *seg, boolean dir, float spd, float len, Color col);
		boolean lightUp(Segment *seg, float spd, Color col);
	
	private:
		uint16_t totLedAm;
		Segment **segArray;
		byte segArray_len;
		Beam *beamArray;
		byte beamArray_len;
		unsigned long lastCalc; // variable to keep track of the loops per second
		float dt;
		
		void (*setPixel)(int pixel, byte r, byte g, byte b);
		void (*showPixels)();
		Color (*getPixel)(int);
		void calcDt();
};


#endif