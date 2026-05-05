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