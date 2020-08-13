// Interrupt-Service-Routine to count at pin
void interruptFunction()
{
  // Debug information to check if interrupt executed
  // Serial.print("Interrupt: "); 
  // Serial.println(interruptions);
  
  // Toggle pin with each interrupt
  // togglePin(PIN_ISR_LED);
  
  // Increment interruptions counter
  interruptions++;
  Serial.println("Interrrupt");
  
}

void togglePin(int pinNumber)
{
  if(digitalRead(pinNumber)){
    digitalWrite(pinNumber, LOW);
  }
  else{
    digitalWrite(pinNumber, HIGH);
  }
}
