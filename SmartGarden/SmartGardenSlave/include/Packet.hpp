#ifndef PACKET
#define PACKET

struct Packet 
{
  float temperature[2];
  int humidity1;
  int humidity2;
  int light1;
  int light2;
};

#endif