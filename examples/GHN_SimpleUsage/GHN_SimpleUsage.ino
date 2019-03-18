
#include <ESP8266WiFi.h>

// #include "/home/amogoi/ourhab/3rd-party/sketch-libs/esp8266-google-home-notifier/src/ESP8266mDNS.h"
// #include "esp8266-google-home-notifier/src/ESP8266mDNS.h"
// #include <esp8266-google-home-notifier/src/ESP8266mDNS.h>
#include <google-tts.h>
#include <esp8266-google-home-notifier.h>


#include <Wire.h>
#include <DallasTemperature.h>


const char* ssid     = _S_WIFI_SSID ;
const char* password = _S_WIFI_PASS ;


GoogleHomeNotifier ghn;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("");
  Serial.print("connecting to Wi-Fi");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("connected.");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //Print the local IP


  TTS tts;
  Serial.println(tts.getSpeechUrl("こんにちは、世界！", "ja"));
  Serial.println(tts.getSpeechUrl("Hello, World!"));


  const char displayName[] = "Office";

  Serial.println("connecting to Google Home...");
  if (ghn.device(displayName, "en") != true) {
    Serial.println(ghn.getLastError());
    return;
  }
  Serial.print("found Google Home(");
  Serial.print(ghn.getIPAddress());
  Serial.print(":");
  Serial.print(ghn.getPort());
  Serial.println(")");

  if (ghn.notify("Hello, World!") != true) {
    Serial.println(ghn.getLastError());
    return;
  }
  Serial.println("Done.");
}

void loop() {
  // put your main code here, to run repeatedly:

}
