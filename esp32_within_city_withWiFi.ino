#include <LoRa.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "__WiFiSSID_";
const char* password = "__WiFiPassword_";
const char* websiteURL = "http://yourwebsite.com/api/emergency-status"; // Replace with the actual API endpoint URL

void setup() {
  pinMode(5, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(2, INPUT);

  // Initialize LoRa and WiFi
  LoRa.setPins(5, 14, 2); // Set LoRa module pins
  if (!LoRa.begin(865E6)) {
    Serial.println("LoRa initialization failed!");
    while (1);
  }

  Serial.begin(115200);
  delay(2000); // Delay for serial connection

  WiFi.begin(ssid, password); // Connect to WiFi

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("WiFi connected!");
}

void loop() {
  int packetSize = LoRa.parsePacket();

  if (packetSize) {
    String remoteID = "";

    while (LoRa.available()) {
      remoteID += (char)LoRa.read();
    }

    String towerID = remoteID.substring(0, remoteID.indexOf("|"));
    String remoteDeviceID = remoteID.substring(remoteID.indexOf("|") + 1);

    DynamicJsonDocument jsonPayload(256);
    jsonPayload["towerID"] = towerID;
    jsonPayload["remoteDeviceID"] = remoteDeviceID;
    jsonPayload["status"] = "emergency";

    HTTPClient http;
    http.begin(websiteURL);
    http.addHeader("Content-Type", "application/json");
    String payloadString;
    serializeJson(jsonPayload, payloadString);
    int httpResponseCode = http.POST(payloadString);

    if (httpResponseCode > 0) {
      Serial.println("Emergency data sent to website successfully");
    } else {
      Serial.println("Failed to send emergency data to website");
    }

    http.end();
  }
}
