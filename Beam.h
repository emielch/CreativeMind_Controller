// ---- Beam effect ----

#ifndef Beam_h
#define Beam_h

#include "Arduino.h"
#include "Segment.h"

#define PIXEL_SPD 0
#define SEGMENT_SPD 1

#define PULSE 0
#define FLASH 1
#define NEURAL 2

#define UP 0
#define DOWN 1


class Beam{
	public:
		Beam();
		void begin(Segment *seg, boolean dir, float spd, byte spdMode, float len, Color col, byte _mode);
		void begin(Segment *seg, boolean dir, float spd, byte spdMode, float len, Color col, byte _mode, int _power);
		void move(float dt);
		void draw(void (*setPixel)(int pixel, byte, byte, byte), Color (*getPixel)(int));
		boolean isActive();
		boolean justArrived();
		void arrive();
		boolean isNeuralMode();
		
		float segSpd;
		float pixelSpd;
		boolean dir; // UP or DOWN
		float spread;
		Color color;
		Segment *onSegment;
		byte spdMode;
		
		//-- NN
		int power;
		boolean arrived;
		
	private:
		boolean active;
		byte mode;
		float posFactor;
		float startFac;
		float endFac;
		float spreadFac;
};

#endif