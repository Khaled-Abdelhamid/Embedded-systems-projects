
int flameread = 9;    
int ledPin = 11;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  pinMode(flameread, INPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = digitalRead(flameread);
   Serial.println(sensorValue);
   Serial.println(flameread);
  if(sensorValue==HIGH)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}
