/*
Colore.cpp - Library for saving colors
Created by Emiel Harmsen 14-1-2015.
*/

#include "Arduino.h"
#include "Colore.h"



void Colore::calcDt(){
	dt = (micros() - lastCalc) / 1000000.;
	lastCalc = micros();
}


Colore::Colore(){
	dt = 0.05;
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
	show();
}

void Colore::begin(uint16_t leds, Segment **segments, byte segLen, Beam *beams, byte beamLen, void (*_setPixel)(int pixel, byte, byte, byte), Color (*_getPixel)(int), void (*_show)()){
	totLedAm = leds;
	segArray = segments;
	segArray_len = segLen;
	beamArray = beams;
	beamArray_len = beamLen;
	setPixel = _setPixel;
	getPixel = _getPixel;
	show = _show;
}

boolean Colore::addBeam(Segment *seg, boolean dir, float spd, float len, Color col){
	for(int i=0; i<beamArray_len; i++){
		if( !beamArray[i].active ){
			beamArray[i].begin(seg, dir, spd, len, col, false);
			return true;
		}
		return false;
	}
}

boolean Colore::lightUp(Segment *seg, float spd, Color col){
	for(int i=0; i<beamArray_len; i++){
		if( !beamArray[i].active ){
			beamArray[i].begin(seg, false, 0, 0, col,true);
			return true;
		}
		return false;
	}
}