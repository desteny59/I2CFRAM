#include "I2CFRAM.h"


I2CFRAM_SW FRAM;


void setup(void) {


  Serial.begin(230400); // change baudrate to 2400 on terminal when low CPU freq!
  FRAM.begin();
}

void loop(void){
  uint32_t data=0;
  while(1){
    FRAM.write_uint32_t(21548,data);
    Serial.println(FRAM.read_uint32_t(21548));
    data++;

  }
}




