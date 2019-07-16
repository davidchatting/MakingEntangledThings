/*
   Making Entangled Things
   -
   David Chatting - david@davidchatting.com
   8th July 2019
   -
   Wemos D1 Mini Arduino setup > https://chewett.co.uk/blog/937/configuring-wemos-d1-mini-pro-esp8266-arduino-ide/
*/

#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#include "EntangledBasics.h"
#include "EntangledMQTT.h"

void setup() {
  Serial.begin(9600);
  setupBasics();

  connectToWiFi("Making Entangled Things", "entanglement");
  setupMQTT("192.168.8.221", 1883);
}

void loop() {
  loopBasics();
  loopMQTT();
}

void onButtonPressed() {
  sendMQTTMessage("/button", "onButtonPressed");
}

void onButtonReleased() {
  sendMQTTMessage("/button", "onButtonReleased");
}

void onButtonClicked() {
}

void onButtonDoubleClicked() {
}

void onButtonLongPressed() {
}

void onMQTTMessage(String topic, String payload) {
  if(topic.equals("/button")) {
    if(payload.equals("onButtonPressed")) {
      digitalWrite(LED_GREEN_PIN, HIGH);
    }
    else if(payload.equals("onButtonReleased")) {
      digitalWrite(LED_GREEN_PIN, LOW);
    }
  }

  if(topic.equals("/led/rgb")) {
    setLEDColourHex(payload);
  }
}
