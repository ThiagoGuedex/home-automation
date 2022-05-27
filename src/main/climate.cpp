#include "Arduino.h"
#include "climate.h"
#include "DHT.h"

#define DHTPIN A1 
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

climateClass::climateClass()
{
}

void climateClass::setup(void)
{
    dht.begin();
}

float climateClass::getTemperature(void)
{
    return (dht.readTemperature());
}

float climateClass::getHumidity(void)
{
    return (dht.readHumidity());
}

climateClass climate = climateClass();