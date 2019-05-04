#ifndef ESP_WIFI_CLIENT_H
#define ESP_WIFI_CLIENT_H

#include <Arduino.h>
#include <ESP8266WiFiMulti.h>

class ESPWifiClient {
public:

  ESPWifiClient(const char   *ap1ssid,
                const char   *ap1password,
                const char   *ap2ssid             = NULL,
                const char   *ap2password         = NULL,
                unsigned long delayBetweenRetries = 500);
  void init();
  void reconnectIfNeeded();

private:

  const char *ap1ssid;
  const char *ap1password;
  const char *ap2ssid;
  const char *ap2password;
  unsigned long delayBetweenRetries;
  ESP8266WiFiMulti wifiMulti;
};

#endif // ifndef ESP_WIFI_CLIENT_H
