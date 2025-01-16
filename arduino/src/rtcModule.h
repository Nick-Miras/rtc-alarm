//
// Created by Nick Anthony Miras on 1/16/25.
//

#ifndef RTCMODULE_H
#define RTCMODULE_H

#define countof(a) (sizeof(a) / sizeof(a[0]))
#define IO_PIN 4
#define SCLK_PIN 5
#define CE_PIN 2

extern void rtcSetup();
extern void rtcLoop(int alarmHour, int alarmMinute);

void triggerAlarm();

#endif //RTCMODULE_H
