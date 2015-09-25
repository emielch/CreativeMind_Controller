// ---- Beam effect ----

#ifndef Beam_h
#define Beam_h

#include "Arduino.h"
#include "Segment.h"

#define PIXEL_SPD 0
#define SEGMENT_SPD 1

class Beam{
	public:
		Beam();
		void begin(Segment *seg, boolean dirUp, float spd, byte spdMode, float len, Color col, boolean lightUp);
		boolean move(float dt);
		void draw(void (*setPixel)(int pixel, byte, byte, byte), Color (*getPixel)(int));
		boolean isActive();
		
	private:
		boolean lightUpMode;
		float posFactor;
		float startFac;
		float endFac;
		float speed;
		float spread;
		Color color;
		Segment *onSegment;
		boolean active;
};

#endif