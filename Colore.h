/*
Colore.h - Library for saving colors
Created by Emiel Harmsen 14-1-2015.
*/

#ifndef Colore_h
#define Colore_h

#include "Arduino.h"

#define RGB_MODE 0
#define HSB_MODE 1

#define BLACK 0
#define SINES 4
#define RAINBOW 2
#define STATIC 3

// ---- color stuff ----


struct RGB {
  byte r;
  byte g;
  byte b;
};

struct HSB {
  int h;  // 360
  byte s;  // 100
  byte b;  // 100
};

class Color {
	public:
		Color();
		Color(int v1, byte v2, byte v3, byte mode);
		
		void setRGB(byte r, byte g, byte b);
		void setHSB(int h, byte s, byte b);
		
		byte red();
		byte green();
		byte blue();
		int hue();
		byte saturation();
		byte brightness();
		
		void add(Color toAdd, float fade){
			if(fade!=0.){
				byte r = constrain(red() + toAdd.red()*fade, 0,255);
				byte g = constrain(green() + toAdd.green()*fade, 0,255);
				byte b = constrain(blue() + toAdd.blue()*fade, 0,255);
				
				setRGB(r,g,b);
			}
		};
	
	private:
		RGB RGB_color;
		HSB HSB_color;
		boolean RGB_updated;
		boolean HSB_updated;
		
		HSB RGBtoHSB(RGB *color);
		RGB HSBtoRGB(HSB *color);
		
		void updateHSB();
		void updateRGB();
};



// ---- led segment ----

class Segment{
	public:
		Segment(int, uint16_t*);
		uint16_t getLen(){return segLen;}
		uint16_t getPixelID(int i){return ledArray[i];}
		void setRainbow(float spd, float len, byte bri){
			effectID = RAINBOW;
			e_spd = spd;
			e_pos = 0;
			e_len = len;
			e_bri = bri;
		}
		void setStaticColor(Color c){
			effectID = STATIC;
			e_color = c;
		}
		void setSines(Color c, float spd){
			if(effectID != SINES) e_pos = 0;
			effectID = SINES;
			e_color = c;
			e_spd = spd;
		}
		
		void draw(void (*setPixel)(int pixel, byte, byte, byte), Color (*getPixel)(int)){
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
		
		void move(){
			if(effectID == SINES){
				e_pos += e_spd;
			}else if(effectID == RAINBOW){
				e_pos += e_spd;
			}
		}
		
	private:
		uint16_t segLen;  // segment length
		uint16_t *ledArray;  // LUT for converting segment pixel ID's to strip pixel ID's
		byte effectID;

		float e_spd;
		float e_pos;
		float e_len;
		byte e_bri;
		Color e_color;
		
};


// ---- Beam effect ----

class Beam{
	public:
		Beam(){};
		void begin(Segment *seg, boolean dirUp, float spd, float len, Color col){
			active = true;
			onSegment = seg;
			spread = len;
			color = col;
			if(dirUp){
				position = 0 - spread/2;
				speed = spd;
			}else{
				position = onSegment->getLen() + spread/2;
				speed = -spd;
			}
		}
		
		boolean move(){
			if(active){
				position += speed;
				uint16_t segLen = onSegment->getLen();
				if( position>segLen+spread/2 || position<0-spread/2 ){
					active = false;
					return false;
				}else{
					return true;
				}
			}
		}
		
		void draw(void (*setPixel)(int pixel, byte, byte, byte), Color (*getPixel)(int)){
			if(active){
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
		
		boolean active;
		
	private:
		float position;
		float speed;
		float spread;
		Color color;
		Segment *onSegment;
};


// --- main class, controlling library etc. ---

class Colore{
	private:
		uint16_t totLedAm;
		Segment **segArray;
		byte segArray_len;
		Beam *beamArray;
		byte beamArray_len;
		void (*setPixel)(int pixel, byte r, byte g, byte b);
		void (*show)();
		Color (*getPixel)(int);
		
	public:
		Colore(){};
		void update(){
			for(int i=0; i<totLedAm; i++){
				setPixel(i,0,0,0);
			}
			
			for(int i=0; i<segArray_len; i++){
				segArray[i]->move();
				segArray[i]->draw(setPixel,getPixel);
			}
			
			for(int i=0; i<beamArray_len; i++){
				beamArray[i].move();
				beamArray[i].draw(setPixel,getPixel);
			}
			show();
		}
		
		void begin(uint16_t leds, Segment **segments, byte segLen, Beam *beams, byte beamLen, void (*_setPixel)(int pixel, byte, byte, byte), Color (*_getPixel)(int), void (*_show)()){
			totLedAm = leds;
			segArray = segments;
			segArray_len = segLen;
			beamArray = beams;
			beamArray_len = beamLen;
			setPixel = _setPixel;
			getPixel = _getPixel;
			show = _show;
		}
		
		boolean addBeam(Segment *seg, boolean dir, float spd, float len, Color col){
			for(int i=0; i<beamArray_len; i++){
				if( !beamArray[i].active ){
					beamArray[i].begin(seg, dir, spd, len, col);
					break;
				}
			}
		}
};


#endif