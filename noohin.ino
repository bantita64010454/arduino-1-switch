#define led1 4
#define led2 3
#define led3 2
#define button1 12
#define button2 11
#define button3 10
long timerLed1 = 0;
long timerLed2 = 0;
long timerLed3 = 0;

long timerSwitch1 = 0;
long timerSwitch2 = 0;
long timerSwitch3 = 0;

int redOn = 0;
int greenOn = 0;
int yellowOn = 0;
int currentRed;
int currentGreen;
int currentYellow;
int redDelay = 3000, greenDelay = 3000, yellowDelay = 2000;

void setup(){
    pinMode(button1,INPUT);
      pinMode(button2,INPUT);
      pinMode(button3,INPUT_PULLUP);
      pinMode(led1,OUTPUT);
      pinMode(led2,OUTPUT);
      pinMode(led3,OUTPUT);
}

void loop(){
  //GREEN
  if(digitalRead(button3) == LOW && redOn == 0){
      digitalWrite(led3, HIGH);
    greenOn = 1;
    delay(300);
  }
  if(greenOn == 1){
      currentGreen = millis();
  }
  if(greenOn == 1 && digitalRead(button3) == LOW){
      digitalWrite(led3,LOW);
    greenOn = 0;
    timerLed3 = currentGreen;
  }
  if(currentGreen - timerLed3 >= greenDelay){
      digitalWrite(led3,LOW);
    greenOn = 0;
    timerLed3 = currentGreen;
  }

  //YELLOW
  if(digitalRead(button2) == LOW && redOn == 0 && greenOn == 0){
      digitalWrite(led2, HIGH);
    yellowOn = 1;
    delay(500);
  }
  if(yellowOn == 1){
      currentYellow = millis();
    digitalWrite(led2,LOW);
    delay(500);
    digitalWrite(led2,HIGH);
    delay(500);
    digitalWrite(led2,LOW);
    delay(500);
    yellowOn = 0;
  }
  if(currentYellow - timerLed2 >= yellowDelay){
    timerLed2 = currentYellow;
  }


  //RED
  if (digitalRead(button1) == HIGH)
  {
    digitalWrite(led1, HIGH);
    redOn = 1;
     delay(300);
  }
  if (redOn == 1)
  {
    currentRed = millis();//จับเวลา
  }
  if(redOn == 1 && digitalRead(button1) == HIGH){
      digitalWrite(led1,LOW);
    redOn = 0;
    timerLed1 = currentRed;
  }
  if (currentRed - timerLed1 >= redDelay)//ถ้าเวลามากกว่า 3000 ให้ดับ
  {
    digitalWrite(led1, LOW);
    redOn = 0;
    timerLed1 = currentRed;
  }
}
