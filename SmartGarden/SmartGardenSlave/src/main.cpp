#include <OneWire.h>
#include <DallasTemperature.h>

#include "SystemeInit.hpp"
#include "SensorReadings.hpp"

//sensor pins
const int HUMID1_PIN = 32;
const int HUMID2_PIN = 33;
const int PHOTO1_PIN = 34;
const int PHOTO2_PIN = 35;

//for ds18b20 temp sensor
#define ONE_WIRE_BUS 25
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature ds18b20(&oneWire);

//creating systeme object and reading object
SystemeInit systeme1(HUMID1_PIN, HUMID2_PIN, PHOTO1_PIN, PHOTO2_PIN);
SensorReadings sensor(systeme1, ds18b20);

//variables
int deviceCount = 0;
int humidVal1;
int humidVal2;
int lightVal1;
int lightVal2;
float tempVal;

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
    lightVal1 = sensor.readPhoto(PHOTO1_PIN);
    lightVal2 = sensor.readPhoto(PHOTO2_PIN);

    //reading humidity
    humidVal1 = sensor.readHumid(HUMID1_PIN);
    humidVal2 = sensor.readHumid(HUMID2_PIN);

    //reading temp
    tempVal = sensor.readTemp(ds18b20, deviceCount);

    //debug
    Serial.println("============================================");
    Serial.print("Temperature : ");
    Serial.print(tempVal);
    Serial.println("°C");
    Serial.print("Humidity pot 1 : ");
    Serial.print(humidVal1);
    Serial.println("%");
    Serial.print("Humidity pot 2 : ");
    Serial.print(humidVal2);
    Serial.println("%");
    Serial.print("Light levels pot 1 : ");
    Serial.print(humidVal1);
    Serial.println("%");
    Serial.print("Light levels pot 2 : ");
    Serial.print(humidVal2);
    Serial.println("%");
    Serial.println("============================================");
    Serial.println();
    delay(2000);
}