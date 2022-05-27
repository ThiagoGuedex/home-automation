#include "Arduino.h"
#include "presence.h"

#define TRIG_PIN            6
#define ECHO_PIN            5

presenceClass::presenceClass()
{
}

void presenceClass::setup(void)
{
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

uint16_t presenceClass::verifyPresence(void)
{
    long duration;

    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    duration = pulseIn(ECHO_PIN, HIGH);
    return ((uint16_t) duration * 0.034 / 2);
}

presenceClass presence = presenceClass();