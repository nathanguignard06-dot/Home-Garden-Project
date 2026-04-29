#include "SensorReadings.hpp"

SensorReadings::SensorReadings(SystemeInit& firstSysteme, DallasTemperature& sensor) : systeme1(firstSysteme), sensors(sensor) {}

int SensorReadings::readHumid(int pinHumid)
{
    int humidMapVal;
    int humidVal = analogRead(pinHumid);

    humidMapVal = map(humidVal, 0, 4096, 0, 255);

    if(humidMapVal > 200)
    {
        humidMapVal = 200;
    }

    return humidMapVal / 2;
}

int SensorReadings::readPhoto(int pinPhoto)
{
    int photoMapVal;
    int photoVal = analogRead(pinPhoto);

    photoMapVal = map(photoVal, 0, 4096, 0, 255);

    if(photoVal > 3200)
    {
        photoMapVal = 200;
    }

    return photoMapVal / 2;    
}

float SensorReadings::readTemp(DallasTemperature& sensor, int deviceCount, int count)
{
    float tempC[2];
    sensors.requestTemperatures();

    for(int i = 0; i < deviceCount; i++)
    {
        if(count == 0 && i == 0)
        {
            tempC[i] = sensors.getTempCByIndex(i);
            return tempC[i];
        }
        else if(count == 1 && i > 0 && i < deviceCount)
        {
            tempC[i] = sensors.getTempCByIndex(i);
            return tempC[i];
        }
    }
}