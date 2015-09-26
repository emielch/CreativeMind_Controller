// ---- led segment ----

#ifndef Segment_h
#define Segment_h

#include "Arduino.h"
#include "Color.h"

#define BLACK 0
#define STATIC 1
#define RAINBOW 2
#define GRADIENT 3
#define SINES 4
#define FADE 5
#define FADEINOUT 6

#define NEURON 0
#define SYNAPSE 1


class Segment{
	public:
		Segment(int, uint16_t*);
		void setNN(boolean _nnType, int _connAm, Segment **_connSeg);
		void draw(void (*setPixel)(int pixel, byte, byte, byte), Color (*getPixel)(int));
		void move(float dt);
		uint16_t getLen(){return segLen;}
		uint16_t getPixelID(int i){return ledArray[i];}
		void setRainbow(float spd, float len, byte bri);
		void setStaticColor(Color c);
		void setSines(Color c, float spd);
		void setFade(Color c, float spd);
		void setFadeInOut(Color c, float inSpd, float outSpd);
		void setGradient(Color c1, Color c2);
		Color getCurrentColor();
		
		//-- NN
		Segment **connSeg;  // neurons are connected to multiple synapses, synapses to two neurons
		byte connAm;
		boolean nnType;  // NEURON or SYNAPSE
		
	private:
		uint16_t segLen;  // segment length
		uint16_t *ledArray;  // LUT for converting segment pixel ID's to strip pixel ID's
		byte effectID;

		//-- effect parameters --
		float e_spd;
		float e_outSpd;
		float e_pos;
		float e_len;
		byte e_bri;
		Color e_color;
		Color e_fromColor;
		Color e_toColor;
		//---
};

#endif