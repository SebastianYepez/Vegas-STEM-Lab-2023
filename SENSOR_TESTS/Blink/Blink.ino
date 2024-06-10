/*
Keyestudio smart home Kit for Arduino
Project 1
Blink
http://www.keyestudio.com
*/
void setup() {
  // initialize digital pin 12 (D12) as an output.
  pinMode(D1, OUTPUT);
}

int count = 0;
// the loop function runs over and over again forever
void loop() {
  
  //TASK 1
  // digitalWrite(26, HIGH);   // turn the LED on (HIGH is the voltage level)
  // delay(5000);              // wait for a second
  // digitalWrite(26, LOW);    // turn the LED off by making the voltage LOW
  // delay(1000);              // wait for a second

  // TASK 2
  // digitalWrite(26, HIGH);   // turn the LED on (HIGH is the voltage level)
  // delay(50);              // wait for a second
  // digitalWrite(26, LOW);    // turn the LED off by making the voltage LOW
  // delay(50);              // wait for a second

  count++;
  digitalWrite(D1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(D1, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second

  // if (count == 3) {
  //   delay(9000);
  //   count = 0;
  // }

}//
