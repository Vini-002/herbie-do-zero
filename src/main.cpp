#include <Arduino.h>

// #include "BluetoothHelper.h"
#include "MemoryHelper.h"

void setup() {
  Serial.begin(9600);
  // Bluetooth::begin();

  // Memory::data = {
  //     {0.643, 0.16, 1.12},  // PID
  //     220,                  // PWM max
  //     160,                  // PWM min
  //     14,                   // Contagem lateral
  //     {65236, 43212, 76210} // Encoder ticks
  // };
  // Memory::write();
  // Serial.println("\n===== Done writing to EEPROM =====");
  
  Memory::read();
  Serial.println("\n===== Done reading from EEPROM =====");
  
  Serial.print("\nP value: ");
  Serial.println(Memory::data.pid.P);
  Serial.print("\nD value: ");
  Serial.println(Memory::data.pid.D);
  Serial.print("\nPWM max value: ");
  Serial.println(Memory::data.pwm_max);
  Serial.print("\nPWM min value: ");
  Serial.println(Memory::data.pwm_min);
}

void loop() {
  // put your main code here, to run repeatedly:
}