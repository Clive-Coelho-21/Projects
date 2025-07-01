#include <Servo.h>

const int trigPin = 9;    
const int echoPin = 10;
const int buzzerPin = 11;

Servo Servo;       
int distance;
long duration;

void setup()    
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(256000);
  Servo.attach(6);              
}

void loop() 
{
  calculateDistance();
  if(distance >=0 && distance <= 30) 
  {
   for(int angle=30;angle<=150;angle++)
   {
    calculateDistance(); 
    Servo.write(angle); 
    Serial.print(angle);         
    Serial.print(",");           
    Serial.print(distance); 
    Serial.print(".");          
    delay(30);
   }
        
   for(int angle=150;angle>=30;angle--)
   {  
    calculateDistance();    
    Servo.write(angle); 
    Serial.print(angle);        
    Serial.print(",");          
    Serial.print(distance);
    Serial.print(".");   
    delay(30);
    }
  } 
  else 
  {
    for(int angle=0;angle<=180;angle++)
    { 
      calculateDistance();
      Servo.write(angle);        
      Serial.print(angle);        
      Serial.print(",");          
      Serial.print(distance);  
      Serial.print("."); 
      delay(30); 
    }
        
    for(int angle=180;angle>=0;angle--)
    {  
      calculateDistance();        
      Servo.write(angle); 
      Serial.print(angle);        
      Serial.print(",");         
      Serial.print(distance);   
      Serial.print(".");
      delay(30);
      }
    }
    adjustBuzzer(distance);
}

void calculateDistance() 
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration=pulseIn(echoPin, HIGH);    
    distance= duration*0.034/2;
}
  
void adjustBuzzer(int distance) 
{
  if (distance <= 10) 
  {
    tone(buzzerPin, 100);          
    //delay(100);
  } 
  else if (distance <= 20) 
  {
    tone(buzzerPin, 500);           
    //delay(500);
  } 
  else if (distance <= 30) 
  {
    tone(buzzerPin, 1000);          
    //delay(1000);
  } 
  else
  {
    noTone(buzzerPin);              
  }
}