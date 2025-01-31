//
// Created by Nick Anthony Miras on 1/16/25.
//
#include "rtcModule.h"
#include <ThreeWire.h>
#include <RtcDS1302.h>

ThreeWire myWire(IO_PIN, SCLK_PIN, CE_PIN); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

void printDateTime(const RtcDateTime& dt)
{
    char datestring[26];

    snprintf_P(
        datestring,
        countof(datestring),
        PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
        dt.Month(),
        dt.Day(),
        dt.Year(),
        dt.Hour(),
        dt.Minute(),
        dt.Second()
    );
    Serial.print(datestring);
}

void rtcSetup() {
    Rtc.Begin();

    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
    printDateTime(compiled);
    Serial.println();

    if (!Rtc.IsDateTimeValid())
    {
        // Common Causes:
        //    1) first time you ran and the device wasn't running yet
        //    2) the battery on the device is low or even missing

        Serial.println("RTC lost confidence in the DateTime!");
        Rtc.SetDateTime(compiled);
    }

    if (Rtc.GetIsWriteProtected())
    {
        Serial.println("RTC was write protected, enabling writing now");
        Rtc.SetIsWriteProtected(false);
    }

    if (!Rtc.GetIsRunning())
    {
        Serial.println("RTC was not actively running, starting now");
        Rtc.SetIsRunning(true);
    }

    RtcDateTime now = Rtc.GetDateTime();
    if (now < compiled)
    {
        Serial.println("RTC is older than compile time!  (Updating DateTime)");
        Rtc.SetDateTime(compiled);
    }
    else if (now > compiled)
    {
        Serial.println("RTC is newer than compile time. (this is expected)");
    }
    else if (now == compiled)
    {
        Serial.println("RTC is the same as compile time! (not expected but all is fine)");
    }
}

void rtcLoop(int alarmHour, int alarmMinute) {
    RtcDateTime now = Rtc.GetDateTime();
    // Check if current time matches the alarm
    if (now.Hour() == alarmHour && now.Minute() == alarmMinute) {
        triggerAlarm();
        delay(60000); // Prevent retriggering for 1 minute
    }

    delay(1000);
}