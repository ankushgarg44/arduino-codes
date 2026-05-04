int buzzerPin = 8;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  tone(buzzerPin, 262, 500); // C4
  delay(600);
  tone(buzzerPin, 294, 500); // D4
  delay(600);
  tone(buzzerPin, 330, 500); // E4
  delay(600);
  tone(buzzerPin, 349, 500); // F4
  delay(600);
  tone(buzzerPin, 392, 500); // G4
  delay(600);
  noTone(buzzerPin);
  delay(1000);
}