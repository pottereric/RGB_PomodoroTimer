const int annodePin = 12;
const int redPin = 11;
const int bluePin = 10;
const int greenPin = 9;

const int blackBtnPin = 7;
const int redBtnPin = 6;
const int blackBtnPinSource = 5;
const int redBtnPinSource = 4;
 

int delayTime = 50;

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
 
  #ifdef SERIAL_DEBUGGING
  Serial.begin(9600);
  #endif
}
 
void loop()
{
  setColor(0, 255, 255);
  delay(1000);
  setColor(255, 0, 255);
  delay(1000);
  setColor(255, 255, 0); 
  delay(1000);
  setColor(210, 100, 255); 
  delay(1000);
}
 
void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
