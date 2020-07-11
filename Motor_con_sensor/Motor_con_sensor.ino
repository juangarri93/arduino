/*
www.RobotLinking.com
*/
 
int led_pin =13;
int sensor_pin =5;
int motorPin = 4;
  int speed = 0;
  
void setup() 
{ 
  pinMode(motorPin, OUTPUT);
  Serial.begin(115200);
  while (! Serial);
  Serial.println("Speed 0 to 255");
  
  pinMode(led_pin, OUTPUT);
  pinMode(sensor_pin, INPUT);
} 
 
 
void loop() 
{ 

if(digitalRead(sensor_pin) == HIGH){

digitalWrite(led_pin, HIGH);

digitalWrite(motorPin, 255);
  Serial.println("High");
  
delay(1000);
 } else {

digitalWrite(led_pin, LOW);
digitalWrite(motorPin, 0);

  Serial.println("Low");
delay(1000);


}

  
/*  while(true){
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
  */
} 
