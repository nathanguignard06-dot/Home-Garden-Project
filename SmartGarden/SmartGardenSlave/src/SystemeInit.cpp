#include "SystemeInit.hpp"

SystemeInit::SystemeInit(int humid1, int humid2, int photo1, int photo2) : HUMID_PIN1(humid1), HUMID_PIN2(humid2), PHOTO_PIN1(photo1), PHOTO_PIN2(photo2) {}

void SystemeInit::begin()
{
    pinMode(HUMID_PIN1, INPUT);
    pinMode(HUMID_PIN2, INPUT);
    pinMode(PHOTO_PIN1, INPUT);
    pinMode(PHOTO_PIN2, INPUT);
}