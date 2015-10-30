/*
Adafruit Arduino - Lesson 3. RGB LED
*/
 
int redPin = 11;
int greenPin = 10;
int bluePin = 9;
 
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
}
 
void loop()
{
  int i = 0;
  

    
  setColor(0, 255, 0);  // blue
  //delay(delayTime);
  
  for (i = 255; i >= 0; i--){
    setColor(0, i, 255-i);
    delay(delayTime); 
  }
  
  setColor(0, 0, 255);  // green
  //delay(delayTime);
  

  for (i = 255; i >= 0; i--){
    setColor(255-i, 0, i);
    delay(delayTime); 
  }
  
  setColor(255, 0, 0);  // red
  //delay(delayTime);
  
  while(true){
    

    
    for(i = 0; i <= 255; i++){
      setColor(i, 0, 0);
      delay(10);
    }
    
    for(i = 255; i > 0; i--){
      setColor(i, 0, 0);
      delay(10);
    }
    
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
