/*
Keyestudio smart home Kit for Arduino
Project 10
PIR
http://www.keyestudio.com
*/

void setup () {
   Serial.begin (115200); // open serial port, and set baud rate at 9600bps
   pinMode (D5, INPUT); // Define PIR as input in D2
    Serial.begin (115200); // open serial port, and set baud rate at 9600bps
   pinMode (D13, OUTPUT); // Define LED as output in D13
   pinMode (D7, OUTPUT); // Define D7 as output
   pinMode (D6, OUTPUT); // Define D6 as output
   pinMode (D3, OUTPUT); //Define D1 (buzzer) as output
}

void loop () {
   Serial.println (digitalRead (D5));
   delay (500); // Delay 500ms //adjusted to 5000
   if (digitalRead (D5) == 1) // If someone is detected walking
  {
     digitalWrite (D13, HIGH); // LED light is on
     digitalWrite (D7, HIGH);
      digitalWrite (D6, LOW);
 // Fan rotates
      // digitalWrite (D1, HIGH); // Sound
      //      delay (10); // delay 2ms
      //      digitalWrite (D1, LOW); // No sound
      for (int j = 0; j <100; j ++) // output sound of another frequency
         {
           digitalWrite (D3, HIGH); // Sound
           delay (1); // delay 1ms
           digitalWrite (D3, LOW); // No sound
           delay (1); // delay 1ms
         }

   } else // If no person is detected walking
{
     digitalWrite (D13, LOW); // LED light is not on
     digitalWrite (D7, LOW);
      digitalWrite (D6, LOW);
 // The fan does not rotate
   }}
//