/*
   Making Entangled Things
   -
   David Chatting - david@davidchatting.com
   8th July 2019
   -
   Wemos D1 Mini Arduino setup > https://chewett.co.uk/blog/937/configuring-wemos-d1-mini-pro-esp8266-arduino-ide/
*/

#include "EntangledBasics.h"
#include "openweathermap.h"

void setup() {
  Serial.begin(9600);
  setupBasics();

  connectToWiFi("Making Entangled Things", "entanglement");
}

void loop() {
  loopBasics();
}

String getWeather(String location, String apiKey) {
  String url = makeOpenweathermapURL(location, apiKey);
  String payload = getURLPayload(url);
  String weather = parseWeatherFromPayload(payload);

  return (weather);
}

void onButtonPressed() {
  String weather = getWeather("newcastle upon tyne", "PUT-API-KEY-HERE");
  Serial.println(weather);
}

void onButtonReleased() {
}

void onButtonClicked() {
}

void onButtonDoubleClicked() {
}

void onButtonLongPressed() {
}
