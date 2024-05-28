int MotorSpeed =255;
#include <Wire.h>

#define Left_I2C_ADDRESS 0x50
#define Right_I2C_ADDRESS 0x51
#define Front_ADDRESS 0x85
#define Back_ADDRESS 0x86

void motor1(int tSpeed){
  int tPWM;
  int tDir;
  if(tSpeed < 0){
    tPWM = -tSpeed;
    tDir = 2;
  }
  else if(tSpeed > 0){
    tPWM = tSpeed;
    tDir = 1;
  }
  else {
    tPWM = 0;
    tDir = 3;
  }
  if(tPWM > 255)tPWM = 255;
  Wire.beginTransmission(Left_I2C_ADDRESS):
  Wire.write(Front_ADDRESS);
  Wire.write(tDir);
  Wire.write(tPWM);
  Wire.endTransmission();
}

void motor2(int tSpeed){
  int tPWM;
  int tDir;
  if(tSpeed < 0){
    tPWM = -tSpeed;
    tDir = 2;
  }
  else if(tSpeed > 0){
    tPWM = tSpeed;
    tDir = 1;
  }
  else {
    tPWM = 0;
    tDir = 3;
  }
  if(tPWM > 255)tPWM = 255;
  Wire.beginTransmission(Left_I2C_ADDRESS):
  Wire.write(Back_ADDRESS);
  Wire.write(tDir);
  Wire.write(tPWM);
  Wire.endTransmission();
}

void motor3(int tSpeed){
  int tPWM;
  int tDir;
  if(tSpeed < 0){
    tPWM = -tSpeed;
    tDir = 2;
  }
  else if(tSpeed > 0){
    tPWM = tSpeed;
    tDir = 1;
  }
  else {
    tPWM = 0;
    tDir = 3;
  }
  if(tPWM > 255)tPWM = 255;
  Wire.beginTransmission(Right_I2C_ADDRESS):
  Wire.write(Front_ADDRESS);
  Wire.write(tDir);
  Wire.write(tPWM);
  Wire.endTransmission();
}

void motor4(int tSpeed){
  int tPWM;
  int tDir;
  if(tSpeed < 0){
    tPWM = -tSpeed;
    tDir = 2;
  }
  else if(tSpeed > 0){
    tPWM = tSpeed;
    tDir = 1;
  }
  else {
    tPWM = 0;
    tDir = 3;
  }
  if(tPWM > 255)tPWM = 255;
  Wire.beginTransmission(Right_I2C_ADDRESS):
  Wire.write(Back_ADDRESS);
  Wire.write(tDir);
  Wire.write(tPWM);
  Wire.endTransmission();
}
void setup() {
  // Initialize the serial communication
  Serial.begin(115200);
  
}

void loop() {
  // Check if data is available to read
  if (Serial.available() > 0) {
    // Read the incoming string
    String data = Serial.readStringUntil('\n');
    
    // Find the index of the comma separator
    int commaIndex = data.indexOf(',');
    
    // Extract the individual values
    int lx = data.substring(0, commaIndex).toInt();
    int ly = data.substring(commaIndex + 1).toInt();
    int rx = data.substring(commaIndex + 2).toInt();
    int ry = data.substring(commaIndex + 3).toInt();
    int A_button = data.substring(commaIndex + 4).toInt();
    int B_button = data.substring(commaIndex + 5).toInt();
    int X_button = data.substring(commaIndex + 6).toInt();
    int Y_button = data.substring(commaIndex + 7).toInt();
    // Control the brightness of the LEDs
    if (abs(lx) < 30){
      lx = 0;
    }
    if (abs(ly) < 30){
      ly = 0;
    }
    if (abs(rx) < 30){
      rx = 0;
    }
    if (abs(ry) < 30){
      ry = 0;
    }
    // Motor Control
    if (abs(lx) < 175 && ly < -200){
      motor1(MotorSpeed);
      motor2(MotorSpeed);
      motor3(MotorSpeed);
      motor4(MotorSpeed);
      //Forward
    }
    else if (abs(lx) < 175 && ly > 200){
      motor1(-MotorSpeed);
      motor2(-MotorSpeed);
      motor3(-MotorSpeed);
      motor4(-MotorSpeed);
      //Backward
    }
    else if (lx < -200 && abs(ly) < 175){
      motor1(-MotorSpeed);
      motor2(MotorSpeed);
      motor3(MotorSpeed);
      motor4(-MotorSpeed);
      //SlideL
    }
    else if (lx > 200 && abs(ly) < 175){
      motor1(MotorSpeed);
      motor2(-MotorSpeed);
      motor3(-MotorSpeed);
      motor4(MotorSpeed);
      //SlideR
  }
    else if (lx < -150 && ly < -150){
      motor1(0);
      motor2(MotorSpeed);
      motor3(MotorSpeed);
      motor4(0);
      //DiagTopL
  }
    else if (lx > 150 && ly < -150){
      motor1(MotorSpeed);
      motor2(0);
      motor3(0);
      motor4(MotorSpeed);
      //DiagTopR
    else if (lx < -150 && ly > 150){
      motor1(-MotorSpeed);
      motor2(0);
      motor3(0);
      motor4(-MotorSpeed);
      //DiagBottomL
  }
    else if (lx > 150 && ly > 50){
      motor1(0);
      motor2(-MotorSpeed);
      motor3(-MotorSpeed);
      motor4(0);
      //DiagBottomR
  }
}
