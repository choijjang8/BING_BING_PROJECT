
#include <Wire.h>

int Sensor = 0;
int Count = 0;
int StopValue = 0;
int LED_A[12] = { 0, };
int LED_B[12] = { 0, };
int LED_C[12] = { 0, };
int LED_D[12] = { 0, };
int LED_E[12] = { 0, };
int LED_F[12] = { 0, };
int LED_G[12] = { 0, };
int LED_H[12] = { 0, };

void chip_reset(char onoff) {
  //LED_A Chip reset
  Wire.beginTransmission(0x30);
  Wire.write(0x38);
  if (onoff == 1)
    Wire.write(0xFF);
  else
    Wire.write(0x00); //0x38  //0xFF = Reset
  Wire.endTransmission();
  //LED_B Chip reset
  Wire.beginTransmission(0x31);
  Wire.write(0x38);
  if (onoff == 1)
    Wire.write(0xFF);
  else
    Wire.write(0x00);
  Wire.endTransmission();
  //LED_C Chip reset
  Wire.beginTransmission(0x32);
  Wire.write(0x38);
  if (onoff == 1)
    Wire.write(0xFF);
  else
    Wire.write(0x00); //0x38  //0xFF = Reset
  Wire.endTransmission();
  //LED_D Chip reset
  Wire.beginTransmission(0x33);
  Wire.write(0x38);
  if (onoff == 1)
    Wire.write(0xFF);
  else
    Wire.write(0x00);
  Wire.endTransmission();

  //LED_E Chip reset
  Wire1.beginTransmission(0x30);
  Wire1.write(0x38);
  if (onoff == 1)
    Wire1.write(0xFF);
  else
    Wire1.write(0x00);  //0x38  //0xFF = Reset
  Wire1.endTransmission();
  //LED_F Chip reset
  Wire1.beginTransmission(0x31);
  Wire1.write(0x38);
  if (onoff == 1)
    Wire1.write(0xFF);
  else
    Wire1.write(0x00);
  Wire1.endTransmission();
  //LED_G Chip reset
  Wire1.beginTransmission(0x32);
  Wire1.write(0x38);
  if (onoff == 1)
    Wire1.write(0xFF);
  else
    Wire1.write(0x00);  //0x38  //0xFF = Reset
  Wire1.endTransmission();
  //LED_H Chip reset
  Wire1.beginTransmission(0x33);
  Wire1.write(0x38);
  if (onoff == 1)
    Wire1.write(0xFF);
  else
    Wire1.write(0x00);
  Wire1.endTransmission();
}

void chip_enable(char onoff) {
  //LED_A Chip Enable
  Wire.beginTransmission(0x30);
  Wire.write(0x00);
  if (onoff == 1)
    Wire.write(0x40); //00  //DEVICE_CONFIG0  /6_Chip_EN
  else
    Wire.write(0x00);
  Wire.endTransmission();
  //LED_B Chip Enable
  Wire.beginTransmission(0x31);
  Wire.write(0x00);
  if (onoff == 1)
    Wire.write(0x40); //00  //DEVICE_CONFIG0  /6_Chip_EN
  else
    Wire.write(0x00);
  Wire.endTransmission();
  //LED_C Chip Enable
  Wire.beginTransmission(0x32);
  Wire.write(0x00);
  if (onoff == 1)
    Wire.write(0x40); //00  //DEVICE_CONFIG0  /6_Chip_EN
  else
    Wire.write(0x00);
  Wire.endTransmission();
  //LED_D Chip Enable
  Wire.beginTransmission(0x33);
  Wire.write(0x00);
  if (onoff == 1)
    Wire.write(0x40); //00  //DEVICE_CONFIG0  /6_Chip_EN
  else
    Wire.write(0x00);
  Wire.endTransmission();

  //LED_E Chip Enable
  Wire1.beginTransmission(0x30);
  Wire1.write(0x00);
  if (onoff == 1)
    Wire1.write(0x40);  //00  //DEVICE_CONFIG0  /6_Chip_EN
  else
    Wire1.write(0x00);
  Wire1.endTransmission();
  //LED_F Chip Enable
  Wire1.beginTransmission(0x31);
  Wire1.write(0x00);
  if (onoff == 1)
    Wire1.write(0x40);  //00  //DEVICE_CONFIG0  /6_Chip_EN
  else
    Wire1.write(0x00);
  Wire1.endTransmission();
  //LED_G Chip Enable
  Wire1.beginTransmission(0x32);
  Wire1.write(0x00);
  if (onoff == 1)
    Wire1.write(0x40);  //00  //DEVICE_CONFIG0  /6_Chip_EN
  else
    Wire1.write(0x00);
  Wire1.endTransmission();
  //LED_H Chip Enable
  Wire1.beginTransmission(0x33);
  Wire1.write(0x00);
  if (onoff == 1)
    Wire1.write(0x40);  //00  //DEVICE_CONFIG0  /6_Chip_EN
  else
    Wire1.write(0x00);
  Wire1.endTransmission();
}

