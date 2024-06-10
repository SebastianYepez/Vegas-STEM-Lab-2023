// /*
// Keyestudio smart home Kit for Arduino
// Project 12
// 1602 LCD
// http://www.keyestudio.com
// */
// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>
// LiquidCrystal_I2C lcd (0x27,16,2); // set the LCD address to 0x27 for a16 chars and 2 line display
// void setup ()
// {
// lcd.init (); // initialize the lcd
// // lcd.init (); // initialize the lcd
//  // Print a message to the LCD.
// lcd.backlight ();
// lcd.clear (); // Clear the screen
// lcd.setCursor (3,0);
// //lcd.setCursor (0,0);
// //lcd.print ("Hello, world!"); // LED print hello, world!
// lcd.print ("Hey!");
// lcd.setCursor (0,1);
// lcd.print ("Vegas Stem Lab!"); // LED print keyestudio!
// }
// void loop ()
// {
// }
// //

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27,16,2); // set the LCD address to 0x27 for a16 chars and 2 line display
void setup ()
{
lcd.init (); // initialize the lcd
lcd.init (); // initialize the lcd
// Print a message to the LCD.
lcd.backlight ();
lcd.clear (); // Clear the screen

lcd.setCursor (3,0);
lcd.print ("Hello, world!"); // LED print hello, world!
lcd.setCursor (2,1);
lcd.print ("keyestudio!"); // LED print keyestudio!
}
void loop ()
{
}
