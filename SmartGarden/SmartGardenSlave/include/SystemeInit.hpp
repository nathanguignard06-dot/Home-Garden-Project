#ifndef SYSTEMEINIT
#define SYSTEMEINIT

#include <Arduino.h>

class SystemeInit
{
    public:

        SystemeInit(int humid1, int humid2, int photo1, int photo2);
        void begin();

    private:

        const int HUMID_PIN1;
        const int HUMID_PIN2;
        const int PHOTO_PIN1;
        const int PHOTO_PIN2;
};

#endif