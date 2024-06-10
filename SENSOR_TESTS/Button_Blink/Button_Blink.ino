/*
Keyestudio smart home Kit for Arduino
Project 4
Button
http://www.keyestudio.com
*/

//TASK 2

//FOR BUZZER

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
int tune [] = // List each frequency according to the notation
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
float durt [] = // List the beats according to the notation
{
  1,1,1,1,
  1,1,1,1,
  1,1,1,1,
  1 + 0.5,0.5,1 + 1,
  1,1,1,1,
  1,1,1,1,
  1,1,1,1,
  1 + 0.5,0.5,1 + 1,
  1,1,1,1,
  1,0.5,0.5,1,1,
  1,0.5,0.5,1,1,
  1,1,1,1,
  1,1,1,1,
  1,1,1,0.5,0.5,
  1,1,1,1,
  1 + 0.5,0.5,1 + 1,
};
int length;
int tonepin = D7; // Use interface 3

//for button
int ledpin = D3; // Define the led light in D5
int inpin = D5; // Define the button in D4
int val; // Define variable val

void setup ()
{
pinMode (ledpin, OUTPUT); // The LED light interface is defined as output
pinMode (inpin, INPUT); // Define the button interface as input

//buzzer
pinMode (tonepin, OUTPUT);
length = sizeof (tune) / sizeof (tune [0]); // Calculate length
}

void playOdetoJoy() {
  for (int x = 0; x <length; x ++)
  {
    tone (tonepin, tune [x]);
    delay (350* durt [x]); // This is used to adjust the delay according to the beat, 350 can be adjusted by yourself.
    noTone (tonepin);
  }
  delay (2000); // delay 2S
}

int count = 0;

void loop ()
{
val = digitalRead (inpin); // Read the digital 4 level value and assign it to val
if (val == LOW) // Whether the key is pressed, the light will be on when pressed
{
  count = count + 1;
  digitalWrite (ledpin, HIGH);
  delay(1000);
}
else
{
  digitalWrite (ledpin, LOW);
}

if (count == 5) {
   playOdetoJoy();
 }
}

// TASK 1

// int ledpin = D3; // Define the led light in D5
// int inpin = D5; // Define the button in D4
// int val; // Define variable val
// void setup ()
// {
// pinMode (ledpin, OUTPUT); // The LED light interface is defined as output
// pinMode (inpin, INPUT); // Define the button interface as input
// }
// void loop ()
// {
// val = digitalRead (inpin); // Read the digital 4 level value and assign it to val
// if (val == LOW) // Whether the key is pressed, the light will be on when pressed
// {digitalWrite (ledpin, LOW);}
// else
// {digitalWrite (ledpin, HIGH);}
// }