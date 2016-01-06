//--- Beam controller
#ifndef BeamControl_h
#define BeamControl_h

#include "Arduino.h"
#include "Beam.h"

class Beam; // forward declaration

class BeamControl{
	public:
		BeamControl();
		void begin(Beam *_beamArray, uint16_t beamAm, void (*_setPixel)(int pixel, byte, byte, byte), Color (*_getPixel)(int));
		void update(float dt);
		Beam* freeBeam();
		
		Beam *beamArray;
		uint16_t beamArray_len;
		uint16_t activeBeams;
		
	private:
		
		void (*setPixel)(int pixel, byte r, byte g, byte b);
		Color (*getPixel)(int);
};

#endif