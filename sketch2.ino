int redpbuttonPin = 10;// 
int yellowpbuttonPin = 11;// connect output to push button
int greenpbuttonPin = 12;// connect output to push buttonconnect output to push button
int redrelayPin = 2;//
int yellowrelayPin = 3;
int greenrelayPin = 4;
int valred = 0; // push value from pin 2
int valyellow = 0;
int valgreen= 0;
int redlightON = 0;//light status
int yellowlightON = 0;
int greenlightON = 0;
int redpushed = 0;//push status
int greenpushed = 0;
int yellowpushed = 0;
unsigned long previousMillis=0;

void setup() {
  Serial.begin(9600);
  pinMode(redpbuttonPin, INPUT_PULLUP); 
    pinMode(yellowpbuttonPin, INPUT_PULLUP); 
      pinMode(greenpbuttonPin, INPUT_PULLUP); 
  pinMode(redrelayPin, OUTPUT);
   pinMode(yellowrelayPin, OUTPUT);
    pinMode(greenrelayPin, OUTPUT);
 digitalWrite(redrelayPin, HIGH);
 digitalWrite(yellowrelayPin, HIGH);
 digitalWrite(greenrelayPin, HIGH);
  millis();
}

void loop() {

valred = digitalRead(redpbuttonPin);
valyellow = digitalRead(yellowpbuttonPin);
valgreen = digitalRead(greenpbuttonPin);

 if(valred == LOW && redlightON == HIGH){
    redpushed = 1-redpushed;

  }    
    redlightON = valred;
     if(redpushed == HIGH) {
        Serial.println("Light ON");
        digitalWrite(redrelayPin, LOW); 
       
      }else{
        Serial.println("Light OFF");
        digitalWrite(redrelayPin, HIGH);
      }     
     
  if(valyellow == HIGH && yellowlightON == LOW){

    yellowpushed = 1-yellowpushed;
    
  }    
    yellowlightON = valyellow;
     if(yellowpushed == HIGH){
        Serial.println("Light ON");
        digitalWrite(yellowrelayPin, LOW); 
  
       
      }else{
        Serial.println("Light OFF");
        digitalWrite(yellowrelayPin, HIGH);
   
      }     

       if(valgreen == HIGH && greenlightON == LOW){

    greenpushed = 1-greenpushed;

  }    
    greenlightON = valgreen;
     if(greenpushed == HIGH){
        Serial.println("Light ON");
        
        digitalWrite(greenrelayPin, LOW); 
  
       
      }else{
        Serial.println("Light OFF");
        digitalWrite(greenrelayPin, HIGH);

      }     
    
  delay(70);
}
