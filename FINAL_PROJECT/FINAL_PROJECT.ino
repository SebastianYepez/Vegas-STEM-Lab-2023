/*

Author: Sebastian Yepez
Date: June 2023

*/

//EXCLUDES STEAM, PHOTOCELL, and GAS SENSORS as well as WATER PUMP - TOO MUCH POWER

/*

LIBRARIES

*/
      #include <ESP32Servo.h>  // SERVO

      #include <Wire.h>
      #include <LiquidCrystal_I2C.h>  // LCD

      #include <Adafruit_NeoPixel.h>
      #ifdef __AVR__
      #include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
      #endif
      #define PIN D13
      #define NUMPIXELS 8  //LED STRIP

      #include "Adafruit_Si7021.h"  //TEMPERATURE & HUMIDITY


/*

FOR BUZZER

*/

      #define NTD0 -1
      #define NTD1 294
      #define NTD2 330
      #define NTD3 350
      #define NTD4 393
      #define NTD5 441
      #define NTD6 495
      #define NTD7 556

      #define NTDL1 147
      #define NTDL2 165
      #define NTDL3 175
      #define NTDL4 196
      #define NTDL5 221
      #define NTDL6 248
      #define NTDL7 278

      #define NTDH1 589
      #define NTDH2 661
      #define NTDH3 700
      #define NTDH4 786
      #define NTDH5 882
      #define NTDH6 990
      #define NTDH7 112
      // List all D-tuned frequencies
      #define WHOLE 1
      #define HALF 0.5
      #define QUARTER 0.25
      #define EIGHTH 0.25
      #define SIXTEENTH 0.625
      // List all beats
      int tune[] =  // List each frequency according to the notation
        {
          NTD3, NTD3, NTD4, NTD5,
          NTD5, NTD4, NTD3, NTD2,
          NTD1, NTD1, NTD2, NTD3,
          NTD3, NTD2, NTD2,
          NTD3, NTD3, NTD4, NTD5,
          NTD5, NTD4, NTD3, NTD2,
          NTD1, NTD1, NTD2, NTD3,
          NTD2, NTD1, NTD1,
          NTD2, NTD2, NTD3, NTD1,
          NTD2, NTD3, NTD4, NTD3, NTD1,
          NTD2, NTD3, NTD4, NTD3, NTD2,
          NTD1, NTD2, NTDL5, NTD0,
          NTD3, NTD3, NTD4, NTD5,
          NTD5, NTD4, NTD3, NTD4, NTD2,
          NTD1, NTD1, NTD2, NTD3,
          NTD2, NTD1, NTD1
        };
      float durt[] =  // List the beats according to the notation
        {
          1,
          1,
          1,
          1,
          1,
          1,
          1,
          1,
          1,
          1,
          1,
          1,
          1 + 0.5,
          0.5,
          1 + 1,
          1,
          1,
          1,
          1,
          1,
          1,
          1,
          1,
          1,
          1,
          1,
          1,
          1 + 0.5,
          0.5,
          1 + 1,
          1,
          1,
          1,
          1,
          1,
          0.5,
          0.5,
          1,
          1,
          1,
          0.5,
          0.5,
          1,
          1,
          1,
          1,
          1,
          1,
          1,
          1,
          1,
          1,
          1,
          1,
          1,
          0.5,
          0.5,
          1,
          1,
          1,
          1,
          1 + 0.5,
          0.5,
          1 + 1,
        };
/*

OBJECTS & GLOBAL VARIABLES

*/
      Adafruit_Si7021 sensor = Adafruit_Si7021();
      Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
      Servo myservo;
      LiquidCrystal_I2C mylcd(0x27, 16, 2);  //LCD
      int length;                            //buzzer length
      bool on = false;                       //Yellow LED

/*

FUNCTIONS

*/
void playOdetoJoy() {
  for (int x = 0; x < length; x++) {
    tone(D3, tune[x]);
    delay(350 * durt[x]);  // This is used to adjust the delay according to the beat, 350 can be adjusted by yourself.
    noTone(D3);
  }
}

