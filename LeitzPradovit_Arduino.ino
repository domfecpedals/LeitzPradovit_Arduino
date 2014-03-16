#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <AltSoftSerial.h>

AltSoftSerial altSerial;
LiquidCrystal_I2C lcd(0x27,16,2); 

int left=12;
int right=13;
int advanceDelay=14;
int highRef=15;

void setup() {
  Serial.begin(4800);
  Serial.println("AltSoftSerial monitor");
  altSerial.begin(9600);
  Serial.println("Leitz Pradovit Begain");
  pinMode(left,OUTPUT);
  pinMode(right,OUTPUT);
  pinMode(advanceDelay,INPUT);
  pinMode(highRef,OUTPUT);
  lcd.init(); // initialize the lcd 
  lcd.backlight(); //Open the backlight
  lcd.print("Leitz Pradovit"); // Print a message to the LCD.
  lcd.setCursor(0,1); //newline
  lcd.print("Initialized");// Print a message to the LCD
  digitalWrite(highRef,HIGH);
}

void loop() {
  char c;
  char l='1';
  char r='2';
  
  
  if (advanceDelay==HIGH){
   delay(1000); 
  }
  
  if (altSerial.available()) {
    c = altSerial.read();
      lcd.setCursor(0,1); //newline
      lcd.print("Focusing!");
    
    Serial.print(c);
    if (c==l){

      Serial.print("left");
      digitalWrite(left,HIGH);
      digitalWrite(right,LOW);
//      lcd.setCursor(0,0); //newline
//      lcd.print("Motor Left");
    }
    else if(c==r)
    {

      Serial.print("right");
      digitalWrite(left,LOW);
      digitalWrite(right,HIGH);
//      lcd.setCursor(0,1); //newline
//      lcd.print("Motor Right");
    }
    else 
    {

      Serial.print("stop");
      digitalWrite(left,LOW);
      digitalWrite(right,LOW);
      lcd.setCursor(0,1); //newline
//      lcd.print("Focused");
    }
  }
}
