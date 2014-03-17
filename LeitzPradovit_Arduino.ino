#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <AltSoftSerial.h>

AltSoftSerial altSerial;
LiquidCrystal_I2C lcd(0x27,16,2); 

int left=12;
int right=13;
int advanceDelay=4;
int highRef=5;

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
  
}

void loop() {
  digitalWrite(highRef,HIGH);
  char c;
  char cmd;
  char l='1';
  char r='2';
  int state=0;
  state=digitalRead(advanceDelay);

  
  
  if (altSerial.available()) {
      c = altSerial.read();
      lcd.setCursor(0,1); //newline
      lcd.print("Focusing!");
      Serial.print(c);
    
    
     if (state==1){
   digitalWrite(left,LOW);
   digitalWrite(right,LOW);
   delay(2000); 
   digitalWrite(left,HIGH);
   digitalWrite(right,LOW);
   delay(500);
  }
  
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
  
//  if (altSerial.available()){
//    cmd=altSerial.read();
//      lcd.setCursor(0,1); //newline
//      lcd.print("Focusing!");
//    switch (cmd){
//    case '1':
//    
//      Serial.print("left");
//      digitalWrite(left,HIGH);
//      digitalWrite(right,LOW);
//    case '2':
//      Serial.print("right");
//      digitalWrite(left,LOW);
//      digitalWrite(right,HIGH);
//    
//    default:
//    
//      Serial.print("stop");
//      digitalWrite(left,LOW);
//      digitalWrite(right,LOW);
//      lcd.setCursor(0,1);
//  }
  }
}
  

//  }

