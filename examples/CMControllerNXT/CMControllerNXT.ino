#include <Colore.h>
#include "netLayout.h"
#include "LUT.h"
#include <OctoWS2811.h>
#include "ledLibSetup.h"

#define BEAM_AM 100
Beam beams[BEAM_AM];

Colore colore;

unsigned long nextBeam = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  leds.begin();
  setNN();
  byte segAm = sizeof(seg)/4;
  colore.begin(LED_AM, seg, segAm, beams, BEAM_AM, &set_ledLib, &get_ledLib, &show_ledLib );
  delay(500);
  Serial.print("Free RAM: ");
  Serial.println(FreeRam());
}


void loop() {
  colore.update();
  Serial.print("FrameRate: ");
  Serial.println(1/colore.getDt()); // print framerate
  blinkLED();
  newBeam();
}




void blinkLED(){
  if(millis()%1000>500) digitalWrite(13,HIGH);
  else digitalWrite(13,LOW);
}

void newBeam(){
  if(millis()>nextBeam){
    Color c1(random(0,360), 100, 100, HSB_MODE);
    colore.neural.startNeuronBeam(&seg[random(0,6)], NULL, 70, PIXEL_SPD, 10, c1, 200);
    nextBeam = millis()+1000;
  }
}

