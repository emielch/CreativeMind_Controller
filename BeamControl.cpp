#include "Arduino.h"
#include "BeamControl.h"


BeamControl::BeamControl(){
}

void BeamControl::begin(Beam *_beamArray, byte beamAm, void (*_setPixel)(int pixel, byte, byte, byte), Color (*_getPixel)(int)){
	beamArray = _beamArray;
	beamArray_len = beamAm;
	
	setPixel = _setPixel;
	getPixel = _getPixel;
}

void BeamControl::update(float dt){
	for(int i=0; i<beamArray_len; i++){
		if( beamArray[i].isActive() ){
			beamArray[i].move(dt);
			beamArray[i].draw(setPixel,getPixel);
		}
	}
}

Beam* BeamControl::freeBeam(){
	for(int i=0; i<beamArray_len; i++){
		if( !beamArray[i].isActive() ){
			return &beamArray[i];
		}
	}
	return NULL;
}