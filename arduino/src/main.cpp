#include <Arduino.h>
#include "rtcModule.h"
#include "alarm.h"

// Alarm time variables
int alarmHour = 20;    // Set alarm hour (24-hour format)
int alarmMinute = 30;  // Set alarm minute

void triggerAlarm() {
    alarmInit();
}

void setup ()
{
    Serial.begin(57600);

    Serial.print("compiled: ");
    Serial.print(__DATE__);
    Serial.println(__TIME__);
    rtcSetup();
}

void loop ()
{
    if (Serial.available()) {
        String receivedMessage = Serial.readString();  // Read message from NodeMCU
    }
    rtcLoop(alarmHour, alarmMinute);
}
