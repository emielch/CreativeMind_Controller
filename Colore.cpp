/*
Colore.cpp - Library for saving colors
Created by Emiel Harmsen 14-1-2015.
*/

#include "Arduino.h"
#include "Colore.h"



Colore::Colore(uint16_t leds, Segment *segments, byte segLen, Beam *beamArray, byte beamAm, void (*_setPixel)(int pixel, byte, byte, byte), Color (*_getPixel)(int), void (*_showPixels)(), void (*_resetPixels)()){
	dt = 0.05;
	totLedAm = leds;
	segArray = segments;
	segArray_len = segLen;
	
	beamControl.begin(beamArray,beamAm);
	neural.begin(&beamControl);
	
	setPixel = _setPixel;
	getPixel = _getPixel;
	showPixels = _showPixels;
	resetPixels = _resetPixels;
}

void Colore::update(){
	calcDt();
	
	resetPixels();

	for(int i=0; i<segArray_len; i++){
		segArray[i].move(dt);
		segArray[i].draw(setPixel,getPixel);
	}

	for(int i=0; i<beamControl.beamArray_len; i++){
		if( beamControl.beamArray[i].isActive() ){
			beamControl.beamArray[i].move(dt);
			if ( beamControl.beamArray[i].isNeuralMode() ){
				if( beamControl.beamArray[i].justArrived() ){
					neural.arriveBeam( &beamControl.beamArray[i] );
				}
			}
			beamControl.beamArray[i].draw(setPixel,getPixel);
		}
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