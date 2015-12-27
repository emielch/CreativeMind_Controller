#include "Arduino.h"
#include "Segment.h"


Segment::Segment(int _segLen, uint16_t *_ledArray){
	segLen = _segLen;
	ledArray = _ledArray;
	ledDefMode = COMPLETE;
	
	blendMode = ADD;
	effectID = 0;  // no effect on segment
	e_spd = 0;
	e_pos = 0;
	e_len = 0;
}

Segment::Segment(uint16_t _startLed, uint16_t _endLed){
	startLed = _startLed;
	ledDefMode = STARTEND;
	
	segLen = _endLed - _startLed + 1;
	
	blendMode = ADD;
	effectID = 0;  // no effect on segment
	e_spd = 0;
	e_pos = 0;
	e_len = 0;
}

void Segment::setBlendMode(int _blendMode){
	blendMode = _blendMode;
}

uint16_t Segment::getPixelID(uint16_t i){
	if(ledDefMode == STARTEND){
		return startLed + i;
	}
	return ledArray[i];
}

void Segment::setNN(boolean _nnType, int _connAm, Segment **_connSeg){
	nnType = _nnType;
	connAm = _connAm;
	connSeg = _connSeg;
}

void Segment::setRainbow(float spd, float len, byte bri){
	if(effectID != RAINBOW) e_pos = 0;
	effectID = RAINBOW;
	e_spd = spd*360;
	e_len = len;
	e_bri = bri;
}

void Segment::setStaticColor(Color c){
	e_color = c;
	if(c.brightness() == 0){
		effectID = BLACK;
		return;
	}
	effectID = STATIC;
}

void Segment::setSines(Color c, float spd){
	if(effectID != SINES) e_pos = 0;
	effectID = SINES;
	e_color = c;
	e_spd = spd;
}

void Segment::setFade(Color c, float spd){
	effectID = FADE;
	e_toColor = c;
	e_fromColor = e_color;
	e_spd = spd;
	e_pos = 0;
}

void Segment::setFadeInOut(Color cIn, Color cOut, float inSpd, float outSpd){
	effectID = FADEINOUT;
	e_toColor = cIn;
	e_outColor = cOut;
	e_fromColor = e_color;
	e_spd = inSpd;
	e_outSpd = outSpd;
	e_pos = 0;
}

void Segment::setGradient(Color c1, Color c2){
	effectID = GRADIENT;
	e_fromColor = c1;
	e_toColor = c2;
}

void Segment::setWipe(Color c, float spd, boolean dir, float fadeLen, float accel){
	e_outSpd = constrain(accel,-0.99,0.99);
	if(!dir) e_outSpd = -e_outSpd;
	e_len = fadeLen;
	
	if(effectID == WIPE){   // if the current effect is already a wipe
		boolean currDir = e_spd > 0;
		if(currDir != dir) e_fromColor = e_color;
		e_color = c;
		if(dir) e_spd = spd;
		else e_spd = -spd;
	}else{
		effectID = WIPE;
		e_fromColor = e_color;
		e_color = c;
		if(dir){
			e_spd = spd;
			e_pos = 0;
		}else{
			e_spd = -spd;
			e_pos = 1;
		}
	}
}

Color Segment::getCurrentColor(){
	return e_color;
}

void Segment::move(float dt){
	switch (effectID) {
		case SINES:{
			e_pos += e_spd*dt;
			break;
		}
		case RAINBOW:{
			e_pos += e_spd*dt;
			break;
		}
		case FADE:{
			e_pos += e_spd*dt;
			if(e_pos >= 1){
				setStaticColor(e_toColor);
			}
			break;
		}
		case FADEINOUT:{
			e_pos +=  ((e_pos <= 1) ? e_spd : e_outSpd) * dt;
			if(e_pos >= 2){
				setStaticColor(e_outColor);
			}
			break;
		}
		case WIPE:{
			float spdBoost = e_spd;
			if(e_outSpd>0){
				spdBoost = (1-e_pos)*e_spd*(e_outSpd) + e_spd*(1-e_outSpd);
			}else if(e_outSpd<0){
				spdBoost = e_pos*e_spd*(-e_outSpd) + e_spd*(1-(-e_outSpd));
			}
			e_pos += spdBoost*dt;
			if(e_pos >= 1 || e_pos <= 0){
				setStaticColor(e_color);
			}
			break;
		}
		default:{
			
		}
		break;
	}
}

