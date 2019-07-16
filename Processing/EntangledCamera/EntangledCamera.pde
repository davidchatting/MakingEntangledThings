/*
   Making Entangled Things
   -
   David Chatting - david@davidchatting.com
   8th July 2019
   -
   Processing example
*/

import mqtt.*;  //https://github.com/256dpi/processing-mqtt
import processing.video.*;

MQTTClient mqtt;

Capture camera;

color currentColor = 0;

void setup() {
  size(320, 240);
  frameRate(100);
  
  mqtt = new MQTTClient(this);
  
  mqtt.connect("mqtt://192.168.8.221");
  mqtt.subscribe("#");  //get everything

  camera = new Capture(this, 320, 240);
  camera.start();
}

void captureEvent(Capture e) {
  e.read();
  currentColor = e.get(320/2, 240/2);  //get the colour of the central pixel
}

void draw() {
  background(currentColor);
}

void keyPressed() {
  mqtt.publish("/led/rgb", hex(currentColor, 6));
}

void messageReceived(String topic, byte[] payload) {
  println("new message: " + topic + " - " + new String(payload));
}
