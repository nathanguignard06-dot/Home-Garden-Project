#ifndef STOREDATA
#define STOREDATA

#include "Packet.hpp"

class StoreData
{
    public:

        StoreData(Packet& pack);

        Packet storeTemp(float tempVal, int deviceCount, int count);
        Packet storeHumid(int humidVal, int spaces, int count);
        Packet storeLight(int lightVal, int spaces, int count);

    private:

        Packet packet;
};

#endif