// Test pins via brute force toggle function
void togglePinTimeControl(int pinNumber, int delayTime)
{
  digitalWrite(pinNumber, HIGH);    // sets the LED on
  delay(delayTime);                 // waits for a second
  digitalWrite(pinNumber, LOW);     // sets the LED off
  delay(delayTime);                 // waits for a second
}
