#include <Wire.h>
#include <Adafruit_INA3221.h>

Adafruit_INA3221 ina3221;

void setup() {

  Serial.begin(115200);

  // SDA = GPIO4
  // SCL = GPIO5
  Wire.begin(4, 5);

  if (!ina3221.begin()) {
    Serial.println("Khong tim thay INA3221 !");
    while (1);
  }

  Serial.println("INA3221 OK");
}

void loop() {

  // CH1 = index 0
  float busVoltage1 = ina3221.getBusVoltage(0);
  float current1 = ina3221.getCurrentAmps(0) * 1000.0;

  // CH2 = index 1
  float busVoltage2 = ina3221.getBusVoltage(1);
  float current2 = ina3221.getCurrentAmps(1) * 1000.0;

  // CH3 = index 2
  float busVoltage3 = ina3221.getBusVoltage(2);
  float current3 = ina3221.getCurrentAmps(2) * 1000.0;

  Serial.println("===== INA3221 =====");

  Serial.print("CH1 Voltage: ");
  Serial.print(busVoltage1, 3);
  Serial.print(" V   Current: ");
  Serial.print(current1, 3);
  Serial.println(" mA");

  Serial.print("CH2 Voltage: ");
  Serial.print(busVoltage2, 3);
  Serial.print(" V   Current: ");
  Serial.print(current2, 3);
  Serial.println(" mA");

  Serial.print("CH3 Voltage: ");
  Serial.print(busVoltage3, 3);
  Serial.print(" V   Current: ");
  Serial.print(current3, 3);
  Serial.println(" mA");

  Serial.println();

  delay(1000);
}