
#include "DHT.h"
#define DHTPIN   A2     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
#define ledRed D3
#define ledYellow D4
#define ledGreen D5
#define ledBlue D6

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);  
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledBlue, OUTPUT);   
  dht.begin();
}

void loop() {
  delay(2000);
  //float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    digitalWrite(ledBlue, HIGH); 
    return;
  }
  
  // Show different coloured LED depending on desired temperature range.  
  if (t > 20){
    digitalWrite(ledGreen, HIGH);
  }
  
  else (18 < t < 20){
    digitalWrite(ledYellow, HIGH);
  }
  
  else ( 18 < t){ 
    digitalWrite(ledRed, HIGH);
  }
}

