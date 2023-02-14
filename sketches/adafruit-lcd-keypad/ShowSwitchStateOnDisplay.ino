/**
This sketch reads the state of a switch connected to pin 2 and displays the state on a 16x2 LCD display using the LiquidCrystal library.

@file ShowSwitchStateOnDisplay.ino
@author Marlon Böhland
@date 2023/02/13
@version 1.0
@pre A switch is connected to pin 2 of the Arduino Uno.
The LCD display is connected to the following pins:
- RS pin: 12
- E pin: 11
- D4 pin: 5
- D5 pin: 4
- D6 pin: 3
- D7 pin: 2
@post The current state of the switch is displayed on the LCD display.
@see https://www.arduino.cc/reference/en/libraries/liquidcrystal/
*/

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// define the pin for the switch
const int switchPin = 2;

void setup() {
  // set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  
  // set up the switch pin as input
  pinMode(switchPin, INPUT);
}

void loop() {
  // read the state of the switch
  int switchState = digitalRead(switchPin);
  
  // display the state of the switch on the LCD
  lcd.setCursor(0, 0);
  lcd.print("Switch state: ");
  lcd.print(switchState == HIGH ? "ON " : "OFF");
  
  delay(500);
}
