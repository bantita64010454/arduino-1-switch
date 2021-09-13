int buttonGREEN = 10;
int buttonYELLOW = 11;
int buttonRED = 12;

int lightGREEN = 2;
int lightYELLOW = 3;
int lightRED = 4;

int GREEN_ON = 0;
int YELLOW_ON = 0;
int RED_ON = 0;

long timerGREEN = 0;
long timerYELLOW = 0;
long timerRED = 0;

long timerGREEN_s = 0;
long timerYELLOW_s = 0;
long timerRED_s = 0;


void setup()
{
  pinMode(buttonGREEN,INPUT_PULLUP);
  pinMode(buttonYELLOW,INPUT);
  pinMode(buttonRED,INPUT);
  pinMode(lightGREEN,OUTPUT);
  pinMode(lightYELLOW,OUTPUT);
  pinMode(lightRED,OUTPUT);
}

void loop()
{
  GREEN();
  YELLOW();
  RED();
}

 void GREEN(){
    //GREEN
    if(digitalRead(lightRED) != 1){
      if(digitalRead(buttonGREEN) == 0 && GREEN_ON == 0) {
        if(millis() - timerGREEN_s >= 200){
          digitalWrite(lightGREEN,1);
          GREEN_ON = 1;
          timerGREEN = millis();
          timerGREEN_s = millis();
        }
      }

      else if(digitalRead(buttonGREEN) == 0 && GREEN_ON == 1){
        if(millis() - timerGREEN_s >= 200){
          digitalWrite(lightGREEN,0);
          GREEN_ON = 0;
          timerGREEN = 0;
          timerGREEN_s = millis();
        }
      }

      else if(GREEN_ON == 1 && millis() - timerGREEN >= 3000){
        digitalWrite(lightGREEN,0);
        GREEN_ON = 0;
        timerGREEN = 0;
        timerGREEN_s = millis();
      }
    }
    if(digitalRead(lightRED) == 1 && digitalRead(lightGREEN) == 1){
     if(digitalRead(buttonGREEN) == 0 && GREEN_ON == 1) {
       if(millis() - timerGREEN_s >= 200){
         digitalWrite(lightGREEN,0);
         GREEN_ON = 0;
         timerGREEN = 0;
         timerGREEN_s = millis();
       }
     }
   }
  }


 void YELLOW(){
    //YELLOW
    if(digitalRead(lightRED) != 1 && digitalRead(lightGREEN) != 1){
      if(digitalRead(buttonYELLOW) == 1 && YELLOW_ON == 0){
        if(millis() - timerYELLOW_s >= 200){
          timerYELLOW = millis();
          delay(500);
          YELLOW_ON = 1;
          digitalWrite(lightYELLOW,YELLOW_ON);
          delay(500);
          YELLOW_ON = 0;
          digitalWrite(lightYELLOW,YELLOW_ON);
          delay(500);
          YELLOW_ON = 1;
          digitalWrite(lightYELLOW,YELLOW_ON);
          timerYELLOW_s = millis();
        }
      }

      else if(YELLOW_ON == 1 && millis() - timerYELLOW >= 2000){
        digitalWrite(lightYELLOW,0);
        YELLOW_ON = 0;
        timerYELLOW = 0;
        timerYELLOW_s = millis();
      }
    }
  }


void RED(){
    //RED
    if(digitalRead(buttonRED) == 0 && RED_ON == 0) {
      if(millis() - timerRED_s >= 200){
        digitalWrite(lightRED,1);
        RED_ON = 1;
        timerRED = millis();
        timerRED_s = millis();
      }
    }

    else if(digitalRead(buttonRED) == 0 && RED_ON == 1){
      if(millis() - timerRED_s >= 200){
        digitalWrite(lightRED,0);
        RED_ON = 0;
        timerRED = 0;
        timerRED_s = millis();
      }
    }

    else if(RED_ON == 1 && millis() - timerRED >= 3000){
      digitalWrite(lightRED,0);
      RED_ON = 0;
      timerRED = 0;
      timerRED_s = millis();
    }
  }
