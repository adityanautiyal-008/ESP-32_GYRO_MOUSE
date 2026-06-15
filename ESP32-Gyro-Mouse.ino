#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <HijelHID_BLEMouse.h> 

Adafruit_MPU6050 mpu;
HijelBLEMouse bleMouse("ESP32 Gyro Mouse"); // Fixed class name here

const int sensitivity = 18; 

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22); 

  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) { delay(10); }
  }
  
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  bleMouse.begin();
  Serial.println("BLE Mouse Initialization Complete.");
}

void loop() {
  if (bleMouse.isConnected()) {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    int moveX = -g.gyro.z * sensitivity;
  int moveY = -g.gyro.x * sensitivity; // Changed to minus

    if (abs(moveX) < 2) moveX = 0;
    if (abs(moveY) < 2) moveY = 0;
 
    if (moveX != 0 || moveY != 0) {
      bleMouse.move(moveX, moveY);
    }
  }
  delay(12); 
}
