// Test pins via brute force toggle function
void togglePinTimeControl(int pinNumber, int delayTime)
{
  digitalWrite(pinNumber, HIGH);    // sets the LED on
  delay(delayTime);                 // waits for a second
  digitalWrite(pinNumber, LOW);     // sets the LED off
  delay(delayTime);                 // waits for a second
}

// Calculate revolutions dynamically due to 
// interruptions and the given time intervall for measurement
int calculateRevolutionsPerMinute(int interruptions, int calculationIntervall, int interruptionsPerRevolution)
{
  // Number of revolutions is lower or equal to the number of interruptions 
  int revolutions = interruptions / interruptionsPerRevolution;
  
  // Number of revolutions per second (ms divided by 100) times 60 seconds = 1 minute
  int rpm = (revolutions / (calculationIntervall / 1000)) * 60;

  return rpm;
}
