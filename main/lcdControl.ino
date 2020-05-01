/*
  Using LiquidCrystal Library

  This sketch prints "Geschw. in m/s" to the LCD
  and shows the current velocity.

  The circuit:
   LCD RS pin (4) to digital pin 12
   LCD Enable pin (6) to digital pin 11

   LCD D4 pin (11) to digital pin 7
   LCD D5 pin (12) to digital pin 6
   LCD D6 pin (13) to digital pin 5
   LCD D7 pin (14) to digital pin 4

   LCD R/W pin (6) to ground
   LCD VSS pin (1) to ground

   LCD VCC pin to 5V
   10K resistor:
   ends to +5V and ground
   wiper to LCD VO pin (pin 3)

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

#include <LiquidCrystal.h>

// Connection of LCD with Arduino pins
const int RS = 12, EN = 11;
const int D4 = 7, D5 = 6, D6 = 5, D7 = 4;

// LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

/*
 * Set up the LCD display with default values
 */
void lcdSetup() {
  // Set up LCD's number of columns (16) and rows (2)
  lcd.begin(16, 2);
  lcd.clear();
}


/*
 * Call the print function to update the velocity on the display
 * Input: 
 * rpm - Current value of revolutions per minute
 */
void lcdLoop(unsigned int rpm) {
  lcd.clear();
  // Set the cursor to column 0, line 0 (First row)
  lcd.setCursor(0, 0);
  lcd.print("Umdreh./Minute:");

  // Set the cursor to column 0, line 1 (Second row)
  lcd.setCursor(0, 1);
  lcd.print(rpm);
}
