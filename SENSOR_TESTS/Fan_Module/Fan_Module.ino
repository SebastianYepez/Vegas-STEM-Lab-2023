/*
Keyestudio smart home Kit for Arduino
Project 8
Fan
http://www.keyestudio.com
*/
void setup () {
   pinMode (D7, OUTPUT); //define D7 pin as output
   pinMode (D6, OUTPUT); //define  D6 pin as output
}
void loop () {
   digitalWrite (D7, LOW);
   digitalWrite (D6, HIGH); // Reverse rotation of the motor
   delay (3000); // delay 3S
   digitalWrite (D7, LOW);
   digitalWrite (D6, LOW); // The motor stops rotating
   delay (1000); //delay 1S
   digitalWrite (D7, HIGH);
   digitalWrite (D6, LOW); // The motor rotates in the forward direction
   delay (3000); // delay 3S
}
//