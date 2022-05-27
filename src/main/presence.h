#ifndef PRESENCE_H
#define PRESENCE_H

class presenceClass
{
    public:
        presenceClass();
        void setup(void);
        uint16_t verifyPresence(void);
};  

extern presenceClass presence;

#endif
