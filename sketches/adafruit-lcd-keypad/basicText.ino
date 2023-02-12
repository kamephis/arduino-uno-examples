#include "LiquidCrystal.h"

LiquidCrystal lcd( 8,  9,  4,  5,  6,  7);

void setup() {
 lcd.begin(16, 2);
 
 lcd.setCursor(0,0);
 lcd.print("  Hello World  ");
 
 lcd.setCursor(0,1);
 lcd.print("Press Key:");
 
}
void loop() {
 int x;
 x = analogRead (0);
 
 lcd.setCursor(10,1);
 
 if (x < 60) {
   lcd.print ("Right ");
 }
 else if (x < 200) {
   lcd.print ("Up    ");
 }
 else if (x < 400){
   lcd.print ("Down  ");
 }
 else if (x < 600){
   lcd.print ("Left  ");
 }
 else if (x < 800){
   lcd.print ("Select");
 }
 
} 
