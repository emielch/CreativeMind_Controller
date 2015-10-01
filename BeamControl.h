//--- Beam controller
#ifndef BeamControl_h
#define BeamControl_h

#include "Arduino.h"
#include "Beam.h"


class BeamControl{
	public:
		BeamControl();
		void begin(Beam *_beamArray, byte beamAm, void (*_setPixel)(int pixel, byte, byte, byte), Color (*_getPixel)(int));
		void update(float dt);
		Beam* freeBeam();
		
		Beam *beamArray;
		byte beamArray_len;
		
	private:
		
		void (*setPixel)(int pixel, byte r, byte g, byte b);
		Color (*getPixel)(int);
};

#endif