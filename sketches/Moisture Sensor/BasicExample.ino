/*
  This example uses a moisture sensor and prints out a percentage level based on the
  soilMoistLeveLow and soilMoistLevelHigh. This highly depends on your plants.

  Pin Settings
  
  Arduino UNO: + = 5V, - = GND, A = A0
  ESP32: + = 3.3V, - GND, A = A0 (36) / VP
  ESP8266: + 3,3V, - GND, A = A0
  Arduino Mega: + 5V, - GND, A = A0
*/

const int soilMoistPin = A0;
const int soilMoistLevelLow = 200;
const int soilMoistLevelHigh = 800;

void setup()
{
  Serial.begin(115200);
  pinMode(soilMoistPin, INPUT);
}

void loop()
{
  int soilMoist = analogRead(soilMoistPin);
  Serial.print("Analog Value: ");
  Serial.print(soilMoist);

  if (soilMoist >= soilMoistLevelLow && soilMoist <= soilMoistLevelHigh) {
    int percentSoilMoist = map(soilMoist, soilMoistLevelHigh, soilMoistLevelLow, 100, 0);
    Serial.print("\t");
    Serial.print(percentSoilMoist);
    Serial.println(" %");
  } else {
    Serial.println("\tNo moisture detected.");
  }
  
  delay(2000);
}
