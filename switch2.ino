const int ledPin =  4;      // the number of the LED pin
unsigned long startTime;        // will store last time LED was updated
const int DisplayButton = 12; 
int lastButtonState = 0; 
int ledState;

unsigned long interval = 3000;           // interval at which to blink (milliseconds)

void setup() 
{
  pinMode(ledPin, OUTPUT);  
  pinMode(DisplayButton, INPUT);  
}

void loop()
{ 
  int buttonState = digitalRead(DisplayButton);
  if (buttonState == HIGH) 
  {
    if (lastButtonState == LOW)
    {
      ledState = 1;
      startTime = millis();
    }
  }
  
  lastButtonState = buttonState;
  if (ledState)
  {
    if (millis() - startTime <= interval)
    {
      digitalWrite(ledPin, HIGH);
    }
    else
    {
      digitalWrite(ledPin, LOW);
      ledState = 0;
    }
    
  }  
}
