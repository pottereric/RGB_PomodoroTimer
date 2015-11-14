int annodePin = 12;
int redPin = 11;
int bluePin = 10;
int greenPin = 9;
 
//this code is using a Common Anode LED

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
  
  for (i = 0; i <= 255; i++){ // green to blue
    setColor(255, i, 255-i);
    delay(delayTime); 
  }
 
  for (i = 0; i <= 255; i++){ // blue to red
    setColor(255-i, 255, i);
    delay(delayTime); 
  }
  
 PulseRed();
    
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
