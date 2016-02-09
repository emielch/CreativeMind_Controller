
void checkSerial(){
  if (Serial.available()) {
    Serial.read();
    printFreeRam();
  }
  
}


void sendNeuronFire(byte neuronID){
  Serial.print("Neruron Fired: ");
  Serial.println(neuronID);
}

