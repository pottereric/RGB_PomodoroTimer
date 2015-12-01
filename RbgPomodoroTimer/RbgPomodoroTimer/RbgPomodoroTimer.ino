#include <Bounce.h>

#define SERIAL_DEBUGGING

const int annodePin = 12;
const int redPin = 11;
const int bluePin = 10;
const int greenPin = 9;

const int blackBtnPin = 7;
const int redBtnPin = 6;
const int blackBtnPinSource = 5;
const int redBtnPinSource = 4;

Bounce blackBtn = Bounce( blackBtnPin,5 ); 
Bounce redBtn = Bounce( redBtnPin,5 ); 

const int noColor = 0;
const int greenToBlue = 1;
const int blueToRed = 2;
const int pluseRed = 3;
const int yellowToRed = 4;

const int Idle = 0;
const int PomodoroSeqence = 1;
const int BreakSequence = 2;

int color;
int state;
int sequence;

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

const long PulsingInterval = 10;
const long OneMinuteInterval = 117;
const long FiveMinuteInterval = 1935;
const long TwentyMinuteInterval = 2941;

long currentInterval;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  pinMode(annodePin, OUTPUT);
  digitalWrite(annodePin, HIGH);
  
  pinMode(blackBtnPin, INPUT_PULLUP);
  pinMode(redBtnPin, INPUT_PULLUP);
  pinMode(blackBtnPinSource, OUTPUT);
  digitalWrite(blackBtnPinSource, LOW);
  pinMode(redBtnPinSource, OUTPUT);
  digitalWrite(redBtnPinSource, LOW);
  
  color = 0;
  sequence = Idle;
  state = noColor;
  
  #ifdef SERIAL_DEBUGGING
  Serial.begin(9600);
  #endif
}
 
void StartPomodoroSequence(){
   sequence = PomodoroSeqence;
   currentInterval = TwentyMinuteInterval;
   state = greenToBlue;
   color = 0;
   setColor(255, 0, 255);
} 

void StartBreakSequence(){
   sequence = BreakSequence;
   currentInterval = FiveMinuteInterval;
   color = 100;
   state = yellowToRed;
   setColor(210, 100, 255);
}
 
void StartPulsingSequence(){
  color = 0;
  state = pluseRed; 
  currentInterval = PulsingInterval;
} 
 
void loop()
{
  blackBtn.update();
  redBtn.update();
  
  if(blackBtn.fallingEdge())
  {
   switch(sequence){
     case Idle:
       StartPomodoroSequence();
       break;
     case PomodoroSeqence:
       StartBreakSequence();
       break;
     case BreakSequence:
       StartPomodoroSequence();
       break;
   }
   #ifdef SERIAL_DEBUGGING
   Serial.println("Black");
   Serial.println(sequence);
   Serial.println(state);
   Serial.println(currentInterval);
   #endif
  }
  
  else if(redBtn.fallingEdge())
  {
   switch(sequence){
     case PomodoroSeqence:
       StartPomodoroSequence();
       break;
     case BreakSequence:
       StartBreakSequence();
       break;
   }
    
    #ifdef SERIAL_DEBUGGING
    Serial.println("Red");
    Serial.println(sequence);
    Serial.println(state);
    Serial.println(currentInterval);
    #endif
  }


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
         StartPulsingSequence();
       }
      break;
     case pluseRed:
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
     case yellowToRed:
       setColor(255-(color/3), color, 255);
       color++;
       if(color == 255)
       {
         StartPulsingSequence();
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

