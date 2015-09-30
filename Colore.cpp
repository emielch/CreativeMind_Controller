/*
Colore.cpp - Library for saving colors
Created by Emiel Harmsen 14-1-2015.
*/

#include "Arduino.h"
#include "Colore.h"



Colore::Colore(){
	dt = 0.05;
}

void Colore::begin(uint16_t leds, Segment *segments, byte segLen, Beam *beams, byte beamAm, void (*_setPixel)(int pixel, byte, byte, byte), Color (*_getPixel)(int), void (*_showPixels)()){
	totLedAm = leds;
	segArray = segments;
	segArray_len = segLen;
	
	beamControl.begin(beams, beamAm);
	neural.begin(&beamControl);
	
	setPixel = _setPixel;
	getPixel = _getPixel;
	showPixels = _showPixels;

}

void Colore::update(){
	calcDt();
	
	for(int i=0; i<totLedAm; i++){
		setPixel(i,0,0,0);
	}

	for(int i=0; i<segArray_len; i++){
		segArray[i].move(dt);
		segArray[i].draw(setPixel,getPixel);
	}

	for(int i=0; i<beamControl.beamArray_len; i++){
		beamControl.beamArray[i].move(dt);
		if ( beamControl.beamArray[i].isNeuralMode() ){
			if( beamControl.beamArray[i].justArrived() ){
				neural.arriveBeam( &beamControl.beamArray[i] );
			}
		}
		beamControl.beamArray[i].draw(setPixel,getPixel);
	}

	showPixels();
}

void Colore::calcDt(){
	dt = (micros() - lastCalc) / 1000000.;  // assume one frame per second
	lastCalc = micros();
}

float Colore::getDt(){
	return dt;
}

boolean Colore::addBeam(Segment *seg, boolean dir, float spd, byte spdMode, float len, Color col){
	Beam* newBeam = beamControl.freeBeam();
	if(newBeam == NULL) return false;
	newBeam->begin(seg, dir, spd, spdMode, len, col, PULSE);
	return true;
}

boolean Colore::lightUp(Segment *seg, float spd, Color col){
	Beam* newBeam = beamControl.freeBeam();
	if(newBeam == NULL) return false;
	newBeam->begin(seg, false, spd, SEGMENT_SPD, 0, col, FLASH);
	return true;
}