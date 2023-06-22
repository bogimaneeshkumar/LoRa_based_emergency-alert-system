#include <LoRa.h>

const int buttonPin = 4; // Pin connected to the push button
const int ledPin = 13;   // Pin connected to the LED (optional)

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  pinMode(5, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(2, INPUT);

  // Initialize LORA module
  LoRa.setPins(5, 14, 2); // Set LORA module pins (change according to your setup)
  if (!LoRa.begin(865E6)) {
    Serial.println("LORA initialization failed!");
    while (1);
  }
  
  Serial.begin(115200);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW) {
    // Button is pressed, send the unique ID via LORA
    digitalWrite(ledPin, HIGH);
    
    // Send the ID via LORA
    LoRa.beginPacket();
    LoRa.print("0987"); // 0987 is unique id of user here
    LoRa.endPacket();
    
    delay(500); // Debounce delay
    
    digitalWrite(ledPin, LOW);
  }
  
 
}
