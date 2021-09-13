
#define led1 2
#define led2 3
#define led3 4
#define B1 12
#define B2 11
#define B3 10

long timeled1 = 0;
long timeled2 = 0;
long timeled3 = 0;

int redOn , greenOn , yellowOn ;
int currentRed , currentGreen , currentYellow ; 
int redDelay = 3000 , greenDelay = 3000 , yellowDelay = 2000 ;
int countD=4;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(B3,INPUT_PULLUP);
  pinMode(B2,INPUT);
  pinMode(B1,INPUT);
}

void loop() {
  redOn=digitalRead(12);
  yellowOn=digitalRead(11);
  greenOn=digitalRead(10);
  currentRed=digitalRead(led1);
  currentYellow=digitalRead(led2);
  currentGreen=digitalRead(led3);
  //red
  if(redOn&&millis()-timeled1>300)
  {
    timeled1=millis();
    digitalWrite(4,1-digitalRead(4));
  }
  else if(!redOn)
  {
    if(millis()-timeled1>3000)
    digitalWrite(4,LOW);
  }

//green
  if(!greenOn&&millis()-timeled3>300&&currentRed!=HIGH)
  {
    timeled3=millis();
    digitalWrite(2,1-digitalRead(2));
  }
  else if(greenOn)
  {
    if(millis()-timeled3>3000)
    digitalWrite(2,LOW);
  }
  

  //yellow
  if(!yellowOn&&millis()-timeled2>300)
  {if(currentRed!=1&&currentGreen!=1)
  {
    countD=0;
  }
  }
  else if(yellowOn)
  {
    if(countD>=4)
    digitalWrite(3,LOW);
    else if(millis()-timeled2>500)
    {
      countD++;
      timeled2=millis();
      digitalWrite(3,1-digitalRead(3));
    }
  }
}
