/*
   Making Entangled Things
   -
   David Chatting - david@davidchatting.com
   8th July 2019
*/

//---Pin Definitions---
#define BUTTON_PIN D8
#define SERVO_PIN D3
#define LED_RED_PIN D7
#define LED_GREEN_PIN D6
#define LED_BLUE_PIN D5
#define CAP_SENSOR D2
#define CAP_REF D4
//---

//---External libraries---
#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#include <ESP8266HTTPClient.h>
//---

//---Button---
#include <AceButton.h>            //https://github.com/bxparks/AceButton
using namespace ace_button;
AceButton button;
void onButtonEvent(AceButton*, uint8_t, uint8_t);
void onButtonPressed();
void onButtonReleased();
void onButtonClicked();
void onButtonDoubleClicked();
void onButtonLongPressed();
//---

//---Servo---
#include <Servo.h>
Servo servo;
//---

//---Capacitive Sensing---
#include <CapacitiveSensor.h>
CapacitiveSensor capSensor = CapacitiveSensor(CAP_REF, CAP_SENSOR);
//---

//---Functions---
//---Call from setup()
void setupBasics() {
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(BUTTON_PIN, INPUT);
  button.init(BUTTON_PIN, LOW);
  ButtonConfig* buttonConfig = button.getButtonConfig();
  buttonConfig->setEventHandler(onButtonEvent);
  buttonConfig->setFeature(ButtonConfig::kFeatureDoubleClick);
  buttonConfig->setFeature(ButtonConfig::kFeatureLongPress);
  buttonConfig->setLongPressDelay(1000);  //in milliseconds 

  servo.attach(SERVO_PIN);
}

void connectToWiFi(String network, String password) {
  WiFi.mode(WIFI_STA);
  WiFi.begin(network.c_str(), password.c_str());

  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }
  Serial.print("Connected to WiFi");
}

//---Call from loop()
void loopBasics() {
  button.check();
}

//---Get the payload of contents from a URL
String getURLPayload(String url) {
  String payload;
  
  HTTPClient http;
  http.begin(url);

  Serial.print("Getting URL: ");
  Serial.println(url);
  
  int httpCode = http.GET();
  Serial.print("HTTP Code: ");
  Serial.println(httpCode);
  
  if (httpCode == HTTP_CODE_OK) {
     payload = http.getString(); 
  }
  http.end();

  return(payload);
}

//---Set colour by integer 0 to 255 in r, g and b
void setLEDColourRGB(int r, int g, int b) {
  analogWrite(LED_RED_PIN, r);
  analogWrite(LED_GREEN_PIN, g);
  analogWrite(LED_BLUE_PIN, b);
}

//---Set colour by hex colour code (same as HTML)
void setLEDColourHex(String hex) {
  if(hex.startsWith("#")) hex = hex.substring(1, hex.length());
  hex.toLowerCase();
  
  int i = strtol(hex.c_str(), 0, 16);
  setLEDColourRGB( (i >> 16) & 0xFF, (i >> 8) & 0xFF,  (i >> 0) & 0xFF);
}


//---Route the button events
void onButtonEvent(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  switch (eventType) {
    case AceButton::kEventPressed:
      onButtonPressed();
      break;
    case AceButton::kEventReleased:
      onButtonReleased();
      break;
    case AceButton::kEventClicked:
      onButtonClicked();
      break;
    case AceButton::kEventDoubleClicked:
      onButtonDoubleClicked();
      break;
    case AceButton::kEventLongPressed:
      onButtonLongPressed();
      break;
  }
}
//---
