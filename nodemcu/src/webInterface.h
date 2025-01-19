//
// Created by cathey on 12/26/24.
//

#ifndef WEBINTERFACE_H
#define WEBINTERFACE_H
#include <ESP8266WebServer.h>

inline ESP8266WebServer server(80);
void informArduino(const char* date, const char* time);
extern void serverLoop();
extern void handleRoot();
extern void setupWebServer();

#endif //WEBINTERFACE_H
