//
// Created by Nick Anthony Miras on 1/16/25.
//

#include "alarm.h"
#include <VibrationMotor.h>

#define ALARM_PIN 3

const int motorPin = 4;
VibrationMotor myVibrationMotor(motorPin);


/*
Activates Buzzer and Vibration Motor - D3 for Buzzer, D4 for Vibration Motor
 */
void alarmInit(void) {
    myVibrationMotor.on();  // turns motor on
}
