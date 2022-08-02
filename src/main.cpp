#include <Arduino.h>

// #include "BluetoothHelper.h"
#include "ParameterHelper.h"

void setup() {
  Serial.begin(9600);

  Parameters herbie;
  
  // Bluetooth::begin();

  // herbie.data = {
  //     {0.643, 0.16, 1.12},  // PID
  //     220,                  // PWM max
  //     160,                  // PWM min
  //     14,                   // Contagem lateral
  //     {65236, 43212, 76210} // Encoder ticks
  // };
  // herbie.write();
  // Serial.println("\n===== Done writing to EEPROM =====");
  
  
  herbie.read();
  Serial.println("\n===== Done reading from EEPROM =====");
  
  Serial.print("\nP value: ");
  Serial.println(herbie.data.pid.P);
  Serial.print("\nD value: ");
  Serial.println(herbie.data.pid.D);
  Serial.print("\nPWM max value: ");
  Serial.println(herbie.data.pwm_max);
  Serial.print("\nPWM min value: ");
  Serial.println(herbie.data.pwm_min);
}

void loop() {
  // put your main code here, to run repeatedly:
}