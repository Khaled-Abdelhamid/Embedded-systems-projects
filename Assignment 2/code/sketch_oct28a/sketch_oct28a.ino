#include <MedianFilter.h>

const int trigPin = 5; // PWM trigger
const int echoPin=3;// PWM Output 0-25000US,Every 50US represent 1cm
long duration; // defines variables
float distance;
int test;
// the pen numbers of the leds
int pred=11;
int pgreen=10;
int pblue=9;
int pyellow=8;
MedianFilter filter(3, 0); //define median filter object

void setup()
{
 
  pinMode(trigPin, OUTPUT); //Sets the trigPin as an Output 
  pinMode(pred, OUTPUT); 
  pinMode(pgreen, OUTPUT);
  pinMode(pblue, OUTPUT); 
  pinMode(pyellow, OUTPUT); 
  
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); //configure baud rate of Serial communication to 9600 bps
}
void loop()
{
  digitalWrite(trigPin, LOW); //Clears the trigPin
  delayMicroseconds(2); // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  //median filter logic
  duration=pulseIn(echoPin,HIGH);// Reads the echoPin, returnsthe sound wave travel time in microseconds
  distance= duration*0.034/2;
  filter.in(distance);
  distance = filter.out();
  distance=distance*2.0/1050.0;// to map the values of the sensor to the test range (for d)
  test=analogRead(A0);
  
  Serial.print("Distance Measured="); // Prints the distance on the Serial Monitor
  Serial.print(distance);
  Serial.println("cm");
  
  
  if (distance>=2)
  {
    digitalWrite(pred, HIGH);
    digitalWrite(pgreen, HIGH);
    digitalWrite(pblue, HIGH);
    digitalWrite(pyellow, HIGH);
//print the led states on the serial monitor
    Serial.println("Red led: High"); 
    Serial.println("green led: High");
    Serial.println("blue led: High"); 
    Serial.println("yellow led: High"); 
  }
  else if (distance>1.5)
  {
    digitalWrite(pred, LOW);
    digitalWrite(pgreen, HIGH);
    digitalWrite(pblue, HIGH);
    digitalWrite(pyellow, HIGH);
    
    //print the led states on the serial monitor
    Serial.println("Red led: LOW"); 
    Serial.println("green led: High");
    Serial.println("blue led: High"); 
    Serial.println("yellow led: High"); 

  }
  else if (distance>1.0)
  {
    digitalWrite(pred, LOW);
    digitalWrite(pgreen, LOW);
    digitalWrite(pblue, HIGH);
    digitalWrite(pyellow, HIGH);
  //print the led states on the serial monitor
    Serial.println("Red led: LOW"); 
    Serial.println("green led: LOW");
    Serial.println("blue led: High"); 
    Serial.println("yellow led: High"); 

  }
  else if (distance>.5)
  {
    digitalWrite(pred, LOW);
    digitalWrite(pgreen, LOW);
    digitalWrite(pblue, LOW);
    digitalWrite(pyellow, HIGH);
  
  //print the led states on the serial monitor
    Serial.println("Red led: LOW"); 
    Serial.println("green led: LOW");
    Serial.println("blue led: LOW"); 
    Serial.println("yellow led: High"); 
  }
  else if (distance<.5)
  {
    digitalWrite(pred, LOW);
    digitalWrite(pgreen, LOW);
    digitalWrite(pblue, LOW);
    digitalWrite(pyellow, LOW);
    //print the led states on the serial monitor
    Serial.println("Red led: LOW"); 
    Serial.println("green led: LOW");
    Serial.println("blue led: LOW"); 
    Serial.println("yellow led: LOW"); 
  }
   Serial.println("--------------------------------------------------------------"); 

}
