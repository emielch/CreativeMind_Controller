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
		void begin(int bDec, float nCharge, int _DCSpd, int _DCPower, float _DCSpread, boolean _DCSpdMode, float inSpd, float outSpd, boolean directSynapse, BeamControl *_beamControl);
		void setSendFunction(void (*_sendNeuronFire)(byte));
		void update();
		boolean startNeuronBeam(Segment *neuron, Segment *skipSeg, float _spd, byte _spdMode, float _len, Color _col, int _power, boolean animNeur);
		boolean startSynapseBeam(Segment *neuron, boolean dir, float _spd, byte _spdMode, float _len, Color _col, int _power );
		
	private:
		void arriveBeam(Beam *beam);
		void neuronDischarge(Segment *neuron, int hue);
		boolean addNNBeam(Segment *seg, boolean dir, float spd, byte spdMode, float len, Color col, int power);
		BeamControl *beamControl;
		
		int beamDecay;
		float neuronChargeFac;
		int DCSpd;
		int DCPower;
		float DCSpread;
		boolean DCSpdMode;
		float fadeInSpd;
		float fadeOutSpd;
		boolean allowDirectSynapse;
		
		void (*sendNeuronFire)(byte);
};



#endif