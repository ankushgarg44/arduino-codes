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