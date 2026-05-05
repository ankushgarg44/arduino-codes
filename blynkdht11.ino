#define BLYNK_TEMPLATE_ID "TMPL3iFOKybXa"
#define BLYNK_TEMPLATE_NAME "DHT"
#define BLYNK_AUTH_TOKEN "jy-ZBEI2udQacBverAbqCTpvleS6CBau"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char ssid[] = "TU";
char pass[] = "tu@inet1";
char auth[] = BLYNK_AUTH_TOKEN;

#define DHTPIN 18   // GPIO4 (D4) where the DHT11 is connected
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  Serial.begin(115200); // Debugging on hardware Serial0
  Blynk.begin(auth, ssid, pass);
  dht.begin();
}

void loop()
{
  Blynk.run();
  readDHT11();
}

void readDHT11()
{
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature))
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Temperature: "));
  Serial.print(temperature);
  Serial.println(F(" °C"));

  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.println(F(" %"));

  Blynk.virtualWrite(V1, temperature);
  Blynk.virtualWrite(V0, humidity);
}