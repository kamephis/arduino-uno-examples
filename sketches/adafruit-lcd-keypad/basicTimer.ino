#include <LiquidCrystal.h>
#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Current Date/Time");
  delay(1000);
  setSyncProvider(RTC.get);   // set function to get the time from the RTC
}

void loop() {
  time_t t = now();
  lcd.setCursor(0, 0);
  lcd.print(day(t));
  lcd.print("/");
  lcd.print(month(t));
  lcd.print("/");
  lcd.print(year(t));
  lcd.setCursor(0, 1);
  lcd.print(hour(t));
  lcd.print(":");
  lcd.print(minute(t));
  lcd.print(":");
  lcd.print(second(t));
  delay(1000);
}
