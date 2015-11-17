
void checkSerial(){
  if (Serial.available()) {
    Serial.read();
    printFreeRam();
  }
  
}

