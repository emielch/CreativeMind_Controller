int bootAnimOrder[] = {6,10,11,7,8,9,12,13,14,   0,1,2,3,4,5,     15,16,17,18,19,20,21,22,23,24,25,26,27,28,29};
int bootAnimAmount = sizeof(bootAnimOrder)/sizeof(int);
unsigned long bootAnimDuration = 3000;


void bootAnimation(){
  unsigned long startTime = millis();
  int i = 0;
  unsigned long nextAnim = 0;
  boolean runAnim = true;

  while(millis()<startTime+bootAnimDuration && runAnim){
    Serial.println("BOOTANIM");
    if(millis()>=nextAnim && i<bootAnimAmount){
      int hue = (360 / bootAnimAmount) * i;
      Color black(0,0,0,RGB_MODE);
      Color c(hue,100,100,HSB_MODE);
      seg[bootAnimOrder[i]].setFadeInOut(c,black,0.8,0.8);
      i++;
      nextAnim = millis() + (bootAnimDuration*0.2)/bootAnimAmount;
    }
    if(millis()>startTime+bootAnimDuration-100){
      Color white(255,255,255,RGB_MODE);
      for(int i=30; i<75; i++){
        colore.addBeam(&seg[i],true,2,SEGMENT_SPD,8,white);
        colore.addBeam(&seg[i],false,2,SEGMENT_SPD,8,white);
      }
      runAnim = false;
    }

    colore.update();
    printFramerate();
    blinkLED();
  }
}

