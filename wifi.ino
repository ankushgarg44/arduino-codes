#include <SoftwareSerial.h>

SoftwareSerial esp8266(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);
  esp8266.begin(115200);
  delay(1000);

  Serial.println("Initializing ESP8266...");
  esp8266.println("AT+RST");
  delay(2000);
  esp8266.println("AT+CWMODE=1");
  delay(1000);
}

void loop() {
  if (esp8266.available()) {
    Serial.write(esp8266.read());
  }
  if (Serial.available()) {
    esp8266.write(Serial.read());
  }
}