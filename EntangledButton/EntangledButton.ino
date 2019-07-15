/*
   Making Entangled Things
   -
   David Chatting - david@davidchatting.com
   8th July 2019
   -
   Wemos D1 Mini Arduino setup > https://chewett.co.uk/blog/937/configuring-wemos-d1-mini-pro-esp8266-arduino-ide/
*/

#define BUTTON_PIN D8
#define LED_RED_PIN D7
#define LED_GREEN_PIN D6
#define LED_BLUE_PIN D5

void setup() {
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == HIGH) {
    digitalWrite(LED_RED_PIN, HIGH);
  }
  else {
    digitalWrite(LED_RED_PIN, LOW);
  }
}
