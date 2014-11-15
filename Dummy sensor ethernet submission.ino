#include <UIPEthernet.h> 
#define DEBUG

// Ethernet MAC address
byte mac[] = { 0x54, 0x34, 0x41, 0x30, 0x30, 0x31 };                                       
 
 
EthernetClient client;
char server[] = "00.00.42.70"; // Data server IP (Replace with actual IP)
int  interval = 5000; // Dump dela
IPAddress myIP(192,168,0,21); // Arduino IP static

void setup() {
  Ethernet.begin(mac,myIP);
  
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
    client.print( "12.3" );
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
