/*
   Making Entangled Things
   -
   David Chatting - david@davidchatting.com
   8th July 2019
   -
   Wemos D1 Mini Arduino setup > https://chewett.co.uk/blog/937/configuring-wemos-d1-mini-pro-esp8266-arduino-ide/
*/

#define BUTTON_PIN D8
#define SERVO_PIN D3
#define LED_RED_PIN D7
#define LED_GREEN_PIN D6
#define LED_BLUE_PIN D5
#define CAP_SENSOR D2
#define CAP_REF D4

#include <CapacitiveSensor.h>
CapacitiveSensor capSensor = CapacitiveSensor(CAP_REF, CAP_SENSOR);

void setup() {
  Serial.begin(9600);
  pinMode(LED_RED_PIN, OUTPUT);

  digitalWrite(LED_RED_PIN, HIGH);
}

void loop() {
  float res =  capSensor.capacitiveSensor(30);

  digitalWrite(LED_RED_PIN, res>10);
  Serial.println(res);
}
