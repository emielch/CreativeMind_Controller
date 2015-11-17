
struct BUTTON{
  byte pin;
  Segment *startSeg;
  int hue;
  unsigned int lastPush;
};


BUTTON buttons[] = {
  {23,&seg[10],0},
  {22,&seg[19],120},
  {19,&seg[26],240},
  {18,&seg[15],60}
};

unsigned long nextBeamTime = 0;
byte buttonAm = sizeof(buttons)/sizeof(BUTTON);

int pushDelay = 150;
int beamMinDelay = 2000;  /// delay for generating a new beam
int beamMaxDelay = 10000;
int buttonWaitTime = 15000;  // the wait time after pressing a button after which a new random beam can be started

void beginButtons(){
  for(int i=0; i<buttonAm; i++){
    byte buttonPin = buttons[i].pin;
    pinMode(buttonPin, INPUT_PULLUP);
    buttons[i].lastPush = 0;
  }
}

void checkButtons(){
  boolean allPressed = true;
  
  for(int i=0; i<buttonAm; i++){
    byte buttonPin = buttons[i].pin;
    if( !digitalRead(buttonPin) ){
      if( millis() > buttons[i].lastPush + pushDelay ){
        int hue = random(buttons[i].hue-10,buttons[i].hue+10);
        Color col(hue, 100, 100, HSB_MODE);
        colore.addNNBeam(buttons[i].startSeg, newBeamSpd, spdMode, beamSpread, col, beamPower);
        buttons[i].lastPush = millis();
      }
    }else allPressed=false;
  }
  
  if(allPressed) bootAnimation();
}

void newRandomBeam(){
  boolean buttonsTimeOut = true;
  for(int i=0; i<buttonAm; i++){
    if( millis() < buttons[i].lastPush + buttonWaitTime){
      buttonsTimeOut = false;
      break;
    }
  }
  
  if(millis()>nextBeamTime && buttonsTimeOut){
    Color c1(random(0,360), 100, 100, HSB_MODE);
    colore.addNNBeam(&seg[random(0,6)], newBeamSpd, spdMode, beamSpread, c1, beamPower);
    nextBeamTime = millis() + random(beamMinDelay,beamMaxDelay);
  }
}
