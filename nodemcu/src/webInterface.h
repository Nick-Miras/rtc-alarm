//
// Created by cathey on 12/26/24.
//

#ifndef WEBINTERFACE_H
#define WEBINTERFACE_H
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

inline ESP8266WebServer server(80);
void informArduino(const char* date, const char* time)
extern char* serverLoop();
extern void handleRoot();

#endif //WEBINTERFACE_H
