/*
  This example uses a moisture sensor
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
