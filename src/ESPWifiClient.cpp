#include "ESPWifiClient.h"
#include <ESP8266WiFi.h>
#include <RemotePrint.h>
#include <CommonConfig.h>

ESPWifiClient::ESPWifiClient(const char *ssid, const char *password) {
  this->ssid     = ssid;
  this->password = password;
}

void ESPWifiClient::init() {
  delay(10);

  // We start by connecting to a WiFi network
  PRINTLN();
  PRINT("WIFI: Connecting to SSID: ");
  PRINTLN(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    // FIXME: Infinite loop in case of unsuccessful WIFI connection. Add reboot
    // or some timeout
    delay(500);

    PRINT(".");
  }

  PRINTLN();
  PRINT("WIFI: Connected to SSID: ");
  PRINT(                       ssid);
  PRINT(           ". IP address: ");
  PRINTLN(WiFi.localIP().toString());
}
