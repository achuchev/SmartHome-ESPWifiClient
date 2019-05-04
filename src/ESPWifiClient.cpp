#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <RemotePrint.h>
#include "ESPWifiClient.h"

ESPWifiClient::ESPWifiClient(const char *ap1ssid, const char *ap1password, const char *ap2ssid,
                             const char *ap2password, unsigned long delayBetweenRetries) {
  this->ap1ssid             = ap1ssid;
  this->ap1password         = ap1password;
  this->ap2ssid             = ap2ssid;
  this->ap2password         = ap2password;
  this->delayBetweenRetries = delayBetweenRetries;
}

void ESPWifiClient::init() {
  delay(10);

  // We start by connecting to a WiFi network
  PRINTLN();
  PRINT("WIFI: Connecting to AP '");
  PRINT(                      this->ap1ssid);
  PRINT(                       "'");

  WiFi.mode(WIFI_STA);
  wifiMulti.addAP(this->ap1ssid, this->ap1password);

  if (ap2ssid != NULL) {
    PRINT(" or AP '");
    PRINT(      this->ap2ssid);
    PRINT(       "'");
    wifiMulti.addAP(this->ap2ssid, this->ap2password);
  }
  PRINTLN(".");

  if (wifiMulti.run() == WL_CONNECTED) {
    PRINTLN();
    PRINT("WIFI: Connected to WiFi. IP address: ");
    PRINTLN(WiFi.localIP().toString());
  }
}

void ESPWifiClient::reconnectIfNeeded() {
  if (wifiMulti.run() != WL_CONNECTED) {
    PRINT_D("WiFi not connected! Waiting ");
    PRINT_D(                          this->delayBetweenRetries);
    PRINT_D(                "miliseconds.");
    delay(this->delayBetweenRetries);
    PRINTLN_D();
  }
}
