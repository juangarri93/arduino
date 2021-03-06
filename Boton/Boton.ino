//Controlling Led By Button
//Turns on and off a LED ,when pressings button attach to pin12
//www.RobotLinking.com
//2015.5.7
/**********************************/
const int keyPin = 12; //the number of the key pin
const int ledPin = 13;//the number of the led pin
int incremento = 0;//the number of the led pin
/**********************************/
void setup()
{
  
  Serial.begin(9600);
  pinMode(keyPin,INPUT);//initialize the key pin as input 
  pinMode(ledPin,OUTPUT);//initialize the led pin as output
}
/**********************************/
void loop()
{
  //read the state of the key value
  //and check if the kye is pressed
  //if it is,the state is HIGH 
  if(digitalRead(keyPin) ==HIGH )
  {
    digitalWrite(ledPin,HIGH);//turn on the led
    Serial.println("ON!" + (String)incremento);
    incremento=incremento+1;
  }
  else
  {
    digitalWrite(ledPin,LOW);//turn off the led
  }
}
/************************************/
