/*
www.RobotLinking.com
*/
 
 
int motorPin = 4;
  int speed = 0;
  
void setup() 
{ 
  pinMode(motorPin, OUTPUT);
  Serial.begin(115200);
  while (! Serial);
  Serial.println("Speed 0 to 255");
} 
 
 
void loop() 
{ 
  while(true){
      speed = speed+10;
  if (speed>255)
  {speed=0;
  } 
    
    if (speed >= 0 && speed <= 255)
    {
      Serial.println(speed);
      digitalWrite(motorPin, speed);
      //analogWrite(motorPin, speed);
    }
  
  }
} 
