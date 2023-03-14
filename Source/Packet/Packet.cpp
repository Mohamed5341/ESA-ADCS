#include "Packet.h"

Packet::Packet(){}

void Packet::init(){
  Serial1.begin(9600);
}

void Packet::receive_packet(){
  if(Serial1.read() == ID){
    Serial1.readBytes(pack, 4);
    Serial1.readBytes(data.bytes, pack[3]);
    new_packet = true;
  }
}

bool Packet::get_new_packet(){
  return new_packet;
}

bool Packet::unpacking(){
  new_packet = false;

  byte temp;
  temp = data.bytes[0];
  data.bytes[0] = data.bytes[3];
  data.bytes[3] = temp;
  temp = data.bytes[1];
  data.bytes[1] = data.bytes[2];
  data.bytes[2] = temp;
  
  switch(pack[0]){
    case 0x01:
      switch(pack[1]){
        case 0x0A:
          if(pack[2] == 0x00 && pack[3] == 0x04){
            return true;
          }
          return false;
        case 0x0B:
          if(pack[2] == 0x00 && pack[3] == 0x04){
            return true;
          }
          return false;
        default:
          return false;
      }
      
      
    case 0x02:
      switch(pack[1]){
        case 0x0A:
          if(pack[2] == 0x00 && pack[3] == 0x01){
            return true;
          }
          return false;
        case 0x0B:
          if(pack[2] == 0x00 && pack[3] == 0x00){
            return true;
          }
          return false;
        default:
          return false;
      }
      
      
    case 0x03:
      switch(pack[1]){
        case 0x0A:
          if(pack[2] == 0x04 && pack[3] == 0x00){
            return true;
          }
          return false;
        case 0x0B:
          if(pack[2] == 0x04 && pack[3] == 0x00){
            return true;
          }
          return false;
        case 0x0C:
          if(pack[2] == 0x04 && pack[3] == 0x00){
            return true;
          }
          return false;
        case 0x0D:
          if(pack[2] == 0x1C && pack[3] == 0x00){
            return true;
          }
          return false;
        default:
          return false;
      }
    default:
      return false;    
  }
}
