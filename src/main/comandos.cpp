#include "Arduino.h"
#include "interface.h"
#include "comandos.h"
#include "climate.h"
#include "light_control.h"
#include "leakage.h"
#include "sms.h"
#include "presence.h"

#define LED_EXTERNAL            1
#define LED_INTERNAL            2
#define FAN                     3

#define NIGHT                   100
#define HOT_TEMPERATURE         28 
#define PRESENCE_THRESHOLD      500

comandosClass::comandosClass()
{
}

void comandosClass::setup(void)
{
    pinMode(LED_EXTERNAL, OUTPUT);
    pinMode(LED_INTERNAL, OUTPUT);
    pinMode(FAN, OUTPUT);
}

void comandosClass::controlInterface(void)
{
    static screenOptions_t userChoice;
    static bool screenTest = true;

    if(screenTest)
    {
        interface.menu();
        screenTest = false;
    }
    
    if(Serial.available() > 0)
    {
        userChoice = interface.readOption();
        switch (userChoice)
        {
            case BACK_OPTION:
            {
                interface.clearScreen();
                interface.menu();
            }
            break;
        
            case CLIMATE_OPTION:
            {
                interface.clearScreen();
                interface.climateScreen();
            }
            break;

            case POTENCY_OPTION:
            {
                interface.clearScreen();
                interface.lightPotency();
            }
            break;

            case TEMPERATURE_OPTION:
            {
                interface.clearScreen();
                interface.temperatureControl();
            }
            break;

            default:
            {
            }
            break;
        }
    }
}

void comandosClass::controlLight(void)
{
    uint32_t luminosityReading = light.getLuminosity(); 
    bool presenceReading = presence.verifyPresence();

    if(luminosityReading <= NIGHT)
    {
        if(presenceReading < PRESENCE_THRESHOLD)
        {
            digitalWrite(LED_EXTERNAL, true);
            digitalWrite(LED_INTERNAL, true);
        }
        else
        {
          digitalWrite(LED_EXTERNAL, true); 
          digitalWrite(LED_INTERNAL, false);
        }
    }
    else
    {
       digitalWrite(LED_INTERNAL, false);
       digitalWrite(LED_EXTERNAL, false);
    }
    delay(2000);
}

void comandosClass::controlTemperature(void)
{
    uint8_t currentTemperature = climate.getTemperature();

    if(currentTemperature > HOT_TEMPERATURE)
    {
        digitalWrite(FAN, true);
    }
    else
    {
        digitalWrite(FAN, false);
    }
}

void comandosClass::leakageAlert(void)
{
    if(leakage.verifyLeakage())
    {
        sms.sendSMS();
    }
}
