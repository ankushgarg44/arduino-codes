#define ENABLE_DEBUG

#ifdef ENABLE_DEBUG
#define DEBUG_ESP_PORT Serial
#define NODEBUG_WEBSOCKETS
#define NDEBUG
#endif

#include <WiFi.h>
#include <SinricPro.h>
#include <SinricProSwitch.h>

#define WIFI_SSID     "Garg"
#define WIFI_PASS     "00000000"

#define APP_KEY       "283ef64c-bbbc-48e5-b4c9-38c30d85e68d"
#define APP_SECRET    "c3fde2a1-c857-44a1-bf97-b52442b5c1f9-eclc11d2-cb7d-403d-b8ed-9203617a87cd"

#define DEVICE_ID     "69d4dc0052800e7ce360c1d5"

#define LED_PIN 15

bool onPowerState(const String &deviceId, bool &state) {
  Serial.printf("Device turned %s\n", state ? "ON" : "OFF");

  digitalWrite(LED_PIN, state);

  return true;
}

void setupWiFi() {
  Serial.print("Connecting to WiFi");
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("\nWiFi Connected!");
}

void setupSinricPro() {
  SinricProSwitch &mySwitch = SinricPro[DEVICE_ID];

  mySwitch.onPowerState(onPowerState);

  SinricPro.begin(APP_KEY, APP_SECRET);
}

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  setupWiFi();
  setupSinricPro();
}

void loop() {
  SinricPro.handle();
}