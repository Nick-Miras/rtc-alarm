//
// Created by cathey on 12/26/24.
//

#ifndef WEBINTERFACE_H
#define WEBINTERFACE_H
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

inline ESP8266WebServer server(80);
extern void serverLoop();
extern void handleRoot();

#endif //WEBINTERFACE_H
