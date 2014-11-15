#include <UIPEthernet.h> 
#include "DHT.h"
#define DEBUG
#define DHTPIN   2 
#define DHTTYPE DHT22

// Ethernet MAC address
byte mac[] = { 0x54, 0x34, 0x41, 0x30, 0x30, 0x31 };                                       

DHT dht(DHTPIN, DHTTYPE);
 
EthernetClient client;
char server[] = "95.85.42.70"; // Data server IP (Replace with actual IP)
int  interval = 5000; // Dump dela
IPAddress myIP(192,168,0,21); // Arduino IP static

void setup() {
  Ethernet.begin(mac,myIP);
  dht.begin();
  
 #ifdef DEBUG
  Serial.begin(9600);
  Serial.print("IP Address        : ");
  Serial.println(Ethernet.localIP());
  Serial.print("Subnet Mask       : ");
  Serial.println(Ethernet.subnetMask());
  Serial.print("Default Gateway IP: ");
  Serial.println(Ethernet.gatewayIP());
  Serial.print("DNS Server IP     : ");
  Serial.println(Ethernet.dnsServerIP());
 #endif
}
 
void loop() {
  if (client.connect(server, 80)) {
    #ifdef DEBUG
    Serial.println("-> Connected");
    #endif
    
    // Make a HTTP request:
    client.print( "GET /add_data.php?");
    client.print("serial=");
    client.print( "288884820500006X" );
    client.print("&&");
    client.print("temperature=");
    DHTTemp();
    client.println( " HTTP/1.1");
    client.print( "Host: " );
    client.println(server);
    client.println( "Connection: close" );
    client.println();
    client.println();
    client.stop();
  }
  else {
    #ifdef DEBUG
    Serial.println("--> connection failed/n");
    #endif
  }
 
  delay(interval);
}

void DHTTemp(void){
  delay(2000); // read every 2000 ms
  //float h = dht.readHumidity();
  float t = dht.readTemperature();
  client.print(t);
  
  #ifdef DEBUG
  Serial.println(t);
  #endif
  
  return;
}
