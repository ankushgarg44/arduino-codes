// ========================================
// COMBINED ARDUINO CODES
// ========================================
// This file contains all Arduino sketches combined with comments
// ========================================

// ========================================
// FILE: assistant.ino
// ========================================
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

// ========================================
// FILE: bluetoothled.ino
// ========================================
char data;    // Variable to store received Bluetooth data

void setup()
{
   Serial.begin(9600);        // HC-05 default baud rate
   pinMode(13, OUTPUT);       // LED connected to pin 13
   digitalWrite(13, LOW);     // LED initially OFF
}

void loop()
{
   if (Serial.available() > 0)     // Check if data is received
   {
       data = Serial.read();       // Read received data
       Serial.println(data);       // Print data for debugging

       if (data == '1')            // If '1' received
       {
           digitalWrite(13, HIGH); // Turn LED ON
       }
       else if (data == '0')       // If '0' received
       {
           digitalWrite(13, LOW);  // Turn LED OFF
       }
   }
}

// ========================================
// FILE: blynk.ino
// ========================================
#define BLYNK_TEMPLATE_ID "TMPL3h7iZACnt"
#define BLYNK_TEMPLATE_NAME "LED"
#define BLYNK_AUTH_TOKEN "hnnhtFGTRHHErASu3VRIAwgPC_p6I6O"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Tu";
char pass[] = "tu@inet1";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();
}

// ========================================
// FILE: dht.ino
// ========================================
#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperaturrre();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to reaad from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println("Temperature: ");
  Serial.print(t);
  Serial.println(" °C");

  delay(2000);
}

// ========================================
// FILE: dhtled.ino
// ========================================
#include <DHT.h>
#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int redLED1 = 3;
int redLED2 = 4;
int redLED3 = 5;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(redLED1, OUTPUT);
  pinMode(redLED2, OUTPUT);
  pinMode(redLED3, OUTPUT);
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C, Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  if (humidity >= 80 || temperature >= 28) {
    digitalWrite(redLED1, HIGH);
    digitalWrite(redLED2, HIGH);
    digitalWrite(redLED3, HIGH);
  }
  else if (humidity >= 70 || temperature < 26) {
    digitalWrite(redLED1, LOW);
    digitalWrite(redLED2, HIGH);
    digitalWrite(redLED3, HIGH);
  }
  else {
    digitalWrite(redLED1, LOW);
    digitalWrite(redLED2, LOW);
    digitalWrite(redLED3, HIGH);
  }

  delay(1000);
}

// ========================================
// FILE: hc05dht11.ino
// ========================================
#include <SoftwareSerial.h>
#include <DHT11.h>

#define DHT11PIN 4   // DHT11 DATA pin

DHT11 dht11(DHT11PIN);
SoftwareSerial hc05(2, 3);  // RX, TX

void setup() {
  Serial.begin(9600);
  hc05.begin(9600);
}

void loop() {
  int temperature = 0;
  int humidity = 0;

  int result = dht11.readTemperatureHumidity(temperature, humidity);

  if (result == 0) {
    // Send via Bluetooth
    hc05.print("Temperature: ");
    hc05.print(temperature);
    hc05.print(" C | Humidity: ");
    hc05.print(humidity);
    hc05.println(" %");

    // Print on Serial Monitor
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" C | Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  } else {
    hc05.println("DHT11 Read Error");
    Serial.println("DHT11 Read Error");
  }

  delay(2000);  // REQUIRED for DHT11
}

// ========================================
// FILE: ldr.ino
// ========================================
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  unsigned int AnalogValue;
  AnalogValue = analogRead(A0);
  Serial.println(AnalogValue);
}

// ========================================
// FILE: ldrled.ino
// ========================================
int ldrPin = A0;

int led1 = 3;
int led2 = 4;
int led3 = 5;

int ldrValue;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  ldrValue = analogRead(ldrPin);
  Serial.println(ldrValue);

  // Dark
  if (ldrValue < 300) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
  // Medium light
  else if (ldrValue < 800) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  }
  // Bright
  else {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }

  delay(200);
}

// ========================================
// FILE: led.ino
// ========================================
int ledPin = 2;

void setup() {

    pinMode(ledPin, OUTPUT);
}

void loop() {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(2000);
}

// ========================================
// FILE: pushbutton.ino
// ========================================
const int buttonPin = 13;
const int ledPin = 9;
void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  void loop()
  {
    currentState = digitalRead(buttonPin);
    if (currentState == LOW)
    {
    }
    digitalWrite(ledPin, HIGH);
    else if (currentState == HIGH)
    {
      digitalWrite(ledPin, LOW);
    }
    delay(50);
  }
}

// ========================================
// FILE: wifi.ino
// ========================================
#include <WiFi.h>

const char* ssid = "Garg";
const char* password = "00000000";

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);

    Serial.print("Connecting to WiFi");

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nConnected!");
    Serial.println(WiFi.localIP());
}

void loop() {}

// bluetooth
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
    Serial.begin(115200);
    SerialBT.begin("ESP32test"); // Bluetooth name
    Serial.println("Bluetooth Started! Pair device.");
}

void loop() {
    if (Serial.available()) {
        SerialBT.write(Serial.read());
    }

    if (SerialBT.available()) {
        Serial.write(SerialBT.read());
    }

    delay(20);
}

// ========================================
// END OF COMBINED FILE
// ========================================
