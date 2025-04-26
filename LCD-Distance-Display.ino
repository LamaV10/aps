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
  // distance in cm
  distance = (duration/2) * 0.03434;

  lcd.setCursor(1, 0);
  lcd.print(distance);

  lcd.setCursor(2, 1);
  lcd.clear();
  if(distance < 2){
    lcd.print("----------------");
  } else if(distance < 4){
    lcd.print("---------------");
  } else if(distance < 6){
    lcd.print("--------------");
  } else if(distance < 8){
    lcd.print("-------------");
  } else if(distance < 10){
    lcd.print("------------");
  } else if(distance < 12){
    lcd.print("-----------");
  } else if(distance < 14){
    lcd.print("----------");
  } else if(distance < 16){
    lcd.print("---------");
  } else if(distance < 18){
    lcd.print("---------");
  } else if(distance < 20){
    lcd.print("--------");
  } else if(distance < 22){
    lcd.print("-------");
  } else if(distance < 24){
    lcd.print("------");
  } else if(distance < 26){
    lcd.print("-----");
  } else if(distance < 28){
    lcd.print("----");
  } else if(distance < 30){
    lcd.print("---");
  } else if(distance < 32){
    lcd.print("--");
  } else if(distance < 34){
    lcd.print("-");
}
}
