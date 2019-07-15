/*
   Making Entangled Things
   -
   David Chatting - david@davidchatting.com
   8th July 2019
*/

#include <PubSubClient.h>        //﻿https://github.com/knolleary/pubsubclient

WiFiClient wifi;
PubSubClient mqtt(wifi);

void onMQTTEvent(char*, byte*, unsigned int);
void onMQTTMessage(String topic, String payload);
void getMacAddress(char *);

void connectMQTT() {
  char macAddress[12];
  getMacAddress(macAddress);
  mqtt.connect(macAddress);
}

void setupMQTT(String ipAddress, int portNumber) {
  digitalWrite(LED_BUILTIN, HIGH); //lights on LOW
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  mqtt.setServer(ipAddress.c_str(), portNumber);
  mqtt.setCallback(onMQTTEvent);

  connectMQTT();

  mqtt.subscribe("#", 0);    //QoS 0 = "fire and forget" - don't get missed messages
}

void loopMQTT() {
  mqtt.loop();

  if(!mqtt.connected()) {
    delay(3000);
    connectMQTT();
  }
  digitalWrite(LED_BUILTIN, !mqtt.connected()); //lights on LOW
}

void sendMQTTMessage(String topic, String payload) {
  mqtt.publish(topic.c_str(), payload.c_str(), false);
}

void onMQTTEvent(char* topic, byte* payload, unsigned int length) {
  onMQTTMessage(String((char *)topic), String((char *)payload).substring(0, length));
}

void getMacAddress(char *result) {
  byte mac[6];
  WiFi.macAddress(mac);
  for (int i = 0; i < 6; ++i) {
    String element = String(mac[i], HEX);
    result[i*2] = element.charAt(0);
    result[(i*2) + 1] = element.charAt(1);
  }
}
