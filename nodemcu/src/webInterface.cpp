#include "webInterface.h"
#include "index_html.h"

const char* hostname = "alarm";
char timeInput[4];

void handleRoot() {
  server.send(200, "text/html", index_html);
}

void handleInputTime() {
  const String input = server.arg("appt-time"); // expected input: HH:MM
  String message = "Received inputs:<br>";
  if (input.length()) message += "Input: " + input + "<br>";

  const String timeWithSeconds = input + ":00";
  const char* time = timeWithSeconds.c_str();
  informArduino(__DATE__, time);
  server.send(200, "text/html", success_html);
}

void setupWebServer() {
  // Start mDNS
  if (!MDNS.begin(hostname)) {  // Replace "esp32" with your desired hostname
    Serial.println("Error starting mDNS");
    return;
  }
  MDNS.addService("http", "tcp", 80);  // Advertise HTTP service

  Serial.print("mDNS responder started. Access it at: http://");
  Serial.print(hostname);
  Serial.println(".local");

  server.on("/", HTTP_GET, handleRoot);
  server.on("/get/input", HTTP_GET, handleInputTime);
  server.begin();

  Serial.println("HTTP server started");
}

void serverLoop() {
  server.handleClient();
}
