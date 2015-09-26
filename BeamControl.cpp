#include "Arduino.h"
#include "BeamControl.h"


BeamControl::BeamControl(){
}

void BeamControl::begin(byte beamAm){
	uint16_t numBytes = beamAm * sizeof(Beam);

	if((beamArray = (Beam *)malloc(numBytes))) {
		memset(beamArray, 0, numBytes);
		beamArray_len = beamAm;
	} else {
		beamAm = numBytes = 0;
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