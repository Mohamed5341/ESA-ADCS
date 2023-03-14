#include "Packet.h"

Packet packet;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  packet.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(packet.get_new_packet()){
    if(packet.unpacking()){
      if(packet.pack[3] == 0x04){
        Serial.print("Data = ");
        Serial.println(packet.data.value, 6);
      }else if(packet.pack[3] == 0x01){
        Serial.print("Data = 0x");
        Serial.println(packet.data.bytes[3], HEX);
      }
    }else{
      Serial.println("Invalid Data");
    }
  }
}

void serialEvent1(){
  packet.receive_packet();
}
