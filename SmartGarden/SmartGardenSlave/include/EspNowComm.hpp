#ifndef ESPNOWCOMM
#define ESPNOWCOMM

#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>
#include "Packet.hpp"

class EspNowComm
{
    public:

        EspNowComm(Packet& pack, uint8_t* mad_addr, esp_now_peer_info_t& infoPeer);

        void begin();
        void initEspNow();

        void peerRegister(esp_now_peer_info_t& infoPeer);
        void addPeer(esp_now_peer_info_t& infoPeer);

        int32_t getWiFiChannel(const char* ssid);
        void OnDataSent(const uint8_t* mac_addr, esp_now_send_status_t status);

        esp_err_t sendPack(Packet& pack, uint8_t* mac_addr);

    private:

        Packet& packet;
        esp_now_peer_info_t& peerInfo;
};

#endif