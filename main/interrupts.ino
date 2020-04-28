// Interrupt-Service-Routine to count at pin
void interruptFunction()
{
  Serial.print("Interrupt: "); 
  Serial.println(interruptions);        // ln: additional "new line"
  
  // Increment interruptions counter
  interruptions++; 

  // Toggle pin with each interrupt
  togglePin(PIN_ISR_LED);
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
