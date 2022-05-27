#include "Arduino.h"
#include "light_control.h"

#define LUMINOSITY_SENSOR       A0


/************************************************************************************************************/
lightClass::lightClass()
/************************************************************************************************************/
{
}

void lightClass::setup(void)
{
    pinMode(LUMINOSITY_SENSOR, INPUT);
}

/************************************************************************************************************/
uint32_t lightClass::getLuminosity(void)
/************************************************************************************************************/
{
    return (analogRead(LUMINOSITY_SENSOR));
}

lightClass light = lightClass();
