//--- Beam controller
#ifndef BeamControl_h
#define BeamControl_h

#include "Arduino.h"
#include "Beam.h"


class BeamControl{
	public:
		BeamControl();
		void begin(Beam *beams, byte beamAm);
		Beam* freeBeam();
		
		Beam *beamArray;
		byte beamArray_len;
		
	private:
		
};

#endif