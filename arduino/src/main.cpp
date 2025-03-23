#include <Arduino.h>
#include "rtcModule.h"
#include "alarm.h"

// Alarm time variables
int alarmHour = 20;    // Set alarm hour (24-hour format)
int alarmMinute = 30;  // Set alarm minute

String receivedDate;
String receivedTime;

void triggerAlarm()
{
    Serial.println("Triggering Alarm");
    alarmInit();
}

void setup()
{
    Serial.begin(57600);

    Serial.print("compiled: ");
    Serial.print(__DATE__);
    Serial.println(__TIME__);
    rtcSetup();
    testMotors();
}

void loop()
{
    if (Serial.available()) {
        String receivedMessage = Serial.readString();  // TODO: read alarm specifications from NODEMCU
        receivedDate = Serial.readStringUntil('\n');  // Read date
        receivedTime = Serial.readStringUntil('\n');  // Read time
    }
    if (rtcLoop(receivedTime.c_str()) == true) {
        triggerAlarm();
    }
}