void LED_A_write(void) {
  //Color //independent control mode 0%~100%
  Wire.beginTransmission(0x30);
  Wire.write(0x14);
  Wire.write((LED_A[0] >> 16) & 0xFF);  //0x14  //OUT0 COLOR 
  Wire.write((LED_A[0] >> 8) & 0xFF); //0x15  //OUT1 COLOR 
  Wire.write((LED_A[0]) & 0xFF);      //0x16  //OUT2 COLOR 
  Wire.write((LED_A[1] >> 16) & 0xFF);  //0x17  //OUT3 COLOR 
  Wire.write((LED_A[1] >> 8) & 0xFF); //0x18  //OUT4 COLOR 
  Wire.write((LED_A[1]) & 0xFF);      //0x19  //OUT5 COLOR 
  Wire.write((LED_A[2] >> 16) & 0xFF);  //0x1A  //OUT6 COLOR 
  Wire.write((LED_A[2] >> 8) & 0xFF); //0x1B  //OUT7 COLOR 
  Wire.write((LED_A[2]) & 0xFF);      //0x1C  //OUT8 COLOR 
  Wire.write((LED_A[3] >> 16) & 0xFF);  //0x1D  //OUT9 COLOR 
  Wire.write((LED_A[3] >> 8) & 0xFF); //0x1E  //OUT10 COLOR 
  Wire.write((LED_A[3]) & 0xFF);      //0x1F  //OUT11 COLOR 
  Wire.write((LED_A[4] >> 16) & 0xFF);  //0x20  //OUT12 COLOR 
  Wire.write((LED_A[4] >> 8) & 0xFF); //0x21  //OUT13 COLOR 
  Wire.write((LED_A[4]) & 0xFF);      //0x22  //OUT14 COLOR 
  Wire.write((LED_A[5] >> 16) & 0xFF);  //0x23  //OUT15 COLOR 
  Wire.write((LED_A[5] >> 8) & 0xFF); //0x24  //OUT16 COLOR 
  Wire.write((LED_A[5]) & 0xFF);      //0x25  //OUT17 COLOR 
  Wire.endTransmission();

  Wire.beginTransmission(0x30);
  Wire.write(0x26);
  Wire.write((LED_A[6] >> 16) & 0xFF);  //0x26  //OUT18 COLOR 
  Wire.write((LED_A[6] >> 8) & 0xFF); //0x27  //OUT19 COLOR 
  Wire.write((LED_A[6]) & 0xFF);      //0x28  //OUT20 COLOR 
  Wire.write((LED_A[7] >> 16) & 0xFF);  //0x29  //OUT21 COLOR 
  Wire.write((LED_A[7] >> 8) & 0xFF); //0x2A  //OUT22 COLOR 
  Wire.write((LED_A[7]) & 0xFF);      //0x2B  //OUT23 COLOR 
  Wire.write((LED_A[8] >> 16) & 0xFF);  //0x2C  //OUT24 COLOR 
  Wire.write((LED_A[8] >> 8) & 0xFF); //0x2D  //OUT25 COLOR 
  Wire.write((LED_A[8]) & 0xFF);      //0x2E  //OUT26 COLOR 
  Wire.write((LED_A[9] >> 16) & 0xFF);  //0x2F  //OUT27 COLOR 
  Wire.write((LED_A[9] >> 8) & 0xFF); //0x30  //OUT28 COLOR 
  Wire.write((LED_A[9]) & 0xFF);      //0x31  //OUT29 COLOR 
  Wire.write((LED_A[10] >> 16) & 0xFF); //0x32  //OUT30 COLOR 
  Wire.write((LED_A[10] >> 8) & 0xFF);  //0x33  //OUT31 COLOR 
  Wire.write((LED_A[10]) & 0xFF);   //0x34  //OUT32 COLOR 
  Wire.write((LED_A[11] >> 16) & 0xFF); //0x35  //OUT33 COLOR 
  Wire.write((LED_A[11] >> 8) & 0xFF);  //0x36  //OUT34 COLOR 
  Wire.write((LED_A[11]) & 0xFF);   //0x37  //OUT35 COLOR 
  Wire.endTransmission();
}
void LED_B_write(void) {
  //Color //independent control mode 0%~100%
  Wire.beginTransmission(0x31);
  Wire.write(0x14);
  Wire.write((LED_B[0] >> 16) & 0xFF);  //0x14  //OUT0 COLOR 
  Wire.write((LED_B[0] >> 8) & 0xFF); //0x15  //OUT1 COLOR 
  Wire.write((LED_B[0]) & 0xFF);      //0x16  //OUT2 COLOR 
  Wire.write((LED_B[1] >> 16) & 0xFF);  //0x17  //OUT3 COLOR 
  Wire.write((LED_B[1] >> 8) & 0xFF); //0x18  //OUT4 COLOR 
  Wire.write((LED_B[1]) & 0xFF);      //0x19  //OUT5 COLOR 
  Wire.write((LED_B[2] >> 16) & 0xFF);  //0x1A  //OUT6 COLOR 
  Wire.write((LED_B[2] >> 8) & 0xFF); //0x1B  //OUT7 COLOR 
  Wire.write((LED_B[2]) & 0xFF);      //0x1C  //OUT8 COLOR 
  Wire.write((LED_B[3] >> 16) & 0xFF);  //0x1D  //OUT9 COLOR 
  Wire.write((LED_B[3] >> 8) & 0xFF); //0x1E  //OUT10 COLOR 
  Wire.write((LED_B[3]) & 0xFF);      //0x1F  //OUT11 COLOR 
  Wire.write((LED_B[4] >> 16) & 0xFF);  //0x20  //OUT12 COLOR 
  Wire.write((LED_B[4] >> 8) & 0xFF); //0x21  //OUT13 COLOR 
  Wire.write((LED_B[4]) & 0xFF);      //0x22  //OUT14 COLOR 
  Wire.write((LED_B[5] >> 16) & 0xFF);  //0x23  //OUT15 COLOR 
  Wire.write((LED_B[5] >> 8) & 0xFF); //0x24  //OUT16 COLOR 
  Wire.write((LED_B[5]) & 0xFF);      //0x25  //OUT17 COLOR 
  Wire.endTransmission();

  Wire.beginTransmission(0x31);
  Wire.write(0x26);
  Wire.write((LED_B[6] >> 16) & 0xFF);  //0x26  //OUT18 COLOR 
  Wire.write((LED_B[6] >> 8) & 0xFF); //0x27  //OUT19 COLOR 
  Wire.write((LED_B[6]) & 0xFF);      //0x28  //OUT20 COLOR 
  Wire.write((LED_B[7] >> 16) & 0xFF);  //0x29  //OUT21 COLOR 
  Wire.write((LED_B[7] >> 8) & 0xFF); //0x2A  //OUT22 COLOR 
  Wire.write((LED_B[7]) & 0xFF);      //0x2B  //OUT23 COLOR 
  Wire.write((LED_B[8] >> 16) & 0xFF);  //0x2C  //OUT24 COLOR 
  Wire.write((LED_B[8] >> 8) & 0xFF); //0x2D  //OUT25 COLOR 
  Wire.write((LED_B[8]) & 0xFF);      //0x2E  //OUT26 COLOR 
  Wire.write((LED_B[9] >> 16) & 0xFF);  //0x2F  //OUT27 COLOR 
  Wire.write((LED_B[9] >> 8) & 0xFF); //0x30  //OUT28 COLOR 
  Wire.write((LED_B[9]) & 0xFF);      //0x31  //OUT29 COLOR 
  Wire.write((LED_B[10] >> 16) & 0xFF); //0x32  //OUT30 COLOR 
  Wire.write((LED_B[10] >> 8) & 0xFF);  //0x33  //OUT31 COLOR 
  Wire.write((LED_B[10]) & 0xFF);   //0x34  //OUT32 COLOR 
  Wire.write((LED_B[11] >> 16) & 0xFF); //0x35  //OUT33 COLOR 
  Wire.write((LED_B[11] >> 8) & 0xFF);  //0x36  //OUT34 COLOR 
  Wire.write((LED_B[11]) & 0xFF);   //0x37  //OUT35 COLOR 
  Wire.endTransmission();
}
void LED_C_write(void) {
  //Color //independent control mode 0%~100%
  Wire.beginTransmission(0x32);
  Wire.write(0x14);
  Wire.write((LED_C[0] >> 16) & 0xFF);  //0x14  //OUT0 COLOR 
  Wire.write((LED_C[0] >> 8) & 0xFF); //0x15  //OUT1 COLOR 
  Wire.write((LED_C[0]) & 0xFF);      //0x16  //OUT2 COLOR 
  Wire.write((LED_C[1] >> 16) & 0xFF);  //0x17  //OUT3 COLOR 
  Wire.write((LED_C[1] >> 8) & 0xFF); //0x18  //OUT4 COLOR 
  Wire.write((LED_C[1]) & 0xFF);      //0x19  //OUT5 COLOR 
  Wire.write((LED_C[2] >> 16) & 0xFF);  //0x1A  //OUT6 COLOR 
  Wire.write((LED_C[2] >> 8) & 0xFF); //0x1B  //OUT7 COLOR 
  Wire.write((LED_C[2]) & 0xFF);      //0x1C  //OUT8 COLOR 
  Wire.write((LED_C[3] >> 16) & 0xFF);  //0x1D  //OUT9 COLOR 
  Wire.write((LED_C[3] >> 8) & 0xFF); //0x1E  //OUT10 COLOR 
  Wire.write((LED_C[3]) & 0xFF);      //0x1F  //OUT11 COLOR 
  Wire.write((LED_C[4] >> 16) & 0xFF);  //0x20  //OUT12 COLOR 
  Wire.write((LED_C[4] >> 8) & 0xFF); //0x21  //OUT13 COLOR 
  Wire.write((LED_C[4]) & 0xFF);      //0x22  //OUT14 COLOR 
  Wire.write((LED_C[5] >> 16) & 0xFF);  //0x23  //OUT15 COLOR 
  Wire.write((LED_C[5] >> 8) & 0xFF); //0x24  //OUT16 COLOR 
  Wire.write((LED_C[5]) & 0xFF);      //0x25  //OUT17 COLOR 
  Wire.endTransmission();

  Wire.beginTransmission(0x32);
  Wire.write(0x26);
  Wire.write((LED_C[6] >> 16) & 0xFF);  //0x26  //OUT18 COLOR 
  Wire.write((LED_C[6] >> 8) & 0xFF); //0x27  //OUT19 COLOR 
  Wire.write((LED_C[6]) & 0xFF);      //0x28  //OUT20 COLOR 
  Wire.write((LED_C[7] >> 16) & 0xFF);  //0x29  //OUT21 COLOR 
  Wire.write((LED_C[7] >> 8) & 0xFF); //0x2A  //OUT22 COLOR 
  Wire.write((LED_C[7]) & 0xFF);      //0x2B  //OUT23 COLOR 
  Wire.write((LED_C[8] >> 16) & 0xFF);  //0x2C  //OUT24 COLOR 
  Wire.write((LED_C[8] >> 8) & 0xFF); //0x2D  //OUT25 COLOR 
  Wire.write((LED_C[8]) & 0xFF);      //0x2E  //OUT26 COLOR 
  Wire.write((LED_C[9] >> 16) & 0xFF);  //0x2F  //OUT27 COLOR 
  Wire.write((LED_C[9] >> 8) & 0xFF); //0x30  //OUT28 COLOR 
  Wire.write((LED_C[9]) & 0xFF);      //0x31  //OUT29 COLOR 
  Wire.write((LED_C[10] >> 16) & 0xFF); //0x32  //OUT30 COLOR 
  Wire.write((LED_C[10] >> 8) & 0xFF);  //0x33  //OUT31 COLOR 
  Wire.write((LED_C[10]) & 0xFF);   //0x34  //OUT32 COLOR 
  Wire.write((LED_C[11] >> 16) & 0xFF); //0x35  //OUT33 COLOR 
  Wire.write((LED_C[11] >> 8) & 0xFF);  //0x36  //OUT34 COLOR 
  Wire.write((LED_C[11]) & 0xFF);   //0x37  //OUT35 COLOR 
  Wire.endTransmission();
}
void LED_D_write(void) {
  //Color //independent control mode 0%~100%
  Wire.beginTransmission(0x33);
  Wire.write(0x14);
  Wire.write((LED_D[0] >> 16) & 0xFF);  //0x14  //OUT0 COLOR 
  Wire.write((LED_D[0] >> 8) & 0xFF); //0x15  //OUT1 COLOR 
  Wire.write((LED_D[0]) & 0xFF);      //0x16  //OUT2 COLOR 
  Wire.write((LED_D[1] >> 16) & 0xFF);  //0x17  //OUT3 COLOR 
  Wire.write((LED_D[1] >> 8) & 0xFF); //0x18  //OUT4 COLOR 
  Wire.write((LED_D[1]) & 0xFF);      //0x19  //OUT5 COLOR 
  Wire.write((LED_D[2] >> 16) & 0xFF);  //0x1A  //OUT6 COLOR 
  Wire.write((LED_D[2] >> 8) & 0xFF); //0x1B  //OUT7 COLOR 
  Wire.write((LED_D[2]) & 0xFF);      //0x1C  //OUT8 COLOR 
  Wire.write((LED_D[3] >> 16) & 0xFF);  //0x1D  //OUT9 COLOR 
  Wire.write((LED_D[3] >> 8) & 0xFF); //0x1E  //OUT10 COLOR 
  Wire.write((LED_D[3]) & 0xFF);      //0x1F  //OUT11 COLOR 
  Wire.write((LED_D[4] >> 16) & 0xFF);  //0x20  //OUT12 COLOR 
  Wire.write((LED_D[4] >> 8) & 0xFF); //0x21  //OUT13 COLOR 
  Wire.write((LED_D[4]) & 0xFF);      //0x22  //OUT14 COLOR 
  Wire.write((LED_D[5] >> 16) & 0xFF);  //0x23  //OUT15 COLOR 
  Wire.write((LED_D[5] >> 8) & 0xFF); //0x24  //OUT16 COLOR 
  Wire.write((LED_D[5]) & 0xFF);      //0x25  //OUT17 COLOR 
  Wire.endTransmission();

  Wire.beginTransmission(0x33);
  Wire.write(0x26);
  Wire.write((LED_D[6] >> 16) & 0xFF);  //0x26  //OUT18 COLOR 
  Wire.write((LED_D[6] >> 8) & 0xFF); //0x27  //OUT19 COLOR 
  Wire.write((LED_D[6]) & 0xFF);      //0x28  //OUT20 COLOR 
  Wire.write((LED_D[7] >> 16) & 0xFF);  //0x29  //OUT21 COLOR 
  Wire.write((LED_D[7] >> 8) & 0xFF); //0x2A  //OUT22 COLOR 
  Wire.write((LED_D[7]) & 0xFF);      //0x2B  //OUT23 COLOR 
  Wire.write((LED_D[8] >> 16) & 0xFF);  //0x2C  //OUT24 COLOR 
  Wire.write((LED_D[8] >> 8) & 0xFF); //0x2D  //OUT25 COLOR 
  Wire.write((LED_D[8]) & 0xFF);      //0x2E  //OUT26 COLOR 
  Wire.write((LED_D[9] >> 16) & 0xFF);  //0x2F  //OUT27 COLOR 
  Wire.write((LED_D[9] >> 8) & 0xFF); //0x30  //OUT28 COLOR 
  Wire.write((LED_D[9]) & 0xFF);      //0x31  //OUT29 COLOR 
  Wire.write((LED_D[10] >> 16) & 0xFF); //0x32  //OUT30 COLOR 
  Wire.write((LED_D[10] >> 8) & 0xFF);  //0x33  //OUT31 COLOR 
  Wire.write((LED_D[10]) & 0xFF);   //0x34  //OUT32 COLOR 
  Wire.write((LED_D[11] >> 16) & 0xFF); //0x35  //OUT33 COLOR 
  Wire.write((LED_D[11] >> 8) & 0xFF);  //0x36  //OUT34 COLOR 
  Wire.write((LED_D[11]) & 0xFF);   //0x37  //OUT35 COLOR 
  Wire.endTransmission();
}
void LED_E_write(void) {
  //Color //independent control mode 0%~100%
  Wire.beginTransmission(0x30);
  Wire.write(0x14);
  Wire.write((LED_E[0] >> 16) & 0xFF);  //0x14  //OUT0 COLOR 
  Wire.write((LED_E[0] >> 8) & 0xFF); //0x15  //OUT1 COLOR 
  Wire.write((LED_E[0]) & 0xFF);      //0x16  //OUT2 COLOR 
  Wire.write((LED_E[1] >> 16) & 0xFF);  //0x17  //OUT3 COLOR 
  Wire.write((LED_E[1] >> 8) & 0xFF); //0x18  //OUT4 COLOR 
  Wire.write((LED_E[1]) & 0xFF);      //0x19  //OUT5 COLOR 
  Wire.write((LED_E[2] >> 16) & 0xFF);  //0x1A  //OUT6 COLOR 
  Wire.write((LED_E[2] >> 8) & 0xFF); //0x1B  //OUT7 COLOR 
  Wire.write((LED_E[2]) & 0xFF);      //0x1C  //OUT8 COLOR 
  Wire.write((LED_E[3] >> 16) & 0xFF);  //0x1D  //OUT9 COLOR 
  Wire.write((LED_E[3] >> 8) & 0xFF); //0x1E  //OUT10 COLOR 
  Wire.write((LED_E[3]) & 0xFF);      //0x1F  //OUT11 COLOR 
  Wire.write((LED_E[4] >> 16) & 0xFF);  //0x20  //OUT12 COLOR 
  Wire.write((LED_E[4] >> 8) & 0xFF); //0x21  //OUT13 COLOR 
  Wire.write((LED_E[4]) & 0xFF);      //0x22  //OUT14 COLOR 
  Wire.write((LED_E[5] >> 16) & 0xFF);  //0x23  //OUT15 COLOR 
  Wire.write((LED_E[5] >> 8) & 0xFF); //0x24  //OUT16 COLOR 
  Wire.write((LED_E[5]) & 0xFF);      //0x25  //OUT17 COLOR 
  Wire.endTransmission();

  Wire.beginTransmission(0x30);
  Wire.write(0x26);
  Wire.write((LED_E[6] >> 16) & 0xFF);  //0x26  //OUT18 COLOR 
  Wire.write((LED_E[6] >> 8) & 0xFF); //0x27  //OUT19 COLOR 
  Wire.write((LED_E[6]) & 0xFF);      //0x28  //OUT20 COLOR 
  Wire.write((LED_E[7] >> 16) & 0xFF);  //0x29  //OUT21 COLOR 
  Wire.write((LED_E[7] >> 8) & 0xFF); //0x2A  //OUT22 COLOR 
  Wire.write((LED_E[7]) & 0xFF);      //0x2B  //OUT23 COLOR 
  Wire.write((LED_E[8] >> 16) & 0xFF);  //0x2C  //OUT24 COLOR 
  Wire.write((LED_E[8] >> 8) & 0xFF); //0x2D  //OUT25 COLOR 
  Wire.write((LED_E[8]) & 0xFF);      //0x2E  //OUT26 COLOR 
  Wire.write((LED_E[9] >> 16) & 0xFF);  //0x2F  //OUT27 COLOR 
  Wire.write((LED_E[9] >> 8) & 0xFF); //0x30  //OUT28 COLOR 
  Wire.write((LED_E[9]) & 0xFF);      //0x31  //OUT29 COLOR 
  Wire.write((LED_E[10] >> 16) & 0xFF); //0x32  //OUT30 COLOR 
  Wire.write((LED_E[10] >> 8) & 0xFF);  //0x33  //OUT31 COLOR 
  Wire.write((LED_E[10]) & 0xFF);   //0x34  //OUT32 COLOR 
  Wire.write((LED_E[11] >> 16) & 0xFF); //0x35  //OUT33 COLOR 
  Wire.write((LED_E[11] >> 8) & 0xFF);  //0x36  //OUT34 COLOR 
  Wire.write((LED_E[11]) & 0xFF);   //0x37  //OUT35 COLOR 
  Wire.endTransmission();
}
void LED_F_write(void) {
  //Color //independent control mode 0%~100%
  Wire.beginTransmission(0x31);
  Wire.write(0x14);
  Wire.write((LED_F[0] >> 16) & 0xFF);  //0x14  //OUT0 COLOR 
  Wire.write((LED_F[0] >> 8) & 0xFF); //0x15  //OUT1 COLOR 
  Wire.write((LED_F[0]) & 0xFF);      //0x16  //OUT2 COLOR 
  Wire.write((LED_F[1] >> 16) & 0xFF);  //0x17  //OUT3 COLOR 
  Wire.write((LED_F[1] >> 8) & 0xFF); //0x18  //OUT4 COLOR 
  Wire.write((LED_F[1]) & 0xFF);      //0x19  //OUT5 COLOR 
  Wire.write((LED_F[2] >> 16) & 0xFF);  //0x1A  //OUT6 COLOR 
  Wire.write((LED_F[2] >> 8) & 0xFF); //0x1B  //OUT7 COLOR 
  Wire.write((LED_F[2]) & 0xFF);      //0x1C  //OUT8 COLOR 
  Wire.write((LED_F[3] >> 16) & 0xFF);  //0x1D  //OUT9 COLOR 
  Wire.write((LED_F[3] >> 8) & 0xFF); //0x1E  //OUT10 COLOR 
  Wire.write((LED_F[3]) & 0xFF);      //0x1F  //OUT11 COLOR 
  Wire.write((LED_F[4] >> 16) & 0xFF);  //0x20  //OUT12 COLOR 
  Wire.write((LED_F[4] >> 8) & 0xFF); //0x21  //OUT13 COLOR 
  Wire.write((LED_F[4]) & 0xFF);      //0x22  //OUT14 COLOR 
  Wire.write((LED_F[5] >> 16) & 0xFF);  //0x23  //OUT15 COLOR 
  Wire.write((LED_F[5] >> 8) & 0xFF); //0x24  //OUT16 COLOR 
  Wire.write((LED_F[5]) & 0xFF);      //0x25  //OUT17 COLOR 
  Wire.endTransmission();

  Wire.beginTransmission(0x31);
  Wire.write(0x26);
  Wire.write((LED_F[6] >> 16) & 0xFF);  //0x26  //OUT18 COLOR 
  Wire.write((LED_F[6] >> 8) & 0xFF); //0x27  //OUT19 COLOR 
  Wire.write((LED_F[6]) & 0xFF);      //0x28  //OUT20 COLOR 
  Wire.write((LED_F[7] >> 16) & 0xFF);  //0x29  //OUT21 COLOR 
  Wire.write((LED_F[7] >> 8) & 0xFF); //0x2A  //OUT22 COLOR 
  Wire.write((LED_F[7]) & 0xFF);      //0x2B  //OUT23 COLOR 
  Wire.write((LED_F[8] >> 16) & 0xFF);  //0x2C  //OUT24 COLOR 
  Wire.write((LED_F[8] >> 8) & 0xFF); //0x2D  //OUT25 COLOR 
  Wire.write((LED_F[8]) & 0xFF);      //0x2E  //OUT26 COLOR 
  Wire.write((LED_F[9] >> 16) & 0xFF);  //0x2F  //OUT27 COLOR 
  Wire.write((LED_F[9] >> 8) & 0xFF); //0x30  //OUT28 COLOR 
  Wire.write((LED_F[9]) & 0xFF);      //0x31  //OUT29 COLOR 
  Wire.write((LED_F[10] >> 16) & 0xFF); //0x32  //OUT30 COLOR 
  Wire.write((LED_F[10] >> 8) & 0xFF);  //0x33  //OUT31 COLOR 
  Wire.write((LED_F[10]) & 0xFF);   //0x34  //OUT32 COLOR 
  Wire.write((LED_F[11] >> 16) & 0xFF); //0x35  //OUT33 COLOR 
  Wire.write((LED_F[11] >> 8) & 0xFF);  //0x36  //OUT34 COLOR 
  Wire.write((LED_F[11]) & 0xFF);   //0x37  //OUT35 COLOR 
  Wire.endTransmission();
}
void LED_G_write(void) {
  //Color //independent control mode 0%~100%
  Wire.beginTransmission(0x32);
  Wire.write(0x14);
  Wire.write((LED_G[0] >> 16) & 0xFF);  //0x14  //OUT0 COLOR 
  Wire.write((LED_G[0] >> 8) & 0xFF); //0x15  //OUT1 COLOR 
  Wire.write((LED_G[0]) & 0xFF);      //0x16  //OUT2 COLOR 
  Wire.write((LED_G[1] >> 16) & 0xFF);  //0x17  //OUT3 COLOR 
  Wire.write((LED_G[1] >> 8) & 0xFF); //0x18  //OUT4 COLOR 
  Wire.write((LED_G[1]) & 0xFF);      //0x19  //OUT5 COLOR 
  Wire.write((LED_G[2] >> 16) & 0xFF);  //0x1A  //OUT6 COLOR 
  Wire.write((LED_G[2] >> 8) & 0xFF); //0x1B  //OUT7 COLOR 
  Wire.write((LED_G[2]) & 0xFF);      //0x1C  //OUT8 COLOR 
  Wire.write((LED_G[3] >> 16) & 0xFF);  //0x1D  //OUT9 COLOR 
  Wire.write((LED_G[3] >> 8) & 0xFF); //0x1E  //OUT10 COLOR 
  Wire.write((LED_G[3]) & 0xFF);      //0x1F  //OUT11 COLOR 
  Wire.write((LED_G[4] >> 16) & 0xFF);  //0x20  //OUT12 COLOR 
  Wire.write((LED_G[4] >> 8) & 0xFF); //0x21  //OUT13 COLOR 
  Wire.write((LED_G[4]) & 0xFF);      //0x22  //OUT14 COLOR 
  Wire.write((LED_G[5] >> 16) & 0xFF);  //0x23  //OUT15 COLOR 
  Wire.write((LED_G[5] >> 8) & 0xFF); //0x24  //OUT16 COLOR 
  Wire.write((LED_G[5]) & 0xFF);      //0x25  //OUT17 COLOR 
  Wire.endTransmission();

  Wire.beginTransmission(0x32);
  Wire.write(0x26);
  Wire.write((LED_G[6] >> 16) & 0xFF);  //0x26  //OUT18 COLOR 
  Wire.write((LED_G[6] >> 8) & 0xFF); //0x27  //OUT19 COLOR 
  Wire.write((LED_G[6]) & 0xFF);      //0x28  //OUT20 COLOR 
  Wire.write((LED_G[7] >> 16) & 0xFF);  //0x29  //OUT21 COLOR 
  Wire.write((LED_G[7] >> 8) & 0xFF); //0x2A  //OUT22 COLOR 
  Wire.write((LED_G[7]) & 0xFF);      //0x2B  //OUT23 COLOR 
  Wire.write((LED_G[8] >> 16) & 0xFF);  //0x2C  //OUT24 COLOR 
  Wire.write((LED_G[8] >> 8) & 0xFF); //0x2D  //OUT25 COLOR 
  Wire.write((LED_G[8]) & 0xFF);      //0x2E  //OUT26 COLOR 
  Wire.write((LED_G[9] >> 16) & 0xFF);  //0x2F  //OUT27 COLOR 
  Wire.write((LED_G[9] >> 8) & 0xFF); //0x30  //OUT28 COLOR 
  Wire.write((LED_G[9]) & 0xFF);      //0x31  //OUT29 COLOR 
  Wire.write((LED_G[10] >> 16) & 0xFF); //0x32  //OUT30 COLOR 
  Wire.write((LED_G[10] >> 8) & 0xFF);  //0x33  //OUT31 COLOR 
  Wire.write((LED_G[10]) & 0xFF);   //0x34  //OUT32 COLOR 
  Wire.write((LED_G[11] >> 16) & 0xFF); //0x35  //OUT33 COLOR 
  Wire.write((LED_G[11] >> 8) & 0xFF);  //0x36  //OUT34 COLOR 
  Wire.write((LED_G[11]) & 0xFF);   //0x37  //OUT35 COLOR 
  Wire.endTransmission();
}
void LED_H_write(void) {
  //Color //independent control mode 0%~100%
  Wire.beginTransmission(0x33);
  Wire.write(0x14);
  Wire.write((LED_H[0] >> 16) & 0xFF);  //0x14  //OUT0 COLOR 
  Wire.write((LED_H[0] >> 8) & 0xFF); //0x15  //OUT1 COLOR 
  Wire.write((LED_H[0]) & 0xFF);      //0x16  //OUT2 COLOR 
  Wire.write((LED_H[1] >> 16) & 0xFF);  //0x17  //OUT3 COLOR 
  Wire.write((LED_H[1] >> 8) & 0xFF); //0x18  //OUT4 COLOR 
  Wire.write((LED_H[1]) & 0xFF);      //0x19  //OUT5 COLOR 
  Wire.write((LED_H[2] >> 16) & 0xFF);  //0x1A  //OUT6 COLOR 
  Wire.write((LED_H[2] >> 8) & 0xFF); //0x1B  //OUT7 COLOR 
  Wire.write((LED_H[2]) & 0xFF);      //0x1C  //OUT8 COLOR 
  Wire.write((LED_H[3] >> 16) & 0xFF);  //0x1D  //OUT9 COLOR 
  Wire.write((LED_H[3] >> 8) & 0xFF); //0x1E  //OUT10 COLOR 
  Wire.write((LED_H[3]) & 0xFF);      //0x1F  //OUT11 COLOR 
  Wire.write((LED_H[4] >> 16) & 0xFF);  //0x20  //OUT12 COLOR 
  Wire.write((LED_H[4] >> 8) & 0xFF); //0x21  //OUT13 COLOR 
  Wire.write((LED_H[4]) & 0xFF);      //0x22  //OUT14 COLOR 
  Wire.write((LED_H[5] >> 16) & 0xFF);  //0x23  //OUT15 COLOR 
  Wire.write((LED_H[5] >> 8) & 0xFF); //0x24  //OUT16 COLOR 
  Wire.write((LED_H[5]) & 0xFF);      //0x25  //OUT17 COLOR 
  Wire.endTransmission();

  Wire.beginTransmission(0x33);
  Wire.write(0x26);
  Wire.write((LED_H[6] >> 16) & 0xFF);  //0x26  //OUT18 COLOR 
  Wire.write((LED_H[6] >> 8) & 0xFF); //0x27  //OUT19 COLOR 
  Wire.write((LED_H[6]) & 0xFF);      //0x28  //OUT20 COLOR 
  Wire.write((LED_H[7] >> 16) & 0xFF);  //0x29  //OUT21 COLOR 
  Wire.write((LED_H[7] >> 8) & 0xFF); //0x2A  //OUT22 COLOR 
  Wire.write((LED_H[7]) & 0xFF);      //0x2B  //OUT23 COLOR 
  Wire.write((LED_H[8] >> 16) & 0xFF);  //0x2C  //OUT24 COLOR 
  Wire.write((LED_H[8] >> 8) & 0xFF); //0x2D  //OUT25 COLOR 
  Wire.write((LED_H[8]) & 0xFF);      //0x2E  //OUT26 COLOR 
  Wire.write((LED_H[9] >> 16) & 0xFF);  //0x2F  //OUT27 COLOR 
  Wire.write((LED_H[9] >> 8) & 0xFF); //0x30  //OUT28 COLOR 
  Wire.write((LED_H[9]) & 0xFF);      //0x31  //OUT29 COLOR 
  Wire.write((LED_H[10] >> 16) & 0xFF); //0x32  //OUT30 COLOR 
  Wire.write((LED_H[10] >> 8) & 0xFF);  //0x33  //OUT31 COLOR 
  Wire.write((LED_H[10]) & 0xFF);   //0x34  //OUT32 COLOR 
  Wire.write((LED_H[11] >> 16) & 0xFF); //0x35  //OUT33 COLOR 
  Wire.write((LED_H[11] >> 8) & 0xFF);  //0x36  //OUT34 COLOR 
  Wire.write((LED_H[11]) & 0xFF);   //0x37  //OUT35 COLOR 
  Wire.endTransmission();
}

