#ifndef COMANDOS_H
#define COMANDOS_H

class comandosClass
{
    public:
        comandosClass();
        void controlInterface(void);
        void controlLight(void);
        void controlTemperature(void);
        void leakageAlert(void);
};

extern comandosClass comandos;

#endif
