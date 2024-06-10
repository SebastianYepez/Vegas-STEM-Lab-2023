 /*
Keyestudio smart home Kit for Arduino
Project 2
PWM
http://www.keyestudio.com
*/
int freq = 5000;
int ledChannel = 0;
int resolution = 8;
 #define LED_BUILTIN 25

//int ledPin = 35; // Define the LED pin at D5
void setup () {
  Serial.begin(115200);
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(LED_BUILTIN, ledChannel);
     // pinMode (ledPin, OUTPUT); // initialize ledpin as an output.
}
void loop () {
for (int value = 0; value<255; value = value + 1) {
     ledcWrite (ledChannel, value); // LED lights gradually light up
     delay (5); // delay 5MS
   }
   Serial.println("MAX");
   delay(4000); //Task 1 //4000 because it accounts for >1s of for loop
   for (int value = 255; value>0; value = value-1) {
     ledcWrite (ledChannel, value); // LED gradually goes out
     delay (5); // delay 5MS
   }}
//