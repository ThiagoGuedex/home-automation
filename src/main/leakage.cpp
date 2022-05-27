#include "Arduino.h"
#include "leakage.h"

#define smokeSensor         A1
#define sensorThreshold     400

leakageClass::leakageClass()
{
}

void leakageClass::setup(void)
{
    pinMode(smokeSensor, INPUT);
}

uint8_t leakageClass::readSensor (void)
{
    return (analogRead(smokeSensor));
}

bool leakageClass::verifyLeakage(void)
{
    return ((leakage.readSensor() > sensorThreshold) ? true : false);
}

leakageClass leakage = leakageClass();
