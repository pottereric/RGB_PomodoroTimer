int annodePin = 12;
int redPin = 11;
int bluePin = 10;
int greenPin = 9;
 
//uncomment this line if using a Common Anode LED
#define COMMON_ANODE

int delayTime = 78;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  pinMode(annodePin, OUTPUT);
  digitalWrite(annodePin, HIGH);
}
 
void loop()
{
  int i = 0;
  
  for (i = 255; i >= 0; i--){ // green to blue
    setColor(0, i, 255-i);
    delay(delayTime); 
  }
 
  for (i = 255; i >= 0; i--){ // blue to red
    setColor(255-i, 0, i);
    delay(delayTime); 
  }
  
 PulseRed();
    
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

void PulseRed(){
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
