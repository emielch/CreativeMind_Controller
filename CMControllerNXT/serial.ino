
void checkSerial(){
  if (Serial.available()) {
    Serial.read();
    printFreeRam();
  }
  
}


void sendNeuronFire(Segment *neuron){
  Serial.print("Neruron Fired: ");
  Serial.println(getSegmentID(neuron));
}


void sendNeuronDischarge(Segment *neuron){
  Serial.print("Neruron Discharged: ");
  Serial.println(getSegmentID(neuron));
}


int getSegmentID(Segment *segment){
  for(int i=0; i<segAm; i++){
    if(segment == &seg[i]){
      return i;
    }
  }
  return -1;
}

