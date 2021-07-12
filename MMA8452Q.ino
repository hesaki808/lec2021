#include <Wire.h>

#define MMA8452_ADRS 0x1D

#define MMA8452_OUT_X_MSB          0x01
#define MMA8452_XYZ_DATA_CFG       0x0E  
#define MMA8452_CTRL_REG1          0x2A  
#define MMA8452_CTRL_REG1_ACTV_BIT 0x01  
#define MMA8452_G_SCALE            2     



void setup() {
  byte tmp;

  Serial.begin(115200);
  Wire.setSDA(20);
  Wire.setSCL(21);
  Wire.begin();

  // Setting MMA8452 internal reg value.
  tmp = MMA8452_ReadByte(MMA8452_CTRL_REG1);
  MMA8452_WriteByte(MMA8452_CTRL_REG1, tmp & ~(MMA8452_CTRL_REG1_ACTV_BIT));

  MMA8452_WriteByte(MMA8452_XYZ_DATA_CFG, (MMA8452_G_SCALE >> 2));

  tmp = MMA8452_ReadByte(MMA8452_CTRL_REG1);
  MMA8452_WriteByte(MMA8452_CTRL_REG1, tmp | MMA8452_CTRL_REG1_ACTV_BIT );

}

void loop() {
  byte buf[6];
  float g[3];

 MMA8452_ReadByteArray(MMA8452_OUT_X_MSB, 6, buf);
 g[0]=-(float((int((buf[0] << 8) | buf[1]) >> 4))/((1 << 11) / MMA8452_G_SCALE));
 g[1]=-(float((int((buf[2] << 8) | buf[3]) >> 4))/((1 << 11) / MMA8452_G_SCALE));
 g[2]=-(float((int((buf[4] << 8) | buf[5]) >> 4))/((1 << 11) / MMA8452_G_SCALE));

 Serial.print(g[0], 4);
 Serial.print("\t");
 Serial.print(g[1], 4);
 Serial.print("\t");
 Serial.print(g[2], 4);
 Serial.println("\t");
 delay(10);

}

void MMA8452_ReadByteArray(byte adrs, int datlen, byte * dest)
{
 Wire.beginTransmission(MMA8452_ADRS);
 Wire.write(adrs);
 Wire.endTransmission(false);
 Wire.requestFrom(MMA8452_ADRS, datlen);
 while(Wire.available() < datlen);
 for(int x = 0 ; x < datlen ; x++){
 dest[x] = Wire.read();
 }
}

byte MMA8452_ReadByte(byte adrs)
{
 Wire.beginTransmission(MMA8452_ADRS);
 Wire.write(adrs);
 Wire.endTransmission(false);
 Wire.requestFrom(MMA8452_ADRS, 1);
 while(!Wire.available());
 return(Wire.read());
}

void MMA8452_WriteByte(byte adrs, byte dat)
{
 Wire.beginTransmission(MMA8452_ADRS);
 Wire.write(adrs);
 Wire.write(dat);
 Wire.endTransmission();
}

