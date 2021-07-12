// rp2040: pullup 4k7, or 5k6.

#include "DHT.h"
#include <U8x8lib.h>
#include <Wire.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

void setup() {
Serial.begin(9600);
dht.begin();

  Wire.setSDA(20);
  Wire.setSCL(21);
  Wire.begin();

  u8x8.begin();  
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.noInverse();
  u8x8.clear();  

  u8x8.setCursor(0,2);
  u8x8.print("Humid = ");  
  u8x8.setCursor(0,4);  
  u8x8.print("Temp  = ");
}
void loop() {
delay(2000);
float h = dht.readHumidity();
float t = dht.readTemperature();
Serial.print("Humidity: ");
Serial.print(h);
Serial.print(" %\t");
Serial.print("Temperature: ");
Serial.print(t);
Serial.println(" C ");

  u8x8.setCursor(9,2);// 桁, 行番号
  u8x8.print("    ");// 数値クリア   
  u8x8.setCursor(9,2);// 桁, 行番号 
  u8x8.print(h);// 書き込み
  u8x8.setCursor(15,2);  
  u8x8.print("%");  

  u8x8.setCursor(9,4);// 桁, 行番号
  u8x8.print("    ");// 数値クリア   
  u8x8.setCursor(9,4);// 桁, 行番号 
  u8x8.print(t);// 書き込み
  u8x8.setCursor(15,4);  
  u8x8.print("C");  

}
