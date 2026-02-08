#include <Arduino.h>

static const uint8_t SENSOR_PIN = 1;
static const uint8_t LED_PIN = 13;

void setup() {
  pinMode(SENSOR_PIN, INPUT_PULLUP);
  //pinMode(SENSOR_PIN, INPUT); // use this if you are using an external PULL-UP to VCC with a 10 kOhm resistor

  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int sensorValue = digitalRead(SENSOR_PIN);
  digitalWrite(LED_PIN, !sensorValue);
}