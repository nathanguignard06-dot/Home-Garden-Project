#ifndef PACKET
#define PACKET

struct Packet 
{
  float temperature[2];
  int humidity[2];
  int light[2];
};

#endif