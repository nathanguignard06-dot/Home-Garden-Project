#ifndef SENSORREADINGS
#define SENSORREADINGS

#include "SystemeInit.hpp"
#include <OneWire.h>
#include <DallasTemperature.h>

class SensorReadings
{
    public:

        SensorReadings(SystemeInit& firstSysteme, DallasTemperature& sensor);

        int readPhoto(int pinPhoto);
        int readHumid(int pinHumid);
        float readTemp(DallasTemperature& sensor, int deviceCount);

    private:

        DallasTemperature& sensors;

        SystemeInit& systeme1;

        float tempC;
};

#endif