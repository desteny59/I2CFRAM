#include "I2CFRAM.h"
#include "SoftI2CMaster.h"
//

I2CFRAM_SW::I2CFRAM_SW(){

}

char I2CFRAM_SW::begin(){
  return i2c_init();
}

uint8_t I2CFRAM_SW::read(int addr){
  char data=0;
  i2c_start(I2CFRAMADR | I2C_WRITE);
  i2c_write(addr >>8);
  i2c_write((addr & 0x00FF));
  i2c_stop();
  i2c_start(I2CFRAMADR | I2C_READ);
  data=i2c_read(true);
  i2c_stop();
  return data;
}

char I2CFRAM_SW::write(int addr, char data){
  if(!i2c_start(I2CFRAMADR | I2C_WRITE))
    return false;
  if(!i2c_write(addr >>8))
    return false;
  if(!i2c_write((addr & 0x00FF)))
    return false;
  if(!i2c_write(data))
    return false;
  i2c_stop();
    return true;

}

uint32_t I2CFRAM_SW::read_uint32_t(int addr){
  uint32_t data=0;
  data=( read(addr) << 24);
  data+=( read(addr+1) << 16);
  data+=( read(addr+2) << 8);
  data+=( read(addr+3) );
  return data;
}

void I2CFRAM_SW::write_uint32_t(int addr,uint32_t data){
  write(addr  ,( data ) >>24 );
  write(addr+1,( data ) >>16 );
  write(addr+2,( data ) >> 8 );
  write(addr+3,( data ) ) ;
}
