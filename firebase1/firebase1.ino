#include <FirebaseError.h>
#include <FirebaseObject.h>
#include <Firebase.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseHttpClient.h>
#include <FirebaseArduino.h>

//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseRoom_ESP8266 is a sample that demo using multiple sensors
// and actuactor with the FirebaseArduino library.

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
// Set these to run example.
#define FIREBASE_HOST "https://stealth99-f2a84.firebaseio.com"
#define FIREBASE_AUTH "ml8XBN8MMHW871Jmo5vC9og8ogAhlvqFWLzk9i8h"
#define WIFI_SSID "k"
#define WIFI_PASSWORD "0987654321"

void setup() {
  Serial.begin(115200);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.set("stealth99-f2a84/pushbutton", 0);
}

void loop() {
  Serial.print("hola");
  delay(200);
}