void Segment::draw(void (*setPixel)(int pixel, byte, byte, byte), Color (*getPixel)(int)){
	switch (effectID) {
		
		case BLACK:{
			e_color.setRGB(0,0,0);
			for(int i=0; i<segLen; i++){
				blendSetPixel(i,e_color,setPixel,getPixel);
			}
			break;
		}
		
		case SINES:{
			for(int i=0; i<segLen; i++){
				float multi = (sin(i*0.5 + e_pos)+1) * (sin(i*0.3 + e_pos*-1.2)+1) /4 * 0.7 + 0.3;
				Color sineCol(e_color.hue(), e_color.saturation(), e_color.brightness()*multi, HSB_MODE);
				
				blendSetPixel(i,sineCol,setPixel,getPixel);
			}
			break;
		}
			
		case RAINBOW:{
			Color rainCol;
			for(int i=0; i<segLen; i++){
				rainCol.setHSB( e_pos+i*(10/e_len), 100, e_bri);
				blendSetPixel(i,rainCol,setPixel,getPixel);
			}
			break;
		}
			
		case STATIC:{
			for(int i=0; i<segLen; i++){
				blendSetPixel(i,e_color,setPixel,getPixel);
			}
			break;
		}
		
		case FADE: case FADEINOUT:{
			if( e_pos <= 1 ){
				e_color.fade(e_fromColor, e_toColor, e_pos);
			}else{
				e_color.fade(e_toColor, e_outColor, e_pos-1);
			}
			for(int i=0; i<segLen; i++){
				blendSetPixel(i,e_color,setPixel,getPixel);
			}
			break;
		}
		
		case GRADIENT:{
			for(int i=0; i<segLen; i++){
				float fade = i*1./(segLen-1);
				e_color.fade(e_fromColor, e_toColor, fade);
				
				blendSetPixel(i,e_color,setPixel,getPixel);
			}
			break;
		}
		
		case WIPE:{
			boolean dir = e_spd > 0;
			float endLed = (segLen+e_len) * e_pos;
			float startLed = endLed - e_len;
			Color wipeCol;
			for(int i=startLed; i<=endLed; i++){
				if(i>=0 && i<segLen){
					float dist = constrain((i-startLed)/e_len,0,1);
					if(!dir) dist = 1-dist;
					wipeCol.fade(e_color,e_fromColor,dist);
					blendSetPixel(i,wipeCol,setPixel,getPixel);
				}
			}
			for(int i=endLed+1; i<segLen; i++){
				if(dir) blendSetPixel(i,e_fromColor,setPixel,getPixel);
				else blendSetPixel(i,e_color,setPixel,getPixel);
			}
			for(int i=0; i<startLed-1; i++){
				if(dir) blendSetPixel(i,e_color,setPixel,getPixel);
				else blendSetPixel(i,e_fromColor,setPixel,getPixel);
			}
			break;
		}
			
		default:{
		}
					
		break;
	}
}

void Segment::blendSetPixel(int segPixel, Color c, void (*setPixel)(int pixel, byte, byte, byte), Color (*getPixel)(int)){
	int pixelID = getPixelID(segPixel);
	Color prevCol = getPixel(pixelID);
	
	if(blendMode == ADD) c.add(prevCol,1);
	else if(blendMode == MULTIPLY) c.multiply(prevCol,1);
	
	setPixel( pixelID, c.red(), c.green(), c.blue() );
}



