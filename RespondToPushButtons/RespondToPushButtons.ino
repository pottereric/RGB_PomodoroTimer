/*
Adafruit Arduino - Lesson 3. RGB LED
*/
 
int redPin = 11;
int greenPin = 9;
int bluePin = 10;
 
int blackBtnPin = 7;
int redBtnPin = 6;
 
//uncomment this line if using a Common Anode LED
#define COMMON_ANODE

int delayTime = 50;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  pinMode(blackBtnPin, INPUT_PULLUP);
  pinMode(redBtnPin, INPUT_PULLUP);
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
}
 
void loop()
{
  if(digitalRead(blackBtnPin) == LOW)
  {
   setColor(0, 0, 255);
  }
  else if(digitalRead(redBtnPin) == LOW)
  {
   setColor(255, 0, 0);
  }
  else
  {
   setColor(0, 255, 0); 
  }

}
 
void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
