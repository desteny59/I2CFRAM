/*
 * Librairie pour utiliser une FRAM en bus I2C software
 */



#ifndef _I2CFRAM_SW_h
#define _I2CFRAM_SW_h   //create token

#define I2CFRAMADR 0xA0 //adresse en 8bits ! (0X50 <<1)

#define SDA_PORT PORTD
#define SDA_PIN 3
#define SCL_PORT PORTD
#define SCL_PIN 2
#define I2C_TIMEOUT 100
#define I2C_NOINTERRUPT 0
#define I2C_SLOWMODE 1
#define FAC 1
#define I2C_CPUFREQ (F_CPU/FAC)

#include <avr/io.h>

class I2CFRAM_SW{
  public:
    I2CFRAM_SW(); //constructeur
      char begin();
      char write(int addr, char data);        
      uint8_t read(int addr);
      uint32_t read_uint32_t(int addr);
      void write_uint32_t(int addr,uint32_t data);
        
      //variable
      
};




#endif
