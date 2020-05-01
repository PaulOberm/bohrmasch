/*
  Bohrmaschinengeschwindigkeitsanzeige

  A hall sensor is measuring a high signal from 
  a magnetic object on the the belt.
  This signal is transmitted via the ISR to the 
  microcontroller and subsequently the current
  velocity is calculated due to a timer reset 
  after ISR. 
  This information is transmitted to the LCD
  screen.

  The circuit:
  * LCD VSS pin (1) to ground
  * LCD VCC/VDD pin (2) to 5V
  * 10K potentionmeter - resistor:
  * ends to +5V and ground
  * wiper to LCD VO pin (3)
  * 
  * LCD RS pin (4) to digital pin 12
  * LCD R/W pin (5) to ground
  * LCD Enable pin (6) to digital pin 11
  * 
  * LCD D4 pin (11) to digital pin 7
  * LCD D5 pin (12) to digital pin 6
  * LCD D6 pin (13) to digital pin 5
  * LCD D7 pin (14) to digital pin 4
  * 
  * LCD LED+ pin (15) to 200 Ohm resistor
  * LCD LED- pin (16) to ground
  * and 220 Ohm resistor to +5V
  * 
  * LED cathode to GND
  * LED anode to 220 Ohm resistor
  * 220 Ohm resistor to digital pin 9
  

  Created 15.02.2020
  By Obermayer Paul
  Modified 30.04.2020
  By Obermayer Paul

  https://github.com/PaulOberm

*/
#include <AUnit.h>
#include "spindle.h"

#define PIN_LED 9                 // Pin 9 is LED visualization during main
#define PIN_ISR_LED 10            // Pin 10 is LED for ISR 
#define ISR_PIN_INTERNAL 2

unsigned long startCalculateTime;
unsigned int rpm = 0;

// Number of interruptions per rpm calculation
volatile unsigned long interruptions=0;

// Time for the aggregation of interruptions 
const unsigned long CALCULATE_TIMEINVERVAL = 2000;  
// Number of markers on the spindle
const byte MARKERS_PER_REVOLUTION = 1;  

// Construct spindle instance
Spindle spindleInstance = Spindle(CALCULATE_TIMEINVERVAL, MARKERS_PER_REVOLUTION);


void setup()
{
    // Set baud rate for Arduino serial data transmission
    Serial.begin(9600);
    
    // Get time for first calculation
    unsigned long startCalculateTime = millis();

    // Set pin as output
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_ISR_LED, OUTPUT);
    // Test pins
    digitalWrite(PIN_LED, HIGH);
    digitalWrite(PIN_ISR_LED, HIGH);

    // Control interrupts
    pinMode(ISR_PIN_INTERNAL, INPUT);
    attachInterrupt(0, interruptFunction, FALLING);

    // Set up LCD
    lcdSetup();
}

void loop()
{
  // Execute unit tests
  aunit::TestRunner::run();
  
  // Test: Toggle LED in set up
  // togglePinTimeControl(PIN_LED, 1000);

  // Update revolutions per minute
  if((millis() - startCalculateTime) > CALCULATE_TIMEINVERVAL){
    
    // Get revolutions per minute
    rpm = spindleInstance.calculateRevolutionsPerMinute(interruptions);
    // Serial.println("Revolutions per Minute: " + (String)rpm + " RPM");

    // Print on LCD screen
    lcdLoop(rpm);

    // Reset variables (time and number of interrupts)
    startCalculateTime = millis();
    interruptions=0;
  }

  delay(10);
}
