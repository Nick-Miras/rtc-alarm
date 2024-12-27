#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "webInterface.h"

const char* ssid = "NodeMCU";
const char* password = "12345678";

// /* Put IP Address details */
// IPAddress local_ip(192,168,1,1);
// IPAddress gateway(192,168,1,1);
// IPAddress subnet(255,255,255,0);

void setup() {
    Serial.begin(115200);

    // Connect to Wi-Fi
    WiFi.begin(ssid, password);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected to Wi-Fi");
    Serial.println("IP Address: " + WiFi.localIP().toString());
}

void loop() {
    serverLoop();
}