void LED_Brightness(void) {
  //LED_A Brightness
  Wire.beginTransmission(0x30); // Slave address
  Wire.write(0x08);
  Wire.write(0xFF); //08  //LED0_BRIGHTNESS /independent control mode 0%~100%
  Wire.write(0xFF); //09  //LED1_BRIGHTNESS
  Wire.write(0xFF); //0A  //LED2_BRIGHTNESS
  Wire.write(0xFF); //0B  //LED3_BRIGHTNESS
  Wire.write(0xFF); //0C  //LED4_BRIGHTNESS
  Wire.write(0xFF); //0D  //LED5_BRIGHTNESS
  Wire.write(0xFF); //0E  //LED6_BRIGHTNESS
  Wire.write(0xFF); //0F  //LED7_BRIGHTNESS
  Wire.write(0xFF); //10  //LED8_BRIGHTNESS
  Wire.write(0xFF); //11  //LED9_BRIGHTNESS
  Wire.write(0xFF); //12  //LED10_BRIGHTNESS
  Wire.write(0xFF); //13  //LED11_BRIGHTNESS
  Wire.endTransmission();    // stop transmitting
  //LED_B Brightness
  Wire.beginTransmission(0x31); // Slave address
  Wire.write(0x08);
  Wire.write(0xFF); //08  //LED0_BRIGHTNESS /independent control mode 0%~100%
  Wire.write(0xFF); //09  //LED1_BRIGHTNESS
  Wire.write(0xFF); //0A  //LED2_BRIGHTNESS
  Wire.write(0xFF); //0B  //LED3_BRIGHTNESS
  Wire.write(0xFF); //0C  //LED4_BRIGHTNESS
  Wire.write(0xFF); //0D  //LED5_BRIGHTNESS
  Wire.write(0xFF); //0E  //LED6_BRIGHTNESS
  Wire.write(0xFF); //0F  //LED7_BRIGHTNESS
  Wire.write(0xFF); //10  //LED8_BRIGHTNESS
  Wire.write(0xFF); //11  //LED9_BRIGHTNESS
  Wire.write(0xFF); //12  //LED10_BRIGHTNESS
  Wire.write(0xFF); //13  //LED11_BRIGHTNESS
  Wire.endTransmission();    // stop transmitting
  //LED_C Brightness
  Wire.beginTransmission(0x32); // Slave address
  Wire.write(0x08);
  Wire.write(0xFF); //08  //LED0_BRIGHTNESS /independent control mode 0%~100%
  Wire.write(0xFF); //09  //LED1_BRIGHTNESS
  Wire.write(0xFF); //0A  //LED2_BRIGHTNESS
  Wire.write(0xFF); //0B  //LED3_BRIGHTNESS
  Wire.write(0xFF); //0C  //LED4_BRIGHTNESS
  Wire.write(0xFF); //0D  //LED5_BRIGHTNESS
  Wire.write(0xFF); //0E  //LED6_BRIGHTNESS
  Wire.write(0xFF); //0F  //LED7_BRIGHTNESS
  Wire.write(0xFF); //10  //LED8_BRIGHTNESS
  Wire.write(0xFF); //11  //LED9_BRIGHTNESS
  Wire.write(0xFF); //12  //LED10_BRIGHTNESS
  Wire.write(0xFF); //13  //LED11_BRIGHTNESS
  Wire.endTransmission();    // stop transmitting
  //LED_D Brightness
  Wire.beginTransmission(0x33); // Slave address
  Wire.write(0x08);
  Wire.write(0xFF); //08  //LED0_BRIGHTNESS /independent control mode 0%~100%
  Wire.write(0xFF); //09  //LED1_BRIGHTNESS
  Wire.write(0xFF); //0A  //LED2_BRIGHTNESS
  Wire.write(0xFF); //0B  //LED3_BRIGHTNESS
  Wire.write(0xFF); //0C  //LED4_BRIGHTNESS
  Wire.write(0xFF); //0D  //LED5_BRIGHTNESS
  Wire.write(0xFF); //0E  //LED6_BRIGHTNESS
  Wire.write(0xFF); //0F  //LED7_BRIGHTNESS
  Wire.write(0xFF); //10  //LED8_BRIGHTNESS
  Wire.write(0xFF); //11  //LED9_BRIGHTNESS
  Wire.write(0xFF); //12  //LED10_BRIGHTNESS
  Wire.write(0xFF); //13  //LED11_BRIGHTNESS
  Wire.endTransmission();    // stop transmitting

  //LED_E Brightness
  Wire1.beginTransmission(0x30); // Slave address
  Wire1.write(0x08);
  Wire1.write(0xFF);  //08  //LED0_BRIGHTNESS /independent control mode 0%~100%
  Wire1.write(0xFF);  //09  //LED1_BRIGHTNESS
  Wire1.write(0xFF);  //0A  //LED2_BRIGHTNESS
  Wire1.write(0xFF);  //0B  //LED3_BRIGHTNESS
  Wire1.write(0xFF);  //0C  //LED4_BRIGHTNESS
  Wire1.write(0xFF);  //0D  //LED5_BRIGHTNESS
  Wire1.write(0xFF);  //0E  //LED6_BRIGHTNESS
  Wire1.write(0xFF);  //0F  //LED7_BRIGHTNESS
  Wire1.write(0xFF);  //10  //LED8_BRIGHTNESS
  Wire1.write(0xFF);  //11  //LED9_BRIGHTNESS
  Wire1.write(0xFF);  //12  //LED10_BRIGHTNESS
  Wire1.write(0xFF);  //13  //LED11_BRIGHTNESS
  Wire1.endTransmission();    // stop transmitting
  //LED_F Brightness
  Wire1.beginTransmission(0x31); // Slave address
  Wire1.write(0x08);
  Wire1.write(0xFF);  //08  //LED0_BRIGHTNESS /independent control mode 0%~100%
  Wire1.write(0xFF);  //09  //LED1_BRIGHTNESS
  Wire1.write(0xFF);  //0A  //LED2_BRIGHTNESS
  Wire1.write(0xFF);  //0B  //LED3_BRIGHTNESS
  Wire1.write(0xFF);  //0C  //LED4_BRIGHTNESS
  Wire1.write(0xFF);  //0D  //LED5_BRIGHTNESS
  Wire1.write(0xFF);  //0E  //LED6_BRIGHTNESS
  Wire1.write(0xFF);  //0F  //LED7_BRIGHTNESS
  Wire1.write(0xFF);  //10  //LED8_BRIGHTNESS
  Wire1.write(0xFF);  //11  //LED9_BRIGHTNESS
  Wire1.write(0xFF);  //12  //LED10_BRIGHTNESS
  Wire1.write(0xFF);  //13  //LED11_BRIGHTNESS
  Wire1.endTransmission();    // stop transmitting
  //LED_G Brightness
  Wire1.beginTransmission(0x32); // Slave address
  Wire1.write(0x08);
  Wire1.write(0xFF);  //08  //LED0_BRIGHTNESS /independent control mode 0%~100%
  Wire1.write(0xFF);  //09  //LED1_BRIGHTNESS
  Wire1.write(0xFF);  //0A  //LED2_BRIGHTNESS
  Wire1.write(0xFF);  //0B  //LED3_BRIGHTNESS
  Wire1.write(0xFF);  //0C  //LED4_BRIGHTNESS
  Wire1.write(0xFF);  //0D  //LED5_BRIGHTNESS
  Wire1.write(0xFF);  //0E  //LED6_BRIGHTNESS
  Wire1.write(0xFF);  //0F  //LED7_BRIGHTNESS
  Wire1.write(0xFF);  //10  //LED8_BRIGHTNESS
  Wire1.write(0xFF);  //11  //LED9_BRIGHTNESS
  Wire1.write(0xFF);  //12  //LED10_BRIGHTNESS
  Wire1.write(0xFF);  //13  //LED11_BRIGHTNESS
  Wire1.endTransmission();    // stop transmitting
  //LED_H Brightness
  Wire1.beginTransmission(0x33); // Slave address
  Wire1.write(0x08);
  Wire1.write(0xFF);  //08  //LED0_BRIGHTNESS /independent control mode 0%~100%
  Wire1.write(0xFF);  //09  //LED1_BRIGHTNESS
  Wire1.write(0xFF);  //0A  //LED2_BRIGHTNESS
  Wire1.write(0xFF);  //0B  //LED3_BRIGHTNESS
  Wire1.write(0xFF);  //0C  //LED4_BRIGHTNESS
  Wire1.write(0xFF);  //0D  //LED5_BRIGHTNESS
  Wire1.write(0xFF);  //0E  //LED6_BRIGHTNESS
  Wire1.write(0xFF);  //0F  //LED7_BRIGHTNESS
  Wire1.write(0xFF);  //10  //LED8_BRIGHTNESS
  Wire1.write(0xFF);  //11  //LED9_BRIGHTNESS
  Wire1.write(0xFF);  //12  //LED10_BRIGHTNESS
  Wire1.write(0xFF);  //13  //LED11_BRIGHTNESS
  Wire1.endTransmission();    // stop transmitting
}

