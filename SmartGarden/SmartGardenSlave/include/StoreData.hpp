#ifndef STOREDATA
#define STOREDATA

#include "Packet.hpp"

class StoreData
{
    public:

        StoreData(Packet pack);

        Packet storeTemp(float tempVal, int spaces);
        Packet storeHumid(int humidVal, int spaces);
        Packet storeLight(int lightVal, int spaces);

    private:

        Packet packet;
};

#endif