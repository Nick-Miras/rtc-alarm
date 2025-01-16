#include "webInterface.h"

const char* hostname = "alarm";
char timeInput[4];

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
  <title>ESP Input Form</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
  <form action="/get/input1">
    input1: <input type="text" name="input1">
    <input type="submit" value="Submit">
  </form>
  <form action="/get/input2">
    <label for="appt-time">Choose a time:</label>
    <input type="time" id="appt-time" name="appt-time">
    <input type="submit">
  </form>
</body>
</html>
)rawliteral";

void handleRoot() {
  server.send(200, "text/html", index_html);
}

void handleInput() {
  const String input = server.arg("input1");

  String message = "Received inputs:<br>";
  if (input.length()) message += "Input 1: " + input + "<br>";

  const char* time = input.c_str();
  informArduino(__DATE__, time);
  server.send(200, "text/html", message);
}

void handleInputTime() { // TODO: Verify if this works
  const String input = server.arg("input1"); // expected input: HH:MM

  String message = "Received inputs:<br>";
  if (input.length()) message += "Input 1: " + input + "<br>";

  const char* time = (input + ":00").c_str();
  informArduino(__DATE__, time);
  server.send(200, "text/html", message);
}

void setupWebServer() {
  // Start mDNS
  if (!MDNS.begin(hostname)) {  // Replace "esp32" with your desired hostname
    Serial.println("Error starting mDNS");
    return;
  }
  Serial.print("mDNS responder started. Access it at: http://");
  Serial.print(hostname);
  Serial.println(".local");

  server.on("/", HTTP_GET, handleRoot);
  server.on("/get/input1", HTTP_GET, handleInput);
  server.on("/get/input2", HTTP_GET, handleInputTime);
  server.begin();

  Serial.println("HTTP server started");
}

char* serverLoop() {
  strcpy(timeInput, "");
  server.handleClient();
  return timeInput;
}
