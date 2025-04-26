// Include the library:
#include "LiquidCrystal.h"
#define trigger 13
#define echo 12

int duration;
int distance;

// Create an LCD object. Parameters: (RS, E, D4, D5, D6, D7):
LiquidCrystal lcd = LiquidCrystal(2, 3, 4, 5, 6, 7);

void setup() {
  // Specify the LCD's number of columns and rows. Change to (20, 4) for a 20x4 LCD:
  lcd.begin(16, 2);

  // ultrasound sensor
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  digitalWrite(trigger, LOW);
  delay(5);
  digitalWrite(trigger, HIGH);
  delay(10);
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2) * 0.03434; // distance in cm

  lcd.setCursor(0, 0);
  lcd.print(distance); // print the distance

  lcd.setCursor(0, 1);
  lcd.print("----------------"); // write the whole row
  lcd.setCursor(15, 1);

  for(int i = 0; i < distance; i += 2){
    lcd.print(" "); // delete the "-" string from the right
    lcd.setCursor(15 - i / 2, 1); // positions cursor one to the left for the next potential deletion
  }
  delay(150); // stops to intense display flickering 
  lcd.clear();
}
