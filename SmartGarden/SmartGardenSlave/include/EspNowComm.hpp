#ifndef ESPNOWCOMM
#define ESPNOWCOMM

#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>
#include "Packet.hpp"

class EspNowComm
{
    public:

        EspNowComm(Packet& pack, esp_now_peer_info_t& infoPeer);

        void begin();
        void initEspNow();

        void peerRegister(const uint8_t* mac_addr);
        void addPeer();

        int32_t getWiFiChannel(const char* ssid);
        void setChannel(int32_t wifiChannel);

        esp_err_t sendPack(Packet& pack, uint8_t* mac_addr);

    private:

        Packet& packet;
        esp_now_peer_info_t& peerInfo;
};

#endif