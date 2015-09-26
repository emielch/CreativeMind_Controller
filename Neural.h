//---- Neural Net ----

#ifndef Neural_h
#define Neural_h

#include "Arduino.h"
#include "Color.h"
#include "Segment.h"
#include "Beam.h"
#include "BeamControl.h"

class Neural{
	public:
		Neural();
		void begin(BeamControl *_beamControl);
		void startBeam(Segment *neuron, Segment *skipSeg, float _spd, byte _spdMode, float _len, Color _col, int _power );
		void arriveBeam(Beam *beam);
	
	private:
		void neuronDischarge(Segment *neuron);
		boolean addNNBeam(Segment *seg, boolean dir, float spd, byte spdMode, float len, Color col, int power);
		BeamControl *beamControl;
		
		int beamDecay = 20;
		
};



#endif