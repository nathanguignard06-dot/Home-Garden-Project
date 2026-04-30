#include "EspNowComm.hpp"

EspNowComm::EspNowComm(Packet& pack, esp_now_peer_info_t& infoPeer) : packet(pack), peerInfo(infoPeer) {}

void EspNowComm::begin(int32_t wiFiChannel)
{
    WiFi.mode(WIFI_STA);

    int32_t channel = wiFiChannel;

    esp_wifi_set_promiscuous(true);
    esp_wifi_set_channel(channel, WIFI_SECOND_CHAN_NONE);
    esp_wifi_set_promiscuous(false);
}

void EspNowComm::initEspNow()
{
    if (esp_now_init() != ESP_OK) 
    {
        Serial.println("Error initializing ESP-NOW");
        return;
    }
}

void EspNowComm::peerRegister(const uint8_t* mac_addr)
{
    const uint8_t* broadcastAddress = mac_addr;

    memcpy(peerInfo.peer_addr, broadcastAddress, 6);
    peerInfo.channel = 0;  
    peerInfo.encrypt = false;
}

void EspNowComm::addPeer()
{
    if (esp_now_add_peer(&peerInfo) != ESP_OK)
    {
        Serial.println("Failed to add peer");
        return;
    }
}

int32_t EspNowComm::getWiFiChannel(const char* ssid)
{
    if (int32_t n = WiFi.scanNetworks()) 
    {
        for (uint8_t i=0; i<n; i++) 
        {
            if (!strcmp(ssid, WiFi.SSID(i).c_str())) 
            {
              return WiFi.channel(i);
            }
        }
    }
    return 0;
}

void EspNowComm::OnDataSent(const uint8_t* mac_addr, esp_now_send_status_t status)
{
    Serial.print("\r\nLast Packet Send Status:\t");
    Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

esp_err_t EspNowComm::sendPack(Packet& pack, uint8_t* mac_addr)
{
    const uint8_t* broadcastAddress = mac_addr;

    esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &packet, sizeof(packet));

    if (result == ESP_OK) 
    {
        Serial.println("Sent with success");
    }
    else 
    {
        Serial.println("Error sending the data");
    }
}