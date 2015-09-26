#include "Arduino.h"
#include "Neural.h"

Neural::Neural(){
	
}

void Neural::begin(BeamControl *_beamControl){
	beamControl = _beamControl;
}



void Neural::startBeam(Segment *neuron, Segment *skipSeg, float _spd, byte _spdMode, float _len, Color _col, int _power ){
	byte nextSegId;
	
	// if the neuron has only one connection choose that one
	if( neuron->connAm == 1 ) nextSegId = 0;
	
	// stop if neuron has no connections
	else if( neuron->connAm == 0 ){
		Serial.println("Neuron has no connections, arrived at dead end");
		return;
	}
	
	// if multiple connections; choose one randomly
	else{
		
		// determine the place of the segment that has to be skipped in the connections array
		int skipId = -1;
		for (int i=0; i<neuron->connAm; i++){
			if( neuron->connSeg[i] == skipSeg ){
				skipId = i;
				break;
			}
		}
		
		// determine the amount of segments that can be chosen from and choose one
		byte chooseAm = neuron->connAm;
		if (skipId != -1) chooseAm--;
		
		nextSegId = random(0,chooseAm);
		if(skipId != -1 && nextSegId >= skipId) nextSegId++;
	}
	
	Segment *nextSynapse = neuron->connSeg[nextSegId];
	
	// determine the correct direction for the beam
	boolean dir = UP;
	if( nextSynapse->connSeg[1] == neuron ) dir = DOWN; // if the neuron at the end of the synapse is the neuron the beam came from; the direction is DOWN. Else its UP
	
	// get the color and change the brightness according to power
	_col.setHSB(_col.hue(), _col.saturation(), constrain(_power,0,100));
	
	// animate the neuron
	Color neurCol = neuron->getCurrentColor();
	neurCol.addHDR( _col, 1 );
	neuron->setFadeInOut(neurCol,2,0.5);
	
	// send the pulse in the neural network
	addNNBeam(nextSynapse, dir, _spd, _spdMode, _len, _col, _power);
}


void Neural::arriveBeam(Beam *beam){
	beam->arrive();
	
	// stop if arrived at dead end
	if( beam->onSegment->connAm == 0 || beam->onSegment->connAm == 1 ){
		Serial.println("Arrived at a dead end");
		return;
	}
	
	// determine the neuron it arrived at
	byte connId = ((beam->dir == UP) ? 1 : 0);
	Segment *nextNeuron = beam->onSegment->connSeg[connId];
	
	//check if the segment is actually a neuron
	if( nextNeuron->nnType != NEURON){
		Serial.println("The beam has arrived at not a NEURON");
		return;
	}
	
	// calc the new power of the beam, stop if no power left
	int newPower = beam->power - beamDecay;
	if (newPower <= 0){
		return;
	}
	
	// get the speed type and the according speed
	float spd = beam->segSpd;
	byte spdMode = beam->spdMode;
	if( spdMode == PIXEL_SPD ){
		spd = beam->pixelSpd;
	}

	// create the next beam
	startBeam(nextNeuron, beam->onSegment, spd, spdMode, beam->spread, beam->color, newPower);
}


void Neural::neuronDischarge(Segment *neuron){
	
}

boolean Neural::addNNBeam(Segment *seg, boolean dir, float spd, byte spdMode, float len, Color col, int power){
	Beam* newBeam = beamControl->freeBeam();
	if(newBeam == NULL) return false;
	newBeam->begin(seg, dir, spd, spdMode, len, col, NEURAL, power);
	return true;
}