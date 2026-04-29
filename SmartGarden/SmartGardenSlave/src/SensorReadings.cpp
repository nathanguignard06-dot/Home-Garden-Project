#include "SensorReadings.hpp"

SensorReadings::SensorReadings(SystemeInit& firstSysteme, DallasTemperature& sensor) : systeme1(firstSysteme), sensors(sensor) {}

int SensorReadings::readHumid(int pinHumid)
{
    int humidMapVal;
    int humidVal = analogRead(pinHumid);

    humidMapVal = map(humidVal, 0, 4096, 0, 255);

    return humidMapVal;
}

int SensorReadings::readPhoto(int pinPhoto)
{
    int photoMapVal;
    int photoVal = analogRead(pinPhoto);

    photoMapVal = map(photoVal, 0, 1023, 0, 255);

    return photoMapVal;    
}

float SensorReadings::readTemp(DallasTemperature& sensor, int deviceCount)
{

    sensors.requestTemperatures();

    for (int i = 0; i < deviceCount; i++) 
    {
        tempC = sensors.getTempCByIndex(i);
        return tempC;
    }
}