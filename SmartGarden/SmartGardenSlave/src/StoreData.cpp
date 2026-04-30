#include "StoreData.hpp"

StoreData::StoreData(Packet& pack) : packet(pack) {}

Packet StoreData::storeTemp(float tempVal, int deviceCount, int count)
{
    for(int i = 0; i < deviceCount; i++)
    {
        if(count == 0 && i == 0)
        {
            packet.temperature[i] = tempVal;
        }
        else if(count == 1 && i > 0 && i < deviceCount)
        {
            packet.temperature[i] = tempVal;
        }
    }
    return packet;
}

Packet StoreData::storeHumid(int humidVal, int spaces, int count)
{
    for(int i = 0; i < spaces; i++)
    {
        if(count == 0 && i == 0)
        {
            packet.humidity[i] = humidVal;
        }
        else if(count == 1 && i > 0 && i < spaces)
        {
            packet.humidity[i] = humidVal;
        }
    }
    return packet;
}

Packet StoreData::storeLight(int lightVal, int spaces, int count)
{
    for(int i = 0; i < spaces; i++)
    {
        if(count == 0 && i == 0)
        {
            packet.light[i] = lightVal;
        }
        else if(count == 1 && i > 0 && i < spaces)
        {
            packet.light[i] = lightVal;
        }
    }
    return packet;
}