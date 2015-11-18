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


// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long PulsingInterval = 10;
const long OneMinuteInterval = 117;
const long FiveMinuteInterval = 588;
const long TwentyMinuteInterval = 2941;

long currentInterval;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  pinMode(annodePin, OUTPUT);
  digitalWrite(annodePin, HIGH);
  
  color = 0;
  state = greenToBlue;
  currentInterval = OneMinuteInterval;
}
 
 
void loop()
{
  
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= currentInterval) {
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
        currentInterval = PulsingInterval;
       }
      break;
     case pluseRed:
       //PulseRed();
       if(color<= 255){
         setColor(color, 255, 255);
         color++;
       }
       else if (color <= 510){
         setColor(255 - (color - 255), 255, 255);
         color++;
       }
       else
       {
        color = 0; 
       }
       
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
