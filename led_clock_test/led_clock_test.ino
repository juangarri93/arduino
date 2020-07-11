#include <stdint.h>
#include <TM1637Display.h>

const int CLK = 2; //Set the CLK pin connection to the display
const int DIO = 3; //Set the DIO pin connection to the display


int NumStep = 0;  //Variable to interate
int start = 1;
TM1637Display display(CLK, DIO);  //set up the 4-Digit Display.

void setup()
{
  display.setBrightness(0x0a);  //set the diplay to maximum brightness
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(5,OUTPUT);
}


void loop()
{
if(start=1){
    uint8_t data[] = {0b01110110, 0b00111111, 0b00111000, 0b01110111};
    display.setSegments(data);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(5,HIGH);
    delay(5000);
    start=0;
}
  for(NumStep = 0; NumStep < 9999; NumStep++)  //Interrate NumStep
  {
    display.showNumberDec(NumStep); //Display the Variable value;
    delay(500);  //A half second delay between steps.
  }


    
}

