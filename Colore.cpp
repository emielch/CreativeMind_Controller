/*
Colore.cpp - Library for saving colors
Created by Emiel Harmsen 14-1-2015.
*/

#include "Arduino.h"
#include "Colore.h"



Colore::Colore(){
	dt = 0.05;
}

void Colore::begin(uint16_t leds, Segment **segments, byte segLen, byte beamAm, void (*_setPixel)(int pixel, byte, byte, byte), Color (*_getPixel)(int), void (*_showPixels)()){
	totLedAm = leds;
	segArray = segments;
	segArray_len = segLen;
	
	beamArray_len = beamAm;
	Beam beams[beamArray_len];
	beamArray = beams;
	
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
		segArray[i]->move(dt);
		segArray[i]->draw(setPixel,getPixel);
	}
	
	for(int i=0; i<beamArray_len; i++){
		beamArray[i].move(dt);
		beamArray[i].draw(setPixel,getPixel);
	}
	showPixels();
}

void Colore::calcDt(){
	dt = (micros() - lastCalc) / 1000000.;  // assume one frame per second
	lastCalc = micros();
}

boolean Colore::addBeam(Segment *seg, boolean dir, float spd, float len, Color col){
	for(int i=0; i<beamArray_len; i++){
		if( !beamArray[i].isActive() ){
			beamArray[i].begin(seg, dir, spd, len, col, false);
			return true;
		}
		return false;
	}
}

boolean Colore::lightUp(Segment *seg, float spd, Color col){
	for(int i=0; i<beamArray_len; i++){
		if( !beamArray[i].isActive() ){
			beamArray[i].begin(seg, false, 0, 0, col,true);
			return true;
		}
		return false;
	}
}