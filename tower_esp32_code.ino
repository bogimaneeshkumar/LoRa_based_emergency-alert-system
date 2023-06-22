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
    // Message received
    String receivedData = "";
    
    while (LoRa.available()) {
      receivedData += (char)LoRa.read();
    }
    
    if (receivedData.indexOf("|") == -1) {
      // Only user ID received, combine with tower ID and forward
      String combinedData = String(towerID) + "|" + receivedData;
      
      // Send combined data to the nearest tower via LORA
      LoRa.beginPacket();
      LoRa.print(combinedData);
      LoRa.endPacket();
    } else {
      // Combined tower and user ID received, forward as is
      // Send data to the next nearest tower or ESP32 in the city center via LORA
      LoRa.beginPacket();
      LoRa.print(receivedData);
      LoRa.endPacket();
    }
  }
}
