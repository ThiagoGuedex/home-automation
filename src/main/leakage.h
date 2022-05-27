#ifndef LEAKAGE_H
#define LEAKAGE_H

class leakageClass
{
    public:
        leakageClass();
        void setup(void);
        uint8_t readSensor(void);
        bool verifyLeakage(void);
};  

extern leakageClass leakage;

#endif
