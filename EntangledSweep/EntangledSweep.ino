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

#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(SERVO_PIN);
}

void loop() {
  int pos;

  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
