#include "Arduino.h"
#include "Segment.h"


Segment::Segment(int len, uint16_t *_ledArray){
	segLen = len;
	ledArray = _ledArray;
	effectID = 0;  // no effect on segment
	e_spd = 0;
	e_pos = 0;
	e_len = 0;

	// allocate memory
	/*if((ledArray = (uint16_t *)malloc(segLen*2))) {  // times 2 because of uint16_t being 2 bytes
		memset(ledArray, 0, segLen*2);  // fill array with 0;
	}*/
}

void Segment::setRainbow(float spd, float len, byte bri){
	effectID = RAINBOW;
	e_spd = spd;
	e_pos = 0;
	e_len = len;
	e_bri = bri;
}

void Segment::setStaticColor(Color c){
	effectID = STATIC;
	e_color = c;
}

void Segment::setSines(Color c, float spd){
	if(effectID != SINES) e_pos = 0;
	effectID = SINES;
	e_color = c;
	e_spd = spd;
}

void Segment::draw(void (*setPixel)(int pixel, byte, byte, byte), Color (*getPixel)(int)){
	if(effectID == RAINBOW){
		Color rainCol;
		for(int i=0; i<segLen; i++){
			rainCol.setHSB( e_pos+i*(10/e_len), 100, e_bri);
			rainCol.add(getPixel(getPixelID(i)),1);
			setPixel( getPixelID(i), rainCol.red(), rainCol.green(), rainCol.blue() );
		}
	}else if(effectID == STATIC){
		for(int i=0; i<segLen; i++){
			Color prevCol = getPixel(getPixelID(i));
			prevCol.add(e_color,1);
			setPixel( getPixelID(i), prevCol.red(), prevCol.green(), prevCol.blue() );
		}
	}else if(effectID == SINES){
		for(int i=0; i<segLen; i++){
			Color prevCol = getPixel(getPixelID(i));
			float multi = (sin(i*0.5 + e_pos)+1) * (sin(i*0.3 + e_pos*-1.2)+1) /4 * 0.7 + 0.3;
			Color sineCol(e_color.hue(), e_color.saturation(), e_color.brightness()*multi, HSB_MODE);
			
			prevCol.add(sineCol,1);
			setPixel( getPixelID(i), prevCol.red(), prevCol.green(), prevCol.blue() );
		}
	}
}

void Segment::move(float dt){
	if(effectID == SINES){
		e_pos += e_spd*dt;
	}else if(effectID == RAINBOW){
		e_pos += e_spd*dt;
	}
}