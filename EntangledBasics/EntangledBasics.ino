/*
   Making Entangled Things
   -
   David Chatting - david@davidchatting.com
   8th July 2019
   -
   Wemos D1 Mini Arduino setup > https://chewett.co.uk/blog/937/configuring-wemos-d1-mini-pro-esp8266-arduino-ide/
*/

#include "EntangledBasics.h"

void setup() {
  Serial.begin(9600);
  setupBasics();

  connectToWiFi("Making Entangled Things", "entanglement");
  setLEDColourHex("#aaaaaa");
}

void loop() {
  loopBasics();
}

void onButtonPressed() {
}

void onButtonReleased() {
}

void onButtonClicked() {
}

void onButtonDoubleClicked() {
}

void onButtonLongPressed() {
}
