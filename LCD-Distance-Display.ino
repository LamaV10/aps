#include "LiquidCrystal.h"
#define trigger 13
#define echo 12

int duration; // time the waves need to come back 
int distance; // distance in cm
int printDelay; // later used for printing the distance more readable 

// Create an LCD object. Parameters: (RS, E, D4, D5, D6, D7):
LiquidCrystal lcd = LiquidCrystal(2, 3, 4, 5, 6, 7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); // Specify the LCD's number of columns and rows

  // ultrasonic-sensor
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  // print the stationary things
  lcd.home(); // go to 0, 0
  lcd.print("Distance: ");
  lcd.setCursor(13, 0);
  lcd.print("cm"); // print the unit of the distance 
}

void loop() {
  digitalWrite(trigger, LOW);
  delay(5);
  digitalWrite(trigger, HIGH);
  delay(10);
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2) * 0.03434; 

  if(distance > 0){
    // a little delay for printing otherwise it's hardly readable
    if(printDelay >= 10){
      lcd.setCursor(10, 0);
      lcd.print(distance); // print the distance
      printDelay = 0;
      // deletes the second column, if the number is only one column long
      if(distance < 10){
        lcd.setCursor(11, 0);
        lcd.print(" ");
      } else if(distance < 100){
        lcd.setCursor(12, 0);
        lcd.print(" ");
      }
    } else {
      printDelay++;
    }

    // printing the distance symbols
    lcd.setCursor(0, 1);
    char symbols[17] = ">>>>>>>>>>>>>>>>";
    lcd.setCursor(0, 1);

    if (distance < 2){ // prints the whole array
      lcd.print(symbols);
    } else { // shortens the symbols according to the distance
      for(int i = 0; i < distance; i += 2){
        symbols[15 - i / 2] = ' '; // positions cursor one to the left for the next potential deletion
      }
    }
    lcd.print(symbols);
  }
}
