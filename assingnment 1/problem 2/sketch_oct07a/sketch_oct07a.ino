
 int SensorPin = 13;
 bool sensorVal;
 int LED = 12;
 
void setup()
{
 pinMode(SensorPin,INPUT);
 pinMode(LED,OUTPUT); 
 Serial.begin(9600);
}

 void loop()
 {
  sensorVal = digitalRead(SensorPin);
  Serial.println(sensorVal);

  if (sensorVal == HIGH)
  {
    digitalWrite (LED , HIGH);
  }
  else
  {
      digitalWrite (LED , LOW);
  }
 }
