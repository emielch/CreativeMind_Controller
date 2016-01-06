#include <Colore.h>
#include "config.h"
#include "netLayout.h"
#include "LUT.h"
#include <OctoWS2811.h>
#include "ledLibSetup.h"

#define BEAM_AM 300
Beam beams[BEAM_AM];

byte segAm = sizeof(seg)/sizeof(Segment);
Colore colore( LED_AM, seg, segAm, beams, BEAM_AM, &set_ledLib, &get_ledLib, &show_ledLib, &reset_ledLib );

void setup() {
  Serial.begin(9600);
  delay(500);
  beginButtons();
  pinMode(statusLedPin, OUTPUT);
  setNN();
  colore.beginNN(beamDecay, neuronChargeFac, DCSpd, DCPower, DCSpread, DCSpdMode, fadeInSpd, fadeOutSpd, allowDirectSynapse);
  leds.begin();
  
  printFreeRam();
  bootAnimation();

  Color white(255,255,255,RGB_MODE);
  seg[75].setSines(white,1);
}


void loop() {
  checkSerial();
  colore.update(true);
  printFramerate();
  blinkLED();
  checkButtons();
  newRandomBeam();

//  float speedFactor = constrain(mapFloat(colore.getActiveBeamsAm(),0,200,1,0.1),0.1,1);
//  Serial.println(speedFactor);
//  colore.setSpdFac(speedFactor);
}

void blinkLED(){
  if(millis()%1000>500) digitalWrite(statusLedPin,HIGH);
  else digitalWrite(statusLedPin,LOW);
}

void printFramerate(){
  Serial.print("FrameRate: ");
  Serial.println(colore.getFPS()); // print framerate
}

void printFreeRam(){
  Serial.print("Free RAM: ");
  Serial.println(FreeRam());
}

float mapFloat(float value, float low1, float high1, float low2, float high2){
  return low2 + (high2 - low2) * (value - low1) / (high1 - low1);
}

