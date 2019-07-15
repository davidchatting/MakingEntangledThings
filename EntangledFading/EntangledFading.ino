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

void setup() {
  analogWrite(LED_RED_PIN, 0);
  analogWrite(LED_GREEN_PIN, 128);
  analogWrite(LED_BLUE_PIN, 128);
}

void loop() {  
  /*
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(LED_RED_PIN, fadeValue);
    analogWrite(LED_GREEN_PIN, fadeValue);
    analogWrite(LED_BLUE_PIN, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(LED_RED_PIN, fadeValue);
    analogWrite(LED_GREEN_PIN, fadeValue);
    analogWrite(LED_BLUE_PIN, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
  */
}
