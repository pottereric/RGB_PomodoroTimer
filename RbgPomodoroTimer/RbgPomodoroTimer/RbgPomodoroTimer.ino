const int annodePin = 12;
const int redPin = 11;
const int bluePin = 10;
const int greenPin = 9;

const int greenToBlue = 1;
const int blueToRed = 2;
const int pluseRed = 3;

//this code is using a Common Anode LED
int color;
int state;


int delayTime = 78;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  pinMode(annodePin, OUTPUT);
  digitalWrite(annodePin, HIGH);
  
  color = 0;
  state = greenToBlue;
}
 
// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 117;           // interval at which to blink (milliseconds) 
 
void loop()
{
  
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
  
    switch(state){
     case greenToBlue:
       setColor(255, color, 255 - color);
       color++;
       if(color == 255)
       {
         color = 0;
        state = blueToRed; 
       }
      break;
     case blueToRed:
     setColor(255-color, 255, color);
       color++;
       if(color == 255)
       {
         color = 0;
        state = pluseRed; 
       }
      break;
     case pluseRed:
       PulseRed();
      break;
      
    }
  
  }

  
    
}
 
void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

void PulseRed(){
    while(true){
    int i = 0;    
    for(i = 0; i <= 255; i++){
      setColor(i, 255, 255);
      delay(10);
    }
    
    for(i = 255; i > 0; i--){
      setColor(i, 255, 255);
      delay(10);
    }
    }
}
