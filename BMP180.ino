#include "BMP085.h"
#include <Wire.h>
float temperature;
float pressure;
float atm;
float altitude;
BMP085 myBarometer;

void setup() {
  Wire.setSDA(20);
  Wire.setSCL(21);
  Wire.begin();

  Serial.begin(9600);
  while (!Serial);
  myBarometer.init();
}

void loop() {
    temperature = myBarometer.bmp085GetTemperature(
                      myBarometer.bmp085ReadUT()); //Get the temperature, bmp085ReadUT MUST be called first
    pressure = myBarometer.bmp085GetPressure(myBarometer.bmp085ReadUP());//Get the temperature

    altitude = myBarometer.calcAltitude(101010);

    atm = pressure / 101325;

    Serial.print("Temperature: ");
    Serial.print(temperature, 2);
    Serial.println(" Celsius");

    Serial.print("Pressure: ");
    Serial.print(pressure, 0);
    Serial.println(" Pa");

    Serial.print("Ralated Atmosphere: ");
    Serial.println(atm, 4);

    Serial.print("Altitude: ");
    Serial.print(altitude, 2);
    Serial.println(" m");

    Serial.println();

    delay(1000);
}



