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