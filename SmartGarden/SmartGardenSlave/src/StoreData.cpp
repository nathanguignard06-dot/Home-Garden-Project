#include "StoreData.hpp"

StoreData::StoreData(Packet& pack) : packet(pack) {}

Packet StoreData::storeTemp(float tempVal, int count)
{
    if(count == 0)
    {
        packet.temperature[count] = tempVal;
    }
    else if(count == 1)
    {
        packet.temperature[count] = tempVal;
    }
    return packet;
}

Packet StoreData::storeHumid(int humidVal, int count)
{
    if(count == 0)
    {
        packet.humidity[count] = humidVal;
    }
    else if(count == 1)
    {
        packet.humidity[count] = humidVal;
    }
    return packet;
}

Packet StoreData::storeLight(int lightVal, int count)
{
    if(count == 0)
    {
        packet.light[count] = lightVal;
    }
    else if(count == 1)
    {
        packet.light[count] = lightVal;
    }
    return packet;
}