#ifndef LIGHT_CONTROL_H
#define LIGHT_CONTROL_H

class lightClass
{
    public:
        lightClass();
        void setup(void);
        uint32_t getLuminosity(void);
};

extern lightClass light;

#endif
