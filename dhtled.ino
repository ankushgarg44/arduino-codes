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