void setup() {
  //  pinMode(2, INPUT);    //Sensor

  Wire.begin();     //Reset i2c
  Wire.setClock(400000);  //400kHz
  Wire1.begin();      //Reset i2c
  Wire1.setClock(400000); //400kHz
  delay(100);

  chip_reset(0);
  chip_enable(0);
  delay(100);

  chip_reset(1);
  chip_reset(0);
  chip_enable(1);

  LED_Brightness();

  attachInterrupt(2, led_write, RISING);  //Sensor interrupt  //LOW, HIGH, RISING, FALLING, CHANGE

}

void loop() {
  //delay(1);    
  //delayMicroseconds(1);
}

void led_write() {
  if (Count == 0) {
    LED_A[0] = 0xFF0000;
    LED_A[1] = 0x00FF00;
    LED_A[2] = 0x0000FF;
    LED_A[3] = 0xFF0000;
    LED_A[4] = 0x00FF00;
    LED_A[5] = 0x0000FF;
    LED_A[6] = 0xFF0000;
    LED_A[7] = 0x00FF00;
    LED_A[8] = 0x0000FF;
    LED_A[9] = 0xFF0000;
    LED_A[10] = 0x00FF00;
    LED_A[11] = 0x0000FF;

    LED_B[0] = 0xFF0000;
    LED_B[1] = 0x00FF00;
    LED_B[2] = 0x0000FF;
    LED_B[3] = 0xFF0000;
    LED_B[4] = 0x00FF00;
    LED_B[5] = 0x0000FF;
    LED_B[6] = 0xFF0000;
    LED_B[7] = 0x00FF00;
    LED_B[8] = 0x0000FF;
    LED_B[9] = 0xFF0000;
    LED_B[10] = 0x00FF00;
    LED_B[11] = 0x0000FF;
  }
  else if (Count == 1) {
    LED_A[0] = 0x00FF00;
    LED_A[1] = 0x0000FF;
    LED_A[2] = 0xFF0000;
    LED_A[3] = 0x00FF00;
    LED_A[4] = 0x0000FF;
    LED_A[5] = 0xFF0000;
    LED_A[6] = 0x00FF00;
    LED_A[7] = 0x0000FF;
    LED_A[8] = 0xFF0000;
    LED_A[9] = 0x00FF00;
    LED_A[10] = 0x0000FF;
    LED_A[11] = 0xFF0000;

    LED_B[0] = 0x00FF00;
    LED_B[1] = 0x0000FF;
    LED_B[2] = 0xFF0000;
    LED_B[3] = 0x00FF00;
    LED_B[4] = 0x0000FF;
    LED_B[5] = 0xFF0000;
    LED_B[6] = 0x00FF00;
    LED_B[7] = 0x0000FF;
    LED_B[8] = 0xFF0000;
    LED_B[9] = 0x00FF00;
    LED_B[10] = 0x0000FF;
    LED_B[11] = 0xFF0000;
  }
  else if (Count == 2) {
    LED_A[0] = 0x0000FF;
    LED_A[1] = 0xFF0000;
    LED_A[2] = 0x00FF00;
    LED_A[3] = 0x0000FF;
    LED_A[4] = 0xFF0000;
    LED_A[5] = 0x00FF00;
    LED_A[6] = 0x0000FF;
    LED_A[7] = 0xFF0000;
    LED_A[8] = 0x00FF00;
    LED_A[9] = 0x0000FF;
    LED_A[10] = 0xFF0000;
    LED_A[11] = 0x00FF00;

    LED_B[0] = 0x0000FF;
    LED_B[1] = 0xFF0000;
    LED_B[2] = 0x00FF00;
    LED_B[3] = 0x0000FF;
    LED_B[4] = 0xFF0000;
    LED_B[5] = 0x00FF00;
    LED_B[6] = 0x0000FF;
    LED_B[7] = 0xFF0000;
    LED_B[8] = 0x00FF00;
    LED_B[9] = 0x0000FF;
    LED_B[10] = 0xFF0000;
    LED_B[11] = 0x00FF00;
  }
  Count++;
  if (Count > 2)
    Count = 0;

  LED_A_write();
  LED_B_write();
  //LED_C_write();
  //LED_D_write();
  //LED_E_write();
  //LED_F_write();
  //LED_G_write();
  //LED_H_write();

}
