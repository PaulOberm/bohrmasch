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
  Modified 28.04.2020
  By Obermayer Paul

  https://github.com/PaulOberm

*/
#define PIN_LED 9                 // Pin 9 is LED visualization during main
#define PIN_ISR_LED 10            // Pin 10 is LED for ISR 
#define PIN_ISR 6 //3             // Pin for interrupt 1

const int ISR_PIN_INTERNAL = 2;
int startCalculateTime;
int rpm;
float velocity = 0;

// Number of interruptions per rpm calculation
volatile unsigned long interruptions=0;

// Time for the aggregation of interruptions 
const unsigned long CALCULATE_TIMEINVERVAL = 1000;

// Number of markers on the V-belt
const byte INTERUPTIONS_PER_REVOLUTION = 1;                 

void setup()
{
    // Set baud rate for Arduino serial data transmission
    Serial.begin(9600);
    
    // Get time for first calculation
    startCalculateTime = millis();
    Serial.print("Start calculation time: ");
    Serial.println(startCalculateTime);

    // Set pin as output
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_ISR_LED, OUTPUT);
    // Test pins
    digitalWrite(PIN_LED, HIGH);
    digitalWrite(PIN_ISR_LED, HIGH);

    // Define global variables
    bool sensorStatus = false;
    unsigned int rpm = 0; 
    unsigned long revolutions = 0, lastCalculateTime;

    // Control interrupts
    pinMode(ISR_PIN_INTERNAL, INPUT);
    attachInterrupt(0, interruptFunction, FALLING);

    // Set up LCD
    lcdSetup();
}

void loop()
{
  // Test: Toggle LED in set up
  // togglePinTimeControl(PIN_LED, 1000);

  // Update revolutions per minute
  if((millis() - startCalculateTime) > CALCULATE_TIMEINVERVAL){
    
    // Get revolutions per minute
    rpm = calculateRevolutionsPerMinute(interruptions, CALCULATE_TIMEINVERVAL, INTERUPTIONS_PER_REVOLUTION);
    Serial.println("Revolutions per Minute: " + (String)rpm + " RPM");

    // Reset variables (time and number of interrupts)
    startCalculateTime = millis();
    interruptions=0;

    // Print on LCD screen
    lcdLoop(round(rpm));
  }
}
