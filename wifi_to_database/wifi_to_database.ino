#include <FirebaseError.h>
#include <FirebaseObject.h>
#include <Firebase.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseHttpClient.h>
#include <FirebaseArduino.h>

#include <ESP8266WiFi.h>
     
    const char* ssid     = "k";
    const char* password = "0987654321";     

    int wifiStatus;

    // Replace with your Carriots apikey
const String APIKEY = "47777777777778c98cbb";
const String DEVICE = "Arduino@Pratham567.Pratham567"; // your deviceID
WiFiClient client;
WiFiServer server(80);
int val = 0;
     
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

//void sendStream()
//{
//  //const int httpPort = 80;
//  if (client.connect(server, 80)) {   // If there's a successful connection
//    Serial.println(F("connected"));
//
//    // construct the data json
//    String json = "{\"protocol\":\"v2\",\"device\":\"" + DEVICE + "\",\"at\":\"now\",\"data\":{\"moisture\":\"" + val + "\"}}";
//
//    // Make an HTTP request
//    client.println("POST /streams HTTP/1.1");
//    client.println("Host: api.carriots.com");
//    client.println("Accept: application/json");
//    client.println("User-Agent: Arduino-Carriots");
//    client.println("Content-Type: application/json");
//    client.print("carriots.apikey: ");
//    client.println(APIKEY);
//    client.print("Content-Length: ");
//    int thisLength = json.length();
//    client.println(thisLength);
//    client.println("Connection: close");
//    client.println();
//    client.println(json);
//  }
//  else {
//    // If server connection failed:
//    Serial.println(F("connection failed"));
//  }
//}
     
void loop() {
      wifiStatus = WiFi.status();

      WiFiClient client = server.available();
  if (!client) {
    return;
  }
   
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
   
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
   
  // Match the request
 
  int value = LOW;
  if (request.indexOf("/LED=ON") != -1) {
    digitalWrite(LED_BUILTIN, HIGH);
    value = HIGH;
  } 
  if (request.indexOf("/LED=OFF") != -1){
    digitalWrite(LED_BUILTIN, LOW);
    value = LOW;
  }
 
  //Set ledPin according to the request
  //digitalWrite(ledPin, value);
   
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
   
  client.print("Led pin is now: ");
   
  if(value == HIGH) {
    client.print("On");  
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("Click <a href=\"/LED=ON\">here</a> turn the LED on pin 2 ON<br>");
  client.println("Click <a href=\"/LED=OFF\">here turn the LED on pin 2 OFF<br>");
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");

}
