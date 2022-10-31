#include <Servo.h> 

//#include <LiquidCrystal.h>
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define servo 9  
#define ldr1 A0  
#define ldr2 A1  

Servo myservo;
int initial_position = 90;
int tolerance = 2;
int pos ;

void setup() {
  
  //lcd.begin(16, 2);
  
  myservo.attach(servo);
  myservo.write(initial_position);
  Serial.begin(9600);
  delay(2000);
  
}

void loop() {

 int volt1 = analogRead(ldr1);
 int volt2 = analogRead(ldr2); 

 if((abs(volt1 - volt2) <= tolerance) || (abs(volt2 - volt1) <= tolerance)) {
     pos= initial_position;
  } else {    
    if(volt1 > volt2)
    {
      pos = --initial_position;
    }
    if(volt1 < volt2) 
    {
      pos = ++initial_position;
    }
  }

  if(pos > 180) {
    pos = 180; 
    } 
  if(pos < 0) { 
    pos = 0; 
    } 
  
  myservo.write(pos); 
  delay(50);
  
  // lcd.setCursor(0, 0);
  // lcd.print("Servo");
  // lcd.setCursor(0, 1);
  // lcd.print(pos);
  
  Serial.print("sensorValue1: ");
  Serial.println(volt1);
  Serial.print(' ');
  Serial.print("sensorValue2: ");
  Serial.println(volt2);
  Serial.print('\n');
  delay(500);

}
