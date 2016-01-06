// ---- led segment ----

#ifndef Segment_h
#define Segment_h

#include "Arduino.h"
#include "Color.h"
#include "Beam.h"
#include "BeamControl.h"

#define BLACK 0
#define STATIC 1
#define RAINBOW 2
#define GRADIENT 3
#define SINES 4
#define FADE 5
#define FADEINOUT 6
#define WIPE 7
#define WHITE 8

#define NEURON 0
#define SYNAPSE 1

#define COMPLETE 0
#define STARTEND 1

#define ADD 0
#define MULTIPLY 1

class BeamControl; // forward declaration
class Beam;

class Segment{
	public:
		Segment(int _segLen, uint16_t *_ledArray);
		Segment(uint16_t startLed, uint16_t endLed);
		void setBlendMode(int _blendMode);
		void setNN(boolean _nnType, int _connAm, Segment **_connSeg);
		void draw(void (*setPixel)(int pixel, byte, byte, byte), Color (*getPixel)(int));
		void move(float dt);
		uint16_t getLen(){return segLen;}
		uint16_t getPixelID(uint16_t i);
		void setRainbow(float spd, float len, byte bri);
		void setStaticColor(Color c);
		void setStaticBlack();
		void setStaticWhite();
		void setSines(Color c, float spd);
		void setFade(Color c, float spd);
		void setFadeInOut(Color cIn, Color cOut, float inSpd, float outSpd);
		void setGradient(Color c1, Color c2);
		void setWipe(Color c, float spd, boolean dir, float fadeLen, float accel);
		Color getCurrentColor();
		
		void setBeamControl(BeamControl *_beamControl);
		boolean setBeam(boolean dir, float spd, byte spdMode, float len, Color col);
		boolean setNNBeam(boolean dir, float spd, byte spdMode, float len, Color col, int power);
		
		
		//-- NN
		Segment **connSeg;  // neurons are connected to multiple synapses, synapses to two neurons
		byte connAm;
		boolean nnType;  // NEURON or SYNAPSE
		
		byte power = 0;
		
	private:
		boolean ledDefMode;
		uint16_t segLen;  // segment length
		uint16_t *ledArray;  // LUT for converting segment pixel ID's to strip pixel ID's
		uint16_t startLed;
		byte effectID;
		
		int blendMode;
		void blendSetPixel(int segPixel, Color c, void (*setPixel)(int pixel, byte, byte, byte), Color (*getPixel)(int));
		
		void addBeam(Beam* beam);

		//-- effect parameters --
		float e_spd;
		float e_outSpd;
		float e_pos;
		float e_len;
		byte e_bri;
		Color e_color;
		Color e_fromColor;
		Color e_toColor;
		Color e_outColor;
		//---
		
		BeamControl *beamControl;
		Beam *beamAnchor; // linked list anchor
		
		void updateBeams(float dt);
		void drawBeams(void (*setPixel)(int pixel, byte, byte, byte), Color (*getPixel)(int));
};

#endif