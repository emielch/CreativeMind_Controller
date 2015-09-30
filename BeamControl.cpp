#include "Arduino.h"
#include "BeamControl.h"


BeamControl::BeamControl(){
}

void BeamControl::begin(Beam *beams, byte beamAm){
	beamArray = beams;
	beamArray_len = beamAm;
}


Beam* BeamControl::freeBeam(){
	for(int i=0; i<beamArray_len; i++){
		if( !beamArray[i].isActive() ){
			return &beamArray[i];
		}
	}
	return NULL;
}