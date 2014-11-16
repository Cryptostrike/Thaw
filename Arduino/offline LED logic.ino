#include "DHT.h"
#define DHTPIN   2     // what pin DHT 22 is on
#define DHTTYPE DHT22   // DHT 22  (AM2302)
int ledRed = 3;
int ledYellow = 4;
int ledGreen = 7;
int ledBlue = 6;

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
  delay(2000); // read every 2000 ms
  //float h = dht.readHumidity();
  float t = dht.readTemperature();


  digitalWrite(ledRed, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledGreen, LOW);

  // Check if any reads failed and show blue
  if (isnan(t)) {
    digitalWrite(ledBlue, HIGH); 
    return;
  };
  
  // Show different coloured LED depending on desired temperature range.  
  
  if (t > 25){digitalWrite(ledYellow, HIGH);
  } else if (20 <= t <= 25){digitalWrite(ledRed, HIGH);
  } else if (t < 20){digitalWrite(ledGreen, HIGH);
  }
  
  Serial.println(t); // Print temp for debugging
}

