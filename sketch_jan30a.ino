/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 https://docs.arduino.cc/learn/electronics/lcd-displays

*/

// include the library code:
#include <LiquidCrystal.h>
#include <ezButton.h>

#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A1 // Arduino pin connected to VRY pin
#define SW_PIN   10  // Arduino pin connected to SW  pin

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
ezButton button(SW_PIN);

int xValue = 0;
int yValue = 0;
int bValue = 0; // To store value of the button

int score = 0;

byte dino[8] = {
  B00111,
  B01111,
  B01100,
  B01111,
  B11110,
  B01110,
  B01010,
  B01010,
};
byte building[8] = {
  B11111,
  B10111,
  B11101,
  B11111,
  B10111,
  B11111,
  B11011,
  B11011,
};
byte blank[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.createChar(0, dino);
  lcd.createChar(1, building);
  lcd.createChar(2, blank);

  lcd.begin(16, 2);
  lcd.setCursor(3,1);
  lcd.write(byte(0));

  button.setDebounceTime(0); // set debounce time to 50 milliseconds
  lcd.setCursor(8,0);
  lcd.print("Score:");
  lcd.print(score);

}

void incrementScore(){
  score += 1;
  lcd.setCursor(14, 0);
  lcd.print(score);
}
void jump(){
  lcd.setCursor(3,1);
  lcd.write(byte(2));
  lcd.setCursor(3,0);
  lcd.write(byte(0));
  delay(200);
  lcd.setCursor(3,0);
  lcd.write(byte(2));
  lcd.setCursor(3,1);
  lcd.write(byte(0));
}
void loop() 
{
  button.loop(); // MUST call the loop() function first
  bValue = button.getState();
  if (button.isPressed()) {
    jump();
    incrementScore();
    Serial.println(bValue);
  }
button.
  // for(int i = 15; i >= 4; i--){
  //   lcd.setCursor(i,1);
  //   lcd.write(byte(1));
  //   delay(1000);
  //   lcd.setCursor(i,1);
  //   lcd.write(byte(2));
  // }
}