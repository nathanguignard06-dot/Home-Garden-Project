#include <OneWire.h>
#include <DallasTemperature.h>

#include "SystemeInit.hpp"
#include "SensorReadings.hpp"
#include "StoreData.hpp"
#include "EspNowComm.hpp"
#include "Packet.hpp"

//sensor pins
const int HUMID1_PIN = 32;
const int HUMID2_PIN = 33;
const int PHOTO1_PIN = 34;
const int PHOTO2_PIN = 35;

//mac address for esp-now communication
uint8_t broadcastAddress[] = {0x30, 0x76, 0xf5, 0xf9, 0x9d, 0xc8};

//peer information
esp_now_peer_info_t peerInfo;

//for ds18b20 temp sensor
#define ONE_WIRE_BUS 25
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature ds18b20(&oneWire);

//creating systeme object and reading object
SystemeInit systeme1(HUMID1_PIN, HUMID2_PIN, PHOTO1_PIN, PHOTO2_PIN);
SensorReadings sensor(systeme1, ds18b20);

//creating packet
Packet packet;

//creating storage object
StoreData storeData(packet);

//creating esp-now communication object
EspNowComm espNow(packet, peerInfo);

//variables
int deviceCount = 0;
const int SPACES = 2;
int humidVal[SPACES];
int lightVal[SPACES];
float tempVal[2];
int count = 0;      //needed for functions and table placements

void setup(void)
{
    //init librairies and serial communication
    Serial.begin(115200);
    ds18b20.begin();
    systeme1.begin();

    while(!Serial) {}

    //finding number of ds18b20 connected
    deviceCount = ds18b20.getDeviceCount();
    
    //debug
    Serial.print("Searching for devices...");
    Serial.print(" Found : ");
    Serial.print(deviceCount, DEC);
    Serial.println(" devices.");
    Serial.println("");
}

void loop(void)
{
    //reading light
    for(int i = 0; i < SPACES; i++)
    {
        if(count == 0)
        {
            lightVal[i] = sensor.readPhoto(PHOTO1_PIN);
        }
        else if(count == 1)
        {
            lightVal[i] = sensor.readPhoto(PHOTO2_PIN);
        }
        else
        {
            return;
        }
        count++;
    }
    count = 0;      //resetting the count for the other readings

    //storing light values in packet
    for(int i = 0; i < SPACES; i ++)
    {
        storeData.storeLight(lightVal[i], SPACES, count);
        count++;
    }
    count = 0;      //resetting the count for the other readings

    //reading humidity
    for(int i = 0; i < SPACES; i++)
    {
        if(count == 0)
        {
            humidVal[i] = sensor.readHumid(HUMID1_PIN);
        }
        else if(count == 1)
        {
            humidVal[i] = sensor.readHumid(HUMID2_PIN);
        }
        else
        {
            return;
        }
        count++;
    }
    count = 0;      //resetting the count for other readings

    //storing humidity values in packet
    for(int i = 0; i < SPACES; i++)
    {
        storeData.storeHumid(humidVal[i], SPACES, count);
        count++;
    }
    count = 0;      //resetting the count for other readings

    //reading temperature
    for(int i = 0; i < deviceCount; i++)
    {
        tempVal[i] = sensor.readTemp(ds18b20, deviceCount, count);
        count++;
    }
    count = 0;
    
    //storing temperature values in packet
    for(int i = 0; i < deviceCount; i++)
    {
        storeData.storeTemp(tempVal[i], deviceCount, count);
        count++;
    }
    
    //debug
    Serial.println("============================================");
    for(int i = 0; i < deviceCount; i++)
    {
        Serial.print("Temperature pot ");
        Serial.print(i + 1);
        Serial.print(" : ");
        Serial.print(packet.temperature[i]);
        Serial.println("°C");
    }

    for(int i = 0; i < SPACES; i++)
    {
        Serial.print("Humidity pot ");
        Serial.print(i + 1);
        Serial.print(" : ");
        Serial.print(packet.humidity[i]);
        Serial.println("%");
    }

    for(int i = 0; i < SPACES; i++)
    {
        Serial.print("Light levels pot ");
        Serial.print(i + 1);
        Serial.print(" : ");
        Serial.print(packet.light[i]);
        Serial.println("%");
    }
    Serial.println("============================================");
    Serial.println();

    count = 0;      //resetting the count for other readings
    delay(2000);
}