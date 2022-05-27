#ifndef INTERFACE_H
#define INTERFACE_H

typedef enum
{
    BACK_OPTION = (48u),
    CLIMATE_OPTION  = (49u),
    POTENCY_OPTION,
    TEMPERATURE_OPTION,
} screenOptions_t;

class interfaceClass
{
    public:
        interfaceClass();
        void setup(void);
        uint8_t readOption(void);
        void clearScreen(void); 
        void menu(void);
        void climateScreen(void);
        void lightPotency(void);
        void temperatureControl(void);
};

extern interfaceClass interface;

#endif
