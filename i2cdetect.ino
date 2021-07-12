#include <Wire.h>
#include <i2cdetect.h>

/*
  Wire.setSDA();
  Wire.setSCL();
  Wire1.setSDA();
  Wire1.setSCL();
  Wire1.begin(address);

*/

void setup() {
  Wire.setSDA(20);
  Wire.setSCL(21);
  Wire.begin();
  Serial.begin(9600);
  Serial.println("i2cdetect example\n");
  Serial.print("Scanning address range 0x03-0x77\n\n");
}

void loop() {
  i2cdetect();  // default range from 0x03 to 0x77
  delay(2000);
}
