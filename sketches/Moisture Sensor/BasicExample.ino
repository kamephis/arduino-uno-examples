#include <LiquidCrystal.h>

const int soilMoistPin = A0;
const int soilMoistLevelLow = 844;
const int soilMoistLevelHigh = 377;

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup()
{
  Serial.begin(115200);
  pinMode(soilMoistPin, INPUT);
  lcd.begin(16, 2);
  lcd.print("Soil Moisture");
}

void loop()
{
  int soilMoist = analogRead(soilMoistPin);

  lcd.setCursor(0, 1);
  lcd.print("Analog Value: ");
  lcd.print(soilMoist);

  if (soilMoist >= soilMoistLevelLow && soilMoist <= soilMoistLevelHigh) {
    int percentSoilMoist = map(soilMoist, soilMoistLevelHigh, soilMoistLevelLow, 100, 0);
    lcd.print("\t");
    lcd.print(percentSoilMoist);
    lcd.print(" %");
  } else {
    lcd.println("\tNo moisture");
  }

  delay(2000);
}
