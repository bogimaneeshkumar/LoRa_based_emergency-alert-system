#include <LoRa.h>

const int towerID = 123; // Unique ID of the tower

void setup() {
  pinMode(5, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(2, INPUT);
  
  // Initialize LORA module
  LoRa.setPins(5, 14, 2); // Set LORA module pins
  if (!LoRa.begin(865E6)) {
    Serial.println("LORA initialization failed!");
    while (1);
  }
  
  Serial.begin(115200);
}

void loop() {
  // Receive incoming LORA messages
  int packetSize = LoRa.parsePacket();
  
  if (packetSize) {
    // Message received, combine the IDs and send to the center of the city
    String remoteID = "";
    
    while (LoRa.available()) {
      remoteID += (char)LoRa.read();
    }
    
    String combinedData = String(towerID) + "|" + remoteID;
    
    // Send combined data to the center of the city via LORA
    LoRa.beginPacket();
    LoRa.print(combinedData);
    LoRa.endPacket();
  }
  
  
}
