#include "hardware/adc.h"  
#include <U8x8lib.h>  
#include <Wire.h>  
int val;    
U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);  
void setup() {  
  Wire.setSDA(20);
  Wire.setSCL(21);
  Wire.begin();
  u8x8.begin();  
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.noInverse();//Normal  
  u8x8.clear();  
  u8x8.setCursor(0,2);  
  u8x8.print("RPi Pico");  
  u8x8.setCursor(0,4);  
  u8x8.print("Temp = ");    
}  
void loop() {  
  delay(500);  
  u8x8.setCursor(9,4);// 桁, 行番号
  u8x8.print("    ");// 数値クリア   
  u8x8.setCursor(9,4);// 桁, 行番号 
  u8x8.print(analogReadTemp());// 書き込み   
  u8x8.setCursor(15,4);  
  u8x8.print("C");  
}  
