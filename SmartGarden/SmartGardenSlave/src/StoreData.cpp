#include "StoreData.hpp"

StoreData::StoreData(Packet pack) : packet(pack) {}

Packet StoreData::storeTemp(float tempVal, int count)
{
    if(count == 0)
    {
        packet.temperature[0] = tempVal;
    }
    else if(count == 1)
    {
        packet.temperature[1] = tempVal;
    }
    return packet;
}

Packet StoreData::storeHumid(int humidVal, int count)
{
    if(count == 0)
    {
        packet.humidity[0] = humidVal;
    }
    else if(count == 1)
    {
        packet.humidity[1] = humidVal;
    }
    return packet;
}

Packet StoreData::storeLight(int lightVal, int count)
{
    if(count == 0)
    {
        packet.light[0] = lightVal;
    }
    else if(count == 1)
    {
        packet.light[1] = lightVal;
    }
    return packet;
}