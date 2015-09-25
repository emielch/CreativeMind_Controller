#include "Arduino.h"
#include "Segment.h"


Segment::Segment(int len, uint16_t *_ledArray){
	segLen = len;
	ledArray = _ledArray;
	effectID = 0;  // no effect on segment
	e_spd = 0;
	e_pos = 0;
	e_len = 0;
}

void Segment::setRainbow(float spd, float len, byte bri){
	if(effectID != RAINBOW) e_pos = 0;
	effectID = RAINBOW;
	e_spd = spd;
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

void Segment::setFade(Color c, float spd){
	effectID = FADE;
	e_toColor = c;
	e_fromColor = e_color;
	e_spd = spd;
	e_pos = 0;
}

void Segment::setGradient(Color c1, Color c2){
	effectID = GRADIENT;
	e_fromColor = c1;
	e_toColor = c2;
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
		default:{
			
		}
		break;
	}
}

void Segment::draw(void (*setPixel)(int pixel, byte, byte, byte), Color (*getPixel)(int)){
	switch (effectID) {
		
		case SINES:{
			for(int i=0; i<segLen; i++){
				Color prevCol = getPixel(getPixelID(i));
				float multi = (sin(i*0.5 + e_pos)+1) * (sin(i*0.3 + e_pos*-1.2)+1) /4 * 0.7 + 0.3;
				Color sineCol(e_color.hue(), e_color.saturation(), e_color.brightness()*multi, HSB_MODE);
				
				prevCol.add(sineCol,1);
				setPixel( getPixelID(i), prevCol.red(), prevCol.green(), prevCol.blue() );
			}
			break;
		}
			
		case RAINBOW:{
			Color rainCol;
			for(int i=0; i<segLen; i++){
				rainCol.setHSB( e_pos+i*(10/e_len), 100, e_bri);
				rainCol.add(getPixel(getPixelID(i)),1);
				setPixel( getPixelID(i), rainCol.red(), rainCol.green(), rainCol.blue() );
			}
			break;
		}
			
		case STATIC:{
			for(int i=0; i<segLen; i++){
				Color prevCol = getPixel(getPixelID(i));
				prevCol.add(e_color,1);
				setPixel( getPixelID(i), prevCol.red(), prevCol.green(), prevCol.blue() );
			}
			break;
		}
		
		case FADE:{
			e_color.fade(e_fromColor, e_toColor, e_pos);
			for(int i=0; i<segLen; i++){
				Color prevCol = getPixel(getPixelID(i));
				prevCol.add(e_color,1);
				setPixel( getPixelID(i), prevCol.red(), prevCol.green(), prevCol.blue() );
			}
			break;
		}
		
		case GRADIENT:{
			for(int i=0; i<segLen; i++){
				float fade = i*1./(segLen-1);
				e_color.fade(e_fromColor, e_toColor, fade);
				
				Color prevCol = getPixel(getPixelID(i));
				prevCol.add(e_color,1);
				setPixel( getPixelID(i), prevCol.red(), prevCol.green(), prevCol.blue() );
			}
			break;
		}
			
		default:{
		}
					
		break;
	}
}

