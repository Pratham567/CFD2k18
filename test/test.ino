#include <FirebaseError.h>
#include <FirebaseObject.h>
#include <Firebase.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseHttpClient.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "https://status-338c0.firebaseio.com/"
#define FIREBASE_AUTH "AIzaSyBkGSF7-RKdBNECWgIowzPsNz1d-vQTPnw"
#define WIFI_SSID "legionnaire"
#define WIFI_PASSWORD "7409246864"
#include <ESP8266WiFi.h>
     
    const char* ssid     = "";
    const char* password = "";     

    int wifiStatus;
     
    void setup() {
      
      Serial.begin(115200);
      delay(200);
      
     
     
      // We start by connecting to a WiFi network
     
      Serial.println();
      Serial.println();
      Serial.print("Your are connecting to;");
      Serial.println(ssid);
      
      WiFi.begin(ssid, password);
      
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
      }
     
 }   
     
void loop() {
      wifiStatus = WiFi.status();

      if(wifiStatus == WL_CONNECTED){
         Serial.println("");
         Serial.println("Your ESP is connected!");  
         Serial.println("Your IP address is: ");
         Serial.println(WiFi.localIP());
          Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
           Firebase.set("redlight", 0);
//         // Firebase.log("HOLA!!!!!");
////         console.log("asadadad");
//            String s = "messages";  
//             Firebase.pushString(s,"holla");
      }
      else{
        Serial.println("");
        Serial.println("WiFi not connected");
      }
      delay(1000); // check for connection every once a second

}
