#include "WiFi.h"
#include "HTTPClient.h"

const char* ssid = "Fibertel WiFi088";
const char* password =  "0041785663"; 
int led_pin =13;
int sensor_pin =4;
int medicion3=0;
  
void setup() 
{ 
  Serial.begin(115200);  
  pinMode(led_pin, OUTPUT);
  pinMode(A0, INPUT);
  
  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi");
  }
 
  Serial.println("Connected to the WiFi network");
} 
 
 
void loop() 
{ 

digitalWrite(led_pin, LOW);

medicion3 = analogRead(A0);
Serial.println("Medido: " + (String) medicion3);

if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
 
    HTTPClient http;
 
    http.begin("http://test.phrodrigo.com.ar/medicion.php?dispositivo=751489&humedad="+(String)medicion3); //Specify the URL
   // Serial.println("Enviando a servicio: "+"http://test.phrodrigo.com.ar/medicion.php?dispositivo=751489&humedad="+medicion);
       
    int httpCode = http.GET();                                        //Make the request
 
    if (httpCode > 0) { //Check for the returning code
       Serial.println("Enviado ok.");
        /*
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
        */
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
 
    http.end(); //Free the resources
  }

delay(320000);
digitalWrite(led_pin, HIGH);

} 
