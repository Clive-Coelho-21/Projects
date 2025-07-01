#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

const int trigPin = 9;
const int echoPin = 10;
const int Buzzer = 11;

float distance,duration;
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() 
{
  lcd.init();
  lcd.backlight();

  pinMode(Buzzer,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distance Measurement");
  lcd.setCursor(1,6);
  lcd.print("Project");

  delay(2000);
}

void loop() 
{
  calculateDistance();

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distance:");
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.setCursor(4,1);
  lcd.print("cm");

  if(distance < 10)
  {
    tone(Buzzer,1000);
  }
  else
  {
    noTone(Buzzer);
  }
  
  delay(100);
}

void calculateDistance()
{
  digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = (0.034*duration)/2;
}