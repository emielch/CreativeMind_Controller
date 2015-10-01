#include "Arduino.h"
#include "Neural.h"

Neural::Neural(){
	
}


void Neural::begin(BeamControl *_beamControl){
	beamControl = _beamControl;
}


void Neural::startNeuronBeam(Segment *neuron, Segment *skipSeg, float _spd, byte _spdMode, float _len, Color _col, int _power ){
	
	// stop if the segment not a NEURON
	if( neuron->nnType!=NEURON){
		Serial.println(F("Segment is not a NEURON"));
		return;
	} 
	
	byte nextSegId;
	//Serial.println(neuron->connAm);
	
	// if the neuron has only one connection choose that one
	if( neuron->connAm == 1 ) nextSegId = 0;
	
	// stop if neuron has no connections
	else if( neuron->connAm == 0 ){
		Serial.println(F("Neuron has no connections, arrived at dead end"));
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
	Color neurBGColor(0,0,100,HSB_MODE);
	neuron->setFadeInOut(neurCol,neurBGColor,2,0.5);
	
	startSynapseBeam(nextSynapse, dir, _spd, _spdMode, _len, _col, _power);
}


void Neural::startSynapseBeam(Segment *synapse, boolean dir, float _spd, byte _spdMode, float _len, Color _col, int _power ){
	if( synapse->nnType != SYNAPSE ){
		Serial.println(F("Segment is not a SYNAPSE"));
		return;
	}
	
	// send the pulse in the neural network
	addNNBeam(synapse, dir, _spd, _spdMode, _len, _col, _power);
}


void Neural::arriveBeam(Beam *beam){
	//Serial.println(F("beam arrived"));
	beam->arrive();
	
	// stop if arrived at dead end
	if( beam->onSegment->connAm == 0 || beam->onSegment->connAm == 1 ){
		Serial.println(F("Arrived at a dead end"));
		return;
	}
	
	// determine the segment it arrived at
	byte connId = ((beam->dir == UP) ? 1 : 0);
	Segment *nextSegment = beam->onSegment->connSeg[connId];
	
	//check the type of the next segment
	if( nextSegment->nnType == SYNAPSE && !allowDirectSynapse){
		Serial.println(F("The beam has arrived at not a NEURON"));
		return;
	}
	
	// increase the power of the segment it arrived at, accoring to the power of the beam
	// and discharge the neuron if neccesary
	if(nextSegment->nnType == NEURON){
		nextSegment->power += 10;
		if(nextSegment->power >= 100){
			neuronDischarge(nextSegment, beam->color.hue());
		}
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
	if (nextSegment->nnType == SYNAPSE){
		boolean dir = DOWN;
		if( nextSegment->connSeg[0] == beam->onSegment) dir = UP;
		startSynapseBeam(nextSegment, dir, spd, spdMode, beam->spread, beam->color, newPower);
	}else{
		startNeuronBeam(nextSegment, beam->onSegment, spd, spdMode, beam->spread, beam->color, newPower);
	}
	
}


void Neural::neuronDischarge(Segment *neuron, int hue){
	// animate the neuron
	Color white(255,255,255,RGB_MODE);
	Color black(0,0,0,RGB_MODE);
	neuron->setFadeInOut(white,black,8,0.5);
	neuron->power = 0;
	
	// get some variables for the new beam
	int spd = 100;
	int power = 100;
	Color col(hue,100,100,HSB_MODE);
	
	// fire beams in all directions
	for (int i=0; i<neuron->connAm; i++){
		Segment *nextSynapse = neuron->connSeg[i];
		
		// determine the correct direction for the beam
		boolean dir = DOWN;
		if( nextSynapse->connSeg[0] == neuron ) dir = UP;
		
		// fire the beam
		startSynapseBeam(nextSynapse, dir, spd, PIXEL_SPD, 10, col, power);
	}
}

boolean Neural::addNNBeam(Segment *seg, boolean dir, float spd, byte spdMode, float len, Color col, int power){
	Beam* newBeam = beamControl->freeBeam();
	if(newBeam == NULL) return false;
	newBeam->begin(seg, dir, spd, spdMode, len, col, NEURAL, power);
	return true;
}