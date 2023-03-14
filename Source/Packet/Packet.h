/*
 * Packet handel library
 */

#ifndef _PACKET_H_
#define _PACKET_H_

#define ID 0x21

#include <Arduino.h>

typedef union floatNum{
  float value;
  byte bytes[4];
}Float;

class Packet{
  public:
    Float data;
    uint8_t pack[4];
    
    Packet();
    void init();
    void receive_packet();
    bool get_new_packet();
    bool unpacking();
  private:
    bool new_packet = false;
};

#endif
 
