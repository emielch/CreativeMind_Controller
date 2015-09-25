#include "Arduino.h"
#include "Beam.h"


Beam::Beam(){
	active = false;
}

void Beam::begin(Segment *seg, boolean dirUp, float spd, byte spdMode, float len, Color col, boolean lightUp){    // speed in pixels/sec or segment/sec
	active = true;
	lightUpMode = lightUp;
	onSegment = seg;
	spread = len;
	color = col;
	int seglen = onSegment->getLen();
	
	if (spdMode==PIXEL_SPD){
		speed = spd / seglen;
	}
	else if(spdMode==SEGMENT_SPD){
		speed = spd;
	}
	
	startFac = 0 - (spread/2)/seglen;
	endFac = 1 + (spread/2)/seglen;
	
	posFactor = startFac;
	if(!dirUp){
		posFactor = endFac;
		speed *= -1;
	}
}

boolean Beam::move(float dt){
	if(active){
		posFactor += speed*dt;
		if( posFactor>endFac || posFactor<startFac ){
			active = false;
			return false;
		}else{
			return true;
		}
	}
	return false;
}

void Beam::draw(void (*setPixel)(int pixel, byte, byte, byte), Color (*getPixel)(int)){
	if(active){
		if(lightUpMode){
			float bri;
			if(posFactor<0.5){
				bri = posFactor*2;
			}else{
				bri = 1 - (posFactor*2 - 1);
			}
			for(int i=0; i<=onSegment->getLen(); i++){
				int pixelID = onSegment->getPixelID(i);
				Color prevCol = getPixel(pixelID);
				prevCol.add(color,bri);
				setPixel(pixelID, prevCol.red(), prevCol.green(), prevCol.blue());
			}
		}else{
			float position = posFactor * onSegment->getLen();
			int startLed = position - spread/2;
			int endLed = position + spread/2;
			
			for(int i=startLed; i<=endLed; i++){
				if( i>=0 && i<onSegment->getLen() ){
					int pixelID = onSegment->getPixelID(i);
					float dist = constrain(1-abs(i-position)/spread*2, 0, 1);
					Color prevCol = getPixel(pixelID);
					prevCol.add(color,dist);
					setPixel(pixelID, prevCol.red(), prevCol.green(), prevCol.blue());
				}
			}
		}
	}
}

boolean Beam::isActive(){
	return active;
}