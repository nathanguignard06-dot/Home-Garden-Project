#include "StoreData.hpp"

StoreData::StoreData(Packet pack) : packet(pack) {}

Packet StoreData::storeTemp(float tempVal, int spaces)
{
    float tempTable[spaces];

    for(int i = 0; i < spaces; i++)
    {
        tempTable[i] = tempVal;
    }

    for(int i = 0; i < spaces; i++)
    {
        packet.temperature[i] = tempTable[i];
    }
    return packet;
}

Packet StoreData::storeHumid(int humidVal, int spaces)
{
    int humidTable[spaces];

    for(int i = 0; i < spaces; i++)
    {
        humidTable[i] = humidVal;
    }

    for(int i = 0; i < spaces; i++)
    {
        packet.humidity[i] = humidTable[i];
    }
    return packet;
}

Packet StoreData::storeLight(int lightVal, int spaces)
{
    int lightTable[spaces];

    for(int i = 0; i < spaces; i++)
    {
        lightTable[i] = lightVal;
    }

    for(int i = 0; i < spaces; i++)
    {
        packet.light[i] = lightTable[i];
    }
    return packet;
}