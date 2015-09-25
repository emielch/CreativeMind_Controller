// ---- led segment ----

#ifndef Segment_h
#define Segment_h

#include "Arduino.h"
#include "Color.h"

#define BLACK 0
#define SINES 4
#define RAINBOW 2
#define STATIC 3

class Segment{
	public:
		Segment(int, uint16_t*);
		void draw(void (*setPixel)(int pixel, byte, byte, byte), Color (*getPixel)(int));
		void move(float dt);
		uint16_t getLen(){return segLen;}
		uint16_t getPixelID(int i){return ledArray[i];}
		void setRainbow(float spd, float len, byte bri);
		void setStaticColor(Color c);
		void setSines(Color c, float spd);
		
	private:
		uint16_t segLen;  // segment length
		uint16_t *ledArray;  // LUT for converting segment pixel ID's to strip pixel ID's
		byte effectID;

		//-- effect parameters --
		float e_spd;
		float e_pos;
		float e_len;
		byte e_bri;
		Color e_color;
		//---
};

#endif