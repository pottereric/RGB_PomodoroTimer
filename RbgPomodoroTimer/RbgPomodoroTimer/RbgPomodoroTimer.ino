const int annodePin = 12;
const int redPin = 11;
const int bluePin = 10;
const int greenPin = 9;

int blackBtnPin = 7;
int redBtnPin = 6;

const int noColor = 0;
const int greenToBlue = 1;
const int blueToRed = 2;
const int pluseRed = 3;

const int Idle = 0;
const int PomodoroSeqence = 1;
const int BreakSequence = 2;

//this code is using a Common Anode LED
int color;
int state;
int sequence;


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
  
  pinMode(blackBtnPin, INPUT_PULLUP);
  pinMode(redBtnPin, INPUT_PULLUP);
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  
  color = 0;
  sequence = Idle;
  state = noColor;
}
 
 
void loop()
{
  if(digitalRead(blackBtnPin) == LOW)
  {
   switch(sequence){
     case Idle:
       sequence = PomodoroSeqence;
       state = greenToBlue;
       break;
     case PomodoroSeqence:
       sequence = BreakSequence;
       currentInterval = TwentyMinuteInterval;
       color = 0;
       state = greenToBlue;
       break;
     case BreakSequence:
       sequence = PomodoroSeqence; 
       currentInterval = FiveMinuteInterval;
       color = 0;
       state = greenToBlue;
       break;
   }
  }
  else if(digitalRead(redBtnPin) == LOW)
  {
    color = 0;
    state = greenToBlue;
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