int count = 0;
volatile int soilVal = 0;
void soilReading() {
  soilVal = analogRead(A2);  // Read the value of the soil sensor
  if (count % 300 == 0) {
    if (soilVal < 300)  // If the value is less than 300
    {
      for(int i=0; i<NUMPIXELS; i++)
        pixels.setPixelColor(i, pixels.Color(255, 0, 0));
      pixels.show();  // Send the updated pixel colors to the hardware.
      mylcd.clear();  // clear screen
      mylcd.setCursor(0, 0);
      mylcd.print("value:");  //
      mylcd.setCursor(6, 0);
      mylcd.print(soilVal);
      mylcd.setCursor(0, 1);
      mylcd.print("dry soil");                        // LCD screen print dry soil
    } else if ((soilVal >= 300) && (soilVal <= 700))  // If the value is greater than 300 and less than 700
    {
      for(int i=0; i<NUMPIXELS; i++)
        pixels.setPixelColor(i, pixels.Color(0, 255, 0));
      pixels.show();  // Send the updated pixel colors to the hardware.
      mylcd.clear();  //clear screen
      mylcd.setCursor(0, 0);
      mylcd.print("value:");
      mylcd.setCursor(6, 0);
      mylcd.print(soilVal);
      mylcd.setCursor(0, 1);
      mylcd.print("humid soil");  // LCD screen printing humid soil
    } else if (soilVal > 700)     // If the value is greater than 700
    {
      for(int i=0; i<NUMPIXELS; i++)
        pixels.setPixelColor(i, pixels.Color(0, 0, 255));
      pixels.show();  // Send the updated pixel colors to the hardware.
      mylcd.clear();  //clear screen
      mylcd.setCursor(0, 0);
      mylcd.print("value:");
      mylcd.setCursor(6, 0);
      mylcd.print(soilVal);
      mylcd.setCursor(0, 1);
      mylcd.print("in water");  /// LCD screen printing in water
    }
  }
  count++;
}

/*

SETUP FUNCTION

*/

void setup() {
  // code that runs ONCE:
  pinMode(25, OUTPUT);  //WHITE LED
  pinMode(D1, OUTPUT);  //YELLOW LED
  pinMode(D3, OUTPUT);  //BUZZER
  length = sizeof(tune) / sizeof(tune[0]);
  pinMode(D5, INPUT);   //MOTION SENSOR
  pinMode(D6, OUTPUT);  //FAN
  pinMode(D7, OUTPUT);  //FAN
  myservo.attach(D9);   // Define the position of the servo on D9
  pinMode(D11, INPUT);  //BUTTON 1
  pinMode(D12, INPUT);  //BUTTON 2
  pinMode(A0, INPUT);   // GAS SENSOR
  pinMode(A2, INPUT);   //SOIL
  pinMode(A3, INPUT);   //STEAM SENSOR
  pinMode(A4, INPUT);
  mylcd.init();
  mylcd.backlight();  // Light up the backlight
  mylcd.clear();      // Clear the screen
  pixels.begin();     // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.clear();     // Set all pixel colors to 'off'
}

/*

LOOP

*/

void loop() {
  // code that runs repeatedly:

  //MOTION SENSOR
  if (digitalRead(D5) == 1)  // If someone is detected walking
  {
    digitalWrite(25, HIGH);  //White LED turns on
  } else {
    digitalWrite(25, LOW);  //White LED turns off
  }

  //LIGHT SWITCH
  int b1Val = digitalRead(D11);
  if (b1Val == LOW) {  //if button is pressed
    on = !on;
    if (on == true) {
      digitalWrite(D1, HIGH);
      delay(300);
    } else {
      digitalWrite(D1, LOW);
      delay(300);
    }
  }

  //DOORBELL + DOOR
  int b2Val = digitalRead(D12);
  if (b2Val == LOW) {
    myservo.write(0);   // The servo angle is pos
    delay(15);          // Delay 15ms
    myservo.write(90);  // The servo angle is pos
    playOdetoJoy();
    delay(15);         // Delay 1000ms
    myservo.write(0);  // The servo angle is pos
    delay(15);         // Delay 15ms
  }


  //TEMP + FAN
  int temp = (sensor.readTemperature() * 1.8) + 32;
  if (temp > 70) {  //if temperature is over 75 degrees
    digitalWrite(D7, HIGH);
    digitalWrite(D6, LOW);
  } else {
    digitalWrite(D7, LOW);
    digitalWrite(D6, LOW);
  }


  //SOIL
  soilReading();
}
