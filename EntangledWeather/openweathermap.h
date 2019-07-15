/*
   Making Entangled Things
   -
   David Chatting - david@davidchatting.com
   8th July 2019
*/
#include <ArduinoJson.h>

String makeOpenweathermapURL(String location, String apiKey) {
  location.replace(" ", "%20");

  String openweathermapURL = "http://api.openweathermap.org/data/2.5/weather?q=" + location + "&appid=" + apiKey;

  return (openweathermapURL);
}

String parseWeatherFromPayload(String payload) {
  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(payload);
  String weather = root[String("weather")][0][String("main")].as<String>();

  return (weather);
}
