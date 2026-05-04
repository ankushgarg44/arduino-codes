#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  Serial.println("Bluetooth ready. Send commands via phone.");
}

void loop() {
  if (bluetooth.available()) {
    char cmd = bluetooth.read();
    Serial.print("Received: ");
    Serial.println(cmd);

    if (cmd == '1') {
      Serial.println("LED ON");
    } else if (cmd == '0') {
      Serial.println("LED OFF");
    }
  }

  if (Serial.available()) {
    bluetooth.write(Serial.read());
  }
}