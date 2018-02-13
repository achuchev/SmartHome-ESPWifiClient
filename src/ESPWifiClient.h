#ifndef ESP_WIFI_CLIENT_H
#define ESP_WIFI_CLIENT_H

#include <Arduino.h>

class ESPWifiClient {
public:

  ESPWifiClient(const char *ssid,
                const char *password);
  void init();
  void reconnectIfNeeded();

private:

  const char *ssid;
  const char *password;
};

#endif // ifndef ESP_WIFI_CLIENT_H
