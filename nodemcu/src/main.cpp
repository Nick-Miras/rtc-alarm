#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "webInterface.h"

const char* ssid = "NodeMCU";
const char* password = "12345678";

// void setup() {
//     Serial.begin(115200);
//     delay(2000);
//     // Connect to Wi-Fi
//     WiFi.begin(ssid, password);
//     Serial.print("Connecting to Wi-Fi");
//     while (WiFi.status() != WL_CONNECTED) {
//         delay(500);
//         Serial.print(".");
//     }
//     Serial.println("\nConnected to Wi-Fi");
//     Serial.println("IP Address: " + WiFi.localIP().toString());
// }

void setup() {
    Serial.begin(115200);
    delay(2000);

    // Set up the access point
    Serial.println("Setting up access point...");
    WiFi.softAP(ssid, password);

    // Display the IP address of the access point
    const IPAddress ip = WiFi.softAPIP();
    Serial.print("Access Point IP address: ");
    Serial.println(ip);
    setupWebServer();
}

void informArduino(const char* date, const char* time) {
    // RtcDateTime compileDateTime(__DATE__, __TIME__); <== parameters required by the rtc-alarm
    // sample input: date = "Dec 06 2009", time = "12:34:56"
    Serial.println(date);
    Serial.println(time);
}

void loop() {
    serverLoop();
}