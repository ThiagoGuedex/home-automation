#ifndef CLIMATE_H
#define CLIMATE_H

class climateClass
{
    public:
        climateClass();
        void setup(void);
        float getTemperature(void);
        float getHumidity(void);
};

extern climateClass climate;

#endif
