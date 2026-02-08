#include <Arduino.h>

static const uint8_t SENSOR_PIN = 2;
static const uint8_t LED_PIN = 12;

void setup() {
  Serial.begin(9600);

  pinMode(SENSOR_PIN, INPUT_PULLUP);
  //pinMode(SENSOR_PIN, INPUT); // use this if you are using an external PULL-UP to VCC with a 10 kOhm resistor

  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int sensorValue = digitalRead(SENSOR_PIN);
  digitalWrite(LED_PIN, !sensorValue);
  
  Serial.print("Sensor value: ");
  Serial.println(sensorValue);
}