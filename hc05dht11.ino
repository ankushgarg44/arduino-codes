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