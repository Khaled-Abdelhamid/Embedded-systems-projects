const int buttonPin = 12;     // the number of the pushbutton pin
const int ledPin =  11;      // the number of the LED pin


int buttonState = 0;         // variable for reading the pushbutton status
int amp=127;
int timee=0;
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH && timee<15 && amp<=255) //if the button is pused for more than 3 seconds
    {
      analogWrite(ledPin, amp);
    }
  else if (buttonState == HIGH && timee>15 && amp<=255) //if the button is pused for more than 3 seconds
  {
    analogWrite(ledPin, amp);
    amp=amp+16;//the led will keep increasing fr three seconds
  } 
  else if(amp>255 && buttonState == HIGH)//if we reached the maximum the led will shut down
  {
    analogWrite(ledPin, 0);
  }
  else if(buttonState == LOW)
  {
    analogWrite(ledPin, 0);
    timee=0;
    amp=127;

  }
  timee=timee+1;
  delay(200);
}
