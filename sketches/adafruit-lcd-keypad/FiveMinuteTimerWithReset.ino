#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int timer = 300; // 5 minutes in seconds
unsigned long startTime;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Timer: 5:00");
  startTime = millis();
}

void loop() {
  unsigned long currentTime = millis();
  if (currentTime - startTime >= 1000) { // decrement timer every second
    startTime = currentTime;
    timer--;
    if (timer <= 0) {
      lcd.clear();
      lcd.print("Time's up!");
      while (true); // stop the timer
    } else {
      lcd.setCursor(0, 1);
      lcd.print("     "); // clear the second line
      lcd.setCursor(0, 1);
      lcd.print(timer / 60); // print minutes
      lcd.print(":");
      lcd.print(timer % 60 / 10); // print tens of seconds
      lcd.print(timer % 60 % 10); // print units of seconds
    }
  }
}
