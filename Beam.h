// ---- Beam effect ----

#ifndef Beam_h
#define Beam_h

#include "Arduino.h"
#include "Segment.h"

class Beam{
	public:
		Beam(){};
		void begin(Segment *seg, boolean dirUp, float spd, float len, Color col, boolean lightUp);
		boolean move(float dt);
		void draw(void (*setPixel)(int pixel, byte, byte, byte), Color (*getPixel)(int));
		boolean isActive();
		
	private:
		boolean lightUpMode;
		float posFactor;
		float speed;
		float spread;
		Color color;
		Segment *onSegment;
		boolean active;
};

#endif