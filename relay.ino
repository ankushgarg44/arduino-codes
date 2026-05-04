int relayPin = 7;

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // Relay off (active LOW)
  Serial.begin(9600);
}

void loop() {
  Serial.println("Relay ON");
  digitalWrite(relayPin, LOW);
  delay(3000);

  Serial.println("Relay OFF");
  digitalWrite(relayPin, HIGH);
  delay(3000);
}