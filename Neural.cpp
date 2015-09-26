#include "Arduino.h"
#include "Neural.h"

Neural::Neural(){
	
}

void Neural::begin(BeamControl *_beamControl){
	beamControl = _beamControl;
}

void Neural::startBeam(Segment *neuron, Segment *skipSeg, float _spd, byte _spdMode, float _len, Color _col, int _power ){
	// detrmine the place of the segment that has to be skipped in the connections array
	int skipId = -1;
	for (int i=0; i<neuron->connAm; i++){
		if( &neuron->connSeg[i] == skipSeg ){
			skipId = i;
			break;
		}
	}
	
	// determine the amount of segments that can be chosen from and choose one
	byte chooseAm = neuron->connAm;
	if (skipId != -1) chooseAm--;
	
	byte nextSegId = random(0,chooseAm);
	if(skipId != -1 && nextSegId >= skipId) nextSegId++;
	
	Segment nextSynapse = neuron->connSeg[nextSegId];
	
	// determine the correct direction for the beam
	boolean dir = UP;
	if( &nextSynapse.connSeg[1] == neuron ) dir = DOWN;
	
	// send the pulse in the neural network
	addNNBeam(&nextSynapse, dir, _spd, _spdMode, _len, _col, _power);
}


void Neural::arriveBeam(Beam *beam){
	beam->arrive();
	
	// determine the neuron it arrived at
	byte connId = ((beam->segSpd > 0) ? 1 : 0);
	Segment *nextNeuron;
	nextNeuron = &beam->onSegment->connSeg[connId];
	
	// animate the neuron
	nextNeuron->setFadeInOut(beam->color,2,0.5);
	
	// calc the new power of the beam, stop if no power left
	int newPower = beam->power - beamDecay;
	if (newPower <= 0){
		return;
	}
	
	// get the speed type and the according speed
	float spd = beam->segSpd;
	byte spdMode = SEGMENT_SPD;
	if( beam->spdMode == PIXEL_SPD ){
		spd = beam->pixelSpd;
		spdMode = PIXEL_SPD;
	}
	
	// get the color and change the brightness if power is less then 100
	Color c = beam->color;
	int power = beam->power;
	if( power < 100 ) beam->color.setHSB(c.hue(), c.saturation(), constrain(power,0,100));
	
	// create the next beam
	startBeam(nextNeuron, beam->onSegment, spd, spdMode, beam->spread, c, power);
}


void Neural::neuronDischarge(Segment *neuron){
	
}

boolean Neural::addNNBeam(Segment *seg, boolean dir, float spd, byte spdMode, float len, Color col, int power){
	Beam* newBeam = beamControl->freeBeam();
	if(newBeam == NULL) return false;
	newBeam->begin(seg, dir, spd, spdMode, len, col, NEURAL, power);
	return true;
}