#include "LiquidCrystal.h"
#define trigger 13
#define echo 12

int duration;
int distance;
int printDelay;

// Create an LCD object. Parameters: (RS, E, D4, D5, D6, D7):
LiquidCrystal lcd = LiquidCrystal(2, 3, 4, 5, 6, 7);

void setup() {
  Serial.begin(9600);
  // Specify the LCD's number of columns and rows:
  lcd.begin(16, 2);

  // ultrasonic-sensor
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
 
  if(distance > 0){
    // print the stationary things
    lcd.home(); // go to 0, 0
    lcd.print("Distance: ");
    lcd.setCursor(13, 0);
    lcd.print("cm"); // print the unit of the distance 
  
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
    lcd.print(">>>>>>>>>>>>>>>>"); // write the whole row full with "-" 
    lcd.setCursor(15, 1);

    // delete the symbols according to the distance
    for(int i = 0; i < distance; i += 2){
      lcd.print(" "); // delete the "-" string from the right
      lcd.setCursor(15 - i / 2, 1); // positions cursor one to the left for the next potential deletion
    }
  }
}
