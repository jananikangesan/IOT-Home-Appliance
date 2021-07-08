/*
  LiquidCrystal Library 

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.


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
*/

// include the library code:
#include <LiquidCrystal.h>
#define trigpin 6
#define echopin 7
int buzzer=8;


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
    
Serial.begin(9600);
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
pinMode(buzzer,OUTPUT);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  
  int duration,distance;
  
digitalWrite(trigpin,HIGH);
delayMicroseconds(1000);
digitalWrite(trigpin,LOW);
duration=pulseIn(echopin,HIGH);
distance=(duration/2)/29;//distance in centimeters
 
 Serial.print("distance:"); 
 Serial.print(distance);
 Serial.print("cm"); 

if(distance>=80 || distance<=0){
  
Serial.println("------> no object detected");
digitalWrite(buzzer,LOW);
  lcd.setCursor(0, 1);
 lcd.print("Doorbell is Off");  
}
  
else{
  lcd.clear(); 
Serial.println("------>object detected");
 lcd.setCursor(1, 1);
 lcd.print("Wel Come!!!");
  
tone(buzzer,400);//play 400Hz tone for 500ms
delay(500);
tone(buzzer,800);//play 800Hz tone for 500ms
 delay(500);
tone(buzzer,400);//play 400Hz tone for 500ms
delay(500);
tone(buzzer,800);//play 800Hz tone for 500ms
delay(500);
tone(buzzer,400);//play 400Hz tone for 500ms
delay(500);
tone(buzzer,800);//play 800Hz tone for 500ms
delay(500);     
noTone(buzzer);
  
lcd.clear();  
}  
delay(300);
    
}
 