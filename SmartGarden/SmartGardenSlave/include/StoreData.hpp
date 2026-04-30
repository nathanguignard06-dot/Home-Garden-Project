#ifndef STOREDATA
#define STOREDATA

#include "Packet.hpp"

class StoreData
{
    public:

        StoreData(Packet pack);

        Packet storeTemp(float tempVal, int count);
        Packet storeHumid(int humidVal, int count);
        Packet storeLight(int lightVal, int count);

    private:

        Packet packet;
};

#